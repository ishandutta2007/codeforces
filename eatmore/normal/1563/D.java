import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static class LongMinAddTree {

		final int n;
		final long t[], m[];

		LongMinAddTree(int n) {
			this.n = n;
			t = new long[2 * n - 1];
			m = new long[n - 1];
		}

		void init(long v[]) {
			for (int i = 0; i < n; i++) {
				t[n - 1 + i] = v[i];
			}
			for (int i = n - 1; i != 0; i--) {
				t[i - 1] = min(t[(i << 1) - 1], t[i << 1]);
			}
			fill(m, 0);
		}

		void fix(int i) {
			t[i - 1] = m[i - 1] + min(t[(i << 1) - 1], t[i << 1]);
		}

		void push(int i) {
			for (int j = 31 - Integer.numberOfLeadingZeros(i); j != 0; --j) {
				int p = i >> j;
				long v = m[p - 1];
				if (v != 0) {
					if (p << 1 < n) {
						m[(p << 1) - 1] += v;
					}
					t[(p << 1) - 1] += v;
					if ((p << 1) + 1 < n) {
						m[p << 1] += v;
					}
					t[p << 1] += v;
					m[p - 1] = 0;
				}
			}
		}

		long get(int i) {
			long v = t[(i += n) - 1];
			for (i >>= 1; i != 0; i >>= 1) {
				v += m[i - 1];
			}
			return v;
		}

		long getMin(int l, int r) {
			long vl = Long.MAX_VALUE, vr = Long.MAX_VALUE;
			for (l += n, r += n;; l >>>= 1, r >>>= 1) {
				if (vl != Long.MAX_VALUE && l != 1) {
					vl += m[l - 2];
				}
				if (vr != Long.MAX_VALUE) {
					vr += m[r - 1];
				}
				if (l == r && (l & 1) != 0) {
					break;
				}
				if ((l & 1) != 0) {
					vl = min(vl, t[l++ - 1]);
				}
				if ((r & 1) != 0) {
					vr = min(vr, t[--r - 1]);
				}
			}
			long v = min(vl, vr);
			for (l >>>= 1; l != 0; l >>>= 1) {
				v += m[l - 1];
			}
			return v;
		}

		void set(int i, long v) {
			push(i += n);
			t[i - 1] = v;
			while ((i >>= 1) != 0) {
				fix(i);
			}
		}

		void add(int l, int r, long v) {
			if (l == r) {
				return;
			}
			l += n;
			r += n;
			for (int cl = l, cr = r; cl != cr; cl >>>= 1, cr >>>= 1) {
				if ((cl & 1) != 0) {
					if (cl < n) {
						m[cl - 1] += v;
					}
					t[cl++ - 1] += v;
				}
				if ((cr & 1) != 0) {
					if (--cr < n) {
						m[cr - 1] += v;
					}
					t[cr - 1] += v;
				}
			}
			for (int i = Integer.numberOfTrailingZeros(l) + 1; l >>> i != 0; ++i) {
				fix(l >>> i);
			}
			for (int i = Integer.numberOfTrailingZeros(r) + 1; r >>> i != 0; ++i) {
				fix(r >>> i);
			}
		}
	}

	static void sortBy(int a[], int n, int v[]) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			int cv = v[ca];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (cv <= v[na]) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		int ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (v[a[j + 2]] > v[a[j + 1]]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			int cv = v[ca];
			while (j != 0 && v[a[j]] < cv) {
				j = (j - 1) >> 1;
			}
			while (j != 0) {
				na = a[j];
				a[j] = ca;
				ca = na;
				j = (j - 1) >> 1;
			}
		}
		a[0] = ca;
	}

	static final int MOD = 998244353;

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
		int tests = scanInt();
		int facts[] = new int[400010];
		facts[0] = 1;
		for (int i = 1; i < facts.length; i++) {
			facts[i] = mul(facts[i - 1], i);
		}
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), m = scanInt(), x[] = new int[m], y[] = new int[m];
			LongMinAddTree tree = new LongMinAddTree(max(m, 1));
			for (int i = 0; i < m; i++) {
				x[i] = scanInt() - 1;
				y[i] = scanInt() - 1;
				tree.set(i, ((long) y[i] << 32) | (m - i));
			}
			for (int i = 0; i < m; i++) {
				long v = tree.getMin(0, m);
				int j = m - (int) v;
				y[j] = (int) (v >> 32);
				tree.add(0, j, 1L << 32);
				tree.set(j, Long.MAX_VALUE / 2);
			}
			int idx[] = new int[m];
			for (int i = 0; i < m; i++) {
				idx[i] = i;
			}
			sortBy(idx, m, y);
			int invs = 0;
			for (int i = 0, p = 0; i < m; i++) {
				int cx = x[idx[i]], cy = y[idx[i]];
				if (cy > (i == 0 ? 0 : y[idx[i - 1]] + 1)) {
					int px = cy - 1 - i + p;
					while (p < m && px >= x[p]) {
						++p;
						++px;
					}
					if (cx < px) {
						++invs;
					}
				}
				if (cy < n - 1) {
					int nx;
					if (i < m - 1 && y[idx[i + 1]] == cy + 1) {
						nx = x[idx[i + 1]];
					} else {
						nx = cy - i + p;
						while (p < m && nx >= x[p]) {
							++p;
							++nx;
						}
					}
					if (nx < cx) {
						++invs;
					}
				}
			}
			out.println(mul(facts[2 * n - invs - 1], inv(mul(facts[n], facts[n - 1 - invs]))));
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