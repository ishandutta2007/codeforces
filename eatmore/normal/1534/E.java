import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void solve() throws Exception {
		int n = scanInt(), k = scanInt();
		if (n % 2 != 0 && k % 2 == 0) {
			out.println(-1);
			return;
		}
		int d = 1;
		while (k * d < n || d < 1 + 2 * ((k * d + n - 1) / (2 * n)) || (k * d + n) % 2 != 0) {
			++d;
		}
		int maxcnt = 1 + 2 * ((k * d + n - 1) / (2 * n));
		int fullcnt = 1 + 2 * ((k * d - n) / (2 * n));
		int vals[] = new int[maxcnt];
		for (int i = 0; i < fullcnt; i++) {
			vals[i] = n;
		}
		if (fullcnt < maxcnt) {
			int p = (k * d - fullcnt * n) / 2;
			vals[fullcnt] = p;
			vals[fullcnt + 1] = p;
		}
		int ans = 0;
		for (int i = 0; i < d; i++) {
			out.print('?');
			int left = k;
			int prev = 0;
			j: for (int j = maxcnt - 1; j >= 0; j--) {
				int cur = vals[j];
				while (vals[j] > prev) {
					out.print(" " + vals[j]);
					--vals[j];
					if (--left == 0) {
						break j;
					}
				}
				prev = cur;
			}
			out.println();
			out.flush();
			ans ^= scanInt();
		}
		out.println("! " + ans);
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