import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int tests = scanInt();
		test: for (int test = 0; test < tests; test++) {
			int n = scanInt(), a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = scanInt();
			}
			int sum[] = new int[1 << n];
			for (int i = 1; i < 1 << n; i++) {
				int z = Integer.numberOfTrailingZeros(i);
				sum[i] = sum[i ^ (1 << z)] + a[z];
			}
			sort(sum);
			for (int i = 0; i < (1 << n) - 1; i++) {
				if (sum[i] == sum[i + 1]) {
					out.println("YES");
					continue test;
				}
			}
			out.println("NO");
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}