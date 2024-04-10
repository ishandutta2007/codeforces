import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		int[][] value = IOUtils.readIntTable(in, rowCount, columnCount);
		int[][][][] path = new int[2][2][rowCount][columnCount];
		for (int i = 0; i < 2; i++) {
			int startRow = i == 0 ? 0 : rowCount - 1;
			int dRow = 1 - 2 * i;
			for (int j = 0; j < 2; j++) {
				int startColumn = j == 0 ? 0 : columnCount - 1;
				int dColumn = 1 - 2 * j;
				for (int k = startRow; k < rowCount && k >= 0; k += dRow) {
					for (int l = startColumn; l < columnCount && l >= 0; l += dColumn) {
						path[i][j][k][l] = value[k][l];
						if (k - dRow >= 0 && k - dRow < rowCount)
							path[i][j][k][l] = Math.max(path[i][j][k][l], path[i][j][k - dRow][l] + value[k][l]);
						if (l - dColumn >= 0 && l - dColumn < columnCount)
							path[i][j][k][l] = Math.max(path[i][j][k][l], path[i][j][k][l - dColumn] + value[k][l]);
					}
				}
			}
		}
		int answer = 0;
		for (int i = 1; i < rowCount - 1; i++) {
			for (int j = 1; j < columnCount - 1; j++) {
				int candidate = path[0][0][i - 1][j] + path[1][1][i + 1][j] + path[0][1][i][j + 1] + path[1][0][i][j - 1];
				answer = Math.max(answer, candidate);
				candidate = path[0][0][i][j - 1] + path[1][1][i][j + 1] + path[0][1][i - 1][j] + path[1][0][i + 1][j];
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

	public static int[][] readIntTable(InputReader in, int rowCount, int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readIntArray(in, columnCount);
		return table;
	}

}