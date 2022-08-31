import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskD {
	private InputReader in;
	private PrintWriter out;

	public static void main(String[] args) {
		TaskD solver = new TaskD();
		solver.run();
		solver.out.close();
	}

	public TaskD() {
//		String id = getClass().getName().toLowerCase();
//		try {
//			System.setIn(new FileInputStream(id + ".in"));
//			System.setOut(new PrintStream(new FileOutputStream(id + ".out")));
//			System.setIn(new FileInputStream("input.txt"));
//			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
//		} catch (FileNotFoundException e) {
//			throw new RuntimeException();
//		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	public boolean run() {
		int n = in.readInt();
		int m = in.readInt();
		int k = in.readInt() + 1;
		int[][] t = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				t[i][j] = in.readCharacter() - '0';
		}
		int[][][] d = new int[n][m][k];
		boolean[][][] l = new boolean[n][m][k];
		for (int[][] dd : d) {
			for (int[] ddd : dd)
				Arrays.fill(ddd, Integer.MIN_VALUE);
		}
		for (int i = 0; i < m; i++)
			d[n - 1][i][t[n - 1][i] % k] = t[n - 1][i];
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				for (int o = 0; o < k; o++) {
					if (j == 0 || j != m - 1 && d[i + 1][j + 1][o] > d[i + 1][j - 1][o]) {
						d[i][j][(o + t[i][j]) % k] = d[i + 1][j + 1][o] + t[i][j];
						l[i][j][(o + t[i][j]) % k] = false;
					} else {
						d[i][j][(o + t[i][j]) % k] = d[i + 1][j - 1][o] + t[i][j];
						l[i][j][(o + t[i][j]) % k] = true;
					}
				}
			}
		}
		int ans = -1;
		for (int i = 0; i < m; i++)
			ans = Math.max(ans, d[0][i][0]);
		out.println(ans);
		if (ans != -1) {
			StringBuilder builder = new StringBuilder(n - 1);
			int pos = -1;
			for (int i = 0; i < m; i++) {
				if (d[0][i][0] == ans)
					pos = i;
			}
			int r = 0;
			for (int i = 0; i < n - 1; i++) {
				if (l[i][pos][r]) {
					r = (r - t[i][pos] + 100 * k) % k;
					pos--;
					builder.append('R');
				} else {
					r = (r - t[i][pos] + 100 * k) % k;
					pos++;
					builder.append('L');
				}
			}
			out.println(pos + 1);
			out.println(builder.reverse());
		}
		return true;
	}

	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar, numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		private int read() {
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
				if (c < '0' || c > '9') {
					if (c == 'e' || c == 'E') {
						int e = readInt();
						return res * Math.pow(10, e);
					}
					throw new InputMismatchException();
				}
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') {
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) {
					if (c == 'e' || c == 'E') {
						int e = readInt();
						return res * Math.pow(10, e);
					}
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}
	}
}