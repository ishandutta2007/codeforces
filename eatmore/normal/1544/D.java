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
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), a[] = new int[n], cnt[] = new int[n], ans = n;
			for (int i = 0; i < n; i++) {
				++cnt[a[i] = scanInt() - 1];
			}
			int p1, p2, p3;
			for (p1 = 0; p1 < n && cnt[p1] != 0; p1++) { }
			for (p2 = 0; p2 < n && cnt[a[p2]] == 1; p2++) { }
			for (p3 = p2 + 1; p3 < n && cnt[a[p3]] == 1; p3++) { }
			while (p1 < n) {
				int c = p1 == p2 ? p3 : p2;
				--cnt[a[c]];
				++cnt[a[c] = p1];
				for (; p1 < n && cnt[p1] != 0; p1++) { }
				for (; p2 < n && cnt[a[p2]] == 1; p2++) { }
				if (p3 <= p2) {
					p3 = p2 + 1;
				}
				for (; p3 < n && cnt[a[p3]] == 1; p3++) { }
				--ans;
			}
			out.println(ans);
			for (int i = 0; i < n; i++) {
				out.print((a[i] + 1) + " ");
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