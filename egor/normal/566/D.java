import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.NavigableSet;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskD {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			int q = in.readInt();
			NavigableSet<Segment> segments = new TreeSet<>();
			for (int i = 0; i < n; i++) {
				segments.add(new Segment(i, i));
			}
			for (int i = 0; i < q; i++) {
				int type = in.readInt();
				int first = in.readInt() - 1;
				int second = in.readInt() - 1;
				if (type == 1) {
					Segment.join(segments.lower(new Segment(first, Integer.MAX_VALUE)), segments.lower(new Segment(second, Integer.MAX_VALUE)));
				} else if (type == 2) {
					Segment from = segments.lower(new Segment(first, Integer.MAX_VALUE));
					Segment to = segments.lower(new Segment(second, Integer.MAX_VALUE));
					if (from == to) {
						continue;
					}
					Segment segment = new Segment(from.from, to.to);
					NavigableSet<Segment> subSet = segments.subSet(from, true, to, true);
					for (Iterator<Segment> iterator = subSet.iterator(); iterator.hasNext(); ) {
						Segment subSegment = iterator.next();
						Segment.join(subSegment, segment);
						iterator.remove();
					}
					segments.add(segment);
				} else if (type == 3) {
					Segment from = segments.lower(new Segment(first, Integer.MAX_VALUE));
					Segment to = segments.lower(new Segment(second, Integer.MAX_VALUE));
					if (from.get() == to.get()) {
						out.printLine("YES");
					} else {
						out.printLine("NO");
					}
				}
			}
		}

		static class Segment implements Comparable<Segment> {
			int from;
			int to;
			Segment parent;

			public Segment(int from, int to) {
				this.from = from;
				this.to = to;
				parent = this;
			}

			Segment get() {
				if (parent == this) {
					return this;
				}
				return parent = parent.get();
			}

			static void join(Segment a, Segment b) {
				a = a.get();
				b = b.get();
				a.parent = b;
			}


			public int compareTo(Segment o) {
				if (from != o.from) {
					return Integer.compare(from, o.from);
				}
				return Integer.compare(to, o.to);
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