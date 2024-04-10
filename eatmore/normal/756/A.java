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

	static void solve() throws Exception {
		int n = nextInt();
		int p[] = new int[n];
		boolean flip = false;
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}
		for (int i = 0; i < n; i++) {
			if (nextInt() == 1) {
				flip = !flip;
			}
		}
		int cyc = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] >= 0) {
				++cyc;
				for (int j = i, k; j >= 0; j = k) {
					k = p[j];
					p[j] = -1;
				}
			}
		}
		out.print((cyc > 1 ? cyc : 0) + (flip ? 0 : 1));
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