import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Collection;
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
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int count = in.readInt();
		int index = in.readInt() - 1;
		int tail = -1;
		for (int i = 0; i <= count; i++) {
			if (IntegerUtils.factorial(i) > index) {
				tail = i;
				break;
			}
		}
		if (tail == -1) {
			out.println(-1);
			return;
		}
		long[] happy = generateHappy();
		int answer = Arrays.binarySearch(happy, count - tail);
		if (answer < 0)
			answer = -answer - 1;
		else
			answer++;
		boolean[] taken = new boolean[tail];
		int start = count - tail + 1;
		for (int i = 0; i < tail; i++) {
			long factorial = IntegerUtils.factorial(tail - i - 1);
			for (int j = 0; j < tail; j++) {
				if (!taken[j]) {
					if (factorial > index) {
						taken[j] = true;
						if (Arrays.binarySearch(happy, start + i) >= 0 && Arrays.binarySearch(happy, start + j) >= 0)
							answer++;
						break;
					} else
						index -= factorial;
				}
			}
		}
		out.println(answer);
	}

	private long[] generateHappy() {
		long[] happy = new long[(1 << 10) - 2];
		happy[0] = 4;
		happy[1] = 7;
		int first = 0;
		int last = 2;
		for (int i = 2; i <= 9; i++) {
			for (int j = 0; j < last - first; j++) {
				happy[last + 2 * j] = 10 * happy[first + j] + 4;
				happy[last + 2 * j + 1] = 10 * happy[first + j] + 7;
			}
			int next = last + 2 * (last - first);
			first = last;
			last = next;
		}
		return happy;
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

	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	}

class IntegerUtils {

	public static long factorial(int n) {
		long result = 1;
		for (int i = 2; i <= n; i++)
			result *= i;
		return result;
	}

	}