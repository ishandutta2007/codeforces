import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

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
		int n = nextInt();
		int k = nextInt();
		int addr[] = new int[n];
		for (int i = 0; i < n; i++) {
			StringTokenizer tok = new StringTokenizer(next(), ".");
			int caddr = 0;
			for (int j = 0; j < 4; j++) {
				caddr = (caddr << 8) | (parseInt(tok.nextToken()) & 0xFF);
			}
			addr[i] = caddr;
		}
		sort(addr);
		for (int bits = 1; bits < 32; bits++) {
			int mask = -1 << -bits;
			int prev = addr[0] & mask;
			int cnt = 1;
			for (int i = 1; i < n; i++) {
				int cur = addr[i] & mask;
				if (cur != prev) {
					++cnt;
					prev = cur;
				}
			}
			if (cnt == k) {
				for (int i = 0; i < 4; i++) {
					if (i > 0) {
						out.print('.');
					}
					out.print((mask >> (8 * (3 - i))) & 0xFF);
				}
				return;
			}
		}
		out.print(-1);
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