import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
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
//        int numTests = in.readInt();
//        for (int testNumber = 0; testNumber < numTests; testNumber++) {
		process();
//        }
		out.close();
	}

	private void process() {
		int n = in.readInt();
		int[] x = new int[n];
		int[] y = new int[n];
		final int[] t = new int[n];
		double[] p = new double[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.readInt();
			y[i] = in.readInt();
			t[i] = in.readInt();
			p[i] = in.readDouble();
		}
		Integer[] o = new Integer[n];
		for (int i = 0; i < n; i++)
			o[i] = i;
		Arrays.sort(o, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return t[o1] - t[o2];
			}
		});
		double[] ans = new double[n];
		double res = 0;
		for (int ind = 0; ind < n; ind++) {
			int i = o[ind];
			for (int ind2 = 0; ind2 < ind; ind2++) {
				int j = o[ind2];
				if (Math.hypot(x[i] - x[j], y[i] - y[j]) < t[i] - t[j] + 1e-8)
					ans[i] = Math.max(ans[i], ans[j]);
			}
			res = Math.max(res, ans[i] += p[i]);
		}
		out.printf("%.8f\n", res);
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