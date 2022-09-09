import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void add(int f[], int i, int v) {
		do {
			f[i] += v;
			i |= i + 1;
		} while (i < f.length);
	}
	
	static int sum(int f[], int i) {
		int v = 0;
		do {
			v += f[i];
			i = (i & (i + 1)) - 1;
		} while (i >= 0);
		return v;
	}
	
	static void adjust(int pi[], int f[], int i, int v) {
		if (i > 0 && pi[i] < pi[i - 1]) {
			add(f, i, v);
		}
		if (i < pi.length - 1 && pi[i] > pi[i + 1]) {
			add(f, i + 1, v);
		}
	}

	static void solve() throws Exception {
		int n = nextInt();
		int p[] = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}
		int pi[] = new int[n];
		for (int i = 0; i < n; i++) {
			pi[p[i]] = i;
		}
		int f[] = new int[n];
		for (int i = 1; i < n; i++) {
			if (pi[i - 1] > pi[i]) {
				add(f, i, 1);
			}
		}
		int q = nextInt();
		for (int i = 0; i < q; i++) {
			switch (nextInt()) {
			case 1:
			{
				int from = nextInt() - 1;
				int to = nextInt() - 1;
				out.println(sum(f, to) - sum(f, from) + 1);
				break;
			}
			case 2:
			{
				int ui = nextInt() - 1;
				int uv = p[ui];
				int vi = nextInt() - 1;
				int vv = p[vi];
				p[ui] = vv;
				p[vi] = uv;
				adjust(pi, f, uv, -1);
				pi[uv] = vi;
				adjust(pi, f, uv, 1);
				adjust(pi, f, vv, -1);
				pi[vv] = ui;
				adjust(pi, f, vv, 1);
				break;
			}
			default:
				throw new AssertionError();
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