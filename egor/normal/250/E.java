import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		char[][] map = IOUtils.readTable(in, rowCount, columnCount);
		int column = 0;
		long answer = 0;
		boolean direction = true;
		for (int row = 0; row < rowCount - 1; row++) {
			int nextLeft = 0;
			int nextRight = columnCount - 1;
			for (int j = column; j < columnCount - 1; j++) {
				if (map[row + 1][j] == '.' || map[row][j + 1] != '.') {
					nextRight = j;
					break;
				}
			}
			for (int j = column; j > 0; j--) {
				if (map[row + 1][j] == '.' || map[row][j - 1] != '.') {
					nextLeft = j;
					break;
				}
			}
			int sinceBreak = 0;
			while (sinceBreak < 3) {
				sinceBreak++;
				if (direction) {
					answer += nextRight - column;
					column = nextRight;
				} else {
					answer += column - nextLeft;
					column = nextLeft;
				}
				answer++;
				if (map[row + 1][column] == '.')
					break;
				if (direction) {
					if (column != columnCount - 1 && map[row][column + 1] == '+') {
						map[row][column + 1] = '.';
						sinceBreak = 0;
						nextRight = columnCount - 1;
						for (int j = column + 1; j < columnCount - 1; j++) {
							if (map[row + 1][j] == '.' || map[row][j + 1] != '.') {
								nextRight = j;
								break;
							}
						}
					}
				} else {
					if (column != 0 && map[row][column - 1] == '+') {
						map[row][column - 1] = '.';
						sinceBreak = 0;
						nextLeft = 0;
						for (int j = column - 1; j > 0; j--) {
							if (map[row + 1][j] == '.' || map[row][j - 1] != '.') {
								nextLeft = j;
								break;
							}
						}
					}
				}
				direction = !direction;
			}
			if (sinceBreak == 3) {
				out.printLine("Never");
				return;
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