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
		for (int test = 0; test < tests; test++) {
			int n = scanInt();
			for (int i = 0; i < n; i++) {
				scanInt();
			}
			out.println(3 * n);
			for (int i = 0; i < n; i += 2) {
				out.println("1 " + (i + 1) + " " + (i + 2));
				out.println("2 " + (i + 1) + " " + (i + 2));
				out.println("2 " + (i + 1) + " " + (i + 2));
				out.println("1 " + (i + 1) + " " + (i + 2));
				out.println("2 " + (i + 1) + " " + (i + 2));
				out.println("2 " + (i + 1) + " " + (i + 2));
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