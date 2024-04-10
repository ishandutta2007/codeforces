import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int t[] = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextInt() - 1;
		}
		int ans[] = new int[n];
		int cnts[] = new int[n];
		for (int i = 0; i < n; i++) {
			fill(cnts, 0);
			int maxCnt = 0;
			int maxCntPos = -1;
			for (int j = i; j < n; j++) {
				int cur = t[j];
				if (++cnts[cur] > maxCnt || (cnts[cur] == maxCnt && cur < maxCntPos)) {
					maxCnt = cnts[cur];
					maxCntPos = cur;
				}
				++ans[maxCntPos];
			}
		}
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(ans[i]);
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