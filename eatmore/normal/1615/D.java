import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static int dsuGet(int dsu[], int i) {
		return i < 0 ? ~dsuGet(dsu, ~i) : dsu[i] == i ? i : (dsu[i] = dsuGet(dsu, dsu[i]));
	}

	static boolean merge(int dsu[], int a, int b, int v) {
		a = dsuGet(dsu, a);
		b = dsuGet(dsu, b) ^ v;
		if (a == ~b) {
			return false;
		} else if (a != b) {
			if (a < 0) {
				a = ~a;
				b = ~b;
			}
			dsu[a] = b;
		}
		return true;
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), m = scanInt(),
				x[] = new int[n - 1], y[] = new int[n - 1], v[] = new int[n - 1],
				dsu[] = new int[n];
			boolean good = true;
			for (int i = 0; i < n; i++) {
				dsu[i] = i;
			}
			for (int i = 0; i < n - 1; i++) {
				x[i] = scanInt() - 1;
				y[i] = scanInt() - 1;
				if ((v[i] = scanInt()) >= 0 && !merge(dsu, x[i], y[i], -(Integer.bitCount(v[i]) & 1))) {
					good = false;
				}
			}
			for (int i = 0; i < m; i++) {
				if (!merge(dsu, scanInt() - 1, scanInt() - 1, -scanInt())) {
					good = false;
				}
			}
			if (good) {
				out.println("YES");
				for (int i = 0; i < n - 1; i++) {
					out.println((x[i] + 1) + " " + (y[i] + 1) + " " + (v[i] >= 0 ? v[i] : ((dsuGet(dsu, x[i]) ^ dsuGet(dsu, y[i])) >>> 31)));
				}
			} else {
				out.println("NO");
			}
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