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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	private int count;
	private int[] x;
	private int[] y;
	private int[] r;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int xa = in.readInt();
		int ya = in.readInt();
		int xb = in.readInt();
		int yb = in.readInt();
		count = in.readInt();
		x = new int[count];
		y = new int[count];
		r = new int[count];
		IOUtils.readIntArrays(in, x, y, r);
		int x0 = Math.min(xa, xb);
		int x1 = Math.max(xa, xb);
		int y0 = Math.min(ya, yb);
		int y1 = Math.max(ya, yb);
		int answer = 0;
		for (int i = x0; i <= x1; i++) {
			if (check(i, y0))
				answer++;
			if (check(i, y1))
				answer++;
		}
		for (int i = y0 + 1; i < y1; i++) {
			if (check(x0, i))
				answer++;
			if (check(x1, i))
				answer++;
		}
		out.printLine(answer);
	}

	private boolean check(int xx, int yy) {
		for (int i = 0; i < count; i++) {
			if ((x[i] - xx) * (x[i] - xx) + (y[i] - yy) * (y[i] - yy) <= r[i] * r[i])
				return false;
		}
		return true;
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