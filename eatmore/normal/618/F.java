import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

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
		int b[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}
		int posI[] = new int[2 * n];
		int posJ[] = new int[2 * n];
		fill(posI, -1);
		for (int i = 0, j = 0, sum = n;;) {
			if (posI[sum] >= 0) {
				out.println(i - posI[sum]);
				for (int k = posI[sum]; k < i; k++) {
					out.print((k + 1) + " ");
				}
				out.println();
				out.println(j - posJ[sum]);
				for (int k = posJ[sum]; k < j; k++) {
					out.print((k + 1) + " ");
				}
				return;
			}
			posI[sum] = i;
			posJ[sum] = j;
			if (sum >= n) {
				sum -= b[j++];
			} else {
				sum += a[i++];
			}
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