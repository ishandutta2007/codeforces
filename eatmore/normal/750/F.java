import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;
import java.util.Random;
import java.util.StringTokenizer;

public class F {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static final boolean DEBUG = false;
	static int debugH, debugQ, debugAns;
	static int debugTree[], debugTreeInv[];
	static final Random rng = new Random(42);

//	static void debug() throws Exception {
//		while (true) {
//			debugH = rng.nextInt(6) + 2;
//			debugTree = new int[(1 << debugH) - 1];
//			for (int i = 0; i < debugTree.length; i++) {
//				int j = rng.nextInt(i + 1);
//				debugTree[i] = debugTree[j];
//				debugTree[j] = i + 1;
//			}
////			debugH = 7;
////			debugTree = new int[127];
////			@SuppressWarnings("resource")
////			StringTokenizer tok = new StringTokenizer(new BufferedReader(new FileReader("tree.txt")).readLine());
////			for (int i = 0; i < debugTree.length; i++) {
////				debugTree[i] = parseInt(tok.nextToken());
////			}
//			debugTreeInv = new int[debugTree.length];
//			for (int i = 0; i < debugTree.length; i++) {
//				debugTreeInv[debugTree[i] - 1] = i;
//			}
//			debugQ = 0;
//			debugAns = -1;
//			try {
//				solve();
//				if (debugAns != debugTree[0]) {
//					throw new AssertionError();
//				}
//			} catch (AssertionError e) {
//				System.err.println(Arrays.toString(debugTree));
//				throw e;
//			}
//			System.err.println("TEST");
////			break;
//		}
//	}

//	static int[] debugQuery(int p) {
//		if (debugQ++ == 16) {
//			throw new AssertionError();
//		}
////		int op = p;
//		int ans[] = new int[3];
//		p = debugTreeInv[p - 1];
//		int n = 0;
//		if (p > 0) {
//			ans[n++] = debugTree[(p - 1) / 2];
//		}
//		if (p < debugTree.length / 2) {
//			ans[n++] = debugTree[2 * p + 1];
//			ans[n++] = debugTree[2 * p + 2];
//		}
//		sort(ans, 0, n);
////		System.err.println(op + " " + Arrays.toString(Arrays.copyOf(ans, n)));
//		return Arrays.copyOf(ans, n);
//	}

	static class Found extends Throwable { }

	static int queries;
	static final Map<Integer, int[]> cache = new HashMap<>();
	static int[] query(int p) throws IOException, Found {
		int ans[] = cache.get(p);
		if (ans != null) {
			return ans;
		}
		--queries;
		if (DEBUG) {
//			ans = debugQuery(p);
		} else {
			out.println("? " + p);
			out.flush();
			int k = nextInt();
			ans = new int[k];
			for (int i = 0; i < k; i++) {
				ans[i] = nextInt();
			}
		}
		if (ans.length == 2) {
			answer(p);
		}
		cache.put(p, ans);
		return ans;
	}

	static void answer(int p) throws Found {
		if (DEBUG) {
			debugAns = p;
		} else {
			out.println("! " + p);
			out.flush();
		}
		throw new Found();
	}

	static void solve() throws Exception {
		int tests = DEBUG ? 1 : nextInt();
		for (int test = 0; test < tests; test++) {
			int h = DEBUG ? debugH : nextInt();
			cache.clear();
			queries = 16;
			try {
				int cpath[] = new int[2 * h - 1];
				cpath[0] = 1;
				int ci = 0;
				while (true) {
					int n[] = query(cpath[ci]);
					int next = -1;
					for (int x: n) {
						if (ci > 0 && cpath[ci - 1] == x) {
							continue;
						}
						next = x;
						break;
					}
					if (next >= 0) {
						cpath[++ci] = next;
						continue;
					}
					if (query(cpath[0]).length != 1) {
						for (int i = 0, j = ci; i < j; ++i, --j) {
							int t = cpath[i];
							cpath[i] = cpath[j];
							cpath[j] = t;
						}
						continue;
					}
//					System.err.println("PATH " + Arrays.toString(Arrays.copyOf(cpath, ci + 1)));
					if (h <= 2) {
						throw new AssertionError();
					}
					if (ci == 2 * h - 4) {
						n = query(cpath[h - 2]);
						next = -1;
						for (int x: n) {
							if (cpath[h - 3] == x || cpath[h - 1] == x) {
								continue;
							}
							next = x;
							break;
						}
						if (next < 0) {
							throw new AssertionError();
						}
						answer(next);
					}
					if (ci % 2 == 1) {
						throw new AssertionError();
					}
					ci = ci / 2;
					n = query(cpath[ci]);
					next = -1;
					for (int x: n) {
						if (cpath[ci - 1] == x || cpath[ci + 1] == x) {
							continue;
						}
						next = x;
						break;
					}
					int depth = h - 2 - ci;
					if (queries >= (1 << (depth + 1)) - 2) {
						Queue<Integer> q = new ArrayDeque<>();
						q.add(next);
						while (queries > 0 && !q.isEmpty()) {
							for (int x: query(q.remove())) {
								if (!cache.containsKey(x)) {
									q.add(x);
								}
							}
						}
						if (q.isEmpty()) {
							throw new AssertionError();
						}
						answer(q.remove());
					}
					if (next >= 0) {
						cpath[++ci] = next;
						continue;
					}
					throw new AssertionError();
				}
			} catch (Found e) { }
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
			if (DEBUG) {
//				debug();
			} else {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}