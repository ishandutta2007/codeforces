import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int moveCount = in.readInt();
		int r = in.readInt();
		int[] a = IOUtils.readIntArray(in, count);
		int[] b = IOUtils.readIntArray(in, count);
		int[] k = IOUtils.readIntArray(in, count);
		int[] p = IOUtils.readIntArray(in, count);
		MiscUtils.decreaseByOne(p);
		out.printLine(go(a, b, k, p, r, moveCount));
	}

	private long go(int[] a, int[] b, int[] k, int[] p, int r, int moveCount) {
		long answer = makeAdd(a, b, k, p, r, moveCount);
		if (moveCount != 0) {
			for (int i = 0; i < a.length; i++)
				a[i] ^= b[i];
			answer = Math.max(answer, makeAdd(a, b, k, p, r, moveCount - 1));
		}
		return answer;
	}

	private long makeAdd(int[] a, int[] b, int[] k, int[] p, int r, int moveCount) {
		long answer = Long.MIN_VALUE;
		if (moveCount % 2 == 0) {
			answer = 0;
			for (int i = 0; i < a.length; i++)
				answer += (long)a[i] * k[i];
		}
		if (moveCount == 0)
			return answer;
		int[] newA = new int[a.length];
		for (int i = 0; i < a.length; i++)
			newA[i] = a[p[i]] + r;
		return Math.max(answer, go(newA, b, k, p, r, moveCount - 1));
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

	}

class MiscUtils {

	public static void decreaseByOne(int[]...arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

	}