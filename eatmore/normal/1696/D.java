import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static class IntMinTree {

		final int n;
		final int t[];

		IntMinTree(int n) {
			if (n == 0) {
				n = 1;
			}
			this.n = n;
			t = new int[2 * n - 1];
		}

		void init(int v[]) {
			if (v.length != 0) {
				arraycopy(v, 0, t, n - 1, n);
			}
			for (int i = n - 1; i != 0; i--) {
				t[i - 1] = min(t[(i << 1) - 1], t[i << 1]);
			}
		}

		int get(int i) {
			return t[i + n - 1];
		}

		int getMin(int l, int r) {
			int v = Integer.MAX_VALUE;
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

		int scanLE(int l, int r, int v) {
			int i;
			scan: {
				for (l += n, r += n, i = 0; l != r >>> i; l >>>= 1, ++i) {
					if ((l & 1) != 0) {
						if (t[l - 1] <= v) {
							break scan;
						}
						++l;
					}
				}
				while (i != 0) {
					int j = r >>> --i;
					if ((j & 1) != 0 && t[j - 2] <= v) {
						l = j - 1;
						break scan;
					}
				}
				return r - n;
			}
			for (; i != 0; --i) {
				if (t[(l <<= 1) - 1] > v) {
					++l;
				}
			}
			return l - n;
		}

		int rscanLE(int l, int r, int v) {
			int i;
			scan: {
				for (l += n - 1, r += n, i = 0; r != (l >>> i) + 1; r >>>= 1, ++i) {
					if ((r & 1) != 0 && t[--r - 1] <= v) {
						break scan;
					}
				}
				while (i != 0) {
					int j = l >>> --i;
					if ((j & 1) == 0 && t[j] <= v) {
						r = j + 1;
						break scan;
					}
				}
				return l - n;
			}
			for (; i != 0; --i) {
				if (t[r <<= 1] <= v) {
					++r;
				}
			}
			return r - n;
		}

		void set(int i, int v) {
			t[(i += n) - 1] = v;
			while ((i >>= 1) != 0) {
				t[i - 1] = min(t[(i << 1) - 1], t[i << 1]);
			}
		}
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), a[] = new int[n];
			int stack1[] = new int[n], stack2[] = new int[n];
			IntMinTree tree1 = new IntMinTree(n), tree2 = new IntMinTree(n);
			int size1 = 0, size2 = 0, ans = 0;
			for (int i = 0; i < n; i++) {
				a[i] = scanInt();
				if (i != 0) {
					while (size1 != 0 && a[stack1[size1 - 1]] < a[i]) {
						--size1;
					}
					while (size2 != 0 && a[stack2[size2 - 1]] > a[i]) {
						--size2;
					}
					if (a[i - 1] > a[i]) {
						int l = size2 == 0 ? 0 : stack2[size2 - 1] + 1;
						int p = binarySearch(stack1, 0, size1, l);
						if (p < 0) {
							p = ~p;
						}
						ans = tree1.getMin(p, size1) + 1;
					} else {
						int l = size1 == 0 ? 0 : stack1[size1 - 1] + 1;
						int p = binarySearch(stack2, 0, size2, l);
						if (p < 0) {
							p = ~p;
						}
						ans = tree2.getMin(p, size2) + 1;
					}
				}
				stack1[size1] = i;
				tree1.set(size1++, ans);
				stack2[size2] = i;
				tree2.set(size2++, ans);
			}
			out.println(ans);
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