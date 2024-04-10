import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

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
		int n = scanInt(), k = scanInt();
		out.println("and 1 2");
		out.flush();
		int and12 = scanInt();
		out.println("or 1 2");
		out.flush();
		int or12 = scanInt();
		out.println("and 2 3");
		out.flush();
		int and23 = scanInt();
		out.println("or 2 3");
		out.flush();
		int or23 = scanInt();
		out.println("and 1 3");
		out.flush();
		int and13 = scanInt();
		out.println("or 1 3");
		out.flush();
		int or13 = scanInt();
		int a[] = new int[n];
		a[0] = and12 | and13 | (or12 & ~or23);
		a[1] = and12 | and23 | (or12 & ~or13);
		a[2] = and23 | and13 | (or13 & ~or12);
		for (int i = 3; i < n; i++) {
			out.println("and 1 " + (i + 1));
			out.flush();
			int and1i = scanInt();
			out.println("or 1 " + (i + 1));
			out.flush();
			int or1i = scanInt();
			a[i] = and1i ^ or1i ^ a[0];
		}
		sort(a, n);
		out.println("finish " + a[k - 1]);
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