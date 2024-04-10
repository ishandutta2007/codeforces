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

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		char field[][] = new char[n][n];
		for (int i = 0; i < n; i++) {
			next().getChars(0, n, field[i], 0);
		}
		boolean attack[][] = new boolean[2 * n - 1][2 * n - 1];
		for (boolean t[]: attack) {
			fill(t, true);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (field[i][j] != 'o') {
					continue;
				}
				for (int ii = 0; ii < n; ii++) {
					for (int jj = 0; jj < n; jj++) {
						if (field[ii][jj] != '.') {
							continue;
						}
						attack[ii - i + n - 1][jj - j + n - 1] = false;
					}
				}
			}
		}
		boolean test[][] = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (field[i][j] != 'o') {
					continue;
				}
				for (int ii = 0; ii < n; ii++) {
					for (int jj = 0; jj < n; jj++) {
						if (attack[ii - i + n - 1][jj - j + n - 1]) {
							test[ii][jj] = true;
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (field[i][j] == 'x' && !test[i][j]) {
					out.print("NO");
					return;
				}
			}
		}
		out.println("YES");
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < 2 * n - 1; j++) {
				out.print(i == n - 1 && j == n - 1 ? 'o' : attack[i][j] ? 'x' : '.');
			}
			out.println();
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