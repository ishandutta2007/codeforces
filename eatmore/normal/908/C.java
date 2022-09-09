import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.sqrt;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class C {

	static int sqr(int x) {
		return x * x;
	}

	static void solve() throws Exception {
		int n = scanInt();
		int r = scanInt();
		int x[] = new int[n];
		double y[] = new double[n];
		for (int i = 0; i < n; i++) {
			int cx = x[i] = scanInt();
			double cy = r;
			for (int j = 0; j < i; j++) {
				if (abs(cx - x[j]) <= 2 * r) {
					cy = max(cy, y[j] + sqrt(sqr(2 * r) - sqr(cx - x[j])));
				}
			}
			y[i] = cy;
			if (i > 0) {
				out.print(' ');
			}
			out.printf(Locale.US, "%.9f", cy);
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}