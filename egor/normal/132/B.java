import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
	private int rowCount;
	private int columnCount;
	private int stepCount;
	private char[][] program;
	private int[][][][] firstTime;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		rowCount = in.readInt();
		stepCount = in.readInt();
		program = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			program[i] = in.readString().toCharArray();
		columnCount = program[0].length;
		firstTime = new int[rowCount][columnCount][4][4];
		ArrayUtils.fill(firstTime, -1);
		out.printLine(go(0, 0, 3, 2, 0));
	}

	private char go(int row, int column, int primaryDirection, int secondaryDirection, int step) {
		if (step == stepCount || firstTime[row][column][primaryDirection][secondaryDirection] != -1 &&
			(stepCount - firstTime[row][column][primaryDirection][secondaryDirection]) %
			(step - firstTime[row][column][primaryDirection][secondaryDirection]) == 0)
		{
			return program[row][column];
		}
		firstTime[row][column][primaryDirection][secondaryDirection] = step;
		int nextRow = row + MiscUtils.DX4[secondaryDirection];
		int nextColumn = column + MiscUtils.DY4[secondaryDirection];
		if (nextRow >= 0 && nextRow < rowCount && nextColumn >= 0 && nextColumn < columnCount &&
			program[row][column] == program[nextRow][nextColumn])
		{
			return go(nextRow, nextColumn, primaryDirection, secondaryDirection, step);
		}
		nextRow = row + MiscUtils.DX4[primaryDirection];
		nextColumn = column + MiscUtils.DY4[primaryDirection];
		if (nextRow >= 0 && nextRow < rowCount && nextColumn >= 0 && nextColumn < columnCount &&
			program[row][column] == program[nextRow][nextColumn])
		{
			return go(nextRow, nextColumn, primaryDirection, secondaryDirection, step);
		}
		if (nextRow >= 0 && nextRow < rowCount && nextColumn >= 0 && nextColumn < columnCount &&
			program[nextRow][nextColumn] != '0')
		{
			return go(nextRow, nextColumn, primaryDirection, secondaryDirection, step + 1);
		}
		if ((primaryDirection + 3) % 4 == secondaryDirection)
			return go(row, column, primaryDirection, (secondaryDirection + 2) % 4, step + 1);
		return go(row, column, (primaryDirection + 1) % 4, (secondaryDirection + 3) % 4, step + 1);
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

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

	public static void fill(int[][][] array, int value) {
		for (int[][] subArray : array)
			fill(subArray, value);
	}

	public static void fill(int[][][][] array, int value) {
		for (int[][][] subArray : array)
			fill(subArray, value);
	}

	}

class MiscUtils {
	public static final int[] DX4 = {1, 0, -1, 0};
	public static final int[] DY4 = {0, -1, 0, 1};

	}