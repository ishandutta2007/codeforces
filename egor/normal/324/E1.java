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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int edgeCount = in.readInt();
		int[] from = new int[edgeCount];
		int[] to = new int[edgeCount];
		int[][] path = new int[edgeCount][];
		int[][] reversePath = new int[edgeCount][];
		for (int i = 0; i < edgeCount; i++) {
			from[i] = in.readInt() - 1;
			to[i] = in.readInt() - 1;
			int length = in.readInt();
			path[i] = IOUtils.readIntArray(in, length);
			reversePath[i] = path[i].clone();
			ArrayUtils.reverse(reversePath[i]);
		}
		MiscUtils.decreaseByOne(path);
		MiscUtils.decreaseByOne(reversePath);
		int[][] id = new int[count][count];
		ArrayUtils.fill(id, -1);
		for (int i = 0; i < edgeCount; i++)
			id[from[i]][to[i]] = i;
		int[][] backId = new int[count][count];
		ArrayUtils.fill(backId, -1);
		for (int i = 0; i < edgeCount; i++)
			backId[to[i]][from[i]] = i;
		int[] queue = new int[2 * count];
		int[] backQueue = new int[2 * count];
		for (int i = 0; i < edgeCount; i++) {
			if (path[i].length > 2 * count)
				continue;
			for (int j = 1; j < path[i].length; j++) {
				if (path[i][j] == to[i] && path[i][j - 1] == from[i]) {
					int length = 0;
					for (int k = j; k < path[i].length; k++)
						queue[length++] = path[i][k];
					length = process(length, queue, from, to, path, id);
					if (length > 2 * count)
						continue;
					int startLength = 0;
					for (int k = j - 1; k >= 0; k--)
						backQueue[startLength++] = path[i][k];
					startLength = process(startLength, backQueue, to, from, reversePath, backId);
					if (length + startLength <= 2 * count) {
						int[] answer = new int[length + startLength];
						for (int k = 0; k < startLength; k++)
							answer[k] = backQueue[startLength - k - 1] + 1;
						for (int k = 0; k < length; k++)
							answer[k + startLength] = queue[k] + 1;
						out.printLine(answer.length);
						out.printLine(answer);
						return;
					}
				}
			}
		}
		out.printLine(0);
    }

	private int process(int length, int[] queue, int[] from, int[] to, int[][] path, int[][] id) {
		int current = queue[0];
		for (int i = 1; i < length; i++) {
			int next = queue[i];
			int edge = id[current][next];
			if (edge == -1 || length + path[edge].length > queue.length)
				return queue.length + 1;
			for (int j : path[edge])
				queue[length++] = j;
			current = next;
		}
		return length;
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

	public static void reverse(int[] array) {
		for (int i = 0, j = array.length - 1; i < j; i++, j--) {
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
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