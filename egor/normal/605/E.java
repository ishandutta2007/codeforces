import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
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

	static class TaskE {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			int[][] p = IOUtils.readIntTable(in, n, n);
			double[] retain = new double[n];
			Arrays.fill(retain, 1);
			double[] answer = new double[n];
			double[] accumulated = new double[n];
			Arrays.fill(answer, Double.POSITIVE_INFINITY);
			answer[n - 1] = 0;
			boolean[] processed = new boolean[n];
			for (int i = 0; i < n; i++) {
				double best = Double.POSITIVE_INFINITY;
				int at = -1;
				for (int j = 0; j < n; j++) {
					if (!processed[j] && best > answer[j]) {
						best = answer[j];
						at = j;
					}
				}
				if (at == -1) {
					break;
				}
				processed[at] = true;
				for (int j = 0; j < n; j++) {
					if (processed[j] || p[j][at] == 0 || retain[j] == 0) {
						continue;
					}
					double nAccumulated = accumulated[j] + retain[j] * p[j][at] / 100d * (answer[at]);
					double nRetain = retain[j] * (1 - p[j][at] / 100d);
					double nAnswer = (1 + nAccumulated) / (1 - nRetain);
					if (nAnswer < answer[j]) {
						accumulated[j] = nAccumulated;
						retain[j] = nRetain;
						answer[j] = nAnswer;
					}
				}
			}
			out.printLine(answer[0]);
		}

	}

	static class InputReader {
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

	static class IOUtils {
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

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(Object... objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}

		public void printLine(Object... objects) {
			print(objects);
			writer.println();
		}

		public void close() {
			writer.close();
		}

	}
}