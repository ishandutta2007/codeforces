import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		int n = nextInt();
		int c = nextInt();
		int p[] = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt();
		}
		int s[] = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = nextInt();
		}
		long ans = 0;
		long pipe[] = new long[n];
		int pipeSize = 0;
		for (int i = 0; i < n; i++) {
			ans += s[i];
			long have = p[i] - s[i];
			int p1 = pipeSize;
			int p2 = pipeSize + 1;
			while (true) {
				while (p1 > 0 && have <= pipe[p1 - 1] * (p2 - p1)) {
					--p1;
					have += pipe[p1];
				}
				if (have < 0) {
					while (p2 > 1) {
						--p2;
						have -= pipe[p2] = max(pipe[p2 - 1] - c, 0);
					}
					pipe[0] = 0;
					ans += have;
					break;
				}
				if (p1 < p2 - 1 && have < (pipe[p2 - 2] - c) * (p2 - p1)) {
					--p2;
					have -= pipe[p2] = pipe[p2 - 1] - c;
				} else {
					for (int j = p1; j < p2; j++) {
						pipe[j] = (have + j - p1) / (p2 - p1);
					}
					break;
				}
			}
			++pipeSize;
		}
		out.print(ans);
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