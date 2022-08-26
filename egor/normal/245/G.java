import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.AbstractSet;
import java.util.Set;
import java.util.Iterator;
import java.util.AbstractMap;
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
		TaskG solver = new TaskG();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int edgeCount = in.readInt();
		int[] from = new int[edgeCount];
		int[] to = new int[edgeCount];
		Indexer<String> indexer = new Indexer<String>();
		for (int i = 0; i < edgeCount; i++) {
			from[i] = indexer.get(in.readString());
			to[i] = indexer.get(in.readString());
		}
		int count = indexer.size();
		int[][] graph = GraphUtils.buildSimpleGraph(count, from, to);
		short[][] common = new short[count][];
		for (int i = 0; i < count; i++)
			common[i] = new short[i];
		for (int[] row : graph) {
			for (int i : row) {
				for (int j : row) {
					if (i == j)
						break;
					if (i > j)
						common[i][j]++;
					else
						common[j][i]++;
				}
			}
		}
		for (int i = 0; i < edgeCount; i++) {
			if (from[i] > to[i])
				common[from[i]][to[i]] = -1;
			else
				common[to[i]][from[i]] = -1;
		}
		String[] byIndex = new String[count];
		for (String s : indexer.keySet())
			byIndex[indexer.get(s)] = s;
		out.printLine(count);
		for (int i = 0; i < count; i++) {
			int max = 0;
			int maxQty = 0;
			for (int j = 0; j < i; j++) {
				if (common[i][j] > max) {
					max = common[i][j];
					maxQty = 1;
				} else if (common[i][j] == max)
					maxQty++;
			}
			for (int j = i + 1; j < count; j++) {
				if (common[j][i] > max) {
					max = common[j][i];
					maxQty = 1;
				} else if (common[j][i] == max)
					maxQty++;
			}
			out.printLine(byIndex[i], maxQty);
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

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
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

class Indexer<K> extends EHashMap<K, Integer> {
	private int index = 0;

	public Integer get(Object key) {
		if (!containsKey(key))
			put((K) key, index++);
		return super.get(key);
	}
}

class EHashMap<E, V> extends AbstractMap<E, V> {
	private static final int[] shifts = new int[10];

	private int size;
	private Object[] keys;
	private Object[] values;
	private int capacity;
	private int shift;
	private int[] indices;
	private Set<Entry<E, V>> entrySet;

	static {
		Random random = new Random(System.currentTimeMillis());
		for (int i = 0; i < 10; i++)
			shifts[i] = 1 + 3 * i + random.nextInt(3);
	}

	public EHashMap() {
		this(4);
	}

	private void setCapacity(int size) {
		capacity = Integer.highestOneBit(10 * size);
		keys = new Object[capacity];
		values = new Object[capacity];
		shift = capacity / 3 - 1;
		shift -= 1 - (shift & 1);
		indices = new int[capacity];
	}

	public EHashMap(int maxSize) {
		setCapacity(maxSize);
		entrySet = new AbstractSet<Entry<E, V>>() {
			@Override
			public Iterator<Entry<E, V>> iterator() {
				return new Iterator<Entry<E, V>>() {
					private HashEntry entry = new HashEntry();
					int index = 0;

					public boolean hasNext() {
						while (index < capacity && keys[index] == null)
							index++;
						return index < capacity;
					}

					public Entry<E, V> next() {
						if (!hasNext())
							throw new NoSuchElementException();
						entry.key = (E) keys[index];
						entry.value = (V) values[index++];
						return entry;
					}

					public void remove() {
						if (entry.key == null)
							throw new IllegalStateException();
						EHashMap.this.remove(entry.key);
						entry.key = null;
						entry.value = null;
					}
				};
			}

			@Override
			public int size() {
				return size;
			}
		};
	}

	public EHashMap(Map<E, V> map) {
		this(map.size());
		putAll(map);
	}

	public Set<Entry<E, V>> entrySet() {
		return entrySet;
	}

	public void clear() {
		Arrays.fill(keys, null);
		Arrays.fill(values, null);
		size = 0;
	}

	private int index(Object o) {
		return getHash(o.hashCode()) & (capacity - 1);
	}

	private int getHash(int h) {
		int result = h;
		for (int i : shifts)
			result ^= h >>> i;
		return result;
	}

	public V remove(Object o) {
		if (o == null)
			return null;
		int index = index(o);
		int indicesSize = 0;
		while (keys[index] != null && !keys[index].equals(o)) {
			indices[indicesSize++] = index;
			index = (index + shift) & (capacity - 1);
		}
		if (keys[index] == null)
			return null;
		size--;
		int lastIndex = indicesSize;
		indices[indicesSize++] = index;
		keys[index] = null;
		V result = (V) values[index];
		values[index] = null;
		index = (index + shift) & (capacity - 1);
		while (keys[index] != null) {
			int curKey = index(keys[index]);
			for (int i = 0; i <= lastIndex; i++) {
				if (indices[i] == curKey) {
					keys[indices[lastIndex]] = keys[index];
					values[indices[lastIndex]] = values[index];
					keys[index] = null;
					values[index] = null;
					lastIndex = indicesSize;
				}
			}
			indices[indicesSize++] = index;
			index = (index + shift) & (capacity - 1);
		}
		return result;
	}

	public V put(E e, V value) {
		if (e == null)
			return null;
		int index = index(e);
		while (keys[index] != null && !keys[index].equals(e))
			index = (index + shift) & (capacity - 1);
		if (keys[index] == null)
			size++;
		keys[index] = e;
		values[index] = value;
		if (size * 2 > capacity) {
			Object[] oldKeys = keys;
			Object[] oldValues = values;
			setCapacity(size);
			size = 0;
			for (int i = 0; i < oldKeys.length; i++) {
				if (oldKeys[i] != null)
					put((E) oldKeys[i], (V) oldValues[i]);
			}
		}
		return value;
	}

	public V get(Object o) {
		if (o == null)
			return null;
		int index = index(o);
		while (keys[index] != null && !keys[index].equals(o))
			index = (index + shift) & (capacity - 1);
		return (V) values[index];
	}

	public boolean containsKey(Object o) {
		if (o == null)
			return false;
		int index = index(o);
		while (keys[index] != null && !keys[index].equals(o))
			index = (index + shift) & (capacity - 1);
		return keys[index] != null;
	}

	public int size() {
		return size;
	}

	private class HashEntry implements Entry<E, V> {
		private E key;
		private V value;

		public E getKey() {
			return key;
		}

		public V getValue() {
			return value;
		}

		public V setValue(V value) {
			put(key, value);
			return this.value = value;
		}
	}
}

class GraphUtils {
	public static int[][] buildGraph(int vertexCount, int[] from, int[] to) {
		int edgeCount = from.length;
		int[] degree = new int[vertexCount];
		for (int i = 0; i < edgeCount; i++) {
			degree[from[i]]++;
			degree[to[i]]++;
		}
		int[][] graph = new int[vertexCount][];
		for (int i = 0; i < vertexCount; i++)
			graph[i] = new int[degree[i]];
		for (int i = 0; i < edgeCount; i++) {
			graph[from[i]][--degree[from[i]]] = i;
			graph[to[i]][--degree[to[i]]] = i;
		}
		return graph;
	}

	public static int otherVertex(int vertex, int from, int to) {
		return from + to - vertex;
	}

	public static int[][] buildSimpleGraph(int vertexCount, int[] from, int[] to) {
		int[][] graph = buildGraph(vertexCount, from, to);
		simplifyGraph(from, to, graph);
		return graph;
	}

	private static void simplifyGraph(int[] from, int[] to, int[][] graph) {
		for (int i = 0; i < graph.length; i++) {
			for (int j = 0; j < graph[i].length; j++) {
				graph[i][j] = otherVertex(i, from[graph[i][j]], to[graph[i][j]]);
			}
		}
	}
}