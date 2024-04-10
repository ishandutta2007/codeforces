import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static void sort(long a[]) {
		int n = a.length;
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			long ca = a[i];
			do {
				int nj = (j - 1) >> 1;
				long na = a[nj];
				if (ca <= na) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		long ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (a[j + 2] > a[j + 1]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			long na = a[i];
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
		int n = scanInt();
		long l = scanLong();
		long a[] = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = scanLong();
		}
		long b[] = new long[n];
		for (int i = 0; i < n; i++) {
			b[i] = scanLong();
			if (2 * b[i] >= l) {
				b[i] -= l;
			}
		}
		sort(a);
		sort(b);
		int bl = 0, br = n + 1;
		long ans = Long.MAX_VALUE;
		while (bl < br) {
			int mid = (bl + br) >> 1;
			long min = 0, max = 0;
			for (int i = 0; i < n; i++) {
				long s = a[i] - (i + mid >= n ? b[i + mid - n] + l : b[i + mid]);
				min = min(min, s);
				max = max(max, s);
			}
			ans = min(ans, max(max, -min));
			if (max > -min) {
				bl = mid + 1;
			} else {
				br = mid;
			}
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