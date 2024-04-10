import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int tests = scanInt();
		test: for (int test = 0; test < tests; test++) {
			int n = scanInt(), a[] = new int[n], b[] = new int[n], moves[] = new int[n + 1];
			for (int i = 0; i < n; i++) {
				a[i] = scanInt();
			}
			for (int i = 0; i < n; i++) {
				b[i] = scanInt();
			}
			int pos = 0;
			for (int i = 0; i < n; i++) {
				int cur = b[i];
				if (i > 0 && cur == b[i - 1] && moves[cur] > 0) {
					--moves[cur];
				} else {
					while (pos < n && a[pos] != cur) {
						++moves[a[pos]];
						++pos;
					}
					if (pos == n) {
						out.println("NO");
						continue test;
					}
					++pos;
				}
			}
			out.println("YES");
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