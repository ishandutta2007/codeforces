import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskE {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	private InputReader in;
	private PrintWriter out;

	private static class Matrix {
		public long[][] m = new long[2][2];
	}

	private static Matrix multiply(Matrix a, Matrix b, int module) {
		Matrix result = new Matrix();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++)
					result.m[i][k] = (result.m[i][k] + a.m[i][j] * b.m[j][k]) % module;
			}
		}
		return result;
	}

	private void solve() {
		int mushroomCount = in.readInt();
		long firstLunchLength = in.readLong();
		long secondLunchLength = in.readLong();
		int module = in.readInt();
		long[] weights = in.readLongArray(mushroomCount);
		if (mushroomCount == 1) {
			out.println(weights[0] % module);
			return;
		}
		long minimum = weights[0] % module;
		long maximum = weights[mushroomCount - 1] % module;
		long sum = 0;
		for (int i = 0; i < mushroomCount; i++)
			sum += weights[i];
		sum %= module;
		long x3 = power(3, firstLunchLength, 2 * module);
		long sumAfterFirstLunch = (x3 * sum) % module - ((x3 - 1) / 2) * (minimum + maximum);
		sumAfterFirstLunch %= module;
		sumAfterFirstLunch += module;
		sumAfterFirstLunch %= module;
		Matrix base = new Matrix();
		base.m[0][0] = 1;
		base.m[0][1] = 1;
		base.m[1][0] = 1;
		Matrix exponent = power(base, firstLunchLength, module);
		maximum = (exponent.m[0][0] * maximum + exponent.m[0][1] * weights[mushroomCount - 2]) % module;
		x3 = power(3, secondLunchLength, 2 * module);
		long finalSum = (x3 * sumAfterFirstLunch) % module - ((x3 - 1) / 2) * (minimum + maximum);
		finalSum %= module;
		finalSum += module;
		finalSum %= module;
		out.println(finalSum);
	}

	public static long power(int base, long exponent, int mod) {
		if (exponent == 0)
			return 1;
		long power = power(base, exponent >> 1, mod);
		power *= power;
		power %= mod;
		if ((exponent & 1) != 0) {
			power *= base;
			power %= mod;
		}
		return power;
	}

	public static Matrix power(Matrix base, long exponent, int mod) {
		if (exponent == 0) {
			Matrix one = new Matrix();
			one.m[0][0] = 1;
			one.m[1][1] = 1;
			return one;
		}
		Matrix power = power(base, exponent >> 1, mod);
		power = multiply(power, power, mod);
		if ((exponent & 1) != 0)
			power = multiply(power, base, mod);
		return power;
	}

	public static void main(String[] args) {
		new TaskE().run();
	}

	private TaskE() {
		@SuppressWarnings({"UnusedDeclaration"})
		String id = getClass().getName().toLowerCase();
		//noinspection EmptyTryBlock
		try {
//			System.setIn(new FileInputStream(id + ".in"));
//			System.setOut(new PrintStream(new FileOutputStream(id + ".out")));
//			System.setIn(new FileInputStream("input.txt"));
//			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	private void run() {
		//noinspection InfiniteLoopStatement
//		int testCount = in.readInt();
//		for (int i = 0; i < testCount; i++)
//		while (true)
		solve();
		exit();
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private void exit() {
		out.close();
		System.exit(0);
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar, numChars;

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

		public String readString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuffer res = new StringBuffer();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private String readLine0() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				if (c != '\r')
					buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		public String readLine() {
			String s = readLine0();
			while (s.trim().length() == 0)
				s = readLine0();
			return s;
		}

		public String readLine(boolean ignoreEmptyLines) {
			if (ignoreEmptyLines)
				return readLine();
			else
				return readLine0();
		}

		public BigInteger readBigInteger() {
			try {
				return new BigInteger(readString());
			} catch (NumberFormatException e) {
				throw new InputMismatchException();
			}
		}

		public char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		public double readDouble() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') {
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) {
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, readInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}

		public int[] readIntArray(int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = readInt();
			return array;
		}

		public long[] readLongArray(int size) {
			long[] array = new long[size];
			for (int i = 0; i < size; i++)
				array[i] = readLong();
			return array;
		}

		public double[] readDoubleArray(int size) {
			double[] array = new double[size];
			for (int i = 0; i < size; i++)
				array[i] = readDouble();
			return array;
		}

		public String[] readStringArray(int size) {
			String[] array = new String[size];
			for (int i = 0; i < size; i++)
				array[i] = readString();
			return array;
		}

		public char[][] readTable(int rowCount, int columnCount) {
			char[][] table = new char[rowCount][columnCount];
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++)
					table[i][j] = readCharacter();
			}
			return table;
		}

		public void readIntArrays(int[]... arrays) {
			for (int i = 0; i < arrays[0].length; i++) {
				for (int j = 0; j < arrays.length; j++)
					arrays[j][i] = readInt();
			}
		}
	}
}