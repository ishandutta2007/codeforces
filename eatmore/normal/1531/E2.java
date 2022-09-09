import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static String s;
	static int pos, a[], b[];

	static void solve() throws Exception {
		s = scanString();
		int l = 0, r = s.length() + 1;
		while (l < r) {
			int n = (l + r + 1) >> 1;
			a = new int[n];
			b = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = i;
			}
			pos = 0;
			if (!go(0, n)) {
				r = n - 1;
			} else if (pos != s.length()) {
				l = n;
			} else {
				r = n;
				break;
			}
		}
		int n = r;
		a = new int[n];
		b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = i;
		}
		pos = 0;
		go(0, n);
		for (int i = 0; i < n; i++) {
			b[a[i]] = i;
		}
		out.println(n);
		for (int i = 0; i < n; i++) {
			out.print((b[i] + 1) + " ");
		}
	}

	static boolean go(int l, int r) {
		if (r - l <= 1) {
			return true;
		}
		int m = (l + r) >> 1;
		if (!go(l, m) || !go(m, r)) {
			return false;
		}
		int i = l, j = m, k = l;
		while (i < m && j < r) {
			if (pos == s.length()) {
				return false;
			}
			if (s.charAt(pos++) == '0') {
				b[k++] = a[i++];
			} else {
				b[k++] = a[j++];
			}
		}
		while (i < m) {
			b[k++] = a[i++];
		}
		while (j < r) {
			b[k++] = a[j++];
		}
		arraycopy(b, l, a, l, r - l);
		return true;
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