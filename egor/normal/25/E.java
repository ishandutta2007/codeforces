import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskE implements Runnable {
	private InputReader in;
	private PrintWriter out;
	private long[] h;

	public static void main(String[] args) {
		new Thread(new TaskE()).start();
//		new Template().run();
	}

	public TaskE() {
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

	public void run() {
//        int numTests = in.readInt();
//        for (int testNumber = 0; testNumber < numTests; testNumber++) {
//        }
		char[] a = in.readString().toCharArray();
		char[] b = in.readString().toCharArray();
		char[] c = in.readString().toCharArray();
		h = new long[Math.max(a.length, Math.max(b.length, c.length)) + 1];
		h[0] = 1;
		for (int i = 1; i < h.length; i++)
			h[i] = h[i - 1] * 27;
		int ans = Integer.MAX_VALUE;
		ans = Math.min(ans, go(a, b, c));
		ans = Math.min(ans, go(a, c, b));
		ans = Math.min(ans, go(b, a, c));
		ans = Math.min(ans, go(b, c, a));
		ans = Math.min(ans, go(c, a, b));
		ans = Math.min(ans, go(c, b, a));
		out.println(ans);
		out.close();
	}

	private int go(char[] a, char[] b, char[] c) {
		long[] ha = hash(a);
		long[] hb = hash(b);
		long[] hc = hash(c);
		if (contains(ha, hb)) {
			if (contains(hb, hc))
				return a.length;
			else
				return construct(ha, hc);
		} else {
			if (contains(hb, hc))
				return construct(ha, hb);
			else
				return construct(ha, hb) + construct(hb, hc) - b.length;
		}
	}

	private int construct(long[] a, long[] b) {
		int l = a.length - 1;
		for (int i = 0; i < l; i++) {
			if (l - i < b.length && a[l] - a[i] == (b[l - i] - b[0]) * h[i])
				return b.length - 1 + i;
		}
		return l + b.length - 1;
	}

	private boolean contains(long[] a, long[] b) {
		int l = b.length - 1;
		for (int i = 0; i < a.length - b.length; i++) {
			if (a[l + i] - a[i] == b[l] * h[i])
				return true;
		}
		return false;
	}

	private long[] hash(char[] a) {
		long[] r = new long[a.length + 1];
		for (int i = 0; i < a.length; i++)
			r[i + 1] = r[i] + (a[i] - 'a') * h[i];
		return r;
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