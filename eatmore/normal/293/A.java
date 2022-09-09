import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		String s = next();
		String t = next();
		int cnt[] = new int[4];
		for (int i = 0; i < 2 * n; i++) {
			++cnt[((s.charAt(i) - '0') << 1) + (t.charAt(i) - '0')];
		}
		for (int i = 0; i < n; i++) {
			boolean ss;
			if (cnt[3] > 0) {
				--cnt[3];
				ss = true;
			} else if (cnt[2] > 0) {
				--cnt[2];
				ss = true;
			} else if (cnt[1] > 0) {
				--cnt[1];
				ss = false;
			} else {
				--cnt[0];
				ss = false;
			}
			boolean tt;
			if (cnt[3] > 0) {
				--cnt[3];
				tt = true;
			} else if (cnt[1] > 0) {
				--cnt[1];
				tt = true;
			} else if (cnt[2] > 0) {
				--cnt[2];
				tt = false;
			} else {
				--cnt[0];
				tt = false;
			}
			if (ss != tt) {
				out.print(ss ? "First" : "Second");
				return;
			}
		}
		out.print("Draw");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}