import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
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

	static class TaskD {
		int good;
		int bad;
		Graph graph;

		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			long x = in.readInt();
			long y = in.readInt();
			int[] u = new int[n - 1];
			int[] v = new int[n - 1];
			IOUtils.readIntArrays(in, u, v);
			MiscUtils.decreaseByOne(u, v);
			int[] degree = new int[n];
			for (int i : u) {
				degree[i]++;
			}
			for (int i : v) {
				degree[i]++;
			}
			if (x >= y) {
				if (ArrayUtils.find(degree, n - 1) != -1) {
					out.printLine(x + y * (n - 2));
				} else {
					out.printLine(y * (n - 1));
				}
				return;
			}
			good = n - 1;
			graph = BidirectionalGraph.createGraph(n, u, v);
			go(0, -1);
			out.printLine(good * x + bad * y);
		}

		private boolean go(int vertex, int last) {
			int degree = 0;
			for (int i = graph.firstOutbound(vertex); i != -1; i = graph.nextOutbound(i)) {
				degree++;
				int next = graph.destination(i);
				if (next == last) {
					continue;
				}
				if (go(next, vertex)) {
					degree--;
				}
			}
			if (degree > 2) {
				bad += degree - 2;
				good -= degree - 2;
				return true;
			}
			return false;
		}

	}

	static abstract class IntAbstractStream implements IntStream {

		public String toString() {
			StringBuilder builder = new StringBuilder();
			boolean first = true;
			for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
				if (first) {
					first = false;
				} else {
					builder.append(' ');
				}
				builder.append(it.value());
			}
			return builder.toString();
		}


		public boolean equals(Object o) {
			if (!(o instanceof IntStream)) {
				return false;
			}
			IntStream c = (IntStream) o;
			IntIterator it = intIterator();
			IntIterator jt = c.intIterator();
			while (it.isValid() && jt.isValid()) {
				if (it.value() != jt.value()) {
					return false;
				}
				it.advance();
				jt.advance();
			}
			return !it.isValid() && !jt.isValid();
		}


		public int hashCode() {
			int result = 0;
			for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
				result *= 31;
				result += it.value();
			}
			return result;
		}

	}

	static interface IntList extends IntReversableCollection {
		public abstract int get(int index);

		public abstract void removeAt(int index);

		default public IntIterator intIterator() {
			return new IntIterator() {
				private int at;
				private boolean removed;

				public int value() {
					if (removed) {
						throw new IllegalStateException();
					}
					return get(at);
				}

				public boolean advance() {
					at++;
					removed = false;
					return isValid();
				}

				public boolean isValid() {
					return !removed && at < size();
				}

				public void remove() {
					removeAt(at);
					at--;
					removed = true;
				}
			};
		}

		default public int find(int value) {
			int size = size();
			for (int i = 0; i < size; i++) {
				if (get(i) == value) {
					return i;
				}
			}
			return -1;
		}

	}

	static class OutputWriter {
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

	}

	static interface IntReversableCollection extends IntCollection {
	}

	static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
		public IntIterator intIterator();

		default public Iterator<Integer> iterator() {
			return new Iterator<Integer>() {
				private IntIterator it = intIterator();

				public boolean hasNext() {
					return it.isValid();
				}

				public Integer next() {
					int result = it.value();
					it.advance();
					return result;
				}
			};
		}

		default public int compareTo(IntStream c) {
			IntIterator it = intIterator();
			IntIterator jt = c.intIterator();
			while (it.isValid() && jt.isValid()) {
				int i = it.value();
				int j = jt.value();
				if (i < j) {
					return -1;
				} else if (i > j) {
					return 1;
				}
				it.advance();
				jt.advance();
			}
			if (it.isValid()) {
				return 1;
			}
			if (jt.isValid()) {
				return -1;
			}
			return 0;
		}

	}

	static interface IntCollection extends IntStream {
		public int size();

	}

	static class Graph {
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

	static class InputReader {
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

	static class BidirectionalGraph extends Graph {
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

	static interface Edge {
	}

	static class IntArray extends IntAbstractStream implements IntList {
		private int[] data;

		public IntArray(int[] arr) {
			data = arr;
		}

		public int size() {
			return data.length;
		}

		public int get(int at) {
			return data[at];
		}

		public void removeAt(int index) {
			throw new UnsupportedOperationException();
		}

	}

	static class IOUtils {
		public static void readIntArrays(InputReader in, int[]... arrays) {
			for (int i = 0; i < arrays[0].length; i++) {
				for (int j = 0; j < arrays.length; j++)
					arrays[j][i] = in.readInt();
			}
		}

	}

	static class MiscUtils {
		public static void decreaseByOne(int[]... arrays) {
			for (int[] array : arrays) {
				for (int i = 0; i < array.length; i++)
					array[i]--;
			}
		}

	}

	static interface IntIterator {
		public int value() throws NoSuchElementException;

		public boolean advance();

		public boolean isValid();

	}

	static class ArrayUtils {
		public static int find(int[] array, int value) {
			return new IntArray(array).find(value);
		}

	}
}