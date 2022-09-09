import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static class IntDeque {

		int data[] = new int[3];
		int p1 = 0, p2 = 0;

		boolean isEmpty() {
			return p1 == p2;
		}

		int size() {
			return p2 - p1;
		}

		void adjust() {
			if (p1 == 0 || p2 == data.length) {
				int size = p2 - p1;
				int odata[] = data;
				if (data.length - size <= size) {
					data = new int[(odata.length << 1) + 1];
				}
				int npos = (data.length - size) >> 1;
				arraycopy(odata, p1, data, npos, size);
				p1 = npos;
				p2 = npos + size;
			}
		}

		void addFirst(int value) {
			adjust();
			data[--p1] = value;
		}

		void addLast(int value) {
			adjust();
			data[p2++] = value;
		}

		int removeFirst() {
			if (isEmpty()) {
				throw new AssertionError();
			}
			return data[p1++];
		}

		int removeLast() {
			if (isEmpty()) {
				throw new AssertionError();
			}
			return data[--p2];
		}

		void clear() {
			p1 = p2 = data.length >> 1;
		}
	}

	static final int DIJ[] = {0, 1, 0, -1, 0};

	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		boolean map[][] = new boolean[n][m];
		int si = -1, sj = -1, ei = -1, ej = -1;
		for (int i = 0; i < n; i++) {
			String s = next();
			for (int j = 0; j < m; j++) {
				switch (s.charAt(j)) {
				case '.':
					map[i][j] = true;
					break;
				case 'S':
					map[i][j] = true;
					si = i;
					sj = j;
					break;
				case 'T':
					map[i][j] = true;
					ei = i;
					ej = j;
					break;
				}
			}
		}
		byte turns[][][] = new byte[4][n][m];
		for (byte a[][]: turns) {
			for (byte aa[]: a) {
				fill(aa, Byte.MAX_VALUE);
			}
		}
		IntDeque q = new IntDeque();
		for (int d = 0; d < 4; d++) {
			turns[d][si][sj] = 0;
			q.addLast((d << 20) | (si << 10) | sj);
		}
		do {
			int cur = q.removeFirst();
			int cd = cur >>> 20;
			int ci = (cur >> 10) & 0x3ff;
			int cj = cur & 0x3ff;
			int cturns = turns[cd][ci][cj];
			if (cturns > 2) {
				break;
			}
			int ni = ci + DIJ[cd], nj = cj + DIJ[cd + 1];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m && map[ni][nj] && turns[cd][ni][nj] > cturns) {
				turns[cd][ni][nj] = (byte) cturns;
				q.addFirst((cd << 20) | (ni << 10) | nj);
			}
			for (int nd = 0; nd < 4; nd++) {
				if (turns[nd][ci][cj] > cturns + 1) {
					turns[nd][ci][cj] = (byte) (cturns + 1);
					q.addLast((nd << 20) | (ci << 10) | cj);
				}
			}
		} while (!q.isEmpty());
		int ans = Integer.MAX_VALUE;
		for (int d = 0; d < 4; d++) {
			ans = min(ans, turns[d][ei][ej]);
		}
		out.print(ans <= 2 ? "YES" : "NO");
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