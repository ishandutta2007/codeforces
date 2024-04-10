import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Collections.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class C {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static class Fountain implements Comparable<Fountain> {
		final int beauty, price;

		Fountain(int beauty, int price) {
			this.beauty = beauty;
			this.price = price;
		}

		public int compareTo(Fountain o) {
			if (price != o.price) {
				return price - o.price;
			}
			return beauty - o.beauty;
		}
	}

	static int getAns(int money, List<Fountain> fountains) {
		sort(fountains);
		int n = fountains.size();
		Fountain best1[] = new Fountain[n];
		Fountain best2[] = new Fountain[n];
		Fountain cbest1 = null, cbest2 = null;
		for (int i = 0; i < n; i++) {
			Fountain cur = fountains.get(i);
			if (cbest1 == null || cbest1.beauty < cur.beauty) {
				cbest2 = cbest1;
				cbest1 = cur;
			} else if (cbest2 == null || cbest2.beauty < cur.beauty) {
				cbest2 = cur;
			}
			best1[i] = cbest1;
			best2[i] = cbest2;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			Fountain cur = fountains.get(i);
			if (cur.price < money) {
				int have = money - cur.price;
				int j = Collections.binarySearch(fountains, new Fountain(1000000, have));
				if (j < 0) {
					j = ~j - 1;
				}
				if (j >= 0) {
					Fountain pair = best1[j];
					if (pair == cur) {
						pair = best2[j];
					}
					if (pair != null) {
						ans = max(ans, cur.beauty + pair.beauty);
					}
				}
			}
		}
		return ans;
	}

	static void solve() throws Exception {
		int n = nextInt();
		int c1 = nextInt();
		int c2 = nextInt();
		List<Fountain> f1 = new ArrayList<>();
		List<Fountain> f2 = new ArrayList<>();
		int best1 = 0;
		int best2 = 0;
		for (int i = 0; i < n; i++) {
			int b = nextInt();
			int p = nextInt();
			switch (next()) {
			case "C":
				f1.add(new Fountain(b, p));
				if (p <= c1) {
					best1 = max(best1, b);
				}
				break;
			case "D":
				f2.add(new Fountain(b, p));
				if (p <= c2) {
					best2 = max(best2, b);
				}
				break;
			default:
				throw new AssertionError();
			}
		}
		int ans = 0;
		if (best1 > 0 && best2 > 0) {
			ans = best1 + best2;
		}
		out.print(max(max(ans, getAns(c1, f1)), getAns(c2, f2)));
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