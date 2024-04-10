import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C2 {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static List<Integer> edges[];
	static int ans;

	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		if (m != n - 1) {
			out.print("no");
			return;
		}
		edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			edges[a].add(b);
			edges[b].add(a);
		}
		ans = 0;
		dfs(0, -1);
		out.print(ans);
	}

	static int dfs(int cur, int prev) {
		int depth = 0;
		for (int next: edges[cur]) {
			if (next == prev) {
				continue;
			}
			int depth2 = 1 + dfs(next, cur);
			ans = max(ans, depth + depth2);
			depth = max(depth, depth2);
		}
		return depth;
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