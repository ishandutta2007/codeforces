import static java.lang.Integer.parseInt;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int cnt[] = new int[4];
		for (int i = 0; i < n; i++) {
			cnt[nextInt() - 1]++;
		}
		int ans = cnt[3];
		int add = min(cnt[0], cnt[2]);
		ans += add;
		cnt[0] -= add;
		cnt[2] -= add;
		ans += cnt[2];
		add = cnt[1] / 2;
		ans += add;
		cnt[1] -= 2 * add;
		ans += (cnt[0] + 2 * cnt[1] + 3) / 4;
		out.print(ans);
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