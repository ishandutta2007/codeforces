import java.util.InputMismatchException;
import java.math.BigInteger;
import java.io.*;
import java.util.HashSet;
import java.util.Set;

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
		Solver solver = new TaskB();
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

class StringHash {
	private static final long MULTIPLIER = 43;
	private static final long REVERSE_MULTIPLIER = BigInteger.valueOf(MULTIPLIER).modInverse(BigInteger.valueOf(2).pow(64)).longValue();

	private final long[] hash;
	private final long[] reversePower;

	public StringHash(CharSequence string) {
		hash = new long[string.length() + 1];
		long power = 1;
		reversePower = new long[hash.length];
		reversePower[0] = 1;
		for (int i = 0; i < hash.length - 1; i++) {
			hash[i + 1] = hash[i] + string.charAt(i) * power;
			power *= MULTIPLIER;
			reversePower[i + 1] = reversePower[i] * REVERSE_MULTIPLIER;
		}
	}

	public long hash(int from, int to) {
		return (hash[to] - hash[from]) * reversePower[from];
	}

	public long hash(int from) {
		return hash(from, hash.length - 1);
	}
}

class TaskB implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		String t = in.readString();
		String sBegin = in.readString();
		String sEnd = in.readString();
		StringHash hash = new StringHash(t);
		boolean[] ends = new boolean[t.length()];
		long endHash = new StringHash(sEnd).hash(0);
		for (int i = sEnd.length(); i <= t.length(); i++)
			ends[i - 1] = endHash == hash.hash(i - sEnd.length(), i);
		Set<Long> good = new HashSet<Long>();
		long beginHash = new StringHash(sBegin).hash(0);
		for (int i = 0; i <= t.length() - sBegin.length(); i++) {
			if (beginHash != hash.hash(i, i + sBegin.length()))
				continue;
			for (int j = i + Math.max(sBegin.length(), sEnd.length()) - 1; j < t.length(); j++) {
				if (ends[j])
					good.add(hash.hash(i, j + 1));
			}
		}
		out.println(good.size());
	}
}