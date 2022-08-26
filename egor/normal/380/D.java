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
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	private static final long MOD = (long) (1e9 + 7);
	private long[] factorial;
	private long[] reverse;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] order = IOUtils.readIntArray(in, count);
		MiscUtils.decreaseByOne(order);
		factorial = IntegerUtils.generateFactorial(count + 1, MOD);
		reverse = IntegerUtils.generateReverseFactorials(count + 1, MOD);
		if (ArrayUtils.count(order, -1) == count) {
			out.printLine(IntegerUtils.power(2, count - 1, MOD));
			return;
		}
		int last = count;
		int left = 0;
		int right = count - 1;
		int leftPosition = 0;
		int rightPosition = count - 1;
		long answer = 1;
		while (true) {
			while (order[left] == -1)
				left++;
			while (order[right] == -1)
				right--;
			if (order[left] >= last || order[right] >= last) {
				out.printLine(0);
				return;
			}
			if (left == right) {
				if (order[left] == 0) {
					answer = answer * c(rightPosition - leftPosition, left - leftPosition) % MOD;
					break;
				}
				int shouldTake = last - order[left] - 1;
				long total = 0;
				if (rightPosition - left <= shouldTake) {
					total += c(shouldTake, rightPosition - left) * IntegerUtils.power(2, order[left] - 1, MOD) % MOD;
				}
				if (left - leftPosition <= shouldTake)
					total += c(shouldTake, left - leftPosition) * IntegerUtils.power(2, order[left] - 1, MOD) % MOD;
				answer = answer * total % MOD;
				break;
			}
			if (order[left] > order[right]) {
				int shouldTake = last - order[left] - 1;
				int leftTake = left - leftPosition;
				int rightTake = shouldTake - leftTake;
				if (leftTake > shouldTake || rightTake > rightPosition - right) {
					out.printLine(0);
					return;
				}
				answer = answer * c(shouldTake, leftTake) % MOD;
				last = order[left];
				leftPosition = ++left;
				rightPosition -= rightTake;
			} else {
				int shouldTake = last - order[right] - 1;
				int rightTake = rightPosition - right;
				int leftTake = shouldTake - rightTake;
				if (rightTake > shouldTake || leftTake > left - leftPosition) {
					out.printLine(0);
					return;
				}
				answer = answer * c(shouldTake, rightTake) % MOD;
				last = order[right];
				rightPosition = --right;
				leftPosition += leftTake;
			}
		}
		out.printLine(answer);
    }

	private long c(int n, int m) {
		return factorial[n] * reverse[m] % MOD * reverse[n - m] % MOD;
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

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	}

class MiscUtils {

    public static void decreaseByOne(int[]...arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

	}

class IntegerUtils {

    public static long power(long base, long exponent, long mod) {
		if (base >= mod)
			base %= mod;
		if (exponent == 0)
			return 1 % mod;
		long result = power(base, exponent >> 1, mod);
		result = result * result % mod;
		if ((exponent & 1) != 0)
			result = result * base % mod;
		return result;
	}

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

	public static long[] generateReverse(int upTo, long module) {
		long[] result = new long[upTo];
		if (upTo > 1)
			result[1] = 1;
		for (int i = 2; i < upTo; i++)
			result[i] = (module - module / i * result[((int) (module % i))] % module) % module;
		return result;
	}

	public static long[] generateReverseFactorials(int upTo, long module) {
		long[] result = generateReverse(upTo, module);
		if (upTo > 0)
			result[0] = 1;
		for (int i = 1; i < upTo; i++)
			result[i] = result[i] * result[i - 1] % module;
		return result;
	}

	}

class ArrayUtils {

	public static int count(int[] array, int value) {
		int result = 0;
		for (int i : array) {
			if (i == value)
				result++;
		}
		return result;
	}

	}