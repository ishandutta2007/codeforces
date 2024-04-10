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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int length = in.readInt();
		int count = in.readInt();
		long speed = in.readInt();
		int[] at = new int[count];
		int[] base = new int[count];
		int[] time = new int[count];
		IOUtils.readIntArrays(in, at, base, time);
		MiscUtils.decreaseByOne(at, time);
		long[] answer = new long[length];
		long[] nextAnswer = new long[length];
		int[] order = new int[length];
		int last = 0;
		for (int i = 0; i < count; i++) {
			int delta = (int) Math.min(speed * (time[i] - last), length);
			int head = 0;
			int size = 0;
			for (int j = 0; j < delta; j++) {
				order[size++] = j;
				while (size > 1 && answer[order[size - 1]] <= answer[order[size - 2]]) {
					order[size - 2] = order[size - 1];
					size--;
				}
			}
			for (int j = 0; j < length; j++) {
				if (j + delta < length) {
					order[size++] = j + delta;
					while (size > 1 && answer[order[size - 1]] <= answer[order[size - 2]]) {
						order[size - 2] = order[size - 1];
						size--;
					}
				}
				if (j - order[head] > delta)
					head++;
				nextAnswer[j] = answer[order[head]] + Math.abs(j - at[i]);
			}
			long[] temp = answer;
			answer = nextAnswer;
			nextAnswer = temp;
			last = time[i];
		}
		out.printLine(ArrayUtils.sumArray(base) - ArrayUtils.minElement(answer));
/*
		long[] answer = new long[2 * count];
		long[] position = new long[2 * count];
		long[] nextAnswer = new long[2 * count];
		long[] nextPosition = new long[2 * count];
		for (int i = 0; i < count; i++) {
			position[2 * i] = normalize(at[i] - time[i] * speed, length);
			position[2 * i + 1] = normalize(at[i] + time[i] * speed, length);
		}
		int[] order = ArrayUtils.order(position);
		ArrayUtils.order(order, position);
		int last = 0;
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				nextPosition[2 * j] = normalize(at[j] - (time[i] - time[j]) * speed, length);
				nextPosition[2 * j + 1] = normalize(at[j] + (time[i] - time[j]) * speed, length);
			}
			final long[] finalNextPosition = nextPosition;
			ArrayUtils.sort(order, new IntComparator() {
				public int compare(int first, int second) {
					return Long.compare(finalNextPosition[first], finalNextPosition[second]);
				}
			});
			ArrayUtils.order(order, nextPosition);
			final long[] finalAnswer = answer;
			Heap heap = new Heap(new IntComparator() {
				public int compare(int first, int second) {
					return Long.compare(finalAnswer[first], finalAnswer[second]);
				}
			}, 2 * count);
			int k = 0;
			for (int j = 0; j < 2 * count; j++) {
				while (k < 2 * count && position[k] - nextPosition[j] <= speed * (time[i] - last))
					heap.add(k++);
				int result;
				while (true) {
					result = heap.peek();
					if (nextPosition[j] - position[result] > speed * (time[i] - last))
						heap.poll();
					else
						break;
				}
				nextAnswer[j] = answer[result] + Math.abs(at[i] - nextPosition[j]);
			}
			long[] temp = answer;
			answer = nextAnswer;
			nextAnswer = temp;
			temp = position;
			position = nextPosition;
			nextPosition = temp;
			last = time[i];
		}
		out.printLine(ArrayUtils.sumArray(base) - ArrayUtils.minElement(answer));*/
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

	public void close() {
		writer.close();
	}

	public void printLine(long i) {
		writer.println(i);
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

	public static long sumArray(int[] array) {
		long result = 0;
		for (int element : array)
			result += element;
		return result;
	}

	public static long minElement(long[] array) {
		return array[minPosition(array)];
	}

	public static int minPosition(long[] array) {
		return minPosition(array, 0, array.length);
	}

	public static int minPosition(long[] array, int from, int to) {
		if (from >= to)
			return -1;
		long min = array[from];
		int result = from;
		for (int i = from + 1; i < to; i++) {
			if (array[i] < min) {
				min = array[i];
				result = i;
			}
		}
		return result;
	}
}