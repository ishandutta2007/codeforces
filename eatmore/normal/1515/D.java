import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), l = scanInt();
			scanInt();
			int cl[] = new int[n], cr[] = new int[n];
			for (int i = 0; i < l; i++) {
				++cl[scanInt() - 1];
			}
			for (int i = l; i < n; i++) {
				++cr[scanInt() - 1];
			}
			int ans = 0;
			int sl = l, sr = n - l;
			for (int i = 0; i < n; i++) {
				int c = min(cl[i], cr[i]);
				sl -= c;
				sr -= c;
				if (cl[i] > cr[i] && sl > sr) {
					c = min(cl[i] - cr[i], sl - sr) / 2;
					sl -= 2 * c;
					ans += c;
				} else if (cr[i] > cl[i] && sr > sl) {
					c = min(cr[i] - cl[i], sr - sl) / 2;
					sr -= 2 * c;
					ans += c;
				}
			}
			ans += max(sl, sr);
			out.println(ans);
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