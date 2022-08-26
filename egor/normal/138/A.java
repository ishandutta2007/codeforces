import java.util.List;
import java.io.IOException;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int suffix = in.readInt();
		int answer = 15;
		for (int i = 0; i < count; i++) {
			String[] currentSuffix = new String[4];
			for (int j = 0; j < 4; j++) {
				String word = in.readString();
				int remaining = suffix;
				for (int k = word.length() - 1; k >= 0; k--) {
					if (MiscUtils.isStrictVowel(word.charAt(k)))
						remaining--;
					if (remaining == 0) {
						currentSuffix[j] = word.substring(k);
						break;
					}
				}
				if (currentSuffix[j] == null) {
					out.printLine("NO");
					return;
				}
			}
			if (currentSuffix[0].equals(currentSuffix[1]) && currentSuffix[0].equals(currentSuffix[2]) && currentSuffix[0].equals(currentSuffix[3]))
				continue;
			if (currentSuffix[0].equals(currentSuffix[1]) && currentSuffix[2].equals(currentSuffix[3])) {
				answer &= 3;
				continue;
			}
			if (currentSuffix[0].equals(currentSuffix[2]) && currentSuffix[1].equals(currentSuffix[3])) {
				answer &= 5;
				continue;
			}
			if (currentSuffix[0].equals(currentSuffix[3]) && currentSuffix[1].equals(currentSuffix[2])) {
				answer &= 9;
				continue;
			}
			out.printLine("NO");
			return;
		}
		if (Integer.bitCount(answer) % 2 != 0 || answer == 0) {
			out.printLine("NO");
			return;
		}
		for (int i = 0; i < 4; i++) {
			if ((answer >> i & 1) == 1)
				out.print('a');
			else
				out.print('b');
		}
		out.printLine();
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