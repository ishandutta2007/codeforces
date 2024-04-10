import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void solve() throws Exception {
		int n = scanInt();
		int l = 2 * n - 1, r = 2001 * n - 1;
		while (l < r) {
			int m = (l + r) >> 1;
			out.println("? " + m);
			out.flush();
			if (scanInt() == 1) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		int ans = l;
		for (int i = 2; i <= n; i++) {
			if (ans >= i + 1) {
				int w = (ans - 1) / i;
				out.println("? " + w);
				out.flush();
				int h = scanInt();
				if (h == 0) {
					break;
				}
				ans = min(ans, w * h);
			}
		}
		out.println("! " + ans);
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