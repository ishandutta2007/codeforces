import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		String n = next();
		int ans = 0;
		for (int i = 0; i < n.length(); i++) {
			ans = max(ans, n.charAt(i) - '0');
		}
		out.println(ans);
		for (int i = 0; i < ans; i++) {
			if (i > 0) {
				out.print(' ');
			}
			char m[] = new char[n.length()];
			for (int j = 0; j < n.length(); j++) {
				m[j] = n.charAt(j) > i + '0' ? '1' : '0';
			}
			int j;
			for (j = 0; j < n.length() && m[j] == '0'; j++) { }
			out.print(new String(m, j, m.length - j));
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