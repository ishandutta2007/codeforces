import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.RandomAccess;
import java.util.AbstractList;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[] s = in.readString().toCharArray();
		char[] t = in.readString().toCharArray();
		int[] maxPrefix = prefix(s, t);
		Collections.reverse(Array.wrap(s));
		Collections.reverse(Array.wrap(t));
		int[] maxSuffix = prefix(s, t);
		for (int i = 0; i < s.length; i++) {
			if (maxPrefix[i] + maxSuffix[s.length - i - 1] <= t.length) {
				out.printLine("No");
				return;
			}
		}
		out.printLine("Yes");
	}

	private int[] prefix(char[] s, char[] t) {
		int[][] last = new int[26][t.length + 1];
		for (int i = 0; i < 26; i++) {
			char current = (char) ('a' + i);
			int position = -1;
			for (int j = 0; j < t.length; j++) {
				if (t[j] == current)
					position = j + 1;
				last[i][j + 1] = position;
			}
		}
		int index = 0;
		int[] result = new int[s.length];
		for (int i = 0; i < s.length; i++) {
			if (index != t.length && s[i] == t[index])
				index++;
			result[i] = last[s[i] - 'a'][index];
		}
		return result;
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

abstract class Array<T> extends AbstractList<T> implements RandomAccess {

	public static List<Character> wrap(char...array) {
		return new CharArray(array);
	}

	protected static class CharArray extends Array<Character> {
		protected final char[] array;

		protected CharArray(char[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Character get(int index) {
			return array[index];
		}

		public Character set(int index, Character value) {
			char result = array[index];
			array[index] = value;
			return result;
		}
	}

	}