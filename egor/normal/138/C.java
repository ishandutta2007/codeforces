import java.util.NavigableSet;
import java.util.SortedSet;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.util.AbstractList;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import java.util.NoSuchElementException;
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
		int treeCount = in.readInt();
		int mushroomCount = in.readInt();
		final long[] treePosition = new long[treeCount];
		final long[] height = new long[treeCount];
		long[] left = new long[treeCount];
		long[] right = new long[treeCount];
		IOUtils.readLongArrays(in, treePosition, height, left, right);
		int[] mushroomPosition = new int[mushroomCount];
		int[] power = new int[mushroomCount];
		IOUtils.readIntArrays(in, mushroomPosition, power);
		Integer[] treeOrder = ListUtils.order(Array.wrap(treePosition));
		Integer[] rightTreeOrder = ArrayUtils.order(treeCount, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return IntegerUtils.longCompare(treePosition[o1] + height[o1], treePosition[o2] + height[o2]);
			}
		});
		Integer[] mushroomOrder = ListUtils.order(Array.wrap(mushroomPosition));
		int newTreeIndex = 0;
		int oldTreeIndex = 0;
		double[] alive = new double[mushroomCount];
		Arrays.fill(alive, 1);
		double currentAlive = 0;
		int countShould = 0;
		for (int i : mushroomOrder) {
			while (newTreeIndex < treeCount && treePosition[treeOrder[newTreeIndex]] < mushroomPosition[i]) {
				if (right[treeOrder[newTreeIndex]] == 100)
					countShould++;
				else
					currentAlive += Math.log((100 - right[treeOrder[newTreeIndex]]) / 100.);
				newTreeIndex++;
			}
			while (oldTreeIndex < treeCount && treePosition[rightTreeOrder[oldTreeIndex]] + height[rightTreeOrder[oldTreeIndex]] < mushroomPosition[i]) {
				if (right[rightTreeOrder[oldTreeIndex]] == 100)
					countShould--;
				else
					currentAlive -= Math.log((100 - right[rightTreeOrder[oldTreeIndex]]) / 100.);
				oldTreeIndex++;
			}
			if (countShould != 0)
				alive[i] = 0;
			else
				alive[i] *= Math.exp(currentAlive);
		}
		Collections.reverse(Array.wrap(mushroomOrder));
		Collections.reverse(Array.wrap(treeOrder));
		Integer[] leftTreeOrder = ArrayUtils.order(treeCount, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return -IntegerUtils.longCompare(treePosition[o1] - height[o1], treePosition[o2] - height[o2]);
			}
		});
		currentAlive = 0;
		countShould = 0;
		newTreeIndex = 0;
		oldTreeIndex = 0;
		for (int i : mushroomOrder) {
			while (newTreeIndex < treeCount && treePosition[treeOrder[newTreeIndex]] > mushroomPosition[i]) {
				if (left[treeOrder[newTreeIndex]] == 100)
					countShould++;
				else
					currentAlive += Math.log((100 - left[treeOrder[newTreeIndex]]) / 100.);
				newTreeIndex++;
			}
			while (oldTreeIndex < treeCount && treePosition[leftTreeOrder[oldTreeIndex]] - height[leftTreeOrder[oldTreeIndex]] > mushroomPosition[i]) {
				if (left[leftTreeOrder[oldTreeIndex]] == 100)
					countShould--;
				else
					currentAlive -= Math.log((100 - left[leftTreeOrder[oldTreeIndex]]) / 100.);
				oldTreeIndex++;
			}
			if (countShould != 0)
				alive[i] = 0;
			else
				alive[i] *= Math.exp(currentAlive);
		}
		double answer = 0;
		for (int i = 0; i < mushroomCount; i++)
			answer += alive[i] * power[i];
		out.printLine(answer);
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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
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

class IOUtils {

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	public static void readLongArrays(InputReader in, long[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readLong();
		}
	}

	}

class ListUtils {

	public static Integer[] order(final List<? extends Comparable<?>>...sequences) {
		return ArrayUtils.order(sequences[0].size(), new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				for (List<? extends Comparable> sequence : sequences) {
					//noinspection unchecked
					int value = sequence.get(o1).compareTo(sequence.get(o2));
					if (value != 0)
						return value;
				}
				return 0;
			}
		});
	}

	}

abstract class Array<T> extends AbstractList<T> {
	public static<T> List<T> wrap(T...array) {
		return new ReferenceArray<T>(array);
	}

	public static List<Integer> wrap(int...array) {
		return new IntArray(array);
	}

	public static List<Long> wrap(long...array) {
		return new LongArray(array);
	}

	protected static class ReferenceArray<T> extends Array<T> {
		protected final T[] array;

		protected ReferenceArray(T[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public T get(int index) {
			return array[index];
		}

		public T set(int index, T value) {
			T result = array[index];
			array[index] = value;
			return result;
		}
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

	protected static class LongArray extends Array<Long> {
		protected final long[] array;

		protected LongArray(long[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Long get(int index) {
			return array[index];
		}

		public Long set(int index, Long value) {
			long result = array[index];
			array[index] = value;
			return result;
		}
	}

	}

class ArrayUtils {
	public static Integer[] generateOrder(int size) {
		Integer[] order = new Integer[size];
		for (int i = 0; i < size; i++)
			order[i] = i;
		return order;
	}

	public static Integer[] order(int size, Comparator<Integer> comparator) {
		Integer[] order = generateOrder(size);
		Arrays.sort(order, comparator);
		return order;
	}

	}

class IntegerUtils {

	public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	}