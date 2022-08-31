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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int stopCount = in.readInt();
		int passengerCount = in.readInt();
		long fine = in.readInt();
		int[] cost = IOUtils.readIntArray(in, stopCount);
		int[] probability = IOUtils.readIntArray(in, stopCount - 1);
		long[] profit = new long[stopCount - 1];
		for (int i = 0; i < stopCount - 1; i++)
			profit[i] = (cost[i + 1] - cost[i]) * 50L - fine * probability[i];
		Tree tree = new Tree(profit);
		long answer = 0;
		for (int i = 0; i < passengerCount; i++) {
			int from = in.readInt() - 1;
			int to = in.readInt() - 1;
			answer += tree.get(from, to);
		}
		out.printLine((double)answer / 100);
	}
}

class Tree {
	private long[] min;
	private long[] sum;
	private long[] minLeft;
	private long[] minRight;
	private long[] resultMin;
	private long[] resultMinLeft;
	private long[] resultMinRight;
	private int length;

	Tree(long[] array) {
		int nodeCount = Integer.highestOneBit(array.length) << 2;
		sum = new long[nodeCount];
		min = new long[nodeCount];
		minLeft = new long[nodeCount];
		minRight = new long[nodeCount];
		resultMin = new long[nodeCount];
		resultMinLeft = new long[nodeCount];
		resultMinRight = new long[nodeCount];
		length = array.length;
		init(0, 0, length, array);
	}

	private void init(int root, int left, int right, long[] array) {
		if (left + 1 == right) {
			sum[root] = array[left];
			min[root] = Math.max(array[left], 0);
			minLeft[root] = array[left];
			minRight[root] = array[left];
			return;
		}
		int middle = (left + right) >> 1;
		init(2 * root + 1, left, middle, array);
		init(2 * root + 2, middle, right, array);
		sum[root] = sum[2 * root + 1] + sum[2 * root + 2];
		min[root] = Math.max(minRight[2 * root + 1] + minLeft[2 * root + 2], Math.max(min[2 * root + 1], min[2 * root + 2]));
		minLeft[root] = Math.max(minLeft[2 * root + 1], sum[2 * root + 1] + minLeft[2 * root + 2]);
		minRight[root] = Math.max(minRight[2 * root + 2], sum[2 * root + 2] + minRight[2 * root + 1]);
	}

	long get(int from, int to) {
		long result = get(0, 0, length, from, to);
//		result -= resultMin[0];
		return resultMin[0];
	}

	private long get(int root, int left, int right, int from, int to) {
		if (right <= from || left >= to)
			return resultMin[root] = resultMinLeft[root] = resultMinRight[root] = 0;
		if (from <= left && right <= to) {
			resultMin[root] = min[root];
			resultMinLeft[root] = minLeft[root];
			resultMinRight[root] = minRight[root];
			return sum[root];
		}
		int middle = (left + right) >> 1;
		long sumLeft = get(2 * root + 1, left, middle, from, to);
		long sumRight = get(2 * root + 2, middle, right, from, to);
		resultMin[root] = Math.max(resultMinLeft[2 * root + 2] + resultMinRight[2 * root + 1], Math.max(resultMin[2 * root + 1], resultMin[2 * root + 2]));
		resultMinLeft[root] = Math.max(resultMinLeft[2 * root + 1], sumLeft + resultMinLeft[2 * root + 2]);
		resultMinRight[root] = Math.max(resultMinRight[2 * root + 2], sumRight + resultMinRight[2 * root + 1]);
		return sumLeft + sumRight;
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

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	}