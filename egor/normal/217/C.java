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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		in.readInt();
		if ((parseNode(in) & 4) != 0)
			out.printLine("YES");
		else
			out.printLine("NO");
	}

	private int parseNode(InputReader in) {
		int[] stack = new int[1000000];
		int stackSize = 0;
		while (!in.isExhausted()) {
			char c = in.readCharacter();
			if (c == ')') {
				int left = stack[--stackSize];
				int operation = stack[--stackSize];
				int right = stack[--stackSize];
				int result = 0;
				if (operation == '&') {
					if ((left & 1) != 0 || (right & 1) != 0 || (left & 4) != 0 && (right & 4) != 0)
						result++;
					result += (left & 2) & (right & 2);
					if ((left & 4) != 0 && (right & 6) != 0 || (right & 4) != 0 && (left & 6) != 0)
						result += 4;
				} else if (operation == '|') {
					result += (left & 1) & (right & 1);
					if ((left & 2) != 0 || (right & 2) != 0 || (left & 4) != 0 && (right & 4) != 0)
						result += 2;
					if ((left & 4) != 0 && (right & 5) != 0 || (right & 4) != 0 && (left & 5) != 0)
						result += 4;
				} else {
					if ((left & 1) != 0 && (right & 1) != 0 || (left & 2) != 0 && (right & 2) != 0 || (left & 4) != 0 && (right & 4) != 0)
						result++;
					if ((left & 1) != 0 && (right & 2) != 0 || (left & 2) != 0 && (right & 1) != 0 || (left & 4) != 0 && (right & 4) != 0)
						result += 2;
					if ((left & 3) != 0 && (right & 4) != 0 || (right & 3) != 0 && (left & 4) != 0)
						result += 4;
				}
				stack[stackSize++] = result;
			} else if (c == '0')
				stack[stackSize++] = 1;
			else if (c == '1')
				stack[stackSize++] = 2;
			else if (c == '?')
				stack[stackSize++] = 4;
			else if (c != '(')
				stack[stackSize++] = c;
		}
		return stack[0];
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

	public int peek() {
		if (numChars == -1)
			return -1;
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				return -1;
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar];
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

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
	}

	public boolean isExhausted() {
		int value;
		while (isSpaceChar(value = peek()) && value != -1)
			read();
		return value == -1;
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