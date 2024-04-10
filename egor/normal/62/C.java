import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskC {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	private InputReader in;
	private PrintWriter out;

	private static final double EPS = 1e-5;

	private static class Point {
		private final double x;
		private final double y;

		private Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		public double distance(Point other) {
			return Math.sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
		}

		@Override
		public String toString() {
			return "(" + x + " " + y + ")";
		}
	}

	private static class Line {
		private final double a, b, c;

		private Line(Point a, Point b) {
			this.a = a.y - b.y;
			this.b = b.x - a.x;
			c = -a.x * this.a - a.y * this.b;
		}

		public Point intersect(Line other) {
			if (Math.abs(a * other.b - b * other.a) < EPS)
				return null;
			double x = (b * other.c - c * other.b) / (a * other.b - b * other.a);
			double y = (a * other.c - c * other.a) / (b * other.a - a * other.b);
			return new Point(x, y);
		}
	}

	private static class Segment {
		private final Point a;
		private final Point b;

		private Segment(Point a, Point b) {
			this.a = a;
			this.b = b;
		}

		public double length() {
			return a.distance(b);
		}

		public Point middle() {
			return new Point((a.x + b.x) / 2, (a.y + b.y) / 2);
		}

		public Point intersect(Segment other) {
			Line first = new Line(a, b);
			Line second = new Line(other.a, other.b);
			Point point = first.intersect(second);
			if (point != null && inside(point) && other.inside(point))
				return point;
			return null;
		}

		private boolean inside(Point point) {
			return Math.abs(length() - point.distance(a) - point.distance(b)) < EPS;
		}

		@Override
		public String toString() {
			return "{" + a + " " + b + "}";
		}
	}

	private static class Triangle {
		private final Point[] vertices;
		private final Segment[] sides;

		private Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
			vertices = new Point[]{new Point(x1, y1), new Point(x2, y2), new Point(x3, y3)};
			sides = new Segment[]{new Segment(vertices[0], vertices[1]), new Segment(vertices[1], vertices[2]),
				new Segment(vertices[2], vertices[0])};
		}

		public boolean inside(Point point) {
			double square = square();
			double allegedSquare = 0;
			for (int i = 0; i < 3; i++)
				allegedSquare += square(point, vertices[(i + 1) % 3], vertices[(i + 2) % 3]);
			return Math.abs(square - allegedSquare) < EPS;
		}

		private double square() {
			return square(vertices[0], vertices[1], vertices[2]);
		}

		private double square(Point a, Point b, Point c) {
			return .5 * Math.abs((a.x - b.x) * (a.y + b.y) + (b.x - c.x) * (b.y + c.y) + (c.x - a.x) * (c.y + a.y));
		}
	}

	private void solve() {
		int triangleCount = in.readInt();
		Triangle[] triangles = new Triangle[triangleCount];
		for (int i = 0; i < triangleCount; i++) {
			int x1 = in.readInt();
			int y1 = in.readInt();
			int x2 = in.readInt();
			int y2 = in.readInt();
			int x3 = in.readInt();
			int y3 = in.readInt();
			triangles[i] = new Triangle(x1, y1, x2, y2, x3, y3);
		}
		double perimeter = 0;
		for (int i = 0; i < triangleCount; i++) {
			for (final Segment side : triangles[i].sides) {
				List<Point> intersections = new ArrayList<Point>();
				intersections.add(side.a);
				intersections.add(side.b);
				for (int j = 0; j < triangleCount; j++) {
					if (i == j)
						continue;
					for (Segment otherSide : triangles[j].sides) {
						Point point = side.intersect(otherSide);
						if (point != null)
							intersections.add(point);
					}
				}
				Collections.sort(intersections, new Comparator<Point>() {
					public int compare(Point o1, Point o2) {
						return Double.compare(side.a.distance(o1), side.a.distance(o2));
					}
				});
				for (int j = 1; j < intersections.size(); j++) {
					Point first = intersections.get(j - 1);
					Point second = intersections.get(j);
					Segment toAdd = new Segment(first, second);
					Point middle = toAdd.middle();
					boolean outside = true;
					for (int k = 0; k < triangleCount && outside; k++) {
						if (i != k && triangles[k].inside(middle))
							outside = false;
					}
					if (outside)
						perimeter += toAdd.length();
				}
			}
		}
		out.printf("%.8f\n", perimeter);
	}

	public static void main(String[] args) {
		new TaskC().run();
	}

	private TaskC() {
		@SuppressWarnings({"UnusedDeclaration"})
		String id = getClass().getName().toLowerCase();
		//noinspection EmptyTryBlock
		try {
//			System.setIn(new FileInputStream(id + ".in"));
//			System.setOut(new PrintStream(new FileOutputStream(id + ".out")));
//			System.setIn(new FileInputStream("input.txt"));
//			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	private void run() {
		//noinspection InfiniteLoopStatement
//		int testCount = in.readInt();
//		for (int i = 0; i < testCount; i++)
//		while (true)
		solve();
		exit();
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private void exit() {
		out.close();
		System.exit(0);
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar, numChars;

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

		public long readLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public String readString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuffer res = new StringBuffer();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private String readLine0() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				if (c != '\r')
					buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		public String readLine() {
			String s = readLine0();
			while (s.trim().length() == 0)
				s = readLine0();
			return s;
		}

		public String readLine(boolean ignoreEmptyLines) {
			if (ignoreEmptyLines)
				return readLine();
			else
				return readLine0();
		}

		public BigInteger readBigInteger() {
			try {
				return new BigInteger(readString());
			} catch (NumberFormatException e) {
				throw new InputMismatchException();
			}
		}

		public char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
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

		public int[] readIntArray(int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = readInt();
			return array;
		}

		public long[] readLongArray(int size) {
			long[] array = new long[size];
			for (int i = 0; i < size; i++)
				array[i] = readLong();
			return array;
		}

		public double[] readDoubleArray(int size) {
			double[] array = new double[size];
			for (int i = 0; i < size; i++)
				array[i] = readDouble();
			return array;
		}

		public String[] readStringArray(int size) {
			String[] array = new String[size];
			for (int i = 0; i < size; i++)
				array[i] = readString();
			return array;
		}

		public char[][] readTable(int rowCount, int columnCount) {
			char[][] table = new char[rowCount][columnCount];
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++)
					table[i][j] = readCharacter();
			}
			return table;
		}

		public void readIntArrays(int[]... arrays) {
			for (int i = 0; i < arrays[0].length; i++) {
				for (int j = 0; j < arrays.length; j++)
					arrays[j][i] = readInt();
			}
		}
	}
}