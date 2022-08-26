import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int queryCount = in.readInt();
		int[] a = IOUtils.readIntArray(in, count);
		int[] b = IOUtils.readIntArray(in, count);
		LongIntervalTree tree = new LongIntervalTree(count) {
			@Override
			protected long joinValue(long left, long right) {
				if (left == neutralValue())
					return right;
				return left;
			}

			@Override
			protected long joinDelta(long was, long delta) {
				if (delta == -1)
					return was;
				return delta;
			}

			@Override
			protected long accumulate(long value, long delta, int length) {
				if (delta == -1)
					return value;
				return delta;
			}

			@Override
			protected long neutralValue() {
				return -1;
			}

			@Override
			protected long neutralDelta() {
				return -1;
			}
		};
		tree.init();
		long mask = (1L << 32) - 1;
		for (int i = 0; i < queryCount; i++) {
			int type = in.readInt();
			if (type == 1) {
				long aPosition = in.readInt() - 1;
				int bPosition = in.readInt() - 1;
				int length = in.readInt();
				tree.update(bPosition, bPosition + length - 1, (aPosition << 32) + bPosition);
			} else {
				int index = in.readInt() - 1;
				long value = tree.query(index, index);
				if (value == -1)
					out.printLine(b[index]);
				else
					out.printLine(a[((int) (index - (value & mask) + (value >> 32)))]);
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

    protected long initValue(int index) {
        return neutralValue();
    }

    public void init() {
        init(0, 0, size - 1);
    }

    private void init(int root, int left, int right) {
        if (left == right) {
            value[root] = initValue(left);
            delta[root] = neutralDelta();
        } else {
            int middle = (left + right) >> 1;
            init(2 * root + 1, left, middle);
            init(2 * root + 2, middle + 1, right);
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
            delta[root] = neutralDelta();
        }
    }

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