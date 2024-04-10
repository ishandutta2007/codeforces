import java.io.IOException;
import java.io.OutputStreamWriter;
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
		TaskH solver = new TaskH();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskH {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[] s = in.readString().toCharArray();
		int total = 0;
		int[] odd = new int[s.length];
		int[] even = new int[s.length - 1];
		for (int i = 0; i < s.length; i++) {
			odd[i] = 1;
			for (int j = 1; j <= i && i + j < s.length; j++) {
				if (s[i - j] == s[i + j])
					odd[i]++;
				else
					break;
			}
			if (i != s.length - 1) {
				for (int j = 0; j <= i && i + j + 1 < s.length; j++) {
					if (s[i - j] == s[i + j + 1])
						even[i]++;
					else
						break;
				}
			}
		}
		int[][] answer = new int[s.length][s.length];
		int[] end = new int[s.length];
		for (int i = 0; i < s.length; i++) {
			int count = 0;
			for (int j = i; j < s.length; j++) {
				if (2 * j - i < s.length && odd[j] > j - i)
					end[count++] = 2 * j - i;
				if (2 * j - i + 1 < s.length && even[j] > j - i)
					end[count++] = 2 * j - i + 1;
			}
			int current = 0;
			int k = 0;
			for (int j = i; j < s.length; j++) {
				if (k != count && end[k] == j) {
					k++;
					current++;
				}
				answer[i][j] = current;
			}
		}
		for (int i = s.length - 1; i > 0; i--) {
			for (int j = i; j < s.length; j++)
				answer[i - 1][j] += answer[i][j];
		}
		int queryCount = in.readInt();
		for (int i = 0; i < queryCount; i++) {
			int from = in.readInt() - 1;
			int to = in.readInt() - 1;
			out.printLine(answer[from][to]);
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