import java.util.Map;
import java.util.Collections;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.util.Collection;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;
import java.util.Comparator;
import java.io.*;
import java.util.Iterator;
import java.util.Arrays;

/**
 * @author Egor Kulikov (egor@egork.net)
 * Actual solution is at the bottom
 */
public class Main {
	public static void main(String[] args) {
		InputReader in = new StreamInputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		run(in, out);
	}

	public static void run(InputReader in, PrintWriter out) {
		Solver solver = new TaskE();
		solver.solve(1, in, out);
		Exit.exit(in, out);
	}
}

abstract class InputReader {
	private boolean finished = false;

	public abstract int read();

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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String readLine0() {
		StringBuffer buf = new StringBuffer();
		int c = read();
		while (c != '\n' && c != -1) {
			if (c != '\r')
				buf.appendCodePoint(c);
			c = read();
		}
		return buf.toString();
	}

	public String readLine() {
		String s = readLine0();
		while (s.trim().length() == 0)
			s = readLine0();
		return s;
	}

	public String readLine(boolean ignoreEmptyLines) {
		if (ignoreEmptyLines)
			return readLine();
		else
			return readLine0();
	}

	public BigInteger readBigInteger() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!isSpaceChar(c) && c != '.') {
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, readInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		if (c == '.') {
			c = read();
			double m = 1;
			while (!isSpaceChar(c)) {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = read();
			}
		}
		return res * sgn;
	}

	public int[] readIntArray(int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = readInt();
		return array;
	}

	public long[] readLongArray(int size) {
		long[] array = new long[size];
		for (int i = 0; i < size; i++)
			array[i] = readLong();
		return array;
	}

	public double[] readDoubleArray(int size) {
		double[] array = new double[size];
		for (int i = 0; i < size; i++)
			array[i] = readDouble();
		return array;
	}

	public String[] readStringArray(int size) {
		String[] array = new String[size];
		for (int i = 0; i < size; i++)
			array[i] = readString();
		return array;
	}

	public char[][] readTable(int rowCount, int columnCount) {
		char[][] table = new char[rowCount][columnCount];
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++)
				table[i][j] = readCharacter();
		}
		return table;
	}

	public void readIntArrays(int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = readInt();
		}
	}

	public boolean isFinished() {
		return finished;
	}

	public void setFinished(boolean finished) {
		this.finished = finished;
	}

	public abstract void close();

	public int[][] readIntTable(int rowCount, int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readIntArray(columnCount);
		return table;
	}

	public String readText() {
		StringBuilder result = new StringBuilder();
		while (true) {
			int character = read();
			if (character == '\r')
				continue;
			if (character == -1)
				break;
			result.append((char) character);
		}
		return result.toString();
	}

	public long[][] readLongTable(int rowCount, int columnCount) {
		long[][] table = new long[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readLongArray(columnCount);
		return table;
	}

	public String[][] readStringTable(int rowCount, int columnCount) {
		String[][] table = new String[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readStringArray(columnCount);
		return table;
	}

	public void readDoubleArrays(double[]...arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = readDouble();
		}
	}
}

class Exit {
	private Exit() {
	}

	public static void exit(InputReader in, PrintWriter out) {
		in.setFinished(true);
		in.close();
		out.close();
	}
}

class StreamInputReader extends InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar, numChars;

	public StreamInputReader(InputStream stream) {
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

	@Override
	public void close() {
		try {
			stream.close();
		} catch (IOException ignored) {
		}
	}
}

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
}

class CollectionUtils {
	public static int[] toArray(Collection<Integer> collection) {
		int[] array = new int[collection.size()];
		int index = 0;
		for (int element : collection)
			array[index++] = element;
		return array;
	}

	public static List<Integer> range(int from, int to) {
		List<Integer> result = new ArrayList<Integer>(Math.max(from, to) - Math.min(from, to) + 1);
		if (to > from) {
			for (int i = from; i <= to; i++)
				result.add(i);
		} else {
			for (int i = from; i >= to; i--)
				result.add(i);
		}
		return result;
	}

	public static void rotate(List<Integer> list) {
		list.add(list.remove(0));
	}

	public static List<Integer> increment(List<Integer> path) {
		return Transformer.transform(path, new Transformer<Integer>() {
			@Override
			public Integer transform(Integer value) {
				return value + 1;
			}
		});
	}

	public static<T extends Comparable<T>> T minElement(Iterable<T> collection) {
		T result = null;
		for (T element : collection) {
			if (result == null || result.compareTo(element) > 0)
				result = element;
		}
		return result;
	}

