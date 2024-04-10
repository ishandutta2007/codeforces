import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G {

	static final int BITS = 17;

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
		int n = scanInt();
		int a[] = new int[1 << BITS];
		for (int i = 0; i < n; i++) {
			++a[scanInt()];
		}
		int b[] = new int[1 << BITS];
		for (int i = 0; i < 1 << BITS; i++) {
			int bi = 0;
			for (int j = i;; j = (j - 1) & i) {
				bi = add(bi, mul(a[j], a[i ^ j]));
				if (j == 0) {
					break;
				}
			}
			b[i] = bi;
		}
		int c[] = a.clone();
		for (int bit = 0; bit < BITS; bit++) {
			int mask = (1 << BITS) - 1 - (1 << bit);
			for (int i = mask;; i = (i - 1) & mask) {
				int j = i | (1 << bit);
				int ci = c[i], cj = c[j];
				c[i] = add(ci, cj);
				c[j] = sub(ci, cj);
				if (i == 0) {
					break;
				}
			}
		}
		int mul = inv(1 << BITS);
		for (int i = 0; i < 1 << BITS; i++) {
			c[i] = mul(mul(c[i], c[i]), mul);
		}
		for (int bit = 0; bit < BITS; bit++) {
			int mask = (1 << BITS) - 1 - (1 << bit);
			for (int i = mask;; i = (i - 1) & mask) {
				int j = i | (1 << bit);
				int ci = c[i], cj = c[j];
				c[i] = add(ci, cj);
				c[j] = sub(ci, cj);
				if (i == 0) {
					break;
				}
			}
		}
		int fib[] = new int[1 << BITS];
		fib[1] = 1;
		for (int i = 2; i < 1 << BITS; i++) {
			fib[i] = add(fib[i - 1], fib[i - 2]);
		}
		for (int i = 0; i < 1 << BITS; i++) {
			a[i] = mul(a[i], fib[i]);
			b[i] = mul(b[i], fib[i]);
			c[i] = mul(c[i], fib[i]);
		}
		for (int bit = 0; bit < BITS; bit++) {
			int mask = (1 << BITS) - 1 - (1 << bit);
			for (int i = mask;; i = (i - 1) & mask) {
				int j = i | (1 << bit);
				a[i] = add(a[i], a[j]);
				b[i] = add(b[i], b[j]);
				c[i] = add(c[i], c[j]);
				if (i == 0) {
					break;
				}
			}
		}
		for (int i = 0; i < 1 << BITS; i++) {
			a[i] = mul(mul(a[i], b[i]), c[i]);
		}
		for (int bit = 0; bit < BITS; bit++) {
			int mask = (1 << BITS) - 1 - (1 << bit);
			for (int i = mask;; i = (i - 1) & mask) {
				int j = i | (1 << bit);
				a[i] = sub(a[i], a[j]);
				if (i == 0) {
					break;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < BITS; i++) {
			ans = add(ans, a[1 << i]);
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