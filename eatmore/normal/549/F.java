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
import java.util.StringTokenizer;

public class F {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Query implements Comparable<Query> {
		final int pos, l, r, mod;
		final boolean sub;
		
		public Query(int pos, int l, int r, int mod, boolean sub) {
			this.pos = pos;
			this.l = l;
			this.r = r;
			this.mod = mod;
			this.sub = sub;
		}
		
		public int compareTo(Query o) {
			return pos - o.pos;
		}
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
		int a[] = new int[n];
		int mods[] = new int[n + 1];
		int right[] = new int[n];
		int stack[] = new int[n];
		int stackSize = 0;
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			mods[i + 1] = (mods[i] + a[i]) % k;
			while (stackSize > 0 && a[stack[stackSize - 1]] < a[i]) {
				right[stack[--stackSize]] = i;
			}
			stack[stackSize++] = i;
		}
		while (stackSize > 0) {
			right[stack[--stackSize]] = n;
		}
		int left[] = new int[n];
		for (int i = n - 1; i >= 0; i--) {
			while (stackSize > 0 && a[stack[stackSize - 1]] <= a[i]) {
				left[stack[--stackSize]] = i;
			}
			stack[stackSize++] = i;
		}
		while (stackSize > 0) {
			left[stack[--stackSize]] = -1;
		}
		Query queries[] = new Query[2 * n];
		for (int i = 0; i < n; i++) {
			int lsize = i - left[i];
			int rsize = right[i] - i;
//			System.err.println(i + ": " + (left[i] + 1) + ".." + i + ", " + (i + 1) + ".." + right[i]);
			if (lsize < rsize) {
				queries[2 * i] = new Query(i + 1, left[i] + 1, i, a[i] % k, true);
				queries[2 * i + 1] = new Query(right[i] + 1, left[i] + 1, i, a[i] % k, false);
			} else {
				queries[2 * i] = new Query(left[i] + 1, i + 1, right[i], k - a[i] % k, true);
				queries[2 * i + 1] = new Query(i + 1, i + 1, right[i], k - a[i] % k, false);
			}
		}
		sort(queries);
		long ans = 0;
		int cnts[] = new int[k];
		for (int i = 0, j = 0;; i++) {
			while (j < 2 * n && queries[j].pos == i) {
				Query q = queries[j++];
				long ch = 0;
				for (int ii = q.l; ii <= q.r; ii++) {
					ch += cnts[(q.mod + mods[ii]) % k];
				}
//				System.err.println(q.pos + " " + q.mod + " " + q.l + ".." + q.r + " " + (q.sub ? -ch : ch));
				if (q.sub) {
					ans -= ch;
				} else {
					ans += ch;
				}
			}
			if (i == n + 1) {
				break;
			}
			++cnts[mods[i]];
		}
		out.print(ans - n);
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