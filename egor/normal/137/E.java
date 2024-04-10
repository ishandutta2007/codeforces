import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Collections;
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
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[] s = in.readString().toCharArray();
		int[] farthest = new int[4 * s.length + 1];
		Arrays.fill(farthest, -1);
		int balance = 2 * s.length;
		farthest[balance] = 0;
		for (int i = 0; i < s.length; i++) {
			if (MiscUtils.isStrictVowel(s[i]))
				balance--;
			else
				balance += 2;
			farthest[balance] = i + 1;
		}
		for (int i = farthest.length - 2; i >= 0; i--)
			farthest[i] = Math.max(farthest[i], farthest[i + 1]);
		int maxLength = 0;
		int count = 0;
		balance = 2 * s.length;
		for (int i = 0; i < s.length; i++) {
			int curLength = farthest[balance] - i;
			if (curLength > maxLength) {
				maxLength = curLength;
				count = 1;
			} else if (curLength == maxLength)
				count++;
			if (MiscUtils.isStrictVowel(s[i]))
				balance--;
			else
				balance += 2;
		}
		if (maxLength == 0)
			out.printLine("No solution");
		else
			out.printLine(maxLength, count);
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

class MiscUtils {

	public static boolean isStrictVowel(char ch) {
		ch = Character.toUpperCase(ch);
		return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
	}

	}