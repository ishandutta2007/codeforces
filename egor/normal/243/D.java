import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
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
		int vx = in.readInt();
		int vy = in.readInt();
		int[][] height = IOUtils.readIntTable(in, count, count);
		final int[][] distance = new int[count][count];
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++)
				distance[i][j] = Math.min(Math.min(vx * i + vy * j, vx * i + vy * (j + 1)), Math.min(vx * (i + 1) + vy * j, vx * (i + 1) + vy * (j + 1)));
		}
		int[] positions = new int[(count + 1) * (count + 1)];
		for (int i = 0; i <= count; i++) {
			for (int j = 0; j <= count; j++)
				positions[i * (count + 1) + j] = vy * i - vx * j;
		}
		ArrayUtils.sort(positions, IntComparator.DEFAULT);
		positions = ArrayUtils.unique(positions);
		IntervalTree tree = new IntervalTree(positions.length - 1);
		int[] order = new int[count * count];
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++)
				order[i * count + j] = (i << 10) + j;
		}
		ArrayUtils.sort(order, new IntComparator() {
			public int compare(int first, int second) {
				return distance[first >> 10][first & 1023] - distance[second >> 10][second & 1023];
			}
		});
		long answer = 0;
		for (int i : order) {
			int x = i >> 10;
			int y = i & 1023;
			int from = Math.min(Math.min(vy * x - vx * y, vy * x - vx * (y + 1)), Math.min(vy * (x + 1) - vx * y, vy * (x + 1) - vx * (y + 1)));
			int to = Math.max(Math.max(vy * x - vx * y, vy * x - vx * (y + 1)), Math.max(vy * (x + 1) - vx * y, vy * (x + 1) - vx * (y + 1)));
			from = Arrays.binarySearch(positions, from);
			to = Arrays.binarySearch(positions, to);
			long min = tree.query(from, to - 1);
			answer += Math.max(0, height[x][y] - min);
			tree.update(from, to - 1, height[x][y]);
		}
		out.printLine(answer);
	}

	static class IntervalTree {
		protected int size;
		protected int[] value;
		protected int[] delta;

		protected IntervalTree(int size) {
			this.size = size;
			int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
			value = new int[nodeCount];
			delta = new int[nodeCount];
		}

		public void update(int from, int to, int delta) {
			update(0, 0, size - 1, from, to, delta);
		}

		private void update(int root, int left, int right, int from, int to, int delta) {
			if (left > to || right < from)
				return;
			if (left >= from && right <= to) {
				this.delta[root] = Math.max(this.delta[root], delta);
				value[root] = Math.max(value[root], delta);
				return;
			}
			this.delta[2 * root + 1] = Math.max(this.delta[2 * root + 1], this.delta[root]);
			this.delta[2 * root + 2] = Math.max(this.delta[2 * root + 2], this.delta[root]);
			int middle = (left + right) >> 1;
			value[2 * root + 1] = Math.max(value[2 * root + 1], this.delta[root]);
			value[2 * root + 2] = Math.max(value[2 * root + 2], this.delta[root]);
			this.delta[root] = 0;
			update(2 * root + 1, left, middle, from, to, delta);
			update(2 * root + 2, middle + 1, right, from, to, delta);
			value[root] = Math.min(value[2 * root + 1], value[2 * root + 2]);
		}

		public int query(int from, int to) {
			return query(0, 0, size - 1, from, to);
		}

		private int query(int root, int left, int right, int from, int to) {
			if (left > to || right < from)
				return Integer.MAX_VALUE;
			if (left >= from && right <= to)
				return value[root];
			delta[2 * root + 1] = Math.max(delta[2 * root + 1], delta[root]);
			delta[2 * root + 2] = Math.max(delta[2 * root + 2], delta[root]);
			int middle = (left + right) >> 1;
			value[2 * root + 1] = Math.max(value[2 * root + 1], delta[root]);
			value[2 * root + 2] = Math.max(value[2 * root + 2], delta[root]);
			this.delta[root] = 0;
			return Math.min(query(2 * root + 1, left, middle, from, to), query(2 * root + 2, middle + 1, right, from, to));
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
	private static int[] tempInt = new int[0];

	public static int[] sort(int[] array, IntComparator comparator) {
		return sort(array, 0, array.length, comparator);
	}

	public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
		ensureCapacityInt(to - from);
		System.arraycopy(array, from, tempInt, 0, to - from);
		sortImpl(array, from, to, tempInt, 0, to - from, comparator);
		return array;
	}

	private static void ensureCapacityInt(int size) {
		if (tempInt.length >= size)
			return;
		size = Math.max(size, tempInt.length << 1);
		tempInt = new int[size];
	}

	private static void sortImpl(int[] array, int from, int to, int[] temp, int fromTemp, int toTemp, IntComparator comparator) {
		if (to - from <= 1)
			return;
		int middle = (to - from) >> 1;
		int tempMiddle = fromTemp + middle;
		sortImpl(temp, fromTemp, tempMiddle, array, from, from + middle, comparator);
		sortImpl(temp, tempMiddle, toTemp, array, from + middle, to, comparator);
		int index = from;
		int index1 = fromTemp;
		int index2 = tempMiddle;
		while (index1 < tempMiddle && index2 < toTemp) {
			if (comparator.compare(temp[index1], temp[index2]) <= 0)
				array[index++] = temp[index1++];
			else
				array[index++] = temp[index2++];
		}
		if (index1 != tempMiddle)
			System.arraycopy(temp, index1, array, index, tempMiddle - index1);
		if (index2 != toTemp)
			System.arraycopy(temp, index2, array, index, toTemp - index2);
	}

	public static int[] unique(int[] array) {
		return unique(array, 0, array.length);
	}

	public static int[] unique(int[] array, int from, int to) {
		if (from == to)
			return new int[0];
		int count = 1;
		for (int i = from + 1; i < to; i++) {
			if (array[i] != array[i - 1])
				count++;
		}
		int[] result = new int[count];
		result[0] = array[from];
		int index = 1;
		for (int i = from + 1; i < to; i++) {
			if (array[i] != array[i - 1])
				result[index++] = array[i];
		}
		return result;
	}

	}

interface IntComparator {
    public static final IntComparator DEFAULT = new IntComparator() {
        public int compare(int first, int second) {
            if (first < second)
                return -1;
            if (first > second)
                return 1;
            return 0;
        }
    };

	public int compare(int first, int second);
}