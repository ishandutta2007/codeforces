import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
	private static final int MOD = (int) (1e9 + 7);
	long[] factorial = IntegerUtils.generateFactorial((int) 2e5, MOD);
	long[] reverse = IntegerUtils.generateReverseFactorials((int) 2e5, MOD);

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int queryCount = in.readInt();
		int[] base = IOUtils.readIntArray(in, count);
		int[] from = new int[queryCount];
		int[] to = new int[queryCount];
		int[] depth = new int[queryCount];
		IOUtils.readIntArrays(in, from, to, depth);
		MiscUtils.decreaseByOne(from);
		int[] diff = new int[count + 1];
		int[] nDiff = new int[count + 1];
//		int[] delta = new int[count + 1];
		int[] first = new int[101];
		int[] next = new int[queryCount];
		Arrays.fill(first, -1);
		for (int i = 0; i < queryCount; i++) {
			next[i] = first[depth[i]];
			first[depth[i]] = i;
		}
//		int atEnd
		for (int i = 100; i >= 0; i--) {
//			Arrays.fill(delta, 0);
			for (int j = first[i]; j != -1; j = next[j]) {
				diff[from[j]]++;
//				diff[to[j]] -= c(to[j] - from[j] + i, i);
//				if (diff[to[j]] < 0)
//					diff[to[j]] += MOD;
			}
			for (int j = i; j <= 100; j++) {
				for (int k = first[j]; k != -1; k = next[k]) {
					diff[to[k]] -= c(to[k] - from[k] - 1 + j - i, j - i);
					if (diff[to[k]] < 0)
						diff[to[k]] += MOD;
				}
			}
			nDiff[0] = diff[0];
			for (int j = 1; j < count; j++) {
				nDiff[j] = nDiff[j - 1] + diff[j];
				if (nDiff[j] >= MOD)
					nDiff[j] -= MOD;
			}
			int[] temp = diff;
			diff = nDiff;
			nDiff = temp;
		}
		for (int i = 0; i < count; i++) {
			base[i] += diff[i];
			if (base[i] >= MOD)
				base[i] -= MOD;
		}
		out.printLine(base);
    }

	private long c(int a, int b) {
		return factorial[a] * reverse[b] % MOD * reverse[a - b] % MOD;
	}
}

class IntegerUtils {

    public static long[] generateFactorial(int count, long module) {
		long[] result = new long[count];
		if (module == -1) {
			if (count != 0)
				result[0] = 1;
			for (int i = 1; i < count; i++)
				result[i] = result[i - 1] * i;
		} else {
			if (count != 0)
				result[0] = 1 % module;
			for (int i = 1; i < count; i++)
				result[i] = (result[i - 1] * i) % module;
		}
		return result;
	}

	public static long[] generateReverse(int upTo, long module) {
		long[] result = new long[upTo];
		if (upTo > 1)
			result[1] = 1;
		for (int i = 2; i < upTo; i++)
			result[i] = (module - module / i * result[((int) (module % i))] % module) % module;
		return result;
	}

	public static long[] generateReverseFactorials(int upTo, long module) {
		long[] result = generateReverse(upTo, module);
		if (upTo > 0)
			result[0] = 1;
		for (int i = 1; i < upTo; i++)
			result[i] = result[i] * result[i - 1] % module;
		return result;
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