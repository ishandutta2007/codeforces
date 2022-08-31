import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.Comparator;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int testCount = in.readInt();
		int count = in.readInt();
		int max = in.readInt();
		int repeats = in.readInt();
		final int[] numbers = new int[count];
		int[] copy = new int[count];
		int[] place = new int[max];
		int[] qty = new int[Math.min(max, count)];
		int[] from = new int[Math.min(max, count)];
		int[] to = new int[Math.min(max, count)];
		int[] order = new int[count];
		for (int i = 0; i < count; i++)
			order[i] = i;
		int[] answer = new int[Math.min(max, count)];
		int[] shift = new int[Math.min(max, count)];
		for (int i = 0; i < testCount; i++) {
			for (int j = 0; j < count; j++)
				numbers[j] = in.readInt() - 1;
			System.arraycopy(numbers, 0, copy, 0, count);
			ArrayUtils.sort(copy, IntComparator.DEFAULT);
			int k = 1;
			for (int j = 1; j < count; j++) {
				if (copy[j] != copy[j - 1])
					copy[k++] = copy[j];
			}
			for (int j = 0; j < k; j++)
				place[copy[j]] = j;
			Arrays.fill(qty, 0);
			for (int j = 0; j < count; j++)
				qty[place[numbers[j]]]++;
			int current = 0;
			for (int j = 0; j < k; j++) {
				from[j] = current;
				current += qty[j];
				to[j] = current;
			}
			ArrayUtils.sort(order, new IntComparator() {
				public int compare(int first, int second) {
					if (numbers[first] != numbers[second])
						return numbers[first] - numbers[second];
					return first - second;
				}
			});
			answer[0] = order[0];
			shift[0] = 0;
			for (int j = 1; j < k; j++) {
				shift[j] = Integer.MAX_VALUE;
				for (int l = j - 1; l >= 0; l--) {
					int candidateAnswer = -Arrays.binarySearch(order, from[j], to[j], answer[l]) - 1;
					int candidateShift = shift[l];
					if (candidateAnswer == to[j]) {
						candidateAnswer = from[j];
						candidateShift++;
					}
					candidateAnswer = order[candidateAnswer];
					if (shift[l + 1] > candidateShift || shift[l + 1] == candidateShift && answer[l + 1] > candidateAnswer) {
						answer[l + 1] = candidateAnswer;
						shift[l + 1] = candidateShift;
					}
				}
				answer[0] = Math.min(answer[0], order[from[j]]);
			}
			int result = -1;
			for (int j = 0; j < k; j++) {
				if (shift[j] < repeats)
					result = j + 1;
			}
			out.printLine(result);
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