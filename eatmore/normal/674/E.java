import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int q = nextInt();
//		int q = 500000;
		final int DEPTH = 100;
		int n = 1;
		int parent[] = new int[q + 1];
		parent[0] = -1;
		double p[][] = new double[DEPTH][q + 1];
		for (double pp[]: p) {
			fill(pp, 1);
		}
		for (int qq = 0; qq < q; qq++) {
			switch (nextInt()) {
			case 1:
			{
				int par = nextInt() - 1;
//				int par = qq;
				parent[n++] = par;
				double mul = 0.5;
				for (int cur = par, i = 1; i < DEPTH && cur >= 0; i++, cur = parent[cur]) {
					double newFrom = p[i][cur];
					p[i][cur] = newFrom * mul;
					mul += (1 - mul) / (newFrom + 1);
				}
				break;
			}
			case 2:
			{
				int v = nextInt() - 1;
//				int v = 0;
				double ans = DEPTH;
				for (int i = 0; i < DEPTH; i++) {
					ans -= p[i][v];
				}
				out.printf(Locale.US, "%.9f\n", ans);
				break;
			}
			default:
				throw new AssertionError();
			}
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