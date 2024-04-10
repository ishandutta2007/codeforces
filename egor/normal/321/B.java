import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int jiroCount = in.readInt();
		int cielCount = in.readInt();
		IntList attack = new IntArrayList();
		IntList defence = new IntArrayList();
		for (int i = 0; i < jiroCount; i++) {
			if ("DEF".equals(in.readString()))
				defence.add(in.readInt());
			else
				attack.add(in.readInt());
		}
		int[] cielStrength = IOUtils.readIntArray(in, cielCount);
		attack.inPlaceSort(IntComparator.REVERSE);
		defence.inPlaceSort();
		ArrayUtils.sort(cielStrength, IntComparator.REVERSE);
		int answer = 0;
		for (int i = 1; i <= Math.min(attack.size(), cielCount); i++) {
			int current = 0;
			for (int j = 0; j < i; j++)
				current += cielStrength[j];
			for (int j = attack.size() - i; j < attack.size(); j++)
				current -= attack.get(j);
			answer = Math.max(answer, current);
		}
		boolean[] killed = new boolean[cielCount];
		ArrayUtils.reverse(cielStrength);
		int j = 0;
		for (int i : defence.toArray()) {
			while (j < cielCount && i >= cielStrength[j])
				j++;
			if (j == cielCount) {
				out.printLine(answer);
				return;
			}
			killed[j++] = true;
		}
		j = 0;
		int all = 0;
		for (int i = cielCount - 1; i >= 0; i--) {
			if (killed[i])
				continue;
			if (j == attack.size())
				all += cielStrength[i];
			else if (cielStrength[i] < attack.get(j)) {
				out.printLine(answer);
				return;
			} else
				all += cielStrength[i] - attack.get(j++);
		}
		answer = Math.max(answer, all);
		out.printLine(answer);
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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
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

abstract class IntList extends IntCollection implements Comparable<IntList> {
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

	public IntSortedList inPlaceSort() {
		return inPlaceSort(IntComparator.DEFAULT);
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

        public void add(int value) {
            throw new UnsupportedOperationException();
        }
    }
}

class IntArrayList extends IntList {
	private int[] array;
	private int size;

	public IntArrayList() {
		this(10);
	}

	public IntArrayList(int capacity) {
		array = new int[capacity];
	}

	public IntArrayList(IntList list) {
		this(list.size());
		addAll(list);
	}

	public int get(int index) {
		if (index >= size)
			throw new IndexOutOfBoundsException();
		return array[index];
	}

	public void set(int index, int value) {
		if (index >= size)
			throw new IndexOutOfBoundsException();
		array[index] = value;
	}

	public int size() {
		return size;
	}

	public void add(int value) {
		ensureCapacity(size + 1);
		array[size++] = value;
	}

	public void ensureCapacity(int newCapacity) {
		if (newCapacity > array.length) {
			int[] newArray = new int[Math.max(newCapacity, array.length << 1)];
			System.arraycopy(array, 0, newArray, 0, size);
			array = newArray;
		}
	}

	public int[] toArray() {
		int[] array = new int[size];
		System.arraycopy(this.array, 0, array, 0, size);
		return array;
	}

    }

abstract class IntCollection {
	public abstract IntIterator iterator();
	public abstract int size();
	public abstract void add(int value);

	public int[] toArray() {
		int size = size();
		int[] array = new int[size];
		int i = 0;
		for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
			array[i++] = iterator.value();
		return array;
	}

	public void addAll(IntCollection values) {
		for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
			add(it.value());
		}
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

abstract class IntSortedList extends IntList {
	protected final IntComparator comparator;

	protected IntSortedList(IntComparator comparator) {
		this.comparator = comparator;
	}

	public void set(int index, int value) {
		throw new UnsupportedOperationException();
	}

	public void add(int value) {
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

			@Override
			public int get(int index) {
				if (index < 0 || index >= size)
					throw new IndexOutOfBoundsException();
				return IntSortedList.this.get(index + from);
			}

			@Override
			public int size() {
				return size;
			}
		};
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

	public static final IntComparator REVERSE = new IntComparator() {
		public int compare(int first, int second) {
			if (first < second)
				return 1;
			if (first > second)
				return -1;
			return 0;
		}
	};

	public int compare(int first, int second);
}

class ArrayUtils {

	public static int[] sort(int[] array, IntComparator comparator) {
		return sort(array, 0, array.length, comparator);
	}

	public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
		new IntArray(array).subList(from, to).inPlaceSort(comparator);
//		ensureCapacityInt(to - from);
//		System.arraycopy(array, from, tempInt, 0, to - from);
//		sortImpl(array, from, to, tempInt, 0, to - from, comparator);
		return array;
	}

	public static void reverse(int[] array) {
		for (int i = 0, j = array.length - 1; i < j; i++, j--) {
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	}

interface IntIterator {
	public int value() throws NoSuchElementException;
	/*
	 * @throws NoSuchElementException only if iterator already invalid
	 */
	public void advance() throws NoSuchElementException;
	public boolean isValid();
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

	public void add(int value) {
		throw new UnsupportedOperationException();
	}

	public int[] toArray() {
		return array;
	}
}