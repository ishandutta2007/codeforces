import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
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
	int[][] size;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] from = new int[count - 1];
		int[] to = new int[count - 1];
		IOUtils.readIntArrays(in, from, to);
		MiscUtils.decreaseByOne(from, to);
		int[][] graph = GraphUtils.buildSimpleGraph(count, from, to);
		boolean[] possible = new boolean[count];
		size = new int[count][count];
		ArrayUtils.fill(size, -1);
		int[] possibleSize = new int[count];
		boolean[] curPossible = new boolean[count];
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < graph[i].length; j++) {
				possibleSize[j] = go(graph[i][j], i, graph);
			}
			Arrays.fill(curPossible, false);
			curPossible[0] = true;
			for (int j = 0; j < graph[i].length; j++) {
				for (int k = count - 1; k >= possibleSize[j]; k--) {
					if (curPossible[k - possibleSize[j]])
						curPossible[k] = true;
				}
			}
			for (int j = 0; j < count; j++)
				possible[j] |= curPossible[j];
		}
		int answer = 0;
		for (int i = 1; i < count - 1; i++) {
			if (possible[i] || possible[count - 1 - i])
				answer++;
		}
		out.printLine(answer);
		for (int i = 1; i < count - 1; i++) {
			if (possible[i] || possible[count - 1 - i])
				out.printLine(i, count - 1 - i);
		}
	}

	private int go(int vertex, int last, int[][] graph) {
		if (size[vertex][last] != -1)
			return size[vertex][last];
		size[vertex][last] = 1;
		for (int i : graph[vertex]) {
			if (i != last)
				size[vertex][last] += go(i, vertex, graph);
		}
		return size[vertex][last];
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

	public static int[][] buildSimpleGraph(int vertexCount, int[] from, int[] to) {
		int[][] graph = buildGraph(vertexCount, from, to);
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

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	}