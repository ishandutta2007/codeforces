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

public class H {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int a = nextInt();
		long num = nextLong();
//		for (long snum = 0; snum < 10; snum++) {
//			long num = snum;
			long x = 0;
			long y = 0;
			long mul = 1;
			boolean vert = true;
			while (num > 0) {
				int cur = (int) (num % 4);
				if (vert) {
					if (cur == 1 || cur == 2) {
						long tmp = x;
						x = y + mul;
						y = tmp;
						if (cur == 2) {
							y += mul;
						}
					} else if (cur == 3) {
						x = mul - x - 1;
						y = 2 * mul - y - 1;
					}
				} else {
					if (cur == 1 || cur == 2) {
						long tmp = y;
						y = x + mul;
						x = tmp;
						if (cur == 2) {
							x += mul;
						}
					} else if (cur == 3) {
						y = mul - y - 1;
						x = 2 * mul - x - 1;
					}
				}
				num /= 4;
				mul *= 2;
//				long tmp = x;
//				x = y;
//				y = tmp;
				vert = !vert;
			}
			if (a % 2 == 1) {
				long tmp = x;
				x = y;
				y = tmp;
			}
			out.println(x + " " + y);
//		}
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