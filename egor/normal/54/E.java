import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskE {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	InputReader in;
	PrintWriter out;

	void solve() {
		int vertexCount = in.readInt();
		long[] x = new long[vertexCount + 1];
		long[] y = new long[vertexCount + 1];
		for (int i = 0; i < vertexCount; i++) {
			x[i] = in.readInt();
			y[i] = in.readInt();
		}
		x[vertexCount] = x[0];
		y[vertexCount] = y[0];
		if ((y[2] - y[0]) * (x[1] - x[0]) + (x[0] - x[2]) * (y[1] - y[0]) > 0) {
			for (int i = 0; i <= vertexCount; i++) {
				long temp = x[i];
				x[i] = y[i];
				y[i] = temp;
			}
		}
		long[] partialSquare = new long[vertexCount];
		long fullSquare = 0;
		for (int i = 0; i < vertexCount; i++) {
			partialSquare[i] = fullSquare;
			fullSquare += (x[i] - x[i + 1]) * (y[i] + y[i + 1]);
		}
		int leftIndex = 1;
		int rightIndex = 1;
		double answer = Double.MAX_VALUE;
		for (int i = 0; i < vertexCount; i++) {
			long a = x[i] - x[i + 1];
			long b = y[i] - y[i + 1];
			long c = x[i] * b - y[i] * a;
			if (rightIndex == i)
				rightIndex = (i + 1) % vertexCount;
			while (rightIndex != i) {
				int nextIndex = (rightIndex + 1) % vertexCount;
				if (a * x[nextIndex] + b * y[nextIndex] < a * x[rightIndex] + b * y[rightIndex])
					rightIndex = nextIndex;
				else
					break;
			}
			if (i == 0)
				leftIndex = rightIndex;
			while (leftIndex != i) {
				int nextIndex = (leftIndex + 1) % vertexCount;
				if (a * x[nextIndex] + b * y[nextIndex] >= a * x[leftIndex] + b * y[leftIndex])
					leftIndex = nextIndex;
				else
					break;
			}
			double leftCandidate = getSquare(x, y, partialSquare, fullSquare, leftIndex, i, a, b, c, -x[leftIndex] * a - y[leftIndex] * b);
			double rightCandidate = getSquare(x, y, partialSquare, fullSquare, (i + 1) % vertexCount, rightIndex, a, b, c, -x[rightIndex] * a - y[rightIndex] * b);
			answer = Math.min(answer, Math.min(leftCandidate, rightCandidate));
		}
		out.printf("%.8f\n", answer);
	}

	private double getSquare(long[] x, long[] y, long[] partialSquare, long fullSquare, int leftIndex, int rightIndex, double a1, double b1, double c, double c1) {
		double a = -b1;
		double b = a1;
		double cornerX = (c1 * b - c * b1) / (a * b1 - a1 * b);
		double cornerY = (c1 * a - c * a1) / (a1 * b - a * b1);
		double square = partialSquare[rightIndex] - partialSquare[leftIndex];
		if (leftIndex > rightIndex)
			square += fullSquare;
		square += (x[rightIndex] - cornerX) * (y[rightIndex] + cornerY);
		square += (cornerX - x[leftIndex]) * (cornerY + y[leftIndex]);
		return 0.5 * Math.abs(square);
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