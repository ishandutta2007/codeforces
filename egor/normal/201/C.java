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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] fragility = IOUtils.readIntArray(in, count - 1);
		long answer = ArrayUtils.sumArray(fragility);
		int countOdd = 0;
		for (int i = 0; i < count; i++) {
			int curDegree = 0;
			if (i != 0)
				curDegree += fragility[i - 1];
			if (i != count - 1)
				curDegree += fragility[i];
			if (curDegree % 2 == 1)
				countOdd++;
		}
		if (countOdd <= 2) {
			out.printLine(answer);
			return;
		}
		answer = 0;
		long[] current = new long[3];
		long[] next = new long[3];
		current[2] = Long.MIN_VALUE;
		for (int i = 0; i < count - 1; i++) {
			answer = Math.max(answer, current[2]);
			if (fragility[i] != 1) {
				next[0] = current[0] + fragility[i] - fragility[i] % 2;
				next[2] = current[2] + fragility[i] - fragility[i] % 2;
			} else
				next[0] = next[2] = 0;
			next[1] = current[1] + fragility[i] - (fragility[i] + 1) % 2;
			next[1] = Math.max(next[1], next[0]);
			next[2] = Math.max(next[2], next[1]);
			long[] temp = next;
			next = current;
			current = temp;
		}
		answer = Math.max(answer, current[2]);
		out.printLine(answer);
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

class ArrayUtils {

	public static long sumArray(int[] array) {
		long result = 0;
		for (int element : array)
			result += element;
		return result;
	}

	}