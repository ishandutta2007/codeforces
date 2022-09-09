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
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class D {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static class Edge {
		final int to;
		final boolean diff;
		public Edge(int to, boolean diff) {
			this.to = to;
			this.diff = diff;
		}
	}

	static List<Edge> edges[];
	static boolean seen[], state[];

	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		boolean diff[] = new boolean[n];
		for (int i = 0; i < n; i++) {
			diff[i] = nextInt() == 0;
		}
		int swnum[] = new int[n];
		fill(swnum, -1);
		edges = new List[m];
		for (int i = 0; i < m; i++) {
			edges[i] = new ArrayList<>();
			int c = nextInt();
			for (int j = 0; j < c; j++) {
				int cur = nextInt() - 1;
				if (swnum[cur] < 0) {
					swnum[cur] = i;
				} else {
					edges[i].add(new Edge(swnum[cur], diff[cur]));
					edges[swnum[cur]].add(new Edge(i, diff[cur]));
				}
			}
		}
		seen = new boolean[m];
		state = new boolean[m];
		for (int i = 0; i < m; i++) {
			if (!seen[i] && !dfs(i, false)) {
				out.print("NO");
				return;
			}
		}
		out.print("YES");
	}

	static boolean dfs(int cur, boolean cState) {
		if (seen[cur]) {
			return state[cur] == cState;
		}
		seen[cur] = true;
		state[cur] = cState;
		for (Edge e: edges[cur]) {
			if (!dfs(e.to, cState ^ e.diff)) {
				return false;
			}
		}
		return true;
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