import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.round;
import static java.lang.Math.sqrt;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int a = nextInt();
		int n = nextInt();
		int max = a + n - 1;
		List<Integer> primes = new ArrayList<Integer>();
		p: for (int p = 2; p * p <= max; p++) {
			for (int i: primes) {
				if (i * i > p) {
					break;
				}
				if (p % i == 0) {
					continue p;
				}
			}
			primes.add(p);
		}
		int pr[] = new int[primes.size()];
		for (int i = 0; i < pr.length; i++) {
			pr[i] = primes.get(i);
		}
		long ans = 0;
		for (int i = a; i <= max; i++) {
			int ci = i;
			int cans = 1;
			for (int j: pr) {
				if (j * j * j > ci) {
					break;
				}
				boolean odd = false;
				while (ci % j == 0) {
					ci /= j;
					odd = !odd;
				}
				if (odd) {
					cans *= j;
				}
			}
			int root = (int) round(sqrt(ci));
			if (ci != root * root) {
				cans *= ci;
			}
			ans += cans;
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