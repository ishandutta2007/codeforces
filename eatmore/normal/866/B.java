import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		int n = scanInt();
		long c = scanLong();
		long s[] = new long[n], d[] = new long[n];
		long ans = 0;
		int idx[] = new int[n];
		long ca = 0, cb = 0;
		for (int i = 0; i < n; i++) {
			s[i] = scanLong();
			long a = scanLong();
			long b = scanLong();
			ans += s[i] * a;
			d[i] = b - a;
			idx[i] = i;
			ca += s[i];
		}
		sortBy(idx, d);
		int p;
		for (p = n - 1; p >= 0 && d[idx[p]] > 0; --p) {
			ans += d[idx[p]] * s[idx[p]];
			ca -= s[idx[p]];
			cb += s[idx[p]];
		}
		++p;
		if ((ca + c - 1) / c + (cb + c - 1) / c == (ca + cb + c - 1) / c) {
			out.print(ans);
			return;
		}
		long theAns = Long.MIN_VALUE;
		{
			int cp = p;
			long cans = ans, cca = ca;
			for (--cp; cp >= 0; --cp) {
				long nca = cca - s[idx[cp]];
				long dif;
				if ((nca + c - 1) / c != (cca + c - 1) / c) {
					dif = cca % c;
				} else {
					dif = cca - nca;
				}
				cans += dif * d[idx[cp]];
				cca -= dif;
				if (cca % c == 0) {
					theAns = cans;
					break;
				}
				if (cp == 0) {
					throw new AssertionError();
				}
			}
		}
		{
			int cp = p;
			long cans = ans, ccb = cb;
			for (; cp < n; ++cp) {
				long ncb = ccb - s[idx[cp]];
				long dif;
				if ((ncb + c - 1) / c != (ccb + c - 1) / c) {
					dif = ccb % c;
				} else {
					dif = ccb - ncb;
				}
				cans -= dif * d[idx[cp]];
				ccb -= dif;
				if (ccb % c == 0) {
					theAns = max(theAns, cans);
					break;
				}
				if (cp + 1 == n) {
					throw new AssertionError();
				}
			}
		}
		out.print(theAns);
	}

	static void sortBy(int a[], long v[]) {
		int n = a.length;
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			long cv = v[ca];
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
			long cv = v[ca];
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