	public static<T extends Comparable<T>> T maxElement(Iterable<T> collection) {
		T result = null;
		for (T element : collection) {
			if (result == null || result.compareTo(element) < 0)
				result = element;
		}
		return result;
	}

	public static<T> List<T> asList(Iterable<T> iterable) {
		List<T> list = new ArrayList<T>();
		for (T element : iterable)
			list.add(element);
		return list;
	}

	public static<T> int count(Iterable<T> array, T sample) {
		int result = 0;
		for (T element : array) {
			if (element.equals(sample))
				result++;
		}
		return result;
	}
}

interface Factory<V> {
	public V create();
}

interface Operation<V> extends Factory<V> {
	public V operation(V first, V second);
}

class MiscUtils {
	public static final int[] DX_4_CONNECTED = {1, 0, -1, 0};
	public static final int[] DY_4_CONNECTED = {0, -1, 0, 1};

	public static long josephProblem(long n, int k) {
		if (n == 1)
			return 0;
		if (k == 1)
			return n - 1;
		if (k > n)
			return (josephProblem(n - 1, k) + k) % n;
		long count = n / k;
		long result = josephProblem(n - count, k);
		result -= n % k;
		if (result < 0)
			result += n;
		else
			result += result / (k - 1);
		return result;
	}

	public static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
		return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
	}

	public static List<Integer> getPath(int[] last, int destination) {
		List<Integer> path = new ArrayList<Integer>();
		while (destination != -1) {
			path.add(destination);
			destination = last[destination];
		}
		Collections.reverse(path);
		return path;
	}

	public static List<Integer> getPath(int[][] lastIndex, int[][] lastPathNumber, int destination, int pathNumber) {
		List<Integer> path = new ArrayList<Integer>();
		while (destination != -1 || pathNumber != 0) {
			path.add(destination);
			int nextDestination = lastIndex[destination][pathNumber];
			pathNumber = lastPathNumber[destination][pathNumber];
			destination = nextDestination;
		}
		Collections.reverse(path);
		return path;
	}

	public static long maximalRectangleSum(long[][] array) {
		int n = array.length;
		int m = array[0].length;
		long[][] partialSums = new long[n + 1][m + 1];
		for (int i = 0; i < n; i++) {
			long rowSum = 0;
			for (int j = 0; j < m; j++) {
				rowSum += array[i][j];
				partialSums[i + 1][j + 1] = partialSums[i][j + 1] + rowSum;
			}
		}
		long result = Long.MIN_VALUE;
		for (int i = 0; i < m; i++) {
			for (int j = i; j < m; j++) {
				long minPartialSum = 0;
				for (int k = 1; k <= n; k++) {
					long current = partialSums[k][j + 1] - partialSums[k][i];
					result = Math.max(result, current - minPartialSum);
					minPartialSum = Math.min(minPartialSum, current);
				}
			}
		}
		return result;
	}

	public static int parseIP(String ip) {
		String[] components = ip.split("[.]");
		int result = 0;
		for (int i = 0; i < 4; i++)
			result += (1 << (24 - 8 * i)) * Integer.parseInt(components[i]);
		return result;
	}
}

interface PowerOperation<V> extends Operation<V> {
	public V power(V base, int exponent);
}

class CPPMap<K, V> extends HashMap<K, V> {
	private final Factory<V> defaultValueFactory;

	public CPPMap(Factory<V> defaultValueFactory) {
		this.defaultValueFactory = defaultValueFactory;
	}

	@Override
	public V get(Object key) {
		if (containsKey(key))
			return super.get(key);
		V value = defaultValueFactory.create();
		try {
			//noinspection unchecked
			super.put((K) key, value);
			return value;
		} catch (ClassCastException e) {
			return value;
		}
	}
}

class MultiSet<K> implements Iterable<K> {
	private final Map<K, Integer> map;
	private int size = 0;

	public MultiSet() {
		this(new HashMap<K, Integer>());
	}

	public MultiSet(Map<K, Integer> underlying) {
		map = underlying;
	}

	public int size() {
		return size;
	}

