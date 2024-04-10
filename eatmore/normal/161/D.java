import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static int n, k;
	static List<Integer> edges[];
	static long ans;
	
	static int[] dfs(int cur, int prev) {
		int cans[] = null;
		for (int next: edges[cur]) {
			if (next == prev) {
				continue;
			}
			if (cans == null) {
				cans = dfs(next, cur);
				ans += cans[k - 1];
				for (int i = k - 1; i > 0; i--) {
					cans[i] = cans[i - 1];
				}
				cans[0] = 1;
			} else {
				int cans2[] = dfs(next, cur);
				for (int i = 0; i < k; i++) {
					ans += (long) cans[i] * cans2[k - i - 1];
				}
				for (int i = 0; i < k - 1; i++) {
					cans[i + 1] += cans2[i];
				}
			}
		}
		if (cans == null) {
			cans = new int[k];
			cans[0] = 1;
		}
		return cans;
	}
	
	static void solve() throws Exception {
		n = nextInt();
		k = nextInt();
		edges = (List<Integer>[]) new List<?>[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n - 1; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			edges[a].add(b);
			edges[b].add(a);
		}
		ans = 0;
		dfs(0, -1);
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