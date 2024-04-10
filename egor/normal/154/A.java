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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		char[] string = in.readString().toCharArray();
		int count = in.readInt();
		boolean[][] forbidden = new boolean[256][256];
		for (int i = 0; i < count; i++) {
			char[] pair = in.readString().toCharArray();
			forbidden[pair[0]][pair[1]] = true;
			forbidden[pair[1]][pair[0]] = true;
		}
		int changeCount = 0;
		for (int i = 1; i < string.length; i++) {
			if (string[i] != string[i - 1])
				changeCount++;
		}
		char[] ch = new char[changeCount + 1];
		int[] cnt = new int[changeCount + 1];
		ch[0] = string[0];
		cnt[0] = 1;
		int index = 0;
		for (int i = 1; i < string.length; i++) {
			if (string[i] == string[i - 1])
				cnt[index]++;
			else {
				index++;
				ch[index] = string[i];
				cnt[index] = 1;
			}
		}
		int[] sum = new int[2];
		index = 0;
		int answer = 0;
		char current = 0;
		for (int i = 0; i <= changeCount; i++) {
			if (!forbidden[current][ch[i]]) {
				answer += Math.min(sum[0], sum[1]);
				sum[0] = sum[1] = 0;
			}
			sum[index] += cnt[i];
			index = 1 - index;
			current = ch[i];
		}
		answer += Math.min(sum[0], sum[1]);
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