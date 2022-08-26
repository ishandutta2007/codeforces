import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.AbstractSet;
import java.util.Iterator;
import java.util.Set;
import java.util.AbstractMap;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	private String[] cards;
	Map<State, Boolean> map = new EHashMap<State, Boolean>();

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		if (count == 1) {
			out.printLine("YES");
			return;
		}
		cards = IOUtils.readStringArray(in, count);
		if (count == 2) {
			if (compatible(cards[0], cards[1]))
				out.printLine("YES");
			else
				out.printLine("NO");
			return;
		}
		if (go(cards[count - 1], cards[count - 2], cards[count - 3], cards.length - 3))
			out.printLine("YES");
		else
			out.printLine("NO");
	}

	private boolean go(String last, String preLast, String prePreLast, int remaining) {
		State key = new State(last, preLast, prePreLast, remaining);
		if (map.containsKey(key))
			return map.get(key);
		if (remaining == 0) {
			if (compatible(last, preLast) && compatible(last, prePreLast)) {
				map.put(key, true);
				return true;
			} else {
				map.put(key, false);
				return false;
			}
		}
		if (compatible(last, preLast) && go(last, prePreLast, cards[remaining - 1], remaining - 1)) {
			map.put(key, true);
			return true;
		}
		if (compatible(last, cards[remaining - 1]) && go(preLast, prePreLast, last, remaining - 1)) {
			map.put(key, true);
			return true;
		}
		map.put(key, false);
		return false;
	}

	private boolean compatible(String last, String preLast) {
		return last.charAt(0) == preLast.charAt(0) || last.charAt(1) == preLast.charAt(1);
	}

	static class State {
		String last;
		String preLast;
		String prePreLast;
		int remaining;

		State(String last, String preLast, String prePreLast, int remaining) {
			this.last = last;
			this.preLast = preLast;
			this.prePreLast = prePreLast;
			this.remaining = remaining;
		}

		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;

			State state = (State) o;

			if (remaining != state.remaining) return false;
			if (!last.equals(state.last)) return false;
			if (!preLast.equals(state.preLast)) return false;
			if (!prePreLast.equals(state.prePreLast)) return false;

			return true;
		}

		public int hashCode() {
			int result = last.hashCode();
			result = 31 * result + preLast.hashCode();
			result = 31 * result + prePreLast.hashCode();
			result = 31 * result + remaining;
			return result;
		}
	}
}

class EHashMap<E, V> extends AbstractMap<E, V> {
	private static final int[] shifts = new int[10];

	private int size;
	private Object[] keys;
	private Object[] values;
	private int capacity;
	private int shift;
	private int[] indices;
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
		capacity = Integer.highestOneBit(10 * size);
		keys = new Object[capacity];
		values = new Object[capacity];
		shift = capacity / 3 - 1;
		shift -= 1 - (shift & 1);
		indices = new int[capacity];
	}

	public EHashMap(int maxSize) {
		setCapacity(maxSize);
		entrySet = new AbstractSet<Entry<E, V>>() {
			@Override
			public Iterator<Entry<E, V>> iterator() {
				return new Iterator<Entry<E, V>>() {
					private HashEntry entry = new HashEntry();
					int index = 0;

					public boolean hasNext() {
						while (index < size && keys[index] == null)
							index++;
						return index < size;
					}

					public Entry<E, V> next() {
						if (!hasNext())
							throw new NoSuchElementException();
						entry.key = (E) keys[index];
						entry.value = (V) values[index++];
						return entry;
					}

					public void remove() {
						if (entry.key == null)
							throw new IllegalStateException();
						EHashMap.this.remove(entry.key);
						entry.key = null;
						entry.value = null;
					}
				};
			}

			@Override
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
		Arrays.fill(keys, null);
		Arrays.fill(values, null);
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
		int indicesSize = 0;
		while (keys[index] != null && !keys[index].equals(o)) {
			indices[indicesSize++] = index;
			index = (index + shift) & (capacity - 1);
		}
		if (keys[index] == null)
			return null;
		size--;
		int lastIndex = indicesSize;
		indices[indicesSize++] = index;
		keys[index] = null;
		V result = (V) values[index];
		values[index] = null;
		index = (index + shift) & (capacity - 1);
		while (keys[index] != null) {
			int curKey = index(keys[index]);
			for (int i = 0; i <= lastIndex; i++) {
				if (indices[i] == curKey) {
					keys[indices[lastIndex]] = keys[index];
					values[indices[lastIndex]] = values[index];
					keys[index] = null;
					values[index] = null;
					lastIndex = indicesSize;
				}
			}
			indices[indicesSize++] = index;
			index = (index + shift) & (capacity - 1);
		}
		return result;
	}

	public V put(E e, V value) {
		if (e == null)
			return null;
		int index = index(e);
		while (keys[index] != null && !keys[index].equals(e))
			index = (index + shift) & (capacity - 1);
		if (keys[index] == null)
			size++;
		keys[index] = e;
		values[index] = value;
		if (size * 2 > capacity) {
			Object[] oldKeys = keys;
			Object[] oldValues = values;
			setCapacity(size);
			size = 0;
			for (int i = 0; i < oldKeys.length; i++) {
				if (oldKeys[i] != null)
					put((E) oldKeys[i], (V) oldValues[i]);
			}
		}
		return value;
	}

	public V get(Object o) {
		if (o == null)
			return null;
		int index = index(o);
		while (keys[index] != null && !keys[index].equals(o))
			index = (index + shift) & (capacity - 1);
		return (V) values[index];
	}

	public boolean containsKey(Object o) {
		if (o == null)
			return false;
		int index = index(o);
		while (keys[index] != null && !keys[index].equals(o))
			index = (index + shift) & (capacity - 1);
		return keys[index] != null;
	}

	public int size() {
		return size;
	}

	private class HashEntry implements Entry<E, V> {
		private E key;
		private V value;

		public E getKey() {
			return key;
		}

		public V getValue() {
			return value;
		}

		public V setValue(V value) {
			put(key, value);
			return this.value = value;
		}
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}

class IOUtils {

	public static String[] readStringArray(InputReader in, int size) {
		String[] array = new String[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readString();
		return array;
	}

	}