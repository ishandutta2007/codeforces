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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskE {
		static int BUBEN = 512;

		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			int m = in.readInt();
			double[] bx = new double[(n - 1) / BUBEN + 2];
			double[] by = new double[bx.length];
			int[] bAng = new int[bx.length];
			int[] len = new int[n];
			int[] ang = new int[n];
			for (int i = 0; i < n; i++) {
				len[i] = 1;
			}
			for (int i = 0; i < bx.length - 1; i++) {
				bx[i] = i * BUBEN;
			}
			double[] cosa = new double[360];
			double[] sina = new double[360];
			for (int i = 0; i < 360; i++) {
				double a = Math.PI * i / 180;
				cosa[i] = Math.cos(a);
				sina[i] = Math.sin(a);
			}
			bx[bx.length - 1] = n;
			for (int i = 0; i < m; i++) {
				int type = in.readInt();
				int at = in.readInt() - 1;
				int delta = in.readInt();
				int chunk = at / BUBEN;
				if (type == 1) {
					int cAng = bAng[chunk];
					for (int j = chunk * BUBEN; j <= at; j++) {
						cAng += ang[j];
						if (cAng >= 360) {
							cAng -= 360;
						}
					}
					len[at] += delta;
					double dx = delta * cosa[cAng];
					double dy = -delta * sina[cAng];
					for (int j = chunk + 1; j < bx.length; j++) {
						bx[j] += dx;
						by[j] += dy;
					}
				} else {
					int cAng = bAng[chunk];
					double cx = bx[chunk];
					double cy = by[chunk];
					for (int j = chunk * BUBEN; j < at; j++) {
						cAng += ang[j];
						if (cAng >= 360) {
							cAng -= 360;
						}
						cx += len[j] * cosa[cAng];
						cy -= len[j] * sina[cAng];
					}
					ang[at] += delta;
					if (ang[at] >= 360) {
						ang[at] -= 360;
					}
					for (int j = chunk + 1; j < bx.length; j++) {
						bAng[j] += delta;
						if (bAng[j] >= 360) {
							bAng[j] -= 360;
						}
						double dx = bx[j] - cx;
						double dy = by[j] - cy;
						bx[j] = cx + dx * cosa[delta] + dy * sina[delta];
						by[j] = cy + dy * cosa[delta] - dx * sina[delta];
					}
				}
				out.printLine(bx[bx.length - 1], by[by.length - 1]);
			}
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