import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		Map<String, List<String>> paths = new HashMap<>();
		for (int i = 0; i < n; i++) {
			String l = next();
			if (!l.startsWith("http://")) {
				throw new AssertionError();
			}
			int pos = l.indexOf('/', 7);
			if (pos < 0) {
				pos = l.length();
			}
			String host = l.substring(0, pos);
			String path = l.substring(pos);
			List<String> cPaths = paths.get(host);
			if (cPaths == null) {
				paths.put(host, cPaths = new ArrayList<>());
			}
			cPaths.add(path);
		}
		Map<List<String>, List<String>> rPaths = new HashMap<>();
		for (Entry<String, List<String>> e: paths.entrySet()) {
			List<String> cPaths = e.getValue();
			Collections.sort(cPaths);
			List<String> out = new ArrayList<>();
			String last = null;
			for (String cur: cPaths) {
				if (!cur.equals(last)) {
					out.add(cur);
					last = cur;
				}
			}
			String host = e.getKey();
			List<String> hosts = rPaths.get(out);
			if (hosts == null) {
				rPaths.put(out, hosts = new ArrayList<>());
			}
			hosts.add(host);
		}
		List<List<String>> res = new ArrayList<>();
		for (List<String> hosts: rPaths.values()) {
			if (hosts.size() > 1) {
				res.add(hosts);
			}
		}
		out.println(res.size());
		for (List<String> hosts: res) {
			out.println(String.join(" ", hosts));
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