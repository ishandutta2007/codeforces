import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskF {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int count = in.readInt();
			int[] a = IOUtils.readIntArray(in, count);
			int[] div = IntegerUtils.generateDivisorTable(1000001);
			int[] ans = new int[1000001];
			for (int i = 1; i <= 1000000; i++) {
				int cur = i;
				while (cur > 1) {
					ans[i] = Math.max(ans[i], ans[i / div[cur]]);
					int d = div[cur];
					do {
						cur /= d;
					} while (cur % d == 0);
				}
				if (Arrays.binarySearch(a, i) >= 0) {
					ans[i]++;
				}
			}
			out.printLine(ArrayUtils.maxElement(ans));
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

		public void printLine(int i) {
			writer.println(i);
		}

	}

	static class IntegerUtils {
		public static int[] generateDivisorTable(int upTo) {
			int[] divisor = new int[upTo];
			for (int i = 1; i < upTo; i++)
				divisor[i] = i;
			for (int i = 2; i * i < upTo; i++) {
				if (divisor[i] == i) {
					for (int j = i * i; j < upTo; j += i)
						divisor[j] = i;
				}
			}
			return divisor;
		}

	}

	static class ArrayUtils {
		public static int maxElement(int[] array) {
			return maxElement(array, 0, array.length);
		}

		public static int maxElement(int[] array, int from, int to) {
			int result = Integer.MIN_VALUE;
			for (int i = from; i < to; i++)
				result = Math.max(result, array[i]);
			return result;
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