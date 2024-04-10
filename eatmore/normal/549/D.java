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

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int v[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			String l = next();
			for (int j = 0; j < m; j++) {
				v[i][j] = l.charAt(j) == 'W' ? 1 : -1;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				v[i][j] -= v[i + 1][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++) {
				v[i][j] -= v[i][j + 1];
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] != 0) {
					++ans;
				}
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