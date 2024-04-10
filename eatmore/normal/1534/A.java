import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), m = scanInt();
			boolean even = true, odd = true;
			for (int i = 0; i < n; i++) {
				String l = scanString();
				for (int j = 0; j < m; j++) {
					char c = l.charAt(j);
					if (c != '.') {
						if ((c == 'R') ^ (((i ^ j) & 1) != 0)) {
							odd = false;
						} else {
							even = false;
						}
					}
				}
			}
			if (!odd && !even) {
				out.println("NO");
			} else {
				out.println("YES");
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						out.print(even ^ (((i ^ j) & 1) != 0) ? 'R' : 'W');
					}
					out.println();
				}
			}
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