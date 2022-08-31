import java.io.IOException;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[] s = in.readString().toCharArray();
		int index = in.readInt() - 1;
		long total = (long)s.length * (s.length + 1) / 2;
		if (index >= total) {
			out.printLine("No such line.");
			return;
		}
		int[] validPositions = new int[s.length];
		for (int i = 0; i < s.length; i++)
			validPositions[i] = i;
		int validLength = s.length;
		for (int length = 0; length < s.length; length++) {
			for (char c = 'a'; c <= 'z'; c++) {
				int count = 0;
				long sumLength = 0;
				int any = -1;
				for (int i = 0; i < validLength; i++) {
					int j = validPositions[i];
					if (j + length < s.length && s[j + length] == c) {
						count++;
						sumLength += s.length - j - length;
						any = j;
					}
				}
				if (index < count) {
					printSubstring(s, any, any + length, out);
					return;
				}
				if (index < sumLength) {
					index -= count;
					int newValidLength = 0;
					for (int i = 0; i < validLength; i++) {
						int j = validPositions[i];
						if (j + length < s.length && s[j + length] == c) {
							validPositions[newValidLength++] = j;
						}
					}
					validLength = newValidLength;
					break;
				}
				index -= sumLength;
			}
		}
		throw new RuntimeException();
	}

	private void printSubstring(char[] s, int from, int to, OutputWriter out) {
		for (int i = from; i <= to; i++)
			out.print(s[i]);
		out.printLine();
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

	private boolean isSpaceChar(int c) {
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