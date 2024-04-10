import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.io.OutputStreamWriter;

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
	private static final long MOD = 998244353;
	private int rootPower = 1 << 23;
	private long root = 31;
	private long reverseRoot = IntegerUtils.reverse(root, MOD);

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int upTo = in.readInt();
		int[] good = IOUtils.readIntArray(in, count);
		long[] base = new long[4 * upTo + 1];
		for (int i : good) {
			if (i <= upTo)
				base[i] = 1;
		}
		long[] answer = new long[4 * upTo + 1];
		answer[0] = 1;
		int STEP = 7000;
		long[] two = new long[4 * upTo + 1];
		long[] cTwo = new long[4 * upTo + 1];
		long[] next = new long[4 * upTo + 1];
		for (int i = 1; i <= upTo; i += STEP) {
			multiply(two, answer, answer, Math.min(i + STEP, upTo + 1));
			for (int j = 0; j < i; j++)
				cTwo[j] = two[j];
			multiply(next, cTwo, base, Math.min(i + STEP, upTo + 1));
			for (int j = i; j <= upTo && j < i + STEP; j++) {
				answer[j] = next[j];
				for (int k = j - 1; k >= i; k--) {
					if (base[j - k] == 1)
						answer[j] += two[k];
				}
				answer[j] %= MOD;
				for (int k = j; k <= upTo && k < i + STEP; k++) {
					if (k - j > j)
						break;
					if (k - j == j)
						two[k] += answer[j] * answer[j];
					else
						two[k] += 2 * answer[j] * answer[k - j];
					two[k] %= MOD;
				}
			}
		}
		for (int i = 0; i < upTo; i++) {
			out.printLine(answer[i + 1]);
		}
	}

	long[] aa;
	long[] bb;

	private void multiply(long[] result, long[] first, long[] second, int length) {
		if (aa == null) {
			aa = new long[result.length];
			bb = new long[result.length];
		}
		int resultSize = Integer.highestOneBit(length - 1) << 2;
		resultSize = Math.max(resultSize, 4);
		Arrays.fill(aa, 0, resultSize, 0);
		Arrays.fill(bb, 0, resultSize, 0);
		for (int i = 0; i < length; i++)
			aa[i] = first[i];
		for (int i = 0; i < length; i++)
			bb[i] = second[i];
		fft(aa, false, resultSize);
		if (first == second) {
			System.arraycopy(aa, 0, bb, 0, resultSize);
		} else
			fft(bb, false, resultSize);
		for (int i = 0; i < resultSize; i++) {
			aa[i] *= bb[i];
			aa[i] %= MOD;
		}
		fft(aa, true, resultSize);
		for (int i = 0; i < length; i++)
			result[i] = aa[i];

	}

	private void fft(long[] array, boolean invert, int size) {
		for (int i = 1, j = 0; i < size; ++i) {
			int bit = size >> 1;
			for (; j >= bit; bit >>= 1)
				j -= bit;
			j += bit;
			if (i < j) {
				long temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}

		for (int len = 2; len <= size; len <<= 1) {
			long wlen = invert ? reverseRoot : root;
			for (int i = len; i < rootPower; i <<= 1)
				wlen =	wlen * wlen % MOD;
			int half = len >> 1;
			for (int i = 0; i < size; i += len) {
				long w = 1;
				for (int j = 0; j < half; ++j) {
					long u = array[i + j], v = array[i + j + half] * w % MOD;
					array[i + j] = u + v < MOD ? u + v : u + v - MOD;
					array[i + j + half] = u - v >= 0 ? u - v : u - v + MOD;
					w =	w * wlen % MOD;
				}
			}
		}
		if (invert) {
			long reverseSize = IntegerUtils.reverse(size, MOD);
			for (int i = 0; i < size; ++i)
				array[i] = array[i] * reverseSize % MOD;
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

	public static long reverse(long number, long module) {
		return power(number, module - 2, module);
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