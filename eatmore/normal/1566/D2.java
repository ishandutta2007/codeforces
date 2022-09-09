import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void sort(int a[], int offset, int n) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[offset + i];
			do {
				int nj = (j - 1) >> 1;
				int na = a[offset + nj];
				if (ca <= na) {
					break;
				}
				a[offset + j] = na;
				j = nj;
			} while (j != 0);
			a[offset + j] = ca;
		}
		int ca = a[offset];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (a[offset + j + 2] > a[offset + j + 1]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[offset + i];
			a[offset + i] = ca;
			ca = na;
			while (j != 0 && a[offset + j] < ca) {
				j = (j - 1) >> 1;
			}
			while (j != 0) {
				na = a[offset + j];
				a[offset + j] = ca;
				ca = na;
				j = (j - 1) >> 1;
			}
		}
		a[offset] = ca;
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

	static int getSum(int fenwick[], int i) {
		int res = fenwick[i];
		while ((i = (i & (i + 1)) - 1) >= 0) {
			res += fenwick[i];
		}
		return res;
	}

	static void updateSum(int fenwick[], int i, int v) {
		fenwick[i] += v;
		while ((i |= i + 1) < fenwick.length) {
			fenwick[i] += v;
		}
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), m = scanInt(), nm = n * m, a[] = new int[nm], idx[] = new int[nm];
			for (int i = 0; i < nm; i++) {
				a[i] = scanInt();
				idx[i] = i;
			}
			sortBy(idx, nm, a);
			for (int i = 0, j; i < nm; i = j) {
				for (j = i + 1; j < nm && a[idx[j]] == a[idx[i]]; j++) { }
				sort(idx, i, j - i);
				for (int k = i, l; k < j; k = l) {
					l = min(k / m * m + m, j);
					for (int ii = k, jj = l - 1; ii < jj; ii++, jj--) {
						int t = idx[ii];
						idx[ii] = idx[jj];
						idx[jj] = t;
					}
				}
			}
			int f[] = new int[nm];
			long ans = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					ans += getSum(f, idx[i * m + j]);
					updateSum(f, idx[i * m + j], 1);
				}
				for (int j = 0; j < m; j++) {
					updateSum(f, idx[i * m + j], -1);
				}
			}
			out.println(ans);
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