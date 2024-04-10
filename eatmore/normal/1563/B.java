import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static int mod;

	static int add(int a, int b) {
		int res = a + b;
		return res >= mod ? res - mod : res;
	}

	static void solve() throws Exception {
		int n = scanInt();
		mod = scanInt();
		int ans[] = new int[n];
		ans[0] = 1;
		ans[1] = mod - 1;
		for (int i = 0; i < n - 1; i++) {
			int v = ans[i];
			int c = i + 1;
			ans[c] = add(ans[c], v);
			for (int m = c + c, a = 2; m <= n; m += c, a++) {
				ans[m - 1] = add(ans[m - 1], v);
				if (m + a <= n && v != 0) {
					ans[m + a - 1] = add(ans[m + a - 1], mod - v);
				}
			}
			ans[i + 1] = add(ans[i + 1], ans[i]);
		}
		out.print(ans[n - 1]);
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