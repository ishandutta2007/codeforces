import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static class Shirt implements Comparable<Shirt> {
		final int price;
		boolean bought;

		Shirt(int price) {
			this.price = price;
		}

		public int compareTo(Shirt o) {
			return price - o.price;
		}
	}

	static void solve() throws Exception {
		int n = nextInt();
		PriorityQueue<Shirt> queues[] = new PriorityQueue[3];
		for (int i = 0; i < 3; i++) {
			queues[i] = new PriorityQueue<>();
		}
		int p[] = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt();
		}
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
		}
		for (int i = 0; i < n; i++) {
			Shirt s = new Shirt(p[i]);
			int b = nextInt() - 1;
			queues[a[i]].add(s);
			if (b != a[i]) {
				queues[b].add(s);
			}
		}
		int m = nextInt();
		i: for (int i = 0; i < m; i++) {
			int c = nextInt() - 1;
			while (!queues[c].isEmpty()) {
				Shirt s = queues[c].remove();
				if (!s.bought) {
					s.bought = true;
					out.print(s.price + " ");
					continue i;
				}
			}
			out.print("-1 ");
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