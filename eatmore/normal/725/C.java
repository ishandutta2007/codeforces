import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

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

	static void solve() throws Exception {
		String s = next();
		int p[] = new int[26], p1 = -1, p2 = -1;
		fill(p, -1);
		for (int i = 0; i < 27; i++) {
			int c = s.charAt(i) - 'A';
			if (p[c] == -1) {
				p[c] = i;
			} else {
				p1 = p[c];
				p2 = i;
				break;
			}
		}
		if (p1 + 1 == p2) {
			out.print("Impossible");
			return;
		}
		s = s.substring(0, p2) + s.substring(p2 + 1);
		int shift = (p1 + p2 + 1) / 2;
		s = s.substring(shift) + s.substring(0, shift);
		out.println(s.substring(0, 13));
		out.print(new StringBuilder(s.substring(13)).reverse().toString());
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