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
		int y = 10000;
		for (int i = 0; i < n; i++) {
			int dist = nextInt();
			switch (next()) {
			case "South":
				if ((y -= dist) < -10000) {
					out.print("NO");
					return;
				}
				break;
			case "North":
				if ((y += dist) > 10000) {
					out.print("NO");
					return;
				}
				break;
			case "West":
			case "East":
				if (y == 10000 || y == -10000) {
					out.print("NO");
					return;
				}
				break;
			default:
				throw new AssertionError();
			}
		}
		out.print(y == 10000 ? "YES" : "NO");
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