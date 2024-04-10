import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int m[] = new int[n];
		int d[] = new int[n];
		int lcm = 1;
		for (int i = 0; i < n; i++) {
			m[i] = nextInt();
			lcm = lcm * (m[i] / gcd(lcm, m[i]));
		}
		for (int i = 0; i < n; i++) {
			d[i] = nextInt();
		}
		int me = 0;
		i: for (int i = 0; i < lcm; i++) {
			for (int j = 0; j < n; j++) {
				if (i % m[j] == d[j]) {
					++me;
					continue i;
				}
			}
		}
		out.printf(Locale.US, "%.9f", (double) me / lcm);
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