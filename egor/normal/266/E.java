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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    private static final long MOD = (long) (1e9 + 7);

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int count = in.readInt();
        int queryCount = in.readInt();
        int[] array = IOUtils.readIntArray(in, count);
        SpecialIntervalTree tree = new SpecialIntervalTree(array);
        for (int i = 0; i < queryCount; i++) {
            char type = in.readCharacter();
            if (type == '?') {
                int from = in.readInt() - 1;
                int to = in.readInt() - 1;
                int index = in.readInt();
                out.printLine(tree.query(from, to, index));
            } else {
                int from = in.readInt() - 1;
                int to = in.readInt() - 1;
                int delta = in.readInt();
                if (delta < 0)
                    throw new RuntimeException();
                tree.update(from, to, delta);
            }
        }
    }

    static class SpecialIntervalTree {
        private final int[] array;
        protected int size;
        protected long[][] value;
        protected long[] delta;
        protected long[][] power;
        protected long[][] sumPower;
        protected long[][] result;
        protected long[] total = new long[6];
        protected long[][] c = IntegerUtils.generateBinomialCoefficients(6);
        protected long[] shift = new long[6];

        protected SpecialIntervalTree(int[] array) {
            this.array = array;
            this.size = array.length;
            int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
            value = new long[6][nodeCount];
            delta = new long[nodeCount];
            power = new long[6][size];
            Arrays.fill(power[0], 1);
            for (int i = 1; i < 6; i++) {
                for (int j = 0; j < size; j++)
                    power[i][j] = power[i - 1][j] * (j + 1) % MOD;
            }
            sumPower = new long[6][size + 1];
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < size; j++) {
                    sumPower[i][j + 1] = sumPower[i][j] + power[i][j];
                    if (sumPower[i][j + 1] >= MOD)
                        sumPower[i][j + 1] -= MOD;
                }
            }
            result = new long[6][nodeCount];
            init();
        }

        protected long initValue(int index) {
            return array[index];
        }

        public void init() {
            init(0, 0, size - 1);
        }

        private void init(int root, int left, int right) {
            if (left == right) {
                for (int i = 0; i < 6; i++)
                    value[i][root] = power[i][left] * initValue(left) % MOD;
                delta[root] = -1;
            } else {
                int middle = (left + right) >> 1;
                init(2 * root + 1, left, middle);
                init(2 * root + 2, middle + 1, right);
                join(root);
                delta[root] = -1;
            }
        }

        private void join(int root) {
            for (int i = 0; i < 6; i++) {
                value[i][root] = value[i][2 * root + 1] + value[i][2 * root + 2];
                if (value[i][root] >= MOD)
                    value[i][root] -= MOD;
            }
        }

        private void apply(int root, int left, int right) {
            if (delta[root] == -1)
                throw new RuntimeException();
            for (int i = 0; i < 6; i++) {
               value[i][root] = (sumPower[i][right + 1] - sumPower[i][left]) * delta[root] % MOD;
                if (value[i][root] < 0)
                    value[i][root] += MOD;
            }
        }

        public void update(int from, int to, long delta) {
            update(0, 0, size - 1, from, to, delta);
        }

        private void update(int root, int left, int right, int from, int to, long delta) {
            if (left > to || right < from)
                return;
            if (left >= from && right <= to) {
                this.delta[root] = delta;
                apply(root, left, right);
                return;
            }
            int middle = (left + right) >> 1;
            if (this.delta[root] != -1) {
                this.delta[2 * root + 1] = this.delta[root];
                apply(2 * root + 1, left, middle);
                this.delta[2 * root + 2] = this.delta[root];
                apply(2 * root + 2, middle + 1, right);
            }
            this.delta[root] = -1;
            update(2 * root + 1, left, middle, from, to, delta);
            update(2 * root + 2, middle + 1, right, from, to, delta);
            join(root);
        }

        public long query(int from, int to, int index) {
            query(0, 0, size - 1, from, to);
            shift[0] = 1;
            total[0] = result[0][0];
            for (int i = 1; i < 6; i++) {
                shift[i] = (shift[i - 1] * from) % MOD;
                total[i] = result[i][0];
                for (int j = 0; j < i; j++)
                    total[i] -= shift[i - j] * total[j] % MOD * c[i][j];
                total[i] %= MOD;
                if (total[i] < 0)
                    total[i] += MOD;
            }
            return total[index];
        }

        private void query(int root, int left, int right, int from, int to) {
            if (left > to || right < from) {
                for (int i = 0; i < 6; i++)
                    result[i][root] = 0;
                return;
            }
            if (left >= from && right <= to) {
                for (int i = 0; i < 6; i++)
                    result[i][root] = value[i][root];
                return;
            }
            int middle = (left + right) >> 1;
            if (this.delta[root] != -1) {
                this.delta[2 * root + 1] = this.delta[root];
                apply(2 * root + 1, left, middle);
                this.delta[2 * root + 2] = this.delta[root];
                apply(2 * root + 2, middle + 1, right);
            }
            this.delta[root] = -1;
            query(2 * root + 1, left, middle, from, to);
            query(2 * root + 2, middle + 1, right, from, to);
            for (int i = 0; i < 6; i++) {
                result[i][root] = result[i][2 * root + 1] + result[i][2 * root + 2];
                if (result[i][root] >= MOD)
                    result[i][root] -= MOD;
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

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
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

class IntegerUtils {

    public static long[][] generateBinomialCoefficients(int n) {
		long[][] result = new long[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			result[i][0] = 1;
			for (int j = 1; j <= i; j++)
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
		return result;
	}

	}

abstract class IntCollection {
	public abstract IntIterator iterator();
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

abstract class IntList extends IntCollection {
	private static final int INSERTION_THRESHOLD = 8;

	public abstract int get(int index);
	public abstract void set(int index, int value);

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

	private void swap(int first, int second) {
		if (first == second)
			return;
		int temp = get(first);
		set(first, get(second));
		set(second, temp);
	}

	public IntSortedList inPlaceSort(IntComparator comparator) {
		quickSort(0, size() - 1, size(), comparator);
		return new IntSortedArray(this, comparator);
	}

	private void quickSort(int from, int to, int remaining, IntComparator comparator) {
		if (to - from < INSERTION_THRESHOLD) {
			insertionSort(from, to, comparator);
			return;
		}
		if (remaining == 0) {
			heapSort(from, to, comparator);
			return;
		}
		remaining >>= 1;
		int pivotIndex = (from + to) >> 1;
		int pivot = get(pivotIndex);
		swap(pivotIndex, to);
		int storeIndex = from;
		int equalIndex = to;
		for (int i = from; i < equalIndex; i++) {
			int value = comparator.compare(get(i), pivot);
			if (value < 0)
				swap(storeIndex++, i);
			else if (value == 0)
				swap(--equalIndex, i--);
		}
		quickSort(from, storeIndex - 1, remaining, comparator);
		for (int i = equalIndex; i <= to; i++)
			swap(storeIndex++, i);
		quickSort(storeIndex, to, remaining, comparator);
	}

	private void heapSort(int from, int to, IntComparator comparator) {
		for (int i = (to + from - 1) >> 1; i >= from; i--)
			siftDown(i, to, comparator);
		for (int i = to; i > from; i--) {
			swap(from, i);
			siftDown(from, i - 1, comparator);
		}
	}

	private void siftDown(int start, int end, IntComparator comparator) {
		int value = get(start);
		while (true) {
			int child = (start << 1) + 1;
			if (child > end)
				return;
			int childValue = get(child);
			if (child + 1 <= end) {
				int otherValue = get(child + 1);
				if (comparator.compare(otherValue, childValue) > 0) {
					child++;
					childValue = otherValue;
				}
			}
			if (comparator.compare(value, childValue) >= 0)
				return;
			swap(start, child);
			start = child;
		}
	}

	private void insertionSort(int from, int to, IntComparator comparator) {
		for (int i = from + 1; i <= to; i++) {
			int value = get(i);
			for (int j = i - 1; j >= from; j--) {
				if (comparator.compare(get(j), value) <= 0)
					break;
				swap(j, j + 1);
			}
		}
	}

	public IntSortedList sort(IntComparator comparator) {
		return new IntArray(this).inPlaceSort(comparator);
	}

	}

interface IntComparator {
    public static final IntComparator DEFAULT = new IntComparator() {
        public int compare(int first, int second) {
            if (first < second)
                return -1;
            if (first > second)
                return 1;
            return 0;
        }
    };

	public int compare(int first, int second);
}

abstract class IntSortedList extends IntList {
	protected final IntComparator comparator;

	protected IntSortedList(IntComparator comparator) {
		this.comparator = comparator;
	}

	public void set(int index, int value) {
		throw new UnsupportedOperationException();
	}

	public IntSortedList inPlaceSort(IntComparator comparator) {
		if (comparator == this.comparator)
			return this;
		throw new UnsupportedOperationException();
	}

	public IntSortedList sort(IntComparator comparator) {
		if (comparator == this.comparator)
			return this;
		return super.sort(comparator);
	}

	protected void ensureSorted() {
		int size = size();
		if (size == 0)
			return;
		int last = get(0);
		for (int i = 1; i < size; i++) {
			int current = get(i);
			if (comparator.compare(last, current) > 0)
				throw new IllegalArgumentException();
			last = current;
		}
	}

	}

class IntSortedArray extends IntSortedList {
	private final int[] array;

	public IntSortedArray(int[] array) {
		this(array, IntComparator.DEFAULT);
	}

	public IntSortedArray(IntCollection collection) {
		this(collection, IntComparator.DEFAULT);
	}

	public IntSortedArray(int[] array, IntComparator comparator) {
		super(comparator);
		this.array = array;
		ensureSorted();
	}

	public IntSortedArray(IntCollection collection, IntComparator comparator) {
		super(comparator);
		array = new int[collection.size()];
		int i = 0;
		for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
			array[i++] = iterator.value();
		ensureSorted();
	}

	public int get(int index) {
		return array[index];
	}

	public int size() {
		return array.length;
	}
}

class IntArray extends IntList {
	private final int[] array;

	public IntArray(int[] array) {
		this.array = array;
	}

	public IntArray(IntCollection collection) {
		array = new int[collection.size()];
		int i = 0;
		for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
			array[i++] = iterator.value();
	}

	public int get(int index) {
		return array[index];
	}

	public void set(int index, int value) {
		array[index] = value;
	}

	public int size() {
		return array.length;
	}

	}