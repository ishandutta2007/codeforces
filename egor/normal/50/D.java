import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskD {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	InputReader in;
	PrintWriter out;

	void solve() {
		int n = in.readInt();
		int k = in.readInt();
		int epsilon = in.readInt();
		int x0 = in.readInt();
		int y0 = in.readInt();
		int[] squaredDistance = new int[n];
		int maxDistSquared = 0;
		for (int i = 0; i < n; i++) {
			int x = in.readInt();
			int y = in.readInt();
			maxDistSquared = Math.max(squaredDistance[i] = (x0 - x) * (x0 - x) + (y0 - y) * (y0 - y), maxDistSquared);
		}
		double left = 0;
		double right = Math.sqrt(maxDistSquared);
		double[][] destroyedProbability = new double[n + 1][k + 1];
		while (right - left > 1e-8) {
			double curDist = (left + right) / 2;
			double curDistSquared = curDist * curDist;
			Arrays.fill(destroyedProbability[0], 0);
			destroyedProbability[0][0] = 1;
			for (int i = 0; i < n; i++) {
				double probabilityToDestroy = curDistSquared > squaredDistance[i] ? 1 : Math.exp(1 - squaredDistance[i] / curDistSquared);
				Arrays.fill(destroyedProbability[i + 1], 0);
				for (int j = 0; j < k; j++) {
					destroyedProbability[i + 1][j] += (1 - probabilityToDestroy) * destroyedProbability[i][j];
					destroyedProbability[i + 1][j + 1] += probabilityToDestroy * destroyedProbability[i][j];
				}
				destroyedProbability[i + 1][k] += destroyedProbability[i][k];
			}
			if (destroyedProbability[n][k] * 1000 > 1000 - epsilon)
				right = curDist;
			else
				left = curDist;
		}
		double ans = (left + right) / 2;
		out.printf("%.7f\n", ans);
	}

	public static void main(String[] args) {
		new TaskD().run();
	}

	TaskD() {
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