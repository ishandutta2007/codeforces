import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.sqrt;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static long get(long a) {
		long s = (long) sqrt(a);
		while (s * s > a) {
			--s;
		}
		while ((s + 1) * (s + 1) <= a) {
			++s;
		}
		return 3 * s - (s * s + s > a ? 2 : s * s + 2 * s > a ? 1 : 0);
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			out.println(-get(scanLong() - 1) + get(scanLong()));
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