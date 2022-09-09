import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int n = scanInt();
		int k = scanInt();
		long c[] = new long[n + 1];
		for (int i = 0; i < n; i++) {
			c[i + 1] = c[i] + scanLong();
		}
		long ans = 0;
		boolean can[] = new boolean[n + 1];
		for (int bit = 55; bit >= 0; bit--) {
			long cans = ans | (1L << bit);
			fill(can, false);
			can[0] = true;
			for (int i = 0; i < k; i++) {
				for (int j = n; j >= 0; j--) {
					boolean v = false;
					for (int jj = 0; jj < j; jj++) {
						if (can[jj] && ((c[j] - c[jj]) & cans) == cans) {
							v = true;
							break;
						}
					}
					can[j] = v;
				}
			}
			if (can[n]) {
				ans = cans;
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