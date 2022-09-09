import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt();
			String s1 = scanString(), s2 = scanString();
			int ans = 0;
			boolean have0 = false, have1 = false;
			for (int i = 0; i < n; i++) {
				char c1 = s1.charAt(i), c2 = s2.charAt(i);
				if (c1 == '0' && c2 == '0') {
					if (have1) {
						ans += 2;
						have1 = false;
					} else {
						++ans;
						have0 = true;
					}
				} else if (c1 == '1' && c2 == '1') {
					if (have0) {
						++ans;
						have0 = false;
					} else {
						have1 = true;
					}
				} else {
					ans += 2;
					have0 = have1 = false;
				}
			}
			out.println(ans);
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