	public int entryCount() {
		return map.size();
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public boolean contains(K key) {
		return map.containsKey(key);
	}

	public int add(K key) {
		Integer value = map.get(key);
		if (value == null)
			value = 0;
		value++;
		size++;
		map.put(key, value);
		return value;
	}

	public int remove(K key) {
		Integer value = map.get(key);
		if (value == null)
			return 0;
		value--;
		size--;
		if (value == 0)
			map.remove(key);
		else
			map.put(key, value);
		return value + 1;
	}

	public int removeAll(K key) {
		int value = map.remove(key);
		size -= value;
		return value;
	}

	public int get(K key) {
		Integer value = map.get(key);
		if (value == null)
			value = 0;
		return value;
	}

	public void clear() {
		map.clear();
		size = 0;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		MultiSet multiSet = (MultiSet) o;

		return !(map != null ? !map.equals(multiSet.map) : multiSet.map != null);

	}

	@Override
	public int hashCode() {
		return map.hashCode();
	}

	public Iterator<K> iterator() {
		return map.keySet().iterator();
	}
}

class Pair<U, V> {
	public static Pair<Long, Long>[] readArray(int n, InputReader in) {
		@SuppressWarnings({"unchecked"})
		Pair<Long, Long>[] result = new Pair[n];
		for (int i = 0; i < n; i++)
			result[i] = readPair(in);
		return result;
	}

	public static Pair<Long, Long> readPair(InputReader in) {
		long first = in.readLong();
		long second = in.readLong();
		return new Pair<Long, Long>(first, second);
	}

	public static class Comparator<U extends Comparable<U>, V extends Comparable<V>> implements java.util.Comparator<Pair<U, V>> {
		public int compare(Pair<U, V> o1, Pair<U, V> o2) {
			int result = o1.first.compareTo(o2.first);
			if (result != 0)
				return result;
			return o1.second.compareTo(o2.second);
		}
	}

	private final U first;
	private final V second;

	public Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	public U first() {
		return first;
	}

	public V second() {
		return second;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

	}

	@Override
	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	public Pair<V, U> swap() {
		//noinspection unchecked
		return new Pair<V, U>(second, first);
	}

	@Override
	public String toString() {
		return "(" + first + "," + second + ")";
	}
}

abstract class ArrayWrapper<T> implements Iterable<T> {
	protected final int from;
	protected final int to;
	protected final int size;
	protected final Object underlying;

	public static<T> ArrayWrapper<T> wrap(T[] array) {
		return new ReferenceArrayWrapper<T>(array);
	}

	public static<T> ArrayWrapper<T> wrap(List<T> list) {
		return new ListWrapper<T>(list);
	}

	public static ArrayWrapper<Integer> wrap(int[] array) {
		return new IntArrayWrapper(array);
	}

	public static ArrayWrapper<Long> wrap(long[] array) {
		return new LongArrayWrapper(array);
	}

	public static ArrayWrapper<Character> wrap(char[] array) {
		return new CharArrayWrapper(array);
	}

	protected ArrayWrapper(Object underlying, int from, int to) {
		this.underlying = underlying;
		this.from = from;
		this.to = to;
		size = to - from;
	}

	protected abstract ArrayWrapper<T> subArrayImpl(int from, int to);

	public ArrayWrapper<T> subArray(int from) {
		return subArray(from, size);
	}

	public ArrayWrapper<T> subArray(int from, int to) {
		if (from < 0)
			from += size;
		if (to < 0)
			to += size;
		return subArrayImpl(from, to);
	}


	public int size() {
		return size;
	}

	public boolean contains(T o) {
		return indexOf(o) != -1;
	}

	public Iterator<T> iterator() {
		return new ArrayIterator();
	}

	public boolean containsAll(Iterable<? extends T> c) {
		for (T o : c) {
			if (!contains(o))
				return false;
		}
		return true;
	}

	public int indexOf(T o) {
		for (int i = 0; i < size; i++) {
			if (get(i).equals(o))
				return i;
		}
		return -1;
	}

	public abstract T get(int index);

	public abstract void set(int index, T value);

	public int lastIndexOf(T o) {
		for (int i = size - 1; i >= 0; i--) {
			if (get(i).equals(o))
				return i;
		}
		return -1;
	}

	public boolean isEmpty() {
		return size == 0;
	}

	private class ArrayIterator implements Iterator<T> {
		private int index = 0;

		protected ArrayIterator() {
		}

		public boolean hasNext() {
			return index < size;
		}

		public T next() {
			return get(index++);
		}

		public void remove() {
			throw new UnsupportedOperationException();
		}
	}

	protected static class ReferenceArrayWrapper<T> extends ArrayWrapper<T> {
		protected final T[] array;

		protected ReferenceArrayWrapper(T[] array) {
			this(array, 0, array.length);
		}

		protected ReferenceArrayWrapper(T[] array, int from, int to) {
			super(array, from, to);
			this.array = array;
		}

