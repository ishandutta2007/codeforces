import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		char[][] labyrinth = IOUtils.readTable(in, rowCount, columnCount);
		boolean[][] visited = new boolean[rowCount][columnCount];
		int[][] visitedRow = new int[rowCount][columnCount];
		int[][] visitedColumn = new int[rowCount][columnCount];
		int[] rowQueue = new int[rowCount * columnCount];
		int[] columnQueue = new int[rowCount * columnCount];
		int size = 0;
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				if (labyrinth[i][j] == 'S') {
					visited[i][j] = true;
					visitedRow[i][j] = i;
					visitedColumn[i][j] = j;
					rowQueue[size] = i;
					columnQueue[size++] = j;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			int row = rowQueue[i];
			int column = columnQueue[i];
			for (int j = 0; j < 4; j++) {
				int newRow = row + MiscUtils.DX4[j];
				int newColumn = column + MiscUtils.DY4[j];
				if (newRow == rowCount)
					newRow = 0;
				else if (newRow == -1)
					newRow = rowCount - 1;
				if (newColumn == columnCount)
					newColumn = 0;
				else if (newColumn == -1)
					newColumn = columnCount - 1;
				if (labyrinth[newRow][newColumn] != '#') {
					int actualRow = visitedRow[row][column] + MiscUtils.DX4[j];
					int actualColumn = visitedColumn[row][column] + MiscUtils.DY4[j];
					if (visited[newRow][newColumn]) {
						if (actualRow != visitedRow[newRow][newColumn] || actualColumn != visitedColumn[newRow][newColumn]) {
							out.printLine("Yes");
							return;
						}
					} else {
						visited[newRow][newColumn] = true;
						visitedRow[newRow][newColumn] = actualRow;
						visitedColumn[newRow][newColumn] = actualColumn;
						rowQueue[size] = newRow;
						columnQueue[size++] = newColumn;
					}
				}
			}
		}
		out.printLine("No");
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

	}