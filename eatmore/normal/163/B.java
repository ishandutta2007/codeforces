import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
		long h = nextLong();
		final long m[] = new long[n];
		for (int i = 0; i < n; i++) {
			m[i] = nextLong();
		}
		final long v[] = new long[n];
		long maxv = 0;
		for (int i = 0; i < n; i++) {
			v[i] = nextLong();
			maxv = max(maxv, v[i]);
		}
		Integer idx[] = new Integer[n];
		for (int i = 0; i < n; i++) {
			idx[i] = i;
		}
		sort(idx, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				if (m[o1] != m[o2]) {
					return Long.signum(m[o1] - m[o2]);
				}
				return Long.signum(v[o1] - v[o2]);
			}
		});
		double l = 0;
		double r = n * h + 1;
		bin: while (l < r) {
			double mid = (l + r) / 2;
			if (mid <= l || mid >= r) {
				break;
			}
			for (int i = 0, j = 1; i < n; i++) {
				long speed = v[idx[i]];
				long height = j * h;
				// height / speed > mid
				if (height > mid * speed) {
					continue;
				}
				++j;
				if (j > k) {
					r = mid;
					continue bin;
				}
			}
			l = mid;
		}
//		System.err.println(l + " " + r);
		for (int i = 0, j = 1; ; i++) {
			long speed = v[idx[i]];
			long height = j * h;
			// height / speed > r
			if (height > r * speed) {
				continue;
			}
			if (j > 1) {
				out.print(' ');
			}
			out.print(idx[i] + 1);
			++j;
			if (j > k) {
				break;
			}
		}
		out.println();
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