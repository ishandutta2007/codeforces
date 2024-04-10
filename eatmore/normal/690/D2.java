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

public class D2 {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static final int MOD = 1000003;

	static int sub(int a, int b) {
		int res = a - b;
		if (res < 0) {
			res += MOD;
		}
		return res;
	}

	static int mul(int a, int b) {
		return (int) ((long) a * b % MOD);
	}

	static int inv(int a) {
		return BigInteger.valueOf(a).modInverse(BigInteger.valueOf(MOD)).intValue();
	}

	static void solve() throws Exception {
		int n = nextInt();
		int c = nextInt();
		int num = 1, den = 1;
		for (int i = 0; i < c; i++) {
			num = mul(num, n + i + 1);
			den = mul(den, i + 1);
		}
		out.print(sub(mul(num, inv(den)), 1));
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