import static java.lang.System.exit;
import static java.util.Collections.sort;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class F {
	
	static InputStream in;
	static PrintWriter out;
	
	static int n, m;
	static boolean[][] map, map2;
	static int cans;
	
	static void solve() throws Exception {
		n = nextInt() + 16;
		m = nextInt() + 16;
		map = new boolean[n][m];
		for (int i = 8; i < n - 8; i++) {
			for (int j = 8; j < m - 8; j++) {
				map[i][j] = nextInt() != 0;
			}
		}
		map2 = new boolean[n][m];
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < m; j++) {
				if (map[i][j]) {
					++cnt;
				} else {
					cnt = 0;
				}
				map2[i][j] = cnt >= 7;
			}
		}
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (map2[i][j]) {
					++cnt;
				} else {
					cnt = 0;
				}
				map2[i][j] = cnt >= 7;
			}
		}
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = m - 1; j >= 0; j--) {
				if (map2[i][j]) {
					cnt = 11;
				} else {
					--cnt;
				}
				if (j + 2 < m) {
					map2[i][j + 2] = cnt > 0;
				}
			}
		}
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			for (int i = n - 1; i >= 0; i--) {
				if (map2[i][j]) {
					cnt = 11;
				} else {
					--cnt;
				}
				if (i + 2 < n) {
					map2[i + 2][j] = cnt > 0;
				}
			}
		}
		List<Integer> ans = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!map[i][j] || !map2[i][j]) {
					continue;
				}
				cans = 0;
				dfs(i, j);
				ans.add(cans);
			}
		}
		sort(ans);
		out.println(ans.size());
		for (int i = 0; i < ans.size(); i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(ans.get(i));
		}
	}
	
	static final int DI[] = {1, 0, -1, 0};
	static final int DJ[] = {0, 1, 0, -1};
	
	static void dfs(int i, int j) {
		map[i][j] = false;
		for (int d = 0; d < 4; d++) {
			int ii = i + DI[d];
			int jj = j + DJ[d];
			if (ii < 0 || ii >= n || jj < 0 || jj >= m) {
				continue;
			}
			if (!map[ii][jj]) {
				continue;
			}
			if (map2[ii][jj]) {
				dfs(ii, jj);
			} else {
				dfs2(ii, jj);
				++cans;
			}
		}
	}

	static void dfs2(int i, int j) {
		map[i][j] = false;
		for (int d = 0; d < 4; d++) {
			int ii = i + DI[d];
			int jj = j + DJ[d];
			if (ii < 0 || ii >= n || jj < 0 || jj >= m) {
				continue;
			}
			if (!map[ii][jj] || map2[ii][jj]) {
				continue;
			}
			dfs2(ii, jj);
		}
	}

	static int nextInt() throws IOException {
		int c;
		do {
			c = in.read();
		} while (c < '0' && c > '9');
		int i = 0;
		do {
			i = i * 10 + (c - '0');
			c = in.read();
		} while (c >= '0' && c <= '9');
		return i;
	}

	public static void main(String[] args) {
		try {
			in = new BufferedInputStream(System.in);
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