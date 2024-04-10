import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
//		int n = 100000;
		List<Integer> children[] = new List[n];
		for (int i = 0; i < n; i++) {
			children[i] = new ArrayList<>();
		}
		int parent[] = new int[n];
		parent[0] = -1;
		for (int i = 0; i < n - 1; i++) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
//			int u = i;
//			int v = i + 1;
			children[u].add(v);
			parent[v] = u;
		}
		boolean odd[] = new boolean[n];
		Queue<Integer> q = new ArrayDeque<>();
		q.add(0);
		do {
			int cur = q.remove();
			for (int next: children[cur]) {
				odd[next] = !odd[cur];
				q.add(next);
			}
		} while (!q.isEmpty());
		int leaves[] = new int[n];
		int max0[] = new int[n];
		int max1[] = new int[n];
		for (int i = 0; i < n; i++) {
			if (children[i].isEmpty()) {
				q.add(i);
			}
		}
		int processed[] = new int[n];
		do {
			int cur = q.remove();
			if (children[cur].isEmpty()) {
				leaves[cur] = 1;
			} else {
				if (odd[cur]) {
					int min0 = Integer.MAX_VALUE;
					for (int next: children[cur]) {
						leaves[cur] += leaves[next];
						max0[cur] += max0[next];
						min0 = min(min0, leaves[next] - max1[next]);
					}
					max1[cur] = leaves[cur] - min0;
				} else {
					int min1 = Integer.MAX_VALUE;
					for (int next: children[cur]) {
						leaves[cur] += leaves[next];
						min1 = min(min1, leaves[next] - max0[next]);
						max1[cur] += max1[next];
					}
					max0[cur] = leaves[cur] - min1;
				}
			}
			if (cur != 0 && ++processed[parent[cur]] == children[parent[cur]].size()) {
				q.add(parent[cur]);
			}
		} while (!q.isEmpty());
//		System.err.println(Arrays.toString(max0));
//		System.err.println(Arrays.toString(max1));
		out.print((max0[0] + 1) + " " + (leaves[0] - max1[0]));
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