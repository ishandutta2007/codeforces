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

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int r[] = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = nextInt();
		}
		List<Integer> edges[] = (List<Integer>[]) new List<?>[n];
		List<Integer> redges[] = (List<Integer>[]) new List<?>[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<Integer>();
			redges[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < m; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			edges[a].add(b);
			redges[b].add(a);
		}
		boolean good1[] = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (r[i] == 1) {
				dfs1(edges, good1, i);
			}
		}
		boolean good2[] = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (r[i] == 2) {
				dfs2(redges, r, good2, i);
			}
		}
		for (int i = 0; i < n; i++) {
			out.println(good1[i] && good2[i] ? 1 : 0);
		}
	}
	
	static void dfs1(List<Integer> edges[], boolean seen[], int cur) {
		if (seen[cur]) {
			return;
		}
		seen[cur] = true;
		for (int next: edges[cur]) {
			dfs1(edges, seen, next);
		}
	}

	static void dfs2(List<Integer> edges[], int r[], boolean seen[], int cur) {
		if (seen[cur]) {
			return;
		}
		seen[cur] = true;
		if (r[cur] == 1) {
			return;
		}
		for (int next: edges[cur]) {
			dfs2(edges, r, seen, next);
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