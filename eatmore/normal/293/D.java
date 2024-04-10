import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int x[] = new int[n];
		int y[] = new int[n];
		long sumX = 0, sumY = 0;
		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
			y[i] = nextInt();
			sumX += x[i];
			sumY += y[i];
		}
		int avgX = (int) (sumX / n);
		int avgY = (int) (sumY / n);
		for (int i = 0; i < n; i++) {
			x[i] -= avgX;
			y[i] -= avgY;
		}
		double ansX = solve(x, y);
		double ansY = solve(y, x);
		out.printf(Locale.US, "%.9f", ansX + ansY);
	}
	
	static double solve(int x[], int y[]) {
//		System.err.println("SCAN");
//		System.err.println("x = " + Arrays.toString(x));
//		System.err.println("y = " + Arrays.toString(y));
		int n = x.length;
		int minX = Integer.MAX_VALUE;
		int minXminY = Integer.MAX_VALUE;
		int minXmaxY = Integer.MIN_VALUE;
		int maxX = Integer.MIN_VALUE;
		int maxXminY = Integer.MAX_VALUE;
		int maxXmaxY = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			int xi = x[i];
			int yi = y[i];
			if (xi < minX) {
				minX = xi;
				minXminY = Integer.MAX_VALUE;
				minXmaxY = Integer.MIN_VALUE;
			}
			if (xi == minX) {
				minXminY = min(minXminY, yi);
				minXmaxY = max(minXmaxY, yi);
			}
			if (xi > maxX) {
				maxX = xi;
				maxXminY = Integer.MAX_VALUE;
				maxXmaxY = Integer.MIN_VALUE;
			}
			if (xi == maxX) {
				maxXminY = min(maxXminY, yi);
				maxXmaxY = max(maxXmaxY, yi);
			}
		}
//		System.err.println("Minimum x: " + minX + " (" + minXminY + " .. " + minXmaxY + ")");
//		System.err.println("Maximum x: " + maxX + " (" + maxXminY + " .. " + maxXmaxY + ")");
		int pLeft = -1, pRight = -1;
		for (int i = 0; i < n; i++) {
			if (x[i] != minX && x[(i + 1) % n] == minX) {
				pLeft = i;
			}
			if (x[i] == minX && x[(i + 1) % n] != minX) {
				pRight = (i + 1) % n;
			}
		}
		if (pLeft < 0 || pRight < 0) {
			throw new AssertionError();
		}
		boolean orient;
		if (minXminY == minXmaxY) {
			orient = (long) (y[pLeft] - minXminY) * (x[pRight] - minX) <
				(long) (y[pRight] - minXminY) * (x[pLeft] - minX);
		} else {
			orient = y[(pLeft + 1) % n] != minXmaxY;
		}
		double sum1 = 0;
		double sumX = 0;
		double sumX2 = 0;
		for (int curX = minX; curX <= maxX; curX++) {
			int minLeft, minRight, maxLeft, maxRight;
			if (orient) {
				minLeft = (pLeft + 1) % n;
				minRight = pLeft;
				maxLeft = (pRight + n - 1) % n;
				maxRight = pRight;
			} else {
				minLeft = (pRight + n - 1) % n;
				minRight = pRight;
				maxLeft = (pLeft + 1) % n;
				maxRight = pLeft;
			}
			int minY = pointUp(x[minLeft], y[minLeft], x[minRight], y[minRight], curX);
			int maxY = pointDown(x[maxLeft], y[maxLeft], x[maxRight], y[maxRight], curX);
//			System.err.println("At x = " + curX + ": " + minY + " .. " + maxY);
			int cnt = maxY - minY + 1;
			sum1 += cnt;
			sumX += (double) cnt * curX;
			sumX2 += (double) cnt * curX * curX;
			while (x[pLeft] == curX) {
				pLeft = (pLeft + n - 1) % n;
			}
			while (x[pRight] == curX) {
				pRight = (pRight + 1) % n;
			}
		}
//		System.err.println("Total points: " + sum1);
//		System.err.println("Sum X: " + sumX);
//		System.err.println("Sum X^2: " + sumX2);
		return (sumX2 - sumX * sumX / sum1) / (sum1 - 1);
	}
	
	static int pointUp(int x1, int y1, int x2, int y2, int x) {
		return y1 + divUp((long) (y2 - y1) * (x - x1), x2 - x1);
	}
	
	static int divUp(long a, long b) {
		return (int) ((a < 0 ? a : a + b - 1) / b);
	}

	static int pointDown(int x1, int y1, int x2, int y2, int x) {
		return y1 + divDown((long) (y2 - y1) * (x - x1), x2 - x1);
	}
	
	static int divDown(long a, long b) {
		return (int) ((a < 0 ? a - b + 1 : a) / b);
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