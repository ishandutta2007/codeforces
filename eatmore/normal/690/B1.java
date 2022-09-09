import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B1 {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		int n = nextInt();
		int a[][] = new int[n][n];
		int minI = Integer.MAX_VALUE, maxI = Integer.MIN_VALUE, minJ = Integer.MAX_VALUE, maxJ = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			String l = next();
			for (int j = 0; j < n; j++) {
				a[i][j] = l.charAt(j) - '0';
				if (a[i][j] < 0 || a[i][j] > 4) {
					out.print("No");
					return;
				}
				if (a[i][j] == 4) {
					minI = min(minI, i);
					maxI = max(maxI, i);
					minJ = min(minJ, j);
					maxJ = max(maxJ, j);
				}
			}
		}
		if (minI == Integer.MAX_VALUE) {
			out.print("No");
			return;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int want;
				if (i < minI - 1 || i > maxI + 1 || j < minJ - 1 || j > maxJ + 1) {
					want = 0;
				} else {
					int in = 0;
					if (i >= minI && i <= maxI) {
						++in;
					}
					if (j >= minJ && j <= maxJ) {
						++in;
					}
					want = 1 << in;
				}
				if (a[i][j] != want) {
					out.print("No");
					return;
				}
			}
		}
		out.print("Yes");
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