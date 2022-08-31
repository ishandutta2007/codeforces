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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskF {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			int m = in.readInt();
			int[] a = IOUtils.readIntArray(in, n);
			//		int[] a = new int[n];
			//		Random ra = new Random(239);
			//		for (int i = 0; i < n; i++) {
			//			a[i] = ra.nextInt(1000000) + 1;
			//		}
			int[] l = new int[m];
			int[] r = new int[m];
			IOUtils.readIntArrays(in, l, r);
			MiscUtils.decreaseByOne(l, r);
			Graph graph = Graph.createGraph(Math.max(n, m), l, Range.range(m).toArray());
			int[] result = new int[n];
			int[] answer = new int[m];
			for (int i = n - 1; i >= 0; i--) {
				result[i] = a[i];
				for (int j = i + 1; j < n; j++) {
					result[j] = Math.max(value(a[i], a[j]), Math.max(result[j - 1], result[j]));
				}
				for (int j = graph.firstOutbound(i); j != -1; j = graph.nextOutbound(j)) {
					int current = graph.destination(j);
					answer[current] = result[r[current]];
				}
			}
			new IntArray(answer).forEach((IntTask) out::printLine);
		}

		private int value(int a, int b) {
			return value(Math.max(a, b)) ^ value(Math.min(a, b) - 1);
		}

		private int value(int x) {
			return x * (1 - (x & 1)) + ((x >> 1 & 1) ^ (x & 1));
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
			if (numChars == -1) {
				throw new InputMismatchException();
			}
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0) {
					return -1;
				}
			}
			return buf[curChar++];
		}

		public int readInt() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9') {
					throw new InputMismatchException();
				}
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public boolean isSpaceChar(int c) {
			if (filter != null) {
				return filter.isSpaceChar(c);
			}
			return isWhitespace(c);
		}

		public static boolean isWhitespace(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
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

		public void printLine(int i) {
			writer.println(i);
		}
	}

	static class MiscUtils {
		public static void decreaseByOne(int[]... arrays) {
			for (int[] array : arrays) {
				for (int i = 0; i < array.length; i++) {
					array[i]--;
				}
			}
		}
	}

	static class IOUtils {
		public static int[] readIntArray(InputReader in, int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++) {
				array[i] = in.readInt();
			}
			return array;
		}

		public static void readIntArrays(InputReader in, int[]... arrays) {
			for (int i = 0; i < arrays[0].length; i++) {
				for (int j = 0; j < arrays.length; j++) {
					arrays[j][i] = in.readInt();
				}
			}
		}
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

		public static Graph createGraph(int vertexCount, int[] from, int[] to) {
			Graph graph = new Graph(vertexCount, from.length);
			for (int i = 0; i < from.length; i++) {
				graph.addSimpleEdge(from[i], to[i]);
			}
			return graph;
		}

		public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
			ensureEdgeCapacity(edgeCount + 1);
			if (firstOutbound[fromID] != -1) {
				nextOutbound[edgeCount] = firstOutbound[fromID];
			} else {
				nextOutbound[edgeCount] = -1;
			}
			firstOutbound[fromID] = edgeCount;
			if (firstInbound != null) {
				if (firstInbound[toID] != -1) {
					nextInbound[edgeCount] = firstInbound[toID];
				} else {
					nextInbound[edgeCount] = -1;
				}
				firstInbound[toID] = edgeCount;
			}
			this.from[edgeCount] = fromID;
			this.to[edgeCount] = toID;
			if (capacity != 0) {
				if (this.capacity == null) {
					this.capacity = new long[from.length];
				}
				this.capacity[edgeCount] = capacity;
			}
			if (weight != 0) {
				if (this.weight == null) {
					this.weight = new long[from.length];
				}
				this.weight[edgeCount] = weight;
			}
			if (reverseEdge != -1) {
				if (this.reverseEdge == null) {
					this.reverseEdge = new int[from.length];
					Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
				}
				this.reverseEdge[edgeCount] = reverseEdge;
			}
			if (edges != null) {
				edges[edgeCount] = createEdge(edgeCount);
			}
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

		public final int firstOutbound(int vertex) {
			int id = firstOutbound[vertex];
			while (id != -1 && isRemoved(id)) {
				id = nextOutbound[id];
			}
			return id;
		}

		public final int nextOutbound(int id) {
			id = nextOutbound[id];
			while (id != -1 && isRemoved(id)) {
				id = nextOutbound[id];
			}
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
				if (edges != null) {
					edges = resize(edges, newSize);
				}
				from = resize(from, newSize);
				to = resize(to, newSize);
				nextOutbound = resize(nextOutbound, newSize);
				if (nextInbound != null) {
					nextInbound = resize(nextInbound, newSize);
				}
				if (weight != null) {
					weight = resize(weight, newSize);
				}
				if (capacity != null) {
					capacity = resize(capacity, newSize);
				}
				if (reverseEdge != null) {
					reverseEdge = resize(reverseEdge, newSize);
				}
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

	static interface IntIterator {
		public int value() throws NoSuchElementException;

		public boolean advance();

		public boolean isValid();
	}

	static interface IntCollection extends IntStream {
		public int size();

		default public int[] toArray() {
			int size = size();
			int[] array = new int[size];
			int i = 0;
			for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
				array[i++] = it.value();
			}
			return array;
		}
	}

	static interface IntReversableCollection extends IntCollection {
	}

	static interface Edge {
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
	}

	static interface IntTask {
		public void process(int value);
	}

	static class Range {
		public static IntList range(int from, int to) {
			int[] result = new int[Math.abs(from - to)];
			int current = from;
			if (from <= to) {
				for (int i = 0; i < result.length; i++) {
					result[i] = current++;
				}
			} else {
				for (int i = 0; i < result.length; i++) {
					result[i] = current--;
				}
			}
			return new IntArray(result);
		}

		public static IntList range(int n) {
			return range(0, n);
		}
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

		default public void forEach(IntTask task) {
			for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
				task.process(it.value());
			}
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
}