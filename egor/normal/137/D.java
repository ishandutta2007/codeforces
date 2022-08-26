import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Collections;
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
	private char[] s;
	private int[][] changes;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		s = in.readString().toCharArray();
		int allowed = in.readInt();
		changes = new int[s.length][s.length];
		ArrayUtils.fill(changes, -1);
		for (int i = 0; i < s.length; i++) {
			for (int j = i; j < s.length; j++)
				countChanges(i, j);
		}
		int[][] answer = new int[s.length + 1][allowed + 1];
		int[][] last = new int[s.length + 1][allowed + 1];
		for (int i = 1; i <= s.length; i++) {
			answer[i][0] = Integer.MAX_VALUE / 2;
			for (int j = 1; j <= allowed; j++) {
				answer[i][j] = Integer.MAX_VALUE / 2;
				for (int k = 0; k < i; k++) {
					int curValue = answer[k][j - 1] + changes[k][i - 1];
					if (answer[i][j] > curValue) {
						answer[i][j] = curValue;
						last[i][j] = k;
					}
				}
			}
		}
		int count = 0;
		for (int i = 1; i <= allowed; i++) {
			if (answer[s.length][i] < answer[s.length][count])
				count = i;
		}
		int position = s.length;
		String asString = new String(s);
		List<char[]> subStrings = new ArrayList<char[]>();
		for (int i = count; i > 0; i--) {
			int start = last[position][i];
			subStrings.add(asString.substring(start, position).toCharArray());
			position = start;
		}
		Collections.reverse(subStrings);
		out.printLine(answer[s.length][count]);
		boolean first = true;
		for (char[] word : subStrings) {
			if (first)
				first = false;
			else
				out.print('+');
			for (int i = 0; i < word.length / 2; i++)
				word[i] = word[word.length - i - 1];
			out.print(new String(word));
		}
		out.printLine();
	}

	private int countChanges(int from, int to) {
		if (from > to)
			return 0;
		if (changes[from][to] != -1)
			return changes[from][to];
		return changes[from][to] = countChanges(from + 1, to - 1) + (s[from] == s[to] ? 0 : 1);
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

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	}