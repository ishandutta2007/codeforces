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
		int minH, maxH;
		switch (next()) {
		case "12":
			minH = 1;
			maxH = 12;
			break;
		case "24":
			minH = 0;
			maxH = 23;
			break;
		default:
			throw new AssertionError();
		}
		int h = nextInt();
		int m = nextInt();
		int ansH = minH;
		int ansD = Integer.MAX_VALUE;
		for (int ch = minH; ch <= maxH; ch++) {
			int cd = 0;
			if (ch % 10 != h % 10) {
				++cd;
			}
			if (ch / 10 != h / 10) {
				++cd;
			}
			if (cd < ansD) {
				ansH = ch;
				ansD = cd;
			}
		}
		int ansM = 0;
		ansD = Integer.MAX_VALUE;
		for (int cm = 0; cm <= 59; cm++) {
			int cd = 0;
			if (cm % 10 != m % 10) {
				++cd;
			}
			if (cm / 10 != m / 10) {
				++cd;
			}
			if (cd < ansD) {
				ansM = cm;
				ansD = cd;
			}
		}
		out.printf("%02d:%02d", ansH, ansM);
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
			tok = new StringTokenizer(in.readLine(), " :");
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