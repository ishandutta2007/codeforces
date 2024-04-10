import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		int n = nextInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int p[] = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}
		int next[] = new int[n];
		int prev[] = new int[n];
		long maxSum[] = new long[n + 1];
		long maxPref[] = new long[n + 1];
		long maxSuf[] = new long[n + 1];
		long sum[] = new long[n + 1];
		for (int i = 0; i < n; i++) {
			prev[i] = i - 1;
			next[i] = i + 1;
		}
		long ans[] = new long[n];
		for (int i = n - 1; i > 0; i--) {
			int cur = p[i];
			int pre = prev[cur];
			long cMaxSum = maxSum[cur + 1], pMaxSum = maxSum[pre + 1];
			long cMaxPref = maxPref[cur + 1], pMaxPref = maxPref[pre + 1];
			long cMaxSuf = maxSuf[cur + 1], pMaxSuf = maxSuf[pre + 1];
			long cSum = sum[cur + 1], pSum = sum[pre + 1];
			maxSum[pre + 1] = max(max(cMaxSum, pMaxSum), cMaxPref + pMaxSuf + a[cur]);
			maxPref[pre + 1] = max(pMaxPref, pSum + a[cur] + cMaxPref);
			maxSuf[pre + 1] = max(cMaxSuf, cSum + a[cur] + pMaxSuf);
			sum[pre + 1] = cSum + pSum + a[cur];
			ans[i - 1] = max(ans[i], maxSum[pre + 1]);
			if (pre >= 0) {
				next[pre] = next[cur];
			}
			if (next[cur] < n) {
				prev[next[cur]] = pre;
			}
		}
		for (int i = 0; i < n; i++) {
			out.println(ans[i]);
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