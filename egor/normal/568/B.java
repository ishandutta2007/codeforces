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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskB {
		static final long MOD = (long) (1e9 + 7);
		long[][] c;
		long[] result;

		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			long answer = 0;
			result = ArrayUtils.createArray(n, -1L);
			c = IntegerUtils.generateBinomialCoefficients(n + 1, MOD);
			for (int i = 1; i <= n; i++) {
				answer += c[n][i] * calculate(n - i) % MOD;
			}
			out.printLine(answer % MOD);
		}

		private long calculate(int n) {
			if (result[n] != -1) {
				return result[n];
			}
			result[n] = 1;
			for (int i = 1; i < n; i++) {
				result[n] += calculate(n - i) * c[n - 1][i - 1] % MOD;
			}
			return result[n] %= MOD;
		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private InputReader.SpaceCharFilter filter;

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

	static class ArrayUtils {
		public static long[] createArray(int count, long value) {
			long[] array = new long[count];
			Arrays.fill(array, value);
			return array;
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
		public static long[][] generateBinomialCoefficients(int n, long module) {
			long[][] result = new long[n + 1][n + 1];
			if (module == 1)
				return result;
			for (int i = 0; i <= n; i++) {
				result[i][0] = 1;
				for (int j = 1; j <= i; j++) {
					result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
					if (result[i][j] >= module)
						result[i][j] -= module;
				}
			}
			return result;
		}

	}
}