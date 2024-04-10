import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] radius = IOUtils.readIntArray(in, count);
		int[] reverse = new int[2 * count];
		for (int i = 0; i < count; i++)
			reverse[i] = radius[count - i - 1];
		System.arraycopy(reverse, 0, reverse, count, count);
		int[][] time = new int[Integer.bitCount(Integer.highestOneBit(count) - 1) + 1][];
		time[0] = new int[2 * count];
		for (int i = 0; i < time[0].length; i++)
			time[0][i] = i + reverse[i];
		IntervalTree[] trees = new IntervalTree[time.length];
		for (int i = 1; i < time.length; i++) {
			IntervalTree tree = new IntervalTree(time[i - 1]);
			trees[i - 1] = tree;
			time[i] = new int[2 * count];
			for (int j = 0; j < time[i].length; j++)
				time[i][j] = tree.query(j, time[i - 1][j]);
		}
		trees[trees.length - 1] = new IntervalTree(time[time.length- 1]);
		long answer = 0;
		for (int i = 0; i < count; i++) {
			int index = time.length - 1;
			int current = i;
			int target = count - 1 + i;
			while (index >= 0) {
				int queryResult = trees[index].query(i, current);
				if (queryResult >= target)
					index--;
				else {
					current = queryResult;
					answer += 1 << index;
				}
			}
			answer++;
		}
		out.printLine(answer);
	}
}

class IntervalTree {
	protected int size;
	protected int[] value;

	protected IntervalTree(int[] array) {
		this.size = array.length;
		int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
		value = new int[nodeCount];
		init(array);
	}

	public void init(int[] array) {
		init(0, 0, size - 1, array);
	}

	private void init(int root, int left, int right, int[] array) {
		if (left == right)
			value[root] = array[left];
		else {
			int middle = (left + right) >> 1;
			init(2 * root + 1, left, middle, array);
			init(2 * root + 2, middle + 1, right, array);
			value[root] = Math.max(value[2 * root + 1], value[2 * root + 2]);
		}
	}

	public int query(int from, int to) {
		return query(0, 0, size - 1, from, to);
	}

	private int query(int root, int left, int right, int from, int to) {
		if (left > to || right < from)
			return 0;
		if (left >= from && right <= to)
			return value[root];
		int middle = (left + right) >> 1;
		int leftResult = query(2 * root + 1, left, middle, from, to);
		int rightResult = query(2 * root + 2, middle + 1, right, from, to);
		return Math.max(leftResult, rightResult);
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