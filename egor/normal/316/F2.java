import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
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
		TaskF1 solver = new TaskF1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF1 {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		int[][] map = IOUtils.readIntTable(in, rowCount, columnCount);
		int[][] sunOnly = new int[rowCount][columnCount];
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				sunOnly[i][j] = 1;
				for (int k = -2; k <= 2; k++) {
					for (int l = -2; l <= 2; l++) {
						if (MiscUtils.isValidCell(i + k, j + l, rowCount, columnCount))
							sunOnly[i][j] &= map[i + k][j + l];
						else
							sunOnly[i][j] = 0;
					}
				}
			}
		}
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				map[i][j] -= 2;
			}
		}
		int[] rowQueue = new int[rowCount * columnCount];
		int[] columnQueue = new int[rowCount * columnCount];
		int count = 0;
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				if (map[i][j] == -1) {
					int size = 1;
					rowQueue[0] = i;
					columnQueue[0] = j;
					map[i][j] = count;
					for (int k = 0; k < size; k++) {
						int row = rowQueue[k];
						int column = columnQueue[k];
						for (int l = 0; l < 4; l++) {
							int nRow = row + MiscUtils.DX4[l];
							int nColumn = column + MiscUtils.DY4[l];
							if (MiscUtils.isValidCell(nRow, nColumn, rowCount, columnCount) && map[nRow][nColumn] == -1) {
								map[nRow][nColumn] = count;
								rowQueue[size] = nRow;
								columnQueue[size++] = nColumn;
							}
						}
					}
					count++;
				}
			}
		}
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				if (map[i][j] == -2)
					continue;
				for (int k = -4; k <= 4; k++) {
					for (int l = -4; l <= 4; l++) {
						if (MiscUtils.isValidCell(i + k, j + l, rowCount, columnCount) && sunOnly[i + k][j + l] == 1)
							map[i][j] = -2;
					}
				}
			}
		}
		int[] answer = new int[count];
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				if (map[i][j] >= 0) {
					answer[map[i][j]]++;
					int size = 1;
					rowQueue[0] = i;
					columnQueue[0] = j;
					map[i][j] = -2;
					for (int k = 0; k < size; k++) {
						int row = rowQueue[k];
						int column = columnQueue[k];
						for (int l = 0; l < 4; l++) {
							int nRow = row + MiscUtils.DX4[l];
							int nColumn = column + MiscUtils.DY4[l];
							if (MiscUtils.isValidCell(nRow, nColumn, rowCount, columnCount) && map[nRow][nColumn] >= 0) {
								map[nRow][nColumn] = -2;
								rowQueue[size] = nRow;
								columnQueue[size++] = nColumn;
							}
						}
					}
				}
			}
		}
		Arrays.sort(answer);
		out.printLine(count);
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

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

    public void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void printLine(int[] array) {
        print(array);
        writer.println();
    }

    public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	public static int[][] readIntTable(InputReader in, int rowCount, int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readIntArray(in, columnCount);
		return table;
	}

	}

class MiscUtils {
	public static final int[] DX4 = {1, 0, -1, 0};
	public static final int[] DY4 = {0, -1, 0, 1};

    public static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
		return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
	}

	}