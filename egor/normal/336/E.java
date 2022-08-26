import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
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
	static final long MOD = 1000000007;

	long[][][] result;
	long[][][] resultSmall;
	long[][] c = IntegerUtils.generateBinomialCoefficients(13);

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int size = in.readInt();
		int count = in.readInt();
		result = new long[size + 1][count + 1][16];
		resultSmall = new long[size + 1][count + 1][16];
		ArrayUtils.fill(result, -1);
		ArrayUtils.fill(resultSmall, -1);
		long answer = calculate(size, count, 0);
		answer *= IntegerUtils.factorial(count, MOD);
		answer %= MOD;
		out.printLine(answer);
    }

	private long calculate(int size, int count, int mask) {
		if (count < 0)
			return 0;
		if (result[size][count][mask] != -1)
			return result[size][count][mask];
		long current = 0;
		if (mask == 0)
			current += 2 * calculate(0, count - 2, 15);
		for (int i = 0; i < 4; i++) {
			int j = (i + 1) & 3;
			if ((mask >> i & 1) != 0 || (mask >> j & 1) != 0)
				continue;
			int remaining = 15 - mask - (1 << i) - (1 << j);
			for (int k = remaining; ; k = (k - 1) & remaining) {
				current += calculateSmall(size, count - 1 - Integer.bitCount(k), mask + (1 << i) + (1 << j) + k);
				if (k == 0)
					break;
			}
		}
		int remaining = 15 - mask;
		for (int k = remaining; ; k = (k - 1) & remaining) {
			current += calculateSmall(size, count - Integer.bitCount(k), mask + k);
			if (k == 0)
				break;
		}
		return result[size][count][mask] = current % MOD;
	}

	private long calculateSmall(int size, int count, int mask) {
		if (count < 0)
			return 0;
		if (resultSmall[size][count][mask] != -1)
			return resultSmall[size][count][mask];
		if (size == 0)
			return resultSmall[size][count][mask] = count == 0 ? 1 : 0;
		int max = 3 * Integer.bitCount(15 - mask);
		int pairCount = 0;
		for (int i = 0; i < 4; i++) {
			int j = (i + 1) & 3;
			if ((mask >> i & 1) == 0 && ((mask >> j & 1) == 0))
				pairCount++;
		}
		long current = 0;
		for (int j = 0; j <= pairCount; j++) {
			for (int i = 0; i <= max - 2 * j; i++)
				current += calculate(size - 1, count - i - j, mask) * c[max - 2 * j][i] * c[pairCount][j];
		}
		return resultSmall[size][count][mask] = current % MOD;
	}
}

class IntegerUtils {

    public static long[][] generateBinomialCoefficients(int n) {
		long[][] result = new long[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			result[i][0] = 1;
			for (int j = 1; j <= i; j++)
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
		return result;
	}

	public static long factorial(int n, long mod) {
		long result = 1;
		for (int i = 2; i <= n; i++)
			result = result * i % mod;
		return result % mod;
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

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

    public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}

class ArrayUtils {

	public static void fill(long[][] array, long value) {
		for (long[] row : array)
			Arrays.fill(row, value);
	}

	public static void fill(long[][][] array, long value) {
		for (long[][] row : array)
			fill(row, value);
	}

	}