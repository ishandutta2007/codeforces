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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int empty = in.readInt();
		long answer = 0;
		int N = count + 1;
		int end = count - empty + 1;
		for (int i = empty + 1; 2 * i <= count + 1; i++) {
//			if (i % 1000 == 0)
//				System.err.println(i);
//			long left = empty + 1;
//			long right = end - 1;
//			while (left < right) {
//				long middle = (left + right) >> 1;
//				if (value(N, i, middle, empty + 1) >= 0)
//					left = middle + 1;
//				else
//					right = middle;
//			}
			int k = empty + 1;
			int value = value(N, i, k, empty + 1);
			int sum = i + empty + 1;
			int current = 0;
			int x = count - empty;
			for (int j = empty + 1; j <= x; j++) {
				if (value >= 0) {
					if (value < sum) {
						k++;
						value -= sum;
					} else {
						int delta = value / sum + 1;
						k += delta;
						value -= delta * sum;
					}
				}
				if (k >= end)
					break;
				current += end - k;
				sum++;
				value += (N << 1) - (i + k);
			}
			if (2 * i != count + 1)
				current *= 2;
			answer += current;
		}
		answer *= 3;
		out.printLine(answer);
    }

	private int value(int n, int i, int k, int j) {
		return 2 * n * j - j * k - j * i - n * i - i * k + 2 * i * i;
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