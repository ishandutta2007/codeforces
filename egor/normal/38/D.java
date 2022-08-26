import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskD implements Runnable {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	private InputReader in;
	private PrintWriter out;
	private static final double EPS = 1e-13;

	public static void main(String[] args) throws InterruptedException {
		new TaskD().run();
	}

	public TaskD() {
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

	public void run() {
		solve();
		out.close();
	}

	public boolean solve() {
		int n = in.readInt();
		int[] x1 = new int[n];
		int[] y1 = new int[n];
		int[] x2 = new int[n];
		int[] y2 = new int[n];
		for (int i = 0; i < n; i++) {
			x1[i] = in.readInt();
			y1[i] = in.readInt();
			x2[i] = in.readInt();
			y2[i] = in.readInt();
		}
		int ans = n;
		for (int i = 0; i < n; i++) {
			double x = 0;
			double y = 0;
			double w = 0;
//			int xx1 = Integer.MIN_VALUE;
//			int xx2 = Integer.MAX_VALUE;
//			int yy1 = Integer.MIN_VALUE;
//			int yy2 = Integer.MAX_VALUE;
			boolean good = true;
			for (int j = i; j >= 0; j--) {
//				xx1 = Math.max(xx1, Math.min(x1[j], x2[j]));
//				xx2 = Math.min(xx2, Math.max(x1[j], x2[j]));
//				yy1 = Math.max(yy1, Math.min(y1[j], y2[j]));
//				yy2 = Math.min(yy2, Math.max(y1[j], y2[j]));
				if (j != i) {
					double xx = x / w;
					double yy = y / w;
					if (xx < Math.min(x1[j], x2[j]) - EPS || xx > Math.max(x1[j], x2[j]) + EPS
							|| yy < Math.min(y1[j], y2[j] - EPS) || yy > Math.max(y1[j], y2[j]) + EPS) {
						good = false;
						break;
					}
				}
				int cw = Math.abs(x2[j] - x1[j]);
				cw *= cw * cw;
				x += (x1[j] + x2[j]) / 2. * cw;
				y += (y1[j] + y2[j]) / 2. * cw;
				w += cw;
			}
			if (!good) {
				ans = i;
				break;
			}
		}
		out.println(ans);
		return true;
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
	}
}