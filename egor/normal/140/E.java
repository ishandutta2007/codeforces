import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
		OutputWriter out = new OutputWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int levelCount = in.readInt();
		int colorCount = in.readInt();
		int module = in.readInt();
		long[][] count = new long[5001][];
		for (int i = 0; i <= 5000; i++)
			count[i] = new long[i + 2];
		count[0][0] = 1;
		for (int i = 1; i <= 5000; i++) {
			for (int j = 1; j <= i; j++)
				count[i][j] = (count[i - 1][j - 1] + (j - 1) * count[i - 1][j]) % module;
		}
		long[] c = new long[5001];
		long current = 1;
		for (int i = 1; i <= 5000; i++) {
			current *= colorCount - i + 1;
			current %= module;
			c[i] = current;
		}
		long[] factorial = IntegerUtils.generateFactorial(5001, module);
		int[] length = IOUtils.readIntArray(in, levelCount);
		long[] answer = new long[5001];
		for (int i = 1; i <= length[0]; i++)
			answer[i] = count[length[0]][i];
		long[] next = new long[5001];
		for (int i = 1; i < levelCount; i++) {
			long sum = 0;
			for (int j = 1; j <= length[i - 1]; j++)
				sum = (sum + c[j] * answer[j]) % module;
			for (int j = 1; j <= length[i]; j++) {
				next[j] = sum;
				if (j <= length[i - 1])
					next[j] -= answer[j] * factorial[j] % module;
				next[j] *= count[length[i]][j];
				next[j] %= module;
			}
			long[] temp = next;
			next = answer;
			answer = temp;
		}
		long sum = 0;
		for (int j = 1; j <= length[levelCount - 1]; j++)
			sum = (sum + c[j] * answer[j]) % module;
		if (sum < 0)
			sum += module;
		out.printLine(sum);
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

class IntegerUtils {

	public static long[] generateFactorial(int count, long module) {
		long[] result = new long[count];
		if (module == -1) {
			if (count != 0)
				result[0] = 1;
			for (int i = 1; i < count; i++)
				result[i] = result[i - 1] * i;
		} else {
			if (count != 0)
				result[0] = 1 % module;
			for (int i = 1; i < count; i++)
				result[i] = (result[i - 1] * i) % module;
		}
		return result;
	}

	}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	}