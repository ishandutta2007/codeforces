import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.Comparator;

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
        char[] s = in.readString().toCharArray();
        long answer = 0;
        long[] partial = new long[(s.length + 1) / 2 + 1];
        long current = 0;
        long multiple = s[0] - '0';
        partial[1] = multiple;
        for (int i = 2; i < s.length; i += 2) {
            int digit = s[i] - '0';
            if (s[i - 1] == '*') {
                multiple *= digit;
            } else {
                current += multiple;
                multiple = digit;
            }
            partial[(i >> 1) + 1] = current + multiple;
        }
        int[] positions = new int[ArrayUtils.count(s, '*') + 2];
        positions[0] = -1;
        int at = 1;
        for (int i = 1; i < s.length; i += 2) {
            if (s[i] == '*') {
                positions[at++] = i;
            }
        }
        positions[at] = s.length;
        for (int i : positions) {
            for (int j : positions) {
                if (i == j) {
                    break;
                }
                long multiply = 1;
                int lft = j;
                while (lft > 0 && s[lft] == '*') {
                    multiply *= s[lft - 1] - '0';
                    lft -= 2;
                }
                int rht = i;
                while (rht < s.length && s[rht] == '*') {
                    multiply *= s[rht + 1] - '0';
                    rht += 2;
                }
                long middle = 0;
                int lft2 = j;
                long cur = 1;
                while (lft2 < i && (lft2 < 0 || s[lft2] == '*')) {
                    cur *= s[lft2 + 1] - '0';
                    lft2 += 2;
                }
                middle += cur;
                int rht2 = i;
                cur = 1;
                while (rht2 > lft2 && (rht2 >= s.length || s[rht2] == '*')) {
                    cur *= s[rht2 - 1] - '0';
                    rht2 -= 2;
                }
                if (lft2 != i) {
                    middle += cur;
                    middle += partial[(rht2 + 1) >> 1] - partial[(lft2 + 1) >> 1];
                }
                long candidate = partial[(lft + 1) >> 1] + middle * multiply +
                    partial[partial.length - 1] - partial[(rht + 1) >> 1];
                answer = Math.max(answer, candidate);
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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
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

	public void close() {
		writer.close();
	}

	public void printLine(long i) {
		writer.println(i);
	}

}

class ArrayUtils {

	public static int count(char[] array, char value) {
		int result = 0;
		for (char i : array) {
			if (i == value)
				result++;
		}
		return result;
	}

}