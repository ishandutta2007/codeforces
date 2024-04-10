import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), x1 = scanInt(), y1 = scanInt(), x2 = scanInt(), y2 = scanInt(),
				x3 = scanInt(), y3 = scanInt(), x = scanInt(), y = scanInt();
			int px = (x1 ^ x2 ^ x3) & 1, py = (y1 ^ y2 ^ y3) & 1;
			int xx, yy;
			if (((x1 ^ px) & 1) != 0 && ((y1 ^ py) & 1) != 0) {
				xx = x1;
				yy = y1;
			} else if (((x2 ^ px) & 1) != 0 && ((y2 ^ py) & 1) != 0) {
				xx = x2;
				yy = y2;
			} else {
				xx = x3;
				yy = y3;
			}
			out.println(((xx == 1 || xx == n) && (yy == 1 || yy == n) ? x == xx || y == yy :
				((x ^ px) & 1) != 0 || ((y ^ py) & 1) != 0) ? "YES" : "NO");
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}