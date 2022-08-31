import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.List;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.util.Random;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	private static final long MOD = (long) (1e9 + 7);

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[] x = in.readString().toCharArray();
		long[][] qty = new long[x.length + 1][x.length + 1];
		int[][] prints = new int[x.length + 1][x.length + 1];
		int[][] lcp = new int[x.length + 1][x.length + 1];
		boolean[][] nonZero = new boolean[x.length + 1][x.length + 1];
		ArrayUtils.fill(prints, Integer.MAX_VALUE / 2);
		prints[0][0] = 1;
		qty[0][0] = 1;
		nonZero[0][0] = true;
		StringHash hash = new SimpleStringHash(new String(x));
		int[] order = ArrayUtils.createOrder(x.length);
		ArrayUtils.sort(order, new IntComparator() {
			public int compare(int first, int second) {
				int left = commonPrefix(first, second, hash);
				if (left == Math.min(x.length - first, x.length - second)) {
					return second - first;
				}
				return x[first + left] - x[second + left];
			}
		});
		int[] position = ArrayUtils.reversePermutation(order);
		int[] common = new int[x.length - 1];
		for (int i = 0; i < x.length - 1; i++) {
			common[i] = commonPrefix(order[i], order[i + 1], hash);
		}
		for (int i = 0; i < x.length; i++) {
			int current = Integer.MAX_VALUE;
			for (int j = i + 1; j < x.length; j++) {
				current = Math.min(current, common[j - 1]);
				lcp[i][j] = lcp[j][i] = current;
			}
		}
		for (int i = 1; i <= x.length; i++) {
			for (int j = Math.max(i - 1, 0); j >= 0; j--) {
				nonZero[i][j] |= nonZero[i - 1][j];
				prints[i][j] = Math.min(prints[i][j], prints[i - 1][j]);
				qty[i][j] += qty[i - 1][j];
				if (qty[i][j] >= MOD) {
					qty[i][j] -= MOD;
				}
				if (i == x.length || x[i] != '1') {
					continue;
				}
				int next = 2 * i - j;
				if (position[i] < position[j] && lcp[position[i]][position[j]] < i - j) {
					next++;
				}
				if (next > x.length) {
					continue;
				}
				nonZero[next][i] |= nonZero[i][j];
				prints[next][i] = Math.min(prints[next][i], prints[i][j] + 1);
				qty[next][i] += qty[i][j];
				if (qty[next][i] >= MOD) {
					qty[next][i] -= MOD;
				}
			}
		}
		long totalQty = 0;
		long minOps = Integer.MAX_VALUE;
		boolean init = false;
		for (int i = x.length - 1; i >= 0; i--) {
			if (x[i] == '1' && nonZero[x.length][i]) {
				totalQty += qty[x.length][i];
				if (!init || x.length - i <= 32) {
					long current = 0;
					boolean overflow = false;
					for (int j = i; j < x.length; j++) {
						current *= 2;
						current += x[j] - '0';
						if (current >= MOD) {
							overflow = true;
							current -= MOD;
						}
					}
					current += prints[x.length][i];
					if (current >= MOD) {
						overflow = true;
						current -= MOD;
					}
					if (current < minOps && !overflow || !init) {
						minOps = current;
					}
					init = true;
				}
			}
		}
		out.printLine(totalQty % MOD);
		out.printLine(minOps);
    }

	protected int commonPrefix(int first, int second, StringHash hash) {
		int left = 0;
		int right = Math.min(hash.length() - first, hash.length() - second);
		while (left < right) {
			int middle = (left + right + 1) >> 1;
			if (hash.hash(first, first + middle) == hash.hash(second, second + middle)) {
				left = middle;
			} else {
				right = middle - 1;
			}
		}
		return left;
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

	public void close() {
		writer.close();
	}

	public void printLine(long i) {
		writer.println(i);
	}

}

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

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
		if (from == 0 && to == array.length)
			new IntArray(array).inPlaceSort(comparator);
		else
			new IntArray(array).subList(from, to).inPlaceSort(comparator);
		return array;
	}

	public static int[] reversePermutation(int[] permutation) {
		int[] result = new int[permutation.length];
		for (int i = 0; i < permutation.length; i++)
			result[permutation[i]] = i;
		return result;
	}

}

interface StringHash {
    long hash(int from, int to);

	int length();
}

class SimpleStringHash extends AbstractStringHash {
    private static long[] firstReversePower = new long[0];
    private static long[] secondReversePower = new long[0];

    private final long[] firstHash;
    private final long[] secondHash;

    public SimpleStringHash(CharSequence string) {
        int length = string.length();
        ensureCapacity(length);
		firstHash = new long[length + 1];
        secondHash = new long[length + 1];
        long firstPower = 1;
        long secondPower = 1;
		for (int i = 0; i < length; i++) {
			firstHash[i + 1] = (firstHash[i] + string.charAt(i) * firstPower) % FIRST_MOD;
            secondHash[i + 1] = (secondHash[i] + string.charAt(i) * secondPower) % SECOND_MOD;
			firstPower *= MULTIPLIER;
            firstPower %= FIRST_MOD;
            secondPower *= MULTIPLIER;
            secondPower %= SECOND_MOD;
		}
	}

