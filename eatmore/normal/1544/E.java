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
		int tests = scanInt();
		test: for (int test = 0; test < tests; test++) {
			String s = scanString();
			int n = s.length();
			int cnt[] = new int[26];
			for (int i = 0; i < n; i++) {
				++cnt[s.charAt(i) - 'a'];
			}
			for (int i = 0; i < 26; i++) {
				if (cnt[i] == n) {
					char c = (char) (i + 'a');
					for (int j = 0; j < n; j++) {
						out.print(c);
					}
					out.println();
					continue test;
				}
				if (cnt[i] == 1) {
					out.print((char) (i + 'a'));
					cnt[i] = 0;
					for (int j = 0; j < 26; j++) {
						char c = (char) (j + 'a');
						for (int k = cnt[j]; k > 0; k--) {
							out.print(c);
						}
					}
					out.println();
					continue test;
				}
			}
			int a = -1, b = -1;
			for (int i = 0; i < 26; i++) {
				if (cnt[i] != 0) {
					if (a < 0) {
						a = i;
					} else if (b < 0) {
						b = i;
						break;
					}
				}
			}
			char ca = (char) (a + 'a');
			if (2 * (cnt[a] - 2) <= n - 2) {
				out.print(ca);
				out.print(ca);
				cnt[a] -= 2;
				for (int i = a + 1; i < 26; i++) {
					char c = (char) (i + 'a');
					for (int j = cnt[i]; j > 0; j--) {
						out.print(c);
						if (cnt[a] > 0) {
							out.print(ca);
							--cnt[a];
						}
					}
				}
			} else {
				char cb = (char) (b + 'a');
				out.print(ca);
				out.print(cb);
				--cnt[a];
				--cnt[b];
				if (cnt[a] + cnt[b] == n - 2) {
					for (int i = cnt[b]; i > 0; i--) {
						out.print(cb);
					}
					for (int i = cnt[a]; i > 0; i--) {
						out.print(ca);
					}
				} else {
					for (int i = cnt[a]; i > 0; i--) {
						out.print(ca);
					}
					for (int i = b + 1; i < 26; i++) {
						char c = (char) (i + 'a');
						for (int j = cnt[i]; j > 0; j--) {
							out.print(c);
							if (cnt[b] > 0) {
								for (int k = cnt[b]; k > 0; k--) {
									out.print(cb);
								}
								cnt[b] = 0;
							}
						}
					}
				}
			}
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