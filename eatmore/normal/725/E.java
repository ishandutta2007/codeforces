import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

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
		int c = nextInt();
		int n = nextInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		sort(a);
		int need[] = new int[n + 1];
		int offset[] = new int[n + 1];
		need[n] = c + 1;
		offset[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] > need[i + 1] / 2) {
				need[i] = a[i];
				offset[i] = offset[i + 1];
			} else {
				need[i] = need[i + 1] - a[i];
				offset[i] = offset[i + 1] + a[i];
			}
		}
		boolean can[] = new boolean[c + 1];
		can[offset[0]] = true;
		for (int i = 0; i < n; i++) {
			if (a[i] > need[i + 1] / 2) {
				arraycopy(can, offset[i], can, offset[i] + a[i], need[i + 1] - a[i]);
			} else {
				arraycopy(can, offset[i], can, offset[i + 1], a[i]);
			}
		}
		if (!can[c]) {
			throw new AssertionError();
		}
		int ans = Integer.MAX_VALUE;
		for (int i = n - 1, pos = 0; i >= 0; i--) {
			if (pos + a[i] > c) {
				continue;
			}
			for (int j = pos + 1; j < pos + a[i] && j < c - a[i]; j++) {
				if (!can[j]) {
					ans = min(ans, c - j);
				}
			}
			pos += a[i];
		}
		if (ans == Integer.MAX_VALUE) {
			out.print("Greed is good");
		} else {
			out.print(ans);
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