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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	static final long MOD = (long) (1e9 + 7);

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int length = in.readInt();
		int subStringLength = in.readInt();
		if (2 * subStringLength > length) {
			out.printLine(0);
			return;
		}
		char[] s = new char[length];
		for (int i = 0; i < length; i++)
			s[i] = in.readCharacter();
		long[] countDirect = count(s, length, subStringLength, 'B');
		char[] reverse = new char[length];
		for (int i = 0; i < length; i++)
			reverse[i] = s[length - i - 1];
		long[] countReverse = count(reverse, length, subStringLength, 'W');
		long answer = 0;
		long sum = 0;
		for (int i = 0; i + 2 * subStringLength <= length; i++) {
			if (s[i + subStringLength - 1] == 'X') {
				sum *= 2;
				if (sum >= MOD)
					sum -= MOD;
			}
			sum += countDirect[i];
			if (sum >= MOD)
				sum -= MOD;
			answer += sum * countReverse[length - i - 2 * subStringLength] % MOD;
		}
		answer %= MOD;
		out.printLine(answer);
	}

	private long[] count(char[] s, int length, int subStringLength, char good) {
		int countBad = 0;
		long[] count = new long[length];
		long[] result = new long[length];
		if (s[0] == 'X') {
			count[0] = 2;
		} else {
			count[0] = 1;
			if (s[0] != good)
				countBad++;
		}
		for (int i = 1; i < subStringLength; i++) {
			if (s[i] == 'X') {
				count[i] = count[i - 1] * 2;
				if (count[i] >= MOD)
					count[i] -= MOD;
			} else {
				count[i] = count[i - 1];
				if (s[i] != good)
					countBad++;
			}
		}
		if (countBad == 0) {
			result[0] = 1;
			count[subStringLength - 1]--;
		}
		for (int i = subStringLength; i < length; i++) {
			if (s[i] == 'X') {
				count[i] = count[i - 1] * 2;
				if (count[i] >= MOD)
					count[i] -= MOD;
			} else {
				count[i] = count[i - 1];
				if (s[i] != good)
				countBad++;
			}
			if (s[i - subStringLength] != 'X' && s[i - subStringLength] != good)
				countBad--;
			if (countBad == 0 && s[i - subStringLength] != good) {
				result[i - subStringLength + 1] = (i == subStringLength ? 1 : count[i - subStringLength - 1]);
				count[i] -= result[i - subStringLength + 1];
				if (count[i] < 0)
					count[i] += MOD;
			}
		}
		return result;
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

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
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