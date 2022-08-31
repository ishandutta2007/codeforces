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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int size = in.readInt();
		int[] numbers = IOUtils.readIntArray(in, 1 << size);
		int[] next = new int[1 << size];
		long[] more = new long[size];
		long[] less = new long[size];
		boolean[] state = new boolean[size];
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < (1 << size); j += 1 << (i + 1)) {
				int middle = j + (1 << i);
				int end = middle + (1 << i);
				int at1 = j;
				int at2 = middle;
				int at = j;
				while (at1 < middle && at2 < end) {
					if (numbers[at1] <= numbers[at2]) {
						next[at++] = numbers[at1++];
						more[i] += at2 - middle;
					} else {
						next[at++] = numbers[at2++];
					}
				}
				while (at1 < middle) {
					next[at++] = numbers[at1++];
					more[i] += 1 << i;
				}
				while (at2 < end) {
					next[at++] = numbers[at2++];
				}
				at1 = j;
				at2 = middle;
				at = j;
				while (at1 < middle && at2 < end) {
					if (numbers[at1] < numbers[at2]) {
						next[at++] = numbers[at1++];
					} else {
						next[at++] = numbers[at2++];
						less[i] += at1 - j;
					}
				}
				while (at1 < middle) {
					next[at++] = numbers[at1++];
				}
				while (at2 < end) {
					next[at++] = numbers[at2++];
					less[i] += 1 << i;
				}
			}
			int[] temp = numbers;
			numbers = next;
			next = temp;
		}
		long answer = 0;
		for (long l : more)
			answer += l;
		int queryCount = in.readInt();
		for (int i = 0; i < queryCount; i++) {
			int query = in.readInt();
			for (int j = 0; j < query; j++) {
				if (state[j]) {
					answer += more[j];
					answer -= less[j];
				} else {
					answer += less[j];
					answer -= more[j];
				}
				state[j] ^= true;
			}
			out.printLine(answer);
		}
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

	public void close() {
		writer.close();
	}

	public void printLine(long i) {
		writer.println(i);
	}

	}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	}