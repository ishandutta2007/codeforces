import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		long l = nextLong();
		long v1 = nextLong();
		long v2 = nextLong();
		long a[] = new long[2 * n + 1];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}
		for (int i = 0; i < n; i++) {
			a[n + i] = a[i] + 2 * l;
		}
		a[2 * n] = 1L << 32;
		// length = l * v2 / (v1 + v2)
		long pos = 0; // 0 .. 2 * l * (v1 + v2)
		int p1 = 0;
		int p2 = 0;
		while (a[p2] * (v1 + v2) <= /*pos + */l * v2) {
			++p2;
		}
		long ans[] = new long[n + 1];
		while (true) {
			long toGo = min(a[p1] * (v1 + v2) - pos, a[p2] * (v1 + v2) - pos - l * v2);
			toGo = min(toGo, 2 * l * (v1 + v2) - pos);
			ans[p2 - p1] += toGo;
			pos += toGo;
			if (pos >= 2 * l * (v1 + v2)) {
				break;
			}
			while (a[p1] * (v1 + v2) <= pos) {
				++p1;
			}
			while (a[p2] * (v1 + v2) <= pos + l * v2) {
				++p2;
			}
		}
		for (int i = 0; i <= n; i++) {
			out.printf(Locale.US, "%.12f\n", (double) ans[i] / (2 * l * (v1 + v2)));
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