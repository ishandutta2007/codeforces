import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static int DIJ[] = {0, 1, 0, -1, 0};

	static void solve() throws Exception {
		int n = scanInt();
		int m = scanInt();
		char map[][] = new char[n][];
		int si = -1, sj = -1;
		for (int i = 0; i < n; i++) {
			map[i] = scanString().toCharArray();
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 'S') {
					si = i;
					sj = j;
				}
			}
		}
		String cmd = scanString();
		int ans = 0;
		int perm[] = {0, 1, 2, 3};
		perm: while (true) {
			int i = si, j = sj;
			for (int k = 0; k < cmd.length(); k++) {
				int d = perm[cmd.charAt(k) - '0'];
				i += DIJ[d];
				j += DIJ[d + 1];
				if (i < 0 || i >= n || j < 0 || j >= m || map[i][j] == '#') {
					break;
				}
				if (map[i][j] == 'E') {
					++ans;
					break;
				}
			}
			for (i = 2;; i--) {
				if (i < 0) {
					break perm;
				}
				if (perm[i] < perm[i + 1]) {
					for (j = 3; j > i + 1; j--) {
						if (perm[j] > perm[i]) {
							break;
						}
					}
					int t = perm[i];
					perm[i] = perm[j];
					perm[j] = t;
					sort(perm, i + 1, 4);
					break;
				}
			}
		}
		out.print(ans);
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