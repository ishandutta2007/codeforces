import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		boolean img[][] = new boolean[n][m];
		int minI = Integer.MAX_VALUE;
		int maxI = Integer.MIN_VALUE;
		int minJ = Integer.MAX_VALUE;
		int maxJ = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			String l = next();
			for (int j = 0; j < m; j++) {
				if (l.charAt(j) == 'X') {
					img[i][j] = true;
					minI = min(minI, i);
					maxI = max(maxI, i);
					minJ = min(minJ, j);
					maxJ = max(maxJ, j);
				}
			}
		}
		if (minI == Integer.MAX_VALUE) {
			out.print(-1);
			return;
		}
		int ans = check(img, minI, maxI + 1, minJ, maxJ + 1);
		boolean imgT[][] = new boolean[m][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				imgT[j][i] = img[i][j];
			}
		}
		ans = min(ans, check(imgT, minJ, maxJ + 1, minI, maxI + 1));
		out.print(ans == Integer.MAX_VALUE ? -1 : ans);
	}
	
	static int check(boolean img[][], int minI, int maxI, int minJ, int maxJ) {
//		System.err.println("BEGIN CHECK");
		int hcnt = 0;
		for (int i = minJ; i < maxJ && img[minI][i]; i++) {
			++hcnt;
		}
		if (hcnt == maxJ - minJ) {
			for (int i = minI; i < maxI; i++) {
				for (int j = minJ; j < maxJ; j++) {
					if (!img[i][j]) {
						return Integer.MAX_VALUE;
					}
				}
			}
			return hcnt;
		}
		int vcnt = 0;
		for (int i = minI; i < maxI && img[i][minJ]; i++) {
			++vcnt;
		}
		int vcnt2 = 0;
		for (int i = minI; i < maxI && !img[i][minJ + hcnt]; i++) {
			++vcnt2;
		}
		if (vcnt2 >= vcnt) {
			return Integer.MAX_VALUE;
		}
		int sizeI = vcnt - vcnt2;
		int sizeJ = hcnt;
//		System.err.println("SIZE " + sizeI + " " + sizeJ);
		int posI = 0;
		int posJ = 0;
		for (int i = 0; i < sizeI; i++) {
			for (int j = 0; j < sizeJ; j++) {
				if (!img[minI + i][minJ + j]) {
					return Integer.MAX_VALUE;
				}
			}
		}
		while (posI < maxI - minI - sizeI || posJ < maxJ - minJ - sizeJ) {
			if (posI < maxI - minI - sizeI && img[minI + posI + sizeI][minJ + posJ]) {
				for (int i = minJ + posJ + sizeJ; i < maxJ; i++) {
					if (img[minI + posI][i]) {
						return Integer.MAX_VALUE;
					}
				}
				for (int i = 0; i < sizeJ; i++) {
					if (!img[minI + posI + sizeI][minJ + posJ + i]) {
						return Integer.MAX_VALUE;
					}
				}
				++posI;
//				System.err.println("DOWN");
				continue;
			}
			if (posJ < maxJ - minJ - sizeJ && img[minI + posI][minJ + posJ + sizeJ]) {
				for (int i = minI + posI + sizeI; i < maxI; i++) {
					if (img[i][minJ + posJ]) {
						return Integer.MAX_VALUE;
					}
				}
				for (int i = 0; i < sizeI; i++) {
					if (!img[minI + posI + i][minJ + posJ + sizeJ]) {
						return Integer.MAX_VALUE;
					}
				}
				++posJ;
//				System.err.println("RIGHT");
				continue;
			}
			return Integer.MAX_VALUE;
		}
//		System.err.println("CHECK OK");
		return sizeI * sizeJ;
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