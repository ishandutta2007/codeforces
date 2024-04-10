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

public class C {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static List<Integer> edges[];
	static boolean seen[];

	static void solve() throws Exception {
		int n = nextInt();
		edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			int p = nextInt() - 1;
			edges[i].add(p);
			edges[p].add(i);
		}
		seen = new boolean[n];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!seen[i]) {
				dfs(i);
				++ans;
			}
		}
		out.print(ans);
	}

	static void dfs(int cur) {
		seen[cur] = true;
		for (int next: edges[cur]) {
			if (!seen[next]) {
				dfs(next);
			}
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