import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		int n = nextInt();
		long a1[] = new long[n];
		long b1[] = new long[n];
		long a2[] = new long[n];
		long b2[] = new long[n];
		for (int i = 0; i < n; i++) {
			a1[i] = nextLong();
			b1[i] = nextLong();
			a2[i] = nextLong();
			b2[i] = nextLong();
		}
		long greed[] = new long[2 * n];
		int greedCnt = 0;
		long ans = 0;
		for (int i = 0; i < n; i++) {
			if (a1[i] + b1[i] >= a2[i] + b2[i]) {
				greed[greedCnt++] = a1[i] + b1[i];
				greed[greedCnt++] = a2[i] + b2[i];
				ans -= b1[i] + b2[i];
			} else if (a1[i] > b2[i]) {
				ans += a1[i] - b2[i];
			} else if (b1[i] > a2[i]) {
				ans -= b1[i] - a2[i];
			}
		}
		sort(greed, 0, greedCnt);
		for (int i = 0; i < greedCnt; i++) {
			if (((i ^ greedCnt) & 1) != 0) {
				ans += greed[i];
			}
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