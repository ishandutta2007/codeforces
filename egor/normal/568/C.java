import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Random;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskC {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			char[] type = in.readString().toCharArray();
			int n = in.readInt();
			int m = in.readInt();
			int[] pos1 = new int[m];
			char[] t1 = new char[m];
			int[] pos2 = new int[m];
			char[] t2 = new char[m];
			for (int i = 0; i < m; i++) {
				pos1[i] = in.readInt();
				t1[i] = in.readCharacter();
				pos2[i] = in.readInt();
				t2[i] = in.readCharacter();
			}
			char[] s = IOUtils.readCharArray(in, n);
			MiscUtils.decreaseByOne(pos1, pos2);
			char[] nextVowel = new char[type.length];
			char[] nextConsonant = new char[type.length];
			char vowel = 0;
			char consonant = 0;
			for (int i = type.length - 1; i >= 0; i--) {
				nextVowel[i] = vowel;
				nextConsonant[i] = consonant;
				if (type[i] == 'V') {
					vowel = (char) ('a' + i);
				} else {
					consonant = (char) ('a' + i);
				}
			}
			if (vowel == 0) {
				for (int i = 0; i < m; i++) {
					if (t1[i] == 'C' && t2[i] == 'V') {
						out.printLine(-1);
						return;
					}
				}
				out.printLine(s);
				return;
			}
			if (consonant == 0) {
				for (int i = 0; i < m; i++) {
					if (t1[i] == 'V' && t2[i] == 'C') {
						out.printLine(-1);
						return;
					}
				}
				out.printLine(s);
				return;
			}
			boolean[][][] relation = new boolean[n + 1][2 * n][2 * n];
			Graph graph = new Graph(2 * n);
			for (int j = 0; j < m; j++) {
				int from = pos1[j];
				int revTo = n + pos1[j];
				if (t1[j] == 'V') {
					from += n;
					revTo -= n;
				}
				int to = pos2[j];
				int revFrom = n + pos2[j];
				if (t2[j] == 'V') {
					to += n;
					revFrom -= n;
				}
				graph.addSimpleEdge(from, to);
				graph.addSimpleEdge(revFrom, revTo);
			}
			Pair<int[], Graph> kosaraju = StronglyConnectedComponents.kosaraju(graph);
			boolean[][] edges = new boolean[kosaraju.second.vertexCount()][kosaraju.second.vertexCount()];
			for (int i = 0; i < edges.length; i++) {
				edges[i][i] = true;
				for (int j = kosaraju.second.firstOutbound(i); j != -1; j = kosaraju.second.nextOutbound(j)) {
					edges[i][kosaraju.second.destination(j)] = true;
				}
			}
			for (int i = 0; i < 2 * n; i++) {
				if (i < n && kosaraju.first[i] == kosaraju.first[i + n]) {
					out.printLine(-1);
					return;
				}
				for (int j = 0; j < 2 * n; j++) {
					if (edges[kosaraju.first[i]][kosaraju.first[j]]) {
						relation[0][i][j] = true;
					}
				}
			}
			for (int i = 0; i < 2 * n; i++) {
				for (int j = 0; j < 2 * n; j++) {
					for (int k = 0; k < 2 * n; k++) {
						relation[0][j][k] |= relation[0][j][i] && relation[0][i][k];
					}
				}
			}
			int start = n;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 2 * n; j++) {
					for (int k = 0; k < 2 * n; k++) {
						relation[i + 1][j][k] = relation[i][j][k];
					}
				}
				if (type[s[i] - 'a'] == 'C') {
					if (relation[i + 1][i][n + i]) {
						start = i;
						break;
					}
					updateConsonant(n, relation[i + 1], i);
				} else {
					if (relation[i + 1][n + i][i]) {
						start = i;
						break;
					}
					updateVowel(n, relation[i + 1], i);
				}
			}
			for (int i = start; i >= 0; i--) {
				if (i == n) {
					out.printLine(s);
					return;
				}
				int value = Integer.MAX_VALUE;
				if (i == n || nextConsonant[s[i] - 'a'] != 0) {
					boolean compatible = !relation[i][i][n + i];
					if (compatible) {
						value = i == n ? 0 : nextConsonant[s[i] - 'a'];
					}
				}
				if (i != n && nextVowel[s[i] - 'a'] != 0) {
					boolean compatible = !relation[i][n + i][i];
					if (compatible) {
						value = Math.min(value, nextVowel[s[i] - 'a']);
					}
				}
				if (value != Integer.MAX_VALUE) {
					boolean[][] current = relation[i];
					if (i != n) {
						s[i] = (char) (value);
						if (type[value - 'a'] == 'C') {
							updateConsonant(n, current, i);
						} else {
							updateVowel(n, current, i);
						}
					}
					for (int k = i + 1; k < n; k++) {
						value = Integer.MAX_VALUE;
						if (!current[k][n + k]) {
							value = type[0] == 'C' ? 'a' : nextConsonant[0];
						}
						if (!current[n + k][k]) {
							value = Math.min(value, type[0] == 'V' ? 'a' : nextVowel[0]);
						}
						s[k] = (char) (value);
						if (type[value - 'a'] == 'C') {
							updateConsonant(n, current, k);
						} else {
							updateVowel(n, current, k);
						}
					}
					out.printLine(s);
					return;
				}
			}
			out.printLine(-1);
		}

		protected void updateVowel(int n, boolean[][] booleans, int i) {
			if (!booleans[i][n + i]) {
				for (int j = 0; j < 2 * n; j++) {
					for (int k = 0; k < 2 * n; k++) {
						booleans[j][k] |= booleans[j][i] && booleans[n + i][k];
					}
				}
			}
		}

		protected void updateConsonant(int n, boolean[][] booleans, int i) {
			if (!booleans[n + i][i]) {
				for (int j = 0; j < 2 * n; j++) {
					for (int k = 0; k < 2 * n; k++) {
						booleans[j][k] |= booleans[j][n + i] && booleans[i][k];
					}
				}
			}
		}

	}

	static abstract class IntCollection {
		public abstract IntIterator iterator();

		public abstract int size();

		public abstract void add(int value);

		public int[] toArray() {
			int size = size();
			int[] array = new int[size];
			int i = 0;
			for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
				array[i++] = iterator.value();
			return array;
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

		public void printLine(char[] array) {
			writer.println(array);
		}

		public void close() {
			writer.close();
		}

		public void printLine(int i) {
			writer.println(i);
		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private InputReader.SpaceCharFilter filter;

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
			StringBuilder res = new StringBuilder();
			do {
				if (Character.isValidCodePoint(c))
					res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
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

	static class IntHashSet extends IntSet {
		private static final Random RND = new Random();
		private static final int[] SHIFTS = new int[4];
		private static final byte PRESENT_MASK = 1;
		private int size;
		private int realSize;
		private int[] values;
		private byte[] present;
		private int step;
		private int ratio;

		static {
			for (int i = 0; i < 4; i++)
				SHIFTS[i] = RND.nextInt(31) + 1;
		}

		public IntHashSet() {
			this(3);
		}

		public IntHashSet(int capacity) {
			capacity = Math.max(capacity, 1);
			values = new int[capacity];
			present = new byte[capacity];
			ratio = 2;
			initStep(capacity);
		}

		private void initStep(int capacity) {
			step = RND.nextInt(capacity - 2) + 1;
			while (IntegerUtils.gcd(step, capacity) != 1)
				step++;
		}


		public IntIterator iterator() {
			return new IntIterator() {
				private int position = size == 0 ? values.length : -1;

				public int value() throws NoSuchElementException {
					if (position == -1)
						advance();
					if (position >= values.length)
						throw new NoSuchElementException();
					return values[position];
				}

				public void advance() throws NoSuchElementException {
					if (position >= values.length)
						throw new NoSuchElementException();
					position++;
					while (position < values.length && (present[position] & PRESENT_MASK) == 0)
						position++;
				}

				public boolean isValid() {
					return position < values.length;
				}
			};
		}


		public int size() {
			return size;
		}


		public void add(int value) {
			ensureCapacity((realSize + 1) * ratio + 2);
			int current = getHash(value);
			while (present[current] != 0) {
				if ((present[current] & PRESENT_MASK) != 0 && values[current] == value) {
					return;
				}
				current += step;
				if (current >= values.length)
					current -= values.length;
			}
			while ((present[current] & PRESENT_MASK) != 0) {
				current += step;
				if (current >= values.length)
					current -= values.length;
			}
			if (present[current] == 0) {
				realSize++;
			}
			present[current] = PRESENT_MASK;
			values[current] = value;
			size++;
		}

		private int getHash(int value) {
			int result = value;
			for (int i : SHIFTS)
				result ^= value >> i;
			result %= values.length;
			if (result < 0)
				result += values.length;
			return result;
		}

		private void ensureCapacity(int capacity) {
			if (values.length < capacity) {
				capacity = Math.max(capacity * 2, values.length);
				rebuild(capacity);
			}
		}

		private void rebuild(int capacity) {
			initStep(capacity);
			int[] oldValues = values;
			byte[] oldPresent = present;
			values = new int[capacity];
			present = new byte[capacity];
			size = 0;
			realSize = 0;
			for (int i = 0; i < oldValues.length; i++) {
				if ((oldPresent[i] & PRESENT_MASK) == PRESENT_MASK)
					add(oldValues[i]);
			}
		}

	}

	static abstract class IntSet extends IntCollection {
	}

	static interface IntIterator {
		public int value();

		public void advance();

		public boolean isValid();

	}

	static class IntegerUtils {
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

	static class StronglyConnectedComponents {
		private final Graph graph;
		private int[] order;
		private boolean[] visited;
		private int index = 0;
		private int vertexCount;
		private int[] condensed;
		private IntSet next;

		private StronglyConnectedComponents(Graph graph) {
			this.graph = graph;
			vertexCount = graph.vertexCount();
			order = new int[vertexCount];
			visited = new boolean[vertexCount];
			condensed = new int[vertexCount];
		}

		public static Pair<int[], Graph> kosaraju(Graph graph) {
			return new StronglyConnectedComponents(graph).kosaraju();
		}

		private Pair<int[], Graph> kosaraju() {
			for (int i = 0; i < vertexCount; i++) {
				if (!visited[i])
					firstDFS(i);
			}
			Arrays.fill(visited, false);
			Graph result = new Graph(0);
			index = 0;
			for (int i = vertexCount - 1; i >= 0; i--) {
				if (!visited[order[i]]) {
					next = new IntHashSet();
					secondDFS(order[i]);
					result.addVertices(1);
					for (int set : next.toArray())
						result.addSimpleEdge(set, index);
					index++;
				}
			}
			return Pair.makePair(condensed, result);
		}

		private void secondDFS(int vertexID) {
			if (visited[vertexID]) {
				if (condensed[vertexID] != index)
					next.add(condensed[vertexID]);
				return;
			}
			condensed[vertexID] = index;
			visited[vertexID] = true;
			int edgeID = graph.firstInbound(vertexID);
			while (edgeID != -1) {
				secondDFS(graph.source(edgeID));
				edgeID = graph.nextInbound(edgeID);
			}
		}

		private void firstDFS(int vertexID) {
			if (visited[vertexID])
				return;
			visited[vertexID] = true;
			int edgeID = graph.firstOutbound(vertexID);
			while (edgeID != -1) {
				firstDFS(graph.destination(edgeID));
				edgeID = graph.nextOutbound(edgeID);
			}
			order[index++] = vertexID;
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

		protected final Graph.GraphEdge createEdge(int id) {
			return new Graph.GraphEdge(id);
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

		public final int firstInbound(int vertex) {
			initInbound();
			int id = firstInbound[vertex];
			while (id != -1 && isRemoved(id))
				id = nextInbound[id];
			return id;
		}

		public final int nextInbound(int id) {
			initInbound();
			id = nextInbound[id];
			while (id != -1 && isRemoved(id))
				id = nextInbound[id];
			return id;
		}

		public final int source(int id) {
			return from[id];
		}

		public final int destination(int id) {
			return to[id];
		}

		public final void addVertices(int count) {
			ensureVertexCapacity(vertexCount + count);
			Arrays.fill(firstOutbound, vertexCount, vertexCount + count, -1);
			if (firstInbound != null)
				Arrays.fill(firstInbound, vertexCount, vertexCount + count, -1);
			vertexCount += count;
		}

		private void initInbound() {
			if (firstInbound == null) {
				firstInbound = new int[firstOutbound.length];
				Arrays.fill(firstInbound, 0, vertexCount, -1);
				nextInbound = new int[from.length];
				for (int i = 0; i < edgeCount; i++) {
					nextInbound[i] = firstInbound[to[i]];
					firstInbound[to[i]] = i;
				}
			}
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

		private void ensureVertexCapacity(int size) {
			if (firstOutbound.length < size) {
				int newSize = Math.max(size, 2 * from.length);
				firstOutbound = resize(firstOutbound, newSize);
				if (firstInbound != null)
					firstInbound = resize(firstInbound, newSize);
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

	static class Pair<U, V> implements Comparable<Pair<U, V>> {
		public final U first;
		public final V second;

		public static <U, V> Pair<U, V> makePair(U first, V second) {
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

		@SuppressWarnings({"unchecked"})
		public int compareTo(Pair<U, V> o) {
			int value = ((Comparable<U>) first).compareTo(o.first);
			if (value != 0)
				return value;
			return ((Comparable<V>) second).compareTo(o.second);
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

	static interface Edge {
	}

	static class IOUtils {
		public static char[] readCharArray(InputReader in, int size) {
			char[] array = new char[size];
			for (int i = 0; i < size; i++)
				array[i] = in.readCharacter();
			return array;
		}

	}
}