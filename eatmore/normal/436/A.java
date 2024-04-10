import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
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
		int x = nextInt();
		int t[] = new int[n];
		int h[] = new int[n];
		int m[] = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextInt();
			h[i] = nextInt();
			m[i] = nextInt();
		}
		int ans = 0;
		for (int st = 0; st < 2; st++) {
			boolean used[] = new boolean[n];
			int ct = st;
			int ch = x;
			int cans = 0;
			while (true) {
				int ci = -1;
				for (int i = 0; i < n; i++) {
					if (!used[i] && t[i] == ct && h[i] <= ch && (ci < 0 || m[ci] < m[i])) {
						ci = i;
					}
				}
				if (ci < 0) {
					break;
				}
				++cans;
				used[ci] = true;
				ch += m[ci];
				ct = 1 - ct;
			}
			ans = max(ans, cans);
		}
		out.print(ans);
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