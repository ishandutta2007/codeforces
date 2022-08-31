import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	int[][] graph;
	int[] first, second;
	int[] degree;
	boolean[] taken;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		first = new int[count];
		second = new int[count];
		taken = new boolean[count];
		IOUtils.readIntArrays(in, first, second);
		IndependentSetSystem setSystem = new RecursiveIndependentSetSystem(7);
		for (int i = 0; i < count; i++)
			setSystem.join(first[i], second[i]);
		int type = setSystem.get(first[0]);
		for (int i = 1; i < count; i++) {
			if (type != setSystem.get(first[i])) {
				out.printLine("No solution");
				return;
			}
		}
		degree = new int[7];
		for (int i : first)
			degree[i]++;
		for (int i : second)
			degree[i]++;
		int total = 0;
		for (int i = 0; i <= 6; i++)
			total += degree[i] % 2;
		if (total > 2) {
			out.printLine("No solution");
			return;
		}
		int start = -1;
		int end = -1;
		for (int i = 0; i <= 6; i++) {
			if (degree[i] % 2 != 0) {
				if (start == -1)
					start = i;
				else
					end = i;
			}
		}
		if (start == -1)
			start = end = first[0];
		graph = GraphUtils.buildGraph(7, first, second);
		List<Edge> answer = findPath(start, end);
		while (answer.size() != count) {
			for (int i = 0; i <= 6; i++) {
				boolean found = i == end;
				for (Edge edge : answer) {
					if (edge.direction && second[edge.index] == i || !edge.direction && first[edge.index] == i) {
						found = true;
						break;
					}
				}
				if (!found)
					continue;
				while (degree[i] != 0) {
					List<Edge> path = findPath(i, i);
					int addAt = -1;
					if (i == end)
						addAt = 0;
					else {
						for (int j = 0; j < answer.size(); j++) {
							Edge edge = answer.get(j);
							if (edge.direction && second[edge.index] == i || !edge.direction && first[edge.index] == i) {
								addAt = j + 1;
								break;
							}
						}
					}
					answer.addAll(addAt, path);
				}
			}
		}
		for (Edge edge : answer)
			out.printLine(edge.index + 1, edge.direction ? '+' : '-');
	}

	private List<Edge> findPath(int start, int end) {
		for (int i : graph[start]) {
			if (taken[i])
				continue;
			taken[i] = true;
			int other = GraphUtils.otherVertex(start, first[i], second[i]);
			List<Edge> result;
			if (other == end)
				result = new ArrayList<Edge>();
			else
				result = findPath(other, end);
			result.add(new Edge(i, second[i] == start));
			degree[first[i]]--;
			degree[second[i]]--;
			return result;
		}
		throw new RuntimeException();
	}

	static class Edge {
		final int index;
		final boolean direction;

		Edge(int index, boolean direction) {
			this.index = index;
			this.direction = direction;
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

interface IndependentSetSystem {
	public boolean join(int first, int second);

	public int get(int index);

	public static interface Listener {
		public void joined(int joinedRoot, int root);
	}
}

class RecursiveIndependentSetSystem implements IndependentSetSystem {
	private final int[] color;
	private int setCount;
	private Listener listener;

	public RecursiveIndependentSetSystem(int size) {
		color = new int[size];
		for (int i = 0; i < size; i++)
			color[i] = i;
		setCount = size;
	}

	public RecursiveIndependentSetSystem(RecursiveIndependentSetSystem other) {
		color = other.color.clone();
		setCount = other.setCount;
	}

	public boolean join(int first, int second) {
		first = get(first);
		second = get(second);
		if (first == second)
			return false;
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

class GraphUtils {
	public static int[][] buildGraph(int vertexCount, int[] from, int[] to) {
		int edgeCount = from.length;
		int[] degree = new int[vertexCount];
		for (int i = 0; i < edgeCount; i++) {
			degree[from[i]]++;
			degree[to[i]]++;
		}
		int[][] graph = new int[vertexCount][];
		for (int i = 0; i < vertexCount; i++)
			graph[i] = new int[degree[i]];
		for (int i = 0; i < edgeCount; i++) {
			graph[from[i]][--degree[from[i]]] = i;
			graph[to[i]][--degree[to[i]]] = i;
		}
		return graph;
	}

	public static int otherVertex(int vertex, int from, int to) {
		return from + to - vertex;
	}

	}