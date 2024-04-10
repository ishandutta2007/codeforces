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
		int changes = in.readInt();
		int[][] table = IOUtils.readIntTable(in, rowCount, columnCount);
		if (rowCount > columnCount) {
			int temp = rowCount;
			rowCount = columnCount;
			columnCount = temp;
			int[][] newTable = new int[rowCount][columnCount];
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++)
					newTable[i][j] = table[j][i];
			}
			table = newTable;
		}
		if (columnCount <= 2 * changes) {
			int answer = Integer.MAX_VALUE;
			int[] mask = new int[columnCount];
			for (int i = 0; i < columnCount; i++) {
				for (int j = 0; j < rowCount; j++)
					mask[i] += table[j][i] << j;
			}
			for (int i = 0; i < (1 << rowCount); i++) {
				int current = 0;
				for (int j : mask) {
					int value = Integer.bitCount(j ^ i);
					current += Math.min(value, rowCount - value);
				}
				answer = Math.min(answer, current);
			}
			if (answer > changes)
				answer = -1;
			out.printLine(answer);
			return;
		}
		int[] rowChanges = new int[rowCount];
		for (int i = 1; i < rowCount; i++) {
			int delta = 0;
			for (int j = 0; j < columnCount; j++) {
				if (table[i][j] != table[i - 1][j])
					delta++;
			}
			if (delta > changes)
				rowChanges[i] = rowChanges[i - 1] + 1;
			else
				rowChanges[i] = rowChanges[i - 1];
		}
		int answer = 0;
		for (int i = 0; i < columnCount; i++) {
			int current = 0;
			for (int j = 0; j < rowCount; j++)
				current += (rowChanges[j] & 1) ^ table[j][i];
			answer += Math.min(current, rowCount - current);
		}
		if (answer > changes)
			answer = -1;
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