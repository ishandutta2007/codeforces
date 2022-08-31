import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	static final long MOD = 1000000007;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		long[][] strict = new long[rowCount][columnCount];
		long[][] nonStrict = new long[rowCount][columnCount];
		Arrays.fill(strict[0], 1, columnCount, 1);
		Arrays.fill(nonStrict[0], 1, columnCount, 1);
		for (int i = 1; i < rowCount; i++) {
			long sum = 0;
			long result = 0;
			for (int j = 0; j < columnCount; j++) {
				result += sum;
				if (result >= MOD)
					result -= MOD;
				strict[i][j] = result;
				result += nonStrict[i - 1][j];
				sum += nonStrict[i - 1][j];
				if (result >= MOD)
					result -= MOD;
				if (sum >= MOD)
					sum -= MOD;
				nonStrict[i][j] = result;
			}
		}
		long answer = 0;
		for (int i = 0; i < columnCount; i++) {
			long sum = 0;
			long result = 0;
			long current = 0;
			for (int j = 0; j < rowCount; j++) {
				sum += nonStrict[j][i];
				if (sum >= MOD)
					sum -= MOD;
				result += sum;
				if (result >= MOD)
					result -= MOD;
				current += strict[rowCount - j - 1][i] * result % MOD;
			}
			current %= MOD;
			answer += current * (columnCount - i);
		}
		answer %= MOD;
		out.printLine(answer);
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