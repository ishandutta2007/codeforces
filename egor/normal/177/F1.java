import java.util.NavigableSet;
import java.util.SortedSet;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
import java.util.TreeSet;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
	int[] first;
	int[] second;
	int[] cost;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int edgeCount = in.readInt();
		int index = in.readInt() - 1;
		first = new int[edgeCount];
		second = new int[edgeCount];
		cost = new int[edgeCount];
		IOUtils.readIntArrays(in, first, second, cost);
		NavigableSet<State> set = new TreeSet<State>();
		set.add(new State(0, 0, 0, 0, 0));
		for (int i = 0; i < index; i++) {
			State current = set.pollFirst();
			for (int j = 0; j < edgeCount; j++) {
				State next = current.add(j);
				if (next != null)
					set.add(next);
			}
		}
		out.printLine(set.first().cost);
	}

	class State implements Comparable<State> {
		final int menMask;
		final int womenMask;
		final long firstEdgeMask;
		final long secondEdgeMask;
		final int cost;

		State(int menMask, int womenMask, long firstEdgeMask, long secondEdgeMask, int cost) {
			this.menMask = menMask;
			this.womenMask = womenMask;
			this.firstEdgeMask = firstEdgeMask;
			this.secondEdgeMask = secondEdgeMask;
			this.cost = cost;
		}

		public int compareTo(State o) {
			if (cost != o.cost)
				return cost - o.cost;
			int value = IntegerUtils.longCompare(firstEdgeMask, o.firstEdgeMask);
			if (value != 0)
				return value;
			return IntegerUtils.longCompare(secondEdgeMask, o.secondEdgeMask);
		}

		public State add(int edge) {
			if ((menMask >> first[edge] & 1) != 0 || (womenMask >> second[edge] & 1) != 0)
				return null;
			return new State(menMask + (1 << first[edge]), womenMask + (1 << second[edge]),
				firstEdgeMask + (edge < 64 ? 1L << edge : 0), secondEdgeMask + (edge >= 64 ? 1L << (edge - 64) : 0),
				cost + TaskF.this.cost[edge]);
		}
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

class IntegerUtils {

	public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	}