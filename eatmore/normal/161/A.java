import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Pair {
		final int a, b;

		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		long x = nextLong();
		long y = nextLong();
		final long a[] = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}
		final long b[] = new long[m];
		for (int i = 0; i < m; i++) {
			b[i] = nextLong();
		}
		Integer idxA[] = new Integer[n];
		for (int i = 0; i < n; i++) {
			idxA[i] = i;
		}
		sort(idxA, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return Long.signum(a[o1] - a[o2]);
			}
		});
		Integer idxB[] = new Integer[m];
		for (int i = 0; i < m; i++) {
			idxB[i] = i;
		}
		sort(idxB, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return Long.signum(b[o1] - b[o2]);
			}
		});
		List<Pair> ans = new ArrayList<Pair>();
		for (int i = 0, j = 0; i < n && j < m; ) {
			if (a[idxA[i]] < b[idxB[j]] - y) {
				++i;
			} else if (b[idxB[j]] < a[idxA[i]] - x) {
				++j;
			} else {
				ans.add(new Pair(idxA[i], idxB[j]));
				++i;
				++j;
			}
		}
		out.println(ans.size());
		for (Pair p: ans) {
			out.println((p.a + 1) + " " + (p.b + 1));
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