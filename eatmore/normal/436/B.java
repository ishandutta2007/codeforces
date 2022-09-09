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

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		nextInt();
		int ans[] = new int[m];
		for (int i = 0; i < n; i++) {
			String l = next();
			for (int j = 0; j < m; j++) {
				switch (l.charAt(j)) {
				case '.':
				case 'D':
					break;
				case 'L':
					if (j - i >= 0) {
						++ans[j - i];
					}
					break;
				case 'R':
					if (j + i < m) {
						++ans[j + i];
					}
					break;
				case 'U':
					if ((i & 1) == 0) {
						++ans[j];
					}
					break;
				default:
					throw new AssertionError();
				}
			}
		}
		for (int i = 0; i < m; i++) {
			out.print(ans[i] + " ");
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