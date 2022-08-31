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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	private static final long MOD = (long) 1e9 + 7;
	SuffixAutomaton automaton;
	private long[][] ways;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		String s1 = in.readString();
		String s2 = in.readString();
		String s3 = in.readString();
		String all = s1 + "0" + s2 + "1" + s3 + "2";
		automaton = new SuffixAutomaton(all);
		ways = new long[3][automaton.size];
		ArrayUtils.fill(ways, -1);
		int size = Math.min(s1.length(), Math.min(s2.length(), s3.length()));
		IntervalTree tree = new SumIntervalTree(size + 1);
		for (int i = 1; i < automaton.size; i++) {
			calculate(i);
			tree.update(automaton.length[automaton.link[i]] + 1, automaton.length[i], ways[0][i] * ways[1][i] * ways[2][i]);
		}
		long[] answer = new long[size];
		for (int i = 0; i < size; i++) {
			answer[i] = tree.query(i + 1, i + 1) % MOD;
		}
		out.printLine(answer);
	}

	private void calculate(int at) {
		if (ways[0][at] != -1) {
			return;
		}
		ways[0][at] = ways[1][at] = ways[2][at] = 0;
		for (int j = automaton.first[at]; j != -1; j = automaton.next[j]) {
			if (Character.isDigit(automaton.label[j])) {
				ways[automaton.label[j] - '0'][at]++;
			} else {
				calculate(automaton.to[j]);
				for (int i = 0; i < 3; i++) {
					ways[i][at] += ways[i][automaton.to[j]];
				}
			}
		}
	}
}

class SuffixAutomaton {
    public final int[] length;
    public final int[] link;
    public final int[] first;
    public final int[] next;
    public final int[] to;
    public final int[] label;
    public int size;
    public int last;
	public int edgeSize;

	public SuffixAutomaton(final CharSequence s) {
        this(new IntList() {
            @Override
            public int get(int index) {
                return s.charAt(index);
            }

            public void set(int index, int value) {
                throw new UnsupportedOperationException();
            }

            @Override
            public int size() {
                return s.length();
            }

            public void add(int value) {
                throw new UnsupportedOperationException();
            }
        });
    }

