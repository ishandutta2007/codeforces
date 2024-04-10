import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static final int MOD = 1000000007;
	
	static int add(int a, int b) {
		int res = a + b;
		if (res >= MOD) {
			res -= MOD;
		}
		return res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		if (res < 0) {
			res += MOD;
		}
		return res;
	}

	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
		int cnt[] = new int[k];
		int totalCnt = 1;
		final int lastUpdate[] = new int[k];
		String s = next();
		for (int i = 0; i < s.length(); i++) {
			int c = s.charAt(i) - 'a';
			lastUpdate[c] = i + 1;
			int add = sub(totalCnt, cnt[c]);
			cnt[c] = totalCnt;
			totalCnt = add(totalCnt, add);
		}
		Integer idx[] = new Integer[k];
		for (int i = 0; i < k; i++) {
			idx[i] = i;
		}
		sort(idx, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return lastUpdate[o1] - lastUpdate[o2];
			}
		});
		for (int i = 0; i < n; i++) {
			int c = idx[i % k];
			int add = sub(totalCnt, cnt[c]);
			cnt[c] = totalCnt;
			totalCnt = add(totalCnt, add);
		}
		out.print(totalCnt);
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