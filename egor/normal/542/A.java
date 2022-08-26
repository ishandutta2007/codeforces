import java.util.NavigableSet;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.util.TreeSet;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.Set;

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
        int clipCount = in.readInt();
        int tvCount = in.readInt();
        int[] left = new int[clipCount];
        int[] right = new int[clipCount];
        IOUtils.readIntArrays(in, left, right);
        int[] from = new int[tvCount];
        int[] to = new int[tvCount];
        int[] qty = new int[tvCount];
        IOUtils.readIntArrays(in, from, to, qty);
        long answer = 0;
        int bestClip = -1;
        int bestTv = -1;
        int[] clipId = ArrayUtils.createOrder(clipCount);
        int[] tvId = ArrayUtils.createOrder(tvCount);
        ArrayUtils.orderBy(left, right, clipId);
        ArrayUtils.orderBy(from, to, qty, tvId);
        int at = 0;
        int rightMost = -1;
        for (int i = 0; i < tvCount; i++) {
            while (at < clipCount && left[at] <= from[i]) {
                if (rightMost == -1 || right[at] > right[rightMost]) {
                    rightMost = at;
                }
                at++;
            }
            int length = rightMost == -1 ? 0 : Math.max(Math.min(right[rightMost], to[i]) - from[i], 0);
            long value = (long)length * qty[i];
            if (value > answer) {
                answer = value;
                bestClip = clipId[rightMost] + 1;
                bestTv = tvId[i] + 1;
            }
        }
        ArrayUtils.orderBy(right, left, clipId);
        ArrayUtils.orderBy(to, from, qty, tvId);
        at = clipCount - 1;
        int leftMost = -1;
        for (int i = tvCount - 1; i >= 0; i--) {
            while (at >= 0 && right[at] >= to[i]) {
                if (leftMost == -1 || left[at] < left[leftMost]) {
                    leftMost = at;
                }
                at--;
            }
            int length = leftMost == -1 ? 0 : Math.max(to[i] - Math.max(left[leftMost], from[i]), 0);
            long value = (long)length * qty[i];
            if (value > answer) {
                answer = value;
                bestClip = clipId[leftMost] + 1;
                bestTv = tvId[i] + 1;
            }
        }
        left = Arrays.copyOf(left, clipCount + 1);
        final int[] finalLeft = left;
        NavigableSet<Integer> set = new TreeSet<>((a, b) -> finalLeft[a] - finalLeft[b]);
        at = 0;
        for (int i = 0; i < tvCount; i++) {
            while (at < clipCount && right[at] <= to[i]) {
                Integer toRight = set.ceiling(at);
                if (toRight != null && right[toRight] - left[toRight] >= right[at] - left[at]) {
                    at++;
                    continue;
                }
                while (true) {
                    Integer toLeft = set.lower(at);
                    if (toLeft == null || right[toLeft] - left[toLeft] > right[at] - left[at]) {
                        break;
                    }
                    set.remove(toLeft);
                }
                set.add(at++);
            }
            left[clipCount] = from[i];
            Integer id = set.ceiling(clipCount);
            if (id != null) {
                long value = (long)(right[id] - left[id]) * qty[i];
                if (value > answer) {
                    answer = value;
                    bestClip = clipId[id] + 1;
                    bestTv = tvId[i] + 1;
                }
            }
        }
        out.printLine(answer);
        if (answer != 0) {
            out.printLine(bestClip, bestTv);
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

	public void printLine(long i) {
		writer.println(i);
	}

}

class IOUtils {

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

}

class ArrayUtils {
	private static int[] tempInt = new int[0];

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

	private static void ensureCapacityInt(int size) {
		if (tempInt.length >= size)
			return;
		size = Math.max(size, tempInt.length << 1);
		tempInt = new int[size];
	}

	public static int[] order(final int[] array) {
		return sort(createOrder(array.length), new IntComparator() {
			public int compare(int first, int second) {
				if (array[first] < array[second])
					return -1;
				if (array[first] > array[second])
					return 1;
				return 0;
			}
		});
	}

	public static void orderBy(int[] base, int[]... arrays) {
		int[] order = ArrayUtils.order(base);
		order(order, base);
		for (int[] array : arrays)
			order(order, array);
	}

	public static void order(int[] order, int[] array) {
		ensureCapacityInt(order.length);
		for (int i = 0; i < order.length; i++)
			tempInt[i] = array[order[i]];
		System.arraycopy(tempInt, 0, array, 0, array.length);
	}

}

abstract class IntCollection {
	public abstract IntIterator iterator();
	public abstract int size();

}

interface IntIterator {
	public int value() throws NoSuchElementException;
	public void advance() throws NoSuchElementException;
	public boolean isValid();
}

interface IntComparator {

	public int compare(int first, int second);
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