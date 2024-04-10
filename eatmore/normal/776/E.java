import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static final int primes[] = new int[80000];
	static {
		primes[0] = 2;
		primes[1] = 3;
		long bitset[] = new long[20000];
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

	static final int MOD = 1000000007;

	static void solve() throws Exception {
		long n = nextLong();
		long k = (nextLong() + 1) / 2;
		for (long i = 0; i < k && n != 1; i++) {
			long nn = 1, cp;
			for (int j = 0; (cp = primes[j]) * cp <= n; j++) {
				if (n % cp == 0) {
					n /= cp;
					nn *= cp - 1;
					while (n % cp == 0) {
						n /= cp;
						nn *= cp;
					}
				}
			}
			if (n > 1) {
				nn *= n - 1;
			}
			n = nn;
		}
		out.print(n % MOD);
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