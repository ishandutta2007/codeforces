import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.math.BigInteger.ONE;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		String s = next();
		BigInteger ans = ONE;
		boolean have[] = new boolean[10];
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			int mul;
			if (c == '?') {
				mul = i == 0 ? 9 : 10;
			} else if ('0' <= c && c <= '9') {
				mul = 1;
			} else if ('A' <= c && c <= 'J') {
				if (have[c - 'A']) {
					mul = 1;
				} else {
					have[c - 'A'] = true;
					mul = i == 0 ? 9 : 10 - cnt;
					++cnt;
				}
			} else {
				throw new AssertionError();
			}
			ans = ans.multiply(BigInteger.valueOf(mul));
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