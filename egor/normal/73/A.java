import java.util.InputMismatchException;
import java.math.BigInteger;
import java.io.*;
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
		Solver solver = new TaskA();
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

	public int[] readIntArray(int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = readInt();
		return array;
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

class TaskA implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int[] dimensions = in.readIntArray(3);
		int slices = in.readInt();
		Arrays.sort(dimensions);
		long result = 1;
		int firstSlices = Math.min(dimensions[0] - 1, slices / 3);
		result *= firstSlices + 1;
		slices -= firstSlices;
		int secondSlices = Math.min(dimensions[1] - 1, slices / 2);
		result *= secondSlices + 1;
		slices -= secondSlices;
		result *= Math.min(dimensions[2], slices + 1);
		out.println(result);
	}
}