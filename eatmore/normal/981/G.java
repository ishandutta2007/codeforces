import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.NavigableSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class G {

	static final int MOD = 998244353;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static int treeN, treeMul[], treeLin[], treeConst[];

	static void treeApp(int i, int mul, int lin, int cons) {
		if (mul != 1) {
			treeMul[i] = mul(treeMul[i], mul);
			treeLin[i] = mul(treeLin[i], mul);
			treeConst[i] = mul(treeConst[i], mul);
		}
		treeLin[i] = add(treeLin[i], lin);
		treeConst[i] = add(treeConst[i], cons);
	}

	static void treePush(int i) {
		if (i >= treeN) {
			treeMul[i] = 0;
			if (treeLin[i] != 0) {
				treeConst[i] = add(treeConst[i], mul(treeLin[i], i - treeN));
				treeLin[i] = 0;
			}
		} else {
			treeApp(i << 1, treeMul[i], treeLin[i], treeConst[i]);
			treeApp((i << 1) + 1, treeMul[i], treeLin[i], treeConst[i]);
			treeMul[i] = 1;
			treeLin[i] = 0;
			treeConst[i] = 0;
		}
	}

	static void treeRangeApp(int from, int to, int mul, int lin, int cons) {
		if (from == to) {
			return;
		}
		from += treeN;
		to += treeN;
		int x = from;
		for (int i = 31 - Integer.numberOfLeadingZeros(x); i >= 0; i--) {
//			System.err.println("-> push " + (x >> i));
			treePush(x >> i);
		}
		int y = 0;
		while (x < to) {
			if ((x & ((1 << (y + 1)) - 1)) == 0 && x + (1 << (y + 1)) <= to) {
				++y;
			} else if (x + (1 << y) > to) {
				--y;
			} else {
				for (int i = Integer.numberOfTrailingZeros(x); i >= y; i--) {
//					System.err.println("-> push " + (x >> i));
					treePush(x >> i);
				}
//				System.err.println("-> app " + (x >> y) + " " + mul + " " + lin + " " + cons);
				treeApp(x >> y, mul, lin, cons);
				x += 1 << y;
			}
		}
	}

	static int treeGet(int i) {
//		System.err.println("get " + i);
		i += treeN;
		for (int j = 31 - Integer.numberOfLeadingZeros(i); j >= 0; j--) {
			treePush(i >> j);
		}
//		System.err.println("-> " + treeConst[i]);
		return treeConst[i];
	}

	static void add1(int from, int to) {
//		System.err.println("add1 " + from + " " + to);
		treeRangeApp(from, to, 1, 1, sub(0, from));
		treeRangeApp(to, treeN, 1, 0, to - from);
	}

	static void mul2(int from, int to) {
//		System.err.println("mul2 " + from + " " + to);
		int vf = treeGet(from), vt = treeGet(to);
		treeRangeApp(from, to, 2, 0, sub(0, vf));
		treeRangeApp(to, treeN, 1, 0, sub(vt, vf));
	}

	static class Range implements Comparable<Range> {
		final int from, to;

		Range(int from, int to) {
			this.from = from;
			this.to = to;
		}

		public int compareTo(Range o) {
			return from - o.from;
		}
	}

	static void solve() throws Exception {
		int n = scanInt();
		int q = scanInt();
		treeN = n + 1;
		treeMul = new int[2 * treeN];
		fill(treeMul, 1);
		treeLin = new int[2 * treeN];
		treeConst = new int[2 * treeN];
		NavigableSet<Range> ranges[] = new NavigableSet[n];
		for (int i = 0; i < n; i++) {
			ranges[i] = new TreeSet<>();
		}
		for (int qq = 0; qq < q; qq++) {
			switch (scanInt()) {
			case 1:
				int from = scanInt() - 1, to = scanInt(), v = scanInt() - 1;
				Range cur = new Range(from, to);
				int pos = from;
				Range test = ranges[v].lower(cur);
				if (test != null && test.to > from) {
					if (test.to > to) {
						mul2(from, to);
						break;
					} else {
						mul2(from, test.to);
						pos = test.to;
						cur = new Range(test.from, to);
						ranges[v].remove(test);
					}
				}
				while (true) {
					test = ranges[v].ceiling(cur);
					if (test == null || test.from >= to) {
						add1(pos, to);
						break;
					}
					add1(pos, test.from);
					if (test.to > to) {
						mul2(test.from, to);
						cur = new Range(cur.from, test.to);
						ranges[v].remove(test);
						break;
					} else {
						mul2(test.from, test.to);
						pos = test.to;
						ranges[v].remove(test);
					}
				}
				ranges[v].add(cur);
				break;
			case 2:
				from = scanInt() - 1;
				to = scanInt();
				out.println(sub(treeGet(to), treeGet(from)));
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