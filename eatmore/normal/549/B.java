import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Collections.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		boolean m[][] = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			String l = next();
			for (int j = 0; j < n; j++) {
				m[i][j] = l.charAt(j) == '1';
			}
		}
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		List<Integer> ans = new ArrayList<Integer>();
		w: while (true) {
			for (int i = 0;; i++) {
				if (i >= n) {
					break w;
				}
				if (a[i] == 0) {
					ans.add(i);
					for (int j = 0; j < n; j++) {
						if (m[i][j]) {
							--a[j];
						}
					}
					continue w;
				}
			}
		}
		sort(ans);
		out.println(ans.size());
		for (int i: ans) {
			out.print(i + 1 + " ");
		}
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