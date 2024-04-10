import java.io.IOException;
import java.io.OutputStreamWriter;
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
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] sequence = IOUtils.readIntArray(in, count);
		int closingCount = in.readInt();
		for (int i = 0; i < closingCount; i++)
			sequence[in.readInt() - 1] *= -1;
		int[] primaryStack = new int[count];
		int sizePrimary = 0;
		int[] secondaryStack = new int[count];
		int sizeSecondary = 0;
		for (int i = 0; i < sequence.length; i++) {
			if (sequence[i] > 0)
				primaryStack[sizePrimary++] = i;
			else {
				while (sizePrimary > 0 && !(sequence[primaryStack[sizePrimary - 1]] == -sequence[i] && sizeSecondary == 0)) {
					if (sizeSecondary > 0 && sequence[secondaryStack[sizeSecondary - 1]] == sequence[primaryStack[sizePrimary - 1]]) {
						sequence[secondaryStack[--sizeSecondary]] *= -1;
						sizePrimary--;
					} else
						secondaryStack[sizeSecondary++] = primaryStack[--sizePrimary];
				}
				if (sizePrimary == 0) {
					out.printLine("NO");
					return;
				}
				sizePrimary--;
			}
		}
		while (sizePrimary > 0) {
			if (sizeSecondary > 0 && sequence[secondaryStack[sizeSecondary - 1]] == sequence[primaryStack[sizePrimary - 1]]) {
				sequence[secondaryStack[--sizeSecondary]] *= -1;
				sizePrimary--;
			} else
				secondaryStack[sizeSecondary++] = primaryStack[--sizePrimary];
		}
		if (sizeSecondary != 0) {
			out.printLine("NO");
			return;
		}
		out.printLine("YES");
		out.printLine(sequence);
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

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

    public void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void printLine(int[] array) {
        print(array);
        writer.println();
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