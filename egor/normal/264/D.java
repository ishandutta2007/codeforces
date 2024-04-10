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
		char[] first = in.readString().toCharArray();
		char[] second = in.readString().toCharArray();
		int j = 0;
		int k = 0;
		long answer = 0;
		int[][] qty = new int[6][second.length];
		for (int i = 1; i < second.length; i++) {
			for (int l = 0; l < 6; l++)
				qty[l][i] = qty[l][i - 1];
			if (second[i - 1] == 'R') {
				if (second[i] == 'G')
					qty[0][i]++;
				else if (second[i] == 'B')
					qty[1][i]++;
			} else if (second[i - 1] == 'G') {
				if (second[i] == 'R')
					qty[2][i]++;
				else if (second[i] == 'B')
					qty[3][i]++;
			} else if (second[i - 1] == 'B') {
				if (second[i] == 'R')
					qty[4][i]++;
				else if (second[i] == 'G')
					qty[5][i]++;
			}
		}
		char last = first[0];
		for (char c : first) {
			while (k + 1 < second.length && second[k] != c)
				k++;
			answer += k - j + 1;
			if (c == 'R') {
				if (last == 'G')
					answer -= qty[0][k] - qty[0][j];
				else if (last == 'B')
					answer -= qty[1][k] - qty[1][j];
			} else if (c == 'G') {
				if (last == 'R')
					answer -= qty[2][k] - qty[2][j];
				else if (last == 'B')
					answer -= qty[3][k] - qty[3][j];
			} else if (c == 'B') {
				if (last == 'R')
					answer -= qty[4][k] - qty[4][j];
				else if (last == 'G')
					answer -= qty[5][k] - qty[5][j];
			}
			last = c;
			if (second[j] == c)
				j++;
			if (j == second.length)
				break;
			if (second[k] == c)
				k = Math.min(k + 1, second.length - 1);
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