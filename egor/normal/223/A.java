import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[] sequence = in.readString().toCharArray();
		int answer = 0;
		int from = 0;
		int to = 0;
		int[] count = new int[sequence.length + 1];
		for (int i = 1; i <= sequence.length; i++)
			count[i] = count[i - 1] + (sequence[i - 1] == '[' ? 1 : 0);
		int[] position = new int[sequence.length + 1];
		char[] symbol = new char[sequence.length + 1];
		int depth = 0;
		Arrays.fill(position, -1);
		int validSince = 0;
		for (int i = 0; i < sequence.length; i++) {
			if (sequence[i] == '(' || sequence[i] == '[') {
				if (position[depth] < validSince)
					position[depth] = i;
				symbol[depth] = sequence[i];
				depth++;
			} else {
				if (depth == 0 || symbol[depth - 1] != open(sequence[i])) {
					validSince = i + 1;
					depth = 0;
					continue;
				}
				position[depth] = -1;
				int start = position[--depth];
				int current = count[i] - count[start];
				if (current > answer) {
					from = start;
					to = i + 1;
					answer = current;
				}
			}
		}
		out.printLine(answer);
		out.printLine(new String(sequence).substring(from, to));
	}

	private char open(char c) {
		if (c == ')')
			return '(';
		return '[';
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
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
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