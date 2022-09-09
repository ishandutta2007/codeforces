import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int a[][] = new int[n][m];
		int b[][] = new int[n][m];
		int c[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			next();
			for (int j = 0; j < m; j++) {
				a[i][j] = nextInt();
				b[i][j] = nextInt();
				c[i][j] = nextInt();
			}
		}
		long ans = 0;
		Integer idx[] = new Integer[m];
		for (int i = 0; i < m; i++) {
			idx[i] = i;
		}
		for (int p1 = 0; p1 < n; p1++) {
			for (int p2 = 0; p2 < n; p2++) {
				final int ca[] = a[p1];
				final int cb[] = b[p2];
				int cc[] = c[p1];
				sort(idx, new Comparator<Integer>() {
					public int compare(Integer o1, Integer o2) {
						return (cb[o2] - ca[o2]) - (cb[o1] - ca[o1]);
					}
				});
				long cans = 0;
				int cs = k;
				for (int i = 0; i < m; i++) {
					int ci = idx[i];
					if (cb[ci] <= ca[ci]) {
						break;
					}
					if (cs > cc[ci]) {
						cans += (long) (cb[ci] - ca[ci]) * cc[ci];
						cs -= cc[ci];
					} else {
						cans += (long) (cb[ci] - ca[ci]) * cs;
						break;
					}
				}
				ans = max(ans, cans);
			}
		}
		out.println(ans);
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