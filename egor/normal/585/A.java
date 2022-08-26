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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskA {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			int[] v = new int[n];
			int[] d = new int[n];
			int[] p = new int[n];
			IOUtils.readIntArrays(in, v, d, p);
			boolean[] inQueue = new boolean[n];
			Arrays.fill(inQueue, true);
			IntList answer = new IntArrayList();
			for (int i = 0; i < n; i++) {
				if (inQueue[i]) {
					answer.add(i + 1);
					IntList runAway = new IntArrayList();
					inQueue[i] = false;
					int current = v[i];
					for (int j = i + 1; j < n && current > 0; j++) {
						if (inQueue[j]) {
							p[j] -= current--;
							if (p[j] < 0) {
								inQueue[j] = false;
								runAway.add(j);
							}
						}
					}
					for (int l = 0; l < runAway.size(); l++) {
						int j = runAway.get(l);
						for (int k = j + 1; k < n; k++) {
							if (inQueue[k]) {
								p[k] -= d[j];
								if (p[k] < 0) {
									inQueue[k] = false;
									runAway.add(k);
								}
							}
						}
					}
				}
			}
			out.printLine(answer.size());
			out.printLine(answer);
		}

	}

	static abstract class IntCollection {
		public abstract IntIterator iterator();

		public abstract int size();

		public abstract void add(int value);

		public void addAll(IntCollection values) {
			for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
				add(it.value());
			}
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

	static class IOUtils {
		public static void readIntArrays(InputReader in, int[]... arrays) {
			for (int i = 0; i < arrays[0].length; i++) {
				for (int j = 0; j < arrays.length; j++)
					arrays[j][i] = in.readInt();
			}
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

	static interface IntIterator {
		public int value();

		public void advance();

		public boolean isValid();

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