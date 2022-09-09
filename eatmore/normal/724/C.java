import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
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

	static void solve() throws Exception {
		int w = nextInt();
		int h = nextInt();
		long ca = w, cb = h, maw = 1, mah = 0, mbw = 0, mbh = 1;
		while (cb != 0) {
			long q = ca / cb;
			ca = ca % cb;
			maw -= q * mbw;
			mah -= q * mbh;
			long t = ca; ca = cb; cb = t;
			t = maw; maw = mbw; mbw = t;
			t = mah; mah = mbh; mbh = t;
		}
		// ca == gcd(w, h) == maw*w + mah*h
		long sw = w / ca, sh = h / ca;
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int y = nextInt();
			long time = Long.MAX_VALUE;
			for (int d = 0; d < 4; d++) {
				// 2*w*i + x == 2*h*j + y
				if ((y - x) % (2 * ca) == 0) {
					long m = (y - x) / (2 * ca);
					long mw = m * maw;
					long mh = -m * mah;
					long q = min(mw / sh, mh / sw);
					mw -= sh * q;
					mh -= sw * q;
					if (mw < 0 || mh < 0) {
						mw += sh;
						mh += sw;
					}
					if (mw < 0 || mh < 0 || 2 * w * mw + x != 2 * h * mh + y) {
						throw new AssertionError();
					}
					time = min(time, 2 * w * mw + x);
				}
				x = 2 * w - x;
				if (d == 1) {
					y = 2 * h - y;
				}
			}
			out.println(time == Long.MAX_VALUE ? -1 : time);
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