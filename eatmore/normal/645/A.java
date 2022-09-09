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

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static boolean get() throws Exception {
		char chars[] = new char[3];
		int cnt = 0;
		for (int i = 0; i < 2; i++) {
			String l = next();
			for (int j = 0; j < 2; j++) {
				char c = l.charAt(i == 0 ? j : 1 - j);
				if (c >= 'A' && c <= 'C') {
					chars[cnt++] = c;
				}
			}
		}
		if (cnt != 3) {
			throw new AssertionError();
		}
		for (int it = 0; it < 3; it++) {
			if (chars[0] == 'A' && chars[1] == 'B' && chars[2] == 'C') {
				return false;
			}
			if (chars[0] == 'A' && chars[1] == 'C' && chars[2] == 'B') {
				return true;
			}
			char c = chars[0];
			chars[0] = chars[1];
			chars[1] = chars[2];
			chars[2] = c;
		}
		throw new AssertionError();
	}
	
	static void solve() throws Exception {
		out.print(get() == get() ? "YES" : "NO");
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