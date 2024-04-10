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
//		new Thread(new Template()).start();
		new TaskC().run();
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
		int[] a = new int[6];
		for (int i = 0; i < 4; i++)
			a[i] = in.readInt();
		while (true) {
			int mx = a[0];
			for (int aa : a)
				mx = Math.max(aa, mx);
			if (mx == 1)
				break;
			int ind = -1;
			for (int i = 0; i < 4; i++) {
				if (a[i] % 2 == 0 && a[(i + 1) % 4] % 2 == 0) {
					ind = i;
					break;
				}
			}
			if (ind != -1) {
				half(a, ind);
				continue;
			}
			for (int i = 0; i < 4; i++) {
				if (a[i] % 2 == 1 && a[(i + 1) % 4] % 2 == 1 && (a[i] != 1 || a[(i + 1) % 4] != 1)) {
					ind = i;
					break;
				}
			}
			if (ind != -1) {
				plus(a, ind);
				continue;
			}
			for (int i = 0; i < 4; i++) {
				if (a[i] % 2 == 1 && a[i] != 1) {
					ind = i;
					break;
				}
			}
			if (ind != -1) {
				plus(a, ind);
				continue;
			}
			if (a[0] % 2 == 0 && a[2] % 2 == 0) {
				plus(a, 1);
				half(a, 0);
				continue;
			}
			if (a[1] % 2 == 0 && a[3] % 2 == 0) {
				plus(a, 2);
				half(a, 1);
				continue;
			}
			for (int i = 0; i < 4; i++) {
				if (a[i] != 1) {
					ind = i;
					break;
				}
			}
			if (a[ind] != 2) {
				plus(a, (ind + 1) % 4);
				half(a, ind);
				continue;
			}
			plus(a, ind);
			plus(a, (ind + 3) % 4);
			half(a, ind);
			half(a, (ind + 3) % 4);
		}
		out.close();
	}

	void plus(int[] a, int ind) {
		a[ind]++;
		a[(ind + 1) % 4]++;
		out.println("+" + (ind + 1));
	}

	void half(int[] a, int ind) {
		a[ind] /= 2;
		a[(ind + 1) % 4] /= 2;
		out.println("/" + (ind + 1));
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