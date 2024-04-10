import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;

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
		int k = in.readInt();
		long[] x = new long[n];
		long[] y = new long[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.readInt();
			y[i] = in.readInt();
		}
		final long[] r = new long[m];
		long[] cx = new long[m];
		long[] cy = new long[m];
		for (int i = 0; i < m; i++) {
			r[i] = in.readInt();
			cx[i] = in.readInt();
			cy[i] = in.readInt();
		}
		Integer[] o = new Integer[m];
		for (int i = 0; i < m; i++)
			o[i] = i;
		Arrays.sort(o, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				if (r[o1] > r[o2])
					return -1;
				if (r[o1] < r[o2])
					return 1;
				return 0;
			}
		});
		int[] q = new int[n];
		int[][] p = new int[n][m];
		for (int i = 0; i < n; i++) {
			int lev = 0;
			for (int j : o) {
				if ((x[i] - cx[j]) * (x[i] - cx[j]) + (y[i] - cy[j]) * (y[i] - cy[j]) < r[j] * r[j]) {
					p[i][lev++] = j;
				}
			}
			q[i] = lev;
		}
		for (int i = 0; i < k; i++) {
			int a = in.readInt() - 1;
			int b = in.readInt() - 1;
			int ll = 0;
			int rr = Math.min(q[a], q[b]);
			while (ll < rr) {
				int mm = (ll + rr) / 2;
				if (p[a][mm] != p[b][mm])
					rr = mm;
				else
					ll = mm + 1;
			}
			out.println(q[a] + q[b] - 2 * ll);
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