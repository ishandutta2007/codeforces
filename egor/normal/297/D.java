import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int height = in.readInt();
		int width = in.readInt();
		int colorCount = in.readInt();
		boolean[][] inRows = new boolean[height][width - 1];
		boolean[][] inColumns = new boolean[width][height - 1];
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width - 1; j++)
				inRows[i][j] = in.readCharacter() == 'E';
			if (i != height - 1) {
				for (int j = 0; j < width; j++)
					inColumns[j][i] = in.readCharacter() == 'E';
			}
		}
		if (colorCount == 1) {
			int total = width * (height - 1) + height * (width - 1);
			total -= total / 4;
			for (boolean[] row : inRows) {
				for (boolean b : row) {
					if (b)
						total--;
				}
			}
			for (boolean[] row : inColumns) {
				for (boolean b : row) {
					if (b)
						total--;
				}
			}
			if (total > 0)
				out.printLine("NO");
			else {
				out.printLine("YES");
				int[] row = new int[width];
				Arrays.fill(row, 1);
				for (int i = 0; i < height; i++)
					out.printLine(row);
			}
			return;
		}
		out.printLine("YES");
		boolean shouldRotate = false;
		if (height > width) {
			int temp = height;
			height = width;
			width = temp;
			shouldRotate = true;
			boolean[][] temp2 = inRows;
			inRows = inColumns;
			inColumns = temp2;
		}
		int[][] answer = new int[height][width];
		answer[0][0] = 1;
		for (int i = 1; i < width; i++) {
			if (inRows[0][i - 1])
				answer[0][i] = answer[0][i - 1];
			else
				answer[0][i] = 3 - answer[0][i - 1];
		}
		for (int i = 1; i < height; i++) {
			int current = 0;
			answer[i][0] = 1;
			if ((answer[i][0] == answer[i - 1][0]) != inColumns[0][i - 1])
				current++;
			for (int j = 1; j < width; j++) {
				if (inRows[i][j - 1])
					answer[i][j] = answer[i][j - 1];
				else
					answer[i][j] = 3 - answer[i][j - 1];
				if ((answer[i][j] == answer[i - 1][j]) != inColumns[j][i - 1])
					current++;
			}
			if (current > width - current) {
				for (int j = 0; j < width; j++)
					answer[i][j] = 3 - answer[i][j];
			}
		}
		if (shouldRotate) {
			int[][] temp = new int[width][height];
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++)
					temp[j][i] = answer[i][j];
			}
			answer = temp;
		}
		for (int[] row : answer)
			out.printLine(row);
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