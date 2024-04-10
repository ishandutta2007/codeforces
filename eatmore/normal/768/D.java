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

public class D {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		int k = nextInt();
		double prob[] = new double[k + 1];
		prob[0] = 1;
		int ans[] = new int[1001];
		int pos = 0;
		for (int i = 0;; i++) {
			for (int j = k - 1; j >= 0; j--) {
				prob[j + 1] += prob[j] * (k - j) / k;
				prob[j] *= (double) j / k;
			}
			while (pos <= 1000 && prob[k] >= (double) pos / 2000 - 5e-11) {
				ans[pos] = i + 1;
				++pos;
			}
			if (pos == 1001) {
				break;
			}
		}
		int q = nextInt();
		for (int i = 0; i < q; i++) {
			out.println(ans[nextInt()]);
		}
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