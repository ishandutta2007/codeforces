import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), k = scanInt(), m = n - k, pair[] = new int[2 * n];
			fill(pair, -1);
			for (int i = 0; i < k; i++) {
				int x = scanInt() - 1, y = scanInt() - 1;
				pair[x] = y;
				pair[y] = x;
			}
			int p1 = 0, p2 = 0;
			for (int i = 0; i < m; i++) {
				while (pair[p2] >= 0) {
					++p2;
				}
				++p2;
			}
			for (int i = 0; i < m; i++) {
				while (pair[p1] >= 0) {
					++p1;
				}
				while (pair[p2] >= 0) {
					++p2;
				}
				pair[p1] = p2;
				pair[p2] = p1;
				++p1;
				++p2;
			}
			int ans = 0;
			for (int i = 0; i < 2 * n; i++) {
				int pi = pair[i];
				if (pi < i) {
					continue;
				}
				for (int j = i + 1; j < 2 * n; j++) {
					int pj = pair[j];
					if (pj < j) {
						continue;
					}
					if (pi > j && pi < pj) {
						++ans;
					}
				}
			}
			out.println(ans);
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