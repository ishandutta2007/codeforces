import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.Comparator;

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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		String first = in.readString();
		String second = in.readString();
		if (first.length() < second.length()) {
			first = new String(ArrayUtils.createArray(second.length() - first.length(), '0')) + first;
		} else {
			second = new String(ArrayUtils.createArray(first.length() - second.length(), '0')) + second;
		}
		int more = 0;
		int carry = 0;
		for (int i = 0; i < first.length(); i++) {
			int current = (int)first.charAt(i) - second.charAt(i);
			if (more != 0) {
				if (current != -more) {
					if (more > 0) {
						out.printLine('>');
					} else {
						out.printLine('<');
					}
					return;
				}
				carry = more;
				more = 0;
				continue;
			}
			if (carry != 0) {
				if (current == carry) {
					if (carry > 0) {
						out.printLine('>');
					} else {
						out.printLine('<');
					}
					return;
				}
			}
			more = carry + current;
			carry = 0;
		}
		if (more + carry > 0) {
			out.printLine('>');
		} else if (more + carry < 0) {
			out.printLine('<');
		} else {
			out.printLine('=');
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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
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

	public void printLine(char i) {
		writer.println(i);
	}

	public void close() {
		writer.close();
	}

}

class ArrayUtils {

	public static char[] createArray(int count, char value) {
		char[] array = new char[count];
		Arrays.fill(array, value);
		return array;
	}

}