    public SuffixAutomaton(IntList s) {
        int count = s.size();
        length = new int[2 * count + 1];
        link = new int[2 * count + 1];
        first = new int[2 * count + 1];
        next = new int[4 * count];
        label = new int[4 * count];
        to = new int[4 * count];
        Arrays.fill(first, -1);
        link[0] = -1;
        size = 1;
        edgeSize = 0;
        last = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s.get(i);
            int current = size++;
            length[current] = length[last] + 1;
            for (int previous = last; ; previous = link[previous]) {
                if (previous == -1) {
                    link[current] = 0;
                    break;
                }
                int index = findEdge(previous, c);
                if (index != -1) {
                    int curLink = to[index];
                    if (length[previous] + 1 == length[curLink])
                        link[current] = curLink;
                    else {
                        int clone = size++;
                        length[clone] = length[previous] + 1;
                        link[clone] = link[curLink];
                        int linkEdge = first[curLink];
                        while (linkEdge != -1) {
                            next[edgeSize] = first[clone];
                            first[clone] = edgeSize;
                            label[edgeSize] = label[linkEdge];
                            to[edgeSize++] = to[linkEdge];
                            linkEdge = next[linkEdge];
                        }
                        for (; previous != -1; previous = link[previous]) {
                            int edge = findEdge(previous, c);
                            if (edge == -1 || to[edge] != curLink)
                                break;
                            to[edge] = clone;
                        }
                        link[current] = link[curLink] = clone;
                    }
                    break;
                }
                next[edgeSize] = first[previous];
                first[previous] = edgeSize;
                label[edgeSize] = c;
                to[edgeSize++] = current;
            }
            last = current;
        }
    }

    public int findEdge(int vertex, int label) {
        int edge = first[vertex];
        while (edge != -1) {
            if (this.label[edge] == label)
                return edge;
            edge = next[edge];
        }
        return -1;
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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
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

class ArrayUtils {

	public static void fill(long[][] array, long value) {
		for (long[] row : array)
			Arrays.fill(row, value);
	}

}

abstract class IntervalTree {
	protected int size;

	protected IntervalTree(int size) {
		this(size, true);
	}

	public IntervalTree(int size, boolean shouldInit) {
		this.size = size;
		int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
		initData(size, nodeCount);
		if (shouldInit)
			init();
	}

	protected abstract void initData(int size, int nodeCount);
	protected abstract void initAfter(int root, int left, int right, int middle);
	protected abstract void initBefore(int root, int left, int right, int middle);
	protected abstract void initLeaf(int root, int index);
	protected abstract void updatePostProcess(int root, int left, int right, int from, int to, long delta, int middle);
	protected abstract void updatePreProcess(int root, int left, int right, int from, int to, long delta, int middle);
	protected abstract void updateFull(int root, int left, int right, int from, int to, long delta);
	protected abstract long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult);
	protected abstract void queryPreProcess(int root, int left, int right, int from, int to, int middle);
	protected abstract long queryFull(int root, int left, int right, int from, int to);
	protected abstract long emptySegmentResult();

	public void init() {
		if (size == 0)
			return;
		init(0, 0, size - 1);
	}

	private void init(int root, int left, int right) {
		if (left == right) {
			initLeaf(root, left);
		} else {
			int middle = (left + right) >> 1;
			initBefore(root, left, right, middle);
			init(2 * root + 1, left, middle);
			init(2 * root + 2, middle + 1, right);
			initAfter(root, left, right, middle);
		}
	}

	public void update(int from, int to, long delta) {
		update(0, 0, size - 1, from, to, delta);
	}

	protected void update(int root, int left, int right, int from, int to, long delta) {
		if (left > to || right < from)
			return;
		if (left >= from && right <= to) {
			updateFull(root, left, right, from, to, delta);
			return;
		}
		int middle = (left + right) >> 1;
		updatePreProcess(root, left, right, from, to, delta, middle);
		update(2 * root + 1, left, middle, from, to, delta);
		update(2 * root + 2, middle + 1, right, from, to, delta);
		updatePostProcess(root, left, right, from, to, delta, middle);
	}

	public long query(int from, int to) {
		return query(0, 0, size - 1, from, to);
	}

	protected long query(int root, int left, int right, int from, int to) {
		if (left > to || right < from)
			return emptySegmentResult();
		if (left >= from && right <= to)
			return queryFull(root, left, right, from, to);
		int middle = (left + right) >> 1;
		queryPreProcess(root, left, right, from, to, middle);
		long leftResult = query(2 * root + 1, left, middle, from, to);
		long rightResult = query(2 * root + 2, middle + 1, right, from, to);
		return queryPostProcess(root, left, right, from, to, middle, leftResult, rightResult);
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

abstract class IntList extends IntCollection implements Comparable<IntList> {

	public abstract int get(int index);

	public IntIterator iterator() {
		return new IntIterator() {
			private int size = size();
			private int index = 0;

			public int value() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				return get(index);
			}

			public void advance() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				index++;
			}

			public boolean isValid() {
				return index < size;
			}
		};
	}

	public int hashCode() {
		int hashCode = 1;
		for (IntIterator i = iterator(); i.isValid(); i.advance())
			hashCode = 31 * hashCode + i.value();
		return hashCode;
	}

	public boolean equals(Object obj) {
		if (!(obj instanceof IntList))
			return false;
		IntList list = (IntList)obj;
		if (list.size() != size())
			return false;
		IntIterator i = iterator();
		IntIterator j = list.iterator();
		while (i.isValid()) {
			if (i.value() != j.value())
				return false;
			i.advance();
			j.advance();
		}
		return true;
	}

	public int compareTo(IntList o) {
		IntIterator i = iterator();
		IntIterator j = o.iterator();
		while (true) {
			if (i.isValid()) {
				if (j.isValid()) {
					if (i.value() != j.value()) {
						if (i.value() < j.value())
							return -1;
						else
							return 1;
					}
				} else
					return 1;
			} else {
				if (j.isValid())
					return -1;
				else
					return 0;
			}
			i.advance();
			j.advance();
		}
	}

}

abstract class IntCollection {
	public abstract int size();

}

interface IntIterator {
	public int value() throws NoSuchElementException;
	/*
	 * @throws NoSuchElementException only if iterator already invalid
	 */
	public void advance() throws NoSuchElementException;
	public boolean isValid();
}

abstract class LongIntervalTree extends IntervalTree {
    protected long[] value;
    protected long[] delta;

    protected LongIntervalTree(int size) {
        this(size, true);
    }

	public LongIntervalTree(int size, boolean shouldInit) {
		super(size, shouldInit);
	}

	protected void initData(int size, int nodeCount) {
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

	protected void initAfter(int root, int left, int right, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
		delta[root] = neutralDelta();
	}

	protected void initBefore(int root, int left, int right, int middle) {
	}

	protected void initLeaf(int root, int index) {
		value[root] = initValue(index);
		delta[root] = neutralDelta();
	}

	protected void updatePostProcess(int root, int left, int right, int from, int to, long delta, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
	}

	protected void updatePreProcess(int root, int left, int right, int from, int to, long delta, int middle) {
		pushDown(root, left, middle, right);
	}

	protected void pushDown(int root, int left, int middle, int right) {
		value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root], middle - left + 1);
		value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root], right - middle);
		delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
		delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
		delta[root] = neutralDelta();
	}

	protected void updateFull(int root, int left, int right, int from, int to, long delta) {
		value[root] = accumulate(value[root], delta, right - left + 1);
		this.delta[root] = joinDelta(this.delta[root], delta);
	}

	protected long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult) {
		return joinValue(leftResult, rightResult);
	}

	protected void queryPreProcess(int root, int left, int right, int from, int to, int middle) {
		pushDown(root, left, middle, right);
	}

	protected long queryFull(int root, int left, int right, int from, int to) {
		return value[root];
	}

	protected long emptySegmentResult() {
		return neutralValue();
	}
}