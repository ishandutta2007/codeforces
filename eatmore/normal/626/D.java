import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.PI;
import static java.lang.Math.cos;
import static java.lang.Math.scalb;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		double v1[] = new double[2 * N];
		double v2[] = new double[2 * N];
		for (int i = 0; i < n; i++) {
			int a = nextInt();
			++v1[a << 1];
			++v2[((-a) & (N - 1)) << 1];
		}
		convolve(v1, v2);
		v1[0] = 0;
		for (int i = N / 2; i < N; i++) {
			v1[i << 1] = 0;
		}
		fill(v2, 0);
		for (int i = 0; i < N; i++) {
			v2[((-i) & (N - 1)) << 1] = v1[i << 1];
		}
		fftR(v1);
		fftR(v2);
		amul(v1, v1, v1);
		amul(v1, v2, v1);
		fftIR(v1);
		double ans = 0, total = 0;
		for (int i = 0; i < N; i++) {
			total += v1[i << 1];
			if (i >= N / 2) {
				ans += v1[i << 1];
			}
		}
		out.printf(Locale.US, "%.9f", ans / total);
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
	
	static final int BITS = 16;
	static final int N = 1 << BITS;
	static final double NI = scalb(1.0, -BITS);

	static final double GENPOWS[] = new double[1 << (BITS - 1)];
	static {
		double step = scalb(PI, -(BITS - 1));
		GENPOWS[0] = 1;
		GENPOWS[1] = 0;
		for (int i = 1; i < 1 << (BITS - 2); i++) {
			double val = cos(step * i);
			GENPOWS[Integer.reverse(i) >>> (32 - (BITS - 1))] = val;
			GENPOWS[Integer.reverse(-i) >>> (32 - (BITS - 1))] = -val;
		}
	}

	static void fftR(double data[]) {
		for (int bit = BITS - 1; bit > 0; bit--) {
			for (int iHigh = 0; iHigh < N << 1; iHigh += 1 << (bit + 2)) {
				for (int i = iHigh; i < iHigh + (1 << bit); i += 2) {
					int j = i ^ (1 << (bit + 1));
					double aR = data[i], aI = data[i + 1];
					double bR = data[j], bI = data[j + 1];
					data[i] = aR + bR; data[i + 1] = aI + bI;
					data[j] = aR - bR; data[j + 1] = aI - bI;
				}
				double gen = GENPOWS[iHigh >> (bit + 1)];
				double gen2 = GENPOWS[(iHigh >> (bit + 1)) + 1];
				for (int i = iHigh + (1 << bit); i < iHigh + (1 << (bit + 1)); i += 2) {
					int j = i ^ (1 << (bit + 1));
					double aR = data[i], aI = data[i + 1];
					double bR = data[j], bI = data[j + 1];
					double sR = aR + bR, sI = aI + bI;
					double dR = aR - bR, dI = aI - bI;
					data[i] = sR * gen + sI * gen2; data[i + 1] = sI * gen - sR * gen2;
					data[j] = dR * gen2 - dI * gen; data[j + 1] = dR * gen + dI * gen2;
				}
			}
		}
		for (int i = 0; i < N << 1; i += 4) {
			double aR = data[i], aI = data[i + 1];
			double bR = data[i + 2], bI = data[i + 3];
			data[i] = aR + bR; data[i + 1] = aI + bI;
			data[i + 2] = aR - bR; data[i + 3] = aI - bI;
		}
	}
	
	static void fftIR(double data[]) {
		for (int bit = 0; bit < BITS - 1; bit++) {
			for (int iHigh = 0; iHigh < N << 1; iHigh += 1 << (bit + 2)) {
				double gen = GENPOWS[iHigh >> (bit + 2)];
				double gen2 = GENPOWS[(iHigh >> (bit + 2)) + 1];
				for (int i = iHigh; i < iHigh + (1 << (bit + 1)); i += 2) {
					int j = i ^ (1 << (bit + 1));
					double aR = data[i], aI = data[i + 1];
					double bR = data[j], bI = data[j + 1];
					data[i] = aR + bR; data[i + 1] = aI + bI;
					double dR = aR - bR, dI = aI - bI;
					data[j] = dR * gen - dI * gen2; data[j + 1] = dR * gen2 + dI * gen;
				}
				iHigh += 1 << (bit + 2);
				for (int i = iHigh; i < iHigh + (1 << (bit + 1)); i += 2) {
					int j = i ^ (1 << (bit + 1));
					double aR = data[i], aI = data[i + 1];
					double bR = data[j], bI = data[j + 1];
					data[i] = aR + bR; data[i + 1] = aI + bI;
					double dR = aR - bR, dI = aI - bI;
					data[j] = dR * gen2 + dI * gen; data[j + 1] = dI * gen2 - dR * gen;
				}
			}
		}
		for (int i = 0; i < N; i += 2) {
			int j = i ^ N;
			double aR = data[i], aI = data[i + 1];
			double bR = data[j], bI = data[j + 1];
			data[i] = (aR + bR) * NI; data[i + 1] = (aI + bI) * NI;
			data[j] = (aR - bR) * NI; data[j + 1] = (aI - bI) * NI;
		}
	}
	
	static void amul(double a[], double b[], double res[]) {
		for (int i = 0; i < N << 1; i += 2) {
			double aR = a[i], aI = a[i + 1];
			double bR = b[i], bI = b[i + 1];
			res[i] = aR * bR - aI * bI; res[i + 1] = aR * bI + aI * bR;
		}
	}
	
	static double[] convolve(double a[], double b[]) {
		fftR(a);
		fftR(b);
		amul(a, b, a);
		fftIR(a);
		return a;
	}
}