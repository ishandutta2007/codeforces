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
import java.util.StringTokenizer;

public class F {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[nextInt() - 1] = i;
		}
		out.print(solve(a) ? "YES" : "NO");
	}
	
	static boolean solve(int a[]) {
		int n = a.length;
		int slmax[] = new int[n];
		int slmin[] = new int[n];
		for (int step = 1; step < n; step <<= 1) {
			for (int pos = 0; pos < step && pos + step < n; pos++) {
				boolean inv = a[pos] > a[pos + step];
				int slmaxHead = 0;
				int slmaxTail = 1;
				int slmaxHeadI = 0;
				slmax[0] = a[pos];
				int slminHead = 0;
				int slminTail = 1;
				int slminHeadI = 1;
				slmin[0] = a[pos + step];
				int maxI = (n - 1 - pos) / step;
//				System.err.println("CHECKING (" + pos + ", " + step + ") WITH maxI = " + maxI + " AND inv = " + inv);
				for (int i = 2; i <= maxI; i++) {
					int cur = pos + i * step;
					int val = a[cur];
					if ((i & 1) == 0) {
//						System.err.println("CHECK " + i + " AGAINST " + slminHeadI + ".." + (i - 1) + " " + Arrays.toString(Arrays.copyOfRange(slmin, slminHead, slminTail)));
						if ((val > slmin[slminHead]) ^ inv) {
							return true;
						}
						while (slmaxTail > slmaxHead && ((slmax[slmaxTail - 1] < val) ^ inv)) {
							--slmaxTail;
						}
						slmax[slmaxTail++] = val;
//						System.err.println("AFTER PUSHING " + val + ": " + Arrays.toString(Arrays.copyOfRange(slmax, slmaxHead, slmaxTail)));
						int newSlmaxHeadI = min(i / 2 + 1, 2 * i + 2 - (maxI & ~1));
						if (newSlmaxHeadI < 0) {
							newSlmaxHeadI = 0;
						}
						if ((newSlmaxHeadI & 1) != 0) {
							++newSlmaxHeadI;
						}
						if (newSlmaxHeadI != slmaxHeadI && newSlmaxHeadI != slmaxHeadI + 2 && newSlmaxHeadI != slmaxHeadI + 4) {
							throw new AssertionError();
						}
						while (newSlmaxHeadI != slmaxHeadI) {
							if (slmax[slmaxHead] == a[pos + slmaxHeadI * step]) {
								++slmaxHead;
							}
							slmaxHeadI += 2;
						}
					} else {
//						System.err.println("CHECK " + i + " AGAINST " + slmaxHeadI + ".." + (i - 1) + " " + Arrays.toString(Arrays.copyOfRange(slmax, slmaxHead, slmaxTail)));
						if ((val < slmax[slmaxHead]) ^ inv) {
							return true;
						}
						while (slminTail > slminHead && ((slmin[slminTail - 1] > val) ^ inv)) {
							--slminTail;
						}
						slmin[slminTail++] = val;
//						System.err.println("AFTER PUSHING " + val + ": " + Arrays.toString(Arrays.copyOfRange(slmin, slminHead, slminTail)));
						int newSlminHeadI = min(i / 2 + 1, 2 * i + 2 - (((maxI + 1) & ~1) - 1));
						if (newSlminHeadI < 0) {
							newSlminHeadI = 0;
						}
						if ((newSlminHeadI & 1) == 0) {
							++newSlminHeadI;
						}
						if (newSlminHeadI != slminHeadI && newSlminHeadI != slminHeadI + 2 && newSlminHeadI != slminHeadI + 4) {
							throw new AssertionError();
						}
						while (newSlminHeadI != slminHeadI) {
							if (slmin[slminHead] == a[pos + slminHeadI * step]) {
								++slminHead;
							}
							slminHeadI += 2;
						}
					}
				}
			}
		}
		return false;
	}
	
//	static boolean solveDumb(int a[]) {
//		int n = a.length;
//		for (int step = 1; step < n; step++) {
//			for (int pos = 0; pos + 2 * step < n; pos++) {
//				int x = a[pos];
//				int y = a[pos + step];
//				int z = a[pos + 2 * step];
//				if ((x < y && y < z) || (x > y && y > z)) {
//					return true;
//				}
//			}
//		}
//		return false;
//	}
	
//	static void strest() {
//		Random rng = new Random(42);
//		for (int test = 0;; test++) {
//			int n = rng.nextInt(30) + 1;
//			int a[] = new int[n];
//			boolean seen[] = new boolean[n];
//			for (int i = 0; i < n; i++) {
//				int x;
//				do {
//					x = rng.nextInt(n);
//				} while (seen[x]);
//				seen[x] = true;
//				a[i] = x;
//			}
//			if (solve(a) != solveDumb(a)) {
//				System.err.println("FAIL");
//				System.err.println(Arrays.toString(a));
//				System.err.println(solve(a));
//				System.err.println(solveDumb(a));
//				exit(1);
//			}
//			if (test % 100000 == 99999) {
//				System.err.println("PASS");
//			}
//		}
//	}
	
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
//			strest();
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