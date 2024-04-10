import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskC {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int h = in.readInt();
			int w = in.readInt();
			char[][] table = IOUtils.readTable(in, h, w);
			int[][] qtyV = new int[h + 1][w + 1];
			int[][] qtyH = new int[h + 1][w + 1];
			for (int i = h - 1; i >= 0; i--) {
				for (int j = w - 1; j >= 0; j--) {
					qtyV[i][j] = qtyV[i + 1][j] + qtyV[i][j + 1] - qtyV[i + 1][j + 1];
					qtyH[i][j] = qtyH[i + 1][j] + qtyH[i][j + 1] - qtyH[i + 1][j + 1];
					if (i != h - 1 && table[i][j] == '.' && table[i + 1][j] == '.') {
						qtyV[i][j]++;
					}
					if (j != w - 1 && table[i][j] == '.' && table[i][j + 1] == '.') {
						qtyH[i][j]++;
					}
				}
			}
			int q = in.readInt();
			for (int i = 0; i < q; i++) {
				int r1 = in.readInt() - 1;
				int c1 = in.readInt() - 1;
				int r2 = in.readInt() - 1;
				int c2 = in.readInt() - 1;
				int answer = qtyV[r1][c1] - qtyV[r1][c2 + 1] - qtyV[r2][c1] + qtyV[r2][c2 + 1] +
					qtyH[r1][c1] - qtyH[r1][c2] - qtyH[r2 + 1][c1] + qtyH[r2 + 1][c2];
				out.printLine(answer);
			}
		}

	}

	static class IOUtils {
		public static char[] readCharArray(InputReader in, int size) {
			char[] array = new char[size];
			for (int i = 0; i < size; i++)
				array[i] = in.readCharacter();
			return array;
		}

		public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
			char[][] table = new char[rowCount][];
			for (int i = 0; i < rowCount; i++)
				table[i] = readCharArray(in, columnCount);
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

		public void close() {
			writer.close();
		}

		public void printLine(int i) {
			writer.println(i);
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

		public char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);

		}

	}
}