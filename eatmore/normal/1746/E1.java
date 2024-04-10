import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void solve() throws Exception {
		int dyn[][] = new int[11][11];
		int dynW[][] = new int[11][11];
		int dynB[][] = new int[11][11];
		for (int both = 3; both < 11; both++) {
			for (int white = 0; white <= both; white++) {
				int black = both - white;
				int cans = Integer.MAX_VALUE / 2, swhite = -1, sblack = -1;
				for (int cwhite = 0; cwhite <= white; cwhite++) {
					for (int cblack = 0; cblack <= both - white; cblack++) {
						int cboth = cwhite + cblack;
						if ((cblack == 0 && both - cboth >= white) ||
							(cblack == black && cboth >= white)) {
							continue;
						}
						int ccans = max(dyn[cblack + white][cboth], dyn[black - cblack + white][both - cboth]);
						if (ccans < cans) {
							cans = ccans;
							swhite = cwhite;
							sblack = cblack;
						}
					}
				}
				dyn[both][white] = cans + 1;
				dynW[both][white] = swhite;
				dynB[both][white] = sblack;
			}
		}
		int n = scanInt();
		int whiteSet[] = new int[n], blackSet[] = new int[n];
		int whiteLen = n, blackLen = 0;
		for (int i = 0; i < n; i++) {
			whiteSet[i] = i + 1;
		}
		int tempSet[] = new int[n];
		while (whiteLen + blackLen > 2) {
			int cwhite, cblack;
			if (whiteLen + blackLen > 10) {
				cwhite = whiteLen / 2;
				cblack = (blackLen + 1) / 2;
			} else {
				cwhite = dynW[whiteLen + blackLen][whiteLen];
				cblack = dynB[whiteLen + blackLen][whiteLen];
			}
			out.print("? " + (cwhite + cblack));
			for (int i = 0; i < cwhite; i++) {
				out.print(" " + whiteSet[i]);
			}
			for (int i = 0; i < cblack; i++) {
				out.print(" " + blackSet[i]);
			}
			out.println();
			out.flush();
			if ("YES".equals(scanString())) {
				arraycopy(whiteSet, cwhite, tempSet, 0, whiteLen - cwhite);
				arraycopy(blackSet, 0, whiteSet, cwhite, cblack);
				int t[] = blackSet;
				blackSet = tempSet;
				tempSet = t;
				blackLen = whiteLen - cwhite;
				whiteLen = cwhite + cblack;
			} else {
				arraycopy(whiteSet, cwhite, tempSet, 0, whiteLen - cwhite);
				arraycopy(blackSet, cblack, tempSet, whiteLen - cwhite, blackLen - cblack);
				int t[] = blackSet;
				blackSet = whiteSet;
				whiteSet = tempSet;
				tempSet = t;
				whiteLen = whiteLen - cwhite + blackLen - cblack;
				blackLen = cwhite;
			}
		}
		for (int i = 0; i < whiteLen; i++) {
			out.println("! " + whiteSet[i]);
			out.flush();
			if (":)".equals(scanString())) {
				return;
			}
		}
		for (int i = 0; i < blackLen; i++) {
			out.println("! " + blackSet[i]);
			out.flush();
			if (":)".equals(scanString())) {
				return;
			}
		}
		throw new AssertionError();
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