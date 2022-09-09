import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int n = scanInt();
		long b[] = new long[n];
		for (int i = 0; i < n; i++) {
			b[i] = scanLong();
		}
		long ans[] = new long[n];
		int ansLen = 0;
		long nans[] = new long[n];
		for (int bit = 59; bit >= 0; --bit) {
			int nansLen = 0, p1 = 0, p2 = 0;
			long bv = 1L << bit;
			while (p1 < n && !((b[p1] & bv) != 0 && b[p1] < bv << 1)) {
				++p1;
			}
			while (p1 < n) {
				nans[nansLen++] = b[p1++];
				while (p1 < n && !((b[p1] & bv) != 0 && b[p1] < bv << 1)) {
					++p1;
				}
				if (p1 == n) {
					break;
				}
				while (p2 < ansLen && (ans[p2] & bv) == 0) {
					nans[nansLen++] = ans[p2++];
				}
				if (p2 == ansLen) {
					out.print("No");
					return;
				}
				nans[nansLen++] = ans[p2++];
			}
			while (p2 < ansLen) {
				nans[nansLen++] = ans[p2++];
			}
			long t[] = ans;
			ans = nans;
			nans = t;
			ansLen = nansLen;
		}
		out.println("Yes");
		long cur = 0;
		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
			if (cur >= (cur ^= ans[i])) {
				throw new AssertionError();
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