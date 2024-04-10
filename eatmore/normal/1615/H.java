import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class H {

	static void sortBy(int a[], int n, int v[]) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			int cv = v[ca];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (cv <= v[na]) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		int ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (v[a[j + 2]] > v[a[j + 1]]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			int cv = v[ca];
			while (j != 0 && v[a[j]] < cv) {
				j = (j - 1) >> 1;
			}
			while (j != 0) {
				na = a[j];
				a[j] = ca;
				ca = na;
				j = (j - 1) >> 1;
			}
		}
		a[0] = ca;
	}

	static class MaxFlow {

		// Flow network structures

		static int n;
		static int edgesLen[], edges[][], capsLen, caps[];

		static void init() {
			edgesLen = new int[n];
			edges = new int[n][6];
			capsLen = 0;
			caps = new int[6];
		}

		static int addEdge(int from, int to, int capacity, int reverseCapacity) {
			int cap = capsLen;
			if (caps.length == cap) {
				caps = copyOf(caps, (cap << 1) + 2);
			}
			caps[cap] = capacity;
			caps[cap + 1] = reverseCapacity;
			capsLen = cap + 2;
			int e1s[] = edges[from], e1 = edgesLen[from];
			if (e1s.length == e1) {
				e1s = edges[from] = copyOf(e1s, (e1 << 1) + 2);
			}
			e1s[e1] = to;
			e1s[e1 + 1] = cap;
			edgesLen[from] = e1 + 2;
			int e2s[] = edges[to], e2 = edgesLen[to];
			if (e2s.length == e2) {
				e2s = edges[to] = copyOf(e2s, (e2 << 1) + 2);
			}
			e2s[e2] = from;
			e2s[e2 + 1] = cap + 1;
			edgesLen[to] = e2 + 2;
			return cap;
		}

		static int dist[];

		static int dinic(int source, int sink) {
			dist = new int[n];
			int curEdge[] = new int[n];
			int queue[] = new int[n];
			int flow = 0;
			while (true) {
				fill(dist, -1);
				dist[source] = 0;
				queue[0] = source;
				int queueHead = 0;
				int queueTail = 1;
				do {
					int cur = queue[queueHead++];
					int ndist = dist[cur] + 1;
					for (int i = 0, e[] = edges[cur], en = edgesLen[cur]; i < en; i += 2) {
						if (caps[e[i + 1]] == 0) {
							continue;
						}
						int to = e[i];
						if (dist[to] < 0) {
							dist[to] = ndist;
							queue[queueTail++] = to;
						}
					}
				} while (queueHead < queueTail);
				if (dist[sink] < 0) {
					return flow;
				}
				fill(curEdge, 0);
				int stackSize = 0;
				int cur = source;
				int eNum = 0;
				cur: while (true) {
					if (cur == sink) {
						int curFlow = Integer.MAX_VALUE;
						for (int i = 0; i < stackSize; i++) {
							int c = queue[i];
							curFlow = min(curFlow, caps[edges[c][curEdge[c] + 1]]);
						}
						for (int i = 0; i < stackSize; i++) {
							int c = queue[i];
							int cap = edges[c][curEdge[c] + 1];
							caps[cap] -= curFlow;
							caps[cap ^ 1] += curFlow;
						}
						flow += curFlow;
						stackSize = 0;
						cur = source;
						eNum = curEdge[source];
						continue;
					}
					int ndist = stackSize + 1;
					for (int e[] = edges[cur], en = edgesLen[cur]; eNum < en; eNum += 2) {
						int next = e[eNum];
						if (caps[e[eNum + 1]] != 0 && dist[next] == ndist) {
							curEdge[cur] = eNum;
							queue[stackSize++] = cur;
							cur = next;
							eNum = curEdge[cur];
							continue cur;
						}
					}
					curEdge[cur] = eNum;
					if (stackSize == 0) {
						break;
					}
					cur = queue[--stackSize];
					eNum = curEdge[cur] + 2;
				}
			}
		}
	}

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt(), a[] = new int[n], idx[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
			idx[i] = i;
		}
		sortBy(idx, n, a);
		MaxFlow.n = n + 2;
		MaxFlow.init();
		for (int i = 0; i < m; i++) {
			int u = scanInt() - 1, v = scanInt() - 1;
			MaxFlow.addEdge(v, u, Integer.MAX_VALUE / 2, 0);
		}
		for (int i = 0; i < n; i++) {
			MaxFlow.addEdge(i, n + 1, 1, 0);
		}
		int ans[] = new int[n];
		for (int i: idx) {
			MaxFlow.addEdge(n, i, 2, 0);
			MaxFlow.dinic(n, n + 1);
			for (int j = 0; j < n; j++) {
				if (ans[j] == 0 && MaxFlow.dist[j] >= 0) {
					ans[j] = a[i];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
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