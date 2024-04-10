import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
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
	int size;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		size = in.readInt();
		int count = in.readInt();
		int[] row = new int[count];
		int[] column = new int[count];
		int[] type = new int[count];
		for (int i = 0; i < count; i++) {
			row[i] = in.readInt() - 1;
			column[i] = in.readInt() - 1;
			type[i] = in.readCharacter() == 'o' ? 1 : 0;
		}
		int[] first = new int[count];
		int[] second = new int[count];
		int[] same = new int[count];
		for (int i = 0; i < count; i++) {
			if (row[i] + column[i] > size - 1) {
				row[i] = size - 1 - row[i];
				column[i] = size - 1 - column[i];
			}
			if (row[i] > column[i]) {
				int temp = row[i];
				row[i] = column[i];
				column[i] = temp;
			}
			first[i] = (column[i] - row[i]) >> 1;
			second[i] = (column[i] + row[i] + 2) >> 1;
			same[i] = (row[i] + column[i]) & 1;
		}
		int answer = 0;
		int even = solve(first, second, same, type, 0);
		if (even == -1) {
			out.printLine(0);
			return;
		}
		answer += even;
		int odd = solve(first, second, same, type, 1);
		if (odd == -1) {
			out.printLine(0);
			return;
		}
		answer += odd;
		out.printLine(IntegerUtils.power(2, answer, (long) (1e9 + 7)));
	}

	private int solve(int[] first, int[] second, int[] same, int[] type, int value) {
		IndependentSetSystem setSystem = new RecursiveIndependentSetSystem((size + 3) >> 1);
		for (int i = 0; i < first.length; i++) {
			if (same[i] == value && type[i] == 0) {
				setSystem.join(first[i], second[i]);
			}
		}
		Graph graph = new BidirectionalGraph((size + 3) >> 1);
		for (int i = 0; i < first.length; i++) {
			if (same[i] == value && type[i] == 1) {
				graph.addSimpleEdge(setSystem.get(first[i]), setSystem.get(second[i]));
			}
		}
		int result = -1;
		int[] color = new int[(size + 3) >> 1];
		for (int i = 0; i < ((size + 3) >> 1); i++) {
			if (2 * i + value >= size + 2 || setSystem.get(i) != i || color[i] != 0) {
				continue;
			}
			if (dfs(i, 1, graph, color)) {
				return -1;
			}
			result++;
		}
		return result;
	}

	private boolean dfs(int id, int newColor, Graph graph, int[] color) {
		if (color[id] != 0) {
			return color[id] != newColor;
		}
		color[id] = newColor;
		for (int i = graph.firstOutbound(id); i != -1; i = graph.nextOutbound(i)) {
			if (dfs(graph.destination(i), -newColor, graph, color)) {
				return true;
			}
		}
		return false;
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

	public void close() {
		writer.close();
	}

	public void printLine(long i) {
		writer.println(i);
	}

	public void printLine(int i) {
		writer.println(i);
	}
}

class IntegerUtils {

	public static long power(long base, long exponent, long mod) {
		if (base >= mod)
			base %= mod;
		if (exponent == 0)
			return 1 % mod;
		long result = power(base, exponent >> 1, mod);
		result = result * result % mod;
		if ((exponent & 1) != 0)
			result = result * base % mod;
		return result;
	}

}

interface IndependentSetSystem {
	public boolean join(int first, int second);

	public int get(int index);

	public static interface Listener {
		public void joined(int joinedRoot, int root);
	}
}

class RecursiveIndependentSetSystem implements IndependentSetSystem {
	private final int[] color;
	private final int[] rank;
	private int setCount;
	private Listener listener;

	public RecursiveIndependentSetSystem(int size) {
		color = new int[size];
		rank = new int[size];
		for (int i = 0; i < size; i++)
			color[i] = i;
		setCount = size;
	}

	public RecursiveIndependentSetSystem(RecursiveIndependentSetSystem other) {
		color = other.color.clone();
		rank = other.rank.clone();
		setCount = other.setCount;
	}

	public boolean join(int first, int second) {
		first = get(first);
		second = get(second);
		if (first == second)
			return false;
		if (rank[first] < rank[second]) {
			int temp = first;
			first = second;
			second = temp;
		} else if (rank[first] == rank[second])
			rank[first]++;
		setCount--;
		color[second] = first;
		if (listener != null)
			listener.joined(second, first);
		return true;
	}

	public int get(int index) {
		if (color[index] == index)
			return index;
		return color[index] = get(color[index]);
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