import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C3 {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static int n;
	static List<Integer> childrenL[];
	static int parent[], children[][], pos[], end[], childPos[][];
	static int fDepth[], treeMax[], treeAdd[];
	static int center;

	static int getSum(int fenwick[], int i) {
		int res = fenwick[i];
		while ((i = (i & (i + 1)) - 1) >= 0) {
			res += fenwick[i];
		}
		return res;
	}

	static void updateSum(int fenwick[], int i, int v) {
		fenwick[i] += v;
		while ((i |= i + 1) < fenwick.length) {
			fenwick[i] += v;
		}
	}

	static int treePlus(int a, int b) {
		return a == Integer.MIN_VALUE ? Integer.MIN_VALUE : a + b;
	}

	static void treeExpose(int i) {
		if (i > 0) {
			treeExpose(i >> 1);
			int a = treeAdd[i >> 1];
			treeAdd[i >> 1] = 0;
			if (i < n) {
				treeAdd[i] += a;
			}
			treeMax[i] = treePlus(treeMax[i], a);
			if ((i ^ 1) < n) {
				treeAdd[i ^ 1] += a;
			}
			treeMax[i ^ 1] = treePlus(treeMax[i ^ 1], a);
//			try {
//				debugCheckTree();
//			} catch (AssertionError e) {
//				System.err.println(i);
//				throw e;
//			}
		}
	}

	static void treeUpdate(int i) {
		if (i > 0) {
			if (treeAdd[i >> 1] != 0) {
				throw new AssertionError();
			}
			treeMax[i >> 1] = max(treeMax[i], treeMax[i ^ 1]);
			treeUpdate(i >> 1);
		}
	}

	static void treeSet(int i, int v) {
		treeExpose(i);
		treeMax[i] = v;
		treeUpdate(i);
	}

	static void treeAdd(int from, int to, int v) {
//		debugCheckTree();
//		int debugIFrom = from, debugITo = to;
		if (from == to) {
			return;
		}
		--to;
		treeExpose(from);
		treeExpose(to);
//		debugCheckTree();
		boolean left = false, right = false;
		while (from <= to) {
			if ((from & 1) != 0) {
				if (from < n) {
					treeAdd[from] += v;
				}
				treeMax[from] = treePlus(treeMax[from], v);
				++from;
				left = true;
			}
			if ((to & 1) == 0) {
				if (to < n) {
					treeAdd[to] += v;
				}
				treeMax[to] = treePlus(treeMax[to], v);
				--to;
				right = true;
			}
			from >>= 1;
			to >>= 1;
			if (left) {
				if (treeAdd[from - 1] != 0) {
					throw new AssertionError();
				}
				treeMax[from - 1] = max(treeMax[(from - 1) << 1], treeMax[((from - 1) << 1) + 1]);
			}
			if (right) {
				if (treeAdd[to + 1] != 0) {
					throw new AssertionError();
				}
				treeMax[to + 1] = max(treeMax[(to + 1) << 1], treeMax[((to + 1) << 1) + 1]);
			}
		}
		if (left) {
			treeUpdate(from - 1);
		}
		if (right) {
			treeUpdate(to + 1);
		}
//		try {
//			debugCheckTree();
//		} catch (AssertionError e) {
//			System.err.println(debugIFrom + " " + debugITo);
//			throw e;
//		}
	}

	static int treeMaxMin, treeMaxMax;
	static int treeMax(int from, int to) {
		if (from == to) {
			treeMaxMin = -1;
			treeMaxMax = -1;
			return Integer.MIN_VALUE;
		}
		--to;
		treeExpose(from);
		treeExpose(to);
		int cans = Integer.MIN_VALUE;
		boolean haveCans = false;
		int cansMinIndex = -1, cansMinHeight = -1, cansMaxIndex = -1, cansMaxHeight = -1;
		int height = 0;
		while (from <= to) {
			if ((from & 1) != 0) {
				if (!haveCans || cans < treeMax[from]) {
					haveCans = true;
					cans = treeMax[from];
					cansMinIndex = cansMaxIndex = from << height;
					cansMinHeight = cansMaxHeight = height;
				} else if (cans == treeMax[from]) {
					if (cansMinIndex > from << height) {
						cansMinIndex = from << height;
						cansMinHeight = height;
					}
					if (cansMaxIndex < from << height) {
						cansMaxIndex = from << height;
						cansMaxHeight = height;
					}
				}
				++from;
			}
			if ((to & 1) == 0) {
				if (!haveCans || cans < treeMax[to]) {
					haveCans = true;
					cans = treeMax[to];
					cansMinIndex = cansMaxIndex = to << height;
					cansMinHeight = cansMaxHeight = height;
				} else if (cans == treeMax[to]) {
					if (cansMinIndex > to << height) {
						cansMinIndex = to << height;
						cansMinHeight = height;
					}
					if (cansMaxIndex < to << height) {
						cansMaxIndex = to << height;
						cansMaxHeight = height;
					}
				}
				--to;
			}
			from >>= 1;
			to >>= 1;
			++height;
		}
		cansMinIndex >>= cansMinHeight;
		while (cansMinHeight > 0) {
			int a = treeAdd[cansMinIndex];
			treeAdd[cansMinIndex] = 0;
			if (cansMinIndex << 1 < n) {
				treeAdd[cansMinIndex << 1] += a;
			}
			treeMax[cansMinIndex << 1] = treePlus(treeMax[cansMinIndex << 1], a);
			if ((cansMinIndex << 1) + 1 < n) {
				treeAdd[(cansMinIndex << 1) + 1] += a;
			}
			treeMax[(cansMinIndex << 1) + 1] = treePlus(treeMax[(cansMinIndex << 1) + 1], a);
			cansMinIndex <<= 1;
			if (treeMax[cansMinIndex] < treeMax[cansMinIndex + 1]) {
				++cansMinIndex;
			}
			--cansMinHeight;
		}
		cansMaxIndex >>= cansMaxHeight;
		while (cansMaxHeight > 0) {
			int a = treeAdd[cansMaxIndex];
			treeAdd[cansMaxIndex] = 0;
			if (cansMaxIndex << 1 < n) {
				treeAdd[cansMaxIndex << 1] += a;
			}
			treeMax[cansMaxIndex << 1] = treePlus(treeMax[cansMaxIndex << 1], a);
			if ((cansMaxIndex << 1) + 1 < n) {
				treeAdd[(cansMaxIndex << 1) + 1] += a;
			}
			treeMax[(cansMaxIndex << 1) + 1] = treePlus(treeMax[(cansMaxIndex << 1) + 1], a);
			cansMaxIndex <<= 1;
			if (treeMax[cansMaxIndex] <= treeMax[cansMaxIndex + 1]) {
				++cansMaxIndex;
			}
			--cansMaxHeight;
		}
		treeMaxMin = cansMinIndex;
		treeMaxMax = cansMaxIndex;
		return cans;
	}

	static void goUp() {
		if (parent[center] < 0) {
			throw new AssertionError();
		}
		updateSum(fDepth, 0, -1);
		treeAdd(n, 2 * n, -1);
		updateSum(fDepth, pos[center], 2);
		if (end[center] < n) {
			updateSum(fDepth, end[center], -2);
		}
		treeAdd(n + pos[center], n + end[center], 2);
		center = parent[center];
	}

	static void goDown(int to) {
		int p = pos[to];
		if (p <= pos[center] || p >= end[center]) {
			throw new AssertionError();
		}
		int i = binarySearch(childPos[center], p);
		if (i < 0) {
			i = ~i - 1;
		}
		center = children[center][i];
		updateSum(fDepth, 0, 1);
		treeAdd(n, 2 * n, 1);
		updateSum(fDepth, pos[center], -2);
		if (end[center] < n) {
			updateSum(fDepth, end[center], 2);
		}
		treeAdd(n + pos[center], n + end[center], -2);
	}

//	static void debugCheckTree() {
//		for (int i = 0; i < n; i++) {
//			if (treeMax[i] != treePlus(max(treeMax[i << 1], treeMax[(i << 1) + 1]), treeAdd[i])) {
//				System.err.println("! " + i);
//				throw new AssertionError();
//			}
//		}
//	}

	static int getAnswer() {
//		debugCheckTree();
//		System.err.print("Center " + (center + 1) + ":");
//		for (int i = 0; i < n; i++) {
//			System.err.print(" " + getSum(fDepth, i));
//		}
//		System.err.println();
		int depthUp = max(0, max(treeMax(n, n + pos[center]), treeMax(n + end[center], 2 * n)));
		int depthDown = treeMax(n + pos[center], n + end[center]);
		if (depthDown <= 0) {
			return depthUp;
		}
//		debugCheckTree();
//		System.err.println("X: " + pos[center] + " " + end[center] + " " + depthDown + " " + (treeMaxMin - n) + " " + (treeMaxMax - n));
		int i = binarySearch(childPos[center], treeMaxMin - n);
		if (i < 0) {
			i = ~i - 1;
		}
		int child = children[center][i];
		boolean onlyChild = treeMaxMax < n + end[child];
		int depthMax = max(depthUp, depthDown);
		if (depthMax == depthUp || !onlyChild) {
			return 2 * depthMax;
		}
		return 2 * depthMax - 1;
	}

	static void solve() throws Exception {
		n = nextInt();
		parent = new int[n];
		childrenL = new List[n];
		parent[0] = -1;
		childrenL[0] = new ArrayList<>();
		for (int i = 1; i < n; i++) {
			parent[i] = nextInt() - 1;
			childrenL[parent[i]].add(i);
			childrenL[i] = new ArrayList<>();
		}
		children = new int[n][];
		pos = new int[n];
		end = new int[n];
		childPos = new int[n][];
		for (int i = 0; i < n; i++) {
			List<Integer> c = childrenL[i];
			int cs = c.size();
			children[i] = new int[cs];
			childPos[i] = new int[cs];
			for (int j = 0; j < cs; j++) {
				children[i][j] = c.get(j);
			}
		}
		dfs(0, 0);
		fDepth = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < children[i].length; j++) {
				childPos[i][j] = pos[children[i][j]];
			}
			if (pos[i] + 1 < n) {
				updateSum(fDepth, pos[i] + 1, 1);
				if (end[i] < n) {
					updateSum(fDepth, end[i], -1);
				}
			}
		}
		treeMax = new int[2 * n];
		treeAdd = new int[n];
		fill(treeMax, Integer.MIN_VALUE);
		treeSet(n, 0);
		center = 0;
		int ans = 0;
		for (int i = 1; i < n; i++) {
//			debugCheckTree();
			treeSet(n + pos[i], getSum(fDepth, pos[i]));
//			debugCheckTree();
			int ans1 = getAnswer(), ans2;
			if (pos[i] < pos[center] || pos[i] >= end[center]) {
				int pcenter = center;
				goUp();
				ans2 = getAnswer();
				if (ans2 > ans1) {
					goDown(pcenter);
					ans = ans1;
				} else {
					ans = ans2;
				}
			} else if (binarySearch(childPos[center], pos[i]) < 0) {
				goDown(i);
				ans2 = getAnswer();
				if (ans2 > ans1) {
					goUp();
					ans = ans1;
				} else {
					ans = ans2;
				}
			} else {
				ans = ans1;
			}
			if (i > 1) {
				out.print(' ');
			}
//			System.err.println("Center " + (center + 1) + " ans " + ans);
			out.print(ans);
		}
	}

	static int dfs(int cur, int cpos) {
		pos[cur] = cpos++;
		for (int next: children[cur]) {
			cpos = dfs(next, cpos);
		}
		end[cur] = cpos;
		return cpos;
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