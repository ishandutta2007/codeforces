import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		long n = nextLong();
		if (n % 3 != 0) {
			out.print(0);
			return;
		}
		n /= 3;
		long divisors[] = new long[4096];
		int divCnt = 0;
		for (int i = 1; (long) i * i <= n; i++) {
			if (n % i != 0) {
				continue;
			}
			if (divCnt + 1 >= divisors.length) {
				divisors = copyOf(divisors, divisors.length << 1);
			}
			divisors[divCnt++] = i;
			if ((long) i * i < n) {
				divisors[divCnt++] = n / i;
			}
		}
		sort(divisors, 0, divCnt);
		int ans = 0;
		for (int i = 0; i < divCnt; i++) {
			long dI = divisors[i];
			long qI = n / dI;
			for (int j = i; j < divCnt; j++) {
				long dJ = divisors[j];
				if (qI % dJ != 0) {
					continue;
				}
				long qJ = qI / dJ;
				if (qJ < dJ) {
					break;
				}
				long sum = dI + dJ + qJ;
				if ((sum & 1) != 0) {
					continue;
				}
				sum >>= 1;
				long a = sum - dI;
				long b = sum - dJ;
				long c = sum - qJ;
				if ((a | b | c) < 0 || a == 0 || b == 0 || c == 0) {
					continue;
				}
				if (a == b) {
					if (b == c) {
						++ans;
					} else {
						ans += 3;
					}
				} else {
					if (b == c) {
						ans += 3;
					} else {
						ans += 6;
					}
				}
			}
		}
		out.print(ans);
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