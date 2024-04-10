import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int repeats = in.readInt();
		int[] openCost = IOUtils.readIntArray(in, count);
		int[] closeCost = IOUtils.readIntArray(in, count);
		long[][][] answer = new long[count + 1][2 * count + 1][count + 1];
		ArrayUtils.fill(answer, Long.MAX_VALUE);
		answer[0][count][0] = 0;
		for (int i = 0; i < count; i++) {
			for (int j = 0; j <= 2 * count; j++) {
				for (int k = 0; k < count; k++) {
					if (answer[i][j][k] == Long.MAX_VALUE)
						continue;
					answer[i + 1][j + 1][k] = Math.min(answer[i + 1][j + 1][k], answer[i][j][k] + openCost[i]);
					answer[i + 1][j - 1][Math.max(k, count - j + 1)] = Math.min(answer[i + 1][j - 1][Math.max(k, count - j + 1)], answer[i][j][k] + closeCost[i]);
				}
			}
		}
		long[][] delta = answer[count];
		long[][] matrix = new long[3 * count + 1][3 * count + 1];
		ArrayUtils.fill(matrix, Long.MAX_VALUE / 2);
		for (int i = 0; i < matrix.length; i++) {
			for (int j = Math.max(0, count - i); j <= 2 * count && i + j - count < matrix.length; j++) {
				for (int k = 0; k <= i && k <= count; k++)
					matrix[i][i + j - count] = Math.min(matrix[i][i + j - count], delta[j][k]);
			}
		}
		long[][] result = new long[matrix.length][matrix.length];
		long[][] temp = new long[matrix.length][matrix.length];
		power(repeats, result, temp, matrix);
		out.printLine(result[0][0]);
    }

	private void power(int exponent, long[][] result, long[][] temp, long[][] matrix) {
		if (exponent == 1) {
			for (int i = 0; i < matrix.length; i++)
				System.arraycopy(matrix[i], 0, result[i], 0, matrix.length);
			return;
		}
		if ((exponent & 1) == 0) {
			power(exponent >> 1, temp, result, matrix);
			multiply(result, temp, temp);
		} else {
			power(exponent - 1, temp, result, matrix);
			multiply(result, temp, matrix);
		}
	}

	private void multiply(long[][] a, long[][] b, long[][] c) {
		ArrayUtils.fill(a, Long.MAX_VALUE / 2);
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length; j++) {
				for (int k = 0; k < a.length; k++)
					a[i][k] = Math.min(a[i][k], b[i][j] + c[j][k]);
			}
		}
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

	}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
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