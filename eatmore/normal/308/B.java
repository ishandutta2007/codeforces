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
	
	static void solve() throws Exception {
		int n = nextInt();
		int r = nextInt();
		int c = nextInt();
		String words[] = new String[n];
		int wl[] = new int[n];
		for (int i = 0; i < n; i++) {
			words[i] = next();
			wl[i] = words[i].length();
		}
		int nextLine[] = new int[n + 1];
		int p1 = 0, p2 = 0, pos1 = 0, pos2 = 0;
		while (p2 < n) {
			int npos2 = pos2 + wl[p2] + 1;
			if (npos2 > c + 1) {
				break;
			}
			++p2;
			pos2 = npos2;
		}
		while (true) {
			nextLine[p1] = p2;
			if (p1 >= n) {
				break;
			}
			pos1 += wl[p1] + 1;
			++p1;
			if (p2 < p1) {
				p2 = p1;
				pos2 = pos1;
			}
			while (p2 < n) {
				int npos2 = pos2 + wl[p2] + 1;
				if (npos2 - pos1 > c + 1) {
					break;
				}
				++p2;
				pos2 = npos2;
			}
		}
//		System.err.println(Arrays.toString(nextLine));
		int pow[] = nextLine.clone();
		int tmp[] = new int[n + 1];
		for (int i = 30 - Integer.numberOfLeadingZeros(r); i >= 0; i--) {
			for (int j = 0; j <= n; j++) {
				tmp[j] = pow[pow[j]];
			}
			{
				int t[] = pow;
				pow = tmp;
				tmp = t;
			}
			if ((r & (1 << i)) != 0) {
				for (int j = 0; j <= n; j++) {
					tmp[j] = nextLine[pow[j]];
				}
				{
					int t[] = pow;
					pow = tmp;
					tmp = t;
				}
			}
		}
//		System.err.println(Arrays.toString(pow));
		int ans = n;
		int ansLength = 0;
		for (int i = 0; i < n; i++) {
			if (pow[i] - i > ansLength) {
				ans = i;
				ansLength = pow[i] - i;
			}
		}
		for (int row = 0; row < r; row++) {
			int column = 0;
			boolean first = true;
			while (ans < n) {
				if (column + wl[ans] + 1 > c + 1) {
					break;
				}
				if (first) {
					first = false;
				} else {
					out.print(' ');
				}
				out.print(words[ans]);
				column += wl[ans] + 1;
				++ans;
			}
			out.println();
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