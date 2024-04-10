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
		test: for (int test = 0; test < tests; test++) {
			int n = scanInt();
			int r[] = new int[5 * n];
			for (int i = 0; i < 5 * n; i++) {
				r[i] = scanInt();
			}
			int cur = 0;
			for (int i = 1; i < n; i++) {
				int c = 0;
				for (int j = 0; j < 5; j++) {
					if (r[5 * cur + j] < r[5 * i + j]) {
						++c;
					}
				}
				if (c < 3) {
					cur = i;
				}
			}
			for (int i = 0; i < n; i++) {
				if (i == cur) {
					continue;
				}
				int c = 0;
				for (int j = 0; j < 5; j++) {
					if (r[5 * cur + j] < r[5 * i + j]) {
						++c;
					}
				}
				if (c < 3) {
					out.println(-1);
					continue test;
				}
			}
			out.println(cur + 1);
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