import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.floorDiv;
import static java.lang.Math.floorMod;
import static java.lang.Math.max;
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
		long ws = nextLong();
		long c1 = nextLong();
		long c2 = nextLong();
		long w1 = nextLong();
		long w2 = nextLong();
		if (c1 * w2 < c2 * w1) {
			long t = c1;
			c1 = c2;
			c2 = t;
			t = w1;
			w1 = w2;
			w2 = t;
		}
		long cnt1 = ws / w1;
		long cnt2 = ws % w1 / w2;
		long wrem = ws % w1 % w2;
		long cans = c1 * cnt1 + c2 * cnt2;
		long ans = cans;
		int lim = 3000000;
		while (cnt1 > 0) {
			--cnt1;
			wrem += w1;
			cans -= c1;
			if (wrem >= w2) {
				long c = wrem / w2;
				wrem = wrem % w2;
				cnt2 += c;
				cans += c2 * c;
			} else {
				++cnt2;
				wrem -= w2;
				cans += c2;
				long c = floorDiv(wrem, w1);
				wrem = floorMod(wrem, w1);
				cnt1 += c;
				cans += c1 * c;
				if (cnt1 < 0) {
					break;
				}
			}
			ans = max(ans, cans);
			if (--lim == 0) {
				break;
			}
		}
		out.print(ans);
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