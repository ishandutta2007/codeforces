import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static int get(int b, int i) {
		return ((b & (1 << i)) != 0 ? b & ((1 << i) - 1) : 0) + ((b & ~((1 << (i + 1)) - 1)) >> 1);
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int l = scanInt(), r = scanInt() + 1;
			int ans = Integer.MAX_VALUE;
			for (int i = 0; i < 18; i++) {
				ans = min(ans, r - l - get(r, i) + get(l, i));
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