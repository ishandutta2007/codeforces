import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static final int MOD = 31607;

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

	static int n, p[][], d[], ps[], pp[][];

	static void solve() throws Exception {
		n = scanInt();
		p = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				p[i][j] = mul(scanInt(), 3973);
			}
		}
		d = new int[n];
		ps = new int[n];
		fill(ps, 1);
		pp = new int[n][n];
		out.print(sub(1, go1()));
	}

	static int go1() {
		int ans = go2();
		int m = 1;
		for (int i = 0; i < n; i++) {
			m = mul(m, p[i][i]);
			p[i][i] = 1;
		}
		return sub(ans, mul(m, go2()));
	}

	static int go2() {
		int ans = go3(0, ps);
		int m = 1;
		for (int i = 0; i < n; i++) {
			m = mul(m, d[i] = p[i][n - i - 1]);
			p[i][n - i - 1] = 1;
		}
		ans = sub(ans, mul(m, go3(0, ps)));
		for (int i = 0; i < n; i++) {
			p[i][n - i - 1] = d[i];
		}
		return ans;
	}

	static int go3(int i, int a[]) {
		if (i == n) {
			int r = 1;
			for (int j = 0; j < n; j++) {
				r = mul(r, sub(1, a[j]));
			}
			return r;
		} else {
			int b[] = pp[i], c[] = p[i];
			int m = 1;
			for (int j = 0; j < n; j++) {
				b[j] = mul(a[j], c[j]);
				m = mul(m, c[j]);
			}
			return sub(go3(i + 1, b), mul(m, go3(i + 1, a)));
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