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
		int k = nextInt();
		int a = nextInt();
		int b = nextInt();
		int c = nextInt();
		int d = nextInt();
		if (n <= 4 || k <= n) {
			out.print("-1");
			return;
		}
		out.print(a + " " + c);
		for (int i = 1; i <= n; i++) {
			if (i != a && i != b && i != c && i != d) {
				out.print(" " + i);
			}
		}
		out.print(" " + d + " " + b);
		out.println();
		out.print(c + " " + a);
		for (int i = 1; i <= n; i++) {
			if (i != a && i != b && i != c && i != d) {
				out.print(" " + i);
			}
		}
		out.print(" " + b + " " + d);
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