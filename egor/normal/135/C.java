import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[] state = in.readString().toCharArray();
		int moveCount = state.length - 2;
		int mashaMoves = (moveCount + 1) / 2;
		int petyaMoves = moveCount / 2;
		List<Character> wrappedState = Array.wrap(state);
		int mashaShouldDestroy = CollectionUtils.count(wrappedState, '1');
		int petyaShouldDestroy = CollectionUtils.count(wrappedState, '0');
		int neutral = CollectionUtils.count(wrappedState, '?');
		if (mashaShouldDestroy >= mashaMoves + 2) {
			out.printLine("11");
			return;
		}
		if (petyaShouldDestroy >= petyaMoves + 2) {
			out.printLine("00");
			return;
		}
		List<String> answer = new ArrayList<String>();
		if (mashaMoves >= mashaShouldDestroy)
			answer.add("00");
		if (petyaMoves >= petyaShouldDestroy)
			answer.add("11");
		if (state[state.length - 1] != '1' && (petyaShouldDestroy != petyaMoves + 1 || state[state.length - 1] == '0'))
			answer.add("10");
		if (state[state.length - 1] != '0' && (mashaShouldDestroy != mashaMoves + 1 || state[state.length - 1] == '1'))
			answer.add("01");
		Collections.sort(answer);
		for (String variant : answer)
			out.printLine(variant);
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

abstract class Array<T> extends AbstractList<T> {

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

class CollectionUtils {

	public static<T> int count(Iterable<T> array, T sample) {
		int result = 0;
		for (T element : array) {
			if (element.equals(sample))
				result++;
		}
		return result;
	}

	}