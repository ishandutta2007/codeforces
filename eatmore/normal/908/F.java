import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static void solve() throws Exception {
		int n = scanInt();
		long pos[] = new long[n];
		char color[] = new char[n];
		for (int i = 0; i < n; i++) {
			pos[i] = scanInt();
			color[i] = scanString().charAt(0);
		}
		long ans = 0;
		long lastR = -1, lastB = -1;
		int i;
		for (i = 0; i < n; i++) {
			if (color[i] != 'B') {
				if (lastR >= 0) {
					ans += pos[i] - lastR;
				}
				lastR = pos[i];
			}
			if (color[i] != 'R') {
				if (lastB >= 0) {
					ans += pos[i] - lastB;
				}
				lastB = pos[i];
			}
			if (color[i] == 'G') {
				break;
			}
		}
		while (i < n) {
			long gapR = 0, gapB = 0, spos = pos[i];
			for (i++; i < n; i++) {
				if (color[i] != 'B') {
					gapR = max(gapR, pos[i] - lastR);
					ans += pos[i] - lastR;
					lastR = pos[i];
				}
				if (color[i] != 'R') {
					gapB = max(gapB, pos[i] - lastB);
					ans += pos[i] - lastB;
					lastB = pos[i];
				}
				if (color[i] == 'G') {
					ans += min(0, pos[i] - spos - gapR - gapB);
					break;
				}
			}
		}
		out.print(ans);
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