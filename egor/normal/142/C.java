import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	private byte[][][] result;
	private int all;
	private int first;
	private int second;
	private int third;
	private int fourth;
	char[][] table;
	private int rowCount;
	private int columnCount;
	char letter = 'A';

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		rowCount = in.readInt();
		columnCount = in.readInt();
		int[][] ans = new int[10][10];
		ans[1][1] = 0;
		ans[1][1] = 0;
		ans[2][1] = 0;
		ans[1][2] = 0;
		ans[2][2] = 0;
		ans[2][2] = 0;
		ans[3][1] = 0;
		ans[1][3] = 0;
		ans[3][2] = 0;
		ans[2][3] = 0;
		ans[3][3] = 1;
		ans[3][3] = 1;
		ans[4][1] = 0;
		ans[1][4] = 0;
		ans[4][2] = 0;
		ans[2][4] = 0;
		ans[4][3] = 1;
		ans[3][4] = 1;
		ans[4][4] = 2;
		ans[4][4] = 2;
		ans[5][1] = 0;
		ans[1][5] = 0;
		ans[5][2] = 0;
		ans[2][5] = 0;
		ans[5][3] = 2;
		ans[3][5] = 2;
		ans[5][4] = 2;
		ans[4][5] = 2;
		ans[5][5] = 4;
		ans[5][5] = 4;
		ans[6][1] = 0;
		ans[1][6] = 0;
		ans[6][2] = 0;
		ans[2][6] = 0;
		ans[6][3] = 2;
		ans[3][6] = 2;
		ans[6][4] = 3;
		ans[4][6] = 3;
		ans[6][5] = 4;
		ans[5][6] = 4;
		ans[6][6] = 5;
		ans[6][6] = 5;
		ans[7][1] = 0;
		ans[1][7] = 0;
		ans[7][2] = 0;
		ans[2][7] = 0;
		ans[7][3] = 3;
		ans[3][7] = 3;
		ans[7][4] = 4;
		ans[4][7] = 4;
		ans[7][5] = 5;
		ans[5][7] = 5;
		ans[7][6] = 6;
		ans[6][7] = 6;
		ans[7][7] = 8;
		ans[7][7] = 8;
		ans[8][1] = 0;
		ans[1][8] = 0;
		ans[8][2] = 0;
		ans[2][8] = 0;
		ans[8][3] = 3;
		ans[3][8] = 3;
		ans[8][4] = 4;
		ans[4][8] = 4;
		ans[8][5] = 6;
		ans[5][8] = 6;
		ans[8][6] = 7;
		ans[6][8] = 7;
		ans[8][7] = 9;
		ans[7][8] = 9;
		ans[8][8] = 10;
		ans[8][8] = 10;
		ans[9][1] = 0;
		ans[1][9] = 0;
		ans[9][2] = 0;
		ans[2][9] = 0;
		ans[9][3] = 4;
		ans[3][9] = 4;
		ans[9][4] = 5;
		ans[4][9] = 5;
		ans[9][5] = 7;
		ans[5][9] = 7;
		ans[9][6] = 8;
		ans[6][9] = 8;
		ans[9][7] = 10;
		ans[7][9] = 10;
		ans[9][8] = 12;
		ans[8][9] = 12;
		ans[9][9] = 13;
		ans[9][9] = 13;
		out.printLine(ans[rowCount][columnCount]);
		result = new byte[rowCount][columnCount][1 << (2 * columnCount + 2)];
		ArrayUtils.fill(result, (byte)-1);
		all = result[0][0].length - 1;
		first = (1 << (2 * columnCount + 2)) + (1 << (2 * columnCount + 1)) + (1 << (2 * columnCount)) +
			(1 << (columnCount + 1)) + 2;
		second = (1 << (2 * columnCount + 1)) + (1 << (columnCount + 1)) + 7;
		third = (1 << (2 * columnCount)) + (1 << (columnCount + 2)) + (1 << (columnCount + 1)) + (1 << (columnCount)) + 1;
		fourth = (1 << (2 * columnCount + 2)) + (1 << (columnCount + 2)) + (1 << (columnCount + 1)) + (1 << (columnCount)) + 4;
		table = new char[rowCount][columnCount];
		ArrayUtils.fill(table, '.');
		go(0, 0, all);
		build(0, 0, all);
		for (char[] row : table)
			out.printLine(row);
	}

	private byte go(int row, int column, int mask) {
		if (column == columnCount)
			return go(row + 1, 0, mask);
		if (row == rowCount)
			return 0;
		if (result[row][column][mask] != -1)
			return result[row][column][mask];
		if (row < 2 || column < 2)
			return result[row][column][mask] = go(row, column + 1, (mask << 1) & all);
		int newMask = mask << 1;
		result[row][column][mask] = go(row, column + 1, newMask & all);
		if ((newMask & first) == 0)
			result[row][column][mask] = (byte) Math.max(result[row][column][mask], go(row, column + 1, (newMask | first) & all) + 1);
		if ((newMask & second) == 0)
			result[row][column][mask] = (byte) Math.max(result[row][column][mask], go(row, column + 1, (newMask | second) & all) + 1);
		if ((newMask & third) == 0)
			result[row][column][mask] = (byte) Math.max(result[row][column][mask], go(row, column + 1, (newMask | third) & all) + 1);
		if ((newMask & fourth) == 0)
			result[row][column][mask] = (byte) Math.max(result[row][column][mask], go(row, column + 1, (newMask | fourth) & all) + 1);
		return result[row][column][mask];
	}

	private void build(int row, int column, int mask) {
		if (column == columnCount) {
			build(row + 1, 0, mask);
			return;
		}
		if (row == rowCount)
			return;
//		if (result[row][column][mask] != -1)
//			return result[row][column][mask];
		if (row < 2 || column < 2) {
			build(row, column + 1, (mask << 1) & all);
			return;
		}
		int newMask = mask << 1;
		if (result[row][column][mask] == go(row, column + 1, newMask & all)) {
			build(row, column + 1, newMask & all);
			return;
		}
		if ((newMask & first) == 0) {
			if (result[row][column][mask] == go(row, column + 1, (newMask | first) & all) + 1) {
				table[row - 2][column - 2] = letter;
				table[row - 2][column - 1] = letter;
				table[row - 2][column] = letter;
				table[row - 1][column - 1] = letter;
				table[row][column - 1] = letter++;
				build(row, column + 1, (newMask | first) & all);
				return;
			}
		}
		if ((newMask & second) == 0) {
			if (result[row][column][mask] == go(row, column + 1, (newMask | second) & all) + 1) {
				table[row][column - 2] = letter;
				table[row][column - 1] = letter;
				table[row][column] = letter;
				table[row - 1][column - 1] = letter;
				table[row - 2][column - 1] = letter++;
				build(row, column + 1, (newMask | second) & all);
				return;
			}
		}
		if ((newMask & third) == 0) {
			if (result[row][column][mask] == go(row, column + 1, (newMask | third) & all) + 1) {
				table[row - 2][column] = letter;
				table[row - 1][column - 1] = letter;
				table[row - 1][column] = letter;
				table[row - 1][column - 2] = letter;
				table[row][column] = letter++;
				build(row, column + 1, (newMask | third) & all);
				return;
			}
		}
		if ((newMask & fourth) == 0) {
			if (result[row][column][mask] == go(row, column + 1, (newMask | fourth) & all) + 1) {
				table[row - 2][column - 2] = letter;
				table[row - 1][column - 1] = letter;
				table[row - 1][column] = letter;
				table[row - 1][column - 2] = letter;
				table[row][column - 2] = letter++;
				build(row, column + 1, (newMask | fourth) & all);
				return;
			}
		}
		throw new RuntimeException();
	}

}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
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

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(outputStream);
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void printLine(char[] array) {
		writer.println(array);
	}

	public void close() {
		writer.close();
	}

	}

class ArrayUtils {

	public static void fill(char[][] array, char value) {
		for (char[] row : array)
			Arrays.fill(row, value);
	}

	public static void fill(byte[][] array, byte value) {
		for (byte[] row : array)
			Arrays.fill(row, value);
	}

	public static void fill(byte[][][] array, byte value) {
		for (byte[][] row : array)
			fill(row, value);
	}

	}