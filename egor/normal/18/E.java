import java.io.*;
import java.math.BigInteger;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskE implements Runnable {
	private InputReader in;
	private PrintWriter out;

	public static void main(String[] args) {
//		new Thread(new Template()).start();
		new TaskE().run();
	}

	public TaskE() {
		String id = getClass().getName().toLowerCase();
//		try {
//			System.setIn(new FileInputStream(id + ".in"));
//			System.setOut(new PrintStream(new FileOutputStream(id + ".out")));
//		} catch (FileNotFoundException e) {
//			throw new RuntimeException();
//		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	public void run() {
//        int numTests = in.readInt();
//        for (int testNumber = 0; testNumber < numTests; testNumber++) {
//        }
		int n = in.readInt();
		int m = in.readInt();
		char[][] t = new char[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				t[i][j] = in.readCharacter();
		}
		int[][][] res = new int[n][26][26];
		int[][][] last1 = new int[n][26][26];
		int[][][] last2 = new int[n][26][26];
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				if (i == j)
					res[0][i][j] = n * m + 1;
				else {
					for (int k = 0; k < m; k++) {
						if (k % 2 == 0 && t[0][k] != i + 'a' || k % 2 == 1 && t[0][k] != j + 'a')
							res[0][i][j]++;
					}
				}
			}
		}
		for (int i = 1; i < n; i++) {
			int[] v1 = new int[26];
			int[] v2 = new int[26];
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < m; k += 2) {
					if (t[i][k] != 'a' + j)
						v1[j]++;
				}
				for (int k = 1; k < m; k += 2) {
					if (t[i][k] != 'a' + j)
						v2[j]++;
				}
			}
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < 26; k++) {
					if (j == k) {
						res[i][j][k] = n * m + 1;
						continue;
					}
					int best = n * m + 1;
					int bestj = -1;
					int bestk = -1;
					for (int j1 = 0; j1 < 26; j1++) {
						if (j1 == j)
							continue;
						for (int k1 = 0; k1 < 26; k1++) {
							if (k1 == k)
								continue;
							if (res[i - 1][j1][k1] < best) {
								best = res[i - 1][j1][k1];
								bestj = j1;
								bestk = k1;
							}
						}
					}
					last1[i][j][k] = bestj;
					last2[i][j][k] = bestk;
					res[i][j][k] = best + v1[j] + v2[k];
				}
			}
		}
		int ans = n * m + 1;
		int cj = -1;
		int ck = -1;
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				if (res[n - 1][i][j] < ans) {
					ans = res[n - 1][i][j];
					cj = i;
					ck = j;
				}
			}
		}
		out.println(ans);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				if (j % 2 == 0)
					t[i][j] = (char) (cj + 'a');
				else
					t[i][j] = (char) (ck + 'a');
			}
			int nj = last1[i][cj][ck];
			ck = last2[i][cj][ck];
			cj = nj;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				out.print(t[i][j]);
			out.println();
		}
		out.close();
	}

	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1000];
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