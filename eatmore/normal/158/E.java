import static java.lang.Integer.parseInt;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static int get(int t[], int i) {
		return i >= t.length ? 86401 : t[i];
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
		int t[] = new int[n];
		int d[] = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextInt();
			d[i] = nextInt();
		}
		int ans;
		if (k >= n) {
			ans = 86400;
		} else {
			ans = t[k] - 1;
			int dyn[] = new int[k + 1];
			fill(dyn, 1);
			for (int i = 0; i < n; i++) {
				for (int j = k; j > 0; j--) {
					dyn[j] = min(max(dyn[j], t[i]) + d[i], dyn[j - 1]);
					ans = max(ans, get(t, i + k - j + 1) - dyn[j]);
				}
				dyn[0] = max(dyn[0], t[i]) + d[i];
				ans = max(ans, get(t, i + k + 1) - dyn[0]);
			}
		}
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