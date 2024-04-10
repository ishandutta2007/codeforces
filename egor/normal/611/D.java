import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Random;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskD {
		private static final long MOD = (long) (1e9 + 7);

		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			char[] digits = IOUtils.readCharArray(in, n);
			StringHash hash = new SimpleStringHash(new String(digits));
			int[] array = StringUtils.suffixArray(new String(digits));
			long[][] answer = new long[n][n + 1];
			for (int i = n - 1; i >= 0; i--) {
				if (digits[i] == '0') {
					continue;
				}
				answer[i][n - i] = 1;
				for (int j = n - i - 1; j >= 1; j--) {
					answer[i][j] = answer[i][j + 1];
					if (i + 2 * j > n) {
						continue;
					}
					if (hash.hash(i, i + j) != hash.hash(i + j, i + 2 * j) && array[i] < array[i + j]) {
						answer[i][j] += answer[i + j][j];
					} else {
						answer[i][j] += answer[i + j][j + 1];
					}
					answer[i][j] %= MOD;
				}
			}
			out.printLine(answer[0][1]);
		}

	}

	static class SimpleStringHash extends AbstractStringHash {
		private static long[] firstReversePower = new long[0];
		private static long[] secondReversePower = new long[0];
		private final long[] firstHash;
		private final long[] secondHash;

		public SimpleStringHash(CharSequence string) {
			int length = string.length();
			ensureCapacity(length);
			firstHash = new long[length + 1];
			secondHash = new long[length + 1];
			long firstPower = 1;
			long secondPower = 1;
			for (int i = 0; i < length; i++) {
				firstHash[i + 1] = (firstHash[i] + string.charAt(i) * firstPower) % AbstractStringHash.FIRST_MOD;
				secondHash[i + 1] = (secondHash[i] + string.charAt(i) * secondPower) % AbstractStringHash.SECOND_MOD;
				firstPower *= AbstractStringHash.MULTIPLIER;
				firstPower %= AbstractStringHash.FIRST_MOD;
				secondPower *= AbstractStringHash.MULTIPLIER;
				secondPower %= AbstractStringHash.SECOND_MOD;
			}
		}

		private void ensureCapacity(int length) {
			if (firstReversePower.length >= length)
				return;
			length = Math.max(length + 1, firstReversePower.length << 1);
			long[] oldFirst = firstReversePower;
			long[] oldSecond = secondReversePower;
			firstReversePower = new long[length];
			secondReversePower = new long[length];
			System.arraycopy(oldFirst, 0, firstReversePower, 0, oldFirst.length);
			System.arraycopy(oldSecond, 0, secondReversePower, 0, oldSecond.length);
			firstReversePower[0] = secondReversePower[0] = 1;
			for (int i = Math.max(oldFirst.length, 1); i < length; i++) {
				firstReversePower[i] = firstReversePower[i - 1] * AbstractStringHash.FIRST_REVERSE_MULTIPLIER % AbstractStringHash.FIRST_MOD;
				secondReversePower[i] = secondReversePower[i - 1] * AbstractStringHash.SECOND_REVERSE_MULTIPLIER % AbstractStringHash.SECOND_MOD;
			}
		}

		public long hash(int from, int to) {
			return (((firstHash[to] - firstHash[from] + AbstractStringHash.FIRST_MOD) * firstReversePower[from] % AbstractStringHash.FIRST_MOD) << 32) +
				((secondHash[to] - secondHash[from] + AbstractStringHash.SECOND_MOD) * secondReversePower[from] % AbstractStringHash.SECOND_MOD);
		}

	}

	static interface StringHash {
		long hash(int from, int to);

	}

	static class StringUtils {
		public static int[] suffixArray(CharSequence s) {
			int length = s.length();
			int[] position = new int[length];
			int[] count = new int[Math.max(256, length)];
			int[] order = new int[length];
			for (int i = 0; i < length; ++i)
				count[s.charAt(i)]++;
			for (int i = 1; i < 256; ++i)
				count[i] += count[i - 1];
			for (int i = 0; i < length; ++i)
				position[--count[s.charAt(i)]] = i;
			order[position[0]] = 0;
			int currentClass = 0;
			for (int i = 1; i < length; ++i) {
				if (s.charAt(position[i]) != s.charAt(position[i - 1]))
					currentClass++;
				order[position[i]] = currentClass;
			}
			int[] nextPosition = new int[length];
			int[] nextOrder = new int[length];
			for (int h = 0; (1 << h) < length; h++) {
				for (int i = 0; i < length; ++i) {
					nextPosition[i] = position[i] - (1 << h);
					if (nextPosition[i] < 0) nextPosition[i] += length;
				}
				Arrays.fill(count, 0);
				for (int i = 0; i < length; ++i)
					count[order[nextPosition[i]]]++;
				for (int i = 1; i <= currentClass; ++i)
					count[i] += count[i - 1];
				for (int i = length - 1; i >= 0; --i)
					position[--count[order[nextPosition[i]]]] = nextPosition[i];
				nextOrder[position[0]] = 0;
				currentClass = 0;
				for (int i = 1; i < length; ++i) {
					int mid1 = (position[i] + (1 << h));
					if (mid1 >= length)
						mid1 -= length;
					int mid2 = (position[i - 1] + (1 << h));
					if (mid2 >= length)
						mid2 -= length;
					if (order[position[i]] != order[position[i - 1]] || order[mid1] != order[mid2])
						currentClass++;
					nextOrder[position[i]] = currentClass;
				}
				System.arraycopy(nextOrder, 0, order, 0, length);
			}
			return order;
		}

	}

	static class IOUtils {
		public static char[] readCharArray(InputReader in, int size) {
			char[] array = new char[size];
			for (int i = 0; i < size; i++)
				array[i] = in.readCharacter();
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

	static abstract class AbstractStringHash implements StringHash {
		public static final long MULTIPLIER;
		protected static final long FIRST_REVERSE_MULTIPLIER;
		protected static final long SECOND_REVERSE_MULTIPLIER;
		public static final long FIRST_MOD;
		public static final long SECOND_MOD;

		static {
			Random random = new Random(System.currentTimeMillis());
			FIRST_MOD = IntegerUtils.nextPrime((long) (1e9 + random.nextInt((int) 1e9)));
			SECOND_MOD = IntegerUtils.nextPrime((long) (1e9 + random.nextInt((int) 1e9)));
			MULTIPLIER = random.nextInt((int) 1e9 - 257) + 257;
			FIRST_REVERSE_MULTIPLIER = IntegerUtils.reverse(MULTIPLIER, FIRST_MOD);
			SECOND_REVERSE_MULTIPLIER = IntegerUtils.reverse(MULTIPLIER, SECOND_MOD);
		}
	}

	static class IntegerUtils {
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

		public static boolean isPrime(long number) {
			if (number < 2)
				return false;
			for (long i = 2; i * i <= number; i++) {
				if (number % i == 0)
					return false;
			}
			return true;
		}

		public static long nextPrime(long from) {
			if (from <= 2)
				return 2;
			from += 1 - (from & 1);
			while (!isPrime(from))
				from += 2;
			return from;
		}

	}

	static class InputReader {
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

		public char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);

		}

	}
}