import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), m = scanInt();
			char c[] = scanString().toCharArray();
			for (int i = 0;;) {
				while (i < n && c[i] == '1') {
					++i;
				}
				if (i == n) {
					break;
				}
				int j = i;
				while (j < n && c[j] == '0') {
					++j;
				}
				int cntL, cntR;
				if (i == 0) {
					cntL = 0;
					if (j == n) {
						cntR = 0;
					} else {
						cntR = min(m, j - i);
					}
				} else {
					if (j == n) {
						cntL = min(m, j - i);
						cntR = 0;
					} else {
						cntL = cntR = min(m, (j - i) / 2);
					}
				}
				fill(c, i, i + cntL, '1');
				fill(c, j - cntR, j, '1');
				i = j;
			}
			out.println(c);
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