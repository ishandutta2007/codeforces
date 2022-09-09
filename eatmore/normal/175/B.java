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
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.Map.Entry;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		Map<String, Integer> score = new HashMap<String, Integer>();
		for (int i = 0; i < n; i++) {
			String name = next();
			int sc = nextInt();
			if (!score.containsKey(name) || score.get(name) < sc) {
				score.put(name, sc);
			}
		}
		Entry<String, Integer> scoreSorted[] = (Entry<String, Integer>[]) score.entrySet().toArray(new Entry<?, ?>[score.size()]);
		sort(scoreSorted, new Comparator<Entry<String, Integer>>() {
			public int compare(Entry<String, Integer> o1,
					Entry<String, Integer> o2) {
				return o1.getValue() - o2.getValue();
			}
		});
		int m = scoreSorted.length;
		out.println(m);
		for (int i = 0, j = 0; i < m; i++) {
			if (j <= i) {
				for (j = i; j < m && scoreSorted[j].getValue() + 0 == scoreSorted[i].getValue(); j++) { }
			}
			out.print(scoreSorted[i].getKey());
			out.print(' ');
			if (j * 10 < m * 5) {
				out.println("noob");
			} else if (j * 10 < m * 8) {
				out.println("random");
			} else if (j * 10 < m * 9) {
				out.println("average");
			} else if (j * 100 < m * 99) {
				out.println("hardcore");
			} else {
				out.println("pro");
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