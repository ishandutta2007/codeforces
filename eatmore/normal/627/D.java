import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static int n, k, a[];
	static List<Integer> edges[];
	static boolean complete[];
	static int count[];
	static int limit;
	static boolean completeUp[];
	static int countUp[];
	
	static void solve() throws Exception {
		n = nextInt();
		k = nextInt();
		a = new int[n];
		Integer aSorted[] = new Integer[n];
		for (int i = 0; i < n; i++) {
			aSorted[i] = a[i] = nextInt();
		}
		sort(aSorted);
		edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 1; i < n; i++) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			edges[u].add(v);
			edges[v].add(u);
		}
		complete = new boolean[n];
		count = new int[n];
		completeUp = new boolean[n];
		countUp = new int[n];
		int l = 0, r = n;
		while (l + 1 < r) {
			int mid = (l + r) >>> 1;
			limit = aSorted[mid];
//			System.err.println("Testing limit " + limit);
			dfs1(0, -1);
//			System.err.println();
//			System.err.println(Arrays.toString(complete));
//			System.err.println(Arrays.toString(count));
			completeUp[0] = true;
			countUp[0] = 0;
//			System.err.println(Arrays.toString(completeUp));
//			System.err.println(Arrays.toString(countUp));
//			System.err.println(good);
			if (dfs2(0, -1)) {
				l = mid;
			} else {
				r = mid;
			}
		}
		out.print(aSorted[l]);
	}
	
	static void dfs1(int cur, int prev) {
//		System.err.print(" (" + cur);
		int sumComplete = 0;
		int bestIncomplete = -1;
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur].get(i);
			if (next == prev) {
//				upEdge[cur] = i;
				continue;
			}
			dfs1(next, cur);
			if (complete[next]) {
				sumComplete += count[next];
			} else {
				bestIncomplete = max(bestIncomplete, count[next]);
			}
		}
		if (a[cur] < limit) {
			complete[cur] = false;
			count[cur] = 0;
		} else if (bestIncomplete >= 0) {
			complete[cur] = false;
			count[cur] = 1 + sumComplete + bestIncomplete;
		} else {
			complete[cur] = true;
			count[cur] = 1 + sumComplete;
		}
//		System.err.print(")");
	}
	
	static boolean dfs2(int cur, int prev) {
		int sumComplete, bestIncomplete, bestIncomplete2 = -1;
		if (completeUp[cur]) {
			sumComplete = countUp[cur];
			bestIncomplete = -1;
		} else {
			sumComplete = 0;
			bestIncomplete = countUp[cur];
		}
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur].get(i);
			if (next == prev) {
				continue;
			}
			if (complete[next]) {
				sumComplete += count[next];
			} else if (count[next] > bestIncomplete) {
				bestIncomplete2 = bestIncomplete;
				bestIncomplete = count[next];
			} else if (count[next] > bestIncomplete2) {
				bestIncomplete2 = count[next];
			}
		}
		if (a[cur] >= limit && 1 + sumComplete + max(bestIncomplete, 0) >= k) {
			return true;
		}
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur].get(i);
			if (next == prev) {
				continue;
			}
			int localSumComplete, localBestIncomplete;
			if (complete[next]) {
				localSumComplete = sumComplete - count[next];
				localBestIncomplete = bestIncomplete;
			} else {
				localSumComplete = sumComplete;
				localBestIncomplete = count[next] == bestIncomplete ? bestIncomplete2 : bestIncomplete;
			}
			if (a[cur] < limit) {
				completeUp[next] = false;
				countUp[next] = 0;
			} else if (localBestIncomplete >= 0) {
				completeUp[next] = false;
				countUp[next] = 1 + localSumComplete + localBestIncomplete;
			} else {
				completeUp[next] = true;
				countUp[next] = 1 + localSumComplete;
			}
			if (dfs2(next, cur)) {
				return true;
			}
		}
		return false;
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