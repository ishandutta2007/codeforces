import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		String s = next();
		long ans = -1;
		for (int i = 1; i < s.length() && i <= 7; i++) {
			for (int j = i + 1; j < s.length() && j <= i + 7; j++) {
				if (s.length() - j > 7) {
					continue;
				}
				String s1 = s.substring(0, i);
				String s2 = s.substring(i, j);
				String s3 = s.substring(j, s.length());
				ans = max(ans, parse(s1) + parse(s2) + parse(s3));
			}
		}
		out.println(ans);
	}
	
	static long parse(String s) {
		if ("0".equals(s)) {
			return 0;
		}
		if (s.length() < 1 || s.length() > 7 || s.charAt(0) == '0') {
			return Integer.MIN_VALUE;
		}
		long n = parseInt(s);
		if (n > 1000000) {
			return Integer.MIN_VALUE;
		}
		return n;
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