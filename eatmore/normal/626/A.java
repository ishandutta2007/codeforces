import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		String s = next();
		Map<Long, Integer> cnts = new HashMap<>();
		int cx = 0, cy = 0;
		cnts.put(0L, 1);
		for (int i = 0; i < n; i++) {
			switch (s.charAt(i)) {
			case 'U':
				++cy;
				break;
			case 'D':
				--cy;
				break;
			case 'L':
				++cx;
				break;
			case 'R':
				--cx;
				break;
			default:
				throw new AssertionError();
			}
			Long key = ((long) cx << 32) | (cy & 0xffffffffL);
			Integer val = cnts.get(key);
			cnts.put(key, val == null ? 1 : val + 1);
		}
		long ans = 0;
		for (int v: cnts.values()) {
			ans += ((long) v * (v - 1)) >> 1;
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