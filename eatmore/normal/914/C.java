import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + MOD : res;
	}

	static void solve() throws Exception {
		String num = scanString();
		int k = scanInt();
		if (k == 0) {
			out.print(1);
			return;
		}
		if (k > 10) {
			out.print(0);
			return;
		}
		int n = num.length();
		int cs[] = new int[n];
		cs[0] = 1;
		int ones = 0;
		for (int i = 0; i < n; i++) {
			if (num.charAt(i) == '1') {
				++ones;
			}
		}
		int cnts[] = new int[n + 1];
		cnts[ones] = 1;
		for (int i = n - 1;; i--) {
			if (num.charAt(i) == '1') {
				--ones;
				for (int j = 0; j < n - i; j++) {
					cnts[ones + j] = add(cnts[ones + j], cs[j]);
				}
			}
			if (i == 0) {
				break;
			}
			for (int j = n - i; j > 0; j--) {
				cs[j] = add(cs[j], cs[j - 1]);
			}
		}
		if (k == 1) {
			out.print(sub(cnts[1], 1));
			return;
		}
		int bc[] = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			bc[i] = Integer.bitCount(i);
		}
		int ans = 0;
		for (--k; k > 0; --k) {
			if (k == 1) {
				ans = sub(ans, cnts[1]);
			}
			for (int i = 2; i <= n; i++) {
				cnts[bc[i]] = add(cnts[bc[i]], cnts[i]);
				cnts[i] = 0;
			}
			if (k == 1) {
				ans = add(ans, cnts[1]);
			}
		}
		out.print(ans);
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