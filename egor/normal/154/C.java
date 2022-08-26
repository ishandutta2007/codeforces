import java.io.IOException;
import java.util.Arrays;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int[] multipliers = new int[]{43, 47, 41, 37, 31, 53, 59};
		int count = in.readInt();
		int edgeCount = in.readInt();
		long[][] powers = new long[multipliers.length][count];
		for (int i = 0; i < multipliers.length; i++) {
			powers[i][0] = 1;
			for (int j = 1; j < count; j++)
				powers[i][j] = powers[i][j - 1] * multipliers[i];
		}
		long[][] hashes = new long[multipliers.length][count];
		for (int i = 0; i < edgeCount; i++) {
			int from = in.readInt() - 1;
			int to = in.readInt() - 1;
			for (int j = 0; j < multipliers.length; j++) {
				hashes[j][from] += powers[j][to];
				hashes[j][to] += powers[j][from];
			}
		}
		long[] resultHash = new long[count];
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < multipliers.length; j++)
				resultHash[i] += hashes[j][i];
		}
		Arrays.sort(resultHash);
		long current = resultHash[0];
		long start = 0;
		long answer = 0;
		for (int i = 1; i < count; i++) {
			if (resultHash[i] != current) {
				answer += (i - start) * (i - start - 1) / 2;
				start = i;
				current = resultHash[i];
			}
		}
		answer += (count - start) * (count - start - 1) / 2;
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < multipliers.length; j++)
				hashes[j][i] += powers[j][i];
		}
		for (int i = 0; i < count; i++) {
			resultHash[i] = 0;
			for (int j = 0; j < multipliers.length; j++)
				resultHash[i] += hashes[j][i];
		}
		Arrays.sort(resultHash);
		current = resultHash[0];
		start = 0;
		for (int i = 1; i < count; i++) {
			if (resultHash[i] != current) {
				answer += (i - start) * (i - start - 1) / 2;
				start = i;
				current = resultHash[i];
			}
		}
		answer += (count - start) * (count - start - 1) / 2;
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