		public T get(int index) {
			return array[index + from];
		}

		public void set(int index, T element) {
			array[index + from] = element;
		}

		protected ArrayWrapper<T> subArrayImpl(int fromIndex, int toIndex) {
			return new ReferenceArrayWrapper<T>(array, fromIndex + from, toIndex + from);
		}
	}

	protected static class ListWrapper<T> extends ArrayWrapper<T> {
		protected final List<T> list;

		protected ListWrapper(List<T> list) {
			this(list, 0, list.size());
		}

		protected ListWrapper(List<T> list, int from, int to) {
			super(list, from, to);
			this.list = list;
		}

		public T get(int index) {
			return list.get(index + from);
		}

		public void set(int index, T element) {
			list.set(index + from, element);
		}

		protected ArrayWrapper<T> subArrayImpl(int fromIndex, int toIndex) {
			return new ListWrapper<T>(list, fromIndex + from, toIndex + from);
		}
	}

	protected static class IntArrayWrapper extends ArrayWrapper<Integer> {
		protected final int[] array;

		protected IntArrayWrapper(int[] array) {
			this(array, 0, array.length);
		}

		protected IntArrayWrapper(int[] array, int from, int to) {
			super(array, from, to);
			this.array = array;
		}

		public Integer get(int index) {
			return array[index + from];
		}

		public void set(int index, Integer element) {
			array[index + from] = element;
		}

		protected ArrayWrapper<Integer> subArrayImpl(int fromIndex, int toIndex) {
			return new IntArrayWrapper(array, fromIndex + from, toIndex + from);
		}
	}

	protected static class LongArrayWrapper extends ArrayWrapper<Long> {
		protected final long[] array;

		protected LongArrayWrapper(long[] array) {
			this(array, 0, array.length);
		}

		protected LongArrayWrapper(long[] array, int from, int to) {
			super(array, from, to);
			this.array = array;
		}

		public Long get(int index) {
			return array[index + from];
		}

		public void set(int index, Long element) {
			array[index + from] = element;
		}

		protected ArrayWrapper<Long> subArrayImpl(int fromIndex, int toIndex) {
			return new LongArrayWrapper(array, fromIndex + from, toIndex + from);
		}
	}

	protected static class CharArrayWrapper extends ArrayWrapper<Character> {
		protected final char[] array;

		protected CharArrayWrapper(char[] array) {
			this(array, 0, array.length);
		}

		protected CharArrayWrapper(char[] array, int from, int to) {
			super(array, from, to);
			this.array = array;
		}

		public Character get(int index) {
			return array[index + from];
		}

		public void set(int index, Character element) {
			array[index + from] = element;
		}

		protected ArrayWrapper<Character> subArrayImpl(int fromIndex, int toIndex) {
			return new CharArrayWrapper(array, fromIndex + from, toIndex + from);
		}
	}
}

abstract class Transformer<T> {
	public abstract T transform(T value);

	public static<T> List<T> transform(List<T> list, Transformer<T> transformer) {
		int size = list.size();
		for (int i = 0; i < size; i++)
			list.set(i, transformer.transform(list.get(i)));
		return list;
	}

	public static<T> T[] transform(T[] array, Transformer<T> transformer) {
		int size = array.length;
		for (int i = 0; i < size; i++)
			array[i] = transformer.transform(array[i]);
		return array;
	}

	public static<T>ArrayWrapper<T> transform(ArrayWrapper<T> array, Transformer<T> transformer) {
		int size = array.size();
		for (int i = 0; i < size; i++)
			array.set(i, transformer.transform(array.get(i)));
		return array;
	}
}

abstract class Filter<T> {
	public abstract boolean accept(T element);

	public static<T> List<T> filter(Iterable<T> iterable, Filter<T> filter) {
		List<T> result = new ArrayList<T>();
		for (T element : iterable) {
			if (filter.accept(element))
				result.add(element);
		}
		return result;
	}

	public static<T> List<T> filter(T[] array, Filter<T> filter) {
		List<T> result = new ArrayList<T>();
		for (T element : array) {
			if (filter.accept(element))
				result.add(element);
		}
		return result;
	}
}

abstract class Function<A, V> {
	public static<A, V> List<V> apply(Iterable<A> collection, Function<A, V> function) {
		List<V> result = new ArrayList<V>();
		for (A argument : collection)
			result.add(function.value(argument));
		return result;
	}

	public abstract V value(A argument);
}

class CPPTreeMap<K, V> extends TreeMap<K, V> {
	private final Factory<V> defaultValueFactory;

