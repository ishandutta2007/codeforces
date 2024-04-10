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
	private InputReader in;
	private PrintWriter out;

	public static void main(String[] args) {
		new Thread(new TaskD()).start();
//		new Template().run();
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
		int xx = in.readInt();
		int yy = in.readInt() - 1;
		double ans;
		double[] z = new double[m];
		if (m == 1) {
			ans = 2 * (n - xx);
		} else {
			double[] a = new double[m];
			for (int i = 0; i < m; i++)
				a[i] = -1. / 3;
			a[m - 1] = -1. / 2;
			double[] b = new double[m];
			for (int i = 0; i < m; i++)
				b[i] = 1;
			double[] c = new double[m];
			double[] d = new double[m];
			for (int j = 0; j < n - xx; j++) {
				for (int i = 0; i < m; i++)
					c[i] = -1. / 3;
				c[0] = -1. / 2;
				for (int i = 0; i < m; i++)
					d[i] = 1 + z[i] / 3;
				d[0] = 1 + z[0] / 2;
				d[m - 1] = 1 + z[m - 1] / 2;
				tridiagonalSolve(a, b, c, d, z);
			}
			ans = z[yy] + n - xx;
		}
		out.printf("%.7f\n", ans);
		out.close();
	}

	private void tridiagonalSolve(double[] a, double[] b, double[] c, double[] d, double[] x) {
		int n = b.length;

		c[0] /= b[0];
		d[0] /= b[0];
		for (int i = 1; i < n; i++) {
			double id = 1 / (b[i] - c[i - 1] * a[i]);
			c[i] *= id;
			d[i] = (d[i] - d[i - 1] * a[i]) * id;
		}

		x[n - 1] = d[n - 1];
		for (int i = n - 2; i >= 0; i--)
			x[i] = d[i] - c[i] * x[i + 1];
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