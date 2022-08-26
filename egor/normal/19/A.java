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
public class TaskA implements Runnable {
	private InputReader in;
	private PrintWriter out;

	public static void main(String[] args) {
		new Thread(new TaskA()).start();
//		new Template().run();
	}

	public TaskA() {
		String id = getClass().getName().toLowerCase();
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
//			out.print("Case #" + (testNumber + 1) + ": ");
//        }
		int n = in.readInt();
		String[] s = new String[n];
		final int[] pts = new int[n];
		final int[] gf = new int[n];
		final int[] ga = new int[n];
		for (int i = 0; i < n; i++)
			s[i] = in.readString();
		for (int i = 0; i < n * (n - 1) / 2; i++) {
			String[] t = in.readString().split("-");
			int i1 = -1;
			for (int j = 0; j < n; j++) {
				if (s[j].equals(t[0])) {
					i1 = j;
					break;
				}
			}
			int i2 = -1;
			for (int j = 0; j < n; j++) {
				if (s[j].equals(t[1])) {
					i2 = j;
					break;
				}
			}
			String[] a = in.readString().split(":");
			int g1 = Integer.parseInt(a[0]);
			int g2 = Integer.parseInt(a[1]);
			gf[i1] += g1;
			ga[i1] += g2;
			gf[i2] += g2;
			ga[i2] += g1;
			if (g1 > g2)
				pts[i1] += 3;
			else if (g1 < g2)
				pts[i2] += 3;
			else {
				pts[i1]++;
				pts[i2]++;
			}
		}
		Integer[] o = new Integer[n];
		for (int i = 0; i < n; i++)
			o[i] = i;
		Arrays.sort(o, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				if (pts[o1] != pts[o2])
					return pts[o2] - pts[o1];
				if (gf[o1] - ga[o1] != gf[o2] - ga[o2])
					return gf[o2] - ga[o2] - gf[o1] + ga[o1];
				return gf[o2] - gf[o1];
			}
		});
		String[] ans = new String[n / 2];
		for (int i = 0; i < n / 2; i++)
			ans[i] = s[o[i]];
		Arrays.sort(ans);
		for (String aa : ans)
			out.println(aa);
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