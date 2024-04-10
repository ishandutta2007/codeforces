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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int upTo = in.readInt();
		int required = in.readInt();
		int firstLength = in.readInt();
		int secondLength = in.readInt();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				int remainingFirstLength = firstLength - i - j;
				if (remainingFirstLength < 0)
					continue;
				for (int k = 0; k * 2 <= remainingFirstLength; k++) {
					for (int l = 0; l < 2; l++) {
						for (int m = 0; m < 2; m++) {
							int remainingSecondLength = secondLength - l - m;
							if (remainingSecondLength < 0)
								continue;
							for (int n = 0; n * 2 <= remainingSecondLength; n++) {
								int lastStartsC = i;
								int lastEndsA = j;
								long last = k;
								int currentStartsC = l;
								int currentEndsA = m;
								long current = n;
								for (int o = 2; o < upTo; o++) {
									int nextStartsC = lastStartsC;
									int nextEndsA = currentEndsA;
									long next = last + current + lastEndsA * currentStartsC;
									lastStartsC = currentStartsC;
									lastEndsA = currentEndsA;
									last = current;
									currentStartsC = nextStartsC;
									currentEndsA = nextEndsA;
									current = next;
								}
								if (current == required) {
									output(out, i, j, remainingFirstLength, k);
									output(out, l, m, remainingSecondLength, n);
									return;
								}
							}
						}
					}
				}
			}
		}
		out.printLine("Happy new year!");
    }

	private void output(OutputWriter out, int i, int j, int remainingFirstLength, int k) {
		StringBuilder first = new StringBuilder();
		if (i != 0)
			first.append('C');
		for (int o = 0; o < k; o++)
			first.append("AC");
		for (int o = 2 * k; o < remainingFirstLength; o++)
			first.append('X');
		if (j != 0)
			first.append('A');
		out.printLine(first);
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