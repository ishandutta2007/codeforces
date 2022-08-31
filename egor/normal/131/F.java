import java.io.IOException;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		int minStars = in.readInt();
		char[][] map = IOUtils.readTable(in, rowCount, columnCount);
		if (rowCount < 3 || columnCount < 3) {
			out.printLine(0);
			return;
		}
		boolean[][] isStar = new boolean[rowCount - 2][columnCount - 2];
		for (int i = 1; i < rowCount - 1; i++) {
			for (int j = 1; j < columnCount - 1; j++) {
				if (map[i][j] == '0' || map[i + 1][j] == '0' || map[i - 1][j] == '0' || map[i][j + 1] == '0' ||
					map[i][j - 1] == '0')
				{
					continue;
				}
				isStar[i - 1][j - 1] = true;
			}
		}
		rowCount -= 2;
		columnCount -= 2;
		int[][] countStars = new int[rowCount + 1][columnCount + 1];
		for (int i = 0; i < rowCount; i++) {
			int row = 0;
			for (int j = 0; j < columnCount; j++) {
				if (isStar[i][j])
					row++;
				countStars[i + 1][j + 1] = row + countStars[i][j + 1];
			}
		}
		long answer = 0;
		for (int i = 1; i <= rowCount; i++) {
			for (int j = 1; j <= columnCount; j++) {
				int column = j;
				for (int k = 0; k < i; k++) {
					while (column >= 0 && countStars[i][j] + countStars[k][column] - countStars[i][column] - countStars[k][j] < minStars)
						column--;
					answer += column + 1;
				}
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