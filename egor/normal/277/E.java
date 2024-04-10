import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.Map;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Iterator;
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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] x = new int[count];
		int[] y = new int[count];
		IOUtils.readIntArrays(in, x, y);
		String[] asParent = new String[count];
		String[] asChild = new String[count];
		for (int i = 0; i < count; i++) {
			asParent[i] = "parent" + i;
			asChild[i] = "child" + i;
		}
		Graph<String> graph = new Graph<String>();
		for (int i = 0; i < count; i++) {
			graph.addFlowEdge("source", asParent[i], 2);
			graph.addFlowEdge(asChild[i], "sink", 1);
			for (int j = 0; j < count; j++) {
				if (y[i] > y[j])
					graph.addFlowWeightedEdge(asParent[i], asChild[j], Math.round(1e11 * Math.hypot(x[i] - x[j], y[i] - y[j])), 1);
			}
		}
		Pair<Long, Long> result = new MinCostFlow(graph, "source", "sink", false).minCostMaxFlow();
		if (result.second != count - 1) {
			out.printLine(-1);
			return;
		}
		out.printLine(result.first / 1e11);
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

class IOUtils {

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
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

	public Edge<V> addFlowEdge(V from, V to, long capacity) {
		return addFlowWeightedEdge(from, to, 0, capacity);
	}

	public int getVertexCount() {
		return vertexCount;
	}

	public int resolve(V vertex) {
		if (map.containsKey(vertex))
			return map.get(vertex);
		throw new IllegalArgumentException();
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

		public void pushFlow(long flow) {
			if (flow == 0)
				return;
			if (flow > 0) {
				if (capacity[id] < flow)
					throw new IllegalArgumentException("Not enough capacity");
			} else {
				if (capacity[reverseEdge[id]] < -flow)
					throw new IllegalArgumentException("Not enough capacity");
			}
			capacity[id] -= flow;
			capacity[reverseEdge[id]] += flow;
		}

		}

	}

interface Edge<V> {
	public void pushFlow(long flow);
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

class MinCostFlow<V> {
	private final Graph<V> graph;
	private final int sourceID;
	private final int destinationID;
	private final long[] phi;
	private final long[] dijkstraResult;
	private final int[] lastEdge;
	private final Heap heap;
	private final int vertexCount;
	private final int[] visited;
	private int visitIndex;

	public MinCostFlow(Graph<V> graph, V source, V destination, boolean hasNegativeEdges) {
		this.graph = graph;
		this.sourceID = graph.resolve(source);
		this.destinationID = graph.resolve(destination);
		vertexCount = graph.getVertexCount();
		phi = new long[vertexCount];
		if (hasNegativeEdges)
			fordBellman();
		dijkstraResult = new long[vertexCount];
		lastEdge = new int[vertexCount];
		if (graph.isSparse()) {
			heap = new Heap(vertexCount, new IntComparator() {
				public int compare(int first, int second) {
					return IntegerUtils.longCompare(dijkstraResult[first], dijkstraResult[second]);
				}
			}, vertexCount);
			visited = null;
		} else {
			heap = null;
			visited = new int[vertexCount];
		}
	}

	private void fordBellman() {
		Arrays.fill(phi, Long.MAX_VALUE);
		phi[sourceID] = 0;
		boolean[] inQueue = new boolean[vertexCount];
		int[] queue = new int[vertexCount + 1];
		queue[0] = sourceID;
		inQueue[sourceID] = true;
		int stepCount = 0;
		int head = 0;
		int end = 1;
		int maxSteps = 2 * vertexCount * vertexCount;
		while (head != end) {
			int vertex = queue[head++];
			if (head == queue.length)
				head = 0;
			inQueue[vertex] = false;
			int edgeID = graph.firstOutbound[vertex];
			while (edgeID != -1) {
				long total = phi[vertex] + graph.weight[edgeID];
				int destination = graph.to[edgeID];
				if (!graph.removed[edgeID] && graph.capacity[edgeID] != 0 && phi[destination] > total) {
					phi[destination] = total;
					if (!inQueue[destination]) {
						queue[end++] = destination;
						inQueue[destination] = true;
						if (end == queue.length)
							end = 0;
					}
				}
				edgeID = graph.nextOutbound[edgeID];
			}
			if (++stepCount > maxSteps)
				throw new IllegalArgumentException("Graph contains negative cycle");
		}
	}

