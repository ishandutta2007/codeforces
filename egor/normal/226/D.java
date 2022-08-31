import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		int[][] table = IOUtils.readIntTable(in, rowCount, columnCount);
		boolean[] takeRow = new boolean[rowCount];
		boolean[] takeColumn = new boolean[columnCount];
		int[] sumRow = new int[rowCount];
		int[] sumColumn = new int[columnCount];
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				sumRow[i] += table[i][j];
				sumColumn[j] += table[i][j];
			}
		}
		while (true) {
			int minSum = Integer.MAX_VALUE;
			int index = -1;
			boolean isRow = false;
			for (int i = 0; i < rowCount; i++) {
				if (sumRow[i] < minSum) {
					minSum = sumRow[i];
					index = i;
					isRow = true;
				}
			}
			for (int i = 0; i < columnCount; i++) {
				if (sumColumn[i] < minSum) {
					minSum = sumColumn[i];
					index = i;
					isRow = false;
				}
			}
			if (minSum >= 0)
				break;
			if (isRow) {
				takeRow[index] = !takeRow[index];
				sumRow[index] = -sumRow[index];
				for (int i = 0; i < columnCount; i++) {
					sumColumn[i] -= table[index][i] << 1;
					table[index][i] = -table[index][i];
				}
			} else {
				takeColumn[index] = !takeColumn[index];
				sumColumn[index] = -sumColumn[index];
				for (int i = 0; i < rowCount; i++) {
					sumRow[i] -= table[i][index] << 1;
					table[i][index] = -table[i][index];
				}
			}
		}
		out.print(CollectionUtils.count(Array.wrap(takeRow), true));
		for (int i = 0; i < rowCount; i++) {
			if (takeRow[i])
				out.print(" " + (i + 1));
		}
		out.printLine();
		out.print(CollectionUtils.count(Array.wrap(takeColumn), true));
		for (int i = 0; i < columnCount; i++) {
			if (takeColumn[i])
				out.print(" " + (i + 1));
		}
		out.printLine();
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

	public static int[][] readIntTable(InputReader in, int rowCount, int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readIntArray(in, columnCount);
		return table;
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

abstract class Array<T> extends AbstractList<T> implements RandomAccess {

	public static List<Boolean> wrap(boolean...array) {
		return new BooleanArray(array);
	}

	protected static class BooleanArray extends Array<Boolean> {
		protected final boolean[] array;

		protected BooleanArray(boolean[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Boolean get(int index) {
			return array[index];
		}

		public Boolean set(int index, Boolean value) {
			boolean result = array[index];
			array[index] = value;
			return result;
		}
	}

	}