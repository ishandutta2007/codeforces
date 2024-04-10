import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

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
	
//	static final Random rng = new Random(42);
//	static String rngString() {
//		StringBuilder sb = new StringBuilder();
//		int l = rng.nextInt(10) + 1;
//		for (int i = 0; i < l; i++) {
//			sb.append((char) (rng.nextInt(26) + 'a'));
//		}
//		return sb.toString();
//	}
//	
//	static void stress() throws Exception {
//		int q = 0;
//		while (true) {
//			solve();
//			if (++q % 1000 == 0) {
//				System.err.println("PASS");
//			}
//		}
//	}
	
	static void solve() throws Exception {
		int n = nextInt();
//		int n = rng.nextInt(5) + 1;
//		int n = 2000;
		String t[] = new String[n];
		int help1[][][] = new int[n][][];
		int helpCur[] = new int[26];
		for (int i = 0; i < n; i++) {
			t[i] = next();
//			t[i] = rngString();
//			StringBuilder sb = new StringBuilder();
//			if (i == 0) {
//				for (int j = 0; j < 1000000; j++) {
//					sb.append('a');
//				}
//			}
//			t[i] = sb.toString();
			int l = t[i].length();
			help1[i] = new int[26][l + 1];
			fill(helpCur, -1);
			for (int j = l; ;) {
				for (int k = 0; k < 26; k++) {
					help1[i][k][j] = helpCur[k];
				}
				if (--j < 0) {
					break;
				}
				helpCur[t[i].charAt(j) - 'a'] = j;
			}
		}
		int m = nextInt();
//		int m = rng.nextInt(5) + 1;
//		int m = 2000;
		int b[] = new int[m];
		for (int i = 0; i < m; i++) {
			b[i] = nextInt() - 1;
//			b[i] = rng.nextInt(n);
//			b[i] = 0;
		}
		int help2[][] = new int[26][m + 1];
		fill(helpCur, -1);
		for (int i = m; ;) {
			for (int j = 0; j < 26; j++) {
				help2[j][i] = helpCur[j];
			}
			if (--i < 0) {
				break;
			}
			for (int j = 0; j < 26; j++) {
				if (help1[b[i]][j][0] >= 0) {
					helpCur[j] = i;
				}
			}
		}
		String s = next();
//		StringBuilder sb = new StringBuilder();
//		for (int i = 0; i < 2000; i++) {
//			sb.append('a');
//		}
//		String s = sb.toString();
//		String s = rngString();
//		int rngAns; String ttt;
//		{
//			StringBuilder tt = new StringBuilder();
//			for (int i = 0; i < m; i++) {
//				tt.append(t[b[i]]);
//			}
//			ttt = tt.toString();
//			int dyn[][] = new int[s.length() + 1][ttt.length() + 1];
//			for (int i = 0; i <= s.length(); i++) {
//				for (int j = 0; j <= ttt.length(); j++) {
//					if (i > 0) {
//						dyn[i][j] = max(dyn[i][j], dyn[i - 1][j]);
//					}
//					if (j > 0) {
//						dyn[i][j] = max(dyn[i][j], dyn[i][j - 1]);
//					}
//					if (i > 0 && j > 0 && s.charAt(i - 1) == ttt.charAt(j - 1)) {
//						dyn[i][j] = max(dyn[i][j], dyn[i - 1][j - 1] + 1);
//					}
//				}
//			}
//			rngAns = dyn[s.length()][ttt.length()];
//		}
		int k = s.length();
		int ans1[] = new int[k + 1];
		int ans2[] = new int[k + 1];
		int tmp1[] = new int[k + 1];
		int tmp2[] = new int[k + 1];
		for (int i = 0; i < k; i++) {
			int character = s.charAt(i) - 'a';
			arraycopy(ans1, 0, tmp1, 0, i + 1);
			arraycopy(ans2, 0, tmp2, 0, i + 1);
			tmp1[i + 1] = -1;
			tmp2[i + 1] = -1;
			for (int j = 0; j <= i; j++) {
				int cans1 = ans1[j];
				int cans2 = ans2[j];
				if (cans1 < 0) {
					continue;
				}
				cans2 = help1[b[cans1]][character][cans2];
				if (cans2 < 0) {
					cans1 = help2[character][cans1 + 1];
					if (cans1 < 0) {
						continue;
					}
					cans2 = help1[b[cans1]][character][0];
				}
				++cans2;
				if (tmp1[j + 1] < 0 || tmp1[j + 1] > cans1 || tmp1[j + 1] == cans1 && tmp2[j + 1] > cans2) {
					tmp1[j + 1] = cans1;
					tmp2[j + 1] = cans2;
				}
			}
			int $[] = ans1;
			ans1 = tmp1;
			tmp1 = $;
			$ = ans2;
			ans2 = tmp2;
			tmp2 = $;
		}
		int ans = 0;
		for (int i = 1; i <= k; i++) {
			if (ans1[i] >= 0) {
				ans = i;
			}
		}
		out.println(ans);
//		if (ans != rngAns) {
//			System.err.println(s + " " + ttt);
//			System.err.println(ans + " " + rngAns);
//			throw new AssertionError();
//		}
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
//			stress();
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