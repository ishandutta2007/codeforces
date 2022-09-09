import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void add(long f[], int i, long v) {
		do {
			f[i] += v;
			i |= i + 1;
		} while (i < f.length);
	}
	
	static long sum(long f[], int i) {
		long v = 0;
		do {
			v += f[i];
			i = (i & (i + 1)) - 1;
		} while (i >= 0);
		return v;
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		long a[] = new long[n];
		long f[] = new long[n];
		Map<Long, Integer> lasts = new HashMap<>();
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			lasts.put(a[i], i);
			if (a[i] > 0) {
				add(f, i, a[i]);
			}
		}
		long ans = Long.MIN_VALUE;
		int ansFirst = -1;
		int ansLast = -1;
		for (int first = 0; first < n; first++) {
			int last = lasts.get(a[first]);
			if (last <= first) {
				continue;
			}
			long test = a[first] * 2 + sum(f, last - 1) - sum(f, first);
			if (test > ans) {
				ans = test;
				ansFirst = first;
				ansLast = last;
			}
		}
		boolean cut[] = new boolean[n];
		int nCut = 0;
		for (int i = 0; i < n; i++) {
			cut[i] = i < ansFirst || i > ansLast || (i > ansFirst && i < ansLast && a[i] <= 0);
			if (cut[i]) {
				++nCut;
			}
		}
		out.println(ans + " " + nCut);
		for (int i = 0; i < n; i++) {
			if (cut[i]) {
				out.print(i + 1 + " ");
			}
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