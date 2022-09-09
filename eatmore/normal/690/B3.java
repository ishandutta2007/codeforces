import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.StringTokenizer;

public class B3 {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		while (nextInt() != 0) {
			int n = nextInt();
			final int pi[] = new int[n];
			final int pj[] = new int[n];
			for (int i = 0; i < n; i++) {
				pi[i] = nextInt();
				pj[i] = nextInt();
			}
			int startPoint = 0, startI = pi[0], startJ = pj[0];
			for (int i = 1; i < n; i++) {
				if (pi[i] < startI || (pi[i] == startI && pj[i] < startJ)) {
					startPoint = i;
					startI = pi[i];
					startJ = pj[i];
				}
			}
			Integer idx[] = new Integer[n - 1];
			for (int i = 0, j = 0; i < n; i++) {
				if (i != startPoint) {
					idx[j++] = i;
				}
			}
			final int fStartI = startI, fStartJ = startJ;
			sort(idx, new Comparator<Integer>() {
				public int compare(Integer o1, Integer o2) {
					int i1 = pi[o1] - fStartI, j1 = pj[o1] - fStartJ;
					int i2 = pi[o2] - fStartI, j2 = pj[o2] - fStartJ;
					int c = Long.compare((long) j1 * i2, (long) i1 * j2);
					if (c != 0) {
						return c;
					}
					return i1 + abs(j1) - (i2 + abs(j2));
				}
			});
			int hull[] = new int[n];
			int hullSize = 1;
			hull[0] = startPoint;
			for (int i: idx) {
				int ni = pi[i], nj = pj[i];
				while (hullSize >= 2) {
					int cur = hull[hullSize - 1];
					int ci = pi[cur], cj = pj[cur];
					int old = hull[hullSize - 2];
					int oi = pi[old], oj = pj[old];
					if ((long) (nj - cj) * (ci - oi) > (long) (ni - ci) * (cj - oj)) {
						break;
					}
					--hullSize;
				}
				hull[hullSize++] = i;
			}
			int ansX[] = new int[hullSize], ansY[] = new int[hullSize];
			int ansSize = 0;
			int start = 0, startX = pi[hull[0]], startY = pj[hull[0]];
			for (int i = 1; i < hullSize; i++) {
				int cx = pi[hull[i]], cy = pj[hull[i]];
				if (cx < startX || (cx == startX && cy < startY)) {
					start = i;
					startX = cx;
					startY = cy;
				}
			}
//			System.err.println(startX + " " + startY);
//			System.err.println(hullSize);
//			for (int i = 0; i < hullSize; i++) {
//				System.err.println((1 + pj[hull[i]]) + " " + (m - pi[hull[i]]));
//			}
			int q = 0;
			for (int i = start;;) {
//				System.err.println(i + " " + (1 + pj[hull[i]]) + " " + (m - pi[hull[i]]) + " " + q);
				ansX[ansSize] = pi[hull[i]] + ADDX[q];
				ansY[ansSize] = pj[hull[i]] + ADDY[q];
				if (ansSize == 0 || ansX[ansSize] != ansX[ansSize - 1] || ansY[ansSize] != ansY[ansSize - 1]) {
					++ansSize;
				}
				int j = i;
				i = (i + hullSize - 1) % hullSize;
				if (i == start) {
					break;
				}
				if (pi[hull[i]] == pi[hull[j]] || pj[hull[i]] == pj[hull[j]]) {
					++q;
				}
			}
			if (ansX[ansSize - 1] == ansX[0] && ansY[ansSize - 1] == ansY[0]) {
				--ansSize;
			}
			out.println(ansSize);
			for (int i = 0; i < ansSize; i++) {
				out.println(ansX[i] + " " + ansY[i]);
			}
		}
	}

	static final int ADDX[] = {0, 0, -1, -1, 0};
	static final int ADDY[] = {0, -1, -1, 0, 0};

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