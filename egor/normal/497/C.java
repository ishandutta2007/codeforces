import java.util.NavigableSet;
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
import java.util.TreeSet;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.SortedSet;
import java.util.Set;

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
        List<Delta> list = new ArrayList<>();
        int roleCount = in.readInt();
        for (int i = 0; i < roleCount; i++) {
            int from = in.readInt();
            int to = in.readInt();
            list.add(new Delta(from, to, -1, i));
        }
        int artistCount = in.readInt();
        for (int i = 0; i < artistCount; i++) {
            int from = in.readInt();
            int to = in.readInt();
            int value = in.readInt();
            list.add(new Delta(from, to, value, i));
        }
        NavigableSet<Delta> artists = new TreeSet<>();
        Collections.sort(list, new Comparator<Delta>() {
            public int compare(Delta o1, Delta o2) {
                if (o1.from != o2.from) {
                    return o1.from - o2.from;
                }
                return o2.value - o1.value;
            }
        });
        int[] answer = new int[roleCount];
        for (Delta delta : list) {
            if (delta.value > 0) {
                artists.add(delta);
            } else {
                NavigableSet<Delta> tail = artists.tailSet(delta, false);
                if (tail.isEmpty()) {
                    out.printLine("NO");
                    return;
                }
                Delta artist = tail.first();
                artist.value--;
                answer[delta.index] = artist.index + 1;
                if (artist.value == 0) {
                    artists.remove(artist);
                }
            }
        }
        out.printLine("YES");
        out.printLine(answer);
    }

    static class Delta implements Comparable<Delta> {
        int from;
        int to;
        int value;
        int index;

        public Delta(int from, int to, int value, int index) {
            this.from = from;
            this.to = to;
            this.value = value;
            this.index = index;
        }

        public int compareTo(Delta o) {
            if (to != o.to) {
                return to - o.to;
            }
            if ((value == -1) != (o.value == -1)) {
                if (value == -1) {
                    return -1;
                } else {
                    return 1;
                }
            }
            return index - o.index;
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