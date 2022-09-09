import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		int n = nextInt();
		int dyn[] = new int[1440];
		int ndyn[] = new int[1440];
		int pt = -1000000;
		int cans = 0;
		for (int i = 0; i < n; i++) {
			int t = nextInt();
			int nans;
			if (t - pt >= 1440) {
				nans = cans + 20;
				dyn[0] = cans + 20;
				fill(dyn, 1, 90, cans + 50);
				fill(dyn, 90, 1440, cans + 120);
			} else {
				ndyn[0] = cans + 20;
				fill(ndyn, 1, 90, cans + 50);
				fill(ndyn, 90, 1440, cans + 120);
				int dt = t - pt;
				for (int j = dt; j < 1440; j++) {
					int nj = j - dt;
					ndyn[nj] = min(ndyn[nj], dyn[j]);
				}
				nans = ndyn[0];
				int tt[] = dyn;
				dyn = ndyn;
				ndyn = tt;
			}
			out.println(nans - cans);
			cans = nans;
			pt = t;
		}
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