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
import java.util.Comparator;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		long k[] = new long[n];
		final long c[] = new long[n];
		for (int i = 0; i < n; i++) {
			k[i] = nextInt();
			c[i] = nextInt();
		}
		Integer idx[] = new Integer[n];
		for (int i = 0; i < n; i++) {
			idx[i] = i;
		}
		sort(idx, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return (int) (c[o1] - c[o2]);
			}
		});
		int t = nextInt();
		long p[] = new long[t];
		for (int i = 0; i < t; i++) {
			p[i] = nextLong();
		}
		long ans = 0;
		int curMul = 0;
		long pos = 0;
		int curFigure = 0;
		long figurePos = 0;
		while (curFigure < n) {
			long haveFigure = k[idx[curFigure]] - figurePos;
			if (curMul < t) {
				long haveMul = p[curMul] - pos;
				if (haveMul < haveFigure) {
					ans += c[idx[curFigure]] * (curMul + 1) * haveMul;
					figurePos += haveMul;
					pos += haveMul;
					++curMul;
					continue;
				}
			}
			ans += c[idx[curFigure]] * (curMul + 1) * haveFigure;
			pos += haveFigure;
			++curFigure;
			figurePos = 0;
		}
		out.println(ans);
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