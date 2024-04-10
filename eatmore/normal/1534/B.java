import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = scanInt();
			}
			int prev = 0;
			long ans = 0;
			for (int i = 0; i < n; i++) {
				int cur = a[i], next = i == n - 1 ? 0 : a[i + 1];
				int v = max(prev, next);
				if (cur > v) {
					ans += cur - v;
					cur = v;
				}
				if (cur > prev) {
					ans += cur - prev;
				}
				if (cur > next) {
					ans += cur - next;
				}
				prev = cur;
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