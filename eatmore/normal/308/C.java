import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

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
		int m = nextInt();
		int a[] = new int[30];
		for (int i = 0; i < n; i++) {
			int cur = nextInt();
			for (int j = 0; j < 30; j++) {
				if ((cur & (1 << j)) != 0) {
					++a[j];
				}
			}
		}
		int b[] = new int[30];
		for (int i = 0; i < m; i++) {
			++b[nextInt()];
		}
		int ans = 0;
		for (int i = 0; i < 30; i++) {
			for (int j = i; j < 30; j++) {
				if (b[i] == 0) {
					break;
				}
				long have = (long) a[j] << (j - i);
				int take = (int) min(b[i], have);
				b[i] -= take;
				ans += take;
				have -= take;
				a[j] = (int) (have >> (j - i));
				for (int k = i; k < j; k++) {
					if ((have & (1 << (k - i))) != 0) {
						++a[k];
					}
				}
			}
			if (b[i] != 0) {
				break;
			}
		}
		out.print(ans);
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