	public CPPTreeMap(Factory<V> defaultValueFactory) {
		this.defaultValueFactory = defaultValueFactory;
	}

	@Override
	public V get(Object key) {
		if (containsKey(key))
			return super.get(key);
		V value = defaultValueFactory.create();
		try {
			//noinspection unchecked
			super.put((K) key, value);
			return value;
		} catch (ClassCastException e) {
			return value;
		}
	}
}

class SumIntervalTree {
	private int[] left;
	private int[] right;
	private long[] value;
	private long[] delta;

	public SumIntervalTree(int size) {
		int arraysSize = Integer.highestOneBit(size) * 4;
		left = new int[arraysSize];
		right = new int[arraysSize];
		value = new long[arraysSize];
		delta = new long[arraysSize];
		initTree(0, size, 0);
	}

	private void initTree(int left, int right, int root) {
		this.left[root] = left;
		this.right[root] = right;
		if (right - left > 1) {
			initTree(left, (left + right + 1) / 2, 2 * root + 1);
			initTree((left + right + 1) / 2, right, 2 * root + 2);
		}
	}
	
	public void putSegment(int left, int right, long value) {
		putSegment(left, right, value, 0);
	}

	private void putSegment(int left, int right, long value, int root) {
		if (left >= this.right[root] || right <= this.left[root])
			return;
		this.value[root] += value * intersection(left, right, root);
		if (left <= this.left[root] && right >= this.right[root]) {
			this.delta[root] += value;
			return;
		}
		putSegment(left, right, value, 2 * root + 1);
		putSegment(left, right, value, 2 * root + 2);
	}

	private int intersection(int left, int right, int root) {
		return Math.min(right, this.right[root]) - Math.max(left, this.left[root]);
	}

	public void put(int position, long value) {
		put(position, value, 0);
	}

	private void put(int position, long value, int root) {
		if (left[root] > position || right[root] <= position)
			return;
		this.value[root] += value;
		if (right[root] - left[root] > 1) {
			put(position, value, 2 * root + 1);
			put(position, value, 2 * root + 2);
		} else
			this.delta[root] += value;
	}

	public long get(int position) {
		return get(position, 0);
	}

	private long get(int position, int root) {
		if (position >= right[root] || position < left[root])
			return 0;
		if (right[root] - left[root] == 1)
			return value[root];
		return delta[root] + get(position, 2 * root + 1) + get(position, 2 * root + 2);
	}

	public long getSegment(int left, int right) {
		return getSegment(left, right, 0);
	}

	private long getSegment(int left, int right, int root) {
		if (left >= this.right[root] || right <= this.left[root])
			return 0;
		if (left <= this.left[root] && right >= this.right[root])
			return value[root];
		return getSegment(left, right, 2 * root + 1) + getSegment(left, right, 2 * root + 2) + delta[root] *
			intersection(left, right, root);
	}
}

class IntervalTree<V> {
	protected int[] left;
	protected int[] right;
	protected Object[] value;
	protected Object[] delta;
	private final PowerOperation<V> operation;

	public IntervalTree(int size, PowerOperation<V> operation) {
		this.operation = operation;
		int arraysSize = Integer.highestOneBit(size) * 4;
		left = new int[arraysSize];
		right = new int[arraysSize];
		value = new Object[arraysSize];
		delta = new Object[arraysSize];
		initTree(0, size, 0);
	}

	private void initTree(int left, int right, int root) {
		this.left[root] = left;
		this.right[root] = right;
		this.value[root] = operation.create();
		this.delta[root] = operation.create();
		if (right - left > 1) {
			initTree(left, (left + right + 1) / 2, 2 * root + 1);
			initTree((left + right + 1) / 2, right, 2 * root + 2);
		}
	}

	public void putSegment(int left, int right, V value) {
		putSegment(left, right, value, 0);
	}

	private void putSegment(int left, int right, V value, int root) {
		if (left >= this.right[root] || right <= this.left[root])
			return;
		this.value[root] = operation.operation((V) this.value[root],
			operation.power(value, intersection(left, right, root)));
		if (left <= this.left[root] && right >= this.right[root]) {
			this.delta[root] = operation.operation((V) this.delta[root], value);
			return;
		}
		putSegment(left, right, value, 2 * root + 1);
		putSegment(left, right, value, 2 * root + 2);
	}

	private int intersection(int left, int right, int root) {
		return Math.min(right, this.right[root]) - Math.max(left, this.left[root]);
	}

