import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[][] table = IOUtils.readTable(in, 8, 8);
		table[0][7] = '.';
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 8; k++) {
					if (table[j][k] == 'M') {
						for (int l = 0; l < 8; l++) {
							int row = j + MiscUtils.DX8[l];
							int column = k + MiscUtils.DY8[l];
							if (row >= 0 && row < 8 && column >= 0 && column < 8 && table[row][column] == '.')
								table[row][column] = 'X';
						}
					}
				}
			}
			for (int j = 7; j >= 0; j--) {
				for (int k = 0; k < 8; k++) {
					if (table[j][k] == 'S') {
						if (j < 7)
							table[j + 1][k] = 'S';
						table[j][k] = '.';
					}
				}
			}
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 8; k++) {
					if (table[j][k] == 'X')
						table[j][k] = 'M';
				}
			}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (table[i][j] == 'M') {
					out.printLine("WIN");
					return;
				}
			}
		}
		out.printLine("LOSE");
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

	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
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

	public static char[] readCharArray(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
		char[][] table = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readCharArray(in, columnCount);
		return table;
	}

	}

class MiscUtils {
	public static final int[] DX8 = {1, 1, 1, 0, -1, -1, -1, 0};
	public static final int[] DY8 = {-1, 0, 1, 1, 1, 0, -1, -1};

	}