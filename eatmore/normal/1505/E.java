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
		int n = scanInt(), m = scanInt();
		String map[] = new String[n];
		for (int i = 0; i < n; i++) {
			map[i] = scanString();
		}
		int ans = 0;
		int i = 0, j = 0;
		while (true) {
			if (map[i].charAt(j) == '*') {
				++ans;
			}
			if (i == n - 1 && j == m - 1) {
				break;
			} else if (i == n - 1) {
				++j;
			} else if (j == m - 1) {
				++i;
			} else {
				for (int d = 1;; d++) {
					if (j + d >= m || map[i].charAt(j + d) == '*') {
						++j;
						break;
					} else if (i + d >= n || map[i + d].charAt(j) == '*') {
						++i;
						break;
					}
				}
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