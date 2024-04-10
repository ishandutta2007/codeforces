import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.min;
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
			int n = scanInt(), p[] = new int[n], c = 0;
			for (int i = 0; i < n; i++) {
				if ((scanInt() & 1) == 0) {
					p[c++] = i;
				}
			}
			if (c != n / 2 && c != (n + 1) / 2) {
				out.println(-1);
				continue;
			}
			long ans1 = 0, ans2 = 0;
			for (int i = 0; i < c; i++) {
				ans1 += abs(p[i] - 2 * i);
				ans2 += abs(p[i] - 2 * i - 1);
			}
			out.println((n & 1) == 0 ? min(ans1, ans2) : c == n / 2 ? ans2 : ans1);
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