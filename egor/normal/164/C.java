import java.util.concurrent.atomic.AtomicBoolean;
import java.util.PriorityQueue;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.HashSet;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Stack;
import java.util.ArrayList;
import java.util.Vector;
import java.util.Iterator;
import java.util.Set;
import java.math.BigInteger;
import java.util.Queue;
import java.util.Collections;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int workerCount = in.readInt();
		int[] start = new int[count];
		int[] time = new int[count];
		int[] profit = new int[count];
		IOUtils.readIntArrays(in, start, time, profit);
		int[] interestingTimes = new int[2 * count];
		for (int i = 0; i < count; i++) {
			interestingTimes[2 * i] = start[i];
			interestingTimes[2 * i + 1] = start[i] + time[i];
		}
		Arrays.sort(interestingTimes);
		Graph graph = new Graph(2 * count + 1);
		for (int i = 1; i < 2 * count; i++)
			graph.add(new FlowEdge(i - 1, i, workerCount));
		FlowEdge[] edges = new FlowEdge[count];
		for (int i = 0; i < count; i++) {
			graph.add(edges[i] = new WeightedFlowEdge(Arrays.binarySearch(interestingTimes, start[i]),
				Arrays.binarySearch(interestingTimes, start[i] + time[i]), -profit[i], 1));
		}
		graph.add(new FlowEdge(2 * count, 0, workerCount));
		GraphAlgorithms.minCostMaxFlow(graph, 2 * count, 2 * count - 1);
		int[] answer = new int[count];
		for (int i = 0; i < count; i++)
			answer[i] = (int) edges[i].getFlow();
		out.printLine(Array.wrap(answer).toArray());
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

class IOUtils {

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

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

interface Edge {
	public int getSource();
	public int getDestination();
	public long getWeight();
	public long getCapacity();
	public void pushFlow(long flow);
	public Edge getReverseEdge();
}

class FlowEdge extends SimpleEdge {
	private long capacity;
	private long flow = 0;
	private Edge reverseEdge;

	public FlowEdge(int source, int destination, long capacity) {
		super(source, destination);
		this.capacity = capacity;
		reverseEdge = new ReverseEdge();
	}

	public long getWeight() {
		return 0;
	}

	public long getCapacity() {
		return capacity;
	}

	public long getFlow() {
		return flow;
	}

	public void pushFlow(long flow) {
		if (flow > 0) {
			if (this.capacity < flow)
				throw new IllegalArgumentException();
		} else {
			if (this.flow < -flow)
				throw new IllegalArgumentException();
		}
		capacity -= flow;
		this.flow += flow;
	}

	public Edge getReverseEdge() {
		return reverseEdge;
	}

	private class ReverseEdge implements Edge {
		public int getSource() {
			return destination;
		}

		public int getDestination() {
			return source;
		}

		public long getWeight() {
			return -FlowEdge.this.getWeight();
		}

		public long getCapacity() {
			return flow;
		}

		public void pushFlow(long flow) {
			FlowEdge.this.pushFlow(-flow);
		}

		public Edge getReverseEdge() {
			return FlowEdge.this;
		}
	}
}

class WeightedFlowEdge extends FlowEdge {
	private final long weight;

	public WeightedFlowEdge(int source, int destination, long weight, long capacity) {
		super(source, destination, capacity);
		this.weight = weight;
	}

	public long getWeight() {
		return weight;
	}

	}

class GraphAlgorithms {

	public static Pair<Long, Long> minCostMaxFlow(Graph graph, int source, int destination) {
		return minCostMaxFlow(graph, source, destination, Long.MAX_VALUE);
	}

