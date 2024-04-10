import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.NavigableSet;
import java.util.Random;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class F {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Point {
		final int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
//		public String toString() {
//			return "(" + x + ", " + y + ")";
//		}
	}
	
	static int compare(int a, int b) {
		return a > b ? 1 : a < b ? -1 : 0;
	}
	
	static final NavigableSet<Point> setX = new TreeSet<>(new Comparator<Point>() {
		public int compare(Point o1, Point o2) {
			return o1.x != o2.x ? F.compare(o1.x, o2.x) : F.compare(o1.y, o2.y);
		}
	});

	static final NavigableSet<Point> setY = new TreeSet<>(new Comparator<Point>() {
		public int compare(Point o1, Point o2) {
			return o1.y != o2.y ? F.compare(o1.y, o2.y) : F.compare(o1.x, o2.x);
		}
	});
	
	static final Set<Integer> cutX = new TreeSet<>(); // x in bounds, no point at x, point at x-1
	static final Set<Integer> cutY = new TreeSet<>();
	
	static void clearPoints() {
		setX.clear();
		setY.clear();
		cutX.clear();
		cutY.clear();
	}
	
	static void addPoint(Point p) {
//		System.err.println("ADD " + p.x + " " + p.y + " " + cutX + " " + cutY);
		cutX.remove(p.x);
		cutY.remove(p.y);
		setX.add(p);
		setY.add(p);
		Point xp1 = setX.ceiling(new Point(p.x + 1, Integer.MIN_VALUE));
		if (xp1 != null && xp1.x > p.x + 1) {
			cutX.add(p.x + 1);
		}
		Point xm1 = setX.floor(new Point(p.x - 1, Integer.MAX_VALUE));
		if (xm1 != null && xm1.x < p.x - 1) {
			cutX.add(xm1.x + 1);
		}
		Point yp1 = setY.ceiling(new Point(Integer.MIN_VALUE, p.y + 1));
		if (yp1 != null && yp1.y > p.y + 1) {
			cutY.add(p.y + 1);
		}
		Point ym1 = setY.floor(new Point(Integer.MAX_VALUE, p.y - 1));
		if (ym1 != null && ym1.y < p.y - 1) {
			cutY.add(ym1.y + 1);
		}
//		System.err.println(cutX + " " + cutY);
	}
	
	static void removePoint(Point p) {
		setX.remove(p);
		setY.remove(p);
		Point xp = setX.ceiling(new Point(p.x, Integer.MIN_VALUE));
		if (xp == null || xp.x > p.x) {
			cutX.remove(p.x + 1);
			Point xm1 = setX.floor(new Point(p.x - 1, Integer.MAX_VALUE));
			if (xp == null && xm1 != null) {
				cutX.remove(xm1.x + 1);
			} else if (xp != null && xm1 != null && xm1.x == p.x - 1) {
				cutX.add(p.x);
			}
		}
		Point yp = setY.ceiling(new Point(Integer.MIN_VALUE, p.y));
		if (yp == null || yp.y > p.y) {
			cutY.remove(p.y + 1);
			Point ym1 = setY.floor(new Point(Integer.MAX_VALUE, p.y - 1));
			if (yp == null && ym1 != null) {
				cutY.remove(ym1.y + 1);
			} else if (yp != null && ym1 != null && ym1.y == p.y - 1) {
				cutY.add(p.y);
			}
		}
	}
	
//	static void check() {
//		if (!setX.equals(setY)) {
//			throw new AssertionError();
//		}
//		Set<Integer> checkX = new HashSet<>();
//		Set<Integer> checkY = new HashSet<>();
//		int maxX = Integer.MIN_VALUE;
//		int maxY = Integer.MIN_VALUE;
//		for (Point p: setX) {
//			checkX.add(p.x);
//			checkY.add(p.y);
//			maxX = max(maxX, p.x);
//			maxY = max(maxY, p.y);
//		}
//		Set<Integer> checkCutX = new HashSet<>();
//		Set<Integer> checkCutY = new HashSet<>();
//		for (int x: checkX) {
//			if (x + 1 <= maxX && !checkX.contains(x + 1)) {
//				checkCutX.add(x + 1);
//			}
//		}
//		for (int y: checkY) {
//			if (y + 1 <= maxY && !checkY.contains(y + 1)) {
//				checkCutY.add(y + 1);
//			}
//		}
//		if (!checkCutX.equals(cutX) || !checkCutY.equals(cutY)) {
//			for (Point p: setX) {
//				System.err.println(p.x + " " + p.y);
//			}
//			System.err.println(cutX);
//			System.err.println(cutY);
//			throw new AssertionError();
//		}
//	}
	
	static int go() {
		List<List<Point>> stack = new ArrayList<>();
		int ans = 0;
		while (true) {
//			check();
			if (!cutX.isEmpty()) {
				int x = cutX.iterator().next();
				List<Point> more = new ArrayList<>();
				List<Point> less = new ArrayList<>();
				Iterator<Point> itMore = setX.descendingIterator();
				Iterator<Point> itLess = setX.iterator();
				while (true) {
					Point p = itMore.next();
					if (p == null || p.x <= x) {
						stack.add(more);
						break;
					}
					more.add(p);
					p = itLess.next();
					if (p == null || p.x >= x) {
						stack.add(less);
						break;
					}
					less.add(p);
				}
			} else if (!cutY.isEmpty()) {
				int y = cutY.iterator().next();
				List<Point> more = new ArrayList<>();
				List<Point> less = new ArrayList<>();
				Iterator<Point> itMore = setY.descendingIterator();
				Iterator<Point> itLess = setY.iterator();
				while (true) {
					Point p = itMore.next();
					if (p == null || p.y <= y) {
						stack.add(more);
						break;
					}
					more.add(p);
					p = itLess.next();
					if (p == null || p.y >= y) {
						stack.add(less);
						break;
					}
					less.add(p);
				}
			} else {
				++ans;
				clearPoints();
				if (!stack.isEmpty()) {
					for (Point p: stack.remove(stack.size() - 1)) {
						addPoint(p);
					}
					continue;
				} else {
					break;
				}
			}
			for (Point p: stack.get(stack.size() - 1)) {
				removePoint(p);
			}
		}
		return ans;
	}
	
//	static int go(List<Point> points) {
//		for (Point p: points) {
//			removePoint(p);
//		}
//		int ans = go();
//		clearPoints();
//		for (Point p: points) {
//			addPoint(p);
//		}
//		return ans + go();
//	}
	
	static final Random rng = new Random(42);

	static void solve() throws Exception {
		int n = nextInt();
//		int n = 100000;
//		int n = 10; clearPoints();
//		System.err.println("BEGIN");
		for (int i = 0; i < n; i++) {
			addPoint(new Point(nextInt(), nextInt()));
//			addPoint(new Point(i, 2 * i));
//			addPoint(new Point(rng.nextInt(10), rng.nextInt(10)));
		}
		out.print(go());
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
			/*if (true) while (true) */solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}