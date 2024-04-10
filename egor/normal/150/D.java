import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
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
	private int[] cost;
	private char[] s;
	private int[][] mustTake;
	private int[][] allPalin;
	private int[][][] palin;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int length = in.readInt();
		cost = IOUtils.readIntArray(in, length);
		s = IOUtils.readCharArray(in, length);
		mustTake = new int[length][length];
		allPalin = new int[length][length];
		palin = new int[length][length][length];
		ArrayUtils.fill(mustTake, -2);
		ArrayUtils.fill(allPalin, -2);
		ArrayUtils.fill(palin, -2);
		int[] answer = new int[length + 1];
		for (int i = 0; i < length; i++) {
			answer[i + 1] = answer[i];
			for (int j = 0; j <= i; j++) {
				int value = getMustTake(j, i);
				if (value != -1)
					answer[i + 1] = Math.max(answer[i + 1], answer[j] + value);
			}
		}
		out.printLine(answer[length]);
	}

	private int getMustTake(int from, int to) {
		if (from > to)
			return 0;
		if (mustTake[from][to] != -2)
			return mustTake[from][to];
		mustTake[from][to] = -1;
		for (int i = from; i <= to; i++) {
			if (s[from] == s[i]) {
				int palinValue = getAllPalin(from, i);
				int remainingValue = getMustTake(i + 1, to);
				if (palinValue != -1 && remainingValue != -1)
					mustTake[from][to] = Math.max(mustTake[from][to], palinValue + remainingValue);
			}
		}
		return mustTake[from][to];
	}

	private int getAllPalin(int from, int to) {
		if (allPalin[from][to] != -2)
			return allPalin[from][to];
		allPalin[from][to] = -1;
		for (int i = 0; i <= to - from; i++) {
			if (cost[i] == -1)
				continue;
			int value = getPalin(from, to, i);
			if (value != -1)
				allPalin[from][to] = Math.max(allPalin[from][to], value + cost[i]);
		}
		return allPalin[from][to];
	}

	private int getPalin(int from, int to, int length) {
		if (length == -2)
			return -1;
		if (from == to && length == 0 || from > to && length == -1)
			return 0;
		if (length == -1)
			return getMustTake(from, to);
		if (length > to - from)
			return -1;
		if (palin[from][to][length] != -2)
			return palin[from][to][length];
		palin[from][to][length] = -1;
		if (s[from] == s[to])
			palin[from][to][length] = Math.max(palin[from][to][length], getPalin(from + 1, to - 1, length - 2));
		for (int i = from; i < to; i++) {
			if (s[i] == s[from]) {
				int segmentValue = getAllPalin(from, i);
				int remainingValue = getPalin(i + 1, to, length);
				if (segmentValue != -1 && remainingValue != -1)
					palin[from][to][length] = Math.max(palin[from][to][length], segmentValue + remainingValue);
			}
		}
		for (int i = to; i > from; i--) {
			if (s[i] == s[to]) {
				int segmentValue = getAllPalin(i, to);
				int remainingValue = getPalin(from, i - 1, length);
				if (segmentValue != -1 && remainingValue != -1)
					palin[from][to][length] = Math.max(palin[from][to][length], segmentValue + remainingValue);
			}
		}
		return palin[from][to][length];
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

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
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

	public static char[] readCharArray(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	}

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	public static void fill(int[][][] array, int value) {
		for (int[][] subArray : array)
			fill(subArray, value);
	}

	}