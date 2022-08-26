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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	private static final long MOD = (long) (1e9 + 7);

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		long width = in.readInt();
		long evenWidth = (width + 2) / 2;
		long oddWidth = (width + 1) / 2;
		long height = in.readInt();
		long evenHeight = (height + 2) / 2;
		long oddHeight = (height + 1) / 2;
		long total = 0;
		int[][] gcd = new int[(int) (width + 1)][(int) (height + 1)];
		for (int i = 0; i <= width; i++)
			gcd[i][0] = i + 1;
		for (int i = 0; i <= height; i++)
			gcd[0][i] = i + 1;
		for (int i = 1; i <= width; i++) {
			for (int j = 1; j <= height; j++) {
				if (i >= j)
					gcd[i][j] = gcd[i - j][j];
				else
					gcd[i][j] = gcd[i][j - i];
			}
		}
		for (int i = 0; i <= width; i++) {
			long remainingWidth = width - i + 1;
			for (int j = 0; j <= height; j++) {
				long remainingHeight = height - j + 1;
				long current;
				if ((i & 1) == 0) {
					if ((j & 1) == 0)
						current = (width + 1) * (height + 1) * remainingWidth * remainingHeight;
					else
						current = evenWidth * (height + 1) * ((remainingWidth + 1) >> 1) * remainingHeight + oddWidth * (height + 1) * (remainingWidth >> 1) * remainingHeight;
				} else {
					if ((j & 1) == 0)
						current = evenHeight * (width + 1) * ((remainingHeight + 1) >> 1) * remainingWidth + oddHeight * (width + 1) * (remainingHeight >> 1) * remainingWidth;
					else {
						current = (((height + 1) * (width + 1) + 1) >> 1) * ((remainingHeight * remainingWidth + 1) >> 1) +
							(((height + 1) * (width + 1)) >> 1) * ((remainingHeight * remainingWidth) >> 1);
					}
				}
				if (i != 0)
					current <<= 1;
				if (j != 0)
					current <<= 1;
				long currentMinus = 0;
				if (gcd[i][j] > 2)
					currentMinus += 6 * (gcd[i][j] - 2) * (width - i + 1) * (height - j + 1);
				if (gcd[i][j] > 1)
					currentMinus += 6 * (width - i + 1) * (height - j + 1);
				if (i != 0 && j != 0)
					currentMinus <<= 1;
				if (i == 0 && j == 0)
					currentMinus += (width + 1) * (height + 1);
				current -= currentMinus;
				total += current;
			}
			total %= MOD;
		}
		if (total < 0)
			total += MOD;
		out.printLine(total);
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