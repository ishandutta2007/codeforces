import java.util.concurrent.atomic.AtomicBoolean;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.HashMap;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.HashSet;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Stack;
import java.util.ArrayList;
import java.util.Vector;
import java.util.Iterator;
import java.util.Set;
import java.util.NoSuchElementException;
import java.util.Queue;
import java.math.BigInteger;
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
		int edgeCount = in.readInt();
		Graph<Integer> graph = new BidirectionalGraph<Integer>();
		for (int i = 0; i < edgeCount; i++) {
			int from = in.readInt();
			int to = in.readInt();
			graph.add(new SimpleEdge<Integer>(from, to));
		}
		final Pair<Map<Integer,Long>,Map<Integer,Edge<Integer>>> firstDistance = GraphAlgorithms.dijkstraAlgorithm(graph, 1);
		final Pair<Map<Integer,Long>,Map<Integer,Edge<Integer>>> secondDistance = GraphAlgorithms.dijkstraAlgorithm(graph, count);
		double[] firstCount = getCount(count, graph, firstDistance, 1);
		double[] secondCount = getCount(count, graph, secondDistance, count);
		double answer = 1;
		for (int i = 2; i < count; i++) {
			if (firstDistance.first.get(i) + secondDistance.first.get(i) == firstDistance.first.get(count))
				answer = Math.max(answer, 2 * firstCount[i] * secondCount[i] / firstCount[count]);
		}
		out.printLine(answer);
	}

	private double[] getCount(int count, Graph<Integer> graph, final Pair<Map<Integer, Long>, Map<Integer, Edge<Integer>>> distance, int start) {
		double[] firstCount = new double[count + 1];
		firstCount[start] = 1;
		int[] order = new int[count];
		for (int i = 0; i < count; i++)
			order[i] = i + 1;
		ArrayUtils.sort(order, new IntComparator() {
			public int compare(int first, int second) {
				return IntegerUtils.longCompare(distance.first.get(first), distance.first.get(second));
			}
		});
		for (int i : order) {
			for (Edge<Integer> edge : graph.getIncident(i)) {
				if (distance.first.get(edge.getDestination()) + 1 == distance.first.get(i))
					firstCount[i] += firstCount[edge.getDestination()];
			}
		}
		return firstCount;
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
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
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

class Graph<V> {
	private Map<V, Edge<V>> firstEdge = new HashMap<V, Edge<V>>();
	private Map<Edge<V>, Edge<V>> nextEdge = new HashMap<Edge<V>, Edge<V>>();
	private Map<Edge<V>, Edge<V>> lastEdge = new HashMap<Edge<V>, Edge<V>>();

	public Iterable<Edge<V>> getIncident(final V vertex) {
		return new Iterable<Edge<V>>() {
			public Iterator<Edge<V>> iterator() {
				return new EdgeIterator(vertex);
			}
		};
	}

	public void add(Edge<V> edge) {
		addImpl(edge);
		edge = edge.getReverseEdge();
		if (edge != null)
			addImpl(edge);
	}

	private void addImpl(Edge<V> edge) {
		V source = edge.getSource();
		if (firstEdge.containsKey(source)) {
			Edge<V> last = firstEdge.get(source);
			lastEdge.put(last, edge);
			nextEdge.put(edge, last);
		}
		firstEdge.put(source, edge);
	}

	public void remove(Edge<V> edge) {
		removeImpl(edge);
		edge = edge.getReverseEdge();
		if (edge != null)
			removeImpl(edge);
	}

	private void removeImpl(Edge<V> edge) {
		V source = edge.getSource();
		if (firstEdge.containsKey(source)) {
			Edge<V> next = nextEdge.get(edge);
			Edge<V> last = lastEdge.get(edge);
			if (last == null) {
				if (next == null)
					firstEdge.remove(source);
				else {
					firstEdge.put(source, next);
					lastEdge.remove(next);
				}
			} else if (next == null)
				nextEdge.remove(last);
			else {
				nextEdge.put(last, next);
				lastEdge.put(next, last);
			}
			nextEdge.remove(edge);
			lastEdge.remove(edge);
		}
	}

	private class EdgeIterator implements Iterator<Edge<V>> {
		private Edge<V> current, last;

		public EdgeIterator(V vertex) {
			current = firstEdge.get(vertex);
		}

		public boolean hasNext() {
			return current != null;
		}

		public Edge<V> next() {
			if (!hasNext())
				throw new NoSuchElementException();
			last = current;
			current = nextEdge.get(current);
			return last;
		}

		public void remove() {
			if (last == null)
				throw new IllegalStateException();
			Graph.this.remove(last);
			last = null;
		}
	}
}

class BidirectionalGraph<V> extends Graph<V> {
	public void add(Edge<V> edge) {
		super.add(edge);
		super.add(edge.getTransposedEdge());
	}

	public void remove(Edge<V> edge) {
		super.remove(edge);
		super.remove(edge.getTransposedEdge());
	}
}

interface Edge<V> {
	public V getSource();
	public V getDestination();
	public long getWeight();
	public Edge<V> getTransposedEdge();
	public Edge<V> getReverseEdge();
	}

class SimpleEdge<V> implements Edge<V> {
	protected final V source;
	protected final V destination;
	protected Edge<V> transposed = null;

	public SimpleEdge(V source, V destination) {
		this.source = source;
		this.destination = destination;
	}

	public V getSource() {
		return source;
	}

	public V getDestination() {
		return destination;
	}

	public long getWeight() {
		return 1;
	}

	public Edge<V> getTransposedEdge() {
		if (transposed == null)
			transposed = new SimpleTransposedEdge();
		return transposed;
	}

	public Edge<V> getReverseEdge() {
		return null;
	}

	protected class SimpleTransposedEdge implements Edge<V> {
		public V getSource() {
			return destination;
		}

		public V getDestination() {
			return source;
		}

		public long getWeight() {
			return 1;
		}

		public Edge<V> getTransposedEdge() {
			return SimpleEdge.this;
		}

		public Edge<V> getReverseEdge() {
			return null;
		}

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

class GraphAlgorithms {

	public static<V> Pair<Map<V, Long>, Map<V, Edge<V>>> dijkstraAlgorithm(Graph<V> graph, V source) {
		Map<V, Long> distance = new HashMap<V, Long>();
		Queue<Pair<Long, V>> queue = new PriorityQueue<Pair<Long, V>>();
		Map<V, Edge<V>> last = new HashMap<V, Edge<V>>();
		distance.put(source, 0L);
		queue.add(Pair.makePair(0L, source));
		Set<V> processed = new HashSet<V>();
		while (!queue.isEmpty()) {
			V current = queue.poll().second;
			if (processed.contains(current))
				continue;
			processed.add(current);
			for (Edge<V> edge : graph.getIncident(current)) {
				V next = edge.getDestination();
				long total = edge.getWeight() + distance.get(current);
				if (!distance.containsKey(next) || distance.get(next) > total) {
					distance.put(next, total);
					last.put(next, edge);
					queue.add(Pair.makePair(total, next));
				}
			}
		}
		return Pair.makePair(distance, last);
	}

	}

class ArrayUtils {
    private static int[] tempInt = new int[0];

	public static int[] sort(int[] array, IntComparator comparator) {
        return sort(array, 0, array.length, comparator);
    }

    public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
        ensureCapacityInt(to - from);
        System.arraycopy(array, from, tempInt, 0, to - from);
        sortImpl(array, from, to, tempInt, 0, to - from, comparator);
        return array;
    }

    private static void ensureCapacityInt(int size) {
        if (tempInt.length >= size)
            return;
        size = Math.max(size, tempInt.length << 1);
        tempInt = new int[size];
    }

    private static void sortImpl(int[] array, int from, int to, int[] temp, int fromTemp, int toTemp, IntComparator comparator) {
        if (to - from <= 1)
            return;
        int middle = (to - from) >> 1;
        int tempMiddle = fromTemp + middle;
        sortImpl(temp, fromTemp, tempMiddle, array, from, from + middle, comparator);
        sortImpl(temp, tempMiddle, toTemp, array, from + middle, to, comparator);
        int index = from;
        int index1 = fromTemp;
        int index2 = tempMiddle;
        while (index1 < tempMiddle && index2 < toTemp) {
            if (comparator.compare(temp[index1], temp[index2]) <= 0)
                array[index++] = temp[index1++];
            else
                array[index++] = temp[index2++];
        }
        if (index1 != tempMiddle)
            System.arraycopy(temp, index1, array, index, tempMiddle - index1);
        if (index2 != toTemp)
            System.arraycopy(temp, index2, array, index, toTemp - index2);
    }

    }

interface IntComparator {

    public int compare(int first, int second);
}

class IntegerUtils {

    public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	}