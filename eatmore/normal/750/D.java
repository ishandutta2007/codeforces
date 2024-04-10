import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static final int DI[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	static final int DJ[] = {0, -1, -1, -1, 0, 1, 1, 1};

	static void solve() throws Exception {
		int n = nextInt();
		int t[] = new int[n];
		int maxUp = 0, maxSide = 0, maxDown = 0;
		for (int i = 0; i < n; i++) {
			t[i] = nextInt();
			maxUp += t[i];
			if (i > 0) {
				maxSide += t[i];
			}
			if (i <= 1) {
				maxDown -= t[i];
			} else if (i >= 3) {
				maxDown += t[i];
			}
		}
		maxDown = max(maxDown, -1);
		boolean field[][] = new boolean[maxUp + maxDown + 1][2 * maxSide + 1];
		boolean field2[][][] = new boolean[8][maxUp + maxDown + 1][2 * maxSide + 1];
		int m = max((maxUp + maxDown + 1) * (2 * maxSide + 1) * 8, 1);
		int q[] = new int[m];
		int qSize = 1;
		q[0] = (maxUp << 18) | (maxSide << 4);
		int nq[] = new int[m];
		int ans = 0;
		for (int ct: t) {
			int nqSize = 0;
			for (int i = 0; i < qSize; i++) {
				int p = q[i];
				int pi = p >>> 18, pj = (p >> 4) & 0x3fff, pd = p & 0xf, pdi = DI[pd], pdj = DJ[pd];
				for (int j = 0; j < ct; j++) {
					pi += pdi;
					pj += pdj;
					if (!field[pi][pj]) {
						field[pi][pj] = true;
						++ans;
					}
				}
				for (int j = 1; j <= 7; j += 6) {
					int nd = (pd + j) & 7;
					if (!field2[nd][pi][pj]) {
						field2[nd][pi][pj] = true;
						nq[nqSize++] = (pi << 18) | (pj << 4) | nd;
					}
				}
			}
			for (int i = 0; i < nqSize; i++) {
				int p = nq[i];
				int pi = p >>> 18, pj = (p >> 4) & 0x3fff, pd = p & 0xf;
				field2[pd][pi][pj] = false;
			}
			int tt[] = q;
			q = nq;
			nq = tt;
			qSize = nqSize;
		}
		out.print(ans);
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