	public static Pair<Long, Long> minCostMaxFlow(Graph graph, int source, int destination, long maxFlow) {
		long cost = 0;
		long flow = 0;
		long[] phi = new long[graph.getSize()];
		long[] initialDistances = fordBellman(graph, source, true).first;
		for (int i = 0; i < graph.getSize(); i++) {
			if (initialDistances[i] != Long.MAX_VALUE)
				phi[i] -= initialDistances[i];
		}
		while (maxFlow != 0) {
			Pair<long[], Edge[]> result = dijkstraAlgorithm(graph, source, phi);
			if (result.first[destination] == Long.MAX_VALUE)
				return Pair.makePair(cost, flow);
			for (int i = 0; i < graph.getSize(); i++) {
				if (result.first[i] != Long.MAX_VALUE)
					phi[i] -= result.first[i];
			}
			int vertex = destination;
			long currentFlow = maxFlow;
			long currentCost = 0;
			while (vertex != source) {
				currentFlow = Math.min(currentFlow, result.second[vertex].getCapacity());
				currentCost += result.second[vertex].getWeight();
				vertex = result.second[vertex].getSource();
			}
			maxFlow -= currentFlow;
			cost += currentCost * currentFlow;
			flow += currentFlow;
			vertex = destination;
			while (vertex != source) {
				result.second[vertex].pushFlow(currentFlow);
				vertex = result.second[vertex].getSource();
			}
		}
		return Pair.makePair(cost, flow);
	}

	public static Pair<long[], Edge[]> fordBellman(Graph graph, int source, boolean ignoreEmptyEdges) {
		long[] distances = new long[graph.getSize()];
		Arrays.fill(distances, Long.MAX_VALUE);
		distances[source] = 0;
		Edge[] last = new Edge[graph.getSize()];
		Set<Integer> viable = Collections.singleton(source);
		int stepCount = 0;
		while (!viable.isEmpty()) {
			Set<Integer> nextViable = new HashSet<Integer>();
			for (int i : viable) {
				for (Edge edge : graph.getIncident(i)) {
					long total = distances[i] + edge.getWeight();
					int destination = edge.getDestination();
					if (total < distances[destination] && (!ignoreEmptyEdges || edge.getCapacity() != 0)) {
						distances[destination] = total;
						last[destination] = edge;
						nextViable.add(destination);
					}
				}
			}
			viable = nextViable;
			stepCount++;
			if (stepCount > graph.getSize() + 1)
				return null;
		}
		return Pair.makePair(distances, last);
	}

	public static Pair<long[], Edge[]> dijkstraAlgorithm(Graph graph, int source, long[] phi) {
		int size = graph.getSize();
		final long[] distance = new long[size];
		Queue<Pair<Long, Integer>> queue = new PriorityQueue<Pair<Long, Integer>>(size);
		Edge[] last = new Edge[size];
		Arrays.fill(distance, Long.MAX_VALUE);
		distance[source] = 0;
		queue.add(Pair.makePair(0L, source));
		boolean[] processed = new boolean[size];
		while (!queue.isEmpty()) {
			int current = queue.poll().second;
			if (processed[current])
				continue;
			processed[current] = true;
			for (Edge edge : graph.getIncident(current)) {
				if (edge.getCapacity() == 0)
					continue;
				int next = edge.getDestination();
				long weight = edge.getWeight() + phi[next] - phi[current];
				if (distance[next] > distance[current] + weight) {
					distance[next] = distance[current] + weight;
					last[next] = edge;
					queue.add(Pair.makePair(distance[next], next));
				}
			}
		}
		return Pair.makePair(distance, last);
	}

	}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
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

	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>)first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>)second).compareTo(o.second);
	}
}

abstract class Array<T> extends AbstractList<T> {

	public static List<Integer> wrap(int...array) {
		return new IntArray(array);
	}

	protected static class IntArray extends Array<Integer> {
		protected final int[] array;

		protected IntArray(int[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Integer get(int index) {
			return array[index];
		}

		public Integer set(int index, Integer value) {
			int result = array[index];
			array[index] = value;
			return result;
		}
	}

	}

class SimpleEdge implements Edge {
	protected final int source;
	protected final int destination;

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

	public void pushFlow(long flow) {
		throw new UnsupportedOperationException();
	}

	public Edge getReverseEdge() {
		return null;
	}

	}