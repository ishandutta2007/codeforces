import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskE {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	InputReader in;
	PrintWriter out;
	private static final double EPS = 1e-8;

	void solve() {
		int n = in.readInt();
		double v = in.readInt();
		final double[] alpha = new double[n];
		for (int i = 0; i < n; i++)
			alpha[i] = in.readDouble();
		int m = in.readInt();
		final double[] x = new double[m];
		double[] y = new double[m];
		for (int i = 0; i < m; i++) {
			x[i] = in.readDouble();
			y[i] = in.readDouble();
		}
		Integer[] missilesOrder = new Integer[n];
		for (int i = 0; i < n; i++)
			missilesOrder[i] = i;
		Arrays.sort(missilesOrder, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return Double.compare(alpha[o1], alpha[o2]);
			}
		});
		Integer[] wallsOrder = new Integer[m];
		for (int i = 0; i < m; i++)
			wallsOrder[i] = i;
		Arrays.sort(wallsOrder, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return Double.compare(x[o1], x[o2]);
			}
		});
		double[] answerX = new double[n];
		double[] answerY = new double[n];
		int missilesLanded = 0;
		for (int i : wallsOrder) {
			int left = missilesLanded;
			int right = n;
			while (left < right) {
				int middle = (left + right) / 2;
				if (getY(alpha[missilesOrder[middle]], x[i], v) < y[i] + EPS)
					left = middle + 1;
				else
					right = middle;
			}
			for (int j = missilesLanded; j < left; j++) {
				answerY[missilesOrder[j]] = getY(alpha[missilesOrder[j]], x[i], v);
				answerX[missilesOrder[j]] = x[i];
				if (answerY[missilesOrder[j]] < 0) {
					answerY[missilesOrder[j]] = 0;
					answerX[missilesOrder[j]] = getX(alpha[missilesOrder[j]], v);
				}
			}
			missilesLanded = left;
		}
		for (int j = missilesLanded; j < n; j++) {
			answerY[missilesOrder[j]] = 0;
			answerX[missilesOrder[j]] = getX(alpha[missilesOrder[j]], v);
		}
		for (int i = 0; i < n; i++)
			out.printf("%.6f %.6f\n", answerX[i], answerY[i]);
	}

	private double getX(double alpha, double v) {
		double vx = v * Math.cos(alpha);
		double vy = v * Math.sin(alpha);
		return 2 * vx * vy / 9.8;
	}

	private double getY(double alpha, double x, double v) {
		double vx = v * Math.cos(alpha);
		double t = x / vx;
		double vy = v * Math.sin(alpha);
		return vy * t - 9.8 * t * t / 2;
	}

	public static void main(String[] args) {
		new TaskE().run();
	}

	TaskE() {
		@SuppressWarnings({"UnusedDeclaration"})
		String id = getClass().getName().toLowerCase();
		//noinspection EmptyTryBlock
		try {
//			System.setIn(new FileInputStream(id + ".in"));
//			System.setOut(new PrintStream(new FileOutputStream(id + ".out")));
//			System.setIn(new FileInputStream("input.txt"));
//			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	void run() {
		//noinspection InfiniteLoopStatement
		solve();
		exit();
	}

	@SuppressWarnings({"UnusedDeclaration"})
	void exit() {
		out.close();
		System.exit(0);
	}

	@SuppressWarnings({"UnusedDeclaration"})
	static class InputReader {
		InputStream stream;
		byte[] buf = new byte[1024];
		int curChar, numChars;

		InputReader(InputStream stream) {
			this.stream = stream;
		}

		int read() {
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

		int readInt() {
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

		long readLong() {
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

		String readString() {
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

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		String readLine0() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				if (c != '\r')
					buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		String readLine() {
			String s = readLine0();
			while (s.trim().length() == 0)
				s = readLine0();
			return s;
		}

		String readLine(boolean ignoreEmptyLines) {
			if (ignoreEmptyLines)
				return readLine();
			else
				return readLine0();
		}

		BigInteger readBigInteger() {
			try {
				return new BigInteger(readString());
			} catch (NumberFormatException e) {
				throw new InputMismatchException();
			}
		}

		char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		double readDouble() {
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
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
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
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, readInt());
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