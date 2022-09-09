import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + MOD : res;
	}

	static void solve() throws Exception {
		int pows[] = new int[200001];
		pows[0] = 1;
		for (int i = 1; i < pows.length; i++) {
			pows[i] = add(pows[i - 1], pows[i - 1]);
		}
		int n = scanInt();
		int cnt[] = new int[30];
		for (int i = 0; i < n; i++) {
			++cnt[Integer.numberOfTrailingZeros(scanInt())];
		}
		int sum = 0;
		for (int i = 0; i < cnt.length; i++) {
			sum += cnt[i];
		}
		int ans = sub(pows[sum], 1);
		sum -= cnt[0];
		for (int i = 1; i < cnt.length; i++) {
			if (cnt[i] != 0) {
				ans = sub(ans, pows[sum - 1]);
			}
			sum -= cnt[i];
		}
		out.println(ans);
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