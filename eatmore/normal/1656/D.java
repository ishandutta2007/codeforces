import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static class Fast {
		static final int primes[] = new int[10000];
		static {
			primes[0] = 2;
			primes[1] = 3;
			long bitset[] = new long[600];
			for (int i = 2, p = 1, dp = 4; i < primes.length; i++) {
				do {
					p += dp;
					dp = 6 - dp;
				} while ((bitset[(p / 3) >> 6] & (1L << (p / 3))) != 0);
				primes[i] = p;
				if (p <= 46340) {
					for (int q = p * p, dq = dp * p, l = 6 * p, j;
						(j = q / 3) >> 6 < bitset.length; q += dq, dq = l - dq) {
						bitset[j >> 6] |= 1L << j;
					}
				}
			}
		}
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			long n = scanLong();
			int p2 = Long.numberOfTrailingZeros(n);
			if (p2 <= 30 && n >= (1L << (2 * p2 + 1)) + (1L << p2)) {
				out.println(1L << (p2 + 1));
				continue;
			}
			long x = n >> p2;
			if (x > 1 && x < Integer.MAX_VALUE && 2 * n >= x * (x + 1)) {
				out.println(x);
				continue;
			}
			int pp = 0;
			for (int p: Fast.primes) {
				if (x % p == 0) {
					pp = p;
					break;
				}
			}
			if (pp >= 3 && 2 * n >= (long) pp * (pp + 1)) {
				out.println(pp);
				break;
			}
			out.println(-1);
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