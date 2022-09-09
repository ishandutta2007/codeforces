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

public class B {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int a[][] = new int[m][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[j][i] = nextInt() - 1;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = i; j < m; j++) {
				int t[] = a[i];
				a[i] = a[j];
				a[j] = t;
				for (int k = 0;; k++) {
					if (k >= n) {
						out.print("YES");
						return;
					}
					int cnt = 0;
					for (int l = 0; l < m; l++) {
						if (a[l][k] != l) {
							++cnt;
						}
					}
					if (cnt > 2) {
						break;
					}
				}
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		out.print("NO");
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