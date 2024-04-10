import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int h = scanInt(), w = scanInt();
			for (int i = 0; i < w; i++) {
				out.print(i % 2 == 0 ? '1' : '0');
			}
			out.println();
			for (int i = 1; i < h - 1; i++) {
				out.print(i % 2 == 0 ? '1' : '0');
				for (int j = 1; j < w - 1; j++) {
					out.print('0');
				}
				out.print(i != 1 && (h - i - 1) % 2 == 0 ? '1' : '0');
				out.println();
			}
			out.print((h - 1) % 2 == 0 ? '1' : '0');
			for (int i = 1; i < w; i++) {
				out.print(i != 1 && (w - i - 1) % 2 == 0 ? '1' : '0');
			}
			out.println();
			out.println();
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