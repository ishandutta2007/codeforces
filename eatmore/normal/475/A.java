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
		int k = nextInt();
		out.print('+');
		for (int i = 0; i < 24; i++) {
			out.print('-');
		}
		out.println('+');
		for (int i = 0; i < 4; i++) {
			out.print('|');
			for (int j = 0; j < 11; j++) {
				if (i == 2 && j > 0) {
					out.print('.');
				} else {
					int x = 3 * j;
					if (j > 0) {
						++x;
					}
					x += i;
					if (i == 3 && j > 0) {
						--x;
					}
					out.print(x < k ? 'O' : '#');
				}
				out.print('.');
			}
			out.print(i == 2 ? '.' : '|');
			out.print(i == 0 ? 'D' : '.');
			out.print('|');
			if (i == 0 || i == 3) {
				out.print(')');
			}
			out.println();
		}
		out.print('+');
		for (int i = 0; i < 24; i++) {
			out.print('-');
		}
		out.print('+');
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