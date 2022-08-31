import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
		long answer;

		public void solve(int testNumber, InputReader in, OutputWriter out) {
			long a = in.readLong();
			long b = in.readLong();
			new NumberIterator(2) {

				protected void process(long prefix, int remainingDigits) {
					int bitCount = Long.bitCount(prefix);
					int total = Long.bitCount(Long.highestOneBit(prefix) - 1) + 1;
					if (bitCount == total) {
						answer += remainingDigits;
					} else if (bitCount == total - 1) {
						answer++;
					}
				}
			}.run(a, b);
			out.printLine(answer);
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

		public void close() {
			writer.close();
		}

		public void printLine(long i) {
			writer.println(i);
		}

	}

	static class IntegerUtils {
		public static long[] generatePowers(long base, int count, long mod) {
			long[] result = new long[count];
			if (count != 0)
				result[0] = 1 % mod;
			for (int i = 1; i < count; i++)
				result[i] = result[i - 1] * base % mod;
			return result;
		}

		public static long[] generatePowers(long base, long maxValue) {
			if (maxValue <= 0)
				return new long[0];
			int size = 1;
			long current = 1;
			while (maxValue / base >= current) {
				current *= base;
				size++;
			}
			return generatePowers(base, size, Long.MAX_VALUE);
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
			if (from < 0 || from > to)
				throw new IllegalArgumentException();
			to++;
			for (int i = 0; ; i++) {
				if (i != power.length - 1 && from / power[i + 1] != to / power[i + 1]) {
					long prefix = from / power[i + 1] * base;
					for (int j = (int) (from / power[i] % base); j < base; j++)
						process(prefix + j, i);
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

		public long readLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
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