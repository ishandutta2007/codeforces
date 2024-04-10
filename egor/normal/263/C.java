import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
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
        if (count == 5) {
            out.printLine("1 2 3 4 5");
            return;
        }
        int[] from = new int[count * 2];
        int[] to = new int[count * 2];
        IOUtils.readIntArrays(in, from, to);
        MiscUtils.decreaseByOne(from, to);
        int[][] graph = GraphUtils.buildSimpleGraph(count, from, to);
        for (int i = 0; i < count; i++) {
            if (graph[i].length != 4) {
                out.printLine(-1);
                return;
            }
        }
        if (count == 6) {
            int[] reverse = new int[6];
            for (int i = 0; i < 6; i++) {
                reverse[i] = 15 - i;
                for (int j : graph[i])
                    reverse[i] -= j;
            }
            int[] answer = new int[6];
            int j = 0;
            for (int i = 0; i < 6; i++) {
                if (reverse[i] > i)
                    answer[j++] = i + 1;
            }
            for (int i = 0; i < 3; i++)
                answer[i + 3] = reverse[answer[i] - 1] + 1;
            out.printLine(answer);
            return;
        }
        int[] newFrom = new int[count];
        int[] newTo = new int[count];
        int j = 0;
        for (int i = 0; i < count; i++) {
            for (int k : graph[i]) {
                if (k > i)
                    continue;
                int same = 0;
                for (int l : graph[i]) {
                    for (int m : graph[k]) {
                        if (l == m)
                            same++;
                    }
                }
//                if (same > 2) {
//                    out.printLine(-1);
//                    return;
//                }
                if (same == 2) {
                    if (j == count) {
                        out.printLine(-1);
                        return;
                    }
                    newFrom[j] = i;
                    newTo[j++] = k;
                }
            }
        }
        if (j != count) {
            out.printLine(-1);
            return;
        }
        int[][] original = graph;
        graph = GraphUtils.buildSimpleGraph(count, newFrom, newTo);
        for (int i = 0; i < count; i++) {
            if (graph[i].length != 2) {
                out.printLine(-1);
                return;
            }
        }
        boolean[] visited = new boolean[count];
        int current = 0;
        int[] answer = new int[count];
        for (int i = 0; i < count; i++) {
            answer[i] = current + 1;
            visited[current] = true;
            if (i == count - 1)
                break;
            int next;
            if (visited[graph[current][0]])
                next = graph[current][1];
            else
                next = graph[current][0];
            if (visited[next]) {
                out.printLine(-1);
                return;
            }
            current = next;
        }
        for (int i = 0; i < count; i++) {
            int next = i + 2;
            int next1 = i + 1;
            if (next >= count)
                next -= count;
            next = answer[next] - 1;
            if (next1 >= count)
                next1 -= count;
            next1 = answer[next1] - 1;
            boolean found = false;
            boolean found1 = false;
            for (int k : original[answer[i] - 1]) {
                if (k == next)
                    found = true;
                if (k == next1)
                    found1 = true;
            }
            if (!found || !found1) {
                out.printLine(-1);
                return;
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

    public void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void printLine(int[] array) {
        print(array);
        writer.println();
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