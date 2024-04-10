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
		TaskH solver = new TaskH();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskH {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        long[] a = IOUtils.readLongArray(in, 4);
        double answer = Double.POSITIVE_INFINITY;
        int[] s = new int[4];
        for (int i = 0; i < 16; i++) {
            double k0 = a[0] * a[3] - a[1] * a[2];
            double k1 = 0;
            for (int j = 0; j < 4; j++) {
                s[j] = (i >> j & 1) == 1 ? -1 : 1;
                k1 += s[j] * a[j];
            }
            double k2 = s[0] * s[3] - s[1] * s[2];
            if (k2 == 0) {
                if (k1 == 0) {
                    if (k0 == 0) {
                        answer = 0;
                    }
                } else {
                    answer = Math.min(answer, Math.abs(k0 / k1));
                }
            } else {
                double d = k1 * k1 - 4 * k0 * k2;
                if (d >= 0) {
                    double x1 = (-k1 - Math.sqrt(d)) / (2 * k2);
                    double x2 = (-k1 + Math.sqrt(d)) / (2 * k2);
                    answer = Math.min(answer, Math.abs(x1));
                    answer = Math.min(answer, Math.abs(x2));
                }
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

	public static long[] readLongArray(InputReader in, int size) {
		long[] array = new long[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readLong();
		return array;
	}

}