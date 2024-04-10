import static java.lang.Integer.parseInt;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int t[] = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextInt();
		}
		int ans = Integer.MIN_VALUE;
		for (int cnt = 3; cnt <= n; cnt++) {
			if (n % cnt != 0) {
				continue;
			}
			for (int start = 0; start < n / cnt; start++) {
				int cur = 0;
				for (int pos = start; pos < n; pos += n / cnt) {
					cur += t[pos];
				}
				ans = max(ans, cur);
			}
		}
		out.println(ans);
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
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