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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskA {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			Point p = Point.readPoint(in);
			double min = Double.POSITIVE_INFINITY;
			double max = 0;
			Point first = null;
			Point last = null;
			for (int i = 0; i < n; i++) {
				Point current = Point.readPoint(in);
				if (i == 0) {
					first = current;
				}
				double distance = p.distance(current);
				min = Math.min(min, distance);
				max = Math.max(max, distance);
				if (last != null) {
					min = Math.min(min, new Segment(last, current).distance(p));
				}
				last = current;
				if (i == n - 1) {
					min = Math.min(min, new Segment(first, current).distance(p));
				}
			}
			double answer = (max - min) * (max + min) * Math.PI;
			out.printLine(answer);
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

	static class GeometryUtils {
		public static double epsilon = 1e-8;

		public static double fastHypot(double x, double y) {
			return Math.sqrt(x * x + y * y);
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

		public double readDouble() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') {
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) {
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, readInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);

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

		public double distance(Line line) {
			return Math.abs(line.a * x + line.b * y + line.c);
		}

		public static Point readPoint(InputReader in) {
			double x = in.readDouble();
			double y = in.readDouble();
			return new Point(x, y);
		}

	}

	static class Segment {
		public final Point a;
		public final Point b;
		private double distance = Double.NaN;
		private Line line = null;

		public Segment(Point a, Point b) {
			this.a = a;
			this.b = b;
		}

		public double length() {
			if (Double.isNaN(distance))
				distance = a.distance(b);
			return distance;
		}

		public double distance(Point point) {
			double length = length();
			double left = point.distance(a);
			if (length < GeometryUtils.epsilon)
				return left;
			double right = point.distance(b);
			if (left * left > right * right + length * length)
				return right;
			if (right * right > left * left + length * length)
				return left;
			return point.distance(line());
		}

		public Line line() {
			if (line == null)
				line = a.line(b);
			return line;
		}

	}
}