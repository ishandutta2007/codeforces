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
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		boolean[][] universe = new boolean[rowCount][columnCount];
		int staticCount = 0;
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				universe[i][j] = in.readCharacter() == 'X';
				if (universe[i][j])
					staticCount++;
			}
		}
		int[] staticRow = new int[staticCount];
		int[] staticColumn = new int[staticCount];
		int[] staticInRow = new int[rowCount];
		int[] staticInColumn = new int[columnCount];
		Arrays.fill(staticInRow, -1);
		Arrays.fill(staticInColumn, -1);
		long totalDistance = 0;
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				long currentDistance = rowCount * (j * (j + 1) / 2 + (columnCount - j) * (columnCount - j - 1) / 2) +
						columnCount * (i * (i + 1) / 2 + (rowCount - i) * (rowCount - i - 1) / 2);
				if (universe[i][j]) {
					totalDistance -= currentDistance;
					staticRow[--staticCount] = i;
					staticColumn[staticCount] = j;
					staticInRow[i] = j;
					staticInColumn[j] = i;
				} else
					totalDistance += currentDistance;
			}
		}
		for (int i = 0; i < staticRow.length; i++) {
			for (int j = 0; j < staticRow.length; j++)
				totalDistance += Math.abs(staticRow[i] - staticRow[j]) + Math.abs(staticColumn[i] - staticColumn[j]);
		}
		for (int i = 0; i < rowCount; i++) {
			for (int j = i; j < rowCount; j++) {
				if (staticInRow[j] == -1)
					break;
				if (j != i && (staticInRow[j] - staticInRow[j - 1]) * (staticInRow[i + 1] - staticInRow[i]) < 0)
					break;
				if (staticInRow[j] >= staticInRow[i])
					totalDistance += 4 * staticInRow[i] * (columnCount - staticInRow[j] - 1);
				else
					totalDistance += 4 * staticInRow[j] * (columnCount - staticInRow[i] - 1);
			}
		}
		for (int i = 0; i < columnCount; i++) {
			for (int j = i; j < columnCount; j++) {
				if (staticInColumn[j] == -1)
					break;
				if (j != i && (staticInColumn[j] - staticInColumn[j - 1]) * (staticInColumn[i + 1] - staticInColumn[i]) < 0)
					break;
				if (staticInColumn[j] >= staticInColumn[i])
					totalDistance += 4 * staticInColumn[i] * (rowCount - staticInColumn[j] - 1);
				else
					totalDistance += 4 * staticInColumn[j] * (rowCount - staticInColumn[i] - 1);
			}
		}
		double expectedLifetime = totalDistance;
		expectedLifetime /= rowCount * columnCount - staticRow.length;
		expectedLifetime /= rowCount * columnCount - staticRow.length;
		out.printf("%.10f\n", expectedLifetime);
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
//		int testCount = in.readInt();
//		for (int i = 0; i < testCount; i++)
//		while (true)
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

		int[] readIntArray(int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = readInt();
			return array;
		}

		long[] readLongArray(int size) {
			long[] array = new long[size];
			for (int i = 0; i < size; i++)
				array[i] = readLong();
			return array;
		}

		double[] readDoubleArray(int size) {
			double[] array = new double[size];
			for (int i = 0; i < size; i++)
				array[i] = readDouble();
			return array;
		}

		String[] readStringArray(int size) {
			String[] array = new String[size];
			for (int i = 0; i < size; i++)
				array[i] = readString();
			return array;
		}

		char[][] readTable(int rowCount, int columnCount) {
			char[][] table = new char[rowCount][columnCount];
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++)
					table[i][j] = readCharacter();
			}
			return table;
		}

		void readIntArrays(int[]...arrays) {
			for (int i = 0; i < arrays[0].length; i++) {
				for (int j = 0; j < arrays.length; j++)
					arrays[j][i] = readInt();
			}
		}
	}
}