import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.util.Collections;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		int passed = in.readInt();
		char[][] map = IOUtils.readTable(in, rowCount, columnCount);
		Graph<Pair<Integer, Integer>> graph = new Graph<Pair<Integer, Integer>>();
		@SuppressWarnings("unchecked")
		Pair<Integer, Integer>[] junctions = new Pair[27];
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				if (Character.isDigit(map[i][j])) {
					int weight = map[i][j] - '0';
					for (int k = 0; k < 4; k++) {
						int row = i + MiscUtils.DX4[k];
						int column = j + MiscUtils.DY4[k];
						if (row >= 0 && row < rowCount && column >= 0 && column < columnCount && map[row][column] != '#')
							graph.addWeightedEdge(Pair.makePair(row, column), Pair.makePair(i, j), weight);
					}
					if (Character.isLetter(map[i][j]))
						junctions[map[i][j] - 'a'] = Pair.makePair(i, j);
				} else if (Character.isLetter(map[i][j]))
					junctions[map[i][j] - 'a'] = Pair.makePair(i, j);
			}
		}
		Pair<Integer, Integer> start = IOUtils.readIntPair(in);
		String path = in.readString();
		Pair<Integer, Integer> finish = IOUtils.readIntPair(in);
		junctions[26] = Pair.makePair(finish.first - 1, finish.second - 1);
		start = Pair.makePair(start.first - 1, start.second - 1);
		@SuppressWarnings("unchecked")
		Pair<Map<Pair<Integer, Integer>, Long>, Map<Pair<Integer, Integer>, Edge<Pair<Integer, Integer>>>>[] dijkstraResults = new Pair[27];
		for (int i = 0; i < 27; i++) {
			if (junctions[i] != null)
				dijkstraResults[i] = ShortestDistance.dijkstraAlgorithm(graph, junctions[i]);
		}
		path = path + ((char)('z' + 1));
		for (int i = 0; i < path.length(); i++) {
			int junction = path.charAt(i) - 'a';
			if (i != 0) {
				if (passed == 0) {
					out.printLine(start.first + 1, start.second + 1);
					return;
				}
				passed--;
				Pair<Integer, Integer> next = junctions[junction];
				if (next.first > start.first)
					start = Pair.makePair(start.first + 1, start.second);
				else if (next.first < start.first)
					start = Pair.makePair(start.first - 1, start.second);
				else if (next.second < start.second)
					start = Pair.makePair(start.first, start.second - 1);
				else
					start = Pair.makePair(start.first, start.second + 1);
			}
			if (dijkstraResults[junction].first.get(start) > passed) {
				while (true) {
					Edge<Pair<Integer, Integer>> edge = dijkstraResults[junction].second.get(start);
					if (edge.getWeight() > passed) {
						out.printLine(start.first + 1, start.second + 1);
						return;
					}
					passed -= edge.getWeight();
					start = edge.getSource();
				}
			}
			passed -= dijkstraResults[junction].first.get(start);
			start = junctions[junction];
		}
		out.printLine(finish.first, finish.second);
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
	public static Pair<Integer, Integer> readIntPair(InputReader in) {
		int first = in.readInt();
		int second = in.readInt();
		return Pair.makePair(first, second);
	}

	public static char[] readCharArray(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
		char[][] table = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readCharArray(in, columnCount);
		return table;
	}

	}

class Graph<V> {
	protected int vertexCount;
	protected int edgeCount;

	protected Map<V, Integer> map = new HashMap<V, Integer>();

	public V[] vertices;
	public int[] firstOutbound;
	public int[] firstInbound;

	public Edge<V>[] edges;
	public int[] nextInbound;
	public int[] nextOutbound;
	public int[] from;
	public int[] to;
	public long[] weight;
	public long[] capacity;
	public int[] reverseEdge;
	public boolean[] removed;

	public Graph() {
		this(10);
	}

	public Graph(int vertexCapacity) {
		this(vertexCapacity, vertexCapacity);
	}

	public Graph(int vertexCapacity, int edgeCapacity) {
		//noinspection unchecked
		vertices = (V[]) new Object[vertexCapacity];
		firstOutbound = new int[vertexCapacity];
		firstInbound = new int[vertexCapacity];

		//noinspection unchecked
		edges = new Edge[edgeCapacity];
		from = new int[edgeCapacity];
		to = new int[edgeCapacity];
		nextInbound = new int[edgeCapacity];
		nextOutbound = new int[edgeCapacity];
		weight = new long[edgeCapacity];
		capacity = new long[edgeCapacity];
		reverseEdge = new int[edgeCapacity];
		removed = new boolean[edgeCapacity];
	}

