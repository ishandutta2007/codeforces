import java.io.IOException;
import java.util.Arrays;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	private double[][] answer;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int whiteCount = in.readInt();
		int blackCount = in.readInt();
		answer = new double[whiteCount + 1][blackCount + 1];
		ArrayUtils.fill(answer, -1);
		out.printLine(go(whiteCount, blackCount));
	}

	private double go(int whiteCount, int blackCount) {
		if (answer[whiteCount][blackCount] != -1)
			return answer[whiteCount][blackCount];
		answer[whiteCount][blackCount] = 0;
		int remainingBlack = blackCount;
		double remainingProbability = 1;
		if (whiteCount == 0)
			return 0;
		answer[whiteCount][blackCount] += (double)whiteCount / (whiteCount + blackCount);
		if (remainingBlack == 0)
			return answer[whiteCount][blackCount];
		remainingProbability *= (double)remainingBlack / (whiteCount + remainingBlack);
		remainingBlack--;
		if (remainingBlack == 0)
			return answer[whiteCount][blackCount];
		remainingProbability *= (double)remainingBlack / (whiteCount + remainingBlack);
		remainingBlack--;
		if (remainingBlack == 0)
			return answer[whiteCount][blackCount] += remainingProbability;
		return answer[whiteCount][blackCount] += remainingProbability * ((double)whiteCount / (whiteCount + remainingBlack) * go(whiteCount - 1, remainingBlack) +
			(double)remainingBlack / (whiteCount + remainingBlack) * go(whiteCount, remainingBlack - 1));
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

class ArrayUtils {

	public static void fill(double[][] array, double value) {
		for (double[] row : array)
			Arrays.fill(row, value);
	}

	}