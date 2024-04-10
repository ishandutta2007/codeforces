import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int maxWeight = in.readInt();
		int[] weights = IOUtils.readIntArray(in, count);
		long[] x = new long[maxWeight + 1];
		for (int i : weights)
			x[i] = 1;
		long[] y = FastFourierTransform.multiply(x, x);
		List<Integer> answer = new ArrayList<Integer>();
		for (int i = 1; i <= maxWeight; i++) {
			if (x[i] == 0 && y[i] != 0) {
				out.printLine("NO");
				return;
			}
			if (x[i] == 1 && y[i] == 0)
				answer.add(i);
		}
		out.printLine("YES");
		out.printLine(answer.size());
		out.printLine(answer.toArray());
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

class FastFourierTransform {
	public static void fft(double[] a, double[] b, boolean invert) {
		int count = a.length;
		for (int i = 1, j = 0; i < count; i++) {
			int bit = count >> 1;
			for (; j >= bit; bit >>= 1)
				j -= bit;
			j += bit;
			if (i < j) {
				double temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
		for (int len = 2; len <= count; len <<= 1) {
			int halfLen = len >> 1;
			double angle = 2 * Math.PI / len;
			if (invert)
				angle = -angle;
			double wLenA = Math.cos(angle);
			double wLenB = Math.sin(angle);
			for (int i = 0; i < count; i += len) {
				double wA = 1;
				double wB = 0;
				for (int j = 0; j < halfLen; j++) {
					double uA = a[i + j];
					double uB = b[i + j];
					double vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB;
					double vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA;
					a[i + j] = uA + vA;
					b[i + j] = uB + vB;
					a[i + j + halfLen] = uA - vA;
					b[i + j + halfLen] = uB - vB;
					double nextWA = wA * wLenA - wB * wLenB;
					wB = wA * wLenB + wB * wLenA;
					wA = nextWA;
				}
			}
		}
		if (invert) {
			for (int i = 0; i < count; i++) {
				a[i] /= count;
				b[i] /= count;
			}
		}
	}

	public static long[] multiply(long[] a, long[] b) {
		int resultSize = Integer.highestOneBit(Math.max(a.length, b.length) - 1) << 2;
		resultSize = Math.max(resultSize, 1);
		double[] aReal = new double[resultSize];
		double[] aImaginary = new double[resultSize];
		double[] bReal = new double[resultSize];
		double[] bImaginary = new double[resultSize];
		for (int i = 0; i < a.length; i++)
			aReal[i] = a[i];
		for (int i = 0; i < b.length; i++)
			bReal[i] = b[i];
		fft(aReal, aImaginary, false);
		fft(bReal, bImaginary, false);
		for (int i = 0; i < resultSize; i++) {
			double real = aReal[i] * bReal[i] - aImaginary[i] * bImaginary[i];
			aImaginary[i] = aImaginary[i] * bReal[i] + bImaginary[i] * aReal[i];
			aReal[i] = real;
		}
		fft(aReal, aImaginary, true);
		long[] result = new long[resultSize];
		for (int i = 0; i < resultSize; i++)
			result[i] = Math.round(aReal[i]);
		return result;
	}
}