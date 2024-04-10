import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	char[] first;
	char[] second;
	char[] virus;
	int[][][] length;
	char[][][] next;
	int[][] automaton;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		first = in.readString().toLowerCase().toCharArray();
		second = in.readString().toLowerCase().toCharArray();
		virus = in.readString().toLowerCase().toCharArray();
		automaton = StringUtils.buildPrefixAutomaton(new String(virus));
		length = new int[first.length + 1][second.length + 1][virus.length];
		next = new char[first.length + 1][second.length + 1][virus.length];
		ArrayUtils.fill(length, -1);
		if (go(0, 0, 0) == 0)
			out.printLine(0);
		else {
			StringBuilder answer = new StringBuilder();
			int i = 0;
			int j = 0;
			int k = 0;
			while (length[i][j][k] != 0) {
				char c = next[i][j][k];
				answer.append(c);
				while (first[i] != c)
					i++;
				i++;
				while (second[j] != c)
					j++;
				j++;
				k = automaton[k][c - 'a'];
			}
			out.printLine(answer.toString().toUpperCase());
		}
    }

	private int go(int i, int j, int k) {
		if (length[i][j][k] != -1)
			return length[i][j][k];
		if (i == first.length || j == second.length)
			return length[i][j][k] = 0;
		if (first[i] != second[j]) {
			int left = go(i + 1, j, k);
			int right = go(i, j + 1, k);
			if (left > right) {
				length[i][j][k] = left;
				next[i][j][k] = next[i + 1][j][k];
			} else {
				length[i][j][k] = right;
				next[i][j][k] = next[i][j + 1][k];
			}
			return length[i][j][k];
		}
		length[i][j][k] = go(i + 1, j + 1, k);
		next[i][j][k] = next[i + 1][j + 1][k];
		if (automaton[k][first[i] - 'a'] != virus.length) {
			int candidate = go(i + 1, j + 1, automaton[k][first[i] - 'a']) + 1;
			if (candidate > length[i][j][k]) {
				length[i][j][k] = candidate;
				next[i][j][k] = first[i];
			}
		}
		return length[i][j][k];
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

class StringUtils {

	public static int[] prefixFunction(CharSequence s) {
		int l = s.length();
		int[] p = new int[l];
		int k = 0;
		for (int i = 1; i < l; i++) {
			while ((k > 0) && (s.charAt(k) != s.charAt(i)))
				k = p[k - 1];
			if (s.charAt(k) == s.charAt(i))
				k++;
			p[i] = k;
		}
		return p;
	}

    public static int[][] buildPrefixAutomaton(CharSequence s) {
		int[] prefixFunction = prefixFunction(s);
		int[][] result = new int[s.length() + 1][26];
		result[0][s.charAt(0) - 'a'] = 1;
		for (int i = 1; i <= s.length(); i++) {
			System.arraycopy(result[prefixFunction[i - 1]], 0, result[i], 0, 26);
			if (i != s.length())
				result[i][s.charAt(i) - 'a'] = i + 1;
		}
		return result;
	}

	}

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	public static void fill(int[][][] array, int value) {
		for (int[][] subArray : array)
			fill(subArray, value);
	}

	}