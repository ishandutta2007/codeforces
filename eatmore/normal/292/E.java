import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Map.Entry;
import java.util.NavigableMap;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Val {
		final int end, off;

		public Val(int end, int off) {
			this.end = end;
			this.off = off;
		}
	}

	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int a[] = new int[n];
		int b[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}
		NavigableMap<Integer, Val> map = new TreeMap<>();
		for (int i = 0; i < m; i++) {
			int t = nextInt();
			if (t == 1) {
				int off = nextInt() - 1;
				int key = nextInt() - 1;
				int end = key + nextInt();
				Iterator<Entry<Integer, Val>> sub = map.headMap(key, false).descendingMap().entrySet().iterator();
				if (sub.hasNext()) {
					Entry<Integer, Val> prev = sub.next();
					Val prevVal = prev.getValue();
					if (prevVal.end > key) {
						prev.setValue(new Val(key, prevVal.off));
						if (prevVal.end > end) {
							map.put(end, new Val(prevVal.end, prevVal.off + end - prev.getKey()));
						}
					}
				}
				sub = map.tailMap(key, true).entrySet().iterator();
				Entry<Integer, Val> next;
				while (sub.hasNext() && (next = sub.next()).getKey() < end) {
					int nextKey = next.getKey();
					Val nextVal = next.getValue();
					sub.remove();
					if (nextVal.end > end) {
						map.put(end, new Val(nextVal.end, nextVal.off + end - nextKey));
						break;
					}
				}
				map.put(key, new Val(end, off));
			} else {
				int pos = nextInt() - 1;
				Iterator<Entry<Integer, Val>> sub = map.headMap(pos, true).descendingMap().entrySet().iterator();
				if (sub.hasNext()) {
					Entry<Integer, Val> prev = sub.next();
					if (prev.getValue().end > pos) {
						out.println(a[prev.getValue().off + pos - prev.getKey()]);
						continue;
					}
				}
				out.println(b[pos]);
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