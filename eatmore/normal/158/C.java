import static java.lang.Integer.parseInt;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		String path = "/";
		for (int i = 0; i < n; i++) {
			String command = next();
			if ("pwd".equals(command)) {
				out.println(path);
			} else if ("cd".equals(command)) {
				String newpath = next();
				if (newpath.startsWith("/")) {
					path = newpath;
				} else {
					path = path + newpath;
				}
				List<String> comps = new ArrayList<String>();
				int pos = 0;
				do {
					++pos;
					int nextpos = path.indexOf('/', pos);
					if (nextpos < 0) {
						nextpos = path.length();
					}
					String comp = path.substring(pos, nextpos);
					if ("..".equals(comp)) {
						comps.remove(comps.size() - 1);
					} else {
						comps.add(comp);
					}
					pos = nextpos;
				} while (pos < path.length());
				StringBuilder sb = new StringBuilder();
				for (String comp: comps) {
					sb.append('/').append(comp);
				}
				sb.append('/');
				path = sb.toString();
			} else {
				throw new AssertionError();
			}
		}
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
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