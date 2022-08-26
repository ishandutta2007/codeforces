import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.util.Iterator;
import java.io.*;
import java.util.Comparator;
import java.util.Arrays;
import java.util.Collection;

/**
 * Generated by Contest helper plug-in
 * Actual solution is at the bottom
 */
public class Main {
	public static void main(String[] args) {
		InputReader in = new StreamInputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		run(in, out);
	}

	public static void run(InputReader in, PrintWriter out) {
		Solver solver = new TaskD();
		solver.solve(1, in, out);
		Exit.exit(in, out);
	}
}

abstract class InputReader {
	private boolean finished = false;

	public abstract int read();

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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public void setFinished(boolean finished) {
		this.finished = finished;
	}

	public abstract void close();
}

class StreamInputReader extends InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar, numChars;

	public StreamInputReader(InputStream stream) {
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

	@Override
	public void close() {
		try {
			stream.close();
		} catch (IOException ignored) {
		}
	}
}

class Exit {
	private Exit() {
	}

	public static void exit(InputReader in, PrintWriter out) {
		in.setFinished(true);
		in.close();
		out.close();
	}
}

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
}

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	}

class Pair<U, V> {

	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

	}

	@Override
	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	@Override
	public String toString() {
		return "(" + first + "," + second + ")";
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

class TaskD implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int queueSize = in.readInt();
		int[] time = IOUtils.readIntArray(in, queueSize);
		int[][] result = new int[queueSize + 1][queueSize];
		int[][] last = new int[queueSize + 1][queueSize];
		int[][] first = new int[queueSize + 1][queueSize];
		int[][] second = new int[queueSize + 1][queueSize];
		ArrayUtils.fill(result, Integer.MAX_VALUE);
		result[1][0] = 0;
		int answer = Integer.MAX_VALUE;
		int lastIndex = -1;
		for (int i = 1; i < queueSize; i += 2) {
			for (int j = 0; j < i; j++) {
				if (i == queueSize - 1) {
					if (answer > result[i][j] + Math.max(time[j], time[i])) {
						answer = result[i][j] + Math.max(time[j], time[i]);
						lastIndex = j;
					}
				} else {
					if (result[i + 2][j] > result[i][j] + Math.max(time[i], time[i + 1])) {
						result[i + 2][j] = result[i][j] + Math.max(time[i], time[i + 1]);
						last[i + 2][j] = j;
						first[i + 2][j] = i;
						second[i + 2][j] = i + 1;
					}
					if (result[i + 2][i] > result[i][j] + Math.max(time[j], time[i + 1])) {
						result[i + 2][i] = result[i][j] + Math.max(time[j], time[i + 1]);
						last[i + 2][i] = j;
						first[i + 2][i] = j;
						second[i + 2][i] = i + 1;
					}
					if (result[i + 2][i + 1] > result[i][j] + Math.max(time[j], time[i])) {
						result[i + 2][i + 1] = result[i][j] + Math.max(time[j], time[i]);
						last[i + 2][i + 1] = j;
						first[i + 2][i + 1] = j;
						second[i + 2][i + 1] = i;
					}
				}
			}
		}
		if (queueSize % 2 == 1) {
			for (int i = 0; i < queueSize; i++) {
				if (answer > result[queueSize][i] + time[i]) {
					answer = result[queueSize][i] + time[i];
					lastIndex = i;
				}
			}
		}
		out.println(answer);
		List<Pair<Integer, Integer>> path = new ArrayList<Pair<Integer, Integer>>();
		int index = queueSize - (1 - queueSize % 2);
		int originalLast = lastIndex;
		if (queueSize % 2 == 0)
			path.add(Pair.makePair(lastIndex + 1, queueSize));
		while (index != 1) {
			path.add(Pair.makePair(first[index][lastIndex] + 1, second[index][lastIndex] + 1));
			lastIndex = last[index][lastIndex];
			index -= 2;
		}
		Collections.reverse(path);
		for (Pair<Integer, Integer> element : path)
			out.println(element.first + " " + element.second);
		if (queueSize % 2 == 1)
			out.println(originalLast + 1);
	}
}