import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
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
		int n = nextInt();
		int k = nextInt();
		int x = nextInt();
		int cnts[] = new int[1024];
		for (int i = 0; i < n; i++) {
			++cnts[nextInt()];
		}
		int newCnts[] = new int[1024];
		for (int i = 0; i < k; i++) {
			fill(newCnts, 0);
			int flag = 0;
			for (int j = 0; j < 1024; j++) {
				int v = cnts[j];
				newCnts[j] += (v + flag) >> 1;
				newCnts[j ^ x] += (v + 1 - flag) >> 1;
				flag ^= v & 1;
			}
			int t[] = cnts;
			cnts = newCnts;
			newCnts = t;
		}
		int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
		for (int i = 0; i < 1024; i++) {
			if (cnts[i] > 0) {
				min = min(min, i);
				max = max(max, i);
			}
		}
		out.print(max + " " + min);
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