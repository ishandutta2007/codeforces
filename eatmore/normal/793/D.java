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

	static class Edge {
		final int to, length;

		Edge(int to, int length) {
			this.to = to;
			this.length = length;
		}
	}

	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
		int m = nextInt();
		List<Edge> edges[] = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			edges[nextInt() - 1].add(new Edge(nextInt() - 1, nextInt()));
		}
		int dyn[][] = new int[n][n];
		int ndyn[][] = new int[n][n];
		for (int it = 1; it < k; it++) {
			for (int i = 0; i < n; i++) {
				List<Edge> cedges = edges[i];
				for (int j = 0; j < i; j++) {
					int cdyn = Integer.MAX_VALUE;
					for (int ei = 0; ei < cedges.size(); ei++) {
						Edge e = cedges.get(ei);
						int eto = e.to, elen = e.length;
						if (eto < i && eto >= j) {
							int dyn1 = dyn[eto][j];
							if (dyn1 != Integer.MAX_VALUE) {
								cdyn = min(cdyn, dyn1 + elen);
							}
							int dyn2 = dyn[eto][i - 1];
							if (dyn2 != Integer.MAX_VALUE) {
								cdyn = min(cdyn, dyn2 + elen);
							}
						}
					}
					ndyn[i][j] = cdyn;
				}
				ndyn[i][i] = Integer.MAX_VALUE;
				for (int j = i + 1; j < n; j++) {
					int cdyn = Integer.MAX_VALUE;
					for (int ei = 0; ei < cedges.size(); ei++) {
						Edge e = cedges.get(ei);
						int eto = e.to, elen = e.length;
						if (eto > i && eto <= j) {
							int dyn1 = dyn[eto][j];
							if (dyn1 != Integer.MAX_VALUE) {
								cdyn = min(cdyn, dyn1 + elen);
							}
							int dyn2 = dyn[eto][i + 1];
							if (dyn2 != Integer.MAX_VALUE) {
								cdyn = min(cdyn, dyn2 + elen);
							}
						}
					}
					ndyn[i][j] = cdyn;
				}
			}
			int t[][] = dyn;
			dyn = ndyn;
			ndyn = t;
		}
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			ans = min(ans, dyn[i][0]);
			ans = min(ans, dyn[i][n - 1]);
		}
		out.print(ans == Integer.MAX_VALUE ? -1 : ans);
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