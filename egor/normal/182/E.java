import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	private static final long MOD = 1000000007;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int length = in.readInt();
		int[] height = new int[count];
		int[] width = new int[count];
		IOUtils.readIntArrays(in, height, width);
		long[][] answer = new long[length + 1][2 * count];
		for (int i = 0; i < count; i++) {
			if (height[i] <= length)
				answer[height[i]][i]++;
			if (width[i] <= length && height[i] != width[i])
				answer[width[i]][i + count]++;
		}
		for (int i = 1; i < length; i++) {
			for (int j = 0; j < 2 * count; j++) {
				if (answer[i][j] == 0)
					continue;
				answer[i][j] %= MOD;
				int requiredWidth = j < count ? width[j] : height[j - count];
				if (i + requiredWidth > length)
					continue;
				for (int k = 0; k < count; k++) {
					if (k == j || k + count == j)
						continue;
					if (height[k] == requiredWidth)
						answer[i + requiredWidth][k] += answer[i][j];
					else if (width[k] == requiredWidth)
						answer[i + requiredWidth][k + count] += answer[i][j];
				}
			}
		}
		long total = 0;
		for (long value : answer[length])
			total += value;
		total %= MOD;
		out.printLine(total);
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

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	}