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
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int firstCount = in.readInt();
		int[] firstDeck = IOUtils.readIntArray(in, firstCount);
		int secondCount = in.readInt();
		int[] secondDeck = IOUtils.readIntArray(in, secondCount);
		List<Integer> first = solve(firstDeck, secondDeck);
		List<Integer> second = solve(secondDeck, firstDeck);
		int current;
		if (first.size() > second.size()) {
			current = secondDeck[0];
			first = second;
		} else {
			current = firstDeck[0];
		}
		int i = 0;
		int j = 0;
		int[] answer = new int[firstCount + secondCount];
		while (i < firstCount || j < secondCount) {
			while (i < firstCount && firstDeck[i] == current) {
				answer[i + j] = i + 1;
				i++;
			}
			while (j < secondCount && secondDeck[j] == current) {
				answer[i + j] = firstCount + j + 1;
				j++;
			}
			current = 1 - current;
		}
		out.printLine(Array.wrap(answer).toArray());
		out.printLine(first.size());
		out.printLine(first.toArray());
	}

	private List<Integer> solve(int[] firstDeck, int[] secondDeck) {
		int current = firstDeck[0];
		List<Integer> same = new ArrayList<Integer>();
		int i = 0;
		int j = 0;
		int firstCount = firstDeck.length;
		int secondCount = secondDeck.length;
		while (i < firstCount || j < secondCount) {
			int curMove = 0;
			while (i < firstCount && firstDeck[i] == current) {
				curMove++;
				i++;
			}
			while (j < secondCount && secondDeck[j] == current) {
				curMove++;
				j++;
			}
			current = 1 - current;
			same.add(curMove);
		}
		List<Integer> result = new ArrayList<Integer>();
		int sum = 0;
		for (int k : same) {
			sum += k;
			if (sum != firstCount + secondCount || current == 0) {
				result.add(sum);
			}
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

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	}

abstract class Array<T> extends AbstractList<T> implements RandomAccess {

	public static List<Integer> wrap(int...array) {
		return new IntArray(array);
	}

	protected static class IntArray extends Array<Integer> {
		protected final int[] array;

		protected IntArray(int[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Integer get(int index) {
			return array[index];
		}

		public Integer set(int index, Integer value) {
			int result = array[index];
			array[index] = value;
			return result;
		}
	}

	}