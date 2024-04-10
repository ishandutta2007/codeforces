import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

	private int[] first;
	private int[] next;
	private int[] diamonds;
	private IntList[] to;
	private int[] max;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int changeCount = in.readInt();
		int count = in.readInt();
		first = new int[count];
		next = new int[changeCount];
		int[] inFirst = new int[count];
		int[] inNext = new int[100000];
		int[] edge = new int[100000];
		int edgeCount = 0;
		diamonds = new int[changeCount];
		int[] degree = new int[changeCount];
		int[] from = new int[changeCount];
		to = new IntList[changeCount];
		Arrays.fill(first, -1);
		Arrays.fill(inFirst, -1);
		for (int i = 0; i < changeCount; i++) {
			from[i] = in.readInt() - 1;
			next[i] = first[from[i]];
			first[from[i]] = i;
			int currentCount = in.readInt();
			to[i] = new IntArrayList(currentCount);
			for (int j = 0; j < currentCount; j++) {
				int type = in.readInt();
				if (type == -1)
					diamonds[i]++;
				else {
					type--;
					inNext[edgeCount] = inFirst[type];
					edge[edgeCount] = i;
					inFirst[type] = edgeCount++;
					to[i].add(type);
					degree[i]++;
				}
			}
		}
		final int[] min = new int[count];
		max = new int[count];
		Heap heap = new Heap(new IntComparator() {
			public int compare(int first, int second) {
				return min[first] - min[second];
			}
		}, count);
		boolean[] processed = new boolean[count];
		for (int i = 0; i < changeCount; i++) {
			if (degree[i] == 0) {
				if (processed[from[i]]) {
					min[from[i]] = Math.min(min[from[i]], diamonds[i]);
					heap.shiftUp(heap.getIndex(from[i]));
				} else {
					min[from[i]] = diamonds[i];
					heap.add(from[i]);
					processed[from[i]] = true;
				}
			}
		}
		while (!heap.isEmpty()) {
			int i = heap.poll();
			for (int jj = inFirst[i]; jj != -1; jj = inNext[jj]) {
				int j = edge[jj];
				degree[j]--;
				if (degree[j] == 0) {
					int total = diamonds[j];
					for (IntIterator iterator = to[j].iterator(); iterator.isValid(); iterator.advance()) {
						total = (int) Math.min(314000000, total + min[iterator.value()]);
					}
					if (processed[from[j]]) {
						if (min[from[j]] > total) {
							min[from[j]] = total;
							heap.shiftUp(heap.getIndex(from[j]));
						}
					} else {
						min[from[j]] = total;
						heap.add(from[j]);
						processed[from[j]] = true;
					}
				}
			}
		}
		for (int i = 0; i < count; i++) {
			if (!processed[i])
				min[i] = max[i] = -1;
		}
		for (int i = 0; i < count; i++) {
			if (max[i] != -2)
				dfs(i);
			out.printLine(min[i], max[i]);
		}
    }

	private int dfs(int i) {
		if (max[i] != 0)
			return max[i];
		max[i] = -2;
		int result = 0;
		for (int j = first[i]; j != -1; j = next[j]) {
			boolean valid = true;
			int total = diamonds[j];
			boolean infinity = false;
			for (IntIterator iterator = to[j].iterator(); iterator.isValid(); iterator.advance()) {
				int k = iterator.value();
				if (max[k] == -1) {
					valid = false;
					break;
				}
				dfs(k);
				if (max[k] == -2)
					infinity = true;
				else
					total = (int) Math.min(314000000, total + max[k]);
			}
			if (!valid)
				continue;
			if (infinity)
				return max[i];
			result = Math.max(result, total);
		}
		return max[i] = result;
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

	}

abstract class IntCollection {
	public abstract IntIterator iterator();
	public abstract int size();
	public abstract void add(int value);

	public void addAll(IntCollection values) {
		for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
			add(it.value());
		}
	}

	}

class Heap {
	private IntComparator comparator;
	private int size = 0;
	private int[] elements;
	private int[] at;

	public Heap(int maxElement) {
		this(10, maxElement);
	}

	public Heap(IntComparator comparator, int maxElement) {
		this(10, comparator, maxElement);
	}

	public Heap(int capacity, int maxElement) {
		this(capacity, IntComparator.DEFAULT, maxElement);
	}

	public Heap(int capacity, IntComparator comparator, int maxElement) {
		this.comparator = comparator;
		elements = new int[capacity];
		at = new int[maxElement];
		Arrays.fill(at, -1);
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public int add(int element) {
		ensureCapacity(size + 1);
		elements[size] = element;
		at[element] = size;
		shiftUp(size++);
		return at[element];
	}

	public void shiftUp(int index) {
//		if (index < 0 || index >= size)
//			throw new IllegalArgumentException();
		int value = elements[index];
		while (index != 0) {
			int parent = (index - 1) >>> 1;
			int parentValue = elements[parent];
			if (comparator.compare(parentValue, value) <= 0) {
				elements[index] = value;
				at[value] = index;
				return;
			}
			elements[index] = parentValue;
			at[parentValue] = index;
			index = parent;
		}
		elements[0] = value;
		at[value] = 0;
	}

	public void shiftDown(int index) {
		if (index < 0 || index >= size)
			throw new IllegalArgumentException();
		while (true) {
			int child = (index << 1) + 1;
			if (child >= size)
				return;
			if (child + 1 < size && comparator.compare(elements[child], elements[child + 1]) > 0)
				child++;
			if (comparator.compare(elements[index], elements[child]) <= 0)
				return;
			swap(index, child);
			index = child;
		}
	}

	public int getIndex(int element) {
		return at[element];
	}

	private void swap(int first, int second) {
		int temp = elements[first];
		elements[first] = elements[second];
		elements[second] = temp;
		at[elements[first]] = first;
		at[elements[second]] = second;
	}

	private void ensureCapacity(int size) {
		if (elements.length < size) {
			int[] oldElements = elements;
			elements = new int[Math.max(2 * elements.length, size)];
			System.arraycopy(oldElements, 0, elements, 0, this.size);
		}
	}

	public int poll() {
		if (isEmpty())
			throw new IndexOutOfBoundsException();
		int result = elements[0];
		at[result] = -1;
		if (size == 1) {
			size = 0;
			return result;
		}
		elements[0] = elements[--size];
		at[elements[0]] = 0;
		shiftDown(0);
		return result;
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

interface IntIterator {
	public int value() throws NoSuchElementException;
	/*
	 * @throws NoSuchElementException only if iterator already invalid
	 */
	public void advance() throws NoSuchElementException;
	public boolean isValid();
}