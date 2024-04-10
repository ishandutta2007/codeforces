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
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		long[] numbers = IOUtils.readLongArray(in, count);
		long xor = 0;
		for (long i : numbers)
			xor ^= i;
		boolean[] answer = new boolean[count];
		int[] special = new int[60];
		long[] mask = new long[count];
		int step = 0;
		long secondXOR = 0;
		for (int i = 59; i >= 0; i--) {
			if ((xor >> i & 1) == 0) {
				for (int j = 0; j < count; j++) {
					if (mask[j] != -1 && (numbers[j] >> i & 1) == 1) {
						special[step] = j;
						if ((secondXOR >> i & 1) == 0) {
							for (int k = 0; k < step; k++) {
								if ((mask[j] >> k & 1) != 0)
									answer[special[k]] ^= true;
							}
							answer[j] = true;
							secondXOR ^= numbers[j];
						}
						for (int k = j + 1; k < count; k++) {
							if ((mask[k] != -1 && (numbers[k] >> i & 1) == 1)) {
								mask[k] ^= (1L << step) + mask[j];
								numbers[k] ^= numbers[j];
							}
						}
						mask[j] = -1;
						step++;
						break;
					}
				}
			}
		}
		for (int i = 59; i >= 0; i--) {
			if ((xor >> i & 1) == 1) {
				for (int j = 0; j < count; j++) {
					if (mask[j] != -1 && (numbers[j] >> i & 1) == 1) {
						special[step] = j;
						if ((secondXOR >> i & 1) == 0) {
							for (int k = 0; k < step; k++) {
								if ((mask[j] >> k & 1) != 0)
									answer[special[k]] ^= true;
							}
							answer[j] = true;
							secondXOR ^= numbers[j];
						}
						for (int k = j + 1; k < count; k++) {
							if ((mask[k] != -1 && (numbers[k] >> i & 1) == 1)) {
								mask[k] ^= (1L << step) + mask[j];
								numbers[k] ^= numbers[j];
							}
						}
						mask[j] = -1;
						step++;
						break;
					}
				}
			}
		}
		int[] result = new int[count];
		for (int i = 0; i < count; i++) {
			if (answer[i])
				result[i] = 2;
			else
				result[i] = 1;
		}
		out.printLine(result);
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

	public void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void printLine(int[] array) {
        print(array);
        writer.println();
    }

    public void close() {
		writer.close();
	}

	}

class IOUtils {

	public static long[] readLongArray(InputReader in, int size) {
		long[] array = new long[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readLong();
		return array;
	}

	}