	public void put(int position, V value) {
		put(position, value, 0);
	}

	private void put(int position, V value, int root) {
		if (left[root] > position || right[root] <= position)
			return;
		this.value[root] = operation.operation((V) this.value[root], value);
		if (right[root] - left[root] > 1) {
			put(position, value, 2 * root + 1);
			put(position, value, 2 * root + 2);
		} else
			this.delta[root] = operation.operation((V) this.delta[root], value);
	}

	public V get(int position) {
		return get(position, 0);
	}

	private V get(int position, int root) {
		if (position >= right[root] || position < left[root])
			return operation.create();
		if (right[root] - left[root] == 1)
			return (V) value[root];
		return operation.operation(operation.operation(get(position, 2 * root + 1), get(position, 2 * root + 2)),
			(V) delta[root]);
	}

	public V getSegment(int left, int right) {
		return getSegment(left, right, 0);
	}

	private V getSegment(int left, int right, int root) {
		if (left >= this.right[root] || right <= this.left[root])
			return operation.create();
		if (left <= this.left[root] && right >= this.right[root])
			return (V) value[root];
		return operation.operation(operation.operation(getSegment(left, right, 2 * root + 1),
			getSegment(left, right, 2 * root + 2)),
			operation.power((V) delta[root], intersection(left, right, root)));
	}
}

class ArrayUtils {
	public static Integer[] generateOrder(int size) {
		Integer[] order = new Integer[size];
		for (int i = 0; i < size; i++)
			order[i] = i;
		return order;
	}

	public static<T extends Comparable<T>> int minIndex(ArrayWrapper<T> array) {
		return array.indexOf(CollectionUtils.minElement(array));
	}

	public static<T extends Comparable<T>> int maxIndex(ArrayWrapper<T> array) {
		return array.indexOf(CollectionUtils.maxElement(array));
	}

	public static<T> void fill(ArrayWrapper<T> array, T value) {
		for (int i = 0; i < array.size(); i++)
			array.set(i, value);			
	}

	public static<T> void fill(ArrayWrapper<T> array, Factory<T> factory) {
		for (int i = 0; i < array.size(); i++)
			array.set(i, factory.create());
	}

	public static void fill(long[][] array, long value) {
		for (long[] row : array)
			Arrays.fill(row, value);
	}

	public static void fillColumn(long[][] array, int index, long value) {
		for (long[] row : array)
			row[index] = value;
	}

	public static void fillColumn(int[][] array, int index, int value) {
		for (int[] row : array)
			row[index] = value;
	}

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	public static void fill(boolean[][] array, boolean value) {
		for (boolean[] row : array)
			Arrays.fill(row, value);
	}

