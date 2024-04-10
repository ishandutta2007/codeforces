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
		int count = in.readInt();
		int size = in.readInt();
		int[][] direction = new int[size + 1][size + 1];
		ArrayUtils.fill(direction, -1);
		for (int i = 0; i < count; i++) {
			int x0 = in.readInt();
			int y0 = in.readInt();
			int x1 = in.readInt();
			int y1 = in.readInt();
			int length = Math.abs(x0 - x1) + Math.abs(y0 - y1);
			for (int j = 0; j < 4; j++) {
				if (x1 == x0 + MiscUtils.DX4[j] * length && y1 == y0 + MiscUtils.DY4[j] * length) {
					for (int k = 0; k <= length; k++)
						direction[x0 + MiscUtils.DX4[j] * k][y0 + MiscUtils.DY4[j] * k] = j;
				}
			}
		}
		int[] next = new int[1 << 20];
		for (int i = 0; i <= size; i++) {
			for (int j = 0; j <= size; j++) {
				for (int k = 0; k < 4; k++) {
					int nk = direction[i][j] == -1 ? k : direction[i][j];
					int ni = i + MiscUtils.DX4[nk];
					int nj = j + MiscUtils.DY4[nk];
					if (!MiscUtils.isValidCell(ni, nj, size + 1, size + 1)) {
						ni = i;
						nj = j;
					}
					next[i + (j << 5) + (k << 10)] = ni + (nj << 5) + (nk << 10);
				}
			}
		}
		for (int i = 1; i <= 50; i++) {
			for (int j = 0; j < (1 << 12); j++)
				next[(i << 12) + j] = next[((i - 1) << 12) + next[((i - 1) << 12) + j]];
		}
		int queryCount = in.readInt();
		for (int i = 0; i < queryCount; i++) {
			int x = in.readInt();
			int y = in.readInt();
			char dir = in.readCharacter();
			long time = in.readLong();
			if (dir == 'U')
				dir = 3;
			else if (dir == 'D')
				dir = 1;
			else if (dir == 'R')
				dir = 0;
			else
				dir = 2;
			int key = x + (y << 5) + (dir << 10);
			while (time > 0) {
				int level = Long.bitCount(Long.highestOneBit(time) - 1);
				key = next[(level << 12) + key];
				time -= 1L << level;
			}
			out.printLine(key & 31, (key >> 5) & 31);
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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
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

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	}

class MiscUtils {
	public static final int[] DX4 = {1, 0, -1, 0};
	public static final int[] DY4 = {0, -1, 0, 1};

    public static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
		return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
	}

	}