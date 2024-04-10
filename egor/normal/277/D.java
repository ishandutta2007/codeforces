import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.AbstractSet;
import java.util.Iterator;
import java.util.Set;
import java.util.AbstractMap;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		final int time = in.readInt();
		int[] scoreSmall = new int[count];
		int[] scoreLarge = new int[count];
		int[] timeSmall = new int[count];
		final int[] timeLarge = new int[count];
		final double[] fail = new double[count];
		for (int i = 0; i < count; i++) {
			scoreSmall[i] = in.readInt();
			scoreLarge[i] = in.readInt();
			timeSmall[i] = in.readInt();
			timeLarge[i] = in.readInt();
			fail[i] = in.readDouble();
		}
		int[] order = ArrayUtils.createOrder(count);
		ArrayUtils.sort(order, new IntComparator() {
			public int compare(int first, int second) {
				return Double.compare(fail[first] * timeLarge[first] + fail[first] * fail[second] * timeLarge[second], fail[second] * timeLarge[second] + fail[first] * fail[second] * timeLarge[first]);
			}
		});
		long[] bestScore = new long[time + 1];
		double[] bestTime = new double[time + 1];
		for (int i : order) {
			long realScoreSmall = scoreSmall[i] * 1000000L;
			long realScoreLarge = Math.round(scoreLarge[i] * 1000000L * (1 - fail[i]));
			for (int j = time; j >= 0; j--) {
				if (j + timeSmall[i] <= time) {
					int next = j + timeSmall[i];
					long score = bestScore[j] + realScoreSmall;
					if (score > bestScore[next]) {
						bestScore[next] = score;
						bestTime[next] = bestTime[j];
					} else if (score == bestScore[next])
						bestTime[next] = Math.max(bestTime[next], bestTime[j]);
				}
				if (j + timeSmall[i] + timeLarge[i] <= time) {
					int next = j + timeSmall[i] + timeLarge[i];
					long score = bestScore[j] + realScoreSmall + realScoreLarge;
					if (score > bestScore[next]) {
						bestScore[next] = score;
						bestTime[next] = fail[i] * (timeLarge[i] + bestTime[j]);
					} else if (score == bestScore[next])
						bestTime[next] = Math.max(bestTime[next], fail[i] * (timeLarge[i] + bestTime[j]));
				}
			}
		}
		long answerScore = -1;
		double answerTime = 0;
		for (int i = 0; i <= time; i++) {
			if (bestScore[i] > answerScore) {
				answerScore = bestScore[i];
				answerTime = i - bestTime[i];
			} else if (bestScore[i] == answerScore)
				answerTime = Math.min(answerTime, i - bestTime[i]);
		}
		out.printFormat("%.15f %.15f\n", answerScore / 1e6, answerTime);
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

	public double readDouble() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!isSpaceChar(c) && c != '.') {
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, readInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		if (c == '.') {
			c = read();
			double m = 1;
			while (!isSpaceChar(c)) {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = read();
			}
		}
		return res * sgn;
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

	public void printFormat(String format, Object...objects) {
		writer.printf(format, objects);
	}

	public void close() {
		writer.close();
	}

	}

class ArrayUtils {
	private static int[] tempInt = new int[0];

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