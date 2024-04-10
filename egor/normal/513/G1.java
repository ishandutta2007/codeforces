import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
		TaskG1 solver = new TaskG1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG1 {
	double numWays = 0;
	double total = 0;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int repeats = in.readInt();
		int[] permutation = IOUtils.readIntArray(in, count);
		go(permutation, repeats);
		out.printLine(total / numWays);
    }

	private void go(int[] permutation, int repeats) {
		if (repeats == 0) {
			numWays++;
			for (int i = 0; i < permutation.length; i++) {
				for (int j = 0; j < i; j++) {
					if (permutation[j] > permutation[i]) {
						total++;
					}
				}
			}
			return;
		}
		for (int i = 0; i < permutation.length; i++) {
			for (int j = 0; j <= i; j++) {
				int k = j;
				int l = i;
				while (k < l) {
					int temp = permutation[k];
					permutation[k] = permutation[l];
					permutation[l] = temp;
					k++;
					l--;
				}
				go(permutation, repeats - 1);
				k = j;
				l = i;
				while (k < l) {
					int temp = permutation[k];
					permutation[k] = permutation[l];
					permutation[l] = temp;
					k++;
					l--;
				}
			}
		}
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