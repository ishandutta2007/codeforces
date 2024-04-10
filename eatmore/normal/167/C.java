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
	
	static boolean solve(long a, long b) {
		if (b == 0) {
			return false;
		}
		if (a < b) {
			return solve(b, a);
		}
		long q = a / b;
		if (!solve(b, a % b)) {
//			System.err.println("Solve " + a + " " + b + " -> " + true);
			return true;
		}
//		System.err.println("Solve " + a + " " + b + " -> " + ((q + 1) % (b + 1) % 2 == 0));
		return q % (b + 1) % 2 == 0;
	}
	
	static void solve() throws Exception {
//		boolean win[] = new boolean[200];
//		for (int a = 1; a < 40; a++) {
//			fill(win, true);
//			win[0] = false;
//			for (int i = 0; i < win.length; i++) {
//				System.err.print(win[i] ? '+' : '-');
//			}
//			System.err.println();
//			fill(win, false);
//			win[0] = true;
//			for (int i = 1; i < win.length; i++) {
//				for (int j = 1; j <= i; j *= a) {
//					if (!win[i - j]) {
//						win[i] = true;
//						break;
//					}
//					if (a == 1) {
//						break;
//					}
//				}
//			}
//			for (int i = 0; i < win.length; i++) {
//				System.err.print(win[i] ? '+' : '-');
//			}
//			System.err.println();
//			System.err.println();
//		}
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			long a = nextLong();
			long b = nextLong();
			out.println(solve(a, b) ? "First" : "Second");
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