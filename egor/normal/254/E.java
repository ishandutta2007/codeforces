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
import java.io.FileOutputStream;
import java.io.FileInputStream;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int required = in.readInt();
		int[] incoming = IOUtils.readIntArray(in, count);
		int friendCount = in.readInt();
		int[] from = new int[friendCount];
		int[] to = new int[friendCount];
		final int[] food = new int[friendCount];
		IOUtils.readIntArrays(in, from, to, food);
		MiscUtils.decreaseByOne(from, to);
		int[] friendsPerDay = new int[count];
		for (int i = 0; i < friendCount; i++) {
			for (int j = from[i]; j <= to[i]; j++)
				friendsPerDay[j]++;
		}
		int[][] day = new int[count][];
		int[][] friendsByIndex = new int[count][];
		for (int i = 0; i < count; i++) {
			day[i] = new int[friendsPerDay[i]];
			friendsByIndex[i] = new int[friendsPerDay[i]];
		}
		for (int i = 0; i < friendCount; i++) {
			for (int j = from[i]; j <= to[i]; j++) {
				day[j][--friendsPerDay[j]] = food[i];
				friendsByIndex[j][friendsPerDay[j]] = i;
			}
		}
		for (int[] row : day)
			Arrays.sort(row);
		for (int i = 0; i < count; i++) {
			for (int j = 1; j < day[i].length; j++)
				day[i][j] += day[i][j - 1];
		}
		int[] rating = new int[401];
		Arrays.fill(rating, Integer.MIN_VALUE);
		rating[0] = 0;
		int[] next = new int[401];
		int[][] lastFeed = new int[count][401];
		int[][] lastIndex = new int[count][401];
		for (int i = 0; i < count; i++) {
			Arrays.fill(next, Integer.MIN_VALUE);
			for (int j = 0; j <= 400; j++) {
				if (rating[j] == Integer.MIN_VALUE)
					continue;
				int curFood = j + incoming[i] - required;
				int curRating = rating[j];
				if (curFood >= 0) {
					int l = Math.min(curFood, incoming[i]);
					if (next[l] < curRating) {
						next[l] = curRating;
						lastFeed[i][l] = 0;
						lastIndex[i][l] = j;
					}
				}
				for (int k = 0; k < day[i].length; k++) {
					curRating++;
					if (curFood >= day[i][k]) {
						int l = Math.min(curFood - day[i][k], incoming[i]);
						if (next[l] < curRating) {
							next[l] = curRating;
							lastFeed[i][l] = k + 1;
							lastIndex[i][l] = j;
						}
					} else
						break;
				}
			}
			int[] temp = rating;
			rating = next;
			next = temp;
		}
		int current = ArrayUtils.maxPosition(rating);
		out.printLine(rating[current]);
		int[][] answer = new int[count][];
		for (int i = count - 1; i >= 0; i--) {
			ArrayUtils.sort(friendsByIndex[i], new IntComparator() {
				public int compare(int first, int second) {
					return food[first] - food[second];
				}
			});
			answer[i] = Arrays.copyOf(friendsByIndex[i], lastFeed[i][current]);
			for (int j = 0; j < answer[i].length; j++)
				answer[i][j]++;
			current = lastIndex[i][current];
		}
		for (int[] row : answer) {
			out.print(row.length + " ");
			out.printLine(row);
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

	public static int maxPosition(int[] array) {
		return maxPosition(array, 0, array.length);
	}

	public static int maxPosition(int[] array, int from, int to) {
		if (from >= to)
			return -1;
		int max = array[from];
		int result = from;
		for (int i = from + 1; i < to; i++) {
			if (array[i] > max) {
				max = array[i];
				result = i;
			}
		}
		return result;
	}

	}

interface IntComparator {

	public int compare(int first, int second);
}