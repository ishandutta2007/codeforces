import java.util.NavigableSet;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.SortedSet;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Set;
import java.util.NoSuchElementException;
import java.util.TreeSet;
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
        int[] color = new int[count];
        final int[] sum = new int[count];
        IOUtils.readIntArrays(in, color, sum);
        Comparator<Integer> comparator = new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                if (sum[o1] != sum[o2])
                    return sum[o1] - sum[o2];
                return o1 - o2;
            }
        };
        NavigableSet<Integer> white = new TreeSet<Integer>(comparator);
        NavigableSet<Integer> black = new TreeSet<Integer>(comparator);
        for (int i = 0; i < count; i++) {
            if (color[i] == 0)
                white.add(i);
            else
                black.add(i);
        }
        for (int i = 0; i < count - 1; i++) {
            if (white.size() < black.size()) {
                NavigableSet<Integer> temp = white;
                white = black;
                black = temp;
            }
            if (sum[white.first()] <= sum[black.first()]) {
                int j = white.pollFirst();
                int k = black.pollLast();
                sum[k] -= sum[j];
                out.printLine(j + 1, k + 1, sum[j]);
                black.add(k);
            } else {
                int j = black.pollFirst();
                int k = white.pollLast();
                sum[k] -= sum[j];
                out.printLine(j + 1, k + 1, sum[j]);
                white.add(k);
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