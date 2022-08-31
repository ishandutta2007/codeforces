import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Iterator;
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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] from = new int[count - 1];
		int[] to = new int[count - 1];
		int[] weight = new int[count - 1];
		IOUtils.readIntArrays(in, from, to, weight);
		MiscUtils.decreaseByOne(from, to);
		Graph graph = BidirectionalGraph.createGraph(count, from, to);
		int[] firstQueue = new int[count];
		int[] secondQueue = new int[count];
		boolean[] inCurrent = new boolean[count];
		int[] processed = new int[count];
		int mark = 0;
		Arrays.fill(inCurrent, true);
		int[] order = ArrayUtils.order(weight);
		ArrayUtils.reverse(order);
		int[] allowed = IOUtils.readIntArray(in, count);
		int totalAllowed = 0;
		int remaining = count;
		DFSOrder dfsOrder = new DFSOrder((BidirectionalGraph)graph);
		IntervalTree tree = new LongIntervalTree(count) {
			@Override
			protected long joinValue(long left, long right) {
				return left + right;
			}

			@Override
			protected long joinDelta(long was, long delta) {
				if (delta == neutralDelta()) {
					return was;
				}
				return delta;
			}

			@Override
			protected long accumulate(long value, long delta, int length) {
				if (delta == neutralDelta()) {
					return value;
				}
				return delta * length;
			}

			@Override
			protected long neutralValue() {
				return 0;
			}

			@Override
			protected long neutralDelta() {
				return -1;
			}

			@Override
			protected long initValue(int index) {
				return 1;
			}
		};
		for (int i : order) {
			if (!inCurrent[from[i]]) {
				continue;
			}
			int toRemove;
			int parent;
			if (dfsOrder.position[from[i]] > dfsOrder.position[to[i]]) {
				int temp = from[i];
				from[i] = to[i];
				to[i] = temp;
			}
			int subSet = (int) tree.query(dfsOrder.position[to[i]], dfsOrder.end[to[i]]);
			if (subSet * 2 < remaining) {
				toRemove = to[i];
				parent = from[i];
				tree.update(dfsOrder.position[to[i]], dfsOrder.end[to[i]], 0);
				remaining -= subSet;
			} else {
				toRemove = from[i];
				parent = to[i];
				tree.update(0, dfsOrder.position[to[i]] - 1, 0);
				tree.update(dfsOrder.end[to[i]] + 1, count - 1, 0);
				remaining = subSet;
			}
			totalAllowed += dfs(toRemove, parent, graph, inCurrent, allowed);
			if (remaining <= totalAllowed) {
				out.printLine(weight[i]);
				return;
			}
		}
		out.printLine(0);
    }

	private int dfs(int current, int parent, Graph graph, boolean[] inCurrent, int[] allowed) {
		if (!inCurrent[current]) {
			return 0;
		}
		inCurrent[current] = false;
		int result = allowed[current];
		for (int i = graph.firstOutbound(current); i != -1; i = graph.nextOutbound(i)) {
			int next = graph.destination(i);
			if (next != parent) {
				result += dfs(next, current, graph, inCurrent, allowed);
			}
		}
		return result;
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

	public void close() {
		writer.close();
	}

	public void printLine(int i) {
		writer.println(i);
	}
}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

}

class MiscUtils {

	public static void decreaseByOne(int[]...arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

}

class Graph {
	public static final int REMOVED_BIT = 0;

	protected int vertexCount;
	protected int edgeCount;

	private int[] firstOutbound;
	private int[] firstInbound;

	private Edge[] edges;
	private int[] nextInbound;
	private int[] nextOutbound;
	private int[] from;
	private int[] to;
	private long[] weight;
	private long[] capacity;
	private int[] reverseEdge;
	private int[] flags;

	public Graph(int vertexCount) {
		this(vertexCount, vertexCount);
	}

	public Graph(int vertexCount, int edgeCapacity) {
		this.vertexCount = vertexCount;
		firstOutbound = new int[vertexCount];
		Arrays.fill(firstOutbound, -1);

		from = new int[edgeCapacity];
		to = new int[edgeCapacity];
		nextOutbound = new int[edgeCapacity];
		flags = new int[edgeCapacity];
	}

	public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
		ensureEdgeCapacity(edgeCount + 1);
		if (firstOutbound[fromID] != -1)
			nextOutbound[edgeCount] = firstOutbound[fromID];
		else
			nextOutbound[edgeCount] = -1;
		firstOutbound[fromID] = edgeCount;
		if (firstInbound != null) {
			if (firstInbound[toID] != -1)
				nextInbound[edgeCount] = firstInbound[toID];
			else
				nextInbound[edgeCount] = -1;
			firstInbound[toID] = edgeCount;
		}
		this.from[edgeCount] = fromID;
		this.to[edgeCount] = toID;
		if (capacity != 0) {
			if (this.capacity == null)
				this.capacity = new long[from.length];
			this.capacity[edgeCount] = capacity;
		}
		if (weight != 0) {
			if (this.weight == null)
				this.weight = new long[from.length];
			this.weight[edgeCount] = weight;
		}
		if (reverseEdge != -1) {
			if (this.reverseEdge == null) {
				this.reverseEdge = new int[from.length];
				Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
			}
			this.reverseEdge[edgeCount] = reverseEdge;
		}
		if (edges != null)
			edges[edgeCount] = createEdge(edgeCount);
		return edgeCount++;
	}

	protected final GraphEdge createEdge(int id) {
		return new GraphEdge(id);
	}

