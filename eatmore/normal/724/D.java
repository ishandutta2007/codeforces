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

public class D {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		int m = nextInt();
		char s[] = next().toCharArray();
		int n = s.length;
		int cnt[] = new int[26];
		for (int i = 0; i < n; i++) {
			++cnt[s[i] - 'a'];
		}
		c: for (char c = 'a';; c++) {
			int last = -1, last2 = -1, curCnt = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] < c) {
					last = last2 = i;
					continue;
				}
				if (s[i] == c) {
					last2 = i;
				}
				if (i - last == m) {
					if (last2 > last) {
						++curCnt;
						last = last2;
					} else {
						continue c;
					}
				}
			}
			for (int i = 0; i < c - 'a'; i++) {
				for (int j = 0; j < cnt[i]; j++) {
					out.print((char) (i + 'a'));
				}
			}
			for (int i = 0; i < curCnt; i++) {
				out.print(c);
			}
			return;
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