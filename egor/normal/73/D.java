import java.util.InputMismatchException;
import java.math.BigInteger;
import java.io.*;
import java.util.Arrays;

/**
 * @author Egor Kulikov (egor@egork.net)
 * Actual solution is at the bottom
 */
public class Main {
	public static void main(String[] args) {
		InputReader in = new StreamInputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		run(in, out);
	}

	public static void run(InputReader in, PrintWriter out) {
		Solver solver = new TaskD();
		solver.solve(1, in, out);
		Exit.exit(in, out);
	}
}

abstract class InputReader {
	private boolean finished = false;

	public abstract int read();

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

	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public void setFinished(boolean finished) {
		this.finished = finished;
	}

	public abstract void close();

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

	@Override
	public void close() {
		try {
			stream.close();
		} catch (IOException ignored) {
		}
	}
}

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
}

class TaskD implements Solver {
	private int[] root;
	private int[] size;
	private int componentCount;

	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int n = in.readInt();
		int m = in.readInt();
		int k = in.readInt();
		root = new int[n];
		size = new int[n];
		componentCount = n;
		Arrays.fill(size, 1);
		for (int i = 0; i < n; i++)
			root[i] = i;
		for (int i = 0; i < m; i++) {
			int a = in.readInt() - 1;
			int b = in.readInt() - 1;
			join(a, b);
		}
		if (k == 1) {
			out.println(Math.max(0, componentCount - 2));
			return;
		}
		int totalWeight = 0;
		for (int i = 0; i < n; i++) {
			if (i == root[i])
				totalWeight += Math.min(k, size[i]);
		}
		int desiredComponentCount = totalWeight / 2 + 1;
		out.println(Math.max(0, componentCount - desiredComponentCount));
	}

	private void join(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b)
			return;
		componentCount--;
		root[b] = a;
		size[a] += size[b];
	}

	private int get(int v) {
		if (root[v] == v)
			return v;
		return root[v] = get(root[v]);
	}
}