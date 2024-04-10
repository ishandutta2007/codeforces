import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int queryCount = in.readInt();
		int[] colors = IOUtils.readIntArray(in, count);
		int[] from = new int[count - 1];
		int[] to = new int[count - 1];
		IOUtils.readIntArrays(in, from, to);
		MiscUtils.decreaseByOne(from, to);
		Graph graph = BidirectionalGraph.createGraph(count, from, to);
		int[] first = new int[count];
		int[] next = new int[queryCount];
		int[] min = new int[queryCount];
		Arrays.fill(first, -1);
		for (int i = 0; i < queryCount; i++) {
			int vertex = in.readInt() - 1;
			min[i] = in.readInt();
			next[i] = first[vertex];
			first[vertex] = i;
		}
		int[] answer = new int[queryCount];
		solve(0, -1, colors, graph, first, next, min, answer);
		for (int i : answer)
			out.printLine(i);
    }

	private Node solve(int vertex, int last, int[] colors, Graph graph, int[] first, int[] next, int[] min, int[] answer) {
		Node node = new Node(colors[vertex]);
		for (int i = graph.firstOutbound(vertex); i != -1; i = graph.nextOutbound(i)) {
			if (graph.destination(i) == last)
				continue;
			node = node.unite(solve(graph.destination(i), vertex, colors, graph, first, next, min, answer));
		}
		int total = node.tree.query(Integer.MAX_VALUE);
		for (int i = first[vertex]; i != -1; i = next[i])
			answer[i] = total - node.tree.query(min[i] - 1);
		return node;
	}

	static class Node {
		IntHashMap colors = new IntHashMap();
		FenwickTree tree = new FenwickTree();

		Node(int color) {
			tree.modify(1, 1);
			colors.put(color, 1);
		}

		Node unite(Node other) {
			if (colors.size() < other.colors.size())
				return other.unite(this);
			for (IntIterator i = other.colors.iterator(); i.isValid(); i.advance()) {
				int color = i.value();
				int total = 0;
				if (colors.contains(color))
					tree.modify(total = colors.get(color), -1);
				total += other.colors.get(color);
				tree.modify(total, 1);
				colors.put(color, total);
			}
			return this;
		}
	}

	static class FenwickTree {
		int[] values = new int[3];

		final void modify(int at, int delta) {
			ensureCapacity(at);
			modify(values, at, delta);
		}

		private void ensureCapacity(int at) {
			if (at >= values.length) {
				int newLength = 2 * values.length - 1;
				while (at >= newLength)
					newLength = 2 * newLength - 1;
				int[] newValues = new int[newLength];
				int sum = 0;
				for (int i = 1; i < values.length; i++) {
					int newSum = query(i);
					modify(newValues, i, newSum - sum);
					sum = newSum;
				}
				values = newValues;
			}
		}

		private void modify(int[] values, int at, int delta) {
			while (at < values.length) {
				values[at] += delta;
				at += at - (at & (at - 1));
			}
		}

		final int query(int upTo) {
			upTo = Math.min(upTo, values.length - 1);
			int result = 0;
			while (upTo > 0) {
				result += values[upTo];
				upTo -= upTo - (upTo & (upTo - 1));
			}
			return result;
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

class IntHashMap extends IntSet {
	private static final Random RND = new Random();
	private static final int[] SHIFTS = new int[4];
	private static final byte PRESENT_MASK = 1;

	static {
		for (int i = 0; i < 4; i++)
			SHIFTS[i] = RND.nextInt(31) + 1;
	}

	private int size;
	private int[] keys;
	private int[] values;
	private byte[] present;
	private int step;
	private int ratio;

	public IntHashMap() {
		this(3);
	}


	public IntHashMap(int capacity) {
		capacity = Math.max(capacity, 1);
		keys = new int[capacity];
		present = new byte[capacity];
		values = new int[capacity];
		ratio = capacity;
		initStep(capacity);
	}

	private void initStep(int capacity) {
		step = RND.nextInt(capacity - 2) + 1;
		while (IntegerUtils.gcd(step, capacity) != 1)
			step++;
	}

	public IntIterator iterator() {
		return new IntIterator() {
			private int position = size == 0 ? keys.length : -1;

			public int value() throws NoSuchElementException {
				if (position == -1)
					advance();
				if (position >= keys.length)
					throw new NoSuchElementException();
				return keys[position];
			}

			public void advance() throws NoSuchElementException {
				if (position >= keys.length)
					throw new NoSuchElementException();
				position++;
				while (position < keys.length && (present[position] & PRESENT_MASK) == 0)
					position++;
			}

			public boolean isValid() {
				return position < keys.length;
			}
		};
	}

	public int size() {
		return size;
	}

	public void put(int key, int value) {
		ensureCapacity((size + 1) * ratio);
		int current = getHash(key);
		while ((present[current] & PRESENT_MASK) != 0) {
			if (keys[current] == key) {
				values[current] = value;
				return;
			}
			current += step;
			if (current >= keys.length)
				current -= keys.length;
		}
		present[current] = PRESENT_MASK;
		keys[current] = key;
		values[current] = value;
		size++;
	}

	private int getHash(int key) {
		int result = key;
		for (int i : SHIFTS)
			result ^= key >> i;
		result %= keys.length;
		if (result < 0)
			result += keys.length;
		return result;
	}

	private void ensureCapacity(int capacity) {
		if (keys.length < capacity) {
			capacity = Math.max(capacity, 2 * keys.length);
			rebuild(capacity);
		}
	}

	private void rebuild(int capacity) {
		initStep(capacity);
		int[] oldKeys = keys;
		byte[] oldPresent = present;
		int[] oldValues = values;
		keys = new int[capacity];
		present = new byte[capacity];
		values = new int[capacity];
		size = 0;
		for (int i = 0; i < oldKeys.length; i++) {
			if ((oldPresent[i] & PRESENT_MASK) == PRESENT_MASK)
				put(oldKeys[i], oldValues[i]);
		}
	}

	public boolean contains(int key) {
		int current = getHash(key);
		while (present[current] != 0) {
			if (keys[current] == key && (present[current] & PRESENT_MASK) != 0)
				return true;
			current += step;
			if (current >= keys.length)
				current -= keys.length;
		}
		return false;
	}

	public int get(int key) {
		int current = getHash(key);
		while (present[current] != 0) {
			if (keys[current] == key && (present[current] & PRESENT_MASK) != 0)
				return values[current];
			current += step;
			if (current >= keys.length)
				current -= keys.length;
		}
		throw new NoSuchElementException();
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

abstract class IntCollection {

	}

interface Edge {
	}

abstract class IntSet extends IntCollection {
	}

class IntegerUtils {

    public static int gcd(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    }