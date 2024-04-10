import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class B {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		int n = nextInt();
		int p[] = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt();
		}
		int primes[] = new int[10000];
		pr: for (int i = 0, pr = 2; i < primes.length; pr++) {
			for (int j = 0; j < i && primes[j] * primes[j] <= pr; j++) {
				if (pr % primes[j] == 0) {
					continue pr;
				}
			}
			primes[i++] = pr;
		}
		List<Integer> res[] = new List[primes.length];
		for (int i = 0; i < res.length; i++) {
			res[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < primes.length && primes[j] * primes[j] <= p[i]; j++) {
				if (p[i] % primes[j] == 0) {
					res[j].add(i);
					do {
						p[i] /= primes[j];
					} while (p[i] % primes[j] == 0);
				}
			}
			if (p[i] > 1) {
				res[binarySearch(primes, p[i])].add(i);
			}
		}
		int ans = 1;
		for (int i = 0; i < res.length; i++) {
			ans = max(ans, res[i].size());
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