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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		long[] happy = IntegerUtils.generateHappy(18);
		int count = in.readInt();
		long moveCount = in.readLong();
		long[] from = new long[count];
		long[] to = new long[count];
		IOUtils.readLongArrays(in, from, to);
		long[] leftSorted = from.clone();
		Arrays.sort(leftSorted);
		long[] rightSorted = to.clone();
		Arrays.sort(rightSorted);
		long maxLength = Long.MAX_VALUE;
		for (int i = 0; i < count; i++)
			maxLength = Math.min(maxLength, to[i] - from[i]);
		double[] leftApproximateSums = new double[count + 1];
		long[] leftExactSums = new long[count + 1];
		for (int i = count - 1; i >= 0; i--) {
			leftApproximateSums[i] = leftApproximateSums[i + 1] + leftSorted[i];
			leftExactSums[i] = leftExactSums[i + 1] + leftSorted[i];
		}
		double[] rightApproximateSums = new double[count + 1];
		long[] rightExactSums = new long[count + 1];
		for (int i = 1; i <= count; i++) {
			rightApproximateSums[i] = rightApproximateSums[i - 1] + rightSorted[i - 1];
			rightExactSums[i] = rightExactSums[i - 1] + rightSorted[i - 1];
		}
		double maxApproximateDiff = (double)moveCount + Long.MAX_VALUE;
		int leftIndex = 0;
		int rightIndex = 0;
		int answer = 0;
		for (int i = 0; i + answer < happy.length; i++) {
			while (leftIndex < count && leftSorted[leftIndex] <= happy[i])
				leftIndex++;
			for (int j = i + answer; j < happy.length; j++) {
				if (happy[j] - happy[i] > maxLength)
					break;
				while (rightIndex < count && rightSorted[rightIndex] < happy[j])
					rightIndex++;
				double approximate = leftApproximateSums[leftIndex] - (double)(count - leftIndex) * happy[i] +
					(double)rightIndex * happy[j] - rightApproximateSums[rightIndex];
				if (approximate > maxApproximateDiff)
					break;
				long exact = leftExactSums[leftIndex] - (count - leftIndex) * happy[i] + rightIndex * happy[j] -
					rightExactSums[rightIndex];
				if (moveCount - exact >= 0)
					answer++;
				else
					break;
			}
		}
		out.println(answer);
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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
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

	public static long[] generateHappy(int digits) {
		long[] happy = new long[(1 << (digits + 1)) - 2];
		happy[0] = 4;
		happy[1] = 7;
		int first = 0;
		int last = 2;
		for (int i = 2; i <= digits; i++) {
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

class IOUtils {

	public static void readLongArrays(InputReader in, long[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readLong();
		}
	}

	}