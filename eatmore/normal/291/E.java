import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static List<Integer> children[];
	static String s[];
	static int trans[][];
	static int n;
	
	static void solve() throws Exception {
		n = nextInt();
		children = (List<Integer>[]) new List<?>[n];
		for (int i = 0; i < n; i++) {
			children[i] = new ArrayList<>();
		}
		s = new String[n];
		s[0] = "";
		for (int i = 1; i < n; i++) {
			children[nextInt() - 1].add(i);
			s[i] = next();
		}
		String t = next();
		n = t.length();
		int pref[] = new int[n + 1];
		pref[0] = -1;
		trans = new int[26][n + 1];
		for (int i = 0; i <= n; i++) {
			if (i > 0) {
				int cur = pref[i - 1];
				while (cur >= 0 && t.charAt(cur) != t.charAt(i - 1)) {
					cur = pref[cur];
				}
				pref[i] = cur + 1;
			}
			for (int c = 0; c < 26; c++) {
				trans[c][i] = (i < n && t.charAt(i) == c + 'a') ? i + 1 : i == 0 ? 0 : trans[c][pref[i]];
			}
		}
		out.print(dfs(0, 0));
	}
	
	static int dfs(int cur, int state) {
		int ans = 0;
		String cs = s[cur];
		for (int i = 0; i < cs.length(); i++) {
			state = trans[cs.charAt(i) - 'a'][state];
			if (state == n) {
				++ans;
			}
		}
		for (int next: children[cur]) {
			ans += dfs(next, state);
		}
		return ans;
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