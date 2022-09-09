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
		int n = scanInt();
		int ans[] = new int[2 * n - 2], ansCnt = 0, cntOdd = 0;
		boolean odd[] = new boolean[n];
		out.println("? 1");
		out.flush();
		for (int i = 0; i < n; i++) {
			int d = scanInt();
			if (d % 2 != 0) {
				odd[i] = true;
				++cntOdd;
			}
			if (d == 1) {
				ans[ansCnt++] = 0;
				ans[ansCnt++] = i;
			}
		}
		boolean choice = cntOdd < (n + 1) / 2;
		for (int i = 1; i < n; i++) {
			if (odd[i] == choice) {
				out.println("? " + (i + 1));
				out.flush();
				for (int j = 0; j < n; j++) {
					int d = scanInt();
					if (d == 1 && j != 0) {
						ans[ansCnt++] = i;
						ans[ansCnt++] = j;
					}
				}
			}
		}
		out.println("!");
		for (int i = 0; i < ansCnt; i += 2) {
			out.println((ans[i] + 1) + " " + (ans[i + 1] + 1));
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