import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		sort(a);
//		System.err.println(Arrays.toString(a));
		long sums[] = new long[n + 1];
		for (int i = 0; i < n; i++) {
			sums[i + 1] = sums[i] + a[i];
		}
		long bestNum = 0, bestDen = 1;
		int bestMid = 0, bestCount = 0;
		for (int mid = 0; mid <= 2 * n - 2; mid++) {
			long medianNum, medianDen;
			int bottom = mid / 2, top = (mid + 1) / 2;
			if (mid % 2 == 0) {
				medianNum = a[bottom];
				medianDen = 1;
			} else {
				medianNum = a[bottom] + a[top];
				medianDen = 2;
			}
//			System.err.println("Point " + mid);
			int l = 0;
			int r = min(bottom, n - top - 1);
			while (l < r) {
				int m = (l + r) >>> 1;
				long averageNum = medianNum + sums[bottom] - sums[bottom - m] + sums[n] - sums[n - m];
				long averageDen = medianDen + 2 * m;
				long nextNum = a[bottom - m - 1] + a[n - m - 1];
				long nextDen = 2;
//				System.err.println("Count " + m +
//					": average " + averageNum + "/" + averageDen +
//					", next " + nextNum + "/" + nextDen);
				if (nextNum * averageDen < averageNum * nextDen) {
					r = m;
				} else {
					l = m + 1;
				}
			}
			int m = l;
			long averageNum = medianNum + sums[bottom] - sums[bottom - m] + sums[n] - sums[n - m];
			long averageDen = medianDen + 2 * m;
			long diffNum = averageNum * medianDen - medianNum * averageDen;
			long diffDen = averageDen * medianDen;
//			System.err.println("At point " + mid +
//				": median " + medianNum + "/" + medianDen +
//				", count " + m +
//				", average: " + averageNum + "/" + averageDen +
//				", difference: " + diffNum + "/" + diffDen);
			if (bestNum * diffDen < diffNum * bestDen) {
				bestNum = diffNum;
				bestDen = diffDen;
				bestMid = mid;
				bestCount = m;
			}
		}
		out.println(2 * bestCount + bestMid % 2 + 1);
		for (int i = 0; i <= bestCount + bestMid % 2; i++) {
			out.print(a[bestMid / 2 - bestCount + i] + " ");
		}
		for (int i = 0; i < bestCount; i++) {
			out.print(a[n - bestCount + i] + " ");
		}
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