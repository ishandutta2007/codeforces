import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G {

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

	static int pow(int a, int e) {
		if (e == 0) {
			return 1;
		}
		int r = a;
		for (int i = 30 - Integer.numberOfLeadingZeros(e); i >= 0; i--) {
			r = mul(r, r);
			if ((e & (1 << i)) != 0) {
				r = mul(r, a);
			}
		}
		return r;
	}

	static int inv(int a) {
		return pow(a, MOD - 2);
	}

	static void solve() throws Exception {
		String x = scanString();
//		char xx[] = new char[700];
//		fill(xx, '9');
//		String x = new String(xx);
		int n = x.length();
		int pows[][] = new int[10][n];
		for (int i = 0; i < 10; i++) {
			pows[i][0] = 1;
			for (int j = 1; j < n; j++) {
				pows[i][j] = mul(pows[i][j - 1], i);
			}
		}
		int ru[] = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			ru[i] = add(1, mul(10, ru[i - 1]));
		}
		int facts[] = new int[n];
		facts[0] = 1;
		for (int i = 1; i < n; i++) {
			facts[i] = mul(facts[i - 1], i);
		}
		int factsInv[] = new int[n];
		factsInv[n - 1] = inv(facts[n - 1]);
		for (int i = n - 1; i > 0; i--) {
			factsInv[i - 1] = mul(factsInv[i], i);
		}
		int ans = 0;
		int off[] = new int[10];
		for (int i = 0; i < n; i++) {
			int cd = x.charAt(i) - '0';
			int l = n - i - 1;
			for (int d = 1; d < 10; d++) {
				for (int p = 0; p <= l; p++) {
					int mul = d < cd ? add(mul(d, ru[p + off[d]]), mul(cd - d, ru[p + off[d] + 1])) : mul(cd, ru[p + off[d]]);
					ans = add(ans, mul(mul, mul(mul(pows[d][l - p], pows[10 - d][p]), mul(facts[l], mul(factsInv[p], factsInv[l - p])))));
				}
			}
			for (int d = 0; d <= cd; d++) {
				++off[d];
			}
		}
		for (int d = 1; d < 10; d++) {
			ans = add(ans, ru[off[d]]);
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