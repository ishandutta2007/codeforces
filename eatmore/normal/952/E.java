import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void solve() throws Exception {
		int c1 = 0, c2 = 0;
		int n = scanInt();
		for (int i = 0; i < n; i++) {
			scanString();
			switch (scanString()) {
			case "soft":
				++c1;
				break;
			case "hard":
				++c2;
				break;
			}
		}
		if (c1 < c2) {
			int t = c1;
			c1 = c2;
			c2 = t;
		}
		for (int i = 0;; i++) {
			if ((i * i + 1) / 2 >= c1 && i * i / 2 >= c2) {
				out.print(i);
				break;
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