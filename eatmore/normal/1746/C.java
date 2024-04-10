import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static class IntSumTree {

		final int t[];

		IntSumTree(int n) {
			t = new int[n];
		}

		void init() {
			int n = t.length;
			for (int i = 0; i < n; i++) {
				t[i] = 1;
			}
			for (int i = 0, j; i < n; i++) {
				if ((j = i | (i + 1)) < n) {
					t[j] += t[i];
				}
			}
		}

		int get(int i) {
			int res = t[i];
			for (int j = 1; (i & j) != 0; j <<= 1) {
				res -= t[i ^ j];
			}
			return res;
		}

		int getPrefixSum(int i) {
			int res = 0;
			for (; i > 0; i &= i - 1) {
				res += t[i - 1];
			}
			return res;
		}

		int getSum(int l, int r) {
			return getPrefixSum(r) - getPrefixSum(l);
		}

		int scanNZ(int i) {
			int n = t.length, s = 1;
			scan: {
				while (i + s <= n) {
					if ((i & s) != 0) {
						do {
							i += s;
							int v = t[i - 1];
							int t = s;
							do {
								v -= this.t[(i - 1) ^ t];
							} while (((i - 1) & (t <<= 1)) != 0);
							if (v != 0) {
								break scan;
							}
							s = t;
						} while (i + s <= n);
						break;
					}
					s <<= 1;
				}
				while ((s >>= 1) != 0) {
					if (i + s <= n) {
						i += s;
						if (t[i - 1] != 0) {
							break scan;
						}
					}
				}
				return n;
			}
			--i;
			while ((s >>= 1) != 0) {
				if (t[i ^ s] != 0) {
					i ^= s;
				}
			}
			return i;
		}

		int rscanNZ(int i) {
			for (; i > 0; i &= i - 1) {
				int v = t[i - 1];
				if (v != 0) {
					--i;
					int j;
					for (j = 1; (i & j) != 0; j <<= 1) { }
					while ((j >>= 1) != 0) {
						int w = t[i ^ j];
						if (w == v) {
							i ^= j;
						} else {
							v -= w;
						}
					}
					return i;
				}
			}
			return -1;
		}

		void add(int i, int v) {
			int n = t.length;
			do {
				t[i] += v;
			} while ((i |= i + 1) < n);
		}

		void set(int i, int v) {
			add(i, v - get(i));
		}
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = scanInt();
			}
			IntSumTree tree = new IntSumTree(n);
			tree.init();
			int x[] = new int[n];
			for (int i = n - 2; i >= 0; i--) {
				if (a[i + 1] < a[i]) {
					int p = tree.scanNZ(a[i] - a[i + 1] - 1);
					x[p] = i + 1;
					tree.add(p, -1);
				}
			}
			for (int i = 0; i < n; i++) {
				out.print((x[i] + 1) + " ");
			}
			out.println();
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