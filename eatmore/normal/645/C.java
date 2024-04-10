import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

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
		int n = nextInt();
		int k = nextInt();
		boolean free[] = new boolean[n];
		String l = next();
		for (int i = 0; i < n; i++) {
			free[i] = l.charAt(i) == '0';
		}
		int p1 = 0;
		while (!free[p1]) {
			++p1;
		}
		int p2 = p1;
		for (int i = 0; i < k; i++) {
			for (++p2; !free[p2]; ++p2) { }
		}
		int p3 = (p1 + p2) / 2;
		while (!free[p3]) {
			--p3;
		}
		int p4 = (p1 + p2 + 1) / 2;
		while (!free[p4]) {
			++p4;
		}
		int ans = min(p2 - p3, p4 - p1);
		scan: while (true) {
			do {
				++p2;
				if (p2 >= n) {
					break scan;
				}
			} while (!free[p2]);
			for (++p1; !free[p1]; ++p1) { }
			if (p4 < (p1 + p2 + 1) / 2) {
				p3 = (p1 + p2) / 2;
				while (!free[p3]) {
					--p3;
				}
				p4 = (p1 + p2 + 1) / 2;
				while (!free[p4]) {
					++p4;
				}
			} else if (free[(p1 + p2) / 2]) {
				p3 = (p1 + p2) / 2;
			}
			ans = min(ans, min(p2 - p3, p4 - p1));
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