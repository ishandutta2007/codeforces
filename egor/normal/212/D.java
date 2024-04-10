import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	private int[] heights;
	private boolean[] present;
	private int[] next;
	private int[] last;
	private int[] queue;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		heights = IOUtils.readIntArray(in, count);
		int[] order = new int[count];
		int[] temp = new int[count];
		for (int i = 0; i < count; i++)
			order[i] = temp[i] = i;
		sort(order, temp, 0, count);
		long[] delta = new long[count + 2];
		present = new boolean[count];
		Arrays.fill(present, true);
		next = new int[count];
		for (int i = 0; i < count; i++)
			next[i] = i + 1;
		last = new int[count];
		for (int i = 0; i < count; i++)
			last[i] = i - 1;
		int[] left = new int[count];
		int[] right = new int[count];
		queue = new int[count];
		for (int i = count - 1; i >= 0; i--) {
			present[order[i]] = false;
			left[order[i]] = get(order[i], last);
			right[order[i]] = get(order[i], next);
		}
		for (int i = 0; i < count; i++) {
			delta[0] += heights[i];
			delta[Math.min(i - left[i], right[i] - i)] -= heights[i];
			delta[Math.max(i - left[i], right[i] - i)] -= heights[i];
			delta[right[i] - left[i]] += heights[i];
		}
		long sum = 0;
		long curDelta = 0;
		long[] answer = new long[count + 1];
		for (int i = 0; i < count; i++) {
			curDelta += delta[i];
			sum += curDelta;
			answer[i + 1] = sum;
		}
		int queryCount = in.readInt();
		for (int i = 0; i < queryCount; i++) {
			int query = in.readInt();
			out.printLine((double)answer[query] / (count - query + 1));
		}
	}

	private int get(int i, int[] next) {
		int size = 0;
		while (!(i < 0 || i >= heights.length || present[i])) {
			queue[size++] = i;
			i = next[i];
		}
		for (int j = 0; j < size; j++)
			next[queue[j]] = i;
		return i;
	}

	private void sort(int[] order, int[] temp, int from, int to) {
		if (to - from <= 1)
			return;
		int middle = (from + to) >> 1;
		sort(temp, order, from, middle);
		sort(temp, order, middle, to);
		int firstIndex = from;
		int secondIndex = middle;
		int index = from;
		while (firstIndex < middle && secondIndex < to) {
			if (heights[temp[firstIndex]] < heights[temp[secondIndex]])
				order[index++] = temp[firstIndex++];
			else
				order[index++] = temp[secondIndex++];
		}
		if (firstIndex != middle)
			System.arraycopy(temp, firstIndex, order, index, to - index);
		if (secondIndex != to)
			System.arraycopy(temp, secondIndex, order, index, to - index);
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