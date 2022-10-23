import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), b[] = new int[n];
			Map<Integer, List<Integer>> els = new HashMap<>();
			int k = 0;
			for (int i = 0; i < n; i++) {
				b[i] = scanInt();
				if (b[i] > i) {
					k = i + 1;
				}
				List<Integer> cels = els.get(b[i]);
				if (cels == null) {
					els.put(b[i], cels = new ArrayList<>());
				}
				cels.add(i);
			}
			int a[] = new int[n];
			int g = -1;
			e: for (Entry<Integer, List<Integer>> e: els.entrySet()) {
				for (int v: e.getValue()) {
					if (els.containsKey(v + 1)) {
						continue e;
					}
				}
				g = e.getKey();
				break;
			}
			int p = -1;
			for (int i = n - 1;;) {
				if (p >= 0) {
					a[i--] = p;
				}
				for (int v: els.get(g)) {
					if (v != p) {
						a[i--] = v;
					}
				}
				if (i == -1) {
					break;
				}
				g = b[p = g - 1];
			}
			out.println(k);
			for (int i = 0; i < n; i++) {
				out.print((a[i] + 1) + " ");
			}
			out.println();
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}