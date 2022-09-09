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
		String s1 = next();
		String s2 = next();
		int bal = 0;
		for (int i = 0; i < s1.length(); i += 2) {
			int p1 = "([8".indexOf(s1.charAt(i));
			int p2 = "([8".indexOf(s2.charAt(i));
//			System.err.println(p1 + " " + p2 + " " + ((p1 - p2 + 4) % 3 - 1));
			bal += (p1 - p2 + 4) % 3 - 1;
		}
		out.println(bal > 0 ? "TEAM 1 WINS" : bal < 0 ? "TEAM 2 WINS" : "TIE");
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