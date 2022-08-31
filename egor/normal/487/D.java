import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
	private char[][] map;
	private int buben;
	private int columnCount;
	private int[][] upRow;
	private int[][] upColumn;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		columnCount = in.readInt();
		int queryCount = in.readInt();
		buben = (int) Math.sqrt(rowCount);
//		buben = 4;
		map = IOUtils.readTable(in, rowCount, columnCount);
		upRow = new int[rowCount][columnCount];
		upColumn = new int[rowCount][columnCount];
		for (int i = 0; i < rowCount; i++) {
			updateRow(i);
		}
		for (int i = 0; i < queryCount; i++) {
			char type = in.readCharacter();
			int row = in.readInt() - 1;
			int column = in.readInt() - 1;
			if (type == 'C') {
				char to = in.readCharacter();
				int upTo = row + buben - row % buben;
				upTo = Math.min(upTo, rowCount);
				map[row][column] = to;
				for (int j = row; j < upTo; j++) {
					updateRow(j);
				}
			} else {
				while (row >= 0 && column >= 0 && column < columnCount) {
					int nRow = upRow[row][column];
					int nColumn = upColumn[row][column];
					row = nRow;
					column = nColumn;
				}
				out.printLine(row + 1, column + 1);
			}
		}
    }

	private void updateRow(int i) {
		boolean terminalRow = i % buben == 0;
		for (int j = 0; j < columnCount; j++) {
			if (map[i][j] == '^') {
				if (terminalRow) {
					upRow[i][j] = i - 1;
					upColumn[i][j] = j;
				} else {
					upRow[i][j] = upRow[i - 1][j];
					upColumn[i][j] = upColumn[i - 1][j];
				}
			}
			if (j < columnCount - 1 && map[i][j] == '>' && map[i][j + 1] == '<') {
				upRow[i][j] = -2;
				upColumn[i][j] = -2;
				upRow[i][j + 1] = -2;
				upColumn[i][j + 1] = -2;
			}
		}
		for (int j = 0; j < columnCount; j++) {
			if (map[i][j] == '<' && (j == 0 || map[i][j - 1] != '>')) {
				upRow[i][j] = j > 0 ? upRow[i][j - 1] : i;
				upColumn[i][j] = j > 0 ? upColumn[i][j - 1] : -1;
			}
		}
		for (int j = columnCount - 1; j >= 0; j--) {
			if (map[i][j] == '>' && (j == columnCount - 1 || map[i][j + 1] != '<')) {
				upRow[i][j] = j < columnCount - 1 ? upRow[i][j + 1] : i;
				upColumn[i][j] = j < columnCount - 1 ? upColumn[i][j + 1] : columnCount;
			}
		}
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