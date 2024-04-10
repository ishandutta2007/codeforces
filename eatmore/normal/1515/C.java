import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class C {

	static class Token implements Comparable<Token> {
		final int i, h;

		Token(int i, int h) {
			this.i = i;
			this.h = h;
		}

		public int compareTo(Token o) {
			return h - o.h;
		}
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), m = scanInt();
			scanInt();
			PriorityQueue<Token> pq = new PriorityQueue<>();
			int h[] = new int[m];
			int ans[] = new int[n];
			for (int i = 0; i < m; i++) {
				pq.add(new Token(i, 0));
			}
			for (int i = 0; i < n; i++) {
				Token cur = pq.remove();
				pq.add(new Token(cur.i, h[cur.i] += scanInt()));
				ans[i] = cur.i;
			}
			out.println("YES");
			for (int i = 0; i < n; i++) {
				out.print((ans[i] + 1) + " ");
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