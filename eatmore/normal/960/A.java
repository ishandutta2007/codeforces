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
		String s = scanString();
		int a = 0, b = 0, c = 0, i = 0;
		while (i < s.length() && s.charAt(i) == 'a') {
			++i;
			++a;
		}
		while (i < s.length() && s.charAt(i) == 'b') {
			++i;
			++b;
		}
		while (i < s.length() && s.charAt(i) == 'c') {
			++i;
			++c;
		}
		out.print(i == s.length() && a > 0 && b > 0 && (c == a || c == b) ? "YES" : "NO");
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