import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.min;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static long sqr(long a) {
		return a * a;
	}

	static void solve() throws Exception {
		int tests = scanInt();
		boolean dyn[] = new boolean[100 * 100 + 1];
		boolean ndyn[] = new boolean[100 * 100 + 1];
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), a[] = new int[n], b[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = scanInt();
			}
			for (int i = 0; i < n; i++) {
				b[i] = scanInt();
			}
			fill(dyn, false);
			dyn[0] = true;
			int sum = 0;
			long ans = 0;
			for (int i = 0; i < n; i++) {
				int v = a[i];
				fill(ndyn, 0, v, false);
				arraycopy(dyn, 0, ndyn, v, ndyn.length - v);
				v = b[i];
				for (int j = 0; j < ndyn.length - v; j++) {
					ndyn[j + v] |= dyn[j];
				}
				sum += a[i] + b[i];
				ans += sqr(a[i]) + sqr(b[i]);
				boolean t[] = dyn;
				dyn = ndyn;
				ndyn = t;
			}
			int dif = sum;
			for (int i = 0; i < dyn.length; i++) {
				if (dyn[i]) {
					dif = min(dif, abs(sum - 2 * i));
				}
			}
			ans = ans * (n - 2) + (sqr(sum) + sqr(dif)) / 2;
			out.println(ans);
		}
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