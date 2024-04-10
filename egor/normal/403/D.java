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
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
	private static final int MOD = (int) (1e9 + 7);
	long[][][] result = new long[1001][][];
//	long[][][] strict = new long[1001][][];
	long[] factorial = IntegerUtils.generateFactorial(1001, MOD);

	{
		result[0] = new long[0][0];
//		strict[0] = new long[0][0];
		for (int i = 1; i <= 1000; i++) {
			int maxLength;
			for (int j = 1; ; j++) {
				if (j * (j + 1) / 2 > i) {
					maxLength = j - 1;
					break;
				}
			}
			result[i] = new long[maxLength + 1][];
//			strict[i] = new long[maxLength + 1][];
			result[i][0] = new long[0];
//			strict[i][0] = new long[0];
			for (int j = 1; j <= maxLength; j++) {
				result[i][j] = new long[i - j * (j - 1) / 2];
//				strict[i][j] = new long[i - j * (j - 1) / 2];
			}
		}
		ArrayUtils.fill(result, -1);
//		ArrayUtils.fill(strict, -1);
		for (int i = 1; i <= 1000; i++) {
			for (int j = 1; j < result[i].length; j++)
				calculateStrict(i, j, result[i][j].length - 1);
			for (int j = 1; j < result[i - 1].length; j++) {
				for (int k = 0; k < result[i][j].length; k++) {
					result[i][j][k] += result[i - 1][j][Math.min(k, result[i - 1][j].length - 1)];
					result[i][j][k] %= MOD;
				}
			}
		}
	}

	private long calculate(int remaining, int qty, int max) {
		if (qty == 0)
			return 1;
		if (result[remaining].length <= qty || max < 0)
			return 0;
		max = Math.min(max, result[remaining][qty].length - 1);
		if (result[remaining][qty][max] != -1)
			return result[remaining][qty][max];
		return result[remaining][qty][max] = (calculate(remaining - 1, qty, max) + calculateStrict(remaining, qty, max)) % MOD;
	}

	private long calculateStrict(int remaining, int qty, int max) {
		if (result[remaining].length <= qty || result[remaining][qty].length <= max || max < 0)
			return 0;
		if (result[remaining][qty][max] != -1)
			return result[remaining][qty][max];
		return result[remaining][qty][max] = (calculateStrict(remaining, qty, max - 1) + calculate(remaining - max - 1, qty - 1, max - 1)) % MOD;
	}

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int qty = in.readInt();
		if (result[count].length <= qty)
			out.printLine(0);
		else
			out.printLine(result[count][qty][result[count][qty].length - 1] * factorial[qty] % MOD);
    }
}

class IntegerUtils {

    public static long[] generateFactorial(int count, long module) {
		long[] result = new long[count];
		if (module == -1) {
			if (count != 0)
				result[0] = 1;
			for (int i = 1; i < count; i++)
				result[i] = result[i - 1] * i;
		} else {
			if (count != 0)
				result[0] = 1 % module;
			for (int i = 1; i < count; i++)
				result[i] = (result[i - 1] * i) % module;
		}
		return result;
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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public String next() {
		return readString();
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