    private void ensureCapacity(int length) {
        if (firstReversePower.length >= length)
            return;
        length = Math.max(length + 1, firstReversePower.length << 1);
        long[] oldFirst = firstReversePower;
        long[] oldSecond = secondReversePower;
        firstReversePower = new long[length];
        secondReversePower = new long[length];
        System.arraycopy(oldFirst, 0, firstReversePower, 0, oldFirst.length);
        System.arraycopy(oldSecond, 0, secondReversePower, 0, oldSecond.length);
        firstReversePower[0] = secondReversePower[0] = 1;
        for (int i = Math.max(oldFirst.length, 1); i < length; i++) {
            firstReversePower[i] = firstReversePower[i - 1] * FIRST_REVERSE_MULTIPLIER % FIRST_MOD;
            secondReversePower[i]= secondReversePower[i - 1] * SECOND_REVERSE_MULTIPLIER % SECOND_MOD;
        }
    }

    public long hash(int from, int to) {
		return (((firstHash[to] - firstHash[from] + FIRST_MOD) * firstReversePower[from] % FIRST_MOD) << 32) +
            ((secondHash[to] - secondHash[from] + SECOND_MOD) * secondReversePower[from] % SECOND_MOD);
	}

	public int length() {
		return firstHash.length - 1;
	}
}

interface IntComparator {

	public int compare(int first, int second);
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

abstract class IntList extends IntCollection implements Comparable<IntList> {
	private static final int INSERTION_THRESHOLD = 16;

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

	public IntList subList(final int from, final int to) {
		return new SubList(from, to);
	}

	private void swap(int first, int second) {
		if (first == second)
			return;
		int temp = get(first);
		set(first, get(second));
		set(second, temp);
	}

	public IntSortedList inPlaceSort(IntComparator comparator) {
		quickSort(0, size() - 1, (Integer.bitCount(Integer.highestOneBit(size()) - 1) * 5) >> 1, comparator);
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
		remaining--;
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
			siftDown(i, to, comparator, from);
		for (int i = to; i > from; i--) {
			swap(from, i);
			siftDown(from, i - 1, comparator, from);
		}
	}

	private void siftDown(int start, int end, IntComparator comparator, int delta) {
		int value = get(start);
		while (true) {
			int child = ((start - delta) << 1) + 1 + delta;
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

	private class SubList extends IntList {
        private final int to;
        private final int from;
        private int size;

        public SubList(int from, int to) {
            this.to = to;
            this.from = from;
            size = to - from;
        }

        public int get(int index) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            return IntList.this.get(index + from);
        }

        public void set(int index, int value) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            IntList.this.set(index + from, value);
        }

        public int size() {
            return size;
        }

	}
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

	public IntSortedList subList(final int from, final int to) {
		return new IntSortedList(comparator) {
			private int size = to - from;

			public int get(int index) {
				if (index < 0 || index >= size)
					throw new IndexOutOfBoundsException();
				return IntSortedList.this.get(index + from);
			}

			public int size() {
				return size;
			}
		};
	}
}

class IntArray extends IntList {
	private final int[] array;

	public IntArray(int[] array) {
		this.array = array;
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

abstract class AbstractStringHash implements StringHash {
    public static final long MULTIPLIER;
    protected static final long FIRST_REVERSE_MULTIPLIER;
    protected static final long SECOND_REVERSE_MULTIPLIER;
    public static final long FIRST_MOD;
    public static final long SECOND_MOD;

    static {
        Random random = new Random(System.currentTimeMillis());
        FIRST_MOD = IntegerUtils.nextPrime((long) (1e9 + random.nextInt((int) 1e9)));
        SECOND_MOD = IntegerUtils.nextPrime((long) (1e9 + random.nextInt((int) 1e9)));
		MULTIPLIER = random.nextInt((int) 1e9 - 257) + 257;
        FIRST_REVERSE_MULTIPLIER = IntegerUtils.reverse(MULTIPLIER, FIRST_MOD);
        SECOND_REVERSE_MULTIPLIER = IntegerUtils.reverse(MULTIPLIER, SECOND_MOD);
    }

}

class IntSortedArray extends IntSortedList {
	private final int[] array;

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

class IntegerUtils {

	public static long power(long base, long exponent, long mod) {
		if (base >= mod)
			base %= mod;
		if (exponent == 0)
			return 1 % mod;
		long result = power(base, exponent >> 1, mod);
		result = result * result % mod;
		if ((exponent & 1) != 0)
			result = result * base % mod;
		return result;
	}

	public static long reverse(long number, long module) {
		return power(number, module - 2, module);
	}

	public static boolean isPrime(long number) {
		if (number < 2)
			return false;
		for (long i = 2; i * i <= number; i++) {
			if (number % i == 0)
				return false;
		}
		return true;
	}

	public static long nextPrime(long from) {
        if (from <= 2)
            return 2;
        from += 1 - (from & 1);
        while (!isPrime(from))
            from += 2;
        return from;
    }

}