	public final int addFlowWeightedEdge(int from, int to, long weight, long capacity) {
		if (capacity == 0) {
			return addEdge(from, to, weight, 0, -1);
		} else {
			int lastEdgeCount = edgeCount;
			addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge());
			return addEdge(from, to, weight, capacity, lastEdgeCount);
		}
	}

	protected int entriesPerEdge() {
		return 1;
	}

	public final int addWeightedEdge(int from, int to, long weight) {
		return addFlowWeightedEdge(from, to, weight, 0);
	}

	public final int addSimpleEdge(int from, int to) {
		return addWeightedEdge(from, to, 0);
	}

	public final int vertexCount() {
		return vertexCount;
	}

	protected final int edgeCapacity() {
		return from.length;
	}

	public final int firstOutbound(int vertex) {
		int id = firstOutbound[vertex];
		while (id != -1 && isRemoved(id))
			id = nextOutbound[id];
		return id;
	}

	public final int nextOutbound(int id) {
		id = nextOutbound[id];
		while (id != -1 && isRemoved(id))
			id = nextOutbound[id];
		return id;
	}

	public final int destination(int id) {
		return to[id];
	}

	public final boolean flag(int id, int bit) {
		return (flags[id] >> bit & 1) != 0;
	}

	public final boolean isRemoved(int id) {
		return flag(id, REMOVED_BIT);
	}

	protected void ensureEdgeCapacity(int size) {
		if (from.length < size) {
			int newSize = Math.max(size, 2 * from.length);
			if (edges != null)
				edges = resize(edges, newSize);
			from = resize(from, newSize);
			to = resize(to, newSize);
			nextOutbound = resize(nextOutbound, newSize);
			if (nextInbound != null)
				nextInbound = resize(nextInbound, newSize);
			if (weight != null)
				weight = resize(weight, newSize);
			if (capacity != null)
				capacity = resize(capacity, newSize);
			if (reverseEdge != null)
				reverseEdge = resize(reverseEdge, newSize);
			flags = resize(flags, newSize);
		}
	}

	protected final int[] resize(int[] array, int size) {
		int[] newArray = new int[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private long[] resize(long[] array, int size) {
		long[] newArray = new long[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private Edge[] resize(Edge[] array, int size) {
		Edge[] newArray = new Edge[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	protected class GraphEdge implements Edge {
		protected int id;

		protected GraphEdge(int id) {
			this.id = id;
		}

	}

}

class BidirectionalGraph extends Graph {
	public int[] transposedEdge;

	public BidirectionalGraph(int vertexCount) {
		this(vertexCount, vertexCount);
	}

	public BidirectionalGraph(int vertexCount, int edgeCapacity) {
		super(vertexCount, 2 * edgeCapacity);
		transposedEdge = new int[2 * edgeCapacity];
	}

	public static BidirectionalGraph createGraph(int vertexCount, int[] from, int[] to) {
		BidirectionalGraph graph = new BidirectionalGraph(vertexCount, from.length);
		for (int i = 0; i < from.length; i++)
			graph.addSimpleEdge(from[i], to[i]);
		return graph;
	}

	public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
		int lastEdgeCount = edgeCount;
		super.addEdge(fromID, toID, weight, capacity, reverseEdge);
		super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
		this.transposedEdge[lastEdgeCount] = lastEdgeCount + 1;
		this.transposedEdge[lastEdgeCount + 1] = lastEdgeCount;
		return lastEdgeCount;
	}

	protected int entriesPerEdge() {
		return 2;
	}

	protected void ensureEdgeCapacity(int size) {
		if (size > edgeCapacity()) {
			super.ensureEdgeCapacity(size);
			transposedEdge = resize(transposedEdge, edgeCapacity());
		}
	}
}

class ArrayUtils {

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

	public static void reverse(int[] array) {
		for (int i = 0, j = array.length - 1; i < j; i++, j--) {
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

}

class DFSOrder {
	public final int[] position;
	public final int[] end;

	public DFSOrder(Graph graph) {
		this(graph, 0);
	}

	public DFSOrder(Graph graph, int root) {
		int count = graph.vertexCount();
		position = new int[count];
		end = new int[count];
		int[] edge = new int[count];
		int[] stack = new int[count];
		for (int i = 0; i < count; i++)
			edge[i] = graph.firstOutbound(i);
		stack[0] = root;
		int size = 1;
		position[root] = 0;
		int index = 0;
		while (size > 0) {
			int current = stack[size - 1];
			if (edge[current] == -1) {
				end[current] = index;
				size--;
			} else {
				int next = graph.destination(edge[current]);
				edge[current] = graph.nextOutbound(edge[current]);
				position[next] = ++index;
				stack[size++] = next;
			}
		}
	}

	public DFSOrder(BidirectionalGraph graph) {
		this(graph, 0);
	}

	public DFSOrder(BidirectionalGraph graph, int root) {
		int count = graph.vertexCount();
		position = new int[count];
		end = new int[count];
		int[] edge = new int[count];
		int[] stack = new int[count];
		int[] last = new int[count];
		for (int i = 0; i < count; i++)
			edge[i] = graph.firstOutbound(i);
		stack[0] = root;
		last[root] = -1;
		int size = 1;
		position[root] = 0;
		int index = 0;
		while (size > 0) {
			int current = stack[size - 1];
			if (edge[current] == -1) {
				end[current] = index;
				size--;
			} else {
				int next = graph.destination(edge[current]);
				if (next == last[current]) {
					edge[current] = graph.nextOutbound(edge[current]);
					continue;
				}
				edge[current] = graph.nextOutbound(edge[current]);
				position[next] = ++index;
				last[next] = current;
				stack[size++] = next;
			}
		}
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

interface Edge {
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