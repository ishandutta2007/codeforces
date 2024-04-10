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

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void set(int f[], int i, int v) {
		do {
			f[i] = max(f[i], v);
			i |= i + 1;
		} while (i < f.length);
	}
	
	static int get(int f[], int i) {
		int ans = f[i];
		while (true) {
			i = (i & (i + 1)) - 1;
			if (i < 0) {
				break;
			}
			ans = max(ans, f[i]);
		}
		return ans;
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int minSep[] = new int[n];
		int maxSep[] = new int[n];
		int minEnd[] = new int[n];
		for (int i = 0; i < n; i++) {
			minSep[i] = i + 1;
			maxSep[i] = n;
			minEnd[i] = i + 1;
		}
		int m = nextInt();
		for (int i = 0; i < m; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			if ("RIGHT".equals(next())) {
				maxSep[a] = min(maxSep[a], b);
			} else {
				minSep[a] = max(minSep[a], b + 1);
			}
			minEnd[a] = max(minEnd[a], b + 1);
			if (b <= a || maxSep[a] < minSep[a]) {
				out.println("IMPOSSIBLE");
				return;
			}
		}
		int f[] = new int[n];
		for (int i = n - 1; i >= 0; i--) {
			minEnd[i] = max(minEnd[i], get(f, minEnd[i] - 1));
			if (minEnd[i] < get(f, minEnd[i] - 1)) {
				throw new AssertionError();
			}
			minSep[i] = max(minSep[i], get(f, minSep[i] - 1));
			if (minSep[i] < get(f, minSep[i] - 1)) {
				throw new AssertionError();
			}
			if (minSep[i] > maxSep[i]) {
				out.println("IMPOSSIBLE");
				return;
			}
			set(f, i, minEnd[i]);
		}
		go(n, minSep, 0, n);
		out.println();
	}
	
	static void go(int n, int sep[], int cur, int end) {
		if (sep[cur] > cur + 1) {
			go(n, sep, cur + 1, sep[cur]);
			out.print(' ');
		}
		out.print(cur + 1);
		if (end > sep[cur]) {
			out.print(' ');
			go(n, sep, sep[cur], end);
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