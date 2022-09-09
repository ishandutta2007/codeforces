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
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int l[] = new int[n];
		int r[] = new int[n];
		for (int i = 0; i < n; i++) {
			l[i] = nextInt();
			r[i] = nextInt();
		}
		double ans = 0;
		for (int winner = 0; winner < n; winner++) {
			for (int second = 0; second < n; second++) {
				if (winner == second) {
					continue;
				}
				price: for (int price = l[second]; price <= r[second]; price++) {
					int lw = max(l[winner], winner > second ? price : price + 1);
					int rw = r[winner];
					if (lw > rw) {
						continue;
					}
					double cans = (double) price * (rw - lw + 1);
					for (int i = 0; i < n; i++) {
						if (i == winner || i == second) {
							continue;
						}
						int li = l[i];
						int ri = min(r[i], i < second ? price : price - 1);
						if (li > ri) {
							continue price;
						}
						cans *= ri - li + 1;
					}
					ans += cans;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			ans /= r[i] - l[i] + 1;
		}
		out.println(ans);
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