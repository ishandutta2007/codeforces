import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskC implements Runnable {
	private InputReader in;
	private PrintWriter out;

	private int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
	private int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};
	private char[][] t;// = new char[250][250];

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

	public static void main(String[] args) {
//		new Thread(new Template()).start();
		new TaskC().run();
	}

	public TaskC() {
//		String id = getClass().getName().toLowerCase();
//		try {
//			System.setIn(new FileInputStream(id + ".in"));
//			System.setOut(new PrintStream(new FileOutputStream(id + ".out")));
//		} catch (FileNotFoundException e) {
//			throw new RuntimeException();
//		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	private int countNeighbours(int x, int y) {
		int res = 0;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < t.length && ny >= 0 && ny < t[0].length && t[nx][ny] == '1')
				res++;
		}
		return res;
	}

	public void run() {
        int numTests = in.readInt();
        for (int testNumber = 0; testNumber < numTests; testNumber++) {
			int n = in.readInt();
			int m = in.readInt();
			t = new char[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					t[i][j] = in.readCharacter();
			}
			int ans = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (t[i][j] == '1') {
						boolean good = true;
						for (int k = 0; k < 4; k++) {
							int ni = i + dx[k];
							int nj = j + dy[k];
							if (ni >= 0 && ni < n && nj >= 0 && nj < m && t[ni][nj] == '1') {
								good = false;
								break;
							}
						}
						if (!good)
							continue;
						if (i + 1 < n && j + 1 < m && t[i + 1][j] == '1' && t[i + 1][j + 1] == '1' && t[i][j + 1] == '1' && countNeighbours(i, j) == 3 && countNeighbours(i + 1, j) == 3 && countNeighbours(i, j + 1) == 3 && countNeighbours(i + 1, j + 1) == 3) {
							ans++;
							continue;
						}
						if (countNeighbours(i, j) != 2)
							continue;
						if (i + 1 < n && j + 1 < m && t[i + 1][j] == '1' && t[i][j + 1] == '1') {
							int k = 1;
							for (; i + k < n && j + k < m && t[i + k][j] == '1' && t[i][j + k] == '1'; k++) {
//								if (countNeighbours(i, j + k) != 2 || countNeighbours(i + k, j) != 2) {
//									good = false;
//									break;
//								}
							}
							k--;
							for (int l = 1; l <= k; l++) {
								int qn = 2;
								if (l == 1)
									qn++;
								if (l == k - 1)
									qn++;
								if (t[i + k][j + l] != '1' || t[i + l][j + k] != '1' || countNeighbours(i + k, j + l) != qn || countNeighbours(i + l, j + k) != qn) {
									good = false;
									break;
								}
								if (t[i][j + l] != '1' || t[i + l][j] != '1' || countNeighbours(i, j + l) != qn || countNeighbours(i + l, j) != qn) {
									good = false;
									break;
								}
							}
							if (good)
								ans++;
						} else if (i + 1 < n && j + 1 < m && j > 0 && t[i + 1][j - 1] == '1' && t[i + 1][j + 1] == '1') {
							int k = 1;
							for (; i + k < n && j + k < m && j >= k && t[i + k][j - k] == '1' && t[i + k][j + k] == '1'; k++) {
								if (countNeighbours(i + k, j + k) != 2 || countNeighbours(i + k, j - k) != 2) {
									good = false;
									break;
								}
							}
							k--;
							for (int l = 1; l <= k; l++) {
								if (i + k + l >= n || t[i + k + l][j - k + l] != '1' || t[i + k + l][j + k - l] != '1' || countNeighbours(i + k + l, j - k + l) != 2 || countNeighbours(i + k + l, j + k - l) != 2) {
									good = false;
									break;
								}
							}
							if (good)
								ans++;
						}
					}
				}
			}
			out.println(ans);
        }
		out.close();
	}
}