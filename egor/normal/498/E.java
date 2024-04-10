import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int[] width = IOUtils.readIntArray(in, 7);
        long[][] matrices = new long[7][];
        for (int i = 1; i <= 7; i++) {
            long[][] matrix = new long[1 << i][1 << i];
            for (int j = 0; j < (1 << i); j++) {
                for (int k = 0; k < (1 << i); k++) {
                    for (int l = 0; l < (1 << (i - 1)); l++) {
                        int mask = 2 * l + 1 + (1 << i);
                        boolean good = true;
                        for (int m = 0; m < i; m++) {
                            if ((j >> m & 1) == 1 && (k >> m & 1) == 1 && (mask >> m & 1) == 1 && (mask >> (m + 1) & 1) == 1) {
                                good = false;
                                break;
                            }
                        }
                        if (good) {
                            matrix[j][k]++;
                        }
                    }
                }
            }
            matrices[i - 1] = Matrix.convert(matrix);
        }
        Matrix.mod = (long) (1e9 + 7);
        long[] result = new long[128];
        result[127] = 1;
        for (int i = 7; i >= 1; i--) {
            long[][] current = Matrix.convert(Matrix.power(matrices[i - 1], width[i - 1], Matrix.mod, 1 << i), 1 << i);
            long[] next = new long[result.length >> 1];
            for (int j = 0; j < next.length; j++) {
                for (int k = 0; k < result.length; k++) {
                    next[j] += current[j + next.length][k] * result[k] % Matrix.mod;
                }
                next[j] %= Matrix.mod;
            }
            result = next;
        }
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

class Matrix {
	public static long mod = Long.MAX_VALUE;

	public static long[] convert(long[][] matrix) {
		long[] result = new long[matrix.length * matrix.length];
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix.length; j++)
				result[i * matrix.length + j] = matrix[i][j];
		}
		return result;
	}

	public static long[][] convert(long[] matrix, int side) {
		long[][] result = new long[side][side];
		for (int i = 0; i < side; i++) {
			for (int j = 0; j < side; j++)
				result[i][j] = matrix[i * side + j];
		}
		return result;
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

	public static void multiply(long[] c, long[] a, long[] b, long mod, int side) {
		Arrays.fill(c, 0);
		for (int i = 0; i < side; i++) {
			for (int j = 0; j < side; j++) {
				for (int k = 0; k < side; k++) {
					c[i * side + k] += a[i * side + j] * b[j * side + k];
					if ((j & 3) == 3) {
						c[i * side + k] %= mod;
					}
				}
			}
		}
		for (int i = 0; i < c.length; i++)
			c[i] %= mod;
	}

}