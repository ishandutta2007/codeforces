import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Random;
import java.util.Set;
import java.util.StringTokenizer;

public class D {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class GoodPair {
		final int i, j, k;

		
		GoodPair(int i, int j, int k) {
			this.i = i;
			this.j = j;
			this.k = k;
		}
		
		boolean compat(GoodPair p) {
			return i != p.i && j != p.j && j != p.k && k != p.j && k != p.k;
		}
		
//		public String toString() {
//			return (i + 1) + " " + (j + 1) + " " + (k + 1);
//		}
	}
	
	static void test() {
		final Random rng = new Random(42);
		int test = 0;
		while (true) {
			int n = 3 * (rng.nextInt(2) + 1);
			boolean type[] = new boolean[n];
			for (int i = 0; i < n; i++) {
				type[i] = rng.nextBoolean();
			}
			List<Integer> edges[] = (List<Integer>[]) new List<?>[n];
			for (int i = 0; i < n; i++) {
				edges[i] = new ArrayList<Integer>();
			}
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (type[i] != type[j] && rng.nextBoolean()) {
						edges[i].add(j);
						edges[j].add(i);
					}
				}
			}
			int ans[] = solve(edges);
			try {
				if (ans != null) {
					int cnt[] = new int[n / 3];
					for (int i: ans) {
						++cnt[i];
						if (cnt[i] > 3) {
							throw new AssertionError();
						}
					}
				}
			} catch (Throwable t) {
				System.err.println(n);
				for (int i = 0; i < n; i++) {
					for (int j: edges[i]) {
						if (j > i) {
							System.err.println((i + 1) + " " + (j + 1));
						}
					}
				}
				t.printStackTrace();
				exit(1);
			}
			if (++test % 1000 == 0) {
				System.err.println("PASS");
			}
		}
	}

	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		if (n % 3 != 0) {
			throw new AssertionError();
		}
		List<Integer> edges[] = (List<Integer>[]) new List<?>[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			edges[a].add(b);
			edges[b].add(a);
		}
		int[] ans = solve(edges);
		if (ans == null) {
			out.println("NO");
		} else {
			out.println("YES");
			for (int i = 0; i < n; i++) {
				if (i > 0) {
					out.print(' ');
				}
				out.print(ans[i] + 1);
			}
			out.println();
		}
	}

	private static int[] solve(List<Integer>[] edges) {
		int n = edges.length;
		boolean seen[] = new boolean[n];
		boolean side[] = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (!seen[i]) {
				dfs(edges, seen, side, i, false);
			}
		}
		int sizeFalse = 0;
		for (int i = 0; i < n; i++) {
			if (!side[i]) {
				++sizeFalse;
			}
		}
//		System.err.println(Arrays.toString(edges));
//		System.err.println(Arrays.toString(side));
		int ans[] = new int[n];
		fill(ans, -1);
		check: {
			if (sizeFalse % 3 != 0) {
				int sizeTrue = n - sizeFalse;
				boolean oneSide = sizeFalse % 3 != 1;
//				System.err.println("oneside " + oneSide);
				int sizeOne = oneSide ? sizeTrue : sizeFalse;
				int sizeTwo = oneSide ? sizeFalse : sizeTrue;
//				System.err.println("size " + sizeOne + " " + sizeTwo);
				List<Integer> sideOne = new ArrayList<>();
				List<Integer> sideTwo = new ArrayList<>();
				for (int i = 0; i < n; i++) {
					if (side[i] == oneSide) {
						sideOne.add(i);
					} else {
						sideTwo.add(i);
					}
				}
				List<GoodPair> pairs = new ArrayList<GoodPair>();
				for (int i = 0; i < n; i++) {
					if (side[i] == oneSide) {
						if (sizeTwo - edges[i].size() >= 2) {
							ans[i] = 0;
							Set<Integer> tmp = new HashSet<>(edges[i]);
							int cnt = 0;
							for (int j : sideTwo) {
								if (!tmp.contains(j)) {
									ans[j] = 0;
									if (++cnt == 2) {
										break;
									}
								}
							}
//							System.err.println("Found good");
							break check;
						}
					} else {
						if (sizeOne - edges[i].size() >= 2) {
							Set<Integer> tmp = new HashSet<>(edges[i]);
							List<Integer> curNonedges = new ArrayList<>();
							for (int j : sideOne) {
								if (!tmp.contains(j)) {
									curNonedges.add(j);
									if (curNonedges.size() >= 4) {
										break;
									}
								}
							}
							for (int j = 0; j < curNonedges.size(); j++) {
								for (int k = j + 1; k < curNonedges.size(); k++) {
									pairs.add(new GoodPair(i, curNonedges.get(j), curNonedges.get(k)));
								}
							}
						}
					}
				}
				if (pairs.size() > 0) {
					GoodPair p = pairs.get(0);
					List<GoodPair> jcompat = new ArrayList<GoodPair>();
					List<GoodPair> kcompat = new ArrayList<GoodPair>();
					for (GoodPair p2: pairs) {
						if (p.compat(p2)) {
							ans[p.i] = 0;
							ans[p.j] = 0;
							ans[p.k] = 0;
							ans[p2.i] = 1;
							ans[p2.j] = 1;
							ans[p2.k] = 1;
//							System.err.println("Found average " + p + " " + p2);
							break check;
						}
						if (p.j != p2.j && p.j != p2.k) {
							jcompat.add(p2);
						}
						if (p.k != p2.j && p.k != p2.k) {
							kcompat.add(p2);
						}
					}
					if (jcompat.size() > 0 && kcompat.size() > 0) {
						GoodPair jp = jcompat.get(0);
						GoodPair kp = kcompat.get(0);
						for (GoodPair p2: pairs) {
							if (jp.compat(p2)) {
								ans[jp.i] = 0;
								ans[jp.j] = 0;
								ans[jp.k] = 0;
								ans[p2.i] = 1;
								ans[p2.j] = 1;
								ans[p2.k] = 1;
//								System.err.println("Found average " + jp + " " + p2);
								break check;
							}
							if (kp.compat(p2)) {
								ans[kp.i] = 0;
								ans[kp.j] = 0;
								ans[kp.k] = 0;
								ans[p2.i] = 1;
								ans[p2.j] = 1;
								ans[p2.k] = 1;
//								System.err.println("Found average " + kp + " " + p2);
								break check;
							}
						}
					}
				}
				return null;
			} else {
//				System.err.println("Found very good");
			}
		}
		int minans = -1;
		for (int i: ans) {
			minans = max(minans, i);
		}
		for (int i = 0, j = 0; i < n; i++) {
			if (!side[i] && ans[i] < 0) {
				if (j++ % 3 == 0) {
					++minans;
				}
				ans[i] = minans;
			}
		}
		for (int i = 0, j = 0; i < n; i++) {
			if (side[i] && ans[i] < 0) {
				if (j++ % 3 == 0) {
					++minans;
				}
				ans[i] = minans;
			}
		}
		return ans;
	}

	static void dfs(List<Integer> edges[], boolean seen[], boolean side[],
			int cur, boolean curSide) {
		if (seen[cur]) {
			if (side[cur] != curSide) {
				throw new AssertionError();
			}
			return;
		}
		seen[cur] = true;
		side[cur] = curSide;
		for (int next : edges[cur]) {
			dfs(edges, seen, side, next, !curSide);
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
//		test();
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