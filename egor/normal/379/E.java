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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int segmentCount = in.readInt();
		int[][] values = IOUtils.readIntTable(in, count, segmentCount + 1);
		double[] answer = new double[count];
		double[] start = new double[count + 1];
		int[] index = new int[count];
		double[] nextStart = new double[count + 1];
		int[] nextIndex = new int[count];
		int[] a = new int[count];
		int[] b = new int[count];
		for (int i = 0; i < segmentCount; i++) {
			answer[0] += (values[0][i] + values[0][i + 1]) / 2d;
			start[0] = 0;
			start[1] = 1;
			index[0] = 0;
			a[0] = values[0][i + 1] - values[0][i];
			b[0] = values[0][i];
			int length = 1;
			for (int j = 1; j < count; j++) {
				a[j] = values[j][i + 1] - values[j][i];
				b[j] = values[j][i];
				boolean bad = false;
				for (int k = 0; k < j; k++) {
					if (a[j] == a[k] && b[j] == b[k]) {
						bad = true;
						break;
					}
				}
				if (bad)
					continue;
				int newLength = 0;
				for (int k = 0; k < length; k++) {
					double oldStart = a[index[k]] * start[k] + b[index[k]];
					double newStart = a[j] * start[k] + b[j];
					double oldEnd = a[index[k]] * start[k + 1] + b[index[k]];
					double newEnd = a[j] * start[k + 1] + b[j];
					if (oldStart >= newStart && oldEnd >= newEnd) {
						nextIndex[newLength] = index[k];
						nextStart[newLength++] = start[k];
						continue;
					}
					if (oldStart <= newStart && oldEnd <= newEnd) {
						if (newLength == 0 || nextIndex[newLength - 1] != j) {
							nextIndex[newLength] = j;
							nextStart[newLength++] = start[k];
						}
						answer[j] += (newStart - oldStart + newEnd - oldEnd) / 2 * (start[k + 1] - start[k]);
						continue;
					}
					double at = (start[k] * Math.abs(oldEnd - newEnd) + start[k + 1] * Math.abs(oldStart - newStart)) / (Math.abs(oldEnd - newEnd) + Math.abs(oldStart - newStart));
					if (oldStart >= newStart && oldEnd <= newEnd) {
						nextIndex[newLength] = index[k];
						nextStart[newLength++] = start[k];
						nextIndex[newLength] = j;
						nextStart[newLength++] = at;
						answer[j] += (newEnd - oldEnd) / 2 * (start[k + 1] - at);
						continue;
					}
					if (newLength == 0 || nextIndex[newLength - 1] != j) {
						nextIndex[newLength] = j;
						nextStart[newLength++] = start[k];
					}
					nextIndex[newLength] = index[k];
					nextStart[newLength++] = at;
					answer[j] += (newStart - oldStart) / 2 * (at - start[k]);
				}
				nextStart[newLength] = 1;
				double[] t1 = start;
				start = nextStart;
				nextStart = t1;
				int[] t2 = index;
				index = nextIndex;
				nextIndex = t2;
				length = newLength;
			}
		}
		for (double d : answer)
			out.printLine(d);
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

	public static int[][] readIntTable(InputReader in, int rowCount, int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readIntArray(in, columnCount);
		return table;
	}

	}