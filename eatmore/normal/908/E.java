import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static void solve() throws Exception {
		int m = scanInt();
		int n = scanInt();
		long v[] = new long[m];
		for (int i = 0; i < n; i++) {
			String s = scanString();
			for (int j = 0; j < m; j++) {
				if (s.charAt(j) == '1') {
					v[j] |= 1L << i;
				}
			}
		}
		sort(v);
		int acnt[][] = new int[m + 1][];
		acnt[0] = new int[] {1};
		int acntSum[] = new int[m + 1];
		for (int i = 1; i <= m; i++) {
			acnt[i] = new int[i + 1];
			int csum = 1;
			for (int j = 1; j < i; j++) {
				csum = add(csum, acnt[i][j] = add(acnt[i - 1][j - 1], mul(j, acnt[i - 1][j])));
			}
			acnt[i][i] = 1;
			acntSum[i] = csum;
		}
		int ans = 1;
		for (int i = 0, j; i < m; i = j) {
			for (j = i + 1; j < m && v[i] == v[j]; j++) { }
			ans = mul(ans, acntSum[j - i]);
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