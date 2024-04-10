import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.AbstractSet;
import java.util.Iterator;
import java.util.Set;
import java.util.AbstractMap;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] numbers = IOUtils.readIntArray(in, count);
		boolean[] possible = new boolean[1 << count];
		boolean[] nextPossible = new boolean[1 << count];
		possible[1] = true;
		int[][] index = new int[count][count];
		ArrayUtils.fill(index, -1);
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < i; j++) {
				for (int k = 0; k < i; k++) {
					if (numbers[j] + numbers[k] == numbers[i])
						index[i][j] = k;
				}
			}
		}
		for (int i = 1; i < count; i++) {
			Arrays.fill(nextPossible, 0, 1 << (i - 1), false);
			for (int j = 0; j < (1 << i); j++) {
				if (possible[j]) {
					boolean good = false;
					for (int k = 0; k < i && !good; k++) {
						if ((j >> k & 1) != 0 && index[i][k] != -1 && (j >> index[i][k] & 1) != 0)
							good = true;
					}
					if (good) {
						nextPossible[j + (1 << i)] = true;
						for (int k = 0; k < i; k++) {
							if ((j >> k & 1) == 1)
								nextPossible[j + (1 << i) - (1 << k)] = true;
						}
					}
				}
			}
			boolean[] temp = possible;
			possible = nextPossible;
			nextPossible = temp;
		}
		int answer = Integer.MAX_VALUE;
		for (int i = 0; i < (1 << count); i++) {
			if (possible[i])
				answer = Math.min(answer, Integer.bitCount(i));
		}
		if (answer == Integer.MAX_VALUE)
			answer = -1;
		out.printLine(answer);
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

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	}

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	}