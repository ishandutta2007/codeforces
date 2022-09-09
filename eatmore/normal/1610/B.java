import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = scanInt();
			}
			int i = 0;
			while (2 * i + 1 < n && a[i] == a[n - i - 1]) {
				++i;
			}
			if (2 * i + 1 >= n) {
				out.println("YES");
				continue;
			}
			int v = a[i];
			boolean good = true;
			for (int p1 = 0, p2 = n - 1; p1 < p2; ++p1, --p2) {
				while (p1 < n && a[p1] == v) {
					++p1;
				}
				while (p2 >= 0 && a[p2] == v) {
					--p2;
				}
				if (p1 >= p2) {
					break;
				}
				if (a[p1] != a[p2]) {
					good = false;
					break;
				}
			}
			if (good) {
				out.println("YES");
				continue;
			}
			v = a[n - i - 1];
			good = true;
			for (int p1 = 0, p2 = n - 1; p1 < p2; ++p1, --p2) {
				while (p1 < n && a[p1] == v) {
					++p1;
				}
				while (p2 >= 0 && a[p2] == v) {
					--p2;
				}
				if (p1 >= p2) {
					break;
				}
				if (a[p1] != a[p2]) {
					good = false;
					break;
				}
			}
			if (good) {
				out.println("YES");
				continue;
			}
			out.println("NO");
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