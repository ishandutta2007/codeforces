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

	static void solve() throws Exception {
		int M = 20;
		int n = nextInt();
		String s = next();
//		int n = 75;
//		String s = "000000000000000000000000000000000000000000000000000000000000000000000000000";
//		String s = "111111111111111111111111111111111111111111111111111111111111111111111111111";
		int num[][] = new int[n + 1][];
		int zpos[] = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			num[i] = new int[i];
			fill(num[i], -1);
			for (int j = 0; j < i; j++) {
				try {
					int v = parseInt(s.substring(j, i), 2);
					if (v > 0 && v <= M) {
						num[i][j] = v - 1;
					}
				} catch (NumberFormatException e) { }
			}
			int j;
			for (j = i; j < n && s.charAt(j) == '0'; j++) { }
			zpos[i] = j;
		}
		int dyn[][] = new int[n + 1][1 << M];
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			dyn[i][0] = 1;
			for (int j = zpos[i] + 1; j <= n && num[j][i] >= 0; j++) {
				int v = 1 << num[j][i];
				for (int k = 0; k < 1 << M; k++) {
					dyn[j][k | v] = add(dyn[j][k | v], dyn[i][k]);
				}
			}
			for (int j = 1; j <= M; j++) {
				ans = add(ans, dyn[i][(1 << j) - 1]);
			}
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