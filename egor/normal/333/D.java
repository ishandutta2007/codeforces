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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		int[][] table = IOUtils.readIntTable(in, rowCount, columnCount);
		int left = 0;
		int right = (int) 1e9;
		int[][] masks = new int[rowCount][(columnCount + 31) >> 5];
		while (left < right) {
			int middle = (left + right + 1) >> 1;
			ArrayUtils.fill(masks, 0);
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++) {
					if (table[i][j] >= middle)
						masks[i][j >> 5] += 1 << (j & 31);
				}
			}
			boolean can = false;
			for (int i = 0; i < rowCount && !can; i++) {
				for (int j = i + 1; j < rowCount && !can; j++) {
					int qty = 0;
					for (int k = 0; k < masks[i].length && qty < 2; k++) {
						int current = masks[i][k] & masks[j][k];
						if (current != 0) {
							qty++;
							if ((current & (current - 1)) != 0)
								qty++;
						}
					}
					if (qty >= 2)
						can = true;
				}
			}
			if (can)
				left = middle;
			else
				right = middle - 1;
		}
//		for (int i = 0; i < rowCount; i++) {
//			for (int j = i + 1; j < rowCount; j++) {
//				int max = -1;
//				int secondMax = -1;
//				for (int k = 0; k < columnCount; k++) {
//					int sum = Math.min(table[i][k], table[j][k]);
//					if (sum > max) {
//						secondMax = max;
//						max = sum;
//					} else
//						secondMax = Math.max(secondMax, sum);
//				}
//				answer = Math.max(answer, secondMax);
//			}
//		}
		out.printLine(left);
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

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	}