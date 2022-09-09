import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

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
		int k = scanInt();
		int pa = scanInt();
		int pb = scanInt();
		int den = inv(pa + pb);
		pa = mul(pa, den);
		pb = mul(pb, den);
		int ans = mul(pa, inv(pb));
		if (k == 1) {
			out.print(add(ans, 1));
			return;
		}
		int dyn[] = new int[k - 1];
		int ndyn[] = new int[k - 2];
		dyn[0] = 1;
		for (int a = 1; a < k; a++) {
			fill(ndyn, 0);
			for (int c = 0; c < k - a; c++) {
				int v = mul(pa, dyn[c]);
				if (a + c + 1 >= k) {
					ans = add(ans, mul(v, a + c + 1));
				} else {
					ndyn[c] = v;
				}
				v = mul(pb, dyn[c]);
				if (a + c + a >= k) {
					ans = add(ans, mul(v, a + c + a));
				} else {
					dyn[c + a] = add(dyn[c + a], v);
				}
			}
			int t[] = dyn;
			dyn = ndyn;
			ndyn = t;
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