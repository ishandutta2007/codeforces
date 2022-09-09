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

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int q = nextInt();
		int a[] = new int[n];
		long asum = 0;
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			asum += a[i];
		}
		int jump[] = new int[n];
		int cnt[] = new int[n];
		int end[] = new int[n];
		for (int qq = 0; qq < q; qq++) {
			long b = nextLong();
			if (asum <= b) {
				out.println(1);
				continue;
			}
			int p1 = 0;
			int p2 = 0;
			long slack = b;
			while (p1 < n) {
				while (slack >= a[p2 % n]) {
					slack -= a[p2 % n];
					++p2;
				}
				jump[p1] = p2;
				slack += a[p1];
				++p1;
			}
			int ans = n;
			for (int i = n - 1; i >= 0; i--) {
				if (jump[i] >= n) {
					cnt[i] = 1;
					end[i] = jump[i] - n;
				} else {
					cnt[i] = cnt[jump[i]] + 1;
					end[i] = end[jump[i]];
				}
				if (end[i] >= i && ans > cnt[i]) {
					ans = cnt[i];
				}
			}
			out.println(ans);
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