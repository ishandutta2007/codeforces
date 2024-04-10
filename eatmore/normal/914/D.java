import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static int n, tree[][];

	static void treeComb(int a[], int b[], int r[]) {
		int a0 = a[0], b0 = b[0];
		r[0] = gcd(a0, b0);
		int p = 1;
		for (int i = 1, ai; (ai = a[i]) >= 0; i++) {
			r[p++] = gcd(ai, b0);
		}
		for (int i = 1, bi; (bi = b[i]) >= 0; i++) {
			r[p++] = gcd(a0, bi);
		}
		sort(r, 1, p);
		int p2 = 1;
		for (int i = 1; i < p; i++) {
			if (r[i] != r[i - 1]) {
				r[p2++] = r[i];
			}
		}
		r[p2] = -1;
	}

	static void solve() throws Exception {
		n = scanInt();
		tree = new int[2 * n][30];
		for (int i = 0; i < n; i++) {
			tree[i + n][0] = scanInt();
			tree[i + n][1] = 0;
			tree[i + n][2] = -1;
		}
		for (int i = n - 1; i > 0; i--) {
			treeComb(tree[i << 1], tree[(i << 1) + 1], tree[i]);
		}
		int q = scanInt();
		int res[] = new int[30], tmp[] = new int[30];
		for (int qq = 0; qq < q; qq++) {
			switch (scanInt()) {
			case 1:
			{
				int l = scanInt() - 1 + n, r = scanInt() + n, v = scanInt();
				boolean haveRes = false;
				int x = l, y = 0;
				while (x != r) {
					if ((x & ((1 << (y + 1)) - 1)) == 0 && x + (1 << (y + 1)) <= r) {
						++y;
					} else if (x + (1 << y) > r) {
						--y;
					} else {
						int i = x >> y;
						if (haveRes) {
							treeComb(res, tree[i], tmp);
							int t[] = tmp;
							tmp = res;
							res = t;
						} else {
							for (int j = 0;; j++) {
								if ((res[j] = tree[i][j]) < 0) {
									break;
								}
							}
							haveRes = true;
						}
						x += 1 << y;
					}
				}
				for (int i = 0;; i++) {
					if (res[i] < 0) {
						out.println("NO");
						break;
					}
					if (res[i] % v == 0) {
						out.println("YES");
						break;
					}
				}
			}
			break;
			case 2:
			{
				int i = scanInt() - 1 + n;
				tree[i][0] = scanInt();
				for (i >>= 1; i > 0; i >>= 1) {
					treeComb(tree[i << 1], tree[(i << 1) + 1], tree[i]);
				}
			}
			break;
			default:
				throw new AssertionError();
			}
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