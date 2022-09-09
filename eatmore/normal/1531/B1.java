import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		int n = scanInt();
		Map<Long, Integer> cnt = new HashMap<>();
		for (int i = 0; i < n; i++) {
			int w = scanInt(), h = scanInt();
			if (w < h) {
				int t = w;
				w = h;
				h = t;
			}
			Long k = (long) w;
			cnt.put(k, cnt.getOrDefault(k, 0) + 1);
			if (h != w) {
				k = (long) h;
				cnt.put(k, cnt.getOrDefault(k, 0) + 1);
				k = ((long) w << 32) | h;
				cnt.put(k, cnt.getOrDefault(k, 0) + 1);
			}
		}
		long ans = 0;
		for (Entry<Long, Integer> e: cnt.entrySet()) {
			long v = e.getValue();
			v = v * (v - 1) / 2;
			if ((e.getKey() & 0xffffffff00000000L) != 0) {
				ans -= v;
			} else {
				ans += v;
			}
		}
		out.print(ans);
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