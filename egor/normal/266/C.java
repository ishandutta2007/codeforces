import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int count = in.readInt();
        int[] row = new int[count - 1];
        int[] column = new int[count - 1];
        IOUtils.readIntArrays(in, row, column);
        MiscUtils.decreaseByOne(row, column);
        int[] queue = new int[count - 1];
        int size = 0;
        int nextRow = count - 1;
        int nextColumn = 0;
        List<Swap> answer = new ArrayList<Swap>();
        boolean[] added = new boolean[count - 1];
        for (int i = 0; i < count - 1; i++) {
            if (size == i) {
                for (int j = 0; j < count - 1; j++) {
                    if (!added[j]) {
                        added[j] = true;
                        queue[size++] = j;
                        break;
                    }
                }
            }
            int currentRow = row[queue[i]];
            int currentColumn = column[queue[i]];
            if (currentRow <= nextRow) {
                if (currentRow != nextRow)
                    answer.add(new Swap(1, currentRow + 1, nextRow + 1));
                for (int j = 0; j < count - 1; j++) {
                    if (currentRow == row[j]) {
                        row[j] = nextRow;
                        if (!added[j]) {
                            queue[size++] = j;
                            added[j] = true;
                        }
                    } else if (nextRow == row[j])
                        row[j] = currentRow;
                }
                nextRow--;
            }
            if (currentColumn >= nextColumn) {
                if (currentColumn != nextColumn)
                    answer.add(new Swap(2, currentColumn + 1, nextColumn + 1));
                for (int j = 0; j < count - 1; j++) {
                    if (currentColumn == column[j]) {
                        column[j] = nextColumn;
                        if (!added[j]) {
                            queue[size++] = j;
                            added[j] = true;
                        }
                    } else if (nextColumn == column[j])
                        column[j] = currentColumn;
                }
                nextColumn++;
            }
        }
        for (int i = 0, j = nextColumn - 1; i < j; i++, j--)
            answer.add(new Swap(2, i + 1, j + 1));
        out.printLine(answer.size());
        for (Swap swap : answer)
            out.printLine(swap.type, swap.from, swap.to);
    }

    static class Swap {
        final int type, from, to;

        Swap(int type, int from, int to) {
            this.type = type;
            this.from = from;
            this.to = to;
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

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	}

class MiscUtils {

    public static void decreaseByOne(int[]...arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

	}