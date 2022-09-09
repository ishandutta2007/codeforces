import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static long solve(int a[], int b[]) {
		long bsum = 0;
		for (int i: b) {
			bsum += i;
		}
		long ans = 0;
		boolean haveBig = false;
		int max = Integer.MIN_VALUE;
		for (int i: a) {
			if (i >= bsum) {
				ans += bsum;
				haveBig = true;
			} else {
				ans += i;
				max = max(max, i);
			}
		}
		if (!haveBig) {
			ans += bsum - max;
		}
		return ans;
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int b[] = new int[m];
		for (int i = 0; i < m; i++) {
			b[i] = nextInt();
		}
		out.print(min(solve(a, b), solve(b, a)));
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