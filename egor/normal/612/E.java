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
			int n = in.readInt();
			int[] p = IOUtils.readIntArray(in, n);
			MiscUtils.decreaseByOne(p);
			int[] cycle = ArrayUtils.createArray(n + 1, -1);
			int[] q = new int[n];
			boolean[] processed = new boolean[n];
			for (int i = 0; i < n; i++) {
				if (processed[i]) {
					continue;
				}
				int length = 0;
				int current = i;
				do {
					length++;
					processed[current] = true;
					current = p[current];
				} while (!processed[current]);
				if (length % 2 == 0) {
					if (cycle[length] != -1) {
						int a = i;
						int b = cycle[length];
						for (int j = 0; j < length; j++) {
							q[a] = b;
							a = p[a];
							q[b] = a;
							b = p[b];
						}
						cycle[length] = -1;
					} else {
						cycle[length] = i;
					}
				} else {
					int a = i;
					int b = i;
					for (int j = 0; j < (length + 1) / 2; j++) {
						b = p[b];
					}
					for (int j = 0; j < length; j++) {
						q[a] = b;
						a = p[a];
						b = p[b];
					}
				}
			}
			if (ArrayUtils.count(cycle, -1) != n + 1) {
				out.printLine(-1);
				return;
			}
			out.printLine(new IntArray(q).map((IntToIntFunction) x -> x + 1).compute());
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

	static class MiscUtils {
		public static void decreaseByOne(int[]... arrays) {
			for (int[] array : arrays) {
				for (int i = 0; i < array.length; i++)
					array[i]--;
			}
		}

	}

	static class ArrayUtils {
		public static int count(int[] array, int value) {
			return new IntArray(array).count(value);
		}

		public static int[] createArray(int count, int value) {
			int[] array = new int[count];
			Arrays.fill(array, value);
			return array;
		}

	}

	static interface IntIterator {
		public int value() throws NoSuchElementException;

		public boolean advance();

		public boolean isValid();

		public void remove();

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

		default public IntCollection compute() {
			return new IntArrayList(this);
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

		default public int count(int value) {
			int result = 0;
			for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
				if (it.value() == value) {
					result++;
				}
			}
			return result;
		}

		default public IntStream map(IntToIntFunction function) {
			return () -> new IntIterator() {
				private IntIterator it = IntStream.this.intIterator();

				public int value() {
					return function.value(it.value());
				}

				public boolean advance() {
					return it.advance();
				}

				public boolean isValid() {
					return it.isValid();
				}

				public void remove() {
					it.remove();
				}
			};
		}

	}

	static interface IntToIntFunction {
		public int value(int key);

	}

	static interface IntReversableCollection extends IntCollection {
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

		default public IntCollection compute() {
			return this;
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

		public void printLine(Object... objects) {
			print(objects);
			writer.println();
		}

		public void close() {
			writer.close();
		}

		public void printLine(int i) {
			writer.println(i);
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
}