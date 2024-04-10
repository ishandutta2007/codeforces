import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		int n = scanInt();
		long p = scanLong(), q = scanLong(), r = scanLong();
		long cansP = Long.MIN_VALUE, cansQ = Long.MIN_VALUE, cansR = Long.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			long cur = scanLong();
			cansP = max(cansP, p * cur);
			cansQ = max(cansQ, cansP + q * cur);
			cansR = max(cansR, cansQ + r * cur);
		}
		out.print(cansR);
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