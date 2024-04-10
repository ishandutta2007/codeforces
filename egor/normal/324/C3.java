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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	long answer = 0;
	private long[][][] result;
	private int[][][] digit;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		long current = in.readLong();
		int curLast = (int) (current % 10);
		long tens = current / 10;
		result = new long[20][10][10];
		digit = new int[20][10][10];
		long[] ten = IntegerUtils.generatePowers(10, 19, Long.MAX_VALUE);
		ArrayUtils.fill(result, -1);
		while (tens > 0) {
			int lengthNines = 0;
			long copy = tens;
			while (copy % 10 == 9) {
				lengthNines++;
				copy /= 10;
			}
			int max = 0;
			while (copy != 0) {
				max = (int) Math.max(max, copy % 10);
				copy /= 10;
			}
			go(lengthNines, max, curLast);
			answer += result[lengthNines][max][curLast];
			curLast = digit[lengthNines][max][curLast];
			tens -= ten[lengthNines];
		}
		if (tens < 0)
			answer--;
		else if (curLast != 0)
			answer++;
		out.printLine(answer);
    }

	private void go(int nines, int max, int digit) {
		if (result[nines][max][digit] != -1)
			return;
		if (nines == 0) {
			if (digit >= max) {
				result[nines][max][digit] = 2;
				this.digit[nines][max][digit] = 10 - max;
			} else {
				result[nines][max][digit] = 1;
				this.digit[nines][max][digit] = 10 - (max - digit);
			}
			return;
		}
		result[nines][max][digit] = 0;
		this.digit[nines][max][digit] = digit;
		for (int i = 9; i >= 0; i--) {
			go(nines - 1, Math.max(i, max), this.digit[nines][max][digit]);
			result[nines][max][digit] += result[nines - 1][Math.max(i, max)][this.digit[nines][max][digit]];
			this.digit[nines][max][digit] = this.digit[nines - 1][Math.max(i, max)][this.digit[nines][max][digit]];
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

class IntegerUtils {

    public static long[] generatePowers(long base, int count, long mod) {
		long[] result = new long[count];
		if (count != 0)
			result[0] = 1 % mod;
		for (int i = 1; i < count; i++)
			result[i] = result[i - 1] * base % mod;
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