import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	double[] probHeight;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		String type = in.readString();
		int value = in.readInt();
		int maxHeight = in.readInt();
		probHeight = new double[maxHeight + 1];
		double curProb = 1;
		for (int i = 0; i < maxHeight; i++)
			probHeight[i] = curProb /= 2;
		probHeight[maxHeight] = curProb;
		if ("Alice".equals(type)) {
			if (maxHeight == 0) {
				out.printLine(value);
				return;
			}
			double[][] expectedOnHeight = new double[value + 1][maxHeight + 1];
			double[][] probOnHeight = new double[value + 1][maxHeight + 1];
			double[][] expectedStopOnHeight = new double[value + 1][maxHeight + 1];
			double[][] probStopOnHeight = new double[value + 1][maxHeight + 1];
			probOnHeight[0][0] = 1;
			for (int i = 1; i <= value; i++) {
				double sumLess = 0;
				double sumProb = 0;
				double sumExpected = 0;
				for (int j = 0; j <= maxHeight; j++) {
					expectedOnHeight[i][j] += probHeight[j] * ((1 << j) * probOnHeight[i - 1][j] + expectedOnHeight[i - 1][j]);
					probOnHeight[i][j] += probOnHeight[i - 1][j] * probHeight[j];
					expectedOnHeight[i][j] += sumExpected * probHeight[j];
					probOnHeight[i][j] += sumProb * probHeight[j];
					expectedStopOnHeight[i][j] = expectedOnHeight[i][j];
					probStopOnHeight[i][j] = probOnHeight[i][j];
					expectedOnHeight[i][j] += expectedOnHeight[i - 1][j] * sumLess;
					probOnHeight[i][j] += probOnHeight[i - 1][j] * sumLess;
					sumLess += probHeight[j];
					sumProb += probOnHeight[i - 1][j];
					sumExpected += (expectedOnHeight[i - 1][j] + (1 << j) * probOnHeight[i - 1][j]);
				}
			}
			double answer = 0;
			double totalProb = 0;
			for (int i = 1; i <= value; i++) {
				double sumProb = 0;
				double sumExpected = 0;
				for (int j = 0; j <= maxHeight; j++) {
					double expected = expectedStopOnHeight[i][j] * sumProb + sumExpected * probStopOnHeight[i][j];
					double probability = probStopOnHeight[i][j] * sumProb;
					answer += expected;
					totalProb += probability;
					sumProb += probOnHeight[value - i][j];
					sumExpected += expectedOnHeight[value - i][j] + (1 << j) * probOnHeight[value - i][j];
				}
			}
			double allOneProb = 1;
			for (int i = 0; i < value; i++)
				allOneProb /= 2;
			totalProb += allOneProb;
			answer += allOneProb * (value + 1);
			out.printLine(answer / totalProb - 1);
			return;
		}
		out.printLine(value);
    }
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

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
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
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