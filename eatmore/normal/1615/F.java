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

public class F {

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt();
			String a = scanString(), b = scanString();
			int mb = n / 2;
			int dyncnt[] = new int[2 * mb + 1], dynans[] = new int[2 * mb + 1], ndyncnt[] = new int[2 * mb + 1], ndynans[] = new int[2 * mb + 1];
			dyncnt[mb] = 1;
			for (int i = 0; i < n; i++) {
				int l = mb - min(i + 1, n - i - 1), r = mb + min(i + 1, n - i - 1);
				char ca = a.charAt(i), cb = b.charAt(i);
				if (ca == '?' && cb == '?') {
					for (int j = l; j <= r; j++) {
						int cnt = dyncnt[j], ans = dynans[j];
						cnt = add(cnt, cnt);
						ans = add(ans, ans);
						if (j > mb - i) {
							cnt = add(cnt, dyncnt[j - 1]);
							ans = add(ans, dynans[j - 1]);
						}
						if (j < mb + i) {
							cnt = add(cnt, dyncnt[j + 1]);
							ans = add(ans, dynans[j + 1]);
						}
						ndyncnt[j] = cnt;
						ndynans[j] = add(ans, mul(abs(j - mb), cnt));
					}
					int t[] = dyncnt;
					dyncnt = ndyncnt;
					ndyncnt = t;
					t = dynans;
					dynans = ndynans;
					ndynans = t;
				} else if (ca == '?' || cb == '?') {
					if ((ca == '0' || cb == '1') ^ ((i & 1) != 0)) {
						for (int j = l; j <= r; j++) {
							int cnt = dyncnt[j], ans = dynans[j];
							if (j < mb + i) {
								cnt = add(cnt, dyncnt[j + 1]);
								ans = add(ans, dynans[j + 1]);
							}
							ndyncnt[j] = cnt;
							ndynans[j] = add(ans, mul(abs(j - mb), cnt));
						}
					} else {
						for (int j = l; j <= r; j++) {
							int cnt = dyncnt[j], ans = dynans[j];
							if (j > mb - i) {
								cnt = add(cnt, dyncnt[j - 1]);
								ans = add(ans, dynans[j - 1]);
							}
							ndyncnt[j] = cnt;
							ndynans[j] = add(ans, mul(abs(j - mb), cnt));
						}
					}
					int t[] = dyncnt;
					dyncnt = ndyncnt;
					ndyncnt = t;
					t = dynans;
					dynans = ndynans;
					ndynans = t;
				} else if (ca != cb) {
					if ((ca == '0') ^ ((i & 1) != 0)) {
						for (int j = l; j <= r; j++) {
							int cnt = 0, ans = 0;
							if (j < mb + i) {
								cnt = dyncnt[j + 1];
								ans = dynans[j + 1];
							}
							ndyncnt[j] = cnt;
							ndynans[j] = add(ans, mul(abs(j - mb), cnt));
						}
					} else {
						for (int j = l; j <= r; j++) {
							int cnt = 0, ans = 0;
							if (j > mb - i) {
								cnt = dyncnt[j - 1];
								ans = dynans[j - 1];
							}
							ndyncnt[j] = cnt;
							ndynans[j] = add(ans, mul(abs(j - mb), cnt));
						}
					}
					int t[] = dyncnt;
					dyncnt = ndyncnt;
					ndyncnt = t;
					t = dynans;
					dynans = ndynans;
					ndynans = t;
				} else {
					for (int j = l; j < n; j++) {
						dynans[j] = add(dynans[j], mul(abs(j - mb), dyncnt[j]));
					}
				}
			}
			out.println(dynans[mb]);
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