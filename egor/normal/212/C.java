import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[] s = in.readString().toCharArray();
		long[][] answer = new long[2][2];
		long[][] next = new long[2][2];
		answer[0][0] = answer[1][1] = 1;
		for (int i = 1; i <= s.length; i++) {
			int currentLetter = s[i - 1] - 'A';
			int nextLetter = s[i % s.length] - 'A';
			ArrayUtils.fill(next, 0);
			if (currentLetter == 0) {
				if (nextLetter == 0) {
					for (int j = 0; j < 2; j++) {
						next[j][0] = answer[j][1] + answer[j][0];
						next[j][1] = 0;
					}
				} else if (nextLetter == 1) {
					for (int j = 0; j < 2; j++) {
						next[j][0] = answer[j][1] + answer[j][0];
						next[j][1] = answer[j][1];
					}					
				}
			} else {
				if (nextLetter == 0) {
					for (int j = 0; j < 2; j++) {
						next[j][0] = answer[j][1];
						next[j][1] = answer[j][0];
					}
				} else if (nextLetter == 1) {
					for (int j = 0; j < 2; j++) {
						next[j][0] = answer[j][1];
						next[j][1] = answer[j][1];
					}					
				}				
			}
			long[][] temp = next;
			next = answer;
			answer = temp;
		}
		long result = answer[0][0] + answer[1][1];
		out.printLine(result);
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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
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

class ArrayUtils {

	public static void fill(long[][] array, long value) {
		for (long[] row : array)
			Arrays.fill(row, value);
	}

	}