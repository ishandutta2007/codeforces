import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int count = in.readInt();
        int edgeCount = in.readInt();
        int[] from = new int[edgeCount];
        int[] to = new int[edgeCount];
        int[] weight = new int[edgeCount];
        IOUtils.readIntArrays(in, from, to, weight);
        MiscUtils.decreaseByOne(from, to);
        int[][] distance = new int[count][count];
        ArrayUtils.fill(distance, Integer.MAX_VALUE);
        for (int i = 0; i < count; i++)
            distance[i][i] = 0;
        for (int i = 0; i < edgeCount; i++)
            distance[from[i]][to[i]] = distance[to[i]][from[i]] = weight[i];
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                for (int k = 0; k < count; k++) {
                    if (distance[j][i] != Integer.MAX_VALUE && distance[i][k] != Integer.MAX_VALUE)
                        distance[j][k] = Math.min(distance[j][k], distance[j][i] + distance[i][k]);
                }
            }
        }
        final int[] position = new int[count];
        final int[] leftValue = new int[count];
        final int[] rightValue = new int[count];
        int[] value = new int[count];
        int[] order = ArrayUtils.createOrder(count);
        int[] leftOrder = ArrayUtils.createOrder(count);
        int[] rightOrder = ArrayUtils.createOrder(count);
        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < edgeCount; i++) {
            for (int j = 0; j < count; j++) {
                int a = distance[from[i]][j] * 2;
                int b = distance[to[i]][j] * 2;
                if (a - b >= weight[i] * 2) {
                    position[j] = 0;
                    leftValue[j] = b + weight[i] * 2;
                    rightValue[j] = b;
                } else if (b - a >= weight[i] * 2) {
                    position[j] = 2 * weight[i];
                    leftValue[j] = a;
                    rightValue[j] = a + 2 * weight[i];
                } else {
                    position[j] = weight[i] + (b - a) / 2;
                    leftValue[j] = a;
                    rightValue[j] = b;
                }
            }
            ArrayUtils.sort(order, new IntComparator() {
                public int compare(int first, int second) {
                    return position[first] - position[second];
                }
            });
            ArrayUtils.sort(leftOrder, new IntComparator() {
                public int compare(int first, int second) {
                    return leftValue[second] - leftValue[first];
                }
            });
            ArrayUtils.sort(rightOrder, new IntComparator() {
                public int compare(int first, int second) {
                    return rightValue[second] - rightValue[first];
                }
            });
            int k = 0;
            for (int j : leftOrder) {
                for (; k < count && position[order[k]] <= position[j]; k++)
                    value[order[k]] = leftValue[j] + position[order[k]];
            }
            k = count - 1;
            for (int j : rightOrder) {
                for (; k >= 0 && position[order[k]] >= position[j]; k--)
                    value[order[k]] = Math.max(value[order[k]], rightValue[j] + 2 * weight[i] - position[order[k]]);
            }
            for (int j : order)
                answer = Math.min(answer, value[j]);
            for (int j = 1; j < count; j++)
                answer = Math.min(answer, (value[order[j]] + value[order[j - 1]] + position[order[j - 1]] - position[order[j]]) >> 1);
        }
        out.printLine(answer / 2d);
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

class ArrayUtils {
	private static int[] tempInt = new int[0];

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	public static int[] createOrder(int size) {
		int[] order = new int[size];
		for (int i = 0; i < size; i++)
			order[i] = i;
		return order;
	}

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

	public int compare(int first, int second);
}