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

public class F {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
//	static final Random rng = new Random(42);
	
	static void solve() throws Exception {
		int n = nextInt();
//		int n = rng.nextInt(100) + 1;
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
//			a[i] = rng.nextInt();
		}
		int ans[] = new int[n - 1];
		for (int i = 1; i < n; i++) {
			for (int k = 1; k < n;) {
				int p = (i - 1) / k;
				int maxk = p == 0 ? n - 1 : (i - 1) / p;
				if (a[i] < a[p]) {
					++ans[k - 1];
					if (maxk < ans.length) {
						--ans[maxk];
					}
				}
				k = maxk + 1;
			}
		}
//		// DEBUG
//		int cans = 0;
//		for (int k = 1; k < n; k++) {
//			cans += ans[k - 1];
//			int dans = 0;
//			for (int i = 1; i < n; i++) {
//				int p = (i - 1) / k;
//				if (a[i] < a[p]) {
//					++dans;
//				}
//			}
//			if (cans != dans) {
//				throw new AssertionError();
//			}
//		}
//		System.err.println("PASS");
		int cans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(cans += ans[i]);
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