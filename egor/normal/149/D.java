import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Stack;
import java.util.Vector;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
	static final long[][] DEFAULT = new long[3][3];

	static {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				DEFAULT[i][j] = i != j || i == 0 ? 1 : 0;
		}
	}

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[] s = in.readString().toCharArray();
		int[] close = new int[s.length];
		Stack<Integer> stack = new Stack<Integer>();
		for (int i = 0; i < s.length; i++) {
			if (s[i] == '(')
				stack.add(i);
			else
				close[stack.pop()] = i;
		}
		out.printLine(go(close, 0, s.length - 1)[0][0]);
	}

	private long[][] go(int[] close, int from, int to) {
		if (from > to)
			return DEFAULT;
		long[][] result = new long[3][3];
		long[][] firstResult = go(close, from + 1, close[from] - 1);
		long[][] secondResult = go(close, close[from] + 1, to);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 1; k < 3; k++) {
					if (k != i || k == 0)
						result[i][j] += firstResult[k][0] * secondResult[0][j];
					result[i][j] += firstResult[0][k] * secondResult[k][j];
				}
				result[i][j] %= (long)1e9 + 7;
			}
		}
		return result;
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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
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