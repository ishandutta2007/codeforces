import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Item {
		final int id;
		final long cost;
		final boolean isStool;
		
		Item(int id, long cost, boolean isBucket) {
			this.id = id;
			this.cost = cost;
			this.isStool = isBucket;
		}
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
		Item items[] = new Item[n];
		for (int i = 0; i < items.length; i++) {
			items[i] = new Item(i, nextLong(), nextInt() == 1);
		}
		sort(items, new Comparator<Item>() {
			public int compare(Item o1, Item o2) {
				if (o1.isStool != o2.isStool) {
					return o1.isStool ? -1 : 1;
				}
				return Long.signum(o2.cost - o1.cost);
			}
		});
		List<Item> bags[] = (List<Item>[]) new List<?>[k];
		for (int i = 0; i < k; i++) {
			bags[i] = new ArrayList<Item>();
		}
		for (int i = 0; i < n; i++) {
			bags[min(i, k - 1)].add(items[i]);
		}
		long ans = 0;
		for (int i = 0; i < k; i++) {
			boolean hasStool = false;
			long sum = 0;
			long min = Long.MAX_VALUE;
			for (Item item: bags[i]) {
				if (item.isStool) {
					hasStool = true;
				}
				sum += item.cost;
				min = min(min, item.cost);
			}
			ans += 2 * sum;
//			System.err.println(sum + " " + min);
			if (hasStool) {
				ans -= min;
			}
		}
		out.println(ans / 2 + "." + (ans % 2 * 5));
		for (int i = 0; i < k; i++) {
			out.print(bags[i].size());
			for (Item j: bags[i]) {
				out.print(" " + (j.id + 1));
			}
			out.println();
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