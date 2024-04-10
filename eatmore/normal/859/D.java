import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int n = scanInt();
		int m = 1 << n;
		double prob[][] = new double[m][m];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				prob[i][j] = scanInt() / 100.0;
			}
		}
		double cprob[] = new double[m];
		fill(cprob, 1);
		double res[] = new double[m];
		for (int level = 0; level < n; level++) {
			double ncprob[] = new double[m];
			double nres[] = new double[m];
			for (int i = 0; i < m; i += 2 << level) {
				int s = 1 << level;
				double max1 = 0, max2 = 0;
				for (int j = i; j < i + s; j++) {
					for (int k = i; k < i + s; k++) {
						ncprob[j] += cprob[k + s] * prob[j][k + s];
						ncprob[j + s] += cprob[k] * prob[j + s][k];
					}
					ncprob[j] *= cprob[j];
					ncprob[j + s] *= cprob[j + s];
					max1 = max(max1, res[j]);
					max2 = max(max2, res[j + s]);
				}
				for (int j = i; j < i + s; j++) {
					nres[j] = res[j] + max2 + ncprob[j] * (1 << level);
					nres[j + s] = res[j + s] + max1 + ncprob[j + s] * (1 << level);
				}
			}
			cprob = ncprob;
			res = nres;
		}
		double ans = 0;
		for (int i = 0; i < m; i++) {
			ans = max(ans, res[i]);
		}
		out.printf(Locale.US, "%.9f", ans);
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}