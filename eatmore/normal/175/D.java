import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.lang.System.nanoTime;

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
	
	static void solve() throws Exception {
//		Random rng = new Random();
//		int hp1 = rng.nextInt(191) + 10, hp2 = rng.nextInt(191) + 10;
//		int dt1 = rng.nextInt(30) + 1, dt2 = rng.nextInt(30) + 1;
//		int l1 = rng.nextInt(91) + 10, l2 = rng.nextInt(91) + 10;
//		int r1 = rng.nextInt(91) + 10, r2 = rng.nextInt(91) + 10;
//		if (l1 > r1) { int t = l1; l1 = r1; r1 = t; }
//		if (l2 > r2) { int t = l2; l2 = r2; r2 = t; }
//		double pMiss1 = rng.nextDouble(), pMiss2 = rng.nextDouble();

		int hp1 = nextInt();
		int dt1 = nextInt();
		int l1 = nextInt();
		int r1 = nextInt();
		double pMiss1 = nextInt() / 100.0;
		double pFullHit1 = 1 - pMiss1;
		double pHit1 = pFullHit1 / (r1 - l1 + 1);
		int hp2 = nextInt();
		int dt2 = nextInt();
		int l2 = nextInt();
		int r2 = nextInt();
		double pMiss2 = nextInt() / 100.0;
		double pFullHit2 = 1 - pMiss2;
		double pHit2 = pFullHit2 / (r2 - l2 + 1);
		double p[][] = new double[hp1][hp2];
		double pWin1 = 0;
		double pWin2 = 0;
		long timeLimit = nanoTime() + 1800000000;
		long shots1 = 0;
		long shots2 = 0;
		p[hp1 - 1][hp2 - 1] = 1;
		do {
//			for (int i = 0; i < hp1; i++) {
//				for (int j = 0; j < hp2; j++) {
//					if (j > 0) {
//						System.err.print(' ');
//					}
//					System.err.printf(Locale.US, "%.2f", pCur[i][j]);
//				}
//				System.err.println();
//			}
			long nextTime1 = shots1 * dt1;
			long nextTime2 = shots2 * dt2;
			if (nextTime1 <= nextTime2) {
//				System.err.println("VASYA");
				for (int h1 = 0; h1 < hp1; h1++) {
					for (int h2 = 0; h2 < l1 && h2 < hp2; h2++) {
						pWin1 += pFullHit1 * p[h1][h2];
					}
					for (int h2 = l1; h2 < r1 && h2 < hp2; h2++) {
						pWin1 += pHit1 * p[h1][h2] * (r1 - h2);
					}
					double sum = 0;
					for (int i = l1; i <= r1 && i < hp2; i++) {
						sum += p[h1][i];
					}
					for (int h2 = 0; h2 < hp2; h2++) {
						p[h1][h2] = pMiss1 * p[h1][h2] + pHit1 * sum;
						if (h2 + l1 < hp2) {
							sum -= p[h1][h2 + l1];
							if (h2 + r1 + 1 < hp2) {
								sum += p[h1][h2 + r1 + 1];
							}
						}
					}
				}
				++shots1;
			} else {
//				System.err.println("OPPONENT");
				for (int h2 = 0; h2 < hp2; h2++) {
					for (int h1 = 0; h1 < l2 && h1 < hp1; h1++) {
						pWin2 += pFullHit2 * p[h1][h2];
					}
					for (int h1 = l2; h1 < r2 && h1 < hp1; h1++) {
						pWin2 += pHit2 * p[h1][h2] * (r2 - h1);
					}
					double sum = 0;
					for (int i = l2; i <= r2 && i < hp1; i++) {
						sum += p[i][h2];
					}
					for (int h1 = 0; h1 < hp1; h1++) {
						p[h1][h2] = pMiss2 * p[h1][h2] + pHit2 * sum;
						if (h1 + l2 < hp1) {
							sum -= p[h1 + l2][h2];
							if (h1 + r2 + 1 < hp1) {
								sum += p[h1 + r2 + 1][h2];
							}
						}
					}
				}
				++shots2;
			}
		} while (nanoTime() < timeLimit);
//		System.err.println(pWin1 + " " + pWin2);
		out.println(pWin1 > 1e-5 ? pWin1 / (pWin1 + pWin2) : pWin1);
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