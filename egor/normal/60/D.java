import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskD {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	private InputReader in;
	private PrintWriter out;

	private void solve() {
		int[] divisor = new int[10000001];
		for (int i = 2; i <= 10000; i++) {
			if (divisor[i] != 0)
				continue;
			for (int j = i * i; j <= 10000000; j += i)
				divisor[j] = i;
		}
		int[] index = new int[10000001];
		int count = in.readInt();
		int[] a = in.readIntArray(count);
		Arrays.sort(a);
		int[] s = new int[count];
		boolean[] joined = new boolean[count];
		for (int i = 0; i < count; i++)
			s[i] = i;
		for (int i = count - 1; i >= 0; i--)
			index[a[i]] = i;
		for (int i = 0; i < count; i++) {
			if (i != 0 && a[i] == a[i - 1]) {
				if (joined[i - 1])
					join(s, i - 1, i, joined);
				continue;
			}
			if (a[i] % 2 == 0)
				findDivisors(a[i] / 2, index, divisor, true, 1, 1, s, joined, i);
			else
				findDivisors(a[i], index, divisor, false, 1, 1, s, joined, i);
		}
		int result = 1;
		for (int i = 0; i < count; i++) {
			if (head(s, i) != head(s, 0)) {
				join(s, 0, i, joined);
				result++;
			}
		}
		out.println(result);
	}

	private void findDivisors(int multiple, int[] index, int[] divisor, boolean even, int first, int second, int[] s, boolean[] joined, int originalIndex) {
		if (multiple == 1) {
			if (first < second)
				return;
			long u, v;
			if (even) {
				u = first;
				v = second;
			} else {
				u = (first + second) / 2;
				v = (first - second) / 2;
			}
			long candidate1 = u * u - v * v;
			long candidate2 = 2 * u * v + 0;
			long candidate3 = u * u + v * v + 0;
			if (candidate1 % 2 == 0 && candidate2 % 2 == 0)
				return;
			if (candidate1 <= 10000000 && index[((int) candidate1)] != 0)
				join(s, index[((int) candidate1)], originalIndex, joined);
			if (candidate2 <= 10000000 && index[((int) candidate2)] != 0)
				join(s, index[((int) candidate2)], originalIndex, joined);
			if (candidate3 <= 10000000 && index[((int) candidate3)] != 0)
				join(s, index[((int) candidate3)], originalIndex, joined);
			return;
		}
		int curDivisor = divisor[multiple];
		if (curDivisor == 0)
			curDivisor = multiple;
		int totalDivisor = 1;
		do {
			multiple /= curDivisor;
			totalDivisor *= curDivisor;
		} while (multiple % curDivisor == 0);
		findDivisors(multiple, index, divisor, even, first * totalDivisor, second, s, joined, originalIndex);
		findDivisors(multiple, index, divisor, even, first, second * totalDivisor, s, joined, originalIndex);
	}

	private void join(int[] s, int a, int b, boolean[] joined) {
		a = head(s, a);
		b = head(s, b);
		if (a == b)
			return;
		s[b] = a;
		joined[a] = true;
		joined[b] = true;
	}

	private int head(int[] s, int a) {
		if (s[a] == a)
			return a;
		return s[a] = head(s, s[a]);
	}

	public static void main(String[] args) {
		new TaskD().run();
	}

	private TaskD() {
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