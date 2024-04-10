import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static void solve() throws Exception {
		/*int n =*/ scanInt();
		/*int m =*/ scanInt();
		int nLad = scanInt();
		int nElev = scanInt();
		int v = scanInt();
		int lad[] = new int[nLad];
		for (int i = 0; i < nLad; i++) {
			lad[i] = scanInt() - 1;
		}
		int elev[] = new int[nElev];
		for (int i = 0; i < nElev; i++) {
			elev[i] = scanInt() - 1;
		}
		int q = scanInt();
		for (int qq = 0; qq < q; qq++) {
			int x1 = scanInt() - 1, y1 = scanInt() - 1,
				x2 = scanInt() - 1, y2 = scanInt() - 1;
			int res;
			if (x1 == x2) {
				res = abs(y1 - y2);
			} else {
				res = Integer.MAX_VALUE;
				if (nLad > 0) {
					int i = ~binarySearch(lad, y1);
					if (i > 0) {
						res = min(res, abs(y1 - lad[i - 1]) + abs(x1 - x2) + abs(y2 - lad[i - 1]));
					}
					if (i < nLad) {
						res = min(res, abs(y1 - lad[i]) + abs(x1 - x2) + abs(y2 - lad[i]));
					}
				}
				if (nElev > 0) {
					int i = ~binarySearch(elev, y1);
					if (i > 0) {
						res = min(res, abs(y1 - elev[i - 1]) + (abs(x1 - x2) + v - 1) / v + abs(y2 - elev[i - 1]));
					}
					if (i < nElev) {
						res = min(res, abs(y1 - elev[i]) + (abs(x1 - x2) + v - 1) / v + abs(y2 - elev[i]));
					}
				}
			}
			out.println(res);
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