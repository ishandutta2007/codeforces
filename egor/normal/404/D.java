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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	private static final long MOD = (long) (1e9 + 7);
	char[] field;
	long[][] answer;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		field = in.readString().toCharArray();
		answer = new long[2][field.length];
		ArrayUtils.fill(answer, -1);
		for (int i = field.length - 1; i >= 0; i--) {
			go(0, i);
			go(1, i);
		}
		out.printLine(go(0, 0));
    }

	private long go(int last, int position) {
		if (position >= field.length)
			return 1;
		if (answer[last][position] != -1)
			return answer[last][position];
		if (field[position] == '?')
			return answer[last][position] = (go(0, position + 1) + go(1, position + 1)) % MOD;
		if (field[position] == '0') {
			if (last == 1 || position + 1 < field.length && field[position + 1] == '*')
				return answer[last][position] = 0;
			if (position == field.length - 1 || field[position + 1] == '?')
				return answer[last][position] = go(0, position + 2);
			return answer[last][position] = go(0, position + 1);
		}
		if (field[position] == '1') {
			if (last == 1) {
				if (position + 1 < field.length && field[position + 1] == '*')
					return answer[last][position] = 0;
				if (position == field.length - 1 || field[position + 1] == '?')
					return answer[last][position] = go(0, position + 2);
				return answer[last][position] = go(0, position + 1);
			}
			if (position + 1 == field.length || Character.isDigit(field[position + 1]))
				return answer[last][position] = 0;
			return answer[last][position] = go(1, position + 2);
		}
		if (field[position] == '2') {
			if (last == 0 || position + 1 == field.length || Character.isDigit(field[position + 1]))
				return answer[last][position] = 0;
			return answer[last][position] = go(1, position + 2);
		}
		return answer[last][position] = go(1, position + 1);
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

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void close() {
		writer.close();
	}

	public void printLine(long i) {
		writer.println(i);
	}

	}

class ArrayUtils {

	public static void fill(long[][] array, long value) {
		for (long[] row : array)
			Arrays.fill(row, value);
	}

	}