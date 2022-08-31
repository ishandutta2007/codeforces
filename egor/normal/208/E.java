import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	private int[][] ascendant;
	private IntervalTree tree;
	private int[] start;
	private int[] end;
	private int[] level;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] parent = IOUtils.readIntArray(in, count);
		MiscUtils.decreaseByOne(parent);
		int queryCount = in.readInt();
		int[] answer = new int[queryCount];
		int[] query = new int[queryCount];
		int[] power = new int[queryCount];
		IOUtils.readIntArrays(in, query, power);
		MiscUtils.decreaseByOne(query);
		int[][] graph = new int[count][];
		int[] degree = new int[count];
		for (int i : parent) {
			if (i != -1)
				degree[i]++;
		}
		for (int i = 0; i < count; i++)
			graph[i] = new int[degree[i]];
		for (int i = 0; i < count; i++) {
			if (parent[i] != -1)
				graph[parent[i]][--degree[parent[i]]] = i;
		}
		int[] order = new int[count];
		start = new int[count];
		end = new int[count];
		int offset = 0;
		level = new int[count];
		for (int i = 0; i < count; i++) {
			if (parent[i] == -1) {
				offset = enumerate(graph, order, start, i, offset, level, 0, end);
			}
		}
		if (offset != count)
			throw new RuntimeException();
		tree = new IntervalTree(order);
		ascendant = new int[Integer.bitCount(Integer.highestOneBit(count) - 1) + 1][count];
		ascendant[0] = parent;
		for (int i = 1; i < ascendant.length; i++) {
			for (int j = 0; j < count; j++) {
				if (ascendant[i - 1][j] == -1)
					ascendant[i][j] = -1;
				else
					ascendant[i][j] = ascendant[i - 1][ascendant[i - 1][j]];
			}
		}
		for (int i = 0; i < queryCount; i++) {
			answer[i] = Math.max(0, query(query[i], power[i], level[query[i]], power[i]) - 1);//query(query[i], power[i] - 1, level[query[i]], power[i] - 1));
		}
		out.printLine(Array.wrap(answer).toArray());
	}

	private int query(int vertex, int power, int level, int initialPower) {
		if (vertex == -1)
			return 0;
		if (power == 0) {
			if (level - this.level[vertex] != initialPower)
				throw new RuntimeException();
			return tree.query(start[vertex], end[vertex], level);
		}
		return query(ascendant[Integer.bitCount(Integer.highestOneBit(power) - 1)][vertex], power - Integer.highestOneBit(power), level, initialPower);
	}

	private int enumerate(int[][] graph, int[] order, int[] start, int current, int offset, int[] level, int curLevel, int[] end) {
		order[offset] = curLevel;
		level[current] = curLevel;
		start[current] = offset++;
		for (int i : graph[current])
			offset = enumerate(graph, order, start, i, offset, level, curLevel + 1, end);
		end[current] = offset - 1;
		return offset;
	}
}

class IntervalTree {
	protected int size;
	protected int[][] value;

	protected IntervalTree(int[] array) {
		this.size = array.length;
		int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
		value = new int[nodeCount][];
		init(array);
	}

	public void init(int[] array) {
		init(0, 0, size - 1, array);
	}

	private void init(int root, int left, int right, int[] array) {
		if (left == right) {
			value[root] = new int[]{array[left] * 2};
		} else {
			int middle = (left + right) >> 1;
			init(2 * root + 1, left, middle, array);
			init(2 * root + 2, middle + 1, right, array);
			value[root] = new int[right - left + 1];
			System.arraycopy(value[2 * root + 1], 0, value[root], 0, value[2 * root + 1].length);
			System.arraycopy(value[2 * root + 2], 0, value[root], value[2 * root + 1].length, value[2 * root + 2].length);
			if (value[root].length != value[2 * root + 1].length + value[2 * root + 2].length)
				throw new RuntimeException();
			ArrayUtils.sort(value[root], IntComparator.DEFAULT);
		}
	}

	public int query(int from, int to, int value) {
		return query(0, 0, size - 1, from, to, value);
	}

	private int query(int root, int left, int right, int from, int to, int value) {
		if (left > to || right < from)
			return 0;
		if (left >= from && right <= to)
			return Arrays.binarySearch(this.value[root], 2 * value - 1) - Arrays.binarySearch(this.value[root], 2 * value + 1);
		int middle = (left + right) >> 1;
		return query(2 * root + 1, left, middle, from, to, value) + query(2 * root + 2, middle + 1, right, from, to, value);
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

abstract class Array<T> extends AbstractList<T> implements RandomAccess {

	public static List<Integer> wrap(int...array) {
		return new IntArray(array);
	}

	protected static class IntArray extends Array<Integer> {
		protected final int[] array;

		protected IntArray(int[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Integer get(int index) {
			return array[index];
		}

		public Integer set(int index, Integer value) {
			int result = array[index];
			array[index] = value;
			return result;
		}
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