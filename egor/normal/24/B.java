import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskB implements Runnable {
	private InputReader in;
	private PrintWriter out;

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
//        int numTests = in.readInt();
//        for (int testNumber = 0; testNumber < numTests; testNumber++) {
//			out.print("Case " + (testNumber + 1) + ": ");
//        }
		final int[] p = new int[50];
		p[0] = 25;
		p[1] = 18;
		p[2] = 15;
		p[3] = 12;
		p[4] = 10;
		p[5] = 8;
		p[6] = 6;
		p[7] = 4;
		p[8] = 2;
		p[9] = 1;
		final int[] pts = new int[50];
		final int[][] places = new int[50][50];
		Map<String, Integer> m = new HashMap<String, Integer>();
		String[] s = new String[50];
		int c = 0;
		int n = in.readInt();
		for (int i = 0; i < n; i++) {
			int q = in.readInt();
			for (int j = 0; j < q; j++) {
				String t = in.readString();
				if (!m.containsKey(t)) {
					m.put(t, c);
					s[c++] = t;
				}
				int ind = m.get(t);
				pts[ind] += p[j];
				places[ind][j]++;
			}
		}
		final Integer[] o = new Integer[c];
		for (int i = 0; i < c; i++)
			o[i] = i;
		Arrays.sort(o, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				if (pts[o1] != pts[o2])
					return pts[o2] - pts[o1];
				for (int i = 0; i < 50; i++) {
					if (places[o1][i] != places[o2][i])
						return places[o2][i] - places[o1][i];
				}
				return 0;
			}
		});
		out.println(s[o[0]]);
		Arrays.sort(o, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				if (places[o1][0] != places[o2][0])
					return places[o2][0] - places[o1][0];
				if (pts[o1] != pts[o2])
					return pts[o2] - pts[o1];
				for (int i = 1; i < 50; i++) {
					if (places[o1][i] != places[o2][i])
						return places[o2][i] - places[o1][i];
				}
				return 0;
			}
		});
		out.println(s[o[0]]);
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