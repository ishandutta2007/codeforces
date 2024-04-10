import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		long shifts[] = new long[60];
		int q = scanInt();
		for (int qq = 0; qq < q; qq++) {
			int qt = scanInt();
			long x = scanLong();
			int level = 63 - Long.numberOfLeadingZeros(x);
			switch (qt) {
			case 1:
			case 2:
				long k = -scanLong();
				shifts[level] += k;
				if (qt == 2) {
					for (++level, k <<= 1; level < 60; ++level, k <<= 1) {
						shifts[level] += k;
					}
				}
				break;
			case 3:
				long pos = x - shifts[level];
				do {
					out.print((1L << level) + ((pos + shifts[level]) & ((1L << level) - 1)));
					out.print(' ');
					pos >>= 1;
				} while (--level >= 0);
				out.println();
				break;
			default:
				throw new AssertionError();
			}
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