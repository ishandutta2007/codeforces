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

public class A2 {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
//		final int maxn = 50;
//		for (int n = 1; n <= maxn; n++) {
//			int ask[] = new int[n];
//			int askSorted[] = new int[n];
//			for (int m = 0;; m++) {
//				for (int cv = 0; cv < n; cv++) {
//					arraycopy(ask, 0, askSorted, 0, cv);
//					sort(askSorted, 0, cv);
//					int s = 0;
//					for (int i = 0; i < cv / 2; i++) {
//						s += askSorted[i];
//					}
//					if (s > m) {
//						ask[cv] = 0;
//					} else {
//						int maxAsk = cv > 1 ? askSorted[cv / 2 - 1] : 0;
//						for (int i = 0; i < cv; i++) {
//							ask[i] = ask[i] > maxAsk ? 1 : ask[i] + 1;
//						}
//						ask[cv] = m - s + 1;
//					}
//				}
//				if (ask[n - 1] > 0) {
//					out.println(n + " " + m);
//					break;
//				}
//			}
//		}
		int n = nextInt();
		int p2 = Integer.highestOneBit(n);
		n = ((n & 1) != 0) ? n >> 1 : (n - p2) >> 1;
		out.print(n);
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