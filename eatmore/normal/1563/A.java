import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
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
			int a = scanInt(), b = scanInt(), c = (a + b) / 2;
			if ((a + b) % 2 == 0) {
				int min = a + b - min(a, c) - min(b, c);
				int max = min(a, c) + min(b, c);
				out.println((max - min) / 2 + 1);
				for (int i = min; i <= max; i += 2) {
					out.print(i + " ");
				}
				out.println();
			} else {
				int min = a + b - min(a, c + 1) - min(b, c + 1);
				int max = min(a, c + 1) + min(b, c + 1);
				out.println(max - min + 1);
				for (int i = min; i <= max; i++) {
					out.print(i + " ");
				}
				out.println();
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