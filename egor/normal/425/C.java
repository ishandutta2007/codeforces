import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
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
	private static final int M = 100000;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int firstSize = in.readInt();
		int secondSize = in.readInt();
		int energy = in.readInt();
		int cost = in.readInt();
		int[] firstArray = IOUtils.readIntArray(in, firstSize);
		int[] secondArray = IOUtils.readIntArray(in, secondSize);
//		int[] firstArray = ArrayUtils.createArray(firstSize, 1);
//		int[] secondArray = ArrayUtils.createArray(secondSize, 1);
		int max = energy / cost;
		int[] position = new int[max + 1];
		Arrays.fill(position, secondSize);
		position[0] = -1;
		int[] secondQty = new int[M + 1];
		for (int i = 0; i < secondSize; i++)
			secondQty[secondArray[i]]++;
		int[][] byValue = new int[M + 1][];
		for (int i = 0; i <= M; i++) {
			if (secondQty[i] != 0)
				byValue[i] = new int[secondQty[i]];
		}
		Arrays.fill(secondQty, 0);
		for (int i = 0; i < secondSize; i++)
			byValue[secondArray[i]][secondQty[secondArray[i]]++] = i;
		int answer = 0;
		for (int i = 0; i < firstSize; i++) {
			if (byValue[firstArray[i]] == null)
				continue;
			for (int j = max - 1; j >= 0; j--) {
				int at = Arrays.binarySearch(byValue[firstArray[i]], position[j] + 1);
				if (at < 0)
					at = -at - 1;
				if (at == byValue[firstArray[i]].length)
					continue;
				int cAt = byValue[firstArray[i]][at];
				position[j + 1] = Math.min(position[j + 1], cAt);
				if (cAt + 1 + i + 1 + (j + 1) * cost > energy)
					continue;
				answer = Math.max(answer, j + 1);
			}
		}
		out.printLine(answer);
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
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
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

	public void close() {
		writer.close();
	}

	public void printLine(int i) {
		writer.println(i);
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