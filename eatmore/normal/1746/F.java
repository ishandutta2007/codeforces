import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;
import static java.lang.System.nanoTime;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;

public class F {

	static long seed1 = currentTimeMillis(), seed2 = nanoTime();

	static int randInt() {
		return (int) (((seed1 = (seed1 << 24) ^ (seed1 >>> 40) ^ (seed2 ^= seed1) ^ (seed2 << 16)) + (seed2 = (seed2 << 37) ^ (seed2 >>> 27))) >> 32);
	}

	static int[] get(Map<Integer, int[]> hashes, int k) {
		int[] v = hashes.get(k);
		if (v == null) {
			v = new int[CNT];
			for (int i = 0; i < CNT; i++) {
				v[i] = randInt();
			}
			hashes.put(k, v);
		}
		return v;
	}

	static class LongSumTree {

		final long t[];

		LongSumTree(int n) {
			t = new long[n];
		}

		void init(long v[]) {
			int n = t.length;
			arraycopy(v, 0, t, 0, n);
			for (int i = 0, j; i < n; i++) {
				if ((j = i | (i + 1)) < n) {
					t[j] += t[i];
				}
			}
		}

		long get(int i) {
			long res = t[i];
			for (int j = 1; (i & j) != 0; j <<= 1) {
				res -= t[i ^ j];
			}
			return res;
		}

		long getPrefixSum(int i) {
			long res = 0;
			for (; i > 0; i &= i - 1) {
				res += t[i - 1];
			}
			return res;
		}

		long getSum(int l, int r) {
			return getPrefixSum(r) - getPrefixSum(l);
		}

		int scanNZ(int i) {
			int n = t.length, s = 1;
			scan: {
				while (i + s <= n) {
					if ((i & s) != 0) {
						do {
							i += s;
							long v = t[i - 1];
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
				long v = t[i - 1];
				if (v != 0) {
					--i;
					int j;
					for (j = 1; (i & j) != 0; j <<= 1) { }
					while ((j >>= 1) != 0) {
						long w = t[i ^ j];
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

		void add(int i, long v) {
			int n = t.length;
			do {
				t[i] += v;
			} while ((i |= i + 1) < n);
		}

		void set(int i, long v) {
			add(i, v - get(i));
		}
	}

	static final int CNT = 30;

	static void solve() throws Exception {
		int n = scanInt(), q = scanInt();
		Map<Integer, int[]> hashes = new HashMap<>();
		LongSumTree trees[] = new LongSumTree[CNT];
		for (int i = 0; i < CNT; i++) {
			trees[i] = new LongSumTree(n);
		}
		int a[][] = new int[n][];
		for (int i = 0; i < n; i++) {
			a[i] = get(hashes, scanInt());
			for (int j = 0; j < CNT; j++) {
				trees[j].add(i, a[i][j]);
			}
		}
		for (int qq = 0; qq < q; qq++) {
			if (scanInt() == 1) {
				int i = scanInt() - 1, v[] = get(hashes, scanInt());
				int pv[] = a[i];
				for (int j = 0; j < CNT; j++) {
					trees[j].add(i, (long) v[j] - pv[j]);
				}
				a[i] = v;
			} else {
				int l = scanInt() - 1, r = scanInt(), k = scanInt();
				for (int i = 0;; i++) {
					if (i == CNT) {
						out.println("YES");
						break;
					}
					if (trees[i].getSum(l, r) % k != 0) {
						out.println("NO");
						break;
					}
				}
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