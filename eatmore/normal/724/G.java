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

public class G {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		if (res >= MOD) {
			res -= MOD;
		}
		return res;
	}

	static int mul(int a, int b) {
		return (int) ((long) a * b % MOD);
	}

	static class Edge {
		final int to;
		final long num;

		public Edge(int to, long num) {
			this.to = to;
			this.num = num;
		}
	}

	static List<Edge> edges[];
	static long p[];
	static long matrix[];
	static int cnt, cnts[];

	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			long num = nextLong();
			edges[a].add(new Edge(b, num));
			edges[b].add(new Edge(a, num));
		}
		p = new long[n];
		fill(p, -1);
		matrix = new long[60];
		cnts = new int[60];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] >= 0) {
				continue;
			}
			fill(matrix, 0);
			cnt = 0;
			fill(cnts, 0);
			dfs(i, 0);
			int msize = 0;
			long mbits = 0;
			for (int j = 0; j < 60; j++) {
				if (matrix[j] != 0) {
					++msize;
					mbits |= matrix[j];
				}
			}
			int mul1 = (int) ((1L << msize) % MOD);
			int mul2 = (int) ((1L << (msize - 1)) % MOD);
			int cans = 0;
			for (int j = 59; j >= 0; j--) {
				cans = add(cans, cans);
				if ((mbits & (1L << j)) != 0) {
					cans = add(cans, mul(mul2, (int) ((long) cnt * (cnt - 1) / 2 % MOD)));
				} else {
					cans = add(cans, mul(mul1, mul(cnts[j], cnt - cnts[j])));
				}
			}
			ans = add(ans, cans);
		}
		out.print(ans);
	}

	static void dfs(int cur, long cp) {
		if (p[cur] < 0) {
			p[cur] = cp;
			++cnt;
			for (int i = 0; i < 60; i++) {
				if ((cp & (1L << i)) != 0) {
					++cnts[i];
				}
			}
			for (Edge e: edges[cur]) {
				dfs(e.to, cp ^ e.num);
			}
		} else {
			long dif = p[cur] ^ cp;
			if (dif != 0) {
				for (int i = 59; i >= 0; i--) {
					if ((dif & (1L << i)) != 0) {
						if (matrix[i] != 0) {
							dif ^= matrix[i];
						} else {
							matrix[i] = dif;
							break;
						}
					}
				}
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