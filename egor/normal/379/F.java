import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
	int[] value;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		System.err.println("Start");
		int queryCount = in.readInt();
		int[] addTo = IOUtils.readIntArray(in, queryCount);
//		Random random = new Random(239);
//		int[] addTo = new int[queryCount];
//		for (int i = 0; i < queryCount; i++) {
//			addTo[i] = random.nextInt(4 + 2 * i) + 1;
//		}
		MiscUtils.decreaseByOne(addTo);
		Graph graph = new BidirectionalGraph(4 + queryCount * 2, 3 + queryCount * 2);
		for (int i = 1; i < 4; i++)
			graph.addSimpleEdge(0, i);
		for (int i = 0; i < queryCount; i++) {
			graph.addSimpleEdge(addTo[i], 2 * i + 4);
			graph.addSimpleEdge(addTo[i], 2 * i + 5);
		}
//		LCA lca = new LCA(graph);
		int[] order = new int[2 * graph.vertexCount() - 1];
		int[] position = new int[graph.vertexCount()];
		int[] level = new int[graph.vertexCount()];
		int[] index = new int[graph.vertexCount()];
		for (int i = 0; i < index.length; i++)
			index[i] = graph.firstOutbound(i);
		int[] last = new int[graph.vertexCount()];
		int[] stack = new int[graph.vertexCount()];
		int size = 1;
		int j = 0;
		last[0] = -1;
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
		int[] spLevel = new int[order.length];
		for (int i = 0; i < order.length; i++)
			spLevel[i] = level[order[i]];
		value = new int[4 * spLevel.length];
		init(0, 0, spLevel.length - 1, spLevel);
//		IntervalTree lca = new ArrayBasedIntervalTree(spLevel) {
//			@Override
//			protected long joinValue(long left, long right) {
//				return Math.min(left, right);
//			}
//
//			@Override
//			protected long joinDelta(long was, long delta) {
//				return 0;
//			}
//
//			@Override
//			protected long accumulate(long value, long delta, int length) {
//				return value;
//			}
//
//			@Override
//			protected long neutralValue() {
//				return Integer.MAX_VALUE;
//			}
//
//			@Override
//			protected long neutralDelta() {
//				return 0;
//			}
//		};
		int from = 1;
		int to = 2;
		int length = 2;
		System.err.println("Preparation");
		for (int i = 0; i < queryCount; i++) {
			int vertex = 2 * i + 4;
			int candidate = getPathLength(vertex, from, level, position);
			if (candidate > length) {
				length = candidate;
				to = vertex;
			}
			candidate = getPathLength(vertex, to, level, position);
			if (candidate > length) {
				length = candidate;
				from = vertex;
			}
			vertex = 2 * i + 5;
			candidate = getPathLength(vertex, from, level, position);
			if (candidate > length) {
				length = candidate;
				to = vertex;
			}
			candidate = getPathLength(vertex, to, level, position);
			if (candidate > length) {
				length = candidate;
				from = vertex;
			}
			out.printLine(length);
		}
    }

	private void init(int root, int left, int right, int[] spLevel) {
		if (left == right) {
			value[root] = spLevel[left];
			return;
		}
		int middle = (left + right) >> 1;
		init(2 * root + 1, left, middle, spLevel);
		init(2 * root + 2, middle + 1, right, spLevel);
		value[root] = Math.min(value[2 * root + 1], value[2 * root + 2]);
	}

	private int getPathLength(int from, int to, int[] level, int[] position) {
		return (level[from] + level[to] - 2 * query(0, 0, 2 * position.length - 2, Math.min(position[from], position[to]), Math.max(position[from], position[to])));
	}

	private int query(int root, int left, int right, int from, int to) {
		if (left > to || right < from)
			return Integer.MAX_VALUE;
		if (left >= from && right <= to)
			return value[root];
		int middle = (left + right) >> 1;
		return Math.min(query(2 * root + 1, left, middle, from, to), query(2 * root + 2, middle + 1, right, from, to));
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

interface Edge {
	}