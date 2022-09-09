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
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
//		int n = 500;
//		int m = 10000;
		int a[] = new int[m];
		int b[] = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = nextInt() - 1;
			b[i] = nextInt() - 1;
//			a[i] = i % n;
//			b[i] = (i + 1) % n;
		}
		int tmp[] = new int[n];
		for (int i = 0; i < n; i++) {
			tmp[i] = i;
		}
		int connFwd[][] = new int[m + 1][];
		connFwd[0] = tmp.clone();
		for (int i = 0; i < m; i++) {
			connFwd[i + 1] = adjust(connFwd[i], a[i], b[i]);
		}
		int connBkw[][] = new int[m + 1][];
		connBkw[m] = tmp.clone();
		for (int i = m - 1; i >= 0; i--) {
			connBkw[i] = adjust(connBkw[i + 1], a[i], b[i]);
		}
		int tmp2[] = new int[n];
		for (int i = 0; i <= m; i++) {
			if (i == 0 || connFwd[i] != connFwd[i - 1]) {
				fix(connFwd[i], tmp, tmp2);
			}
			if (i == 0 || connBkw[i] != connBkw[i - 1]) {
				fix(connBkw[i], tmp, tmp2);
			}
		}
		int k = nextInt();
//		int k = 20000;
		boolean see[] = new boolean[n];
		for (int i = 0; i < k; i++) {
			int l[] = connFwd[nextInt() - 1];
			int r[] = connBkw[nextInt()];
//			int l[] = connFwd[m];
//			int r[] = connBkw[0];
			fill(see, false);
			int ans = 0;
			for (int j = 0; j < n; j++) {
				if (see[j]) {
					continue;
				}
				++ans;
				dfs(l, r, see, j);
			}
			out.println(ans);
		}
	}
	
	static int[] adjust(int conn[], int a, int b) {
		if (conn[a] == conn[b]) {
			return conn;
		}
		conn = conn.clone();
		int from = conn[b];
		int to = conn[a];
		for (int i = 0; i < conn.length; i++) {
			if (conn[i] == from) {
				conn[i] = to;
			}
		}
		return conn;
	}
	
	static void fix(int conn[], int first[], int prev[]) {
		int n = conn.length;
		fill(first, -1);
		for (int i = 0; i < n; i++) {
			int cur = conn[i];
			if (first[cur] < 0) {
				first[cur] = i;
//				conn[i] = -1;
			} else {
				conn[prev[cur]] = i;
			}
			prev[cur] = i;
		}
		for (int i = 0; i < n; i++) {
			if (first[i] >= 0) {
				conn[prev[i]] = first[i];
			}
		}
	}
	
	static void dfs(int l[], int r[], boolean see[], int cur) {
		if (see[cur]) {
			return;
		}
		see[cur] = true;
		dfs(l, r, see, l[cur]);
		dfs(l, r, see, r[cur]);
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