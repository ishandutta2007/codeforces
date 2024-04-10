import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G {

	static void solve() throws Exception {
		int n = scanInt();
		String aa = scanString();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = aa.charAt(i) - '0';
		}
		int m = n;
		for (int p = 2; p <= m; p++) {
			if (m % p != 0) {
				continue;
			}
			int pk = 1;
			do {
				m /= p;
				pk *= p;
			} while (m % p == 0);
			int s = n / p;
			for (int i = 0; i < s; i++) {
				int x = i;
				for (int j = i; j < n; j += s) {
					if (j % pk < x % pk) {
						x = j;
					}
				}
				int v = a[x];
				for (int j = i; j < n; j += s) {
					a[j] -= v;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[i] != 0) {
				out.print("NO");
				return;
			}
		}
		out.print("YES");
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