import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int n = scanInt();
		long depth = 0, ans = 0, mvals[] = new long[n];
		int mcnt = 0, mcnts[] = new int[n];
		for (int i = 0; i < n; i++) {
			int c = scanInt();
			if ((i & 1) == 0) {
				depth += c;
			} else {
				ans += min(depth, c);
				depth -= c;
				while (mcnt > 0 && mvals[mcnt - 1] > depth) {
					ans += mcnts[mcnt - 1];
					--mcnt;
				}
				if (mcnt > 0 && mvals[mcnt - 1] == depth) {
					ans += mcnts[mcnt - 1];
					++mcnts[mcnt - 1];
				} else if (depth < 0) {
					depth = 0;
				} else {
					mvals[mcnt] = depth;
					mcnts[mcnt] = 1;
					++mcnt;
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