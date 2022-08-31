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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		GeometryUtils.epsilon = 5e-6;
		int count = in.readInt();
		int[] x = new int[count];
		int[] y = new int[count];
		IOUtils.readIntArrays(in, x, y);
		double answer = calculate(x, y, count) + calculate(y, x, count);
		out.printLine(answer);
    }

	private double calculate(int[] x, int[] y, int count) {
		x = Arrays.copyOf(x, count + 1);
		y = Arrays.copyOf(y, count + 1);
		x[count] = x[0];
		y[count] = y[0];
		int minX = Integer.MAX_VALUE;
		int at = -1;
		int maxX = Integer.MIN_VALUE;
		for (int i = 0; i < count; i++) {
			if (x[i] < minX) {
				minX = x[i];
				at = i;
			}
			maxX = Math.max(maxX, x[i]);
		}
		long[] qty = new long[maxX - minX + 1];
		int side = at;
		int otherSide = at - 1;
		if (otherSide < 0)
			otherSide += count;
		for (int i = minX; i < maxX; i++) {
			while (x[side] <= i && x[side + 1] <= i) {
				side++;
				if (side == count)
					side = 0;
			}
			while (x[otherSide] <= i && x[otherSide + 1] <= i) {
				otherSide--;
				if (otherSide == -1)
					otherSide = count - 1;
			}
			double y0 = getY(x, y, side, i);
			double y1 = getY(x, y, otherSide, i);
			if (y0 < y1)
				qty[i - minX] = delta(y0, y1);
			else
				qty[i - minX] = delta(y1, y0);
		}
		int minY = Integer.MAX_VALUE;
		int maxY = Integer.MIN_VALUE;
		for (int i = 0; i < count; i++) {
			if (x[i] == maxX) {
				maxY = Math.max(maxY, y[i]);
				minY = Math.min(minY, y[i]);
			}
		}
		qty[maxX - minX] = maxY - minY + 1;
		double sum = 0;
		long total = 0;
		double result = 0;
		for (long i = 0; i < qty.length; i++) {
			long q = qty[((int) i)];
			sum += i * q;
			result += i * i * q;
			total += q;
		}
		result *= total;
		for (int i = 0; i < qty.length; i++)
			result -= sum * i * qty[i];
		result /= total;
		result /= total - 1;
//		result *= 2;
		return result;
	}

	private int delta(double y0, double y1) {
		return (int) (Math.round(Math.floor(y1 + GeometryUtils.epsilon)) - Math.round(Math.ceil(y0 - GeometryUtils.epsilon)) + 1);
	}

	private double getY(int[] x, int[] y, int side, int i) {
		return ((double)y[side] * Math.abs(x[side + 1] - i) + (double)y[side + 1] * Math.abs(x[side] - i)) / Math.abs(x[side] - x[side + 1]);
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

class GeometryUtils {
	public static double epsilon = 1e-8;

	}

class IOUtils {

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	}