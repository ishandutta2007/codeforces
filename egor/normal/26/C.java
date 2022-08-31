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

	public static void main(String[] args) {
		new Thread(new TaskC()).start();
//		new Template().run();
	}

	public TaskC() {
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
		int a = in.readInt();
		int b = in.readInt();
		int c = in.readInt();
		char[][] t = new char[n][m];
		if (n % 2 == 1) {
			if (m % 2 == 1) {
				out.println("IMPOSSIBLE");
				out.close();
				return;
			}
			if (a >= m / 2) {
				a -= m / 2;
				for (int j = 0; j < m / 2; j++) {
					char cur = 'y';
					if (j % 2 == 1)
						cur = 'z';
					t[n - 1][2 * j] = t[n - 1][2 * j + 1] = cur;
				}
				n--;
			} else {
				out.println("IMPOSSIBLE");
				out.close();
				return;
			}
		}
		if (m % 2 == 1) {
			if (b >= n / 2) {
				b -= n / 2;
				for (int j = 0; j < n / 2; j++) {
					char cur = 'y';
					if (j % 2 == 1)
						cur = 'z';
					t[2 * j][m - 1] = t[2 * j + 1][m - 1] = cur;
				}
				m--;
			} else {
				out.println("IMPOSSIBLE");
				out.close();
				return;
			}
		}
		if (c + a / 2 + b / 2 < m * n / 4) {
			out.println("IMPOSSIBLE");
			out.close();
			return;
		}
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < m / 2; j++) {
				char cur = (char) ('a' + ((i % 2) * 2 + (j % 2)) * 2);
				if (c != 0) {
					t[2 * i][2 * j] = t[2 * i + 1][2 * j] = t[2 * i][2 * j + 1] = t[2 * i + 1][2 * j + 1] = cur;
					c--;
				} else if (a >= 2) {
					a -= 2;
					t[2 * i][2 * j] = t[2 * i][2 * j + 1] = cur;
					t[2 * i + 1][2 * j] = t[2 * i + 1][2 * j + 1] = (char) (cur + 1);
				} else {
					t[2 * i][2 * j] = t[2 * i + 1][2 * j] = cur;
					t[2 * i][2 * j + 1] = t[2 * i + 1][2 * j + 1] = (char) (cur + 1);					
				}
			}
		}
		for (char[] aT : t) {
			for (char anAT : aT)
				out.print(anAT);
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