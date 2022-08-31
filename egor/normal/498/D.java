import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    int[] period;
    int[][] answer;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int count = in.readInt();
        period = IOUtils.readIntArray(in, count);
        answer = new int[60][count << 2];
        init(0, 0, count);
        int queryCount = in.readInt();
        for (int i = 0; i < queryCount; i++) {
            char type = in.readCharacter();
            if (type == 'C') {
                int at = in.readInt() - 1;
                period[at] = in.readInt();
                update(0, 0, count, at);
            } else {
                int from = in.readInt() - 1;
                int to = in.readInt() - 1;
                out.printLine(calculate(0, 0, count, from, to, 0));
            }
        }
    }

    private int calculate(int root, int from, int to, int left, int right, int shift) {
        if (from >= right || to <= left) {
            return -1;
        }
        if (from >= left && to <= right) {
            return shift + answer[shift % 60][root];
        }
        int middle = (from + to) >> 1;
        if (right <= middle) {
            return calculate(2 * root + 1, from, middle, left, right, shift);
        }
        if (left >= middle) {
            return calculate(2 * root + 2, middle, to, left, right, shift);
        }
        int result = calculate(2 * root + 1, from, middle, left, right, shift);
        return calculate(2 * root + 2, middle, to, left, right, result);
    }

    private void update(int root, int from, int to, int at) {
        if (from > at || to <= at) {
            return;
        }
        if (from + 1 == to) {
            for (int i = 0; i < 60; i++) {
                if (i % period[from] == 0) {
                    answer[i][root] = 2;
                } else {
                    answer[i][root] = 1;
                }
            }
        } else {
            int middle = (from + to) >> 1;
            update(2 * root + 1, from, middle, at);
            update(2 * root + 2, middle, to, at);
            for (int i = 0; i < 60; i++) {
                answer[i][root] = answer[i][2 * root + 1] + answer[(i + answer[i][2 * root + 1]) % 60][2 * root + 2];
            }
        }
    }

    private void init(int root, int from, int to) {
        if (from + 1 == to) {
            for (int i = 0; i < 60; i++) {
                if (i % period[from] == 0) {
                    answer[i][root] = 2;
                } else {
                    answer[i][root] = 1;
                }
            }
        } else {
            int middle = (from + to) >> 1;
            init(2 * root + 1, from, middle);
            init(2 * root + 2, middle, to);
            for (int i = 0; i < 60; i++) {
                answer[i][root] = answer[i][2 * root + 1] + answer[(i + answer[i][2 * root + 1]) % 60][2 * root + 2];
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

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
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

	public void close() {
		writer.close();
	}

	public void printLine(int i) {
		writer.println(i);
	}
}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

}