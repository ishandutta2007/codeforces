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
import java.util.Locale;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
//	static final Random rng = new Random(42);
	
	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
//		int n = 200000;
//		int k = 50;
//		int n = rng.nextInt(30) + 1;
//		int k = rng.nextInt(n) + 1;
		int t[] = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextInt();
//			t[i] = 1;
//			t[i] = rng.nextInt(20) + 1;
		}
		out.printf(Locale.US, "%.9f", solveSmart(n, k, t));
//		double expected = solveDumb(n, k, t);
//		double actual = solveSmart(n, k, t);
//		if (abs(expected - actual) > 1e-3) {
//			System.err.println(n + " " + k);
//			System.err.println(Arrays.toString(t));
//			throw new AssertionError();
//		}
//		System.err.println("PASS");
	}
	
//	static double solveDumb(int n, int k, int t[]) {
//		double dyn[] = new double[n + 1];
//		fill(dyn, 1, n + 1, Double.POSITIVE_INFINITY);
//		double ndyn[] = new double[n + 1];
//		for (int i = 0; i < k; i++) {
//			fill(ndyn, Double.POSITIVE_INFINITY);
//			for (int j = 0; j < n; j++) {
//				double cur = dyn[j];
//				double sum = 0;
//				for (int jj = j; jj < n; jj++) {
//					sum += t[jj];
//					cur += sum / t[jj];
//					ndyn[jj + 1] = min(ndyn[jj + 1], cur);
//				}
//			}
//			double tt[] = dyn;
//			dyn = ndyn;
//			ndyn = tt;
//		}
//		return dyn[n];
//	}
	
	static int t[];
	static double sums[], sumsI[], anss[];
	
	static double solveSmart(int n, int k, int t[]) {
		C.t = t;
		sums = new double[n + 1];
		sumsI = new double[n + 1];
		anss = new double[n + 1];
		for (int i = 0; i < n; i++) {
			sums[i + 1] = sums[i] + t[i];
			sumsI[i + 1] = sumsI[i] + 1.0 / t[i];
			anss[i + 1] = anss[i] + sums[i + 1] / t[i];
		}
		double dyn[] = new double[n + 1];
		fill(dyn, 1, n + 1, Double.POSITIVE_INFINITY);
		double ndyn[] = new double[n + 1];
		for (int i = 0; i < k; i++) {
//			System.err.println("ITER");
			rec(dyn, i, n - 1, ndyn, i + 1, n);
			double tt[] = dyn;
			dyn = ndyn;
			ndyn = tt;
//			System.err.println(Arrays.toString(Arrays.copyOfRange(dyn, i + 1, n + 1)));
		}
		return dyn[n];
	}
	
	static void rec(double dyn[], int dynFrom, int dynTo, double ndyn[], int ndynFrom, int ndynTo) {
		int ndynPos = (ndynFrom + ndynTo) >>> 1;
		double ans = Double.POSITIVE_INFINITY;
		int ansPos = Integer.MIN_VALUE;
		for (int dynPos = dynFrom; dynPos <= dynTo; dynPos++) {
			double cans = dyn[dynPos] + (anss[ndynPos] - anss[dynPos] - sums[dynPos] * (sumsI[ndynPos] - sumsI[dynPos]));
			if (ans > cans) {
				ans = cans;
				ansPos = dynPos;
			}
		}
//		System.err.println(ndynPos + " <- " + ansPos + ": " + ans);
		ndyn[ndynPos] = ans;
		if (ndynFrom < ndynPos) {
			rec(dyn, dynFrom, ansPos, ndyn, ndynFrom, ndynPos - 1);
		}
		if (ndynPos < ndynTo) {
			rec(dyn, ansPos, dynTo, ndyn, ndynPos + 1, ndynTo);
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