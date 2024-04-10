import java.io.IOException;
import java.util.InputMismatchException;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		if (columnCount == 1) {
			out.printLine("Second");
			return;
		}
		int maxPerMove = in.readInt();
		char[][] field = IOUtils.readTable(in, rowCount, columnCount);
		if (columnCount == 2) {
			boolean firstCanMove = false;
			boolean secondCanMove = false;
			for (int i = 0; i < rowCount; i++) {
				if (field[i][0] == 'G' && field[i][1] == '-' || field[i][1] == 'G' && field[i][0] == '-')
					firstCanMove = true;
				if (field[i][0] == 'R' && field[i][1] == '-' || field[i][1] == 'R' && field[i][0] == '-')
					secondCanMove = true;
			}
			if (!firstCanMove)
				out.printLine("Second");
			else if (!secondCanMove)
				out.printLine("First");
			else
				out.printLine("Draw");
			return;
		}
		int[] distance = new int[rowCount];
		boolean firstCanSkip = false;
		boolean secondCanSkip = false;
		for (int i = 0; i < rowCount; i++) {
			int rPosition = -1;
			int gPosition = -1;
			for (int j = 0; j < columnCount; j++) {
				if (field[i][j] == 'G')
					gPosition = j;
				else if (field[i][j] == 'R')
					rPosition = j;
			}
			if (rPosition == -1) {
				if (gPosition != -1)
					firstCanSkip = true;
			} else if (gPosition == -1)
				secondCanSkip = true;
			else
				distance[i] = Math.abs(rPosition - gPosition) - 1;
		}
		if (firstCanSkip) {
			if (secondCanSkip) {
				out.printLine("Draw");
				return;
			}
			out.printLine("First");
			return;
		} else if (secondCanSkip) {
			out.printLine("Second");
			return;
		}
		for (int i = 0; i < 7; i++) {
			int current = 0;
			for (int j : distance)
				current += j >> i & 1;
			if (current % (maxPerMove + 1) != 0) {
				out.printLine("First");
				return;
			}
		}
		out.printLine("Second");
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