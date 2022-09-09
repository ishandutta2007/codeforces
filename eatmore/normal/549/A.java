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

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		char d[][] = new char[n][];
		for (int i = 0; i < n; i++) {
			d[i] = next().toCharArray();
		}
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				boolean c1 = false, c2 = false, c3 = false, c4 = false;
				for (int ii = 0; ii < 2; ii++) {
					for (int jj = 0; jj < 2; jj++) {
						switch (d[i + ii][j + jj]) {
						case 'f':
							c1 = true;
							break;
						case 'a':
							c2 = true;
							break;
						case 'c':
							c3 = true;
							break;
						case 'e':
							c4 = true;
							break;
						}
					}
					if (c1 && c2 && c3 && c4) {
						++ans;
					}
				}
			}
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