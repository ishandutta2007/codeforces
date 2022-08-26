import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Random;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskC {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			int[] a = IOUtils.readIntArray(in, n);
			int answer = 0;
			IntHashSet was = new IntHashSet();
			IntList ends = new IntArrayList();
			for (int j = 0; j < a.length; j++) {
				int i = a[j];
				if (was.contains(i)) {
					answer++;
					was = new IntHashSet();
					ends.add(j);
				} else {
					was.add(i);
				}
			}
			out.printLine(answer == 0 ? -1 : answer);
			if (answer != 0) {
				out.print("1 ");
				ends.popLast();
				for (int i : ends) {
					out.printLine(i + 1);
					out.print((i + 2) + " ");
				}
				out.printLine(n);
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
			if (numChars == -1) {
				throw new InputMismatchException();
			}
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0) {
					return -1;
				}
			}
			return buf[curChar++];
		}

		public int readInt() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9') {
					throw new InputMismatchException();
				}
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public boolean isSpaceChar(int c) {
			if (filter != null) {
				return filter.isSpaceChar(c);
			}
			return isWhitespace(c);
		}

		public static boolean isWhitespace(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
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
				if (i != 0) {
					writer.print(' ');
				}
				writer.print(objects[i]);
			}
		}

		public void close() {
			writer.close();
		}

		public void printLine(int i) {
			writer.println(i);
		}
	}

	static class IntegerUtils {
		public static int gcd(int a, int b) {
			a = Math.abs(a);
			b = Math.abs(b);
			while (b != 0) {
				int temp = a % b;
				a = b;
				b = temp;
			}
			return a;
		}
	}

	static class IOUtils {
		public static int[] readIntArray(InputReader in, int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++) {
				array[i] = in.readInt();
			}
			return array;
		}
	}

	static class IntHashSet extends IntAbstractStream implements IntSet {
		private static final Random RND = new Random();
		private static final int[] SHIFTS = new int[4];
		private static final byte PRESENT_MASK = 1;
		private static final byte REMOVED_MASK = 2;
		private int size;
		private int realSize;
		private int[] values;
		private byte[] present;
		private int step;
		private int ratio;

		static {
			for (int i = 0; i < 4; i++) {
				SHIFTS[i] = RND.nextInt(31) + 1;
			}
		}

		public IntHashSet() {
			this(3);
		}

		public IntHashSet(int capacity) {
			capacity = Math.max(capacity, 3);
			values = new int[capacity];
			present = new byte[capacity];
			ratio = 2;
			initStep(capacity);
		}

		public IntHashSet(IntCollection c) {
			this(c.size());
			addAll(c);
		}

		public IntHashSet(int[] arr) {
			this(new IntArray(arr));
		}

		private void initStep(int capacity) {
			step = RND.nextInt(capacity - 2) + 1;
			while (IntegerUtils.gcd(step, capacity) != 1) {
				step++;
			}
		}

		public IntIterator intIterator() {
			return new IntIterator() {
				private int position = size == 0 ? values.length : -1;

				public int value() throws NoSuchElementException {
					if (position == -1) {
						advance();
					}
					if (position >= values.length) {
						throw new NoSuchElementException();
					}
					if ((present[position] & PRESENT_MASK) == 0) {
						throw new IllegalStateException();
					}
					return values[position];
				}

				public boolean advance() throws NoSuchElementException {
					if (position >= values.length) {
						throw new NoSuchElementException();
					}
					position++;
					while (position < values.length && (present[position] & PRESENT_MASK) == 0) {
						position++;
					}
					return isValid();
				}

				public boolean isValid() {
					return position < values.length;
				}

				public void remove() {
					if ((present[position] & PRESENT_MASK) == 0) {
						throw new IllegalStateException();
					}
					present[position] = REMOVED_MASK;
				}
			};
		}

		public int size() {
			return size;
		}

		public void add(int value) {
			ensureCapacity((realSize + 1) * ratio + 2);
			int current = getHash(value);
			while (present[current] != 0) {
				if ((present[current] & PRESENT_MASK) != 0 && values[current] == value) {
					return;
				}
				current += step;
				if (current >= values.length) {
					current -= values.length;
				}
			}
			while ((present[current] & PRESENT_MASK) != 0) {
				current += step;
				if (current >= values.length) {
					current -= values.length;
				}
			}
			if (present[current] == 0) {
				realSize++;
			}
			present[current] = PRESENT_MASK;
			values[current] = value;
			size++;
		}

		private int getHash(int value) {
			int hash = IntHash.hash(value);
			int result = hash;
			for (int i : SHIFTS) {
				result ^= hash >> i;
			}
			result %= values.length;
			if (result < 0) {
				result += values.length;
			}
			return result;
		}

		private void ensureCapacity(int capacity) {
			if (values.length < capacity) {
				capacity = Math.max(capacity * 2, values.length);
				rebuild(capacity);
			}
		}

		private void rebuild(int capacity) {
			initStep(capacity);
			int[] oldValues = values;
			byte[] oldPresent = present;
			values = new int[capacity];
			present = new byte[capacity];
			size = 0;
			realSize = 0;
			for (int i = 0; i < oldValues.length; i++) {
				if ((oldPresent[i] & PRESENT_MASK) == PRESENT_MASK) {
					add(oldValues[i]);
				}
			}
		}

		public boolean contains(int value) {
			int current = getHash(value);
			while (present[current] != 0) {
				if (values[current] == value && (present[current] & PRESENT_MASK) != 0) {
					return true;
				}
				current += step;
				if (current >= values.length) {
					current -= values.length;
				}
			}
			return false;
		}
	}

	static interface IntIterator {
		public int value() throws NoSuchElementException;

		public boolean advance();

		public boolean isValid();
	}

	static class IntHash {
		private IntHash() {
		}

		public static int hash(int c) {
			return c;
		}
	}

	static abstract class IntAbstractStream implements IntStream {

		public String toString() {
			StringBuilder builder = new StringBuilder();
			boolean first = true;
			for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
				if (first) {
					first = false;
				} else {
					builder.append(' ');
				}
				builder.append(it.value());
			}
			return builder.toString();
		}

		public boolean equals(Object o) {
			if (!(o instanceof IntStream)) {
				return false;
			}
			IntStream c = (IntStream) o;
			IntIterator it = intIterator();
			IntIterator jt = c.intIterator();
			while (it.isValid() && jt.isValid()) {
				if (it.value() != jt.value()) {
					return false;
				}
				it.advance();
				jt.advance();
			}
			return !it.isValid() && !jt.isValid();
		}

		public int hashCode() {
			int result = 0;
			for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
				result *= 31;
				result += it.value();
			}
			return result;
		}
	}

	static interface IntCollection extends IntStream {
		public int size();

		default public void add(int value) {
			throw new UnsupportedOperationException();
		}

		default public IntCollection addAll(IntStream values) {
			for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
				add(it.value());
			}
			return this;
		}
	}

	static interface IntReversableCollection extends IntCollection {
	}

	static interface IntList extends IntReversableCollection {
		public abstract int get(int index);

		public abstract void addAt(int index, int value);

		public abstract void removeAt(int index);

		default public IntIterator intIterator() {
			return new IntIterator() {
				private int at;
				private boolean removed;

				public int value() {
					if (removed) {
						throw new IllegalStateException();
					}
					return get(at);
				}

				public boolean advance() {
					at++;
					removed = false;
					return isValid();
				}

				public boolean isValid() {
					return !removed && at < size();
				}

				public void remove() {
					removeAt(at);
					at--;
					removed = true;
				}
			};
		}

		default public void add(int value) {
			addAt(size(), value);
		}

		default public void popLast() {
			removeAt(size() - 1);
		}
	}

	static class IntArray extends IntAbstractStream implements IntList {
		private int[] data;

		public IntArray(int[] arr) {
			data = arr;
		}

		public int size() {
			return data.length;
		}

		public int get(int at) {
			return data[at];
		}

		public void addAt(int index, int value) {
			throw new UnsupportedOperationException();
		}

		public void removeAt(int index) {
			throw new UnsupportedOperationException();
		}
	}

	static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
		public IntIterator intIterator();

		default public Iterator<Integer> iterator() {
			return new Iterator<Integer>() {
				private IntIterator it = intIterator();

				public boolean hasNext() {
					return it.isValid();
				}

				public Integer next() {
					int result = it.value();
					it.advance();
					return result;
				}
			};
		}

		default public int compareTo(IntStream c) {
			IntIterator it = intIterator();
			IntIterator jt = c.intIterator();
			while (it.isValid() && jt.isValid()) {
				int i = it.value();
				int j = jt.value();
				if (i < j) {
					return -1;
				} else if (i > j) {
					return 1;
				}
				it.advance();
				jt.advance();
			}
			if (it.isValid()) {
				return 1;
			}
			if (jt.isValid()) {
				return -1;
			}
			return 0;
		}
	}

	static interface IntSet extends IntCollection {
	}

	static class IntArrayList extends IntAbstractStream implements IntList {
		private int size;
		private int[] data;

		public IntArrayList() {
			this(3);
		}

		public IntArrayList(int capacity) {
			data = new int[capacity];
		}

		public IntArrayList(IntCollection c) {
			this(c.size());
			addAll(c);
		}

		public IntArrayList(IntStream c) {
			this();
			if (c instanceof IntCollection) {
				ensureCapacity(((IntCollection) c).size());
			}
			addAll(c);
		}

		public IntArrayList(IntArrayList c) {
			size = c.size();
			data = c.data.clone();
		}

		public IntArrayList(int[] arr) {
			size = arr.length;
			data = arr.clone();
		}

		public int size() {
			return size;
		}

		public int get(int at) {
			if (at >= size) {
				throw new IndexOutOfBoundsException("at = " + at + ", size = " + size);
			}
			return data[at];
		}

		private void ensureCapacity(int capacity) {
			if (data.length >= capacity) {
				return;
			}
			capacity = Math.max(2 * data.length, capacity);
			data = Arrays.copyOf(data, capacity);
		}

		public void addAt(int index, int value) {
			ensureCapacity(size + 1);
			if (index > size || index < 0) {
				throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
			}
			if (index != size) {
				System.arraycopy(data, index, data, index + 1, size - index);
			}
			data[index] = value;
			size++;
		}

		public void removeAt(int index) {
			if (index >= size || index < 0) {
				throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
			}
			if (index != size - 1) {
				System.arraycopy(data, index + 1, data, index, size - index - 1);
			}
			size--;
		}
	}
}