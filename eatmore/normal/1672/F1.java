import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F1 {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), pos[] = new int[n + 1], prev[] = new int[n];
			fill(pos, -1);
			for (int i = 0; i < n; i++) {
				int cur = scanInt();
				prev[i] = pos[cur];
				pos[cur] = i;
			}
			int last = -1, posPrev[] = new int[n + 1], b[] = new int[n], left = n;
			for (int i = 0; i <= n; i++) {
				if (pos[i] >= 0) {
					posPrev[i] = last;
					last = i;
				}
			}
			while (left > 0) {
				int newLast = -1, newCur = -1;
				for (int i = last; i >= 0; i = posPrev[i]) {
					b[pos[i]] = posPrev[i] >= 0 ? posPrev[i] : last;
					--left;
					pos[i] = prev[pos[i]];
					if (pos[i] >= 0) {
						if (newLast < 0) {
							newLast = i;
						} else {
							posPrev[newCur] = i;
						}
						newCur = i;
					}
				}
				if (newCur >= 0) {
					posPrev[newCur] = -1;
				}
				last = newLast;
			}
			for (int i = 0; i < n; i++) {
				out.print(b[i] + " ");
			}
			out.println();
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