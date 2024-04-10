import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
		int carCount = in.readInt();
		int roundCount = in.readInt();
		int[][][] time = new int[carCount][][];
		for (int i = 0; i < carCount; i++)
			time[i] = IOUtils.readIntTable(in, count, count);
		for (int i = 0; i < carCount; i++) {
			for (int j = 0; j < count; j++) {
				for (int k = 0; k < count; k++) {
					for (int l = 0; l < count; l++)
						time[i][k][l] = Math.min(time[i][k][l], time[i][k][j] + time[i][j][l]);
				}
			}
		}
		int[][] minTime = new int[count][count];
		ArrayUtils.fill(minTime, Integer.MAX_VALUE);
		for (int i = 0; i < carCount; i++) {
			for (int j = 0; j < count; j++) {
				for (int k = 0; k < count; k++)
					minTime[j][k] = Math.min(minTime[j][k], time[i][j][k]);
			}
		}
		int[][][] answer = new int[count][count][count + 1];
		ArrayUtils.fill(answer, Integer.MAX_VALUE / 2);
		for (int i = 0; i < count; i++) {
			Arrays.fill(answer[i][i], 0);
			for (int j = 0; j < count; j++) {
				for (int k = 0; k < count; k++) {
					for (int l = 0; l < count; l++)
						answer[i][l][j + 1] = Math.min(answer[i][l][j + 1], answer[i][k][j] + minTime[k][l]);
				}
			}
		}
		for (int i = 0; i < roundCount; i++) {
			int from = in.readInt() - 1;
			int to = in.readInt() - 1;
			int changes = in.readInt() + 1;
			out.printLine(answer[from][to][Math.min(changes, count)]);
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