import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskC {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			int[] x = new int[n];
			int[] y = new int[n];
			IOUtils.readIntArrays(in, x, y);
			Point[] starts = new Point[n];
			for (int i = 0; i < n; i++) {
				starts[i] = new Point(x[i], y[i]);
			}
			int[] answer = new int[3];
			answer[0] = 1;
			Point current = starts[0];
			int closest = 1;
			double distance = starts[1].distance(current);
			for (int i = 2; i < n; i++) {
				double candidate = current.distance(starts[i]);
				if (candidate < distance) {
					distance = candidate;
					closest = i;
				}
			}
			answer[1] = closest + 1;
			Line line = current.line(starts[closest]);
			long a = y[closest] - y[0];
			long b = x[0] - x[closest];
			long c = -a * x[0] - b * y[0];
			closest = -1;
			distance = Double.POSITIVE_INFINITY;
			for (int i = 0; i < n; i++) {
				if (a * x[i] + b * y[i] + c == 0) {
					continue;
				}
				double candidate = line.distance(starts[i]);
				if (candidate < distance) {
					distance = candidate;
					closest = i;
				}
			}
			answer[2] = closest + 1;
			out.printLine(answer);
		}

	}

	static class GeometryUtils {
		public static double epsilon = 1e-8;

		public static double fastHypot(double x, double y) {
			return Math.sqrt(x * x + y * y);
		}

	}

	static class Line {
		public final double a;
		public final double b;
		public final double c;

		public Line(Point p, double angle) {
			a = Math.sin(angle);
			b = -Math.cos(angle);
			c = -p.x * a - p.y * b;
		}

		public Line(double a, double b, double c) {
			double h = GeometryUtils.fastHypot(a, b);
			this.a = a / h;
			this.b = b / h;
			this.c = c / h;
		}

		public boolean parallel(Line other) {
			return Math.abs(a * other.b - b * other.a) < GeometryUtils.epsilon;
		}

		public double value(Point point) {
			return a * point.x + b * point.y + c;
		}

		public double distance(Point center) {
			return Math.abs(value(center));
		}


		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;

			Line line = (Line) o;

			if (!parallel(line)) return false;
			if (Math.abs(a * line.c - c * line.a) > GeometryUtils.epsilon || Math.abs(b * line.c - c * line.b) > GeometryUtils.epsilon)
				return false;

			return true;
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

		public void close() {
			writer.close();
		}

	}

	static class Point {
		public final double x;
		public final double y;


		public String toString() {
			return "(" + x + ", " + y + ")";
		}

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		public Line line(Point other) {
			if (equals(other))
				return null;
			double a = other.y - y;
			double b = x - other.x;
			double c = -a * x - b * y;
			return new Line(a, b, c);
		}


		public boolean equals(Object o) {
			if (this == o)
				return true;
			if (o == null || getClass() != o.getClass())
				return false;

			Point point = (Point) o;

			return Math.abs(x - point.x) <= GeometryUtils.epsilon && Math.abs(y - point.y) <= GeometryUtils.epsilon;
		}


		public int hashCode() {
			int result;
			long temp;
			temp = x != +0.0d ? Double.doubleToLongBits(x) : 0L;
			result = (int) (temp ^ (temp >>> 32));
			temp = y != +0.0d ? Double.doubleToLongBits(y) : 0L;
			result = 31 * result + (int) (temp ^ (temp >>> 32));
			return result;
		}

		public double distance(Point other) {
			return GeometryUtils.fastHypot(x - other.x, y - other.y);
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