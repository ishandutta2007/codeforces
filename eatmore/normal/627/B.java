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

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static long getSum(long fenwick[], int i) {
		long res = fenwick[i];
		while ((i = (i & (i + 1)) - 1) >= 0) {
			res += fenwick[i];
		}
		return res;
	}

	static void updateSum(long fenwick[], int i, long v) {
		fenwick[i] += v;
		while ((i |= i + 1) < fenwick.length) {
			fenwick[i] += v;
		}
	}

	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
		long a = nextLong();
		long b = nextLong();
		int q = nextInt();
		long orders[] = new long[n];
		long f1[] = new long[n];
		long f2[] = new long[n];
		for (int i = 0; i < q; i++) {
			switch (nextInt()) {
			case 1:
				int day = nextInt() - 1;
				long cnt = nextLong();
				updateSum(f1, day, min(orders[day] + cnt, b) - min(orders[day], b));
				updateSum(f2, n - day - 1, min(orders[day] + cnt, a) - min(orders[day], a));
				orders[day] += cnt;
				break;
			case 2:
				day = nextInt() - 1;
				out.println((day > 0 ? getSum(f1, day - 1) : 0) + (day + k < n ? getSum(f2, n - day - k - 1) : 0));
				break;
			default:
				throw new AssertionError();
			}
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