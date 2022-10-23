import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G {

	static void solve() throws Exception {
		int tests = scanInt();
		test: for (int test = 0; test < tests; test++) {
			int n = scanInt(), k = scanInt();
			boolean canDel[][] = new boolean[n][n];
			for (int i = 0; i < n; i++) {
				String l = scanString();
				for (int j = 0; j < n; j++) {
					canDel[i][j] = l.charAt(j) == '1';
				}
			}
			int max[][] = new int[n][n];
			for (int i = n - 1; i >= 0; i--) {
				int cmax = 0;
				for (int j = n - 1; j >= 0; j--) {
					if (!canDel[i][j]) {
						max[i][j] = cmax + 1;
						if (cmax + 1 >= k) {
							out.println("NO");
							continue test;
						}
					} else if (i < n - 1) {
						max[i][j] = max[i + 1][j];
					}
					if (i < n - 1) {
						cmax = max(cmax, max[i + 1][j]);
					}
				}
			}
			out.println("YES");
			int max2[][] = new int[n][n];
			int mm[] = new int[n];
			for (int i = 0; i < n; i++) {
				if (i < n - 1) {
					for (int j = n - 2; j >= 0; j--) {
						mm[j] = max(mm[j + 1], max[i + 1][j + 1]);
					}
				} else {
					fill(mm, 0);
				}
				int cmax = 0;
				for (int j = 0; j < n; j++) {
					if (cmax + mm[j] + 1 >= k) {
						if (!canDel[i][j]) {
							throw new AssertionError();
						}
						out.print('0');
						if (i > 0) {
							max2[i][j] = max2[i - 1][j];
						}
					} else {
						out.print('1');
						max2[i][j] = cmax + 1;
					}
					if (i > 0) {
						cmax = max(cmax, max2[i - 1][j]);
					}
				}
				out.println();
			}
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}