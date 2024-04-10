import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskE {
	private InputReader in;
	private PrintWriter out;

	public static void main(String[] args) {
		TaskE solver = new TaskE();
		solver.run();
		solver.out.close();
	}

	public TaskE() {
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
		double t = in.readInt();
		double[] x = new double[n];
		double[] v = new double[n];
		double[] m = new double[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.readInt();
			v[i] = in.readInt();
			m[i] = in.readInt();
		}
		while (true) {
			double nextCollision = t;
			List<Integer> index1 = new ArrayList<Integer>();
			List<Integer> index2 = new ArrayList<Integer>();
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (Math.abs(v[i] - v[j]) < 1e-11)
						continue;
					double current = (x[j] - x[i]) / (v[i] - v[j]);
					if (current > 1e-11) {
						if (current < nextCollision - 1e-11) {
							index1 = new ArrayList<Integer>();
							index2 = new ArrayList<Integer>();
							nextCollision = current;
						}
						if (current < nextCollision + 1e-11) {
							index1.add(i);
							index2.add(j);
						}
					}
				}
			}
			if (index1.size() == 0)
				break;
			for (int i = 0; i < n; i++)
				x[i] += nextCollision * v[i];
			for (int i = 0; i < index1.size(); i++) {
				int ind1 = index1.get(i);
				int ind2 = index2.get(i);
				double v1 = ((m[ind1] - m[ind2]) * v[ind1] + 2 * m[ind2] * v[ind2]) / (m[ind1] + m[ind2]);
				double v2 = ((m[ind2] - m[ind1]) * v[ind2] + 2 * m[ind1] * v[ind1]) / (m[ind1] + m[ind2]);
				v[ind1] = v1;
				v[ind2] = v2;
			}
			t -= nextCollision;
		}
		for (int i = 0; i < n; i++)
			x[i] += t * v[i];
		for (int i = 0; i < n; i++)
			out.printf("%.6f\n", x[i]);
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