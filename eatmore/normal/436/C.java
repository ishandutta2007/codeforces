import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

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
		int m = nextInt();
		int k = nextInt();
		int w = nextInt();
		long data[][] = new long[k][(n * m + 9) / 10];
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				String l = next();
				for (int jj = 0; jj < m; jj++) {
					char c = l.charAt(jj);
					int code = c == '.' ? 0 : (c >= 'A' && c <= 'Z') ? c - 'A' + 1 : c - 'a' + 27;
					data[i][(m * j + jj) / 10] |= (long) code << (6 * ((m * j + jj) % 10));
				}
			}
		}
		int ans = 0;
		int elems[] = new int[k];
		int types[] = new int[k];
		boolean elemHave[] = new boolean[k];
		int elemCost[] = new int[k];
		int elemType[] = new int[k];
		fill(elemCost, n * m);
		for (int i = 0; i < k; i++) {
			int cans = Integer.MAX_VALUE;
			int celem = -1;
			for (int j = 0; j < k; j++) {
				if (!elemHave[j] && cans > elemCost[j]) {
					cans = elemCost[j];
					celem = j;
				}
			}
			ans += cans;
			elemHave[celem] = true;
			elems[i] = celem;
			types[i] = elemType[celem];
//			System.err.println("Take " + (celem + 1) + " for " + cans);
			for (int j = 0; j < k; j++) {
				if (elemHave[j]) {
					continue;
				}
				long a1[] = data[j];
				long a2[] = data[celem];
				int ccans = 0;
				for (int jj = 0; jj < a1.length; jj++) {
					long v = a1[jj] ^ a2[jj];
//					System.err.println(Long.toOctalString(v));
					ccans += Long.bitCount((v | (v >> 1) | (v >> 2) | (v >> 3) | (v >> 4) | (v >> 5)) & 0x0041041041041041L);
				}
//				System.err.println("Diff between " + (j + 1) + " and " + (celem + 1) + " is " + ccans);
				if (ccans * w < elemCost[j]) {
					elemCost[j] = ccans * w;
					elemType[j] = celem + 1;
				}
			}
		}
		out.println(ans);
		for (int i = 0; i < k; i++) {
			out.println((elems[i] + 1) + " " + types[i]);
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