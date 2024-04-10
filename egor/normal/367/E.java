import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	private static final int MOD = (int) (1e9 + 7);

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int size = in.readInt();
		int special = in.readInt() - 1;
		if (count > size) {
			out.printLine(0);
			return;
		}
		int[][] result = new int[count + 1][];
		for (int i = 0; i <= count; i++)
			result[i] = new int[i + 2];
		result[0][0] = 1;
		for (int i = 0; i < size; i++) {
			if (i == special) {
				for (int j = Math.min(count, i + 1); j > 0; j--) {
					for (int k = j; k > 0; k--) {
						result[j][k] = result[j - 1][k] + result[j - 1][k - 1];
						if (result[j][k] >= MOD)
							result[j][k] -= MOD;
					}
					result[j][0] = result[j - 1][0];
				}
				result[0][0] = 0;
			} else {
				for (int j = Math.min(count, i + 1); j > 0; j--) {
					for (int k = j; k > 0; k--) {
						result[j][k] += result[j][k - 1];
						if (result[j][k] >= MOD)
							result[j][k] -= MOD;
						result[j][k] += result[j - 1][k];
						if (result[j][k] >= MOD)
							result[j][k] -= MOD;
						result[j][k] += result[j - 1][k - 1];
						if (result[j][k] >= MOD)
							result[j][k] -= MOD;
					}
					result[j][0] += result[j - 1][0];
					if (result[j][0] >= MOD)
						result[j][0] -= MOD;
				}
			}
		}
		out.printLine(result[count][count] * IntegerUtils.factorial(count, MOD) % MOD);
    }
}

class InputReader {

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

class OutputWriter {
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

	public void printLine(int i) {
		writer.println(i);
	}
}

class IntegerUtils {

    public static long factorial(int n, long mod) {
		long result = 1;
		for (int i = 2; i <= n; i++)
			result = result * i % mod;
		return result % mod;
	}

	}