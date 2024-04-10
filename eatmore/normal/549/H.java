import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
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

public class H {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		double a = nextDouble();
		double b = nextDouble();
		double c = nextDouble();
		double d = nextDouble();
		double l = 0;
		double r = max(abs(a), max(abs(b), max(abs(c), abs(d)))) + 1;
		for (int i = 0; i < 100; i++) {
			double mid = (l + r) * 0.5;
			double min1 = min((a - mid) * (d - mid),
				min((a - mid) * (d + mid),
				min((a + mid) * (d - mid),
				(a + mid) * (d + mid))));
			double max1 = max((a - mid) * (d - mid),
				max((a - mid) * (d + mid),
				max((a + mid) * (d - mid),
				(a + mid) * (d + mid))));
			double min2 = min((b - mid) * (c - mid),
				min((b - mid) * (c + mid),
				min((b + mid) * (c - mid),
				(b + mid) * (c + mid))));
			double max2 = max((b - mid) * (c - mid),
				max((b - mid) * (c + mid),
				max((b + mid) * (c - mid),
				(b + mid) * (c + mid))));
			if (min1 <= max2 && min2 <= max1) {
				r = mid;
			} else {
				l = mid;
			}
		}
		out.printf(Locale.US, "%.12f", (l + r) * 0.5);
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