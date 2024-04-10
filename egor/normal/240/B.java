import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int red = in.readInt();
		int green = in.readInt();
		int[] heights = IOUtils.readIntArray(in, count);
		int[][] minBadness = new int[2][red + 1];
		int[][] next = new int[2][red + 1];
		ArrayUtils.fill(minBadness, Integer.MAX_VALUE);
		minBadness[0][0] = minBadness[1][0] = 0;
		int total = 0;
		int last = 0;
		for (int i : heights) {
			ArrayUtils.fill(next, Integer.MAX_VALUE);
			int cost = Math.min(i, last);
			for (int j = red; j >= 0; j--) {
				if (minBadness[0][j] != Integer.MAX_VALUE) {
					if (j <= red - i)
						next[0][j + i] = Math.min(next[0][j + i], minBadness[0][j]);
					next[1][j] = Math.min(next[1][j], minBadness[0][j] + cost);
				}
				if (minBadness[1][j] != Integer.MAX_VALUE) {
					next[1][j] = Math.min(next[1][j], minBadness[1][j]);
					if (j <= red - i)
						next[0][j + i] = Math.min(next[0][j + i], minBadness[1][j] + cost);
				}
			}
			last = i;
			total += i;
			int[][] temp = minBadness;
			minBadness = next;
			next = temp;
		}
		int answer = Integer.MAX_VALUE;
		for (int i = Math.max(0, total - green); i <= red; i++)
			answer = Math.min(answer, Math.min(minBadness[0][i], minBadness[1][i]));
		if (answer == Integer.MAX_VALUE)
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

	}

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	}