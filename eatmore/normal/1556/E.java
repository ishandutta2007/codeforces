import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static class LongMaxTree {

		final int n;
		final long t[];

		LongMaxTree(int n) {
			this.n = n;
			t = new long[2 * n - 1];
		}

		long get(int i) {
			return t[i + n - 1];
		}

		long getMax(int l, int r) {
			long v = Long.MIN_VALUE;
			for (l += n, r += n; l != r; l >>>= 1, r >>>= 1) {
				if ((l & 1) != 0) {
					v = max(v, t[l++ - 1]);
				}
				if ((r & 1) != 0) {
					v = max(v, t[--r - 1]);
				}
			}
			return v;
		}

		void set(int i, long v) {
			t[(i += n) - 1] = v;
			for (i >>= 1; i != 0; i >>= 1) {
				t[i - 1] = max(t[(i << 1) - 1], t[i << 1]);
			}
		}
	}

	static class LongMinTree {

		final int n;
		final long t[];

		LongMinTree(int n) {
			this.n = n;
			t = new long[2 * n - 1];
		}

		long get(int i) {
			return t[i + n - 1];
		}

		long getMin(int l, int r) {
			long v = Long.MAX_VALUE;
			for (l += n, r += n; l != r; l >>>= 1, r >>>= 1) {
				if ((l & 1) != 0) {
					v = min(v, t[l++ - 1]);
				}
				if ((r & 1) != 0) {
					v = min(v, t[--r - 1]);
				}
			}
			return v;
		}

		void set(int i, long v) {
			t[(i += n) - 1] = v;
			for (i >>= 1; i != 0; i >>= 1) {
				t[i - 1] = min(t[(i << 1) - 1], t[i << 1]);
			}
		}
	}

	static void solve() throws Exception {
		int n = scanInt(), q = scanInt();
		LongMinTree minTree = new LongMinTree(n + 1);
		LongMaxTree maxTree = new LongMaxTree(n + 1);
		for (int i = 0; i < n; i++) {
			minTree.t[n + i] = -scanInt();
		}
		for (int i = 0; i < n; i++) {
			minTree.t[n + i] += scanInt();
		}
		long sum = 0;
		for (int i = 0; i < n; i++) {
			long v = minTree.t[n + i];
			minTree.t[n + i] = sum;
			sum += v;
		}
		minTree.t[n + n] = sum;
		arraycopy(minTree.t, n, maxTree.t, n, n + 1);
		for (int i = n; i != 0; i--) {
			minTree.t[i - 1] = min(minTree.t[(i << 1) - 1], minTree.t[i << 1]);
			maxTree.t[i - 1] = max(maxTree.t[(i << 1) - 1], maxTree.t[i << 1]);
		}
		for (int qq = 0; qq < q; qq++) {
			int l = scanInt() - 1, r = scanInt();
			long s = minTree.get(l);
			out.println(minTree.get(r) != s || minTree.getMin(l, r + 1) != s ? -1 : maxTree.getMax(l, r + 1) - s);
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}