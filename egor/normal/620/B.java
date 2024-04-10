import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		int[] cost = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
		long totalCost = ArrayUtils.sumArray(cost);
		int answer = 0;
		long[] ten = IntegerUtils.generatePowers(10, (long) 1e9);

		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int a = in.readInt();
			int b = in.readInt();
			new NumberIterator() {

				protected void process(long prefix, int remainingDigits) {
					int prCost = 0;
					while (prefix != 0) {
						prCost += cost[(int) (prefix % 10)];
						prefix /= 10;
					}
					answer += prCost * ten[remainingDigits];
					if (remainingDigits == 0) {
						return;
					}
					answer += totalCost * ten[remainingDigits - 1] * remainingDigits;
				}
			}.run(a, b);
			out.printLine(answer);
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

	static interface IntCollection extends IntStream {
		public int size();
	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void close() {
			writer.close();
		}

		public void printLine(int i) {
			writer.println(i);
		}
	}

	static abstract class NumberIterator {
		protected final long base;
		protected final long[] power;

		protected NumberIterator() {
			this(10);
		}

		protected NumberIterator(int base) {
			this.base = base;
			power = IntegerUtils.generatePowers(base, Long.MAX_VALUE);
		}

		protected abstract void process(long prefix, int remainingDigits);

		public void run(long from, long to) {
			if (from < 0 || from > to) {
				throw new IllegalArgumentException();
			}
			to++;
			for (int i = 0; ; i++) {
				if (i != power.length - 1 && from / power[i + 1] != to / power[i + 1]) {
					long prefix = from / power[i + 1] * base;
					for (int j = (int) (from / power[i] % base); j < base; j++) {
						process(prefix + j, i);
					}
					from /= power[i + 1];
					from++;
					from *= power[i + 1];
				} else {
					long upTo = to / power[i] % base;
					long prefix = from / power[i] / base * base;
					for (int j = (int) (from / power[i] % base); j < upTo; j++) {
						process(prefix + j, i);
					}
					for (int k = i - 1; k >= 0; k--) {
						upTo = to / power[k] % base;
						prefix = to / power[k + 1] * base;
						for (int j = 0; j < upTo; j++) {
							process(prefix + j, k);
						}
					}
					break;
				}
			}
		}
	}

	static class IntegerUtils {
		public static long[] generatePowers(long base, int count, long mod) {
			long[] result = new long[count];
			if (count != 0) {
				result[0] = 1 % mod;
			}
			for (int i = 1; i < count; i++) {
				result[i] = result[i - 1] * base % mod;
			}
			return result;
		}

		public static long[] generatePowers(long base, long maxValue) {
			if (maxValue <= 0) {
				return new long[0];
			}
			int size = 1;
			long current = 1;
			while (maxValue / base >= current) {
				current *= base;
				size++;
			}
			return generatePowers(base, size, Long.MAX_VALUE);
		}
	}

	static interface IntReversableCollection extends IntCollection {
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
	}

	static interface IntIterator {
		public int value() throws NoSuchElementException;

		public boolean advance();

		public boolean isValid();
	}

	static class ArrayUtils {
		public static long sumArray(int[] array) {
			return new IntArray(array).sum();
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

		default public long sum() {
			long result = 0;
			for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
				result += it.value();
			}
			return result;
		}
	}
}