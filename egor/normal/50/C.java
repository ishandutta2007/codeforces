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
	InputReader in;
	PrintWriter out;
	 static class Point {
		 final int x, y;
		 double angle;
		 private static final double EPS = 1e-8;

		 public Point(int x, int y) {
			 this.y = y;
			 this.x = x;
		 }

		 void countAngle(double meanX, double meanY) {
			 if (Math.abs(meanX - x) < EPS && Math.abs(meanY - y) < EPS)
				 return;
			 angle = Math.atan2(y - meanY, x - meanX);
		 }
	 }

	void solve() {
		int n = in.readInt();
		Point[] points = new Point[4 * n];
		for (int i = 0; i < n; i++) {
			int x = in.readInt();
			int y = in.readInt();
			points[4 * i] = new Point(x - 1, y);
			points[4 * i + 1] = new Point(x + 1, y);
			points[4 * i + 2] = new Point(x, y - 1);
			points[4 * i + 3] = new Point(x, y + 1);
		}
		Point minX = null;
		Point minY = null;
		Point maxX = null;
		Point maxY = null;
		Point minSum = null;
		Point minDif = null;
		Point maxSum = null;
		Point maxDif = null;
		for (Point vertex : points) {
			if (minX == null) {
				minX = vertex;
				maxX = vertex;
				minY = vertex;
				maxY = vertex;
				minDif = vertex;
				minSum = vertex;
				maxDif = vertex;
				maxSum = vertex;
			}
			if (vertex.x > maxX.x)
				maxX = vertex;
			if (vertex.y > maxY.y)
				maxY = vertex;
			if (vertex.x < minX.x)
				minX = vertex;
			if (vertex.y < minY.y)
				minY = vertex;
			if (vertex.x + vertex.y > maxSum.x + maxSum.y)
				maxSum = vertex;
			if (vertex.x - vertex.y > maxDif.x - maxDif.y)
				maxDif = vertex;
			if (vertex.x + vertex.y < minSum.x + minSum.y)
				minSum = vertex;
			if (vertex.x - vertex.y < minDif.x - minDif.y)
				minDif = vertex;
		}
		int ans = 0;
		ans += distance(minX, minSum);
		ans += distance(minSum, minY);
		ans += distance(minY, maxDif);
		ans += distance(maxDif, maxX);
		ans += distance(maxX, maxSum);
		ans += distance(maxSum, maxY);
		ans += distance(maxY, minDif);
		ans += distance(minDif, minX);
		out.println(ans);
/*		double meanX = 0;
		double meanY = 0;
		for (Point vertex : points) {
			meanX += vertex.x;
			meanY += vertex.y;
		}
		meanX /= 4 * n;
		meanY /= 4 * n;
		for (Point vertex : points)
			vertex.countAngle(meanX, meanY);
		Arrays.sort(points, new Comparator<Point>() {
			public int compare(Point o1, Point o2) {
				return Double.compare(o1.angle, o2.angle);
			}
		});
		Deque<Point> convexHull = new ArrayDeque<Point>();
		for (Point vertex : points) {
			while (convexHull.size() > 1) {
				Point last = convexHull.pollLast();
				Point nextToLast = convexHull.peekLast();
				double angle = getAngle(vertex, last, nextToLast);
				if (angle > 0) {
					convexHull.addLast(last);
					break;
				}
			}
			while (convexHull.size() > 1) {
				Point first = convexHull.pollFirst();
				Point second = convexHull.peekFirst();
				double angle = getAngle(second, first, vertex);
				if (angle > 0) {
					convexHull.addFirst(first);
					break;
				}
			}
			convexHull.addLast(vertex);
		}
		Point firstVertex = convexHull.getFirst();
		while (convexHull.size() > 1) {
			Point last = convexHull.pollLast();
			Point nextToLast = convexHull.peekLast();
			double angle = getAngle(firstVertex, last, nextToLast);
			if (angle > 0) {
				convexHull.addLast(last);
				break;
			}
		}
		convexHull.addLast(firstVertex);
		Point last = null;
		long ans = 0;
		for (Point vertex : convexHull) {
			if (last == null) {
				last = vertex;
				continue;
			}
			ans += Math.max(Math.abs(vertex.x - last.x), Math.abs(vertex.y - last.y));
			last = vertex;
		}
		out.println(ans);*/
	}

	private int distance(Point a, Point b) {
		return Math.max(Math.abs(a.x - b.x), Math.abs(a.y - b.y));
	}

	private double getAngle(Point vertex, Point last, Point nextToLast) {
		double angle = Math.atan2(vertex.y - nextToLast.y, vertex.x - nextToLast.x) - Math.atan2(last.y - nextToLast.y, last.x - nextToLast.x);
		while (Math.abs(angle) > Math.PI) {
			if (angle > 0)
				angle -= 2 * Math.PI;
			else
				angle += 2 * Math.PI;
		}
		return angle;
	}

	public static void main(String[] args) {
		new TaskC().run();
	}

	TaskC() {
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

	void run() {
		//noinspection InfiniteLoopStatement
		solve();
		exit();
	}

	@SuppressWarnings({"UnusedDeclaration"})
	void exit() {
		out.close();
		System.exit(0);
	}

	@SuppressWarnings({"UnusedDeclaration"})
	static class InputReader {
		InputStream stream;
		byte[] buf = new byte[1024];
		int curChar, numChars;

		InputReader(InputStream stream) {
			this.stream = stream;
		}

		int read() {
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

		int readInt() {
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

		long readLong() {
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

		String readString() {
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

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		String readLine0() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				if (c != '\r')
					buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		String readLine() {
			String s = readLine0();
			while (s.trim().length() == 0)
				s = readLine0();
			return s;
		}

		String readLine(boolean ignoreEmptyLines) {
			if (ignoreEmptyLines)
				return readLine();
			else
				return readLine0();
		}

		BigInteger readBigInteger() {
			try {
				return new BigInteger(readString());
			} catch (NumberFormatException e) {
				throw new InputMismatchException();
			}
		}

		char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		double readDouble() {
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
	}
}