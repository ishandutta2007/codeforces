import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

	static class Tree {

		final int n;
		final int t[];

		Tree(int n) {
			this.n = n;
			t = new int[2 * n - 1];
		}

		static int f(int a, int b) {
			return ff(a, b) | (ff(a >> 16, b) << 16);
		}

		static int ff(int a, int b) {
			if ((a & 1) != 0) {
				b >>= 16;
			}
			b &= 0xffff;
			if ((b & 0xfffe) == 0) {
				b ^= (a ^ b) & 0xfffe;
			}
			return b;
		}

		void fix(int i) {
			t[i - 1] = f(t[(i << 1) - 1], t[i << 1]);
		}

		int get2(int l, int r) {
			int vl = 0x10000, vr = 0x10000;
			for (l += n, r += n; l != r; l >>>= 1, r >>>= 1) {
				if ((l & 1) != 0) {
					vl = f(vl, t[l++ - 1]);
				}
				if ((r & 1) != 0) {
					vr = f(t[--r - 1], vr);
				}
			}
			return f(vl, vr);
		}

		void set(int i, int v) {
			t[(i += n) - 1] = v;
			for (i >>= 1; i != 0; i >>= 1) {
				fix(i);
			}
		}
	}

	static final String COLORS[] = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};
	static {
		sort(COLORS);
	}

	static int val() throws IOException {
		String cmd = scanString();
		switch (cmd) {
		case "lock":
			return 0x10001;
		case "unlock":
			return 0;
		default:
			int p = Arrays.binarySearch(COLORS, cmd);
			if (p < 0) {
				throw new AssertionError();
			}
			return 0x10000 | ((p + 1) << 1);
		}
	}

	static void solve() throws Exception {
		int n = scanInt();
		Tree tree = new Tree(n);
		for (int i = 0; i < n; i++) {
			tree.t[n - 1 + i] = val();
		}
		for (int i = n - 1; i != 0; i--) {
			tree.fix(i);
		}
		int t = scanInt();
		int init = (Arrays.binarySearch(COLORS, "blue") + 1) << 1;
		for (int qq = 0;; qq++) {
			out.println(COLORS[((Tree.f(init, tree.get2(0, n)) & 0xfffe) >> 1) - 1]);
			if (qq == t) {
				break;
			}
			tree.set(scanInt() - 1, val());
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