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
		int[] x = new int[vertexCount];
		int[] y = new int[vertexCount];
		for (int i = 0; i < vertexCount; i++) {
			x[i] = in.readInt();
			y[i] = in.readInt();
		}
		long square = 0;
		for (int i = 0; i < vertexCount; i++) {
			int nextVertex = (i + 1) % vertexCount;
			square += ((long)(x[nextVertex] - x[i])) * (y[nextVertex] + y[i]);
		}
		square = Math.abs(square);
		int pointCount = in.readInt();
		for (int i = 0; i < pointCount; i++) {
			int px = in.readInt();
			int py = in.readInt();
			long currentSquare = 0;
			for (int j = 0; j < vertexCount; j++) {
				int nextVertex = (j + 1) % vertexCount;
				long triangleSquare = 0;
				triangleSquare += ((long)(x[nextVertex] - x[j])) * (y[nextVertex] + y[j]);
				triangleSquare += ((long)(px - x[nextVertex])) * (y[nextVertex] + py);
				triangleSquare += ((long)(x[j] - px)) * (py + y[j]);
				currentSquare += Math.abs(triangleSquare);
			}
			if (currentSquare != square) {
				out.println(0);
				continue;
			}
			int rightIndex = 0;
			long triangleCount = 0;
			for (int j = 0; j < vertexCount; j++) {
				while (true) {
					int nextIndex = (rightIndex + 1) % vertexCount;
					long a = y[nextIndex] - y[j];
					long b = x[j] - x[nextIndex];
					long c = -a * x[j] - b * y[j];
					if (a * px + b * py + c < 0)
						break;
					else {
						rightIndex = nextIndex;
						if (rightIndex > j) {
							long variants = rightIndex - j;
							triangleCount += variants * (variants - 1) / 2;
						} else {
							long variants = vertexCount - j + rightIndex;
							triangleCount += variants * (variants - 1) / 2;
							@SuppressWarnings({"UnnecessaryLocalVariable"})
							long alreadyCountedVariants = rightIndex;
							triangleCount -= alreadyCountedVariants * (alreadyCountedVariants - 1) / 2;
						}
					}
				}
			}
			long allTriangles = vertexCount;
			allTriangles *= vertexCount - 1;
			allTriangles *= vertexCount - 2;
			allTriangles /= 6;
			out.println(allTriangles - triangleCount);
		}
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