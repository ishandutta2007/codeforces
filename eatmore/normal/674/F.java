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

public class F {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int p = nextInt();
		int q = nextInt();
		if (p >= n) {
			p = n - 1;
		}
		int c[] = new int[p + 1];
		c[0] = 1;
		for (int i = 1, val = 1, pow = 0; i <= p; i++) {
			int mul = n - i + 1;
			int shift = Integer.numberOfTrailingZeros(mul);
			val *= mul >> shift;
			pow += shift;
			mul = i;
			shift = Integer.numberOfTrailingZeros(mul);
			val *= BigInteger.valueOf(mul >> shift).modInverse(BigInteger.valueOf(0x100000000L)).intValue();
			pow -= shift;
			c[i] = pow >= 32 ? 0 : val << pow;
		}
		int ans = 0;
		for (int day = 1; day <= q; day++) {
			int cans = 0;
			for (int i = 0, pow = 1; i <= p; i++, pow *= day) {
				cans += c[i] * pow;
			}
			ans ^= day * cans;
		}
		out.print(ans & 0xffffffffL);
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