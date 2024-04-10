import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskD {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	private InputReader in;
	private PrintWriter out;

	private void solve() {
		int roomCount = in.readInt();
		int edgeCount = in.readInt();
		Edge[] edges = new Edge[edgeCount];
		int last = in.readInt() - 1;
		for (int i = 0; i < edgeCount; i++) {
			int next = in.readInt() - 1;
			edges[i] = new SimpleEdge(last, next);
			last = next;
		}
		Graph graph = new BidirectionalGraph(roomCount);
		boolean found = false;
		for (int i = edgeCount - 1; i >= 0; i--) {
			graph.addEdge(edges[i]);
			Edge minimal = findMinimalEdge(edges[i].getSource(), edges[i].getDestination(), graph);
			if (minimal != null) {
				edges[i] = minimal;
				graph.removeEdge(minimal);
				for (i++; i < edgeCount; i++) {
					edges[i] = findMinimalEdge(edges[i - 1].getDestination(), -1, graph);
					graph.removeEdge(edges[i]);
				}
				found = true;
				break;
			}
		}
		if (found) {
			out.print(edges[0].getSource() + 1);
			for (Edge edge : edges)
				out.print(" " + (edge.getDestination() + 1));
			out.println();
		} else
			out.println("No solution");
	}

	private Edge restrictedEdge;
	private Edge reverseRestrictedEdge;
	private int visited;

	private BFSCallback callback = new BFSCallback() {
		public boolean vertexAdded(Graph graph, Edge edge) {
			if (edge == restrictedEdge || edge == reverseRestrictedEdge)
				return false;
			visited++;
			return true;
		}

		public void alreadyVisited(Graph graph, Edge edge) {
		}
	};

	private Edge findMinimalEdge(int source, int destination, Graph graph) {
		List<Edge> edges = graph.getIncident(source);
		Collections.sort(edges, new Comparator<Edge>() {
			public int compare(Edge o1, Edge o2) {
				return o1.getDestination() - o2.getDestination();
			}
		});
		int nonZero = 0;
		int vertexCount = graph.getVertexCount();
		for (int i = 0; i < vertexCount; i++) {
			if (!graph.getIncident(i).isEmpty())
				nonZero++;
		}
		if (edges.size() == 1)
			nonZero--;
		for (Edge edge : edges) {
			if (edge.getDestination() <= destination) {
				continue;
			}
			visited = 1;
			restrictedEdge = edge;
			reverseRestrictedEdge = edge.getTransposedEdge();
			graph.bfs(edge.getDestination(), callback);
			if (visited == nonZero) {
				return edge;
			}
		}
		return null;
	}

	public interface DFSCallback<R, P> {
		public static final Object EMPTY_PARAMETERS = new Object();
		public R enterUnvisitedVertex(Graph graph, int vertex, Edge edge, P parameters);
		public R enterVisitedVertex(Graph graph, int vertex, Edge edge, P parameters);
		public void exitVertex(Graph graph, int vertex, Edge edge, P parameters, R currentResult);
		public P beforeUsingEdge(Graph graph, int vertex, Edge edge, P parameters, R currentResult, Edge nextEdge);
		public boolean afterVisitingEdge(Graph graph, int vertex, Edge edge, P parameters, R currentResult,
				Edge nextEdge, R visitResult, P passedParameters);
	}

	public static abstract class DFSCallbackAdapter<R> implements DFSCallback<R, Object> {
		public R enterUnvisitedVertex(Graph graph, int vertex, Edge edge, Object parameters) {
			return null;
		}

		public R enterVisitedVertex(Graph graph, int vertex, Edge edge, Object parameters) {
			return null;
		}

		public void exitVertex(Graph graph, int vertex, Edge edge, Object parameters, Object currentResult) {
		}

		public Object beforeUsingEdge(Graph graph, int vertex, Edge edge, Object parameters, Object currentResult,
								 Edge nextEdge) {
			return EMPTY_PARAMETERS;
		}

		public boolean afterVisitingEdge(Graph graph, int vertex, Edge edge, Object parameters, Object currentResult, Edge nextEdge,
										 Object visitResult, Object passedParameters)
		{
			return true;
		}
	}

	public interface FullDFSCallback<R, P> extends DFSCallback<R, P> {
		public R start(Graph graph);
		public P beforeEnteringVertex(R currentResult, int startVertex);
		public boolean afterEnteringVertex(R currentResult, int startVertex, R visitResult, P parameters);
		public void finish(Graph graph, R currentResult);
	}

	public static abstract class FullDFSCallbackAdapter<R> extends DFSCallbackAdapter<R>
			implements FullDFSCallback<R, Object>
	{
		public R start(Graph graph) {
			return null;
		}

		public Object beforeEnteringVertex(R currentResult, int startVertex) {
			return EMPTY_PARAMETERS;
		}

		public boolean afterEnteringVertex(R currentResult, int startVertex, R visitResult, Object parameters) {
			return true;
		}

		public void finish(Graph graph, R currentResult) {
		}
	}

	public interface BFSCallback {
		public boolean vertexAdded(Graph graph, Edge edge);
		public void alreadyVisited(Graph graph, Edge edge);
	}

	public interface FullBFSCallback extends BFSCallback {
		public void bfsStarted(Graph graph, int vertex);
	}

	public interface Edge {
		public int getSource();
		public int getDestination();
		public int getWeight();
		public int getCapacity();
		public int getFlow();
		public void pushFlow(int flow);
		public Edge getTransposedEdge();
	}

	public static class SimpleEdge implements Edge {
		protected final int source;
		protected final int destination;
		protected final TransposedEdge transposed;

		public SimpleEdge(int source, int destination) {
			this.source = source;
			this.destination = destination;
			transposed = new TransposedEdge(this);
		}

		public int getSource() {
			return source;
		}

		public int getDestination() {
			return destination;
		}

		public int getWeight() {
			return 1;
		}

		public int getCapacity() {
			return 0;
		}

		public int getFlow() {
			return 0;
		}

		public void pushFlow(int flow) {
			throw new UnsupportedOperationException();
		}

		public Edge getTransposedEdge() {
			return transposed;
		}
	}

	public static class WeightedEdge extends SimpleEdge {
		protected final int weight;

		public WeightedEdge(int source, int destination, int weight) {
			super(source, destination);
			this.weight = weight;
		}

		@Override
		public int getWeight() {
			return weight;
		}

		@Override
		public Edge getTransposedEdge() {
			return new WeightedEdge(destination, source, weight);
		}
	}

	public static class FlowEdge extends SimpleEdge {
		protected int capacity;
		private int flow = 0;

		public FlowEdge(int source, int destination, int capacity) {
			super(source, destination);
			this.capacity = capacity;
		}

		@Override
		public int getCapacity() {
			return capacity;
		}

		@Override
		public int getFlow() {
			return flow;
		}

		@Override
		public void pushFlow(int flow) {
			if (this.capacity < flow)
				throw new IllegalArgumentException("Not enough capacity");
			if (this.flow < -flow)
				throw new IllegalArgumentException("Not enough flow");
			this.flow += flow;
			this.capacity -= flow;
		}

		@Override
		public int getWeight() {
			return 0;
		}

		@Override
		public Edge getTransposedEdge() {
			return new FlowEdge(destination, source, capacity);
		}

		public Edge getReverseEdge() {
			return new ReverseEdge(this);
		}

		protected static class ReverseEdge implements Edge {
			private final FlowEdge parent;

			public ReverseEdge(FlowEdge edge) {
				parent = edge;
			}

			public int getSource() {
				return parent.getDestination();
			}

			public int getDestination() {
				return parent.getSource();
			}

			public int getWeight() {
				return -parent.getWeight();
			}

			public int getCapacity() {
				return parent.getFlow();
			}

			public int getFlow() {
				return 0;
			}

			public void pushFlow(int flow) {
				parent.pushFlow(-flow);
			}

			public Edge getTransposedEdge() {
				throw new UnsupportedOperationException();
			}
		}
	}

	public static class WeightedFlowEdge extends FlowEdge {
		protected final int weight;

		public WeightedFlowEdge(int source, int destination, int capacity, int weight) {
			super(source, destination, capacity);
			this.weight = weight;
		}

		@Override
		public int getWeight() {
			return weight;
		}

		@Override
		public Edge getTransposedEdge() {
			return new WeightedFlowEdge(destination, source, capacity, weight);
		}
	}

	public static class TransposedEdge implements Edge {
		private final Edge parent;

		public TransposedEdge(Edge parent) {
			this.parent = parent;
		}

		public int getSource() {
			return parent.getDestination();
		}

		public int getDestination() {
			return parent.getSource();
		}

		public int getWeight() {
			return parent.getWeight();
		}

		public int getCapacity() {
			return 0;
		}

		public int getFlow() {
			return 0;
		}

		public void pushFlow(int flow) {
			throw new UnsupportedOperationException();
		}

		public Edge getTransposedEdge() {
			return parent;
		}
	}

	public interface Graph {
		public int getVertexCount();
		public List<Edge> getIncident(int source);
		public void addEdge(Edge edge);
		public <R, P> R dfs(int startVertex, DFSCallback<R, P> callback, P parameters);
		public <R, P> R fullDFS(FullDFSCallback<R, P> callback);
		public <R, P> R fullDFS(FullDFSCallback<R, P> callback, int[] order);
		public void bfs(int startVertex, BFSCallback callback);
		public void fullBFS(FullBFSCallback callback);
		public void fullBFS(FullBFSCallback callback, int[] order);
		public List<Edge> getEdges();
		public Graph transposed();
		public void removeEdge(Edge edge);
	}

	public static class BidirectionalGraph extends SparseGraph {
		public BidirectionalGraph(int vertexCount) {
			super(vertexCount);
		}

		@Override
		public void addEdge(Edge edge) {
			super.addEdge(edge);
			super.addEdge(edge.getTransposedEdge());
		}

		@Override
		public Graph transposed() {
			return this;
		}

		public void removeEdge(Edge edge) {
			super.removeEdge(edge);
			super.removeEdge(edge.getTransposedEdge());
		}
	}

	public static class SparseGraph implements Graph {
		private final int vertexCount;
		private final List<Edge>[] edges;
		private List<Edge> allEdges = null;

		public SparseGraph(int vertexCount) {
			this.vertexCount = vertexCount;
			//noinspection unchecked
			edges = new List[vertexCount];
			for (int i = 0; i < vertexCount; i++)
				edges[i] = new ArrayList<Edge>();
		}

		public int getVertexCount() {
			return vertexCount;
		}

		public void addEdge(Edge edge) {
			allEdges = null;
			edges[edge.getSource()].add(edge);
			if (edge instanceof FlowEdge)
				edges[edge.getDestination()].add(((FlowEdge)edge).getReverseEdge());
		}

		public <R, P> R dfs(int startVertex, DFSCallback<R, P> callback, P parameters) {
			boolean[] visited  = new boolean[vertexCount];
			return dfsImpl(startVertex, callback, visited, parameters, null);
		}

		public <R, P> R fullDFS(FullDFSCallback<R, P> callback) {
			boolean[] visited = new boolean[vertexCount];
			R result = callback.start(this);
			for (int i = 0; i < vertexCount; i++) {
				P parameters = callback.beforeEnteringVertex(result, i);
				if (parameters == null)
					continue;
				R currentResult = dfsImpl(i, callback, visited, parameters, null);
				if (!callback.afterEnteringVertex(result, i, currentResult, parameters))
					break;
			}
			callback.finish(this, result);
			return result;
		}

		public <R, P> R fullDFS(FullDFSCallback<R, P> callback, int[] order) {
			boolean[] visited = new boolean[vertexCount];
			R result = callback.start(this);
			for (int i : order) {
				P parameters = callback.beforeEnteringVertex(result, i);
				if (parameters == null)
					continue;
				R currentResult = dfsImpl(i, callback, visited, parameters, null);
				if (!callback.afterEnteringVertex(result, i, currentResult, parameters))
					break;
			}
			callback.finish(this, result);
			return result;
		}

		public void bfs(int startVertex, BFSCallback callback) {
			boolean[] visited = new boolean[vertexCount];
			bfsImpl(startVertex, callback, visited);
		}

		private void bfsImpl(int startVertex, BFSCallback callback, boolean[] visited) {
			if (visited[startVertex])
				return;
			Queue<Integer> queue = new ArrayDeque<Integer>(vertexCount);
			queue.add(startVertex);
			visited[startVertex] = true;
			while (!queue.isEmpty()) {
				int currentVertex = queue.poll();
				for (Edge edge : getIncident(currentVertex)) {
					int destination = edge.getDestination();
					if (!visited[destination] && callback.vertexAdded(this, edge)) {
						visited[destination] = true;
						queue.add(destination);
					} else if (visited[destination])
						callback.alreadyVisited(this, edge);
				}
			}
		}

		public void fullBFS(FullBFSCallback callback) {
			boolean[] visited = new boolean[vertexCount];
			for (int i = 0; i < vertexCount; i++) {
				if (!visited[i]) {
					callback.bfsStarted(this, i);
					bfsImpl(i, callback, visited);
				}
			}
		}

		public void fullBFS(FullBFSCallback callback, int[] order) {
			boolean[] visited = new boolean[vertexCount];
			for (int i : order) {
				if (!visited[i]) {
					callback.bfsStarted(this, i);
					bfsImpl(i, callback, visited);
				}
			}
		}

		public List<Edge> getEdges() {
			if (allEdges != null)
				return allEdges;
			allEdges = new ArrayList<Edge>();
			for (int i = 0; i < vertexCount; i++)
				allEdges.addAll(getIncident(i));
			return allEdges;
		}

		public Graph transposed() {
			Graph graph = new SparseGraph(vertexCount);
			for (Edge edge : getEdges())
				graph.addEdge(edge.getTransposedEdge());
			return graph;
		}

		public void removeEdge(Edge edge) {
			edges[edge.getSource()].remove(edge);
		}

		private <R, P> R dfsImpl(int vertex, DFSCallback<R, P> callback, boolean[] visited, P parameters, Edge edge) {
			if (visited[vertex])
				return callback.enterVisitedVertex(this, vertex, edge, parameters);
			R result = callback.enterUnvisitedVertex(this, vertex, edge, parameters);
			visited[vertex] = true;
			for (Edge nextEdge : getIncident(vertex)) {
				P passedParameters = callback.beforeUsingEdge(this, vertex, edge, parameters, result,
						nextEdge);
				if (passedParameters == null) {
					if (!callback.afterVisitingEdge(this, vertex, edge, parameters, result, nextEdge, null, null))
						break;
					continue;
				}
				if (!callback.afterVisitingEdge(this, vertex, edge, parameters, result, nextEdge,
						dfsImpl(nextEdge.getDestination(), callback, visited, passedParameters, nextEdge),
						passedParameters))
				{
					break;
				}
			}
			callback.exitVertex(this, vertex, edge, parameters, result);
			return result;
		}

		public List<Edge> getIncident(int source) {
			return edges[source];
		}
	}

	public static void main(String[] args) {
		new TaskD().run();
	}

	private TaskD() {
		@SuppressWarnings({"UnusedDeclaration"})
		String id = getClass().getName().toLowerCase();
		//noinspection EmptyTryBlock
		try {
//			System.setIn(new FileInputStream(id + ".in"));
//			System.setOut(new PrintStream(new FileOutputStream(id + ".out")));
//			System.setIn(new FileInputStream("input.txt"));
//			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	private void run() {
		//noinspection InfiniteLoopStatement
//		int testCount = in.readInt();
//		for (int i = 0; i < testCount; i++)
//		while (true)
		solve();
		exit();
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private void exit() {
		out.close();
		System.exit(0);
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar, numChars;

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

		public long readLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
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
			StringBuffer res = new StringBuffer();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private String readLine0() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				if (c != '\r')
					buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		public String readLine() {
			String s = readLine0();
			while (s.trim().length() == 0)
				s = readLine0();
			return s;
		}

		public String readLine(boolean ignoreEmptyLines) {
			if (ignoreEmptyLines)
				return readLine();
			else
				return readLine0();
		}

		public BigInteger readBigInteger() {
			try {
				return new BigInteger(readString());
			} catch (NumberFormatException e) {
				throw new InputMismatchException();
			}
		}

		public char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		public double readDouble() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') {
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) {
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, readInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}

		public int[] readIntArray(int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = readInt();
			return array;
		}

		public long[] readLongArray(int size) {
			long[] array = new long[size];
			for (int i = 0; i < size; i++)
				array[i] = readLong();
			return array;
		}

		public double[] readDoubleArray(int size) {
			double[] array = new double[size];
			for (int i = 0; i < size; i++)
				array[i] = readDouble();
			return array;
		}

		public String[] readStringArray(int size) {
			String[] array = new String[size];
			for (int i = 0; i < size; i++)
				array[i] = readString();
			return array;
		}

		public char[][] readTable(int rowCount, int columnCount) {
			char[][] table = new char[rowCount][columnCount];
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++)
					table[i][j] = readCharacter();
			}
			return table;
		}

		public void readIntArrays(int[]... arrays) {
			for (int i = 0; i < arrays[0].length; i++) {
				for (int j = 0; j < arrays.length; j++)
					arrays[j][i] = readInt();
			}
		}
	}
}