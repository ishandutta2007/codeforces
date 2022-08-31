import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.util.Collections;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.InputStream;
import java.util.Collection;
import java.io.OutputStreamWriter;

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
		IntPair[] first = new IntPair[count - 3];
		for (int i = 0; i < count - 3; i++) {
			int a = in.readInt() - 1;
			int b = in.readInt() - 1;
			first[i] = new IntPair(a, b);
		}
		List<IntPair> answer = solve(count, first, true);
		IntPair[] second = new IntPair[count - 3];
		for (int i = 0; i < count - 3; i++) {
			int a = in.readInt() - 1;
			int b = in.readInt() - 1;
			second[i] = new IntPair(a, b);
		}
		List<IntPair> secondAnswer = solve(count, second, false);
		Collections.reverse(secondAnswer);
		answer.addAll(secondAnswer);
		out.printLine(answer.size());
		for (IntPair pair : answer) {
			out.printLine(pair.first, pair.second);
		}
	}

	private List<IntPair> solve(int count, IntPair[] edges, boolean direct) {
		boolean[][] g = new boolean[count][count];
		for (int i = 1; i < count; i++) {
			g[i - 1][i] = g[i][i - 1] = true;
		}
		g[0][count - 1] = g[count - 1][0] = true;
		for (IntPair pair : edges) {
			g[pair.first][pair.second] = g[pair.second][pair.first] = true;
		}
		List<IntPair> answer = new ArrayList<>();
		int last = 1;
		for (int i = 2; i < count - 1; i++) {
			if (g[0][i]) {
				solve(last, i, g, answer, direct);
				last = i;
			}
		}
		solve(last, count - 1, g, answer, direct);
		return answer;
	}

	private void solve(int from, int to, boolean[][] g, List<IntPair> answer, boolean direct) {
		if (from + 1 == to) {
			return;
		}
		for (int i = from + 1; i < to; i++) {
			if (g[from][i] && g[i][to]) {
				if (direct) {
					answer.add(new IntPair(from + 1, to + 1));
				} else {
					answer.add(new IntPair(1, i + 1));
				}
				g[from][to] = g[to][from] = false;
				g[0][i] = g[i][0] = true;
				solve(from, i, g, answer, direct);
				solve(i, to, g, answer, direct);
			}
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

	public void printLine(int i) {
		writer.println(i);
	}
}

class IntPair implements Comparable<IntPair> {
	public final int first, second;

	public IntPair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	public String toString() {
		return "(" + first + "," + second + ")";
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		IntPair intPair = (IntPair) o;

		return first == intPair.first && second == intPair.second;

	}

	public int hashCode() {
		int result = first;
		result = 31 * result + second;
		return result;
	}

	public int compareTo(IntPair o) {
		if (first < o.first)
			return -1;
		if (first > o.first)
			return 1;
		if (second < o.second)
			return -1;
		if (second > o.second)
			return 1;
		return 0;
	}
}