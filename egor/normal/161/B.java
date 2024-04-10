import java.util.Comparator;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int basketCount = in.readInt();
		final int[] price = new int[count];
		final int[] type = new int[count];
		IOUtils.readIntArrays(in, price, type);
		Integer[] order = ArrayUtils.order(count, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				if (type[o1] != type[o2])
					return type[o1] - type[o2];
				return price[o2] - price[o1];
			}
		});
		int[][] answer = new int[basketCount][];
		for (int i = 0; i < basketCount - 1; i++)
			answer[i] = new int[]{order[i] + 1};
		answer[basketCount - 1] = new int[count - basketCount + 1];
		for (int i = 0; i < answer[basketCount - 1].length; i++)
			answer[basketCount - 1][i] = order[i + basketCount - 1] + 1;
		long score = 2 * ArrayUtils.sumArray(price);
		for (int[] basket : answer) {
			boolean hasChair = false;
			int minPrice = Integer.MAX_VALUE;
			for (int i : basket) {
				hasChair |= type[i - 1] == 1;
				minPrice = Math.min(minPrice, price[i - 1]);
			}
			if (hasChair)
				score -= minPrice;
		}
		out.printLine((score / 2) + "." + (score % 2 * 5));
		for (int[] basket : answer) {
			out.print(basket.length + " ");
			out.printLine(Array.wrap(basket).toArray());
		}
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

class IOUtils {

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
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

	public static long sumArray(int[] array) {
		long result = 0;
		for (int element : array)
			result += element;
		return result;
	}

	public static Integer[] order(int size, Comparator<Integer> comparator) {
		Integer[] order = generateOrder(size);
		Arrays.sort(order, comparator);
		return order;
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