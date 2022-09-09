import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static void solve() throws Exception {
		int n = scanInt(), q = scanInt(), ones = 0, a[] = new int[n];
		for (int i = 0; i < n; i++) {
			if ((a[i] = scanInt()) != 0) {
				++ones;
			}
		}
		for (int qq = 0; qq < q; qq++) {
			switch (scanInt()) {
			case 1:
				int i = scanInt() - 1;
				if (a[i] != 0) {
					--ones;
					a[i] = 0;
				} else {
					++ones;
					a[i] = 1;
				}
				break;
			case 2:
				int k = scanInt() - 1;
				out.println(k < ones ? 1 : 0);
				break;
			default:
				throw new AssertionError();
			}
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