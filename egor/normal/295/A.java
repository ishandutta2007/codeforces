import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.util.Collections;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int queryTypeCount = in.readInt();
		int queryCount = in.readInt();
		long[] array = IOUtils.readLongArray(in, count);
		int[] from = new int[queryTypeCount];
		int[] to = new int[queryTypeCount];
		int[] delta = new int[queryTypeCount];
		IOUtils.readIntArrays(in, from, to, delta);
		MiscUtils.decreaseByOne(from, to);
		SumIntervalTree queryTree = new SumIntervalTree(queryTypeCount);
		for (int i = 0; i < queryCount; i++) {
			int currentFrom = in.readInt() - 1;
			int currentTo = in.readInt() - 1;
			queryTree.update(currentFrom, currentTo, 1);
		}
		SumIntervalTree result = new SumIntervalTree(count);
		for (int i = 0; i < queryTypeCount; i++)
			result.update(from[i], to[i], delta[i] * queryTree.query(i, i));
		for (int i = 0; i < count; i++)
			array[i] += result.query(i, i);
		out.printLine(array);
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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
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

	public void print(long[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void printLine(long[] array) {
        print(array);
        writer.println();
    }

    public void close() {
		writer.close();
	}

	}

class IOUtils {

	public static long[] readLongArray(InputReader in, int size) {
		long[] array = new long[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readLong();
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

class SumIntervalTree extends LongIntervalTree {
    public SumIntervalTree(int size) {
        super(size);
    }

    protected long joinValue(long left, long right) {
        return left + right;
    }

    protected long joinDelta(long was, long delta) {
        return was + delta;
    }

    protected long accumulate(long value, long delta, int length) {
        return value + delta * length;
    }

    protected long neutralValue() {
        return 0;
    }

    protected long neutralDelta() {
        return 0;
    }
}

abstract class LongIntervalTree {
    protected int size;
    protected long[] value;
    protected long[] delta;

    protected LongIntervalTree(int size) {
        this.size = size;
        int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
        value = new long[nodeCount];
        delta = new long[nodeCount];
    }

    protected abstract long joinValue(long left, long right);
    protected abstract long joinDelta(long was, long delta);
    protected abstract long accumulate(long value, long delta, int length);
    protected abstract long neutralValue();
    protected abstract long neutralDelta();

    public void update(int from, int to, long delta) {
        update(0, 0, size - 1, from, to, delta);
    }

    private void update(int root, int left, int right, int from, int to, long delta) {
        if (left > to || right < from)
            return;
        if (left >= from && right <= to) {
            this.delta[root] = joinDelta(this.delta[root], delta);
            value[root] = accumulate(value[root], delta, right - left + 1);
            return;
        }
        this.delta[2 * root + 1] = joinDelta(this.delta[2 * root + 1], this.delta[root]);
        this.delta[2 * root + 2] = joinDelta(this.delta[2 * root + 2], this.delta[root]);
        int middle = (left + right) >> 1;
        value[2 * root + 1] = accumulate(value[2 * root + 1], this.delta[root], middle - left + 1);
        value[2 * root + 2] = accumulate(value[2 * root + 2], this.delta[root], right - middle);
        this.delta[root] = neutralDelta();
        update(2 * root + 1, left, middle, from, to, delta);
        update(2 * root + 2, middle + 1, right, from, to, delta);
        value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
    }

    public long query(int from, int to) {
        return query(0, 0, size - 1, from, to);
    }

    private long query(int root, int left, int right, int from, int to) {
        if (left > to || right < from)
            return neutralValue();
        if (left >= from && right <= to)
            return value[root];
        delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
        delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
        int middle = (left + right) >> 1;
        value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root], middle - left + 1);
        value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root], right - middle);
        this.delta[root] = neutralDelta();
        return joinValue(query(2 * root + 1, left, middle, from, to), query(2 * root + 2, middle + 1, right, from, to));
    }
}