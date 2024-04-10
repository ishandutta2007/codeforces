import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {
	
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
	
	static int mul(int a, int b) {
		return (int) ((long) a * b % MOD);
	}

	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		sort(a);
		int dyn[][] = new int[n / 2 + 1][k + 1];
		int ndyn[][] = new int[n / 2 + 1][k + 1];
		dyn[0][0] = 1;
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				int diff = a[i] - a[i - 1];
				for (int j = 1; j <= n / 2; j++) {
					int shift = diff * j;
					if (shift > k) {
						fill(dyn[j], 0);
					} else {
						arraycopy(dyn[j], 0, dyn[j], shift, k + 1 - shift);
						fill(dyn[j], 0, shift, 0);
					}
				}
			}
			for (int j = 0; j <= n / 2; j++) {
				for (int j2 = 0; j2 <= k; j2++) {
					int cur = mul(dyn[j][j2], j + 1);
					if (j > 0) {
						cur = add(cur, dyn[j - 1][j2]);
					}
					if (j < n / 2) {
						cur = add(cur, mul(dyn[j + 1][j2], j + 1));
					}
					ndyn[j][j2] = cur;
				}
			}
			int t[][] = dyn;
			dyn = ndyn;
			ndyn = t;
		}
		int ans = 0;
		for (int i = 0; i <= k; i++) {
			ans = add(ans, dyn[0][i]);
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