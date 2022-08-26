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
public class TaskD implements Runnable {
	private InputReader in;
	private PrintWriter out;

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
		process();
//        }
		out.close();
	}

	private void process() {
		int n = in.readInt();
		int k = in.readInt();
		final int[] x = new int[n + 1];
		for (int i = 0; i <= n; i++)
			x[i] = in.readInt();
		int y = in.readInt();
		double ans;
		int minIndex = 0;
		int maxIndex = 0;
		int min = x[0];
		int max = x[0];
		for (int i = 1; i < n; i++) {
			if (x[i] < min) {
				min = x[i];
				minIndex = i;
			}
			if (x[i] > max) {
				max = x[i];
				maxIndex = i;
			}
		}
		Integer[] o = new Integer[n];
		for (int i = 0; i < n; i++)
			o[i] = i;
		Arrays.sort(o, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return x[o1] - x[o2];
			}
		});
		int[] oo = new int[n];
		for (int i = 0; i < n; i++)
			oo[o[i]] = i;
		if (k == n + 1)
			ans = x[maxIndex] - x[minIndex] + Math.min(Math.hypot(x[n] - x[minIndex], y), Math.hypot(x[n] - x[maxIndex], y));
		else {
			int start = oo[k - 1];
			Arrays.sort(x, 0, n);
			ans = Math.hypot(x[start] - x[n], y) + Math.hypot(x[0] - x[n], y) + x[n - 1] - x[0];
			ans = Math.min(ans, Math.hypot(x[start] - x[n], y) + Math.hypot(x[n - 1] - x[n], y) + x[n - 1] - x[0]);
			ans = Math.min(ans, x[start] - x[0] + x[n - 1] - x[0] + Math.hypot(x[n - 1] - x[n], y));
			ans = Math.min(ans, x[n - 1] - x[start] + x[n - 1] - x[0] + Math.hypot(x[0] - x[n], y));
			for (int i = 1; i < n; i++) {
				if (start >= i) {
					double v1 = Math.min(x[start] - x[i] + x[n - 1] - x[i] + Math.hypot(x[n - 1] - x[n], y), x[n - 1] - x[start] + x[n - 1] - x[i] + Math.hypot(x[n] - x[i], y));
					double v2 = x[i - 1] - x[0] + Math.min(Math.hypot(x[i - 1] - x[n], y), Math.hypot(x[0] - x[n], y));
					ans = Math.min(ans, v1 + v2);
				} else {
					double v1 = Math.min(x[start] - x[0] + x[i - 1] - x[0] + Math.hypot(x[i - 1] - x[n], y), x[i - 1] - x[start] + x[i - 1] - x[0] + Math.hypot(x[n] - x[0], y));
					double v2 = x[n - 1] - x[i] + Math.min(Math.hypot(x[n - 1] - x[n], y), Math.hypot(x[i] - x[n], y));
					ans = Math.min(ans, v1 + v2);
				}
			}
		}
		out.printf("%.8f\n", ans);
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