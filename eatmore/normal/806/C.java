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
		int pows[] = new int[45];
		int powsT[] = new int[45];
		for (int i = 0; i < n; i++) {
			long x = nextLong();
			if ((x & -x) == x) {
				++pows[Long.numberOfTrailingZeros(x)];
			} else {
				++powsT[Long.numberOfTrailingZeros(Long.highestOneBit(x)) + 1];
			}
		}
		boolean can = false;
		for (int res = 1; res <= pows[0]; res++) {
			int terms = 0;
			for (int i = 0; i < 45; i++) {
				terms += powsT[i] + max(pows[i] - res, 0);
			}
			if (terms > res) {
				continue;
			}
			int have = res, haveTerms = max(pows[0] - res, 0);
			for (int i = 0; i < 44; i++) {
//				have = min(have, pows[i]);
//				haveTerms += powsT[i + 1] + max(pows[i + 1] - have, 0);
//				haveTerms = max(haveTerms - have, 0);
				haveTerms = max(haveTerms - max(have - pows[i], 0), 0);
				have = min(have, pows[i]);
				haveTerms += powsT[i + 1] + max(pows[i + 1] - have, 0);
			}
			if (haveTerms == 0) {
				if (can) {
					out.print(' ');
				} else {
					can = true;
				}
				out.print(res);
			}
		}
		if (!can) {
			out.print(-1);
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