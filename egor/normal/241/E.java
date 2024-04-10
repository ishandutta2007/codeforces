import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int edgeCount = in.readInt();
		int[] from = new int[edgeCount];
		int[] to = new int[edgeCount];
		IOUtils.readIntArrays(in, from, to);
		MiscUtils.decreaseByOne(from, to);
		int[][] graph = GraphUtils.buildSimpleOrientedGraph(count, from, to);
		int[][] reverse = GraphUtils.buildSimpleOrientedGraph(count, to, from);
		boolean[] interesting = new boolean[count];
		interesting[0] = true;
		for (int i = 0; i < count; i++) {
			if (interesting[i]) {
				for (int j : graph[i])
					interesting[j] = true;
			}
		}
		boolean[] reverseInteresting = new boolean[count];
		reverseInteresting[count - 1] = true;
		for (int i = count - 1; i >= 0; i--) {
			if (reverseInteresting[i]) {
				for (int j : reverse[i])
					reverseInteresting[j] = true;
			}
		}
		for (int i = 0; i < count; i++)
			interesting[i] &= reverseInteresting[i];
		int[] min = new int[count];
		int[] max = new int[count];
		Arrays.fill(min, Integer.MIN_VALUE);
		Arrays.fill(max, Integer.MAX_VALUE);
		min[0] = max[0] = 0;
		while (true) {
			boolean updated = false;
			for (int i = 0; i < count; i++) {
				if (!interesting[i])
					continue;
				for (int j : graph[i]) {
					if (!interesting[j])
						continue;
					if (min[j] < min[i] + 1) {
						min[j] = min[i] + 1;
						updated = true;
					}
					if (max[j] > max[i] + 2) {
						max[j] = max[i] + 2;
						updated = true;
					}
				}
			}
			for (int i = count - 1; i >= 0; i--) {
				if (!interesting[i])
					continue;
				for (int j : reverse[i]) {
					if (!interesting[j])
						continue;
					if (min[j] < min[i] - 2) {
						min[j] = min[i] - 2;
						updated = true;
					}
					if (max[j] > max[i] - 1) {
						max[j] = max[i] - 1;
						updated = true;
					}
				}
			}
			for (int i = 0; i < count; i++) {
				if (interesting[i] && min[i] > max[i]) {
					out.printLine("No");
					return;
				}
			}
			if (!updated)
				break;
		}
		out.printLine("Yes");
		for (int i = 0; i < edgeCount; i++) {
			if (!interesting[from[i]] || !interesting[to[i]])
				out.printLine(1);
			else
				out.printLine(min[to[i]] - min[from[i]]);
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

class MiscUtils {

	public static void decreaseByOne(int[]...arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

	}

class GraphUtils {

	public static int[][] buildOrientedGraph(int vertexCount, int[] from, int[] to) {
		int edgeCount = from.length;
		int[] degree = new int[vertexCount];
		for (int i = 0; i < edgeCount; i++)
			degree[from[i]]++;
		int[][] graph = new int[vertexCount][];
		for (int i = 0; i < vertexCount; i++)
			graph[i] = new int[degree[i]];
		for (int i = 0; i < edgeCount; i++)
			graph[from[i]][--degree[from[i]]] = i;
		return graph;
	}

	public static int otherVertex(int vertex, int from, int to) {
		return from + to - vertex;
	}

	public static int[][] buildSimpleOrientedGraph(int vertexCount, int[] from, int[] to) {
		int[][] graph = buildOrientedGraph(vertexCount, from, to);
		simplifyGraph(from, to, graph);
		return graph;
	}

	private static void simplifyGraph(int[] from, int[] to, int[][] graph) {
		for (int i = 0; i < graph.length; i++) {
			for (int j = 0; j < graph[i].length; j++) {
				graph[i][j] = otherVertex(i, from[graph[i][j]], to[graph[i][j]]);
			}
		}
	}
}