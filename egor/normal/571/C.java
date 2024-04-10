import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.AbstractSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Set;
import java.io.IOException;
import java.util.AbstractMap;
import java.io.Writer;
import java.util.Map.Entry;
import java.util.Queue;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskC {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			int m = in.readInt();
			int[][] v = new int[n][];
			for (int i = 0; i < n; i++) {
				v[i] = IOUtils.readIntArray(in, in.readInt());
			}
			Formula[] formulas = new Formula[n];
			Variable[] variables = new Variable[m];
			for (int i = 0; i < m; i++) {
				variables[i] = new Variable();
			}
			for (int i = 0; i < n; i++) {
				formulas[i] = new Formula();
				for (int j = 0; j < v[i].length; j++) {
					int id = Math.abs(v[i][j]) - 1;
					formulas[i].type.put(variables[id], v[i][j] > 0);
					variables[id].addFormula(formulas[i]);
				}
			}
			Queue<Ready> queue = new ArrayDeque<>();
			int processed = 0;
			for (int i = 0; i < n; i++) {
				if (formulas[i].ready()) {
					queue.add(formulas[i]);
				}
			}
			for (int i = 0; i < m; i++) {
				if (variables[i].ready()) {
					queue.add(variables[i]);
				}
			}
			while (true) {
				while (!queue.isEmpty()) {
					Ready current = queue.poll();
					if (current instanceof Formula) {
						Formula formula = (Formula) current;
						if (formula.satisfied) {
							continue;
						}
						if (formula.type.size() == 0) {
							out.printLine("NO");
							return;
						}
						formula.satisfied = true;
						Variable variable = formula.type.keySet().iterator().next();
						variable.value = formula.type.get(variable);
						if (variable.ready()) {
							variable.removeFormula(formula);
						} else {
							variable.removeFormula(formula);
							Formula other = variable.first;
							other.type.remove(variable);
							variable.removeFormula(other);
							if (other.ready()) {
								queue.add(other);
							}
						}
					} else {
						Variable variable = (Variable) current;
						if (variable.first == null) {
							continue;
						}
						if (!variable.first.satisfied) {
							variable.value = variable.first.type.get(variable);
							variable.first.satisfied = true;
							for (Variable other : variable.first.type.keySet()) {
								if (other != variable) {
									other.removeFormula(variable.first);
									variable.first.type.remove(other);
									queue.add(other);
								}
							}
						}
						if (variable.second != null && !variable.second.satisfied) {
							variable.value = variable.second.type.get(variable);
							variable.second.satisfied = true;
							for (Variable other : variable.second.type.keySet()) {
								if (other != variable) {
									other.removeFormula(variable.second);
									variable.second.type.remove(other);
									queue.add(other);
								}
							}
						}
					}
				}
				while (processed < n && formulas[processed].satisfied) {
					processed++;
				}
				if (processed == n) {
					break;
				}
				Formula formula = formulas[processed];
				Variable variable = formula.type.keySet().iterator().next();
				for (Variable other : formula.type.keySet()) {
					if (other != variable) {
						formula.type.remove(other);
						other.removeFormula(formula);
						queue.add(other);
					}
				}
				queue.add(formula);
			}
			out.printLine("YES");
			for (int i = 0; i < m; i++) {
				out.print(variables[i].value ? 1 : 0);
			}
			out.printLine();
		}

		static class Formula implements Ready {
			Map<Variable, Boolean> type = new EHashMap<>();
			boolean satisfied;


			public boolean ready() {
				return type.size() <= 1;
			}

		}

		static class Variable implements Ready {
			Formula first;
			Formula second;
			boolean value;

			void addFormula(Formula formula) {
				if (first == null) {
					first = formula;
				} else {
					second = formula;
				}
			}

			void removeFormula(Formula formula) {
				if (first == formula) {
					first = second;
					second = null;
				} else if (second == formula) {
					second = null;
				}
			}


			public boolean ready() {
				return second == null || first.type.get(this).equals(second.type.get(this));
			}

		}

		interface Ready {
		}

	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(Object... objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}

		public void printLine() {
			writer.println();
		}

		public void printLine(Object... objects) {
			print(objects);
			writer.println();
		}

		public void close() {
			writer.close();
		}

		public void print(int i) {
			writer.print(i);
		}

	}

	static class EHashMap<E, V> extends AbstractMap<E, V> {
		private static final int[] shifts = new int[10];
		private int size;
		private HashEntry<E, V>[] data;
		private int capacity;
		private Set<Entry<E, V>> entrySet;

		static {
			Random random = new Random(System.currentTimeMillis());
			for (int i = 0; i < 10; i++)
				shifts[i] = 1 + 3 * i + random.nextInt(3);
		}

		public EHashMap() {
			this(4);
		}

		private void setCapacity(int size) {
			capacity = Integer.highestOneBit(4 * size);
			//noinspection unchecked
			data = new HashEntry[capacity];
		}

		public EHashMap(int maxSize) {
			setCapacity(maxSize);
			entrySet = new AbstractSet<Entry<E, V>>() {

				public Iterator<Entry<E, V>> iterator() {
					return new Iterator<Entry<E, V>>() {
						private HashEntry<E, V> last = null;
						private HashEntry<E, V> current = null;
						private HashEntry<E, V> base = null;
						private int lastIndex = -1;
						private int index = -1;

						public boolean hasNext() {
							if (current == null) {
								for (index++; index < capacity; index++) {
									if (data[index] != null) {
										base = current = data[index];
										break;
									}
								}
							}
							return current != null;
						}

						public Entry<E, V> next() {
							if (!hasNext())
								throw new NoSuchElementException();
							last = current;
							lastIndex = index;
							current = current.next;
							if (base.next != last)
								base = base.next;
							return last;
						}

						public void remove() {
							if (last == null)
								throw new IllegalStateException();
							size--;
							if (base == last)
								data[lastIndex] = last.next;
							else
								base.next = last.next;
						}
					};
				}


				public int size() {
					return size;
				}
			};
		}

		public EHashMap(Map<E, V> map) {
			this(map.size());
			putAll(map);
		}


		public Set<Entry<E, V>> entrySet() {
			return entrySet;
		}


		public void clear() {
			Arrays.fill(data, null);
			size = 0;
		}

		private int index(Object o) {
			return getHash(o.hashCode()) & (capacity - 1);
		}

		private int getHash(int h) {
			int result = h;
			for (int i : shifts)
				result ^= h >>> i;
			return result;
		}


		public V remove(Object o) {
			if (o == null)
				return null;
			int index = index(o);
			HashEntry<E, V> current = data[index];
			HashEntry<E, V> last = null;
			while (current != null) {
				if (current.key.equals(o)) {
					if (last == null)
						data[index] = current.next;
					else
						last.next = current.next;
					size--;
					return current.value;
				}
				last = current;
				current = current.next;
			}
			return null;
		}


		public V put(E e, V value) {
			if (e == null)
				return null;
			int index = index(e);
			HashEntry<E, V> current = data[index];
			if (current != null) {
				while (true) {
					if (current.key.equals(e)) {
						V oldValue = current.value;
						current.value = value;
						return oldValue;
					}
					if (current.next == null)
						break;
					current = current.next;
				}
			}
			if (current == null)
				data[index] = new HashEntry<E, V>(e, value);
			else
				current.next = new HashEntry<E, V>(e, value);
			size++;
			if (2 * size > capacity) {
				HashEntry<E, V>[] oldData = data;
				setCapacity(size);
				for (HashEntry<E, V> entry : oldData) {
					while (entry != null) {
						HashEntry<E, V> next = entry.next;
						index = index(entry.key);
						entry.next = data[index];
						data[index] = entry;
						entry = next;
					}
				}
			}
			return null;
		}


		public V get(Object o) {
			if (o == null)
				return null;
			int index = index(o);
			HashEntry<E, V> current = data[index];
			while (current != null) {
				if (current.key.equals(o))
					return current.value;
				current = current.next;
			}
			return null;
		}


		public boolean containsKey(Object o) {
			if (o == null)
				return false;
			int index = index(o);
			HashEntry<E, V> current = data[index];
			while (current != null) {
				if (current.key.equals(o))
					return true;
				current = current.next;
			}
			return false;
		}


		public int size() {
			return size;
		}

		private static class HashEntry<E, V> implements Entry<E, V> {
			private final E key;
			private V value;
			private HashEntry<E, V> next;

			private HashEntry(E key, V value) {
				this.key = key;
				this.value = value;
			}

			public E getKey() {
				return key;
			}

			public V getValue() {
				return value;
			}

			public V setValue(V value) {
				V oldValue = this.value;
				this.value = value;
				return oldValue;
			}

		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int readInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return isWhitespace(c);
		}

		public static boolean isWhitespace(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);

		}

	}

	static class IOUtils {
		public static int[] readIntArray(InputReader in, int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = in.readInt();
			return array;
		}

	}
}