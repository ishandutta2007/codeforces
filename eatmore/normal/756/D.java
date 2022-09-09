import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

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

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		if (res >= MOD) {
			res -= MOD;
		}
		return res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		if (res < 0) {
			res += MOD;
		}
		return res;
	}

	static void solve() throws Exception {
		int n = nextInt();
		char s[] = next().toCharArray();
		int pos[] = new int[26];
		fill(pos, -1);
		int ppos[] = new int[n];
		for (int i = 0; i < n; i++) {
			ppos[i] = pos[s[i] - 'a'];
			pos[s[i] - 'a'] = i;
		}
		int vals[] = new int[n];
		int sums[] = new int[n + 1];
		vals[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sums[j + 1] = add(sums[j], vals[j]);
			}
			for (int j = 0; j < n; j++) {
				vals[j] = sub(sums[j + 1], sums[ppos[j] + 1]);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = add(ans, vals[i]);
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