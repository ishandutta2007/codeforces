import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt();
			String a = scanString(), b = scanString();
			int ca = 0, cb = 0, inv = 0;
			for (int i = 0; i < n; i++) {
				int aa = a.charAt(i) - '0', bb = b.charAt(i) - '0';
				ca += aa;
				cb += bb;
				inv += aa ^ bb;
			}
			int ans = Integer.MAX_VALUE;
			if (ca == cb) {
				ans = min(ans, inv);
			}
			if (ca + cb == n + 1) {
				ans = min(ans, n - inv);
			}
			out.println(ans == Integer.MAX_VALUE ? -1 : ans);
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