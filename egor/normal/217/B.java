import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int result = in.readInt();
		if (count == 1 && result == 1) {
			out.printLine(0);
			out.printLine("T");
			return;
		}
		char[] current = new char[count];
		char[] answer = new char[count];
		int minErrors = Integer.MAX_VALUE;
		for (int i = 1; i < result; i++) {
			if (IntegerUtils.gcd(i, result - i) != 1)
				continue;
			int top = result - i;
			int bottom = i;
			boolean good = true;
			int errors = 0;
			current[count - 1] = 'T';
			for (int j = count - 2; j >= 0; j--) {
				if (top == 0 || bottom == 0 || errors >= minErrors) {
					good = false;
					break;
				}
				if (top > bottom || top == bottom && current[j + 1] == 'B') {
					current[j] = 'T';
					top -= bottom;
				} else {
					current[j] = 'B';
					bottom -= top;
				}
				if (current[j] == current[j + 1])
					errors++;
			}
			if (good && top + bottom == 1 && errors < minErrors) {
				minErrors = errors;
				for (int j = 0; j < count; j++) {
					if (current[0] == 'T')
						answer[j] = current[j];
					else
						answer[j] = (char) ('T' + 'B' - current[j]);
				}
			}
		}
		if (minErrors == Integer.MAX_VALUE) {
			out.printLine("IMPOSSIBLE");
			return;
		}
		out.printLine(minErrors);
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

	public void printLine(char[] array) {
		writer.println(array);
	}

	public void close() {
		writer.close();
	}

	}

class IntegerUtils {

    public static int gcd(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    }