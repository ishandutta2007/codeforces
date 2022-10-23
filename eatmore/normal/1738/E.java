import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;

public class E {

	static final int MOD = 998244353;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static int pow(int a, int e) {
		if (e == 0) {
			return 1;
		}
		int r = a;
		for (int i = 30 - Integer.numberOfLeadingZeros(e); i >= 0; i--) {
			r = mul(r, r);
			if ((e & (1 << i)) != 0) {
				r = mul(r, a);
			}
		}
		return r;
	}

	static int inv(int a) {
		return pow(a, MOD - 2);
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt();
			Map<Long, Integer> classes = new HashMap<>();
			long sum = 0;
			for (int i = 0; i < n; i++) {
				sum += scanInt();
				if (i < n - 1) {
					classes.put(sum, classes.getOrDefault(sum, 0) + 1);
				}
			}
			int ansNum = 1, ansDen = 1;
			for (Entry<Long, Integer> e: classes.entrySet()) {
				long csum = e.getKey();
				int cnt = e.getValue();
				if (2 * csum < sum) {
					int cnt2 = classes.getOrDefault(sum - csum, 0);
					int cansNum = 0, cansDen = 1, cnum = 1, cden = 1;
					for (int i = 0;; i++) {
						cansNum = add(mul(cansNum, cden), mul(cansDen, cnum));
						cansDen = mul(cansDen, cden);
						if (i == cnt || i == cnt2) {
							break;
						}
						cnum = mul(cnum, mul(cnt - i, cnt2 - i));
						cden = mul(cden, mul(i + 1, i + 1));
					}
					ansNum = mul(ansNum, cansNum);
					ansDen = mul(ansDen, cansDen);
				} else if (2 * csum == sum) {
					ansNum = mul(ansNum, pow(2, cnt));
				}
			}
			out.println(mul(ansNum, inv(ansDen)));
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