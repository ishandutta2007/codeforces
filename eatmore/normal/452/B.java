import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.hypot;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Point {
		final int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Point other = (Point) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}
		
		
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		Set<Point> points = new HashSet<>();
		points.add(new Point(0, 0));
		points.add(new Point(n, 0));
		points.add(new Point(0, m));
		points.add(new Point(n, m));
		if (n > 0) {
			points.add(new Point(1, 0));
			points.add(new Point(n - 1, 0));
			points.add(new Point(1, m));
			points.add(new Point(n - 1, m));
		}
		if (m > 0) {
			points.add(new Point(0, 1));
			points.add(new Point(n, 1));
			points.add(new Point(0, m - 1));
			points.add(new Point(n, m - 1));
		}
		if (n > 0 && m > 0) {
			points.add(new Point(1, 1));
			points.add(new Point(n - 1, 1));
			points.add(new Point(1, m - 1));
			points.add(new Point(n - 1, m - 1));
		}
		Point res[] = new Point[4];
		search(points, 0, null, res);
		for (Point p: res) {
			out.println(p.x + " " + p.y);
		}
	}
	
	static double dist(Point a, Point b) {
		return hypot(a.x - b.x, a.y - b.y);
	}
	
	static double search(Set<Point> points, int depth, Point prev, Point res[]) {
		if (depth == 4) {
			return 0;
		}
		Point arr[] = points.toArray(new Point[points.size()]);
		double resVal = Double.NEGATIVE_INFINITY;
		Point resPoint = null;
		for (Point p: arr) {
			points.remove(p);
			double val = search(points, depth + 1, p, res);
			if (prev != null) {
				val += dist(p, prev);
			}
			points.add(p);
			if (val > resVal) {
				resVal = val;
				resPoint = p;
			}
		}
		if (resPoint == null) {
			throw new AssertionError();
		}
		points.remove(resPoint);
		search(points, depth +  1, resPoint, res);
		points.add(resPoint);
		res[depth] = resPoint;
		return resVal;
 	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}