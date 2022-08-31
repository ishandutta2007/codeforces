import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
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
		TaskG1 solver = new TaskG1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG1 {
	int count;
	int[] min, max;
	int[][] ways;
	private SuffixAutomaton automaton;
	int length;
	StringBuilder all;
	int[] help;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		String s = in.readString();
		length = s.length();
		count = in.readInt();
		String[] t = new String[count];
		min = new int[count];
		max = new int[count];
		for (int i = 0; i < count; i++) {
			t[i] = in.readString();
			min[i] = in.readInt();
			max[i] = in.readInt();
		}
		all = new StringBuilder();
		all.append(s);
		all.append((char)count);
		for (int i = 0; i < count; i++) {
			all.append(t[i]);
			all.append((char)i);
		}
		automaton = new SuffixAutomaton(all);
		int x = 0;
		help = new int[automaton.size];
		for (int i = 0; i < all.length(); i++) {
			x = automaton.to[automaton.findEdge(x, all.charAt(i))];
			int xx = x;
			while (xx != -1 && help[xx] == 0) {
				help[xx] = i + 1;
				xx = automaton.link[xx];
			}
		}
		ways = new int[count + 1][automaton.size];
		ArrayUtils.fill(ways, -1);
		long answer = go(0);
		out.printLine(answer);
    }

	private long go(int vertex) {
		if (ways[0][vertex] != -1)
			return 0;
		ArrayUtils.fillColumn(ways, vertex, 0);
		int id = automaton.first[vertex];
		long result = 0;
		while (id != -1) {
			result += go(automaton.to[id]);
			if (automaton.label[id] <= count)
				ways[automaton.label[id]][vertex]++;
			else {
				for (int i = 0; i <= count; i++)
					ways[i][vertex] += ways[i][automaton.to[id]];
			}
			id = automaton.next[id];
		}
		if (vertex != 0) {
			boolean good = true;
			for (int i = 0; i < count; i++) {
				if (ways[i][vertex] < min[i] || ways[i][vertex] > max[i]) {
					good = false;
					break;
				}
			}
			long multiplier = Math.max(0, Math.min(automaton.length[vertex], length) - automaton.length[automaton.link[vertex]]);
			if (good && ways[count][vertex] != 0)
				result += multiplier;
		}
		return result;
	}
}

class SuffixAutomaton {
    public final int[] length;
    public final int[] link;
    public final int[] first;
    public final int[] next;
    public final int[] to;
    public final int[] label;
    public int size;
    public int last;
	public int edgeSize;

	public SuffixAutomaton(final CharSequence s) {
        this(new IntList() {
            @Override
            public int get(int index) {
                return s.charAt(index);
            }

            public void set(int index, int value) {
                throw new UnsupportedOperationException();
            }

            @Override
            public int size() {
                return s.length();
            }

            public void add(int value) {
                throw new UnsupportedOperationException();
            }
        });
    }

    public SuffixAutomaton(IntList s) {
        int count = s.size();
        length = new int[2 * count];
        link = new int[2 * count];
        first = new int[2 * count];
        next = new int[4 * count];
        label = new int[4 * count];
        to = new int[4 * count];
        Arrays.fill(first, -1);
        link[0] = -1;
        size = 1;
        edgeSize = 0;
        last = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s.get(i);
            int current = size++;
            length[current] = length[last] + 1;
            for (int previous = last; ; previous = link[previous]) {
                if (previous == -1) {
                    link[current] = 0;
                    break;
                }
                int index = findEdge(previous, c);
                if (index != -1) {
                    int curLink = to[index];
                    if (length[previous] + 1 == length[curLink])
                        link[current] = curLink;
                    else {
                        int clone = size++;
                        length[clone] = length[previous] + 1;
                        link[clone] = link[curLink];
                        int linkEdge = first[curLink];
                        while (linkEdge != -1) {
                            next[edgeSize] = first[clone];
                            first[clone] = edgeSize;
                            label[edgeSize] = label[linkEdge];
                            to[edgeSize++] = to[linkEdge];
                            linkEdge = next[linkEdge];
                        }
                        for (; previous != -1; previous = link[previous]) {
                            int edge = findEdge(previous, c);
                            if (edge == -1 || to[edge] != curLink)
                                break;
                            to[edge] = clone;
                        }
                        link[current] = link[curLink] = clone;
                    }
                    break;
                }
                next[edgeSize] = first[previous];
                first[previous] = edgeSize;
                label[edgeSize] = c;
                to[edgeSize++] = current;
            }
            last = current;
        }
    }

    public int findEdge(int vertex, int label) {
        int edge = first[vertex];
        while (edge != -1) {
            if (this.label[edge] == label)
                return edge;
            edge = next[edge];
        }
        return -1;
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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
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

class ArrayUtils {

	public static void fillColumn(int[][] array, int index, int value) {
		for (int[] row : array)
			row[index] = value;
	}

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	}

abstract class IntList extends IntCollection implements Comparable<IntList> {

	public abstract int get(int index);

	public IntIterator iterator() {
		return new IntIterator() {
			private int size = size();
			private int index = 0;

			public int value() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				return get(index);
			}

			public void advance() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				index++;
			}

			public boolean isValid() {
				return index < size;
			}
		};
	}

	public int hashCode() {
		int hashCode = 1;
		for (IntIterator i = iterator(); i.isValid(); i.advance())
			hashCode = 31 * hashCode + i.value();
		return hashCode;
	}

	public boolean equals(Object obj) {
		if (!(obj instanceof IntList))
			return false;
		IntList list = (IntList)obj;
		if (list.size() != size())
			return false;
		IntIterator i = iterator();
		IntIterator j = list.iterator();
		while (i.isValid()) {
			if (i.value() != j.value())
				return false;
			i.advance();
			j.advance();
		}
		return true;
	}

	public int compareTo(IntList o) {
		IntIterator i = iterator();
		IntIterator j = o.iterator();
		while (true) {
			if (i.isValid()) {
				if (j.isValid()) {
					if (i.value() != j.value()) {
						if (i.value() < j.value())
							return -1;
						else
							return 1;
					}
				} else
					return 1;
			} else {
				if (j.isValid())
					return -1;
				else
					return 0;
			}
			i.advance();
			j.advance();
		}
	}

	}

abstract class IntCollection {
	public abstract int size();

	}

interface IntIterator {
	public int value() throws NoSuchElementException;
	/*
	 * @throws NoSuchElementException only if iterator already invalid
	 */
	public void advance() throws NoSuchElementException;
	public boolean isValid();
}