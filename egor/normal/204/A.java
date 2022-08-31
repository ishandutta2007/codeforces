import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	long[] tenPower = IntegerUtils.generatePowers(10, 19, Long.MAX_VALUE);

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		long left = in.readLong();
		long right = in.readLong();
		long answer = count(right) - count(left - 1);
		out.printLine(answer);
	}

	private long count(long max) {
		long answer = 0;
		long ten = 1;
		int digitCount = 1;
		while (ten <= max && ten > 0) {
			for (int i = 1; i <= 9 && i * ten <= max; i++) {
				if ((i + 1) * ten - 1 <= max) {
					if (ten == 1)
						answer++;
					else
						answer += tenPower[digitCount - 2];
				} else if (max >= i * ten + i) {
					answer += 1 + (max - i * ten - i) / 10;
				}
			}
			ten *= 10;
			digitCount++;
		}
		return answer;
	}
}

class IntegerUtils {

	public static long[] generatePowers(long base, int upTo, long mod) {
		long[] result = new long[upTo];
		if (upTo != 0)
			result[0] = 1 % mod;
		for (int i = 1; i < upTo; i++)
			result[i] = result[i - 1] * base % mod;
		return result;
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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
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