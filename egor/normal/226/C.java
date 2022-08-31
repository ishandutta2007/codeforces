import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
		int mod = in.readInt();
		long left = in.readLong();
		long right = in.readLong();
		long count = in.readLong();
		long required = count;
		long power;
		while (true) {
			power = right / required;
			if (right / power - (left - 1) / power >= count)
				break;
			required = count + (left - 1) / power;
		}
		long[] result = Matrix.power(new long[]{1, 1, 1, 0}, power - 1, mod, 2);
		out.printLine(result[0]);
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

class Matrix {
	public final long[][] data;
	public final int rowCount;
	public final int columnCount;

	public Matrix(int rowCount, int columnCount) {
		this.rowCount = rowCount;
		this.columnCount = columnCount;
		this.data = new long[rowCount][columnCount];
	}

	public Matrix(long[][] data) {
		this.rowCount = data.length;
		this.columnCount = data[0].length;
		this.data = data;
	}

	public static long[] power(long[] matrix, long exponent, long mod, int side) {
		long[] result = new long[matrix.length];
		long[] temp = new long[result.length];
		power(matrix, result, temp, exponent, mod, side);
		return result;
	}

	private static void power(long[] matrix, long[] result, long[] temp, long exponent, long mod, int side) {
		if (exponent == 0) {
			for (int i = 0; i < matrix.length; i += side + 1)
				result[i] = 1 % mod;
			return;
		}
		if ((exponent & 1) == 0) {
			power(matrix, temp, result, exponent >> 1, mod, side);
			multiply(result, temp, temp, mod, side);
		} else {
			power(matrix, temp, result, exponent - 1, mod, side);
			multiply(result, temp, matrix, mod, side);
		}
	}

	private static void multiply(long[] c, long[] a, long[] b, long mod, int side) {
		Arrays.fill(c, 0);
		for (int i = 0; i < side; i++) {
			for (int j = 0; j < side; j++) {
				for (int k = 0; k < side; k++)
					c[i * side + k] += a[i * side + j] * b[j * side + k] % mod;
			}
		}
		for (int i = 0; i < c.length; i++)
			c[i] %= mod;
	}

	}