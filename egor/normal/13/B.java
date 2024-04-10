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
	private static final double EPS = 1e-12;

	public static void main(String[] args) {
		new Thread(new TaskB()).start();
//		new Template().run();
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
        int numTests = in.readInt();
        for (int testNumber = 0; testNumber < numTests; testNumber++) {
			int[] x1 = new int[3];
			int[] x2 = new int[3];
			int[] y1 = new int[3];
			int[] y2 = new int[3];
			for (int i = 0; i < 3; i++) {
				x1[i] = in.readInt();
				y1[i] = in.readInt();
				x2[i] = in.readInt();
				y2[i] = in.readInt();
			}
			int dash = -1;
			outer:
			for (int i = 0; i < 3; i++) {
				for (int j = i + 1; j < 3; j++) {
					if (x1[i] == x1[j] && y1[i] == y1[j]) {
						dash = 3 - i - j;
						int x = x1[i];
						int y = y1[i];
						for (int k = 0; k < 3; k++) {
							x1[k] -= x;
							x2[k] -= x;
							y1[k] -= y;
							y2[k] -= y;
						}
						break outer;
					}
					if (x1[i] == x2[j] && y1[i] == y2[j]) {
						dash = 3 - i - j;
						int x = x1[i];
						int y = y1[i];
						for (int k = 0; k < 3; k++) {
							x1[k] -= x;
							x2[k] -= x;
							y1[k] -= y;
							y2[k] -= y;
						}
						break outer;
					}
					if (x2[i] == x1[j] && y2[i] == y1[j]) {
						dash = 3 - i - j;
						int x = x2[i];
						int y = y2[i];
						for (int k = 0; k < 3; k++) {
							x1[k] -= x;
							x2[k] -= x;
							y1[k] -= y;
							y2[k] -= y;
						}
						break outer;
					}
					if (x2[i] == x2[j] && y2[i] == y2[j]) {
						dash = 3 - i - j;
						int x = x2[i];
						int y = y2[i];
						for (int k = 0; k < 3; k++) {
							x1[k] -= x;
							x2[k] -= x;
							y1[k] -= y;
							y2[k] -= y;
						}
						break outer;
					}
				}
			}
			if (dash == -1) {
				out.println("NO");
				continue;
			}
			{
				int t = x1[dash];
				x1[dash] = x1[0];
				x1[0] = t;
			}
			{
				int t = x2[dash];
				x2[dash] = x2[0];
				x2[0] = t;
			}
			{
				int t = y1[dash];
				y1[dash] = y1[0];
				y1[0] = t;
			}
			{
				int t = y2[dash];
				y2[dash] = y2[0];
				y2[0] = t;
			}
			double ang = Math.atan2(y1[1] + y2[1], x1[1] + x2[1]) - Math.atan2(y1[2] + y2[2], x1[2] + x2[2]);
			while (ang > Math.PI)
				ang -= 2 * Math.PI;
			while (ang < -Math.PI)
				ang += 2 * Math.PI;
			if (Math.abs(ang) < EPS || Math.abs(ang) > Math.PI / 2 + EPS) {
				out.println("NO");
				continue;
			}
			boolean good = false;
			for (int i = 1; i < 3; i++) {
				{
					long dx1 = x1[i] - x1[0];
					long dx2 = x2[i] - x1[0];
					long dy1 = y1[i] - y1[0];
					long dy2 = y2[i] - y1[0];
					if (!(dx1 * dy2 == dy1 * dx2 && dx1 * dx2 <= 0 && dy1 * dy2 <= 0 && Math.max(Math.abs(dx1), Math.abs(dx2)) <= 4 * Math.min(Math.abs(dx1), Math.abs(dx2)) && Math.max(Math.abs(dy1), Math.abs(dy2)) <= 4 * Math.min(Math.abs(dy1), Math.abs(dy2))))
						continue;
				}
				{
					long dx1 = x1[3 - i] - x2[0];
					long dx2 = x2[3 - i] - x2[0];
					long dy1 = y1[3 - i] - y2[0];
					long dy2 = y2[3 - i] - y2[0];
					if (!(dx1 * dy2 == dy1 * dx2 && dx1 * dx2 <= 0 && dy1 * dy2 <= 0 && Math.max(Math.abs(dx1), Math.abs(dx2)) <= 4 * Math.min(Math.abs(dx1), Math.abs(dx2)) && Math.max(Math.abs(dy1), Math.abs(dy2)) <= 4 * Math.min(Math.abs(dy1), Math.abs(dy2))))
						continue;
				}
				good = true;
				break;
			}
			if (good)
				out.println("YES");
			else
				out.println("NO");
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