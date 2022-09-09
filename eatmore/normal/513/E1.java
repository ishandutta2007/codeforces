import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
//		int n = 30000;
//		int k = 200;
		long between[][] = new long[2][k - 1];
		long inMid[][] = new long[4][k - 2];
		for (long a[]: between) {
			fill(a, Long.MIN_VALUE / 2);
		}
		for (long a[]: inMid) {
			fill(a, Long.MIN_VALUE / 2);
		}
		long before = 0;
		long first0 = 0;
		long first1 = 0;
		long last0 = Long.MIN_VALUE / 2;
		long last1 = Long.MIN_VALUE / 2;
		long after = Long.MIN_VALUE / 2;
		for (int i = 0; i < n; i++) {
			long elem = nextLong();
//			long elem = 0;
			first0 += elem;
			first1 -= elem;
			for (int j = 0; j < k - 2; j++) {
				inMid[0][j] += 2 * elem;
				inMid[1][j] -= 2 * elem;
			}
			last0 += elem;
			last1 -= elem;
			after = max(after, max(last0, last1));
			if (i < n - 1) {
				for (int j = k - 2; j >= 0; j--) {
					if (j == 0) {
						between[0][0] = max(between[0][0], first0);
						between[1][0] = max(between[1][0], first1);
					} else {
						between[0][j] = max(between[0][j], max(inMid[0][j - 1], inMid[2][j - 1]));
						between[1][j] = max(between[1][j], max(inMid[1][j - 1], inMid[3][j - 1]));
					}
					if (j == k - 2) {
						last0 = max(last0, between[1][k - 2]);
						last1 = max(last1, between[0][k - 2]);
					} else {
						inMid[0][j] = max(inMid[0][j], between[1][j]);
						inMid[1][j] = max(inMid[1][j], between[0][j]);
						inMid[2][j] = max(inMid[2][j], between[0][j]);
						inMid[3][j] = max(inMid[3][j], between[1][j]);
					}
				}
				first0 = max(first0, before);
				first1 = max(first1, before);
			}
		}
		out.println(after);
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