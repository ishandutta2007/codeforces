import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

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

	static int value[];
	static int treeSub[], treeAdd[];

	static void treeFix(int i) {
		int s1 = treeSub[2 * i], a1 = treeAdd[2 * i];
		int s2 = treeSub[2 * i + 1], a2 = treeAdd[2 * i + 1];
		int rs, ra;
		if (s2 < a1) {
			rs = s1;
			ra = a1 - s2 + a2;
		} else {
			rs = s1 - a1 + s2;
			ra = a2;
		}
		treeSub[i] = rs;
		treeAdd[i] = ra;
	}

	static void solve() throws Exception {
		int n = nextInt();
		value = new int[n];
		treeSub = new int[2 * n];
		treeAdd = new int[2 * n];
		for (int i = 0; i < n; i++) {
			int p = nextInt() - 1;
			if (nextInt() == 0) {
				treeSub[n + p] = 1;
			} else {
				treeAdd[n + p] = 1;
				value[p] = nextInt();
			}
			for (int j = (n + p) >> 1; j > 0; j >>= 1) {
				treeFix(j);
			}
			int x = 2 * n, y = 0, toskip = 0;
			while (true) {
				if (x == n) {
					out.println(-1);
					break;
				} else if (y == 0 && treeAdd[x - 1] > toskip) {
					out.println(value[x - n - 1]);
					break;
				} else if ((x & ((1 << (y + 1)) - 1)) == 0 && x - (1 << (y + 1)) >= n && treeAdd[(x >> (y + 1)) - 1] <= toskip) {
					++y;
				} else if (x - (1 << y) < n || treeAdd[(x >> y) - 1] > toskip) {
					--y;
				} else {
					x -= 1 << y;
					toskip -= treeAdd[x >> y];
					toskip += treeSub[x >> y];
				}
			}
		}
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