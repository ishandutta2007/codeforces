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

public class D {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		int n = nextInt();
		int tree[] = new int[3 * 30 * (n + 1)];
		tree[1] = tree[2] = -1;
		int free = 3;
		for (int i = 0; i < n; i++) {
			int cur = nextInt();
			int cNode = 0;
			for (int j = 30 - Integer.numberOfLeadingZeros(cur); j >= 0; j--) {
				int bit = (cur >> j) & 1;
				int nNode = tree[cNode + 1 + bit];
				if (nNode < 0) {
					tree[free + 1] = tree[free + 2] = -1;
					tree[cNode + 1 + bit] = nNode = free;
					free += 3;
				}
				cNode = nNode;
				++tree[cNode];
			}
		}
		cur: for (int i = 0, cur = 1; i < n; cur++) {
			int cNode = 0;
			for (int j = 30 - Integer.numberOfLeadingZeros(cur); j >= 0; j--) {
				int bit = (cur >> j) & 1;
				int nNode = tree[cNode + 1 + bit];
				if (nNode < 0 || tree[nNode] == 0) {
					cur |= (1 << j) - 1;
					continue cur;
				}
				cNode = nNode;
			}
			cNode = 0;
			for (int j = 30 - Integer.numberOfLeadingZeros(cur); j >= 0; j--) {
				int bit = (cur >> j) & 1;
				int nNode = tree[cNode + 1 + bit];
				cNode = nNode;
				--tree[cNode];
			}
			if (i > 0) {
				out.print(' ');
			}
			out.print(cur);
			++i;
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