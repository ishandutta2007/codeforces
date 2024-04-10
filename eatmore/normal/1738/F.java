import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

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

	static int dsuGet(int dsu[], int i) {
		return dsu[i] == i ? i : (dsu[i] = dsuGet(dsu, dsu[i]));
	}

	static boolean dsuMerge(int dsu[], int i, int j) {
		i = dsuGet(dsu, i);
		j = dsuGet(dsu, j);
		if (i == j) {
			return false;
		}
		dsu[j] = i;
		return true;
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), d[] = new int[n];
			for (int i = 0; i < n; i++) {
				d[i] = scanInt();
			}
			int idx[] = new int[n];
			for (int i = 0; i < n; i++) {
				idx[i] = i;
			}
			sortBy(idx, n, d);
			boolean used[] = new boolean[n];
			int dsu[] = new int[n];
			for (int i = 0; i < n; i++) {
				dsu[i] = i;
			}
			for (int i = n - 1; i >= 0; i--) {
				int ii = idx[i];
				if (used[ii]) {
					continue;
				}
				used[ii] = true;
				for (int j = 0; j < d[ii]; j++) {
					out.println("? " + (ii + 1));
					out.flush();
					int jj = scanInt() - 1;
					dsuMerge(dsu, ii, jj);
					if (!used[jj]) {
						used[jj] = true;
					} else {
						break;
					}
				}
			}
			out.print('!');
			for (int i = 0; i < n; i++) {
				out.print(" " + (dsuGet(dsu, i) + 1));
			}
			out.println();
			out.flush();
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