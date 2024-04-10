import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.util.Iterator;
import java.io.PrintWriter;
import java.io.Writer;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    private static final long MOD = (long) (1e9 + 7);
    Graph graph;
    long[] qty;
    long[] sum;
    long[] sq;
    long[] totalSq;
    long[] totalSum;
    long[] level;
    long[] qUp;
    long[] qDown;
    long[] sumUp;
    long[] sumDown;
    long[] sqUp;
    long[] sqDown;
    int[] parent;
    long[] edgeUp;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int count = in.readInt();
        int[] from = new int[count - 1];
        int[] to = new int[count - 1];
        int[] length = new int[count - 1];
        IOUtils.readIntArrays(in, from, to, length);
        MiscUtils.decreaseByOne(from, to);
        graph = BidirectionalGraph.createWeightedGraph(count, from, to, ArrayUtils.asLong(length));
        qty = new long[count];
        sum = new long[count];
        sq = new long[count];
        totalSq = new long[count];
        totalSum = new long[count];
        qUp = new long[count];
        qDown = new long[count];
        sumUp = new long[count];
        sumDown = new long[count];
        sqUp = new long[count];
        sqDown = new long[count];
        level = new long[count];
        parent = new int[count];
        edgeUp = new long[count];
        calculate(0, -1, 0L);
        calculateTotal(0, -1, 0L);
        LCA lca = new LCA(graph);
        int queryCount = in.readInt();
        for (int i = 0; i < queryCount; i++) {
            int first = in.readInt() - 1;
            int root = in.readInt() - 1;
            int base = lca.getLCA(first, root);
            long answer;
            if (base == root) {
                long distance = level[first] - level[root];
                if (parent[root] == -1) {
                    answer = totalSq[first];
                } else {
                    long otherQty = count - qty[root];
                    long otherSum = (totalSum[parent[root]] - sum[root] - edgeUp[root] * qty[root]) % MOD;
                    long otherSq = (totalSq[parent[root]] - sq[root] - 2 * sum[root] * edgeUp[root] - edgeUp[root] * edgeUp[root] % MOD * qty[root]) % MOD;
                    distance = (distance + edgeUp[root]) % MOD;
                    answer = (totalSq[first] - otherSq - 2 * otherSum * distance - distance * distance % MOD * otherQty) % MOD;
                }
            } else {
                long distance = (level[first] + level[root] - 2 * level[base]) % MOD;
                answer = (sq[root] + 2 * sum[root] * distance + distance * distance % MOD * qty[root]);
            }
//            long baseLength = level[first] - level[base];
//            answer += sqUp[base] + 2 * sumUp[base] * baseLength + baseLength * baseLength % MOD * qUp[base];
//            answer %= MOD;
//            long otherQty = qDown[root] - qDown[base];
//            long otherSum = (sumDown[root] - sumDown[base] - level[base] * otherQty) % MOD;
//            long otherSq = (sqDown[root] - sqDown[base] - 2 * (sumDown[root] - sumDown[base]) * level[base] + level[base] * level[base] % MOD * otherQty);
//            answer += otherSq + 2 * otherSum * baseLength + baseLength * baseLength % MOD * otherQty;
//            answer += baseLength * baseLength;
//            answer %= MOD;
            answer *= 2;
            answer %= MOD;
            answer -= totalSq[first];
            answer %= MOD;
            if (answer < 0) {
                answer += MOD;
            }
            out.printLine(answer);
        }
    }

    private void calculateTotal(int vertex, int last, long edge) {
        if (last != -1) {
            long otherQty = graph.vertexCount() - qty[vertex];
            long otherSum = (totalSum[last] - sum[vertex] - qty[vertex] * edge) % MOD;
            long otherSq = (totalSq[last] - sq[vertex] - 2 * sum[vertex] * edge - edge * edge % MOD * qty[vertex]) % MOD;
            totalSum[vertex] = (sum[vertex] + otherSum + otherQty * edge) % MOD;
            totalSq[vertex] = (sq[vertex] + otherSq + 2 * otherSum * edge + edge * edge % MOD * otherQty) % MOD;
        } else {
            totalSq[vertex] = sq[vertex];
            totalSum[vertex] = sum[vertex];
        }
        for (int i = graph.firstOutbound(vertex); i != -1; i = graph.nextOutbound(i)) {
            int next = graph.destination(i);
            if (next == last) {
                continue;
            }
            long down = graph.weight(i);
            calculateTotal(next, vertex, down);
        }
    }

    private void calculate(int vertex, int last, long edge) {
        parent[vertex] = last;
        edgeUp[vertex] = edge;
        if (last != -1) {
            level[vertex] = (level[last] + edge) % MOD;
            qUp[vertex] = qUp[last] + 1;
            qDown[vertex] = qDown[last] + 1;
            sumUp[vertex] = (sumUp[last] + edge * qUp[vertex]) % MOD;
            sumDown[vertex] = (sumDown[last] + level[vertex]) % MOD;
            sqUp[vertex] = (sqUp[last] + 2 * sumUp[last] * edge + edge * edge % MOD * qUp[vertex]) % MOD;
            sqDown[vertex] = (sqDown[last] + level[vertex] * level[vertex]) % MOD;
        }
        qty[vertex] = 1;
        for (int i = graph.firstOutbound(vertex); i != -1; i = graph.nextOutbound(i)) {
            int next = graph.destination(i);
            if (next == last) {
                continue;
            }
            long down = graph.weight(i);
            calculate(next, vertex, down);
            qty[vertex] += qty[next];
            qty[vertex] %= MOD;
            sum[vertex] += sum[next] + qty[next] * down;
            sum[vertex] %= MOD;
            sq[vertex] += sq[next] + 2 * sum[next] * down + down * down % MOD * qty[next];
            sq[vertex] %= MOD;
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
	public long[] capacity;
	private int[] reverseEdge;
	private int[] flags;

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

	public final long weight(int id) {
		if (weight == null)
			return 0;
		return weight[id];
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

class MiscUtils {

	public static void decreaseByOne(int[]...arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

}

class BidirectionalGraph extends Graph {
	public int[] transposedEdge;

	public BidirectionalGraph(int vertexCount, int edgeCapacity) {
		super(vertexCount, 2 * edgeCapacity);
		transposedEdge = new int[2 * edgeCapacity];
	}

	public static BidirectionalGraph createWeightedGraph(int vertexCount, int[] from, int[] to, long[] weight) {
		BidirectionalGraph graph = new BidirectionalGraph(vertexCount, from.length);
		for (int i = 0; i < from.length; i++)
			graph.addWeightedEdge(from[i], to[i], weight[i]);
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

	public static long[] asLong(int[] array) {
		long[] result = new long[array.length];
		for (int i = 0; i < array.length; i++)
			result[i] = array[i];
		return result;
	}

}

class LCA {
	private final long[] order;
	private final int[] position;
	private final Graph graph;
	private final IntervalTree lcaTree;
	private final int[] level;

	public LCA(Graph graph) {
		this(graph, 0);
	}

	public LCA(Graph graph, int root) {
		this.graph = graph;
		order = new long[2 * graph.vertexCount() - 1];
		position = new int[graph.vertexCount()];
		level = new int[graph.vertexCount()];
		int[] index = new int[graph.vertexCount()];
		for (int i = 0; i < index.length; i++)
			index[i] = graph.firstOutbound(i);
		int[] last = new int[graph.vertexCount()];
		int[] stack = new int[graph.vertexCount()];
		stack[0] = root;
		int size = 1;
		int j = 0;
		last[root] = -1;
		Arrays.fill(position, -1);
		while (size > 0) {
			int vertex = stack[--size];
			if (position[vertex] == -1)
				position[vertex] = j;
			order[j++] = vertex;
			if (last[vertex] != -1)
				level[vertex] = level[last[vertex]] + 1;
			while (index[vertex] != -1 && last[vertex] == graph.destination(index[vertex]))
				index[vertex] = graph.nextOutbound(index[vertex]);
			if (index[vertex] != -1) {
				stack[size++] = vertex;
				stack[size++] = graph.destination(index[vertex]);
				last[graph.destination(index[vertex])] = vertex;
				index[vertex] = graph.nextOutbound(index[vertex]);
			}
		}
		lcaTree = new ReadOnlyIntervalTree(order) {
			protected long joinValue(long left, long right) {
				if (left == -1)
					return right;
				if (right == -1)
					return left;
				if (level[((int) left)] < level[((int) right)])
					return left;
				return right;
			}

			protected long neutralValue() {
				return -1;
			}
		};
		lcaTree.init();
	}

	public int getLCA(int first, int second) {
		return (int) lcaTree.query(Math.min(position[first], position[second]), Math.max(position[first], position[second]));
	}

}

interface Edge {
}

abstract class IntervalTree {
	protected int size;

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

abstract class ReadOnlyIntervalTree extends IntervalTree {
	protected long[] value;
	protected long[] array;

	protected ReadOnlyIntervalTree(long[] array) {
		super(array.length, false);
		this.array = array;
		init();
	}

	protected void initData(int size, int nodeCount) {
		value = new long[nodeCount];
	}

	protected void initAfter(int root, int left, int right, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
	}

	protected void initBefore(int root, int left, int right, int middle) {
	}

	protected void initLeaf(int root, int index) {
		value[root] = array[index];
	}

	protected long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult) {
		return joinValue(leftResult, rightResult);
	}

	protected void queryPreProcess(int root, int left, int right, int from, int to, int middle) {
	}

	protected long queryFull(int root, int left, int right, int from, int to) {
		return value[root];
	}

	protected long emptySegmentResult() {
		return neutralValue();
	}

	protected abstract long neutralValue();
	protected abstract long joinValue(long left, long right);
}