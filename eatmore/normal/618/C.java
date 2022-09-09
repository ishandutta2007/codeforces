import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
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
	
	static long vmul(int x1, int y1, int x2, int y2) {
		return (long) y2 * x1 - (long) x2 * y1;
	}
	
	static long sqr(int a) {
		return (long) a * a;
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		final int x[] = new int[n];
		final int y[] = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
			y[i] = nextInt();
		}
		int minI = 0;
		for (int i = 1; i < n; i++) {
			if (x[i] < x[minI] || (x[i] == x[minI] && y[i] < y[minI])) {
				minI = i;
			}
		}
		int minI2 = -1;
		for (int i = 0; i < n; i++) {
			if (i == minI) {
				continue;
			}
			if (minI2 < 0) {
				minI2 = i;
				continue;
			}
			long vmul = vmul(x[minI2] - x[minI], y[minI2] - y[minI], x[i] - x[minI], y[i] - y[minI]);
			long distI = sqr(x[i] - x[minI]) + sqr(y[i] - y[minI]);
			long distMin = sqr(x[minI2] - x[minI]) + sqr(y[minI2] - y[minI]);
			if (vmul < 0 || (vmul == 0 && distI < distMin)) {
				minI2 = i;
			}
		}
		int minI3 = -1;
		for (int i = 0; i < n; i++) {
			long vmul = vmul(x[minI2] - x[minI], y[minI2] - y[minI], x[i] - x[minI], y[i] - y[minI]);
			if (vmul == 0) {
				continue;
			}
			if (vmul < 0) {
				throw new AssertionError();
			}
			if (minI3 < 0) {
				minI3 = i;
				continue;
			}
			long vmul2 = vmul(x[minI2] - x[minI], y[minI2] - y[minI], x[minI3] - x[minI], y[minI3] - y[minI]);
			if (vmul < vmul2) {
				minI3 = i;
			}
		}
		out.print((minI + 1) + " " + (minI2 + 1) + " " + (minI3 + 1));
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