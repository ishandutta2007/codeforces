import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static final int DI[] = {1, 0, -1, 0};
	static final int DJ[] = {0, 1, 0, -1};
	
	static class Pos implements Comparable<Pos> {
		int i, j, dist;

		Pos(int i, int j, int dist) {
			this.i = i;
			this.j = j;
			this.dist = dist;
		}
		
		public int compareTo(Pos o) {
			return dist - o.dist;
		}
	}
	
	static final List<Pos> pool = new ArrayList<>();
	
	static Pos get(int i, int j, int dist) {
		if (pool.isEmpty()) {
			return new Pos(i, j, dist);
		} else {
			Pos res = pool.remove(pool.size() - 1);
			res.i = i;
			res.j = j;
			res.dist = dist;
			return res;
		}
	}
	
	static void put(Pos pos) {
		pool.add(pos);
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
//		int n = 80;
//		int m = 80;
		int id[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				id[i][j] = nextInt() - 1;
//				id[i][j] = (n * i + j) % (n * m / 2);
			}
		}
		int cap[][][] = new int[n][m][4];
		int cost[][][] = new int[n][m][4];
		int imbalance[][] = new int[n][m];
		int totalCost = n * m / 2;
		int totalImbalance = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (((i ^ j) & 1) != 0) {
					--imbalance[i][j];
					continue;
				}
				++imbalance[i][j];
				for (int d = 0; d < 4; d++) {
					int ii = i + DI[d];
					int jj = j + DJ[d];
					if (ii < 0 || ii >= n || jj < 0 || jj >= m) {
						continue;
					}
					if (id[i][j] == id[ii][jj]) {
						cap[ii][jj][d ^ 2] = 1;
						cost[ii][jj][d ^ 2] = 1;
						cost[i][j][d] = -1;
						--imbalance[i][j];
						++imbalance[ii][jj];
						--totalCost;
					} else {
						cap[i][j][d] = 1;
					}
				}
				totalImbalance += imbalance[i][j];
			}
		}
		int dist[][] = new int[n][m];
		int distAdj[][] = new int[n][m];
		int back[][] = new int[n][m];
		PriorityQueue<Pos> queue = new PriorityQueue<>();
		List<Pos> curDistQ = new ArrayList<>();
		while (totalImbalance > 0) {
			for (int t[]: dist) {
				fill(t, Integer.MAX_VALUE);
			}
			for (int t[]: back) {
				fill(t, -1);
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (imbalance[i][j] > 0) {
						dist[i][j] = 0;
						curDistQ.add(get(i, j, 0));
					}
				}
			}
			do {
				Pos pos = curDistQ.isEmpty() ? queue.remove() : curDistQ.remove(curDistQ.size() - 1);
				int i = pos.i;
				int j = pos.j;
				int cdist = pos.dist;
				put(pos);
				if (dist[i][j] != cdist) {
					continue;
				}
				for (int d = 0; d < 4; d++) {
					if (cap[i][j][d] == 0) {
						continue;
					}
					int ii = i + DI[d];
					int jj = j + DJ[d];
					int ndist = cdist + cost[i][j][d] + distAdj[ii][jj] - distAdj[i][j];
					if (ndist < cdist) {
						throw new AssertionError();
					}
					if (dist[ii][jj] > ndist) {
						dist[ii][jj] = ndist;
						back[ii][jj] = d ^ 2;
						(cdist == ndist ? curDistQ : queue).add(get(ii, jj, ndist));
					}
				}
			} while (!curDistQ.isEmpty() || !queue.isEmpty());
			int resDist = Integer.MAX_VALUE;
			int resI = -1;
			int resJ = -1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (imbalance[i][j] < 0 && resDist > dist[i][j]) {
						resDist = dist[i][j];
						resI = i;
						resJ = j;
					}
				}
			}
			if (resDist == Integer.MAX_VALUE) {
				throw new AssertionError();
			}
			{
				int i = resI, j = resJ;
				++imbalance[i][j];
				while (true) {
					int d = back[i][j];
					int ii = i + DI[d];
					int jj = j + DJ[d];
					++cap[i][j][d];
					--cap[ii][jj][d ^ 2];
					i = ii;
					j = jj;
					if (imbalance[i][j] > 0) {
						break;
					}
				}
				--imbalance[i][j];
				--totalImbalance;
				totalCost += dist[resI][resJ] - distAdj[resI][resJ] - dist[i][j] + distAdj[i][j];
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (dist[i][j] != Integer.MAX_VALUE) {
						distAdj[i][j] -= dist[i][j];
					}
				}
			}
		}
		out.print(totalCost);
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