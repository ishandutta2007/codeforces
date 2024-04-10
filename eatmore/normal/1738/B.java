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
			int n = scanInt(), k = scanInt();
			int s[] = new int[k];
			for (int i = 0; i < k; i++) {
				s[i] = scanInt();
			}
			if (k > 1) {
				for (int i = 0; i < k - 2; i++) {
					if (s[i + 2] + s[i] < 2 * s[i + 1]) {
						out.println("No");
						continue test;
					}
				}
				if ((long) (s[1] - s[0]) * (n - k + 1) < s[0]) {
					out.println("No");
					continue;
				}
			}
			out.println("Yes");
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