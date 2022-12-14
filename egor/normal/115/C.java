import java.util.ArrayList;
import java.util.List;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.util.Iterator;
import java.util.Comparator;
import java.io.*;
import java.util.Arrays;
import java.util.Collection;

/**
 * Generated by Contest helper plug-in
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

	public void close() {
		try {
			stream.close();
		} catch (IOException ignored) {
		}
	}
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

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
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

class TaskC implements Solver {
	private static final int MOD = 1000003;

	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		char[][] table = IOUtils.readTable(in, rowCount, columnCount);
		int answer = 1;
		for (int i = 0; i < rowCount; i++) {
			int type = 0;
			for (int j = 0; j < columnCount; j++) {
				if (table[i][j] != '.') {
					if (table[i][j] <= '2' && (j & 1) == 0 || table[i][j] >= '3' && (j & 1) == 1)
						type |= 1;
					else
						type |= 2;
				}
			}
			if (type == 3) {
				out.println(0);
				return;
			}
			if (type == 0) {
				answer *= 2;
				if (answer >= MOD)
					answer -= MOD;
			}
		}
		for (int i = 0; i < columnCount; i++) {
			int type = 0;
			for (int j = 0; j < rowCount; j++) {
				if (table[j][i] != '.') {
					if ((table[j][i] == '1' || table[j][i] == '4') && (j & 1) == 0 || (table[j][i] == '2' || table[j][i] == '3') && (j & 1) == 1)
						type |= 1;
					else
						type |= 2;
				}
			}
			if (type == 3) {
				out.println(0);
				return;
			}
			if (type == 0) {
				answer *= 2;
				if (answer >= MOD)
					answer -= MOD;
			}
		}
		out.println(answer);
	}
}