	public Pair<Long, Long> minCostMaxFlow() {
		return minCostMaxFlow(Long.MAX_VALUE);
	}

	public Pair<Long, Long> minCostMaxFlow(long maxFlow) {
		long cost = 0;
		long flow = 0;
		while (maxFlow != 0) {
			if (graph.isSparse())
				dijkstraAlgorithm();
			else
				dijkstraAlgorithmFull();
			if (lastEdge[destinationID] == -1)
				return Pair.makePair(cost, flow);
			for (int i = 0; i < dijkstraResult.length; i++) {
				if (dijkstraResult[i] != Long.MAX_VALUE)
					phi[i] += dijkstraResult[i];
			}
			int vertex = destinationID;
			long currentFlow = maxFlow;
			long currentCost = 0;
			while (vertex != sourceID) {
				int edgeID = lastEdge[vertex];
				currentFlow = Math.min(currentFlow, graph.capacity[edgeID]);
				currentCost += graph.weight[edgeID];
				vertex = graph.from[edgeID];
			}
			maxFlow -= currentFlow;
			cost += currentCost * currentFlow;
			flow += currentFlow;
			vertex = destinationID;
			while (vertex != sourceID) {
				int edgeID = lastEdge[vertex];
				graph.edges[edgeID].pushFlow(currentFlow);
				vertex = graph.from[edgeID];
			}
		}
		return Pair.makePair(cost, flow);
	}

	private void dijkstraAlgorithm() {
		Arrays.fill(dijkstraResult, Long.MAX_VALUE);
		Arrays.fill(lastEdge, -1);
		dijkstraResult[sourceID] = 0;
		heap.add(sourceID);
		while (!heap.isEmpty()) {
			int current = heap.poll();
			int edgeID = graph.firstOutbound[current];
			while (edgeID != -1) {
				if (graph.capacity[edgeID] == 0 || graph.removed[edgeID]) {
					edgeID = graph.nextOutbound[edgeID];
					continue;
				}
				int next = graph.to[edgeID];
				long total = graph.weight[edgeID] - phi[next] + phi[current] + dijkstraResult[current];
				if (dijkstraResult[next] > total) {
					dijkstraResult[next] = total;
					if (heap.getIndex(next) == -1)
						heap.add(next);
					else
						heap.shiftUp(heap.getIndex(next));
					lastEdge[next] = edgeID;
				}
				edgeID = graph.nextOutbound[edgeID];
			}
		}
	}

	private void dijkstraAlgorithmFull() {
		visitIndex++;
		Arrays.fill(dijkstraResult, Long.MAX_VALUE);
		lastEdge[destinationID] = -1;
		dijkstraResult[sourceID] = 0;
		for (int i = 0; i < vertexCount; i++) {
			int index = -1;
			long length = Long.MAX_VALUE;
			for (int j = 0; j < vertexCount; j++) {
				if (visited[j] != visitIndex && dijkstraResult[j] < length) {
					length = dijkstraResult[j];
					index = j;
				}
			}
			if (index == -1) {
				return;
			}
			visited[index] = visitIndex;
			int edgeID = graph.firstOutbound[index];
			while (edgeID != -1) {
				if (graph.capacity[edgeID] == 0 || graph.removed[edgeID]) {
					edgeID = graph.nextOutbound[edgeID];
					continue;
				}
				int next = graph.to[edgeID];
				if (visited[next] == visitIndex) {
					edgeID = graph.nextOutbound[edgeID];
					continue;
				}
				long total = graph.weight[edgeID] - phi[next] + phi[index] + length;
				if (dijkstraResult[next] > total) {
					dijkstraResult[next] = total;
					lastEdge[next] = edgeID;
				}
				edgeID = graph.nextOutbound[edgeID];
			}
		}
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

class IntegerUtils {

    public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

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

	public IntSortedList sort(IntComparator comparator) {
		return new IntArray(this).inPlaceSort(comparator);
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