import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Collections;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		char[][] table = IOUtils.readTable(in, rowCount, columnCount);
		int[] rowQueue = new int[rowCount * columnCount];
		int[] columnQueue = new int[rowCount * columnCount];
		int[] rowBorder = new int[rowCount * columnCount];
		int[] columnBorder = new int[rowCount * columnCount];
		int answer = 0;
		for (int i = 0; i < rowCount - 1; i++) {
			for (int j = 0; j < columnCount - 1; j++) {
				if (table[i][j] == '1' && table[i][j + 1] == '1' &&
					table[i + 1][j] == '1' && table[i + 1][j + 1] == '1')
				{
					answer = 4;
				}
			}
		}
		int[][] accounted = new int[rowCount][columnCount];
		int[][] ind = new int[rowCount][columnCount];
		int[][] graph = new int[2][rowCount * columnCount];
		int call = 1;
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				if (table[i][j] == '1')
					continue;
				rowQueue[0] = i;
				columnQueue[0] = j;
				table[i][j] = '2';
				int size = 1;
				for (int k = 0; k < size; k++) {
					int row = rowQueue[k];
					int column = columnQueue[k];
					for (int l = 0; l < 8; l++) {
						int newRow = row + MiscUtils.DX8[l];
						int newColumn = column + MiscUtils.DY8[l];
						if (newRow >= 0 && newRow < rowCount && newColumn >= 0 &&
							newColumn < columnCount && table[newRow][newColumn] == '0')
						{
							table[newRow][newColumn] = '2';
							rowQueue[size] = newRow;
							columnQueue[size++] = newColumn;
						}
					}
				}
				
				int current = 0;
				for (int k = 0; k < size && current != -1; k++) {
					int row = rowQueue[k];
					int column = columnQueue[k];
					if (row == 0 || column == 0 || row == rowCount - 1 || column == columnCount - 1) {
						current = 0;
						break;
					}
					for (int l = 0; l < 8; l++) {
						int newRow = row + MiscUtils.DX8[l];
						int newColumn = column + MiscUtils.DY8[l];
						if (table[newRow][newColumn] == '0') {
							current = -1;
							break;
						}
						if (table[newRow][newColumn] == '1' && accounted[newRow][newColumn] != call) {
							accounted[newRow][newColumn] = call;
							rowBorder[current] = newRow;
							columnBorder[current] = newColumn;
							ind[newRow][newColumn] = current;
							current++;
						}
					}
				}
				if (current > 0) {
					boolean good = true;
					for (int k = 0; k < current && good; k++) {
						int degree = 0;
						for (int l = 0; l < 4; l++) {
							int row = rowBorder[k] + MiscUtils.DX4[l];
							int column = columnBorder[k] + MiscUtils.DY4[l];
							if (row >= 0 && row < rowCount && column >= 0 && column < columnCount &&
								accounted[row][column] == call)
							{
								if (degree < 2)
									graph[degree][k] = ind[row][column];
								degree++;
							}
						}
						if (degree != 2)
							good = false;
					}
					if (good) {
						int curIndex = 0;
						int lastIndex = graph[0][0];
						int processed = 0;
						do {
							processed++;
							int nextIndex = graph[0][curIndex] + graph[1][curIndex] - lastIndex;
							lastIndex = curIndex;
							curIndex = nextIndex;
						} while (curIndex != 0);
						if (processed == current)
							answer = Math.max(answer, current);
					}
				}
				call++;
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

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
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

	public void close() {
		writer.close();
	}

	}

class IOUtils {

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

class MiscUtils {
	public static final int[] DX4 = {1, 0, -1, 0};
	public static final int[] DY4 = {0, -1, 0, 1};
	public static final int[] DX8 = {1, 1, 1, 0, -1, -1, -1, 0};
	public static final int[] DY8 = {-1, 0, 1, 1, 1, 0, -1, -1};

	}