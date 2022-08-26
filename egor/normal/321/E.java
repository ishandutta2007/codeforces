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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int carriageCount = in.readInt();
		int[][] cost = IOUtils.readIntTable(in, count, count);
		int[][] sum = new int[count + 1][count + 1];
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++)
				sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + cost[i][j];
		}
		for (int i = 0; i < count; i++) {
			for (int j = i; j < count; j++)
				cost[i][j] = (sum[j + 1][j + 1] - sum[i][j + 1] - sum[j + 1][i] + sum[i][i]) >> 1;
		}
		int[] answer = new int[count];
		System.arraycopy(cost[0], 0, answer, 0, count);
		int[] next = new int[count];
		for (int i = 0; i < carriageCount - 1; i++) {
			System.arraycopy(answer, 0, next, 0, count);
			go(next, answer, cost, 0, count - 1, 0, count - 1);
			int[] t = answer;
			answer = next;
			next = t;
		}
		out.printLine(answer[count - 1]);
    }

	private void go(int[] next, int[] answer, int[][] cost, int left, int right, int from, int to) {
		if (left > right)
			return;
		int current = (left + right) >> 1;
		int best = from;
		for (int i = from; i <= to && i < current; i++) {
			if (next[current] > answer[i] + cost[i + 1][current]) {
				next[current] = answer[i] + cost[i + 1][current];
				best = i;
			}
		}
		go(next, answer, cost, left, current - 1, from, best);
		go(next, answer, cost, current + 1, right, best, to);
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