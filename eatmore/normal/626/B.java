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

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		String s = next();
		int cnts[] = new int[3];
		for (int i = 0; i < n; i++) {
			switch (s.charAt(i)) {
			case 'R':
				++cnts[0];
				break;
			case 'G':
				++cnts[1];
				break;
			case 'B':
				++cnts[2];
				break;
			default:
				throw new AssertionError();
			}
		}
		if ((cnts[0] > 0 && cnts[1] > 0) || (cnts[2] > 0 && ((cnts[0] == 0 && cnts[1] == 0) || cnts[0] > 1 || cnts[1] > 1))) {
			out.print('B');
		}
		if ((cnts[0] > 0 && cnts[2] > 0) || (cnts[1] > 0 && ((cnts[0] == 0 && cnts[2] == 0) || cnts[0] > 1 || cnts[2] > 1))) {
			out.print('G');
		}
		if ((cnts[1] > 0 && cnts[2] > 0) || (cnts[0] > 0 && ((cnts[1] == 0 && cnts[2] == 0) || cnts[1] > 1 || cnts[2] > 1))) {
			out.print('R');
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