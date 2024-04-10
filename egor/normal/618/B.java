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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskB {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			int[][] a = IOUtils.readIntTable(in, n, n);
			int[] answer = new int[n];
			int[] qty = new int[n + 1];
			for (int i = 0; i < n; i++) {
				Arrays.fill(qty, 0);
				for (int j = 0; j < n; j++) {
					qty[a[i][j]]++;
				}
				int at = ArrayUtils.maxPosition(qty);
				if (qty[at] > 1) {
					answer[i] = at;
				}
			}
			int current = n - 1;
			for (int i = 0; i < n; i++) {
				if (answer[i] == 0) {
					answer[i] = current++;
				}
			}
			out.printLine(answer);
		}

	}

	static class ArrayUtils {
		public static int maxPosition(int[] array) {
			return new IntArray(array).maxIndex();
		}

	}

	static class IOUtils {
		public static int[] readIntArray(InputReader in, int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = in.readInt();
			return array;
		}

		public static int[][] readIntTable(InputReader in, int rowCount, int columnCount) {
			int[][] table = new int[rowCount][];
			for (int i = 0; i < rowCount; i++)
				table[i] = readIntArray(in, columnCount);
			return table;
		}

	}

	static interface IntList extends IntReversableCollection {
		public abstract int get(int index);

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

		default public int maxIndex() {
			int result = Integer.MIN_VALUE;
			int size = size();
			int at = -1;
			for (int i = 0; i < size; i++) {
				int current = get(i);
				if (current > result) {
					result = current;
					at = i;
				}
			}
			return at;
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

		public void print(int[] array) {
			for (int i = 0; i < array.length; i++) {
				if (i != 0)
					writer.print(' ');
				writer.print(array[i]);
			}
		}

		public void printLine(int[] array) {
			print(array);
			writer.println();
		}

		public void close() {
			writer.close();
		}

	}

	static interface IntCollection extends IntStream {
		public int size();

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

		public void removeAt(int index) {
			throw new UnsupportedOperationException();
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