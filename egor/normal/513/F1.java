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
		TaskF1 solver = new TaskF1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF1 {
	private int rowCount;
		private int columnCount;
		private int[][] distance;
		private int[] malePosition;
		private int[] femalePosition;
		private int[] maleTime;
		private int[] femaleTime;

		public void solve(int testNumber, InputReader in, OutputWriter out) {
			rowCount = in.readInt();
			columnCount = in.readInt();
			int maleCount = in.readInt();
			int femaleCount = in.readInt();
			if (Math.abs(maleCount - femaleCount) != 1) {
				out.printLine(-1);
				return;
			}
			char[][] map = IOUtils.readTable(in, rowCount, columnCount);
			distance = new int[rowCount * columnCount][rowCount * columnCount];
			ArrayUtils.fill(distance, Integer.MAX_VALUE / 2);
			int[] queueRow = new int[rowCount * columnCount];
			int[] queueColumn = new int[rowCount * columnCount];
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++) {
					if (map[i][j] == '#') {
						continue;
					}
					int id = i * columnCount + j;
					distance[id][id] = 0;
					queueRow[0] = i;
					queueColumn[0] = j;
					int size = 1;
					for (int k = 0; k < size; k++) {
						int row = queueRow[k];
						int column = queueColumn[k];
						for (int l = 0; l < 4; l++) {
							int nRow = row + MiscUtils.DX4[l];
							int nColumn = column + MiscUtils.DY4[l];
							if (MiscUtils.isValidCell(nRow, nColumn, rowCount, columnCount) && map[nRow][nColumn] != '#') {
								int nId = nRow * columnCount + nColumn;
								if (distance[id][nId] == Integer.MAX_VALUE / 2) {
									queueRow[size] = nRow;
									queueColumn[size++] = nColumn;
									distance[id][nId] = distance[id][row * columnCount + column] + 1;
								}
							}
						}
					}
	//				for (int k = 0; k < 4; k++) {
	//					int row = i + MiscUtils.DX4[k];
	//					int column = j + MiscUtils.DY4[k];
	//					if (MiscUtils.isValidCell(row, column, rowCount, columnCount) && map[row][column] != '#') {
	//						distance[id][row * columnCount + column] = 1;
	//					}
	//				}
				}
			}
	//		for (int i = 0; i < rowCount * columnCount; i++) {
	//			for (int j = 0; j < rowCount * columnCount; j++) {
	//				for (int k = 0; k < rowCount * columnCount; k++) {
	//					distance[j][k] = Math.min(distance[j][k], distance[j][i] + distance[i][k]);
	//				}
	//			}
	//		}
			malePosition = new int[Math.max(maleCount, femaleCount)];
			femalePosition = new int[Math.max(maleCount, femaleCount)];
			maleTime = new int[Math.max(maleCount, femaleCount)];
			femaleTime = new int[Math.max(maleCount, femaleCount)];
			if (maleCount < femaleCount) {
				malePosition[maleCount] = read(in);
				maleTime[maleCount] = in.readInt();
			} else {
				femalePosition[femaleCount] = read(in);
				femaleTime[femaleCount] = in.readInt();
			}
			for (int i = 0; i < maleCount; i++) {
				malePosition[i] = read(in);
				maleTime[i] = in.readInt();
			}
			for (int i = 0; i < femaleCount; i++) {
				femalePosition[i] = read(in);
				femaleTime[i] = in.readInt();
			}
			if (!calculate(Long.MAX_VALUE / 2)) {
				out.printLine(-1);
				return;
			}
			long left = 0;
			long right = 23L * 11 * 1000000000;
			while (left < right) {
				long middle = (left * 3 + right) / 4;
				if (calculate(middle)) {
					right = middle;
				} else {
					left = middle + 1;
				}
			}
			out.printLine(left);
		}

	Graph graph = null;
	long last = Long.MAX_VALUE;
	long lastResult;

		private boolean calculate(long time) {
			int source = 2 * malePosition.length + 2 * rowCount * columnCount;
			int sink = source + 1;
			if (time > last) {
				for (int i = 0; i < malePosition.length; i++) {
					for (int j = 0; j < rowCount * columnCount; j++) {
						if (distance[malePosition[i]][j] != Integer.MAX_VALUE / 2 && (long) distance[malePosition[i]][j] * maleTime[i] <= time
							&& (long) distance[malePosition[i]][j] * maleTime[i] > last) {
							graph.addFlowEdge(i, 2 * malePosition.length + j, 1);
						}
						if (distance[femalePosition[i]][j] != Integer.MAX_VALUE / 2 && (long) distance[femalePosition[i]][j] * femaleTime[i] <= time
							&& (long) distance[femalePosition[i]][j] * femaleTime[i] > last) {
							graph.addFlowEdge(2 * malePosition.length + rowCount * columnCount + j, malePosition.length + i, 1);
						}
					}
				}
			} else {
				graph = new Graph(2 * malePosition.length + 2 * rowCount * columnCount + 2);
				lastResult = 0;
				for (int i = 0; i < rowCount * columnCount; i++) {
					graph.addFlowEdge(2 * malePosition.length + i, 2 * malePosition.length + rowCount * columnCount + i, 1);
				}
				for (int i = 0; i < malePosition.length; i++) {
					graph.addFlowEdge(source, i, 1);
					graph.addFlowEdge(i + malePosition.length, sink, 1);
					for (int j = 0; j < rowCount * columnCount; j++) {
						if (distance[malePosition[i]][j] != Integer.MAX_VALUE / 2 && (long) distance[malePosition[i]][j] * maleTime[i] <= time) {
							graph.addFlowEdge(i, 2 * malePosition.length + j, 1);
						}
						if (distance[femalePosition[i]][j] != Integer.MAX_VALUE / 2 && (long) distance[femalePosition[i]][j] * femaleTime[i] <= time) {
							graph.addFlowEdge(2 * malePosition.length + rowCount * columnCount + j, malePosition.length + i, 1);
						}
					}
				}
			}
			lastResult = MaxFlow.dinic(graph, source, sink) + lastResult;
			last = time;
			return  lastResult == malePosition.length;
		}

		private int read(InputReader in) {
			int row = in.readInt() - 1;
			int column = in.readInt() - 1;
			return row * columnCount + column;
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

class IOUtils {

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

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

}

class MiscUtils {
	public static final int[] DX4 = {1, 0, -1, 0};
	public static final int[] DY4 = {0, -1, 0, 1};

	public static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
		return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
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

	public final int addFlowEdge(int from, int to, long capacity) {
		return addFlowWeightedEdge(from, to, 0, capacity);
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

	public final int destination(int id) {
		return to[id];
	}

	public final long capacity(int id) {
		if (capacity == null)
			return 0;
		return capacity[id];
	}

	public final long flow(int id) {
		if (reverseEdge == null)
			return 0;
		return capacity[reverseEdge[id]];
	}

	public final void pushFlow(int id, long flow) {
		if (flow == 0)
			return;
		if (flow > 0) {
			if (capacity(id) < flow)
				throw new IllegalArgumentException("Not enough capacity");
		} else {
			if (flow(id) < -flow)
				throw new IllegalArgumentException("Not enough capacity");
		}
		capacity[id] -= flow;
		capacity[reverseEdge[id]] += flow;
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

class MaxFlow {
	private final Graph graph;
	private int source;
	private int destination;
	private int[] queue;
	private int[] distance;
	private int[] nextEdge;

	public MaxFlow(Graph graph, int source, int destination) {
		this.graph = graph;
		this.source = source;
		this.destination = destination;
		int vertexCount = graph.vertexCount();
		queue = new int[vertexCount];
		distance = new int[vertexCount];
		nextEdge = new int[vertexCount];
	}

	public static long dinic(Graph graph, int source, int destination) {
		return new MaxFlow(graph, source, destination).dinic();
	}

	public long dinic() {
		long totalFlow = 0;
		while (true) {
			edgeDistances();
			if (distance[destination] == -1)
				break;
			Arrays.fill(nextEdge, -2);
			totalFlow += dinicImpl(source, Long.MAX_VALUE);
		}
		return totalFlow;
	}

	private void edgeDistances() {
		Arrays.fill(distance, -1);
		distance[source] = 0;
		int size = 1;
		queue[0] = source;
		for (int i = 0; i < size; i++) {
			int current = queue[i];
			int id = graph.firstOutbound(current);
			while (id != -1) {
				if (graph.capacity(id) != 0) {
					int next = graph.destination(id);
					if (distance[next] == -1) {
						distance[next] = distance[current] + 1;
						queue[size++] = next;
					}
				}
				id = graph.nextOutbound(id);
			}
		}
	}

	private long dinicImpl(int source, long flow) {
		if (source == destination)
			return flow;
		if (flow == 0 || distance[source] == distance[destination])
			return 0;
		int id = nextEdge[source];
		if (id == -2)
			nextEdge[source] = id = graph.firstOutbound(source);
		long totalPushed = 0;
		while (id != -1) {
			int nextDestinationID = graph.destination(id);
			if (graph.capacity(id) != 0 && distance[nextDestinationID] == distance[source] + 1) {
				long pushed = dinicImpl(nextDestinationID, Math.min(flow, graph.capacity(id)));
				if (pushed != 0) {
					graph.pushFlow(id, pushed);
					flow -= pushed;
					totalPushed += pushed;
					if (flow == 0)
						return totalPushed;
				}
			}
			nextEdge[source] = id = graph.nextOutbound(id);
		}
		return totalPushed;
	}
}

interface Edge {
}