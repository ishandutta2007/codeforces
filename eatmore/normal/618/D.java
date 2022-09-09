import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
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
	
	static long x, y;
	static List<Integer> edges[];
	
	static void solve() throws Exception {
		int n = nextInt();
		x = nextLong();
		y = nextLong();
		edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 1; i < n; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			edges[a].add(b);
			edges[b].add(a);
		}
		if (x < y) {
			int paths = dfs(0, -1);
			out.print(y * (paths - 1) + x * (n - paths));
		} else {
			for (int i = 0; i < n; i++) {
				if (edges[i].size() == n - 1) {
					out.print(x + y * (n - 2));
					return;
				}
			}
			out.print(y * (n - 1));
		}
	}
	
	static int resConnected;
	static int dfs(int cur, int prev) {
		int sum = 0;
		int minInc = Integer.MAX_VALUE;
		int minInc2 = Integer.MAX_VALUE;
		for (int next: edges[cur]) {
			if (next == prev) {
				continue;
			}
			int res1 = dfs(next, cur);
			int res2 = resConnected - res1;
			sum += res1;
			if (res2 < minInc) {
				minInc2 = minInc;
				minInc = res2;
			} else if (res2 < minInc2) {
				minInc2 = res2;
			}
		}
		int res1 = sum + 1;
		int res2 = sum + 1;
		if (minInc != Integer.MAX_VALUE) {
			res1 = min(res1, sum + minInc);
			res2 = min(res1, sum + minInc);
			if (minInc2 != Integer.MAX_VALUE) {
				res1 = min(res1, sum + minInc + minInc2 - 1);
			}
		}
		resConnected = res2;
		return res1;
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