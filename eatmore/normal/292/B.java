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

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		List<Integer> edges[] = (List<Integer>[]) new List<?>[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		int m = nextInt();
		for (int i = 0; i < m; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			edges[a].add(b);
			edges[b].add(a);
		}
		star: {
			int c = -1;
			for (int i = 0; i < n; i++) {
				if (edges[i].size() == n - 1) {
					if (c < 0) {
						c = i;
					} else {
						break star;
					}
				} else if (edges[i].size() != 1) {
					break star;
				}
			}
			for (int i = 0; i < n; i++) {
				if (i != c && edges[i].get(0) != c) {
					break star;
				}
			}
			out.print("star topology");
			return;
		}
		ring: {
			for (int i = 0; i < n; i++) {
				if (edges[i].size() != 2) {
					break ring;
				}
			}
			for (int i = 0, cur = 0, prev = -1; i < n; i++) {
				int next = edges[cur].get(0) == prev ? edges[cur].get(1) : edges[cur].get(0);
				if ((next == 0) != (i == n - 1)) {
					break ring;
				}
				prev = cur;
				cur = next;
			}
			out.print("ring topology");
			return;
		}
		bus: {
			int e1 = -1, e2 = -1;
			for (int i = 0; i < n; i++) {
				if (edges[i].size() == 1) {
					if (e1 < 0) {
						e1 = i;
					} else if (e2 < 0) {
						e2 = i;
					} else {
						break bus;
					}
				} else if (edges[i].size() != 2) {
					break bus;
				}
			}
			if (e1 < 0 || e2 < 0) {
				break bus;
			}
			for (int i = 0, cur = e1, prev = -1; i < n - 1; i++) {
				int next = edges[cur].get(0) == prev ? edges[cur].get(1) : edges[cur].get(0);
				if ((next == e2) != (i == n - 2)) {
					break bus;
				}
				prev = cur;
				cur = next;
			}
			out.print("bus topology");
			return;
		}
		out.print("unknown topology");
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