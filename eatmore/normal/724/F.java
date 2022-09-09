import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class F {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		int n = nextInt();
		int d = nextInt();
		int mod = nextInt();
		if (n == 1) {
			out.print('1');
			return;
		}
		int fracs[] = new int[d + 2];
		for (int i = 1; i < fracs.length; i++) {
			fracs[i] = BigInteger.valueOf(i).modInverse(BigInteger.valueOf(mod)).intValue();
		}
		int maxsize = n;
		int cnts[] = new int[maxsize + 1];
		cnts[1] = 1;
		int cnts2[][][] = new int[maxsize + 1][d + 1][maxsize + 1];
		cnts2[0][0][1] = 1;
		for (int lastsize = 0; lastsize < (n - 1) / 2; lastsize++) {
			int nlastsize = lastsize + 1;
			int ccnt = cnts[nlastsize];
			int ccnt2[][] = cnts2[lastsize];
			int ncnt2[][] = cnts2[nlastsize];
			for (int ctrees = 0; ctrees <= d; ctrees++) {
				for (int csize = 1; csize <= maxsize; csize++) {
					int cur = ccnt2[ctrees][csize];
//					if (cur != 0) {
//						System.err.println(csize + " " + ctrees + " " + lastsize + " -> " + cur);
//					}
					for (int i = 0, ntrees = ctrees, nsize = csize;
						ntrees <= d && nsize <= maxsize;
						++i, ++ntrees, nsize += nlastsize) {
						ncnt2[ntrees][nsize] += cur;
						if (ncnt2[ntrees][nsize] >= mod) {
							ncnt2[ntrees][nsize] -= mod;
						}
						cur = (int) ((long) cur * (ccnt + i) % mod * fracs[i + 1] % mod);
					}
				}
			}
			if (nlastsize + 1 <= maxsize) {
				cnts[nlastsize + 1] = ncnt2[d - 1][nlastsize + 1];
			}
		}
		int ans = 0;
		if (n % 2 == 0) {
			ans = (int) ((long) cnts[n / 2] * (cnts[n / 2] + 1) % mod * fracs[2] % mod);
		}
		ans = (ans + cnts2[(n - 1) / 2][d][n]) % mod;
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