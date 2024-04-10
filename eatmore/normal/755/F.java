import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void sort(int a[], int n) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (ca <= na) {
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
				j += (a[j + 2] > a[j + 1]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			while (j != 0 && a[j] < ca) {
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

	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
		int p[] = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}
		int cyc[] = new int[n];
		int nCyc = 0;
		boolean seen[] = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (seen[i]) {
				continue;
			}
			for (int j = i; !seen[j]; j = p[j]) {
				seen[j] = true;
				++cyc[nCyc];
			}
			++nCyc;
		}
		sort(cyc, nCyc);
		{
			int ck = min(k, n - k);
			boolean can[] = new boolean[ck + 1];
			can[0] = true;
			int max = 0;
			for (int i = 0, j; i < nCyc; i = j) {
				int v = cyc[i];
				if (v > ck) {
					break;
				}
				for (j = i + 1; j < nCyc && cyc[j] == v; j++) { }
				int c = j - i;
				max = min(max + c * v, ck);
				for (int ii = max - v + 1; ii <= max; ii++) {
					int cnt = 0, jj, kk, lim = max(ii - c * v, 0);
					for (jj = ii - v; jj >= lim; jj -= v) {
						if (can[jj]) {
							++cnt;
						}
					}
					for (kk = ii;;) {
						if (cnt > 0) {
							can[kk] = true;
						}
						if ((kk -= v) < 0) {
							break;
						}
						if (can[kk]) {
							--cnt;
						}
						if (jj >= 0) {
							if (can[jj]) {
								++cnt;
							}
							jj -= v;
						}
					}
				}
				if (can[ck]) {
					break;
				}
			}
			out.print(can[ck] ? k : k + 1);
		}
		int a2 = 0;
		for (int i = 0; i < nCyc; i++) {
			if (k <= cyc[i] / 2) {
				a2 += 2 * k;
				k = 0;
			} else {
				a2 += cyc[i] / 2 * 2;
				k -= cyc[i] / 2;
			}
		}
		for (int i = 0; i < nCyc; i++) {
			if (k > 0 && cyc[i] % 2 == 1) {
				++a2;
				--k;
			}
		}
		out.print(" " + a2);
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