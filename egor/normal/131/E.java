import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
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
		int size = in.readInt();
		int count = in.readInt();
		Pair<Integer, Integer>[] figures = IOUtils.readIntPairArray(in, count);
		Arrays.sort(figures);
		int[] canEat = new int[count];
		int[] row = new int[size + 1];
		int[] column = new int[size + 1];
		int[] firstDiagonal = new int[2 * size + 1];
		int[] secondDiagonal = new int[2 * size + 1];
		Arrays.fill(row, -1);
		Arrays.fill(column, -1);
		Arrays.fill(firstDiagonal, -1);
		Arrays.fill(secondDiagonal, -1);
		for (int i = 0, figuresLength = figures.length; i < figuresLength; i++) {
			Pair<Integer, Integer> figure = figures[i];
			if (row[figure.first] != -1) {
				canEat[i]++;
				canEat[row[figure.first]]++;
			}
			row[figure.first] = i;
			if (column[figure.second] != -1) {
				canEat[i]++;
				canEat[column[figure.second]]++;
			}
			column[figure.second] = i;
			if (firstDiagonal[figure.first + figure.second] != -1) {
				canEat[i]++;
				canEat[firstDiagonal[figure.first + figure.second]]++;
			}
			firstDiagonal[figure.first + figure.second] = i;
			if (secondDiagonal[figure.first - figure.second + size] != -1) {
				canEat[i]++;
				canEat[secondDiagonal[figure.first - figure.second + size]]++;
			}
			secondDiagonal[figure.first - figure.second + size] = i;
		}
		int[] answer = new int[9];
		for (int i : canEat)
			answer[i]++;
		out.printLine(Array.wrap(answer).toArray());
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

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

	}

	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	public String toString() {
		return "(" + first + "," + second + ")";
	}

	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>)first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>)second).compareTo(o.second);
	}
}

class IOUtils {
	public static Pair<Integer, Integer> readIntPair(InputReader in) {
		int first = in.readInt();
		int second = in.readInt();
		return Pair.makePair(first, second);
	}

	public static Pair<Integer, Integer>[] readIntPairArray(InputReader in, int size) {
		@SuppressWarnings({"unchecked"})
		Pair<Integer, Integer>[] result = new Pair[size];
		for (int i = 0; i < size; i++)
			result[i] = readIntPair(in);
		return result;
	}

	}

abstract class Array<T> extends AbstractList<T> {

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