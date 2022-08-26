import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskB {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	InputReader in;
	PrintWriter out;

	void solve() {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		char[][] picture = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			picture[i] = in.readString().toCharArray();
		int puzzlesCount = 0;
		int minHeight = -1;
		int minWidth = -1;
		for (int i = 1; i <= rowCount; i++) {
			if (rowCount % i != 0)
				continue;
			for (int j = 1; j <= columnCount; j++) {
				if (columnCount % j == 0 && validPuzzle(picture, i, j)) {
					puzzlesCount++;
					if (puzzlesCount == 1 || minHeight * minWidth > i * j) {
						minHeight = i;
						minWidth = j;
					}
				}
			}
		}
		out.println(puzzlesCount);
		out.println(minHeight + " " + minWidth);
	}

	private boolean validPuzzle(char[][] picture, int height, int width) {
		Set<String> pieces = new HashSet<String>();
		for (int i = 0; i < picture.length; i += height) {
			for (int j = 0; j < picture[i].length; j += width) {
				StringBuilder piece = new StringBuilder(height * (width + 1));
				for (int k = i; k < i + height; k++) {
					for (int l = j; l < j + width; l++)
						piece.append(picture[k][l]);
					piece.append(' ');
				}
				if (pieces.contains(piece.toString()))
					return false;
				pieces.add(piece.toString());
				StringBuilder piece90 = new StringBuilder(height * (width + 1));
				for (int l = j + width - 1; l >= j; l--) {
					for (int k = i; k < i + height; k++)
						piece90.append(picture[k][l]);
					piece90.append(' ');
				}
				pieces.add(piece90.toString());
				StringBuilder piece180 = new StringBuilder(height * (width + 1));
				for (int k = i + height - 1; k >= i; k--) {
					for (int l = j + width - 1; l >= j; l--)
						piece180.append(picture[k][l]);
					piece180.append(' ');
				}
				pieces.add(piece180.toString());
				StringBuilder piece270 = new StringBuilder(height * (width + 1));
				for (int l = j; l < j + width; l++) {
					for (int k = i + height - 1; k >= i; k--)
						piece270.append(picture[k][l]);
					piece270.append(' ');
				}
				pieces.add(piece270.toString());
			}
		}
		return true;
	}

	public static void main(String[] args) {
		new TaskB().run();
	}

	TaskB() {
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