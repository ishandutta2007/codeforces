import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NavigableSet;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskB {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int count = in.readInt();
			int[] a = new int[4 * count];
			int[] b = new int[4 * count];
			int[] c = new int[4 * count];
			IOUtils.readIntArrays(in, a, b, c);
			MiscUtils.decreaseByOne(a, b, c);
			NavigableSet<Integer> present = new TreeSet<>();
			for (int i = 0; i < 4 * count; i++) {
				present.add(i);
			}
			int[][] queries = new int[count][8];
			int[] size = new int[count];
			for (int i = 0; i < 4 * count; i++) {
				queries[b[i]][size[b[i]]++] = i;
				queries[c[i]][size[c[i]]++] = i;
			}
			int[] order = new int[4 * count];
			int at = 4 * count - 1;
			while (!present.isEmpty()) {
				int current = present.pollFirst();
				order[at--] = current + 1;
				int id = a[current];
				while (true) {
					boolean found = false;
					for (int j : queries[id]) {
						if (present.contains(j)) {
							present.remove(j);
							order[at--] = j + 1;
							id = a[j];
							found = true;
							break;
						}
					}
					if (!found) {
						break;
					}
				}
			}
			out.printLine("YES");
			out.printLine(order);
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

		public void printLine(Object... objects) {
			print(objects);
			writer.println();
		}

		public void close() {
			writer.close();
		}

	}

	static class IOUtils {
		public static void readIntArrays(InputReader in, int[]... arrays) {
			for (int i = 0; i < arrays[0].length; i++) {
				for (int j = 0; j < arrays.length; j++)
					arrays[j][i] = in.readInt();
			}
		}

	}

	static class MiscUtils {
		public static void decreaseByOne(int[]... arrays) {
			for (int[] array : arrays) {
				for (int i = 0; i < array.length; i++)
					array[i]--;
			}
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
}