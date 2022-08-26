import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int queryCount = in.readInt();
		int n = 1000000;
		int[] direct = new int[n];
		for (int i = 1; i < n; i++) {
			direct[i] = direct[i - 1] + 1;
			if ((i & (i - 1)) == 0)
				direct[i]++;
		}
		int[][] reverse = new int[20][n];
		int current = 1;
		for (int i = 1; i < n; i++) {
			while (current <= direct[i] && current < n)
				reverse[0][current++] = i;
		}
		for (int i = 1; i < 20; i++) {
			for (int j = 0; j < n; j++)
				reverse[i][j] = reverse[i - 1][reverse[i - 1][j]];
		}
		int[] level = new int[queryCount];
		int[] left = new int[queryCount];
		int[] right = new int[queryCount];
		int[] value = new int[queryCount];
		boolean[] segment = new boolean[queryCount];
		for (int i = 0; i < queryCount; i++) {
			int type = in.readInt();
			if (type == 1) {
				level[i] = in.readInt();
				left[i] = in.readInt();
				right[i] = in.readInt();
				value[i] = in.readInt();
				segment[i] = true;
			} else {
				int cLevel = in.readInt();
				int position = in.readInt();
				IntSet set = new IntHashSet();
				for (int j = 0; j < i; j++) {
					if (segment[j] && level[j] >= cLevel) {
						int delta = level[j] - cLevel;
						int cLeft = left[j];
						int cRight = right[j];
						for (int k = 19; k >= 0; k--) {
							if (delta >= (1 << k)) {
								delta -= 1 << k;
								cLeft = reverse[k][cLeft];
								cRight = reverse[k][cRight];
							}
						}
						if (position >= cLeft && position <= cRight)
							set.add(value[j]);
					}
				}
				out.printLine(set.size());
			}
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

	public void close() {
		writer.close();
	}

	public void printLine(int i) {
		writer.println(i);
	}
}

abstract class IntSet extends IntCollection {
	}

class IntHashSet extends IntSet {
	private static final Random RND = new Random();
	private static final int[] SHIFTS = new int[4];
	private static final byte PRESENT_MASK = 1;

	static {
		for (int i = 0; i < 4; i++)
			SHIFTS[i] = RND.nextInt(31) + 1;
	}

	private int size;
	private int[] values;
	private byte[] present;
	private int step;
	private int ratio;

	public IntHashSet() {
		this(3);
	}


	public IntHashSet(int capacity) {
		capacity = Math.max(capacity, 1);
		values = new int[capacity];
		present = new byte[capacity];
		ratio = 2;
		initStep(capacity);
	}

	private void initStep(int capacity) {
		step = RND.nextInt(capacity - 2) + 1;
		while (IntegerUtils.gcd(step, capacity) != 1)
			step++;
	}

	public int size() {
		return size;
	}

	public void add(int value) {
		ensureCapacity((size + 1) * ratio);
		int current = getHash(value);
		while ((present[current] & PRESENT_MASK) != 0) {
			if (values[current] == value)
				return;
			current += step;
			if (current >= values.length)
				current -= values.length;
		}
		present[current] = PRESENT_MASK;
		values[current] = value;
		size++;
	}

	private int getHash(int value) {
		int result = value;
		for (int i : SHIFTS)
			result ^= value >> i;
		result %= values.length;
		if (result < 0)
			result += values.length;
		return result;
	}

	private void ensureCapacity(int capacity) {
		if (values.length < capacity) {
			capacity = Math.max(capacity * 2, values.length);
			rebuild(capacity);
		}
	}

	private void rebuild(int capacity) {
		initStep(capacity);
		int[] oldValues = values;
		byte[] oldPresent = present;
		values = new int[capacity];
		present = new byte[capacity];
		size = 0;
		for (int i = 0; i < oldValues.length; i++) {
			if ((oldPresent[i] & PRESENT_MASK) == PRESENT_MASK)
				add(oldValues[i]);
		}
	}

	}

abstract class IntCollection {
	public abstract int size();
	public abstract void add(int value);

	}

class IntegerUtils {

    public static int gcd(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    }