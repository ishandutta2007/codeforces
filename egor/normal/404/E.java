import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[] sequence = in.readString().toCharArray();
		int left = 0;
		int right = 0;
		int current = 0;
		for (char c : sequence) {
			left = Math.min(left, current);
			right = Math.max(right, current);
			if (c == 'R')
				current++;
			else
				current--;
		}
		if (current > right || current < left) {
			out.printLine(1);
			return;
		}
		if (sequence[sequence.length - 1] == 'R') {
			int min = 0;
			int max = -left;
			while (min < max) {
				int at = (min + max + 1) >> 1;
				right = 0;
				current = 0;
				for (char c : sequence) {
					right = Math.max(right, current);
					if (c == 'R')
						current++;
					else
						current--;
					current = Math.max(current, -at + 1);
				}
				if (current > right)
					min = at;
				else
					max = at - 1;
			}
			out.printLine(min);
		} else {
			int min = 0;
			int max = right;
			while (min < max) {
				int at = (min + max + 1) >> 1;
				left = 0;
				current = 0;
				for (char c : sequence) {
					left = Math.min(left, current);
					if (c == 'R')
						current++;
					else
						current--;
					current = Math.min(current, at - 1);
				}
				if (current < left)
					min = at;
				else
					max = at - 1;
			}
			out.printLine(min);			
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

	public void printLine(int i) {
		writer.println(i);
	}
}