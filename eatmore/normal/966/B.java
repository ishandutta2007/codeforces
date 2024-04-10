import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void sortBy(int a[], int v[]) {
		int n = a.length;
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

	static int n, pow[], idx[];

	static void solve() throws Exception {
		n = scanInt();
		int x1 = scanInt();
		int x2 = scanInt();
		pow = new int[n];
		idx = new int[n];
		for (int i = 0; i < n; i++) {
			pow[i] = scanInt();
			idx[i] = i;
		}
		sortBy(idx, pow);
		if (solve(x1, x2)) {
			output(false, retK1, retK2);
		} else if (solve(x2, x1)) {
			output(true, retK2, retK1);
		} else {
			out.print("No");
		}
	}

	static int retK1, retK2;

	static boolean solve(int x1, int x2) {
		retK1 = 1;
		while (pow[idx[n - retK1]] < (x1 + retK1 - 1) / retK1) {
			if (retK1 == n) {
				return false;
			}
			++retK1;
		}
		if (retK1 == n) {
			return false;
		}
		retK2 = 1;
		while (pow[idx[n - retK1 - retK2]] < (x2 + retK2 - 1) / retK2) {
			if (retK1 + retK2 == n) {
				return false;
			}
			++retK2;
		}
		return true;
	}

	static void output(boolean swap, int k1, int k2) {
		out.println("Yes");
		out.println(k1 + " " + k2);
		int off = swap ? k2 : 0;
		for (int i = 0; i < k1; i++) {
			out.print((idx[n - off - i - 1] + 1) + " ");
		}
		out.println();
		off = swap ? 0 : k1;
		for (int i = 0; i < k2; i++) {
			out.print((idx[n - off - i - 1] + 1) + " ");
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