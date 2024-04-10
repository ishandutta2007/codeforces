import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.Comparator;

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
		TaskE1 solver = new TaskE1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE1 {
	int[] array;
	long[][][] answerStarted;
	long[][][] answerNotStarted;
	int count;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		count = in.readInt();
		int partCount = in.readInt();
		array = IOUtils.readIntArray(in, count);
		answerStarted = new long[5][partCount + 1][count + 1];
		answerNotStarted = new long[5][partCount + 1][count + 1];
		ArrayUtils.fill(answerStarted, Long.MIN_VALUE);
		ArrayUtils.fill(answerNotStarted, Long.MIN_VALUE);
		out.printLine(Math.max(goNotStarted(-1, partCount, 0), goNotStarted(1, partCount, 0)));
    }

	private long goNotStarted(int type, int remainingParts, int at) {
		if (answerNotStarted[type + 2][remainingParts][at] != Long.MIN_VALUE) {
			return answerNotStarted[type + 2][remainingParts][at];
		}
		if (remainingParts == 0) {
			return answerNotStarted[type + 2][remainingParts][at] = 0;
		}
		if (at == count) {
			return answerNotStarted[type + 2][remainingParts][at] = Long.MIN_VALUE / 2;
		}
		long result = getStarted(type, remainingParts, at + 1) + type * array[at];
		result = Math.max(result, goNotStarted(type, remainingParts, at + 1));
		if (Math.abs(type) != 1) {
			result = Math.max(result, goNotStarted(convertType(type, remainingParts - 1), remainingParts - 1, at + 1));
		}
		return answerNotStarted[type + 2][remainingParts][at] = result;
	}

	private long getStarted(int type, int remainingParts, int at) {
		if (answerStarted[type + 2][remainingParts][at] != Long.MIN_VALUE) {
			return answerStarted[type + 2][remainingParts][at];
		}
		long result = goNotStarted(convertType(-type, remainingParts - 1), remainingParts - 1, at);
		if (at != count) {
			result = Math.max(result, getStarted(type, remainingParts, at + 1) + type * array[at]);
		}
		return answerStarted[type + 2][remainingParts][at] = result;
	}

	private int convertType(int type, int partsRemaining) {
		type /= Math.abs(type);
		if (partsRemaining == 1)  {
			return type;
		} else {
			return 2 * type;
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

	public void close() {
		writer.close();
	}

	public void printLine(long i) {
		writer.println(i);
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

class ArrayUtils {

	public static void fill(long[][] array, long value) {
		for (long[] row : array)
			Arrays.fill(row, value);
	}

	public static void fill(long[][][] array, long value) {
		for (long[][] row : array)
			fill(row, value);
	}

}