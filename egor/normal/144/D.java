import java.util.concurrent.atomic.AtomicBoolean;
import java.util.PriorityQueue;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.AbstractCollection;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Stack;
import java.util.ArrayList;
import java.util.Vector;
import java.util.Iterator;
import java.util.ArrayDeque;
import java.util.Deque;
import java.math.BigInteger;
import java.util.Queue;
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
		int vertexCount = in.readInt();
		int edgeCount = in.readInt();
		int capital = in.readInt() - 1;
		Edge[] edges = new Edge[edgeCount];
		Graph graph = new BidirectionalGraph(vertexCount);
		for (int i = 0; i < edgeCount; i++) {
			int from = in.readInt() - 1;
			int to = in.readInt() - 1;
			int length = in.readInt();
			graph.add(edges[i] = new WeightedEdge(from, to, length));
		}
		int rocketDistance = in.readInt();
		GraphAlgorithms.DistanceResult result = GraphAlgorithms.leviteAlgorithm(graph, capital);
		int answer = 0;
		for (int i = 0; i < vertexCount; i++) {
			if (result.distances[i] == rocketDistance)
				answer++;
		}
		for (Edge edge : edges) {
			if (result.distances[edge.getSource()] < rocketDistance && result.distances[edge.getDestination()] > rocketDistance ||
				result.distances[edge.getSource()] > rocketDistance && result.distances[edge.getDestination()] < rocketDistance)
			{
				answer++;
			} else if (result.distances[edge.getSource()] < rocketDistance || result.distances[edge.getDestination()] < rocketDistance) {
				long delta = 2 * rocketDistance - result.distances[edge.getSource()] - result.distances[edge.getDestination()];
				boolean bothSmaller = result.distances[edge.getSource()] < rocketDistance && result.distances[edge.getDestination()] < rocketDistance;
				if (delta < edge.getWeight())
					answer += bothSmaller ? 2 : 1;
				else if (delta == edge.getWeight())
					answer += bothSmaller ? 1 : 0;
			}
		}
		out.printLine(answer);
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

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

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(outputStream);
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}

interface Edge {
	public int getSource();
	public int getDestination();
	public long getWeight();
	public long getCapacity();
	public Edge getTransposedEdge();
	public Edge getReverseEdge();
}

class Graph {
	private final int size;
	private final List<Edge>[] edges;

	public Graph(int size) {
		this.size = size;
		//noinspection unchecked
		edges = new List[size];
		for (int i = 0; i < size; i++)
			edges[i] = new ArrayList<Edge>();
	}

	public int getSize() {
		return size;
	}

	public List<Edge> getIncident(int vertex) {
		return edges[vertex];
	}

	public void add(Edge edge) {
		edges[edge.getSource()].add(edge);
		edge = edge.getReverseEdge();
		if (edge != null)
			edges[edge.getSource()].add(edge);
	}

	}

class BidirectionalGraph extends Graph {
	public BidirectionalGraph(int size) {
		super(size);
	}

	public void add(Edge edge) {
		super.add(edge);
		super.add(edge.getTransposedEdge());
	}
}

class WeightedEdge extends SimpleEdge {
	private final long weight;

	public WeightedEdge(int source, int destination, long weight) {
		super(source, destination);
		this.weight = weight;
	}

	public long getWeight() {
		return weight;
	}

	public Edge getTransposedEdge() {
		if (transposed == null)
			transposed = new WeightedTransposedEdge();
		return transposed;
	}

	protected class WeightedTransposedEdge extends SimpleTransposedEdge {
		public long getWeight() {
			return weight;
		}
	}
}

class GraphAlgorithms {

	public static class DistanceResult {
		public final long[] distances;
		public final Edge[] last;

		public DistanceResult(long[] distances, Edge[] last) {
			this.distances = distances;
			this.last = last;
		}
	}

	public static DistanceResult leviteAlgorithm(Graph graph, int source) {
		return leviteAlgorithm(graph, source, false);
	}

	public static DistanceResult leviteAlgorithm(Graph graph, int source, boolean ignoreEmpty) {
		int size = graph.getSize();
		Deque<Integer> queue = new ArrayDeque<Integer>(size);
		boolean[] processed = new boolean[size];
		boolean[] notReached = new boolean[size];
		Arrays.fill(notReached, true);
		long[] distance = new long[size];
		Edge[] last = new Edge[size];
		Arrays.fill(distance, Long.MAX_VALUE);
		distance[source] = 0;
		queue.add(source);
		notReached[source] = false;
		int iterationCount = 0;
		while (!queue.isEmpty()) {
			iterationCount++;
			if (iterationCount / size / size / size != 0)
				return null;
			int current = queue.poll();
			processed[current] = true;
			for (Edge edge : graph.getIncident(current)) {
				if (ignoreEmpty && edge.getCapacity() == 0)
					continue;
				int next = edge.getDestination();
				long weight = edge.getWeight();
				if (distance[next] > distance[current] + weight) {
					distance[next] = distance[current] + weight;
					last[next] = edge;
					if (notReached[next]) {
						notReached[next] = false;
						queue.add(next);
					} else if (processed[next]) {
						processed[next] = false;
						queue.addFirst(next);
					}
				}
			}
		}
		return new DistanceResult(distance, last);
	}

	}

class SimpleEdge implements Edge {
	protected final int source;
	protected final int destination;
	protected Edge transposed = null;

	public SimpleEdge(int source, int destination) {
		this.source = source;
		this.destination = destination;
	}

	public int getSource() {
		return source;
	}

	public int getDestination() {
		return destination;
	}

	public long getWeight() {
		return 1;
	}

	public long getCapacity() {
		return 0;
	}

	public Edge getTransposedEdge() {
		if (transposed == null)
			transposed = new SimpleTransposedEdge();
		return transposed;
	}

	public Edge getReverseEdge() {
		return null;
	}

	protected class SimpleTransposedEdge implements Edge {
		public int getSource() {
			return destination;
		}

		public int getDestination() {
			return source;
		}

		public long getWeight() {
			return 1;
		}

		public long getCapacity() {
			return 0;
		}

		public Edge getTransposedEdge() {
			return SimpleEdge.this;
		}

		public Edge getReverseEdge() {
			return null;
		}
	}
}