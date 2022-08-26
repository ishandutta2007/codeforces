import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.List;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int studentCount = in.readInt();
		int capacity = in.readInt();
		int[] time = new int[studentCount];
		final int[] destination = new int[studentCount];
		IOUtils.readIntArrays(in, time, destination);
		long curTime = 0;
		long[] answer = new long[studentCount];
		for (int i = 0; i < studentCount; i += capacity) {
			int curCapacity = Math.min(capacity, studentCount - i);
			Integer[] order = new Integer[curCapacity];
			for (int j = 0; j < curCapacity; j++)
				order[j] = i + j;
			curTime = Math.max(curTime, time[i + curCapacity - 1]);
			Arrays.sort(order, new Comparator<Integer>() {
				public int compare(Integer o1, Integer o2) {
					return destination[o1] - destination[o2];
				}
			});
			int lastPosition = 0;
			int atCurStop = 0;
			long stopTime = -1;
			for (int j : order) {
				if (destination[j] != lastPosition) {
					curTime += destination[j] - lastPosition;
					stopTime = curTime;
					lastPosition = destination[j];
					atCurStop = 0;
				}
				answer[j] = stopTime;
				if (atCurStop == 0)
					curTime++;
				if (atCurStop % 2 == 1)
					curTime++;
				atCurStop++;
			}
			curTime += lastPosition;
		}
		out.printLine(Array.wrap(answer).toArray());
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

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	}

abstract class Array<T> extends AbstractList<T> {

	public static List<Long> wrap(long...array) {
		return new LongArray(array);
	}

	protected static class LongArray extends Array<Long> {
		protected final long[] array;

		protected LongArray(long[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Long get(int index) {
			return array[index];
		}

		public Long set(int index, Long value) {
			long result = array[index];
			array[index] = value;
			return result;
		}
	}

	}