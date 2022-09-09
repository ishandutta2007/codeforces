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
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static final int MOD = 1000000007;
	
	static int add(int a, int b) {
		int res = a + b;
		if (res > MOD) {
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
		int ones = 0;
		int twos = 0;
		for (int i = 0; i < n; i++) {
			if (nextInt() == 1) {
				++ones;
			} else {
				++twos;
			}
		}
//		int c[][] = new int[twos + 1][];
//		for (int i = 0; i < c.length; i++) {
//			c[i] = new int[i + 1];
//			c[i][0] = c[i][i] = 1;
//			for (int j = 1; j < i; j++) {
//				c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
//			}
//		}
		int dyn[][] = new int[ones + 1][twos + 1];
		fill(dyn[0], 1);
		for (int i = 1; i <= ones; i++) {
			for (int j = 0; j <= twos; j++) {
				int cans = 0;
				if (i >= 2) {
					for (int k = 0; k <= j; k++) {
						cans = add(cans, mul(k + 1, dyn[i - 2][j - k]));
					}
					cans = mul(cans, i - 1);
				}
				for (int k = 0; k <= j; k++) {
					cans = add(cans, dyn[i - 1][j - k]);
				}
				dyn[i][j] = cans;
			}
		}
		int ans = dyn[ones][twos];
		for (int i = 1; i <= twos; i++) {
			ans = mul(ans, i);
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