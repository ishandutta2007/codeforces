import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
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
	int RIGHT = 3;
	int LEFT = 1;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		char[][] table = IOUtils.readTable(in, rowCount, columnCount);
		int treasureCount = 0;
		int bombCount = 0;
		int sRow = -1;
		int sColumn = -1;
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				char c = table[i][j];
				if (Character.isDigit(c))
					treasureCount = Math.max(treasureCount, c - '0');
				else if (c == 'B')
					bombCount++;
				else if (c == 'S') {
					sRow = i;
					sColumn = j;
				}
			}
		}
		table[sRow][sColumn] = '.';
		int[] value = IOUtils.readIntArray(in, treasureCount);
		int[][][] change = new int[4][rowCount][columnCount];
		int bombIndex = treasureCount;
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				int curIndex = -1;
				if (Character.isDigit(table[i][j]))
					curIndex = table[i][j] - '1';
				else if (table[i][j] == 'B')
					curIndex = bombIndex++;
				if (curIndex == -1)
					continue;
				for (int k = 0; k < i; k++) {
					change[RIGHT][k][j] += 1 << curIndex;
					if (j + 1 < columnCount)
						change[LEFT][k][j + 1] += 1 << curIndex;
				}
			}
		}
		int count = treasureCount + bombCount;
		int[][][] cost = new int[rowCount][columnCount][1 << count];
		ArrayUtils.fill(cost, -1);
		cost[sRow][sColumn][0] = 0;
		int[] rowQueue = new int[rowCount * columnCount * (1 << count)];
		int[] columnQueue = new int[rowQueue.length];
		int[] maskQueue = new int[rowQueue.length];
		rowQueue[0] = sRow;
		columnQueue[0] = sColumn;
		int length = 1;
		for (int i = 0; i < length; i++) {
			int row = rowQueue[i];
			int column = columnQueue[i];
			int mask = maskQueue[i];
			for (int j = 0; j < 4; j++) {
				int nRow = row + MiscUtils.DX4[j];
				int nColumn = column + MiscUtils.DY4[j];
				int nMask = mask ^ change[j][row][column];
				if (!MiscUtils.isValidCell(nRow, nColumn, rowCount, columnCount) || table[nRow][nColumn] != '.' ||
					cost[nRow][nColumn][nMask] != -1)
				{
					continue;
				}
				cost[nRow][nColumn][nMask] = cost[row][column][mask] + 1;
				rowQueue[length] = nRow;
				columnQueue[length] = nColumn;
				maskQueue[length++] = nMask;
			}
		}
		int answer = 0;
		for (int i = 0; i < (1 << treasureCount); i++) {
			if (cost[sRow][sColumn][i] != -1) {
				int candidate = -cost[sRow][sColumn][i];
				for (int j = 0; j < treasureCount; j++) {
					if ((i >> j & 1) == 1)
						candidate += value[j];
				}
				answer = Math.max(answer, candidate);
			}
		}
		out.printLine(answer);
    }
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

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

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void close() {
		writer.close();
	}

	public void printLine(int i) {
		writer.println(i);
	}
}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	public static char[] readCharArray(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
		char[][] table = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readCharArray(in, columnCount);
		return table;
	}

	}

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	public static void fill(int[][][] array, int value) {
		for (int[][] subArray : array)
			fill(subArray, value);
	}

	}

class MiscUtils {
	public static final int[] DX4 = {1, 0, -1, 0};
	public static final int[] DY4 = {0, -1, 0, 1};

    public static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
		return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
	}

	}