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
public class TaskD implements Runnable {
	private InputReader in;
	private PrintWriter out;
	private static final int INF = 1000000000;

	public static void main(String[] args) {
//		new Thread(new Template()).start();
		new TaskD().run();
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

	public void run() {
//        int numTests = in.readInt();
//        for (int testNumber = 0; testNumber < numTests; testNumber++) {
//			out.print("Case " + (testNumber + 1) + ": ");
//        }
		int n = in.readInt();
		int m = in.readInt();
		int ans = 0;
		int[][] e = new int[n][n];
		int[] d = new int[n];
		for (int[] ee : e)
			Arrays.fill(ee, INF);
		for (int i = 0; i < n; i++)
			e[i][i] = 0;
		for (int i = 0; i < m; i++) {
			int x = in.readInt() - 1;
			int y = in.readInt() - 1;
			int w = in.readInt();
			ans += w;
			e[x][y] = e[y][x] = Math.min(e[x][y], w);
			d[x]++;
			d[y]++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++)
					e[j][k] = Math.min(e[j][k], e[j][i] + e[i][k]);
			}
		}
		boolean good = true;
		for (int i = 1; i < n; i++) {
			if (e[0][i] == INF && d[i] > 0)
				good = false;
		}
		if (!good)
			out.println(-1);
		else {
			int[] r = new int[1 << n];
			Arrays.fill(r, INF);
			r[0] = 0;
			for (int i = 0; i < (1 << n); i++) {
				for (int j = 0; j < n; j++) {
					if (((i >> j) & 1) == 0) {
						if (d[j] % 2 == 0)
							r[i + (1 << j)] = Math.min(r[i + (1 << j)], r[i]);
						else {
							for (int k = j + 1; k < n; k++) {
								if (((i >> k) & 1) == 0 && d[k] % 2 == 1)
									r[i + (1 << j) + (1 << k)] = Math.min(r[i + (1 << j) + (1 << k)], r[i] + e[j][k]);
							}
						}
					}
				}
			}
			out.println(ans + r[(1 << n) - 1]);
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
}