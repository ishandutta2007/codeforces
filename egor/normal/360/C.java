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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	private static final long MOD = (long) (1e9 + 7);

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int length = in.readInt();
		int beauty = in.readInt();
		char[] sample = IOUtils.readCharArray(in, length);
		for (int i = 0; i < length; i++)
			sample[i] -= 'a';
		long[][] more = new long[length][beauty + 1];
		long[][] less = new long[length][beauty + 1];
		less[length - 1][0] = sample[length - 1] + 1;
		if (beauty > 0)
			more[length - 1][1] = 25 - sample[length - 1];
		for (int i = length - 1; i > 0; i--) {
			for (int j = 0; j <= beauty; j++) {
				if (less[i][j] != 0) {
					less[i][j] %= MOD;
					less[i - 1][j] += less[i][j] * (sample[i - 1] + 1);
					if (j + (length - i + 1) <= beauty)
						more[i - 1][j + (length - i + 1)] += less[i][j] * (25 - sample[i - 1]);
				}
				if (more[i][j] != 0) {
					more[i][j] %= MOD;
					int total = j;
					for (int k = i - 1; total <= beauty && k >= 0; k--) {
						less[k][total] += more[i][j] * sample[k];
						if (total + (length - k) <= beauty)
							more[k][total + (length - k)] += more[i][j] * (25 - sample[k]);
						total += length - i;
					}
					if (total <= beauty)
						less[0][total] += more[i][j];
				}
			}
		}
		long answer = (more[0][beauty] + less[0][beauty]) % MOD;
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

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
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

	public void close() {
		writer.close();
	}

	public void printLine(long i) {
		writer.println(i);
	}

	}

class IOUtils {

	public static char[] readCharArray(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	}