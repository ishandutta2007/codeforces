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
	
	static List<Integer> edges[];
	static boolean seen[];
	static int exit[];
	static int exitCnt;
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		int u[] = new int[m];
		int v[] = new int[m];
		for (int i = 0; i < m; i++) {
			u[i] = nextInt() - 1;
			v[i] = nextInt() - 1;
			edges[u[i]].add(v[i]);
		}
		seen = new boolean[n];
		exit = new int[n];
		exitCnt = 0;
		for (int i = 0; i < n; i++) {
			dfs(i);
		}
		int next[] = new int[n];
		fill(next, -1);
		for (int i = 0; i < n - 1; i++) {
			next[exit[i + 1]] = exit[i];
		}
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			if (v[i] == next[u[i]] && ++cnt == n - 1) {
				out.print(i + 1);
				return;
			}
		}
		out.print(-1);
	}
	
	static void dfs(int cur) {
		if (seen[cur]) {
			return;
		}
		seen[cur] = true;
		for (int next: edges[cur]) {
			dfs(next);
		}
		exit[exitCnt++] = cur;
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