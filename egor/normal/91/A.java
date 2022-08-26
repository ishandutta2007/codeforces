import java.util.InputMismatchException;
import java.math.BigInteger;
import java.io.*;
import java.util.Arrays;

/**
 * Generated by Contest helper plug-in
 * Actual solution is at the bottom
 */
public class Main {
	public static void main(String[] args) {
		InputReader in = new StreamInputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		run(in, out);
	}

	public static void run(InputReader in, PrintWriter out) {
		Solver solver = new TaskA();
		solver.solve(1, in, out);
		Exit.exit(in, out);
	}
}

abstract class InputReader {
	private boolean finished = false;

	public abstract int read();

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

	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public void setFinished(boolean finished) {
		this.finished = finished;
	}

	public abstract void close();
}

class StreamInputReader extends InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar, numChars;

	public StreamInputReader(InputStream stream) {
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

	public void close() {
		try {
			stream.close();
		} catch (IOException ignored) {
		}
	}
}

class Exit {
	private Exit() {
	}

	public static void exit(InputReader in, PrintWriter out) {
		in.setFinished(true);
		in.close();
		out.close();
	}
}

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
}

class TaskA implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		char[] name = in.readString().toCharArray();
		char[] target = in.readString().toCharArray();
		int[][] next = new int[name.length][26];
		Arrays.fill(next[name.length - 1], -1);
		for (int i = name.length - 1; i >= 0; i--)
			next[name.length - 1][name[i] - 'a'] = i;
		for (int i = name.length - 2; i >= 0; i--) {
			System.arraycopy(next[i + 1], 0, next[i], 0, 26);
			next[i][name[i + 1] - 'a'] = i + 1;
		}
		int position = name.length - 1;
		int answer = 0;
		for (char c : target) {
			int nextPosition = next[position][c - 'a'];
			if (nextPosition == -1) {
				answer = -1;
				break;
			}
			if (nextPosition <= position)
				answer++;
			position = nextPosition;
		}
		out.println(answer);
	}
}