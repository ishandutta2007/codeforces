import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static final int MOD = 1000000000;
	
	static int add(int a, int b) {
		int res = a + b;
		if (res > MOD) {
			res -= MOD;
		}
		return res;
	}
	
	static int sub(int a, int b) {
		int res = a - b;
		if (res < 0) {
			res += MOD;
		}
		return res;
	}
	
	static int mul(int a, int b) {
		return (int) ((long) a * b % MOD);
	}
	
	static void incr(int f[], int i, int v) {
		do {
			f[i] = add(f[i], v);
			i |= i + 1;
		} while (i < f.length);
	}
	
	static int sum(int f[], int i) {
		int a = 0;
		do {
			a = add(a, f[i]);
			i = (i & (i + 1)) - 1;
		} while (i >= 0);
		return a;
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int a[] = new int[n + 1];
		int fibs[] = new int[n + 1];
		int fibs2[] = new int[n + 1];
		int fibsums[] = new int[n + 1];
		int fibsums2[] = new int[n + 1];
		fibs[1] = fibs2[0] = fibs2[1] = 1;
		for (int i = 2; i <= n; i++) {
			fibs[i] = add(fibs[i - 1], fibs[i - 2]);
			fibs2[i] = add(fibs2[i - 1], fibs2[i - 2]);
		}
		fibsums[0] = fibs[0];
		fibsums2[0] = fibs2[0];
		for (int i = 1; i <= n; i++) {
			fibsums[i] = add(fibsums[i - 1], fibs[i]);
			fibsums2[i] = add(fibsums2[i - 1], fibs2[i]);
		}
		int afibs[] = new int[n + 1];
		int afibs2[] = new int[n + 1];
		{
			int prev = 0;
			for (int i = 0; i < n; i++) {
				int cur = nextInt();
				int diff = sub(cur, prev);
				int undiff = sub(0, diff);
				incr(a, i, diff);
				if (i > 0) {
					incr(afibs, i, mul(undiff, fibsums[i - 1]));
					incr(afibs2, i, mul(undiff, fibsums2[i - 1]));
				}
				prev = cur;
			}
		}
		for (int q = 0; q < m; q++) {
			int t = nextInt();
			if (t == 1) {
				int i = nextInt() - 1;
				int diff = sub(nextInt(), sum(a, i));
				int undiff = sub(0, diff);
				incr(a, i, diff);
				incr(a, i + 1, undiff);
				if (i > 0) {
					incr(afibs, i, mul(undiff, fibsums[i - 1]));
					incr(afibs2, i, mul(undiff, fibsums2[i - 1]));
				}
				incr(afibs, i + 1, mul(diff, fibsums[i]));
				incr(afibs2, i + 1, mul(diff, fibsums2[i]));
			} else if (t == 2) {
				int l = nextInt() - 1;
				int r = nextInt();
				int res1 = add(mul(sum(a, r - 1), fibsums[r - 1]), sum(afibs, r - 1));
				int res2 = add(mul(sum(a, r - 1), fibsums2[r - 1]), sum(afibs2, r - 1));
				if (l > 0) {
					res1 = sub(res1, add(mul(sum(a, l - 1), fibsums[l - 1]), sum(afibs, l - 1)));
					res2 = sub(res2, add(mul(sum(a, l - 1), fibsums2[l - 1]), sum(afibs2, l - 1)));
				}
				// 0 1 1 2 3 5 8
				// 1 1 2 3 5 8 13
				// l = 0 -> 0 1
				// l = 1 -> 1 0
				// l = 2 -> -1 1
				// l = 3 -> 2 -1
				// l = 4 -> -3 2
				// l = 5 -> 5 -3
				int res = l == 0 ? res2 : sub(mul(fibs[l - 1], res2), mul(fibs[l], res1));
				if ((l & 1) != 0) {
					res = sub(0, res);
				}
				out.println(res);
			} else if (t == 3) {
				int l = nextInt() - 1;
				int r = nextInt();
				int diff = nextInt();
				int undiff = sub(0, diff);
				incr(a, l, diff);
				incr(a, r, undiff);
				if (l > 0) {
					incr(afibs, l, mul(undiff, fibsums[l - 1]));
					incr(afibs2, l, mul(undiff, fibsums2[l - 1]));
				}
				incr(afibs, r, mul(diff, fibsums[r - 1]));
				incr(afibs2, r, mul(diff, fibsums2[r - 1]));
			} else {
				throw new AssertionError();
			}
		}
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}