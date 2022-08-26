import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskE {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			char[] s = in.readString().toCharArray();
			int[] next = new int[s.length];
			int[] length = new int[s.length];
			char[] end = new char[s.length];
			Heap rs = new Heap((a, b) -> length[b] - length[a], s.length);
			Heap ls = new Heap((a, b) -> length[b] - length[a], s.length);
			Arrays.fill(next, -1);
			for (int i = s.length - 1; i >= 0; i--) {
				if (s[i] == 'R') {
					if (!ls.isEmpty()) {
						next[i] = ls.poll();
						length[i] = length[next[i]] + 1;
						end[i] = end[next[i]];
					} else {
						length[i] = 1;
						end[i] = 'L';
					}
					rs.add(i);
				} else {
					if (!rs.isEmpty()) {
						next[i] = rs.poll();
						length[i] = length[next[i]] + 1;
						end[i] = end[next[i]];
					} else {
						length[i] = 1;
						end[i] = 'R';
					}
					ls.add(i);
				}
			}
			int rCount = ArrayUtils.count(s, 'R');
			int lCount = s.length - rCount;
			IntList ll = new IntArrayList();
			IntList lr = new IntArrayList();
			IntList rl = new IntArrayList();
			IntList rr = new IntArrayList();
			while (!ls.isEmpty()) {
				int current = ls.poll();
				if (end[current] == 'R') {
					lr.add(current);
				} else {
					ll.add(current);
				}
			}
			while (!rs.isEmpty()) {
				int current = rs.poll();
				if (end[current] == 'L') {
					rl.add(current);
				} else {
					rr.add(current);
				}
			}
			out.printLine(ll.size() + lr.size() + rl.size() + rr.size() - 1);
			IntList answer = new IntArrayList();
			if (lr.size() == 0 && rl.size() == 0) {
				if (ll.size() != 0 && rr.size() != 0) {
					throw new RuntimeException();
				}
				for (int i : ll.toArray()) {
					add(answer, next, i);
				}
				for (int i : rr.toArray()) {
					add(answer, next, i);
				}
			} else {
				if (lr.size() > rl.size()) {
					construct(next, ll, lr, rl, rr, answer);
				} else {
					construct(next, rr, rl, lr, ll, answer);
				}
			}
			out.printLine(answer);
		}

		protected void construct(int[] next, IntList ll, IntList lr, IntList rl, IntList rr, IntList answer) {
			for (int i : ll.toArray()) {
				add(answer, next, i);
			}
			add(answer, next, lr.popBack());
			for (int i : rr.toArray()) {
				add(answer, next, i);
			}
			while (true) {
				if (rl.size() == 0) {
					break;
				}
				add(answer, next, rl.popBack());
				if (lr.size() == 0) {
					break;
				}
				add(answer, next, lr.popBack());
			}
		}

		private void add(IntList answer, int[] next, int current) {
			while (current != -1) {
				answer.add(current + 1);
				current = next[current];
			}
		}

	}

	static abstract class IntCollection {
		public abstract IntIterator iterator();

		public abstract int size();

		public abstract void add(int value);

		public int[] toArray() {
			int size = size();
			int[] array = new int[size];
			int i = 0;
			for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
				array[i++] = iterator.value();
			return array;
		}

		public void addAll(IntCollection values) {
			for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
				add(it.value());
			}
		}

	}

	static class ArrayUtils {
		public static int count(char[] array, char value) {
			int result = 0;
			for (char i : array) {
				if (i == value)
					result++;
			}
			return result;
		}

	}

	static interface IntIterator {
		public int value();

		public void advance();

		public boolean isValid();

	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(IntCollection collection) {
			boolean first = true;
			for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance()) {
				if (first)
					first = false;
				else
					writer.print(' ');
				writer.print(iterator.value());
			}
		}

		public void printLine(IntCollection collection) {
			print(collection);
			writer.println();
		}

		public void close() {
			writer.close();
		}

		public void printLine(int i) {
			writer.println(i);
		}

	}

	static class Heap {
		private IntComparator comparator;
		private int size = 0;
		private int[] elements;
		private int[] at;

		public Heap(int maxElement) {
			this(10, maxElement);
		}

		public Heap(IntComparator comparator, int maxElement) {
			this(10, comparator, maxElement);
		}

		public Heap(int capacity, int maxElement) {
			this(capacity, IntComparator.DEFAULT, maxElement);
		}

		public Heap(int capacity, IntComparator comparator, int maxElement) {
			this.comparator = comparator;
			elements = new int[capacity];
			at = new int[maxElement];
			Arrays.fill(at, -1);
		}

		public boolean isEmpty() {
			return size == 0;
		}

		public int add(int element) {
			ensureCapacity(size + 1);
			elements[size] = element;
			at[element] = size;
			shiftUp(size++);
			return at[element];
		}

		public void shiftUp(int index) {
//		if (index < 0 || index >= size)
//			throw new IllegalArgumentException();
			int value = elements[index];
			while (index != 0) {
				int parent = (index - 1) >>> 1;
				int parentValue = elements[parent];
				if (comparator.compare(parentValue, value) <= 0) {
					elements[index] = value;
					at[value] = index;
					return;
				}
				elements[index] = parentValue;
				at[parentValue] = index;
				index = parent;
			}
			elements[0] = value;
			at[value] = 0;
		}

		public void shiftDown(int index) {
			if (index < 0 || index >= size)
				throw new IllegalArgumentException();
			while (true) {
				int child = (index << 1) + 1;
				if (child >= size)
					return;
				if (child + 1 < size && comparator.compare(elements[child], elements[child + 1]) > 0)
					child++;
				if (comparator.compare(elements[index], elements[child]) <= 0)
					return;
				swap(index, child);
				index = child;
			}
		}

		private void swap(int first, int second) {
			int temp = elements[first];
			elements[first] = elements[second];
			elements[second] = temp;
			at[elements[first]] = first;
			at[elements[second]] = second;
		}

		private void ensureCapacity(int size) {
			if (elements.length < size) {
				int[] oldElements = elements;
				elements = new int[Math.max(2 * elements.length, size)];
				System.arraycopy(oldElements, 0, elements, 0, this.size);
			}
		}

		public int poll() {
			if (isEmpty())
				throw new IndexOutOfBoundsException();
			int result = elements[0];
			at[result] = -1;
			if (size == 1) {
				size = 0;
				return result;
			}
			elements[0] = elements[--size];
			at[elements[0]] = 0;
			shiftDown(0);
			return result;
		}

	}

	static interface IntComparator {
		public static final IntComparator DEFAULT = new IntComparator() {
			public int compare(int first, int second) {
				if (first < second)
					return -1;
				if (first > second)
					return 1;
				return 0;
			}
		};

		public int compare(int first, int second);

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

		public String readString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				if (Character.isValidCodePoint(c))
					res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
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

	static class IntArrayList extends IntList {
		private int[] array;
		private int size;

		public IntArrayList() {
			this(10);
		}

		public IntArrayList(int capacity) {
			array = new int[capacity];
		}

		public IntArrayList(IntList list) {
			this(list.size());
			addAll(list);
		}


		public int get(int index) {
			if (index >= size)
				throw new IndexOutOfBoundsException();
			return array[index];
		}


		public int size() {
			return size;
		}


		public void add(int value) {
			ensureCapacity(size + 1);
			array[size++] = value;
		}

		public void ensureCapacity(int newCapacity) {
			if (newCapacity > array.length) {
				int[] newArray = new int[Math.max(newCapacity, array.length << 1)];
				System.arraycopy(array, 0, newArray, 0, size);
				array = newArray;
			}
		}


		public int[] toArray() {
			int[] array = new int[size];
			System.arraycopy(this.array, 0, array, 0, size);
			return array;
		}


		public int popBack() {
			return array[--size];
		}

	}

	static abstract class IntList extends IntCollection implements Comparable<IntList> {
		public abstract int get(int index);


		public IntIterator iterator() {
			return new IntIterator() {
				private int size = size();
				private int index = 0;

				public int value() throws NoSuchElementException {
					if (!isValid())
						throw new NoSuchElementException();
					return get(index);
				}

				public void advance() throws NoSuchElementException {
					if (!isValid())
						throw new NoSuchElementException();
					index++;
				}

				public boolean isValid() {
					return index < size;
				}
			};
		}

		public int popBack() {
			throw new UnsupportedOperationException();
		}

		public int hashCode() {
			int hashCode = 1;
			for (IntIterator i = iterator(); i.isValid(); i.advance())
				hashCode = 31 * hashCode + i.value();
			return hashCode;
		}


		public boolean equals(Object obj) {
			if (!(obj instanceof IntList))
				return false;
			IntList list = (IntList) obj;
			if (list.size() != size())
				return false;
			IntIterator i = iterator();
			IntIterator j = list.iterator();
			while (i.isValid()) {
				if (i.value() != j.value())
					return false;
				i.advance();
				j.advance();
			}
			return true;
		}

		public int compareTo(IntList o) {
			IntIterator i = iterator();
			IntIterator j = o.iterator();
			while (true) {
				if (i.isValid()) {
					if (j.isValid()) {
						if (i.value() != j.value()) {
							if (i.value() < j.value())
								return -1;
							else
								return 1;
						}
					} else
						return 1;
				} else {
					if (j.isValid())
						return -1;
					else
						return 0;
				}
				i.advance();
				j.advance();
			}
		}

	}
}