	public static<T extends Comparable<T>> long countUnorderedPairs(final ArrayWrapper<T> array) {
		long result = 0;
		Integer[] order = generateOrder(array.size());
		Arrays.sort(order, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return array.get(o1).compareTo(array.get(o2));
			}
		});
		SumIntervalTree tree = new SumIntervalTree(array.size());
		for (int i : order) {
			result += i - tree.getSegment(0, i);
			tree.put(i, 1);
		}
		return result;
	}

	public static<T extends Comparable<T>> boolean nextPermutation(ArrayWrapper<T> array) {
		for (int i = array.size() - 2; i >= 0; i--) {
			if (array.get(i).compareTo(array.get(i + 1)) < 0) {
				int index = i + 1;
				for (int j = i + 2; j < array.size(); j++) {
					if (array.get(i).compareTo(array.get(j)) >= 0)
						break;
					else
						index = j;
				}
				T temp = array.get(i);
				array.set(i, array.get(index));
				array.set(index, temp);
				sort(array.subArray(i + 1));
				return true;
			}
		}
		return false;
	}

	public static long sumArray(int[] array) {
		long result = 0;
		for (int element : array)
			result += element;
		return result;
	}

	public static int[] range(int from, int to) {
		int[] result = new int[Math.max(from, to) - Math.min(from, to) + 1];
		int index = 0;
		if (to > from) {
			for (int i = from; i <= to; i++)
				result[index++] = i;
		} else {
			for (int i = from; i >= to; i--)
				result[index++] = i;
		}
		return result;
	}

	@SuppressWarnings({"unchecked"})
	public static<T extends Comparable<T>> ArrayWrapper<T> sort(ArrayWrapper<T> array) {
		Object underlying = array.underlying;
		if (underlying instanceof char[])
			Arrays.sort((char[]) underlying, array.from, array.to);
		else if (underlying instanceof int[])
			Arrays.sort((int[]) underlying, array.from, array.to);
		else if (underlying instanceof long[])
			Arrays.sort((long[]) underlying, array.from, array.to);
		else if (underlying instanceof Object[])
			Arrays.sort((T[]) underlying, array.from, array.to);
		else if (underlying instanceof List)
			Collections.sort(((List<T>) underlying).subList(array.from, array.to));
		else
			throw new IllegalArgumentException();
		return array;
	}

	@SuppressWarnings({"unchecked", "RedundantCast"})
	public static<T> ArrayWrapper<T> sort(ArrayWrapper<T> array, Comparator<? super T> comparator) {
		Object underlying = array.underlying;
		if (underlying instanceof char[]) {
			Character[] copy = new Character[array.size];
			for (int i = 0, j = array.from; i < array.size; i++, j++)
				copy[i] = ((char[])underlying)[j];
			Arrays.sort(copy, (Comparator<? super Character>) comparator);
			for (int i = 0, j = array.from; i < array.size; i++, j++)
				((char[])underlying)[j] = copy[i];
		} else if (underlying instanceof int[]) {
			Integer[] copy = new Integer[array.size];
			for (int i = 0, j = array.from; i < array.size; i++, j++)
				copy[i] = ((int[])underlying)[j];
			Arrays.sort(copy, (Comparator<? super Integer>) comparator);
			for (int i = 0, j = array.from; i < array.size; i++, j++)
				((int[])underlying)[j] = copy[i];
		} else if (underlying instanceof long[]) {
			Long[] copy = new Long[array.size];
			for (int i = 0, j = array.from; i < array.size; i++, j++)
				copy[i] = ((long[])underlying)[j];
			Arrays.sort(copy, (Comparator<? super Long>) comparator);
			for (int i = 0, j = array.from; i < array.size; i++, j++)
				((long[])underlying)[j] = copy[i];
		} else if (underlying instanceof Object[])
			Arrays.sort((T[]) underlying, array.from, array.to, comparator);
		else if (underlying instanceof List)
			Collections.sort(((List<T>) underlying).subList(array.from, array.to), comparator);
		else
			throw new IllegalArgumentException();
		return array;
	}

	public static<T> boolean isSubSequence(ArrayWrapper<T> array, ArrayWrapper<T> sample) {
		int index = 0;
		for (T element : array) {
			if (element.equals(sample.get(index))) {
				if (++index == sample.size)
					return true;
			}
		}
		return false;
	}

	public static Integer[] order(int size, Comparator<Integer> comparator) {
		Integer[] order = generateOrder(size);
		Arrays.sort(order, comparator);
		return order;
	}

	public static<T extends Comparable> Integer[] order(final ArrayWrapper<T> array) {
		return order(array.size, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return array.get(o1).compareTo(array.get(o2));
			}
		});
	}

	public static void fill(int[][][] array, int value) {
		for (int[][] subArray : array)
			fill(subArray, value);
	}
}

class Rational implements Comparable<Rational> {
	private final long numerator;
	private final long denominator;
	public static final Rational MAX_VALUE = new Rational(Integer.MAX_VALUE, 1);

	public Rational(long numerator, long denominator) {
		if (denominator == 0)
			throw new IllegalArgumentException();
		long gcd = IntegerUtils.gcd(Math.abs(numerator), Math.abs(denominator));
		if (denominator > 0) {
			this.numerator = numerator / gcd;
			this.denominator = denominator / gcd;
		} else {
			this.numerator = -numerator / gcd;
			this.denominator = -denominator / gcd;
		}
	}

	public long getNumerator() {
		return numerator;
	}

	public long getDenominator() {
		return denominator;
	}

	@Override
	public String toString() {
		return numerator + "/" + denominator;
	}

	public int compareTo(Rational other) {
		return IntegerUtils.longCompare(numerator * other.denominator, denominator * other.numerator);
	}
}

class DoubleUtils {
	public static double sumGeometricProgression(double p, double q) {
		return p / (1 - q);
	}
}

class IntegerUtils {
	public static long gcd(long a, long b) {
		while (b != 0) {
			long temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}

	public static int[] generatePrimes(int upTo) {
		boolean[] isPrime = generatePrimalityTable(upTo);
		List<Integer> primes = new ArrayList<Integer>();
		for (int i = 0; i < upTo; i++) {
			if (isPrime[i])
				primes.add(i);
		}
		return CollectionUtils.toArray(primes);
	}

	public static boolean[] generatePrimalityTable(int upTo) {
		boolean[] isPrime = new boolean[upTo];
		Arrays.fill(isPrime, true);
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i * i < upTo; i++) {
			if (isPrime[i]) {
				for (int j = i * i; j < upTo; j += i)
					isPrime[j] = false;
			}
		}
		return isPrime;
	}

