import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int l = nextInt();
		int k = nextInt();
		double p[] = new double[n];
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = (double) nextInt() / 100;
		}
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int maxPrize[] = new int[n + 1];
		for (int i = n - 1; i >= 0; i--) {
			maxPrize[i] = maxPrize[i + 1];
			if (a[i] < 0) {
				++maxPrize[i];
			}
		}
		int totalPrize = maxPrize[0];
		double dyn[][] = new double[n + 1][2 * totalPrize + 1];
		double newDyn[][] = new double[n + 1][2 * totalPrize + 1];
		dyn[0][totalPrize + min(k, totalPrize)] = 1;
		for (int i = 0; i < n; i++) {
			for (double tmp[]: newDyn) {
				fill(tmp, 0);
			}
			double curP = p[i];
			int curA = a[i];
			int curMax = maxPrize[i];
			int nextMax = maxPrize[i + 1];
			for (int j = 0; j <= i; j++) {
				for (int ballance = -totalPrize; ballance <= curMax; ballance++) {
					double curDyn = dyn[j][totalPrize + ballance];
					if (curDyn == 0) {
						continue;
					}
					int newBallance = min(ballance + curA, nextMax);
					newDyn[j + 1][totalPrize + min(newBallance, nextMax)] += curP * curDyn;
					newDyn[j][totalPrize + min(ballance, nextMax)] += (1 - curP) * curDyn;
				}
			}
			double tmp[][] = dyn;
			dyn = newDyn;
			newDyn = tmp;
		}
		double ans = 0;
		for (int i = l; i <= n; i++) {
			ans += dyn[i][totalPrize];
		}
		out.printf(Locale.US, "%.12f\n", ans);
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