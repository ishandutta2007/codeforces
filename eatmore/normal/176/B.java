import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static final int MOD = 1000000007;
	
	static class Number {
		final int num, den;

		Number(int num, int den) {
			if (num < 0) {
				num += MOD;
			}
			this.num = num;
			this.den = den;
		}

		Number(int num) {
			num = num % MOD;
			if (num < 0) {
				num += MOD;
			}
			this.num = num;
			den = 1;
		}
		
		Number add(Number b) {
			return new Number((int) (((long) num * b.den + (long) den * b.num) % MOD),
				(int) (((long) den * b.den) % MOD));
		}
		
		Number mul(int b) {
			return new Number((int) (((long) num * b) % MOD), den);
		}
		
		Number neg() {
			return new Number((MOD - num) % MOD, den);
		}
		
		Number div(Number b) {
			return new Number((int) (((long) num * b.den) % MOD), (int) (((long) den * b.num) % MOD));
		}
		
		Number div(int b) {
			return new Number(num, (int) (((long) den * b) % MOD));
		}
		
		int intValue() {
			return (int) ((num *
				BigInteger.valueOf(den).modInverse(BigInteger.valueOf(MOD)).longValue()) % MOD);
		}
	}
	
	static void solve() throws Exception {
		String s1 = next();
		String s2 = next();
		int n = s1.length();
		int k = nextInt();
		Number mul = new Number(k % 2 == 0 ? -k : k);
		Number cur = new Number(0);
		for (int i = 1; i <= k; i++) {
			mul = mul.div(i);
//			System.err.println(mul.intValue());
			cur = cur.add(mul);
			mul = mul.mul(-n * (k - i));
		}
		int curi = cur.intValue();
		int ans = 0;
		i: for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (s1.charAt(j) != s2.charAt((i + j) % n)) {
					continue i;
				}
			}
			ans = (ans + curi) % MOD;
			if (i == 0) {
				ans = (ans + (k % 2 == 0 ? 1 : MOD - 1)) % MOD;
			}
		}
		ans %= MOD;
		if (ans < 0) {
			ans += MOD;
		}
		out.println(ans);
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