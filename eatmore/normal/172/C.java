import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.SortedMap;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Map.Entry;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		long time = 0;
		SortedMap<Integer, List<Integer>> contents = new TreeMap<Integer, List<Integer>>();
		long ans[] = new long[n];
		for (int i = 0; i < n; i++) {
			time = max(time, nextInt());
			int pos = nextInt();
			if (!contents.containsKey(pos)) {
				contents.put(pos, new ArrayList<Integer>());
			}
			contents.get(pos).add(i);
			if (i % m == m - 1 || i == n - 1) {
				pos = 0;
				for (Entry<Integer, List<Integer>> e: contents.entrySet()) {
					time += e.getKey() - pos;
					pos = e.getKey();
					for (int x: e.getValue()) {
						ans[x] = time;
					}
					time += 1 + e.getValue().size() / 2;
				}
				time += pos;
				contents.clear();
			}
		}
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(ans[i]);
		}
		out.println();
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