import static java.lang.Double.NaN;
import static java.lang.Double.isNaN;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class C {

	static int n, r, f[], s[];
	static double p[];
	static double ans[][];
	static double time;

	static double get(int i, int j) {
		if (j > r) {
			return time;
		}
		if (i == n) {
			return 0;
		}
		double res = ans[i][j];
		if (!isNaN(res)) {
			return res;
		}
		int fi = f[i], si = s[i];
		double pi = p[i];
		res = pi * (fi + get(i + 1, j + fi)) + (1 - pi) * (si + get(i + 1, j + si));
		if (i != 0 && res > time) {
			res = time;
		}
//		System.err.println(" -> " + i + " " + j + " " + res);
		return ans[i][j] = res;
	}

	static void solve() throws Exception {
		n = scanInt();
		r = scanInt();
		f = new int[n];
		s = new int[n];
		p = new double[n];
		int fsum = 0, ssum = 0;
		double pprod = 1;
		for (int i = 0; i < n; i++) {
			f[i] = scanInt();
			s[i] = scanInt();
			p[i] = scanInt() / 100.0;
			fsum += f[i];
			ssum += s[i];
			pprod *= p[i];
		}
		ans = new double[n][r + 1];
		double left = fsum, right = ssum / pprod;
		while ((right - left) / left > 1e-12) {
			time = (left + right) / 2;
//			System.err.println("TIME " + time);
			for (double a[]: ans) {
				fill(a, NaN);
			}
			double res = get(0, 0);
			if (res < time) {
				right = time;
			} else {
				left = time;
			}
		}
		out.printf(Locale.US, "%.12f", (left + right) / 2);
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