	public static int[] generateDivisorTable(int upTo) {
		int[] divisor = new int[upTo];
		for (int i = 1; i < upTo; i++)
			divisor[i] = i;
		for (int i = 2; i * i < upTo; i++) {
			if (divisor[i] == i) {
				for (int j = i * i; j < upTo; j += i)
					divisor[j] = i;
			}
		}
		return divisor;
	}

	public static long powerInFactorial(long n, long p) {
		long result = 0;
		while (n != 0) {
			result += n /= p;
		}
		return result;
	}

	public static int sumDigits(CharSequence number) {
		int result = 0;
		for (int i = number.length() - 1; i >= 0; i--)
			result += digitValue(number.charAt(i));
		return result;
	}

	public static int digitValue(char digit) {
		if (Character.isDigit(digit))
			return digit - '0';
		if (Character.isUpperCase(digit))
			return digit + 10 - 'A';
		return digit + 10 - 'a';
	}

	public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	public static long[][] generateBinomialCoefficients(int n) {
		long[][] result = new long[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			result[i][0] = 1;
			for (int j = 1; j <= i; j++)
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
		return result;
	}

	public static int[] representationInBase(long number, int base) {
		long basePower = base;
		int exponent = 1;
		while (number >= basePower) {
			basePower *= base;
			exponent++;
		}
		int[] representation = new int[exponent];
		for (int i = 0; i < exponent; i++) {
			basePower /= base;
			representation[i] = (int) (number / basePower);
			number %= basePower;
		}
		return representation;
	}

	public static int trueDivide(int a, int b) {
		return (a - trueMod(a, b)) / b;
	}

	public static int trueMod(int a, int b) {
		a %= b;
		a += b;
		a %= b;
		return a;
	}
}

abstract class MultiplicativeFunction {
	public static final MultiplicativeFunction DIVISOR_COUNT = new MultiplicativeFunction() {
		@Override
		protected long value(long p, int exponent, long power) {
			return exponent + 1;
		}
	};

	public static final MultiplicativeFunction DIVISOR_SUM = new MultiplicativeFunction() {
		@Override
		protected long value(long p, int exponent, long power) {
			return (power * p - 1) / (p - 1);
		}
	};

	public static final MultiplicativeFunction PHI = new MultiplicativeFunction() {
		@Override
		protected long value(long p, int exponent, long power) {
			return power / p * (p - 1);
		}
	};

	public static final MultiplicativeFunction MOBIUS = new MultiplicativeFunction() {
		@Override
		protected long value(long p, int exponent, long power) {
			return exponent == 1 ? -1 : 0;
		}
	};

	protected abstract long value(long p, int exponent, long power);

	public long calculate(long argument) {
		long value = 1;
		for (long i = 2; i * i <= argument; i++) {
			if (argument % i == 0) {
				int exponent = 0;
				long power = 0;
				do {
					exponent++;
					power *= i;
					argument /= i;
				} while (argument % i == 0);
				value *= value(i, exponent, power);
			}
		}
		if (argument != 1)
			value *= value(argument, 1, argument);
		return value;
	}

	public long[] calculateUpTo(int upTo) {
		int[] divisor = IntegerUtils.generateDivisorTable(upTo);
		long[] result = new long[upTo];
		result[1] = 1;
		for (int i = 2; i < upTo; i++) {
			int iDivided = i;
			int exponent = 0;
			do {
				iDivided /= divisor[i];
				exponent++;
			} while (iDivided % divisor[i] == 0);
			result[i] = result[iDivided] * value(divisor[i], exponent, i / iDivided);
		}
		return result;
	}
}

class TaskE implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int n = in.readInt();
		int x = in.readInt();
		int[] a = in.readIntArray(n);
		if (x == 2) {
			out.println(0);
			return;
		}
		if (n == 0) {
			out.println(-1);
			return;
		}
		Arrays.sort(a);
		if (a[0] == 1) {
			out.println(1);
			return;
		}
		int[] primes = IntegerUtils.generatePrimes(Math.min(1300000, x));
		if (ArrayUtils.isSubSequence(ArrayWrapper.wrap(a), ArrayWrapper.wrap(primes)))
			out.println(primes.length);
		else
			out.println(-1);
	}
}