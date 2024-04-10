import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
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
		char[] string = in.readString().toCharArray();
		char[] sample = in.readString().toCharArray();
		if (string.length < sample.length) {
			out.printLine(0);
			return;
		}
		int[] sampleCount = new int[256];
		for (char c : sample)
			sampleCount[c]++;
		int[] count = new int[256];
		int bad = 0;
		for (int i = 0; i < sample.length; i++) {
			if (string[i] != '?') {
				count[string[i]]++;
				if (count[string[i]] == sampleCount[string[i]] + 1)
					bad++;
			}
		}
		int answer = 0;
		if (bad == 0)
			answer++;
		for (int i = sample.length; i < string.length; i++) {
			char current = string[i];
			if (current != '?') {
				count[current]++;
				if (count[current] == sampleCount[current] + 1)
					bad++;
			}
			char first = string[i - sample.length];
			if (first != '?') {
				count[first]--;
				if (count[first] == sampleCount[first])
					bad--;
			}
			if (bad == 0)
				answer++;
		}
		out.printLine(answer);
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