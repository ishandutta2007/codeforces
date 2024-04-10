import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
	private static final long MOD = (long) (1e9 + 7);
	private int size;
	private int limit;
	private int[] at;
	private int[] length;
	private int[] ends;
	private int[][] edges;
	private long[][][][] result;
	private int[] upTo;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		size = in.readInt();
		limit = in.readInt();
		int[] from = IOUtils.readIntArray(in, in.readInt());
		int[] to = IOUtils.readIntArray(in, in.readInt());
		int[][] samples = new int[count][];
		int[] value = new int[count];
		for (int i = 0; i < count; i++) {
			samples[i] = IOUtils.readIntArray(in, in.readInt());
			value[i] = in.readInt();
		}
		from[from.length - 1]--;
		int totalPositions = 1;
		for (int i = 0; i < count; i++)
			totalPositions += samples[i].length;
		at = new int[totalPositions];
		length = new int[totalPositions];
		ends = new int[totalPositions];
		edges = new int[totalPositions][size];
		int current = 1;
		for (int i = 0; i < count; i++) {
			for (int j = 1; j <= samples[i].length; j++) {
				at[current] = i;
				length[current++] = j;
			}
		}
		for (int i = 0; i < totalPositions; i++) {
			for (int j = 0; j < count; j++) {
				if (length[i] >= samples[j].length) {
					boolean good = true;
					for (int k = 0; k < samples[j].length; k++) {
						if (samples[at[i]][length[i] - samples[j].length + k] != samples[j][k]) {
							good = false;
							break;
						}
					}
					if (good)
						ends[i] += value[j];
				}
			}
			for (int j = 0; j < size; j++) {
				boolean found = false;
				for (int k = 0; k <= length[i] + 1; k++) {
					for (int l = 0; l < totalPositions; l++) {
						if (length[l] + k != length[i] + 1)
							continue;
						boolean good = true;
						for (int m = 0; m < length[l]; m++) {
							int left = m + k == length[i] ? j : samples[at[i]][m + k];
							if (left != samples[at[l]][m]) {
								good = false;
								break;
							}
						}
						if (good) {
							edges[i][j] = l;
							found = true;
							break;
						}
					}
					if (found)
						break;
				}
			}
		}
		result = new long[2][to.length][totalPositions][limit + 1];
		ArrayUtils.fill(result[0], -1);
		upTo = new int[to.length];
		long answer = calculate(to) - calculate(from);
		if (answer < 0)
			answer += MOD;
		out.printLine(answer);
    }

	private long calculate(int[] upTo) {
		for (int i = 0; i < upTo.length; i++)
			this.upTo[upTo.length - i - 1] = upTo[i];
		ArrayUtils.fill(result[1], -1);
		long result = 0;
		for (int i = 1; i < upTo.length; i++) {
			for (int j = 1; j < size; j++)
				result += calculate(0, i - 2, edges[0][j], limit);
		}
		for (int i = 1; i < upTo[0]; i++)
			result += calculate(0, upTo.length - 2, edges[0][i], limit);
		if (upTo[0] != 0)
			result += calculate(1, upTo.length - 2, edges[0][upTo[0]], limit);
		return result % MOD;
	}

	private long calculate(int same, int remaining, int position, int limit) {
		limit -= ends[position];
		if (limit < 0)
			return 0;
		if (remaining < 0)
			return 1;
		if (result[same][remaining][position][limit] != -1)
			return result[same][remaining][position][limit];
		int max = same == 1 ? upTo[remaining] : size;
		long answer = 0;
		for (int i = 0; i < max; i++)
			answer += calculate(0, remaining - 1, edges[position][i], limit);
		if (same == 1 && upTo[remaining] >= 0)
			answer += calculate(1, remaining - 1, edges[position][upTo[remaining]], limit);
		result[same][remaining][position][limit] = answer %= MOD;
		return answer;
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