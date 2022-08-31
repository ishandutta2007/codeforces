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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskA {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			String s = StringUtils.reverse(Integer.toBinaryString(n));
			IntList answer = new IntArrayList();
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == '1') {
					answer.add(i + 1);
				}
			}
			answer.inPlaceReverse();
			out.printLine(answer);
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

		public void set(int index, int value) {
			if (index >= size) {
				throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
			}
			data[index] = value;
		}

	}

	static interface IntList extends IntReversableCollection {
		public abstract int get(int index);

		public abstract void set(int index, int value);

		public abstract void addAt(int index, int value);

		public abstract void removeAt(int index);

		default public void swap(int first, int second) {
			if (first == second) {
				return;
			}
			int temp = get(first);
			set(first, get(second));
			set(second, temp);
		}

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

		default public void inPlaceReverse() {
			for (int i = 0, j = size() - 1; i < j; i++, j--) {
				swap(i, j);
			}
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

	static class StringUtils {
		public static String reverse(String sample) {
			StringBuilder result = new StringBuilder(sample);
			result.reverse();
			return result.toString();
		}

	}

	static interface IntReversableCollection extends IntCollection {
	}

	static interface IntIterator {
		public int value() throws NoSuchElementException;

		public boolean advance();

		public boolean isValid();

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
}