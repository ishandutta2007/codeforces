import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int wishCount = in.readInt();
		int titleCount = in.readInt();
		int[][] values = new int[titleCount][];
		for (int i = 0; i < titleCount; i++)
			values[i] = IOUtils.readIntArray(in, in.readInt());
		int total = 0;
		for (int[] row : values)
			total += row.length;
		int[] all = new int[total];
		int index = 0;
		for (int[] row : values) {
			System.arraycopy(row, 0, all, index, row.length);
			index += row.length;
		}
		Arrays.sort(all);
		int smallest = all[total - wishCount];
		int[] shouldTake = new int[titleCount];
		int[] mayTake = new int[titleCount];
		int good = 0;
		int notBad = 0;
		for (int i = 0; i < titleCount; i++) {
			for (int j : values[i]) {
				if (j > smallest) {
					shouldTake[i]++;
					good++;
				} else if (j == smallest) {
					mayTake[i]++;
					notBad++;
				}
			}
		}
		int remaining = good + notBad - wishCount;
		double[] answer = new double[notBad - remaining + 1];
		answer[0] = 1;
		double[] next = new double[answer.length];
		double[][] c = new double[total + 1][total + 1];
		for (int i = 0; i <= total; i++) {
			c[i][0] = 1;
			for (int j = 1; j <= i; j++)
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
		int mayTakeRemaining = notBad;
		int willTake = answer.length - 1;
		for (int i = 0; i < titleCount; i++) {
			Arrays.fill(next, 0);
			for (int j = 0; j < answer.length; j++) {
				for (int k = 0; k <= mayTake[i] && j + k < answer.length; k++) {
					if (mayTakeRemaining < mayTake[i] || notBad < j + k)
						continue;
					double probability = c[mayTake[i]][k] * c[mayTakeRemaining - mayTake[i]][willTake - j - k] / c[mayTakeRemaining][willTake - j];
					double win = c[mayTake[i]][k] / c[values[i].length][shouldTake[i] + k];
					next[j + k] += answer[j] * probability * win;
				}
			}
			double[] temp = answer;
			answer = next;
			next = temp;
			mayTakeRemaining -= mayTake[i];
		}
		out.printLine(answer[answer.length - 1]);
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

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

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
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

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	}