	public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
		ensureEdgeCapacity(edgeCount + 1);
		if (firstOutbound[fromID] != -1)
			nextOutbound[edgeCount] = firstOutbound[fromID];
		else
			nextOutbound[edgeCount] = -1;
		firstOutbound[fromID] = edgeCount;
		if (firstInbound[toID] != -1)
			nextInbound[edgeCount] = firstInbound[toID];
		else
			nextInbound[edgeCount] = -1;
		firstInbound[toID] = edgeCount;
		this.from[edgeCount] = fromID;
		this.to[edgeCount] = toID;
		this.weight[edgeCount] = weight;
		this.capacity[edgeCount] = capacity;
		this.reverseEdge[edgeCount] = reverseEdge;
		edges[edgeCount] = createEdge(edgeCount);
		return edgeCount++;
	}

	protected GraphEdge createEdge(int id) {
		return new GraphEdge(id);
	}

	public Edge<V> addFlowWeightedEdge(V from, V to, long weight, long capacity) {
		int fromID = resolveOrAdd(from);
		int toID = resolveOrAdd(to);
		if (capacity == 0) {
			int result = addEdge(fromID, toID, weight, 0, -1);
			return edges[result];
		} else {
			int lastEdgeCount = edgeCount;
			addEdge(toID, fromID, -weight, 0, lastEdgeCount + entriesPerEdge());
			int result = addEdge(fromID, toID, weight, capacity, lastEdgeCount);
			return edges[result];
		}
	}

	protected int entriesPerEdge() {
		return 1;
	}

	public Edge<V> addWeightedEdge(V from, V to, long weight) {
		return addFlowWeightedEdge(from, to, weight, 0);
	}

	public int getVertexCount() {
		return vertexCount;
	}

	public int resolve(V vertex) {
		if (map.containsKey(vertex))
			return map.get(vertex);
		throw new IllegalArgumentException();
	}

	public V getVertex(int id) {
		return vertices[id];
	}

	public Edge<V> getEdge(int id) {
		return edges[id];
	}

	private int resolveOrAdd(V vertex) {
		if (map.containsKey(vertex))
			return map.get(vertex);
		ensureVertexCapacity(vertexCount + 1);
		map.put(vertex, vertexCount);
		vertices[vertexCount] = vertex;
		firstInbound[vertexCount] = firstOutbound[vertexCount] = -1;
		return vertexCount++;
	}

	protected void ensureEdgeCapacity(int size) {
		if (from.length < size) {
			int newSize = Math.max(size, 2 * from.length);
			edges = resize(edges, newSize);
			from = resize(from, newSize);
			to = resize(to, newSize);
			nextInbound = resize(nextInbound, newSize);
			nextOutbound = resize(nextOutbound, newSize);
			weight = resize(weight, newSize);
			capacity = resize(capacity, newSize);
			reverseEdge = resize(reverseEdge, newSize);
			removed = resize(removed, newSize);
		}
	}

	protected void ensureVertexCapacity(int size) {
		if (firstInbound.length < size) {
			int newSize = Math.max(size, 2 * firstInbound.length);
			vertices = resize(vertices, newSize);
			firstInbound = resize(firstInbound, newSize);
			firstOutbound = resize(firstOutbound, newSize);
		}
	}

	protected int[] resize(int[] array, int size) {
		int[] newArray = new int[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	protected boolean[] resize(boolean[] array, int size) {
		boolean[] newArray = new boolean[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private long[] resize(long[] array, int size) {
		long[] newArray = new long[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private Edge<V>[] resize(Edge<V>[] array, int size) {
		@SuppressWarnings("unchecked")
		Edge<V>[] newArray = new Edge[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private V[] resize(V[] array, int size) {
		@SuppressWarnings("unchecked")
		V[] newArray = (V[]) new Object[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	public boolean isSparse() {
		return vertexCount == 0 || edgeCount * 20 / vertexCount <= vertexCount;
	}

	protected class GraphEdge implements Edge<V> {
		protected int id;

		protected GraphEdge(int id) {
			this.id = id;
		}

		public V getSource() {
			return vertices[from[id]];
		}

		public long getWeight() {
			return weight[id];
		}

		}

	}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

	}

	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	public String toString() {
		return "(" + first + "," + second + ")";
	}

	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>)first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>)second).compareTo(o.second);
	}
}

class MiscUtils {
	public static final int[] DX4 = {1, 0, -1, 0};
	public static final int[] DY4 = {0, -1, 0, 1};

	}

interface Edge<V> {
	public V getSource();
	public long getWeight();
	}

class ShortestDistance {
	public static<V> Pair<Map<V, Long>, Map<V, Edge<V>>> dijkstraAlgorithm(Graph<V> graph, V source) {
		Pair<long[], int[]> result = dijkstraAlgorithmByID(graph, graph.resolve(source));
		Map<V, Long> distance = new HashMap<V, Long>();
		Map<V, Edge<V>> last = new HashMap<V, Edge<V>>();
		for (int i = graph.getVertexCount() - 1; i >= 0; i--) {
			if (result.second[i] != -1) {
				distance.put(graph.getVertex(i), result.first[i]);
				last.put(graph.getVertex(i), graph.getEdge(result.second[i]));
			}
		}
		distance.put(source, 0L);
		return Pair.makePair(distance, last);
	}

	public static<V> Pair<long[], int[]> dijkstraAlgorithmByID(Graph<V> graph, int sourceID) {
		int vertexCount = graph.getVertexCount();
		final long[] distance = new long[vertexCount];
		int[] last = new int[vertexCount];
		Arrays.fill(distance, Long.MAX_VALUE);
		Arrays.fill(last, -1);
		distance[sourceID] = 0;
		if (graph.isSparse()) {
			Heap heap = new Heap(vertexCount, new IntComparator() {
				public int compare(int first, int second) {
					return IntegerUtils.longCompare(distance[first], distance[second]);
				}
			}, vertexCount);
			heap.add(sourceID);
			while (!heap.isEmpty()) {
				int current = heap.poll();
				int edgeID = graph.firstOutbound[current];
				while (edgeID != -1) {
					if (graph.removed[edgeID]) {
						edgeID = graph.nextOutbound[edgeID];
						continue;
					}
					int next = graph.to[edgeID];
					long total = graph.weight[edgeID] + distance[current];
					if (distance[next] > total) {
						distance[next] = total;
						if (heap.getIndex(next) == -1)
							heap.add(next);
						else
							heap.shiftUp(heap.getIndex(next));
						last[next] = edgeID;
					}
					edgeID = graph.nextOutbound[edgeID];
				}
			}
		} else {
			boolean[] visited = new boolean[vertexCount];
			for (int i = 0; i < vertexCount; i++) {
				int index = -1;
				long length = Long.MAX_VALUE;
				for (int j = 0; j < vertexCount; j++) {
					if (!visited[j] && distance[j] < length) {
						length = distance[j];
						index = j;
					}
				}
				if (index == -1)
					break;
				visited[index] = true;
				int edgeID = graph.firstOutbound[index];
				while (edgeID != -1) {
					if (graph.removed[edgeID]) {
						edgeID = graph.nextOutbound[edgeID];
						continue;
					}
					int next = graph.to[edgeID];
					if (visited[next]) {
						edgeID = graph.nextOutbound[edgeID];
						continue;
					}
					long total = graph.weight[edgeID] + length;
					if (distance[next] > total) {
						distance[next] = total;
						last[next] = edgeID;
					}
					edgeID = graph.nextOutbound[edgeID];
				}
			}
		}
		return Pair.makePair(distance, last);
	}
}

class Heap {
	private final IntComparator comparator;
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
		if (index < 0 || index >= size)
			throw new IllegalArgumentException();
		while (index != 0) {
			int parent = (index - 1) >>> 1;
			if (comparator.compare(parent, index) <= 0)
				return;
			swap(parent, index);
			index = parent;
		}
	}

	public void shiftDown(int index) {
		if (index < 0 || index >= size)
			throw new IllegalArgumentException();
		while (true) {
			int child = (index << 1) + 1;
			if (child >= size)
				return;
			if (child + 1 < size && comparator.compare(child, child + 1) > 0)
				child++;
			if (comparator.compare(index, child) <= 0)
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

class IntegerUtils {

    public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	}