import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskB implements Runnable {
	private InputReader in;
	private PrintWriter out;

	public static void main(String[] args) {
//		new Thread(new Template()).start();
		new TaskB().run();
	}

	public TaskB() {
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
		int r1x = in.readCharacter() - 'a';
		int r1y = in.readCharacter() - '1';
		int r2x = in.readCharacter() - 'a';
		int r2y = in.readCharacter() - '1';
		int wkx = in.readCharacter() - 'a';
		int wky = in.readCharacter() - '1';
		int bkx = in.readCharacter() - 'a';
		int bky = in.readCharacter() - '1';
		boolean ans = true;
		for (int i = Math.max(bkx - 1, 0); i <= bkx + 1 && i < 8; i++) {
			for (int j = Math.max(bky - 1, 0); j <= bky + 1 && j < 8; j++) {
				if (!(reachableByRook(i, j, wkx, wky, r1x, r1y) || reachableByRook(i, j, wkx, wky, r2x, r2y) || Math.abs(i - wkx) <= 1 && Math.abs(j - wky) <= 1)) {
					ans = false;
				}
			}
		}
		if (ans)
			out.println("CHECKMATE");
		else
			out.println("OTHER");
		out.close();
	}

	private static final int[] dx = {1, 0, -1, 0};
	private static final int[] dy = {0, -1, 0, 1};

	private boolean reachableByRook(int x, int y, int kx, int ky, int rx, int ry) {
		for (int i = 0; i < 4; i++) {
			int xx = rx;
			int yy = ry;
			while (xx >= 0 && xx < 8 && yy >= 0 && yy < 8) {
				xx += dx[i];
				yy += dy[i];
				if (xx == kx && yy == ky)
					break;
				if (xx == x && yy == y)
					return true;
			}
		}
		return false;
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