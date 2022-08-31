import java.util.Map;
import java.util.Collections;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.util.Collection;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;
import java.util.Comparator;
import java.io.*;
import java.util.Iterator;
import java.util.Arrays;

/**
 * @author Egor Kulikov (egor@egork.net)
 * Actual solution is at the bottom
 */
public class Main {
	public static void main(String[] args) {
		InputReader in = new StreamInputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		run(in, out);
	}

	public static void run(InputReader in, PrintWriter out) {
		Solver solver = new TaskC();
		solver.solve(1, in, out);
		Exit.exit(in, out);
	}
}

abstract class InputReader {
	private boolean finished = false;

	public abstract int read();

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

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
	}

	public void setFinished(boolean finished) {
		this.finished = finished;
	}

	public abstract void close();

	}

class Exit {
	private Exit() {
	}

	public static void exit(InputReader in, PrintWriter out) {
		in.setFinished(true);
		in.close();
		out.close();
	}
}

class StreamInputReader extends InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar, numChars;

	public StreamInputReader(InputStream stream) {
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

	@Override
	public void close() {
		try {
			stream.close();
		} catch (IOException ignored) {
		}
	}
}

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
}

class CollectionUtils {

	public static<T extends Comparable<T>> T maxElement(Iterable<T> collection) {
		T result = null;
		for (T element : collection) {
			if (result == null || result.compareTo(element) < 0)
				result = element;
		}
		return result;
	}

	}

abstract class ArrayWrapper<T> implements Iterable<T> {
	protected final int from;
	protected final int to;
	protected final int size;
	protected final Object underlying;

	public static ArrayWrapper<Integer> wrap(int[] array) {
		return new IntArrayWrapper(array);
	}

	protected ArrayWrapper(Object underlying, int from, int to) {
		this.underlying = underlying;
		this.from = from;
		this.to = to;
		size = to - from;
	}


	public Iterator<T> iterator() {
		return new ArrayIterator();
	}

	public abstract T get(int index);

	private class ArrayIterator implements Iterator<T> {
		private int index = 0;

		protected ArrayIterator() {
		}

		public boolean hasNext() {
			return index < size;
		}

		public T next() {
			return get(index++);
		}

		public void remove() {
			throw new UnsupportedOperationException();
		}
	}

	protected static class IntArrayWrapper extends ArrayWrapper<Integer> {
		protected final int[] array;

		protected IntArrayWrapper(int[] array) {
			this(array, 0, array.length);
		}

		protected IntArrayWrapper(int[] array, int from, int to) {
			super(array, from, to);
			this.array = array;
		}

		public Integer get(int index) {
			return array[index + from];
		}

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

class TaskC implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		char[] name = in.readString().toCharArray();
		int maxAlterations = in.readInt();
		int[][] bonus = new int[256][256];
		int goodPairs = in.readInt();
		for (int i = 0; i < goodPairs; i++) {
			char first = in.readCharacter();
			char second = in.readCharacter();
			bonus[first][second] = in.readInt();
		}
		int[][][] result = new int[name.length][maxAlterations + 1][256];
		ArrayUtils.fill(result, Integer.MIN_VALUE);
		if (maxAlterations != 0) {
			for (int i = 'a'; i <= 'z'; i++) {
				result[0][i == name[0] ? 0 : 1][i] = 0;
			}
		} else
			result[0][0][name[0]] = 0;
		for (int i = 1; i < name.length; i++) {
			result[i][0][name[i]] = result[i - 1][0][name[i - 1]] + bonus[name[i - 1]][name[i]];
			for (int j = 1; j <= maxAlterations; j++) {
				for (int k = 'a'; k <= 'z'; k++) {
					int oldJ = k == name[i] ? j : j - 1;
					for (int l = 'a'; l <= 'z'; l++) {
						if (result[i - 1][oldJ][l] != Integer.MIN_VALUE)
							result[i][j][k] = Math.max(result[i][j][k], result[i - 1][oldJ][l] + bonus[l][k]);
					}
				}
			}
		}
		int answer = Integer.MIN_VALUE;
		for (int i = 0; i <= maxAlterations; i++)
			answer = Math.max(answer, CollectionUtils.maxElement(ArrayWrapper.wrap(result[name.length - 1][i])));
		out.println(answer);
	}
}