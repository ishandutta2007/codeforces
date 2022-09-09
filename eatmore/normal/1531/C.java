import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int n = scanInt();
		if (n == 2) {
			out.print(-1);
			return;
		}
		int m = 0;
		while (m * m < n) {
			++m;
		}
		int k = m * m - n;
		boolean x = k == 2;
		if (x) {
			k = 4;
			out.println(m + 1);
			out.print('o');
			for (int i = 0; i < m; i++) {
				out.print('.');
			}
			out.println();
		} else {
			out.println(m);
		}
		for (int i = 0; i < m; i++) {
			int l1 = i == 0 ? m - (k + 1) / 2 :
				i == 1 && k > 0 && k % 2 == 0 ? m - 2 :
				i < (k + 1) / 2 ? m - 1 :
				x && i == m - 1 ? m + 1 : m;
			for (int j = 0; j < l1; j++) {
				out.print('o');
			}
			int l2 = x ? m + 1 : m;
			for (int j = l1; j < l2; j++) {
				out.print('.');
			}
			out.println();
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