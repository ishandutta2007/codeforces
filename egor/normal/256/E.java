import java.util.NavigableSet;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.Set;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.TreeSet;
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
	private static final long MOD = 777777777;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int queryCount = in.readInt();
		boolean[][] isLucky = new boolean[4][4];
		for (int i = 1; i < 4; i++) {
			for (int j = 1; j < 4; j++)
				isLucky[i][j] = in.readInt() == 1;
		}
		long[][][] variants = new long[4][4][count + 1];
		for (int i = 1; i < 4; i++) {
			variants[i][i][1] = 1;
			variants[0][i][1] = 1;
			variants[i][0][1] = 1;
		}
		variants[0][0][1] = 3;
		for (int i = 2; i <= count; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 1; k < 4; k++) {
					for (int l = 1; l < 4; l++) {
						if (isLucky[k][l]) {
							variants[j][l][i] += variants[j][k][i - 1];
							variants[j][0][i] += variants[j][k][i - 1];
						}
					}
				}
				for (int k = 0; k < 4; k++)
					variants[j][k][i] %= MOD;
			}
		}
		NavigableSet<Integer> set = new TreeSet<Integer>();
		int[] state = new int[count];
		LongIntervalTree tree = new LongIntervalTree(count + 1) {
			@Override
			protected long joinValue(long left, long right) {
				return left * right % MOD;
			}

			@Override
			protected long joinDelta(long was, long delta) {
				if (was == -1)
					return delta;
				if (delta == -1)
					return was;
				return was * delta % MOD;
			}

			@Override
			protected long accumulate(long value, long delta, int length) {
				if (delta == -1)
					return value;
				return delta;
			}

			@Override
			protected long neutralValue() {
				return 1;
			}

			@Override
			protected long neutralDelta() {
				return -1;
			}
		};
		tree.init();
		set.add(-1);
		set.add(count);
		tree.update(0, 0, variants[0][0][count]);
		tree.query(0, 0);
		for (int i = 0; i < queryCount; i++) {
			int index = in.readInt() - 1;
			int value = in.readInt();
			if (value != 0) {
				int left = set.lower(index);
				int leftState = left == -1 ? 0 : state[left];
				int leftLength = left == -1 ? index + 1 : index - left + 1;
				int right = set.higher(index);
				int rightState = right == count ? 0 : state[right];
				int rightLength = right == count ? right - index : right - index + 1;
				tree.update(left + 1, left + 1, variants[leftState][value][leftLength]);
				tree.update(index + 1, index + 1, variants[value][rightState][rightLength]);
			} else if (state[index] != 0) {
				tree.update(index + 1, index + 1, 1);
				int left = set.lower(index);
				int leftState = left == -1 ? 0 : state[left];
				int right = set.higher(index);
				int rightState = right == count ? 0 : state[right];
				int length = right - left + 1;
				if (left == -1)
					length--;
				if (right == count)
					length--;
				tree.update(left + 1, left + 1, variants[leftState][rightState][length]);
			}
			state[index] = value;
			if (value == 0)
				set.remove(index);
			else
				set.add(index);
			out.printLine(tree.query(0, count));
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