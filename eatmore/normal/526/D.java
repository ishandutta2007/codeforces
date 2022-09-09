import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static final Random rng = new Random(42);
	
	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
//		int n = 1 + rng.nextInt(10);
//		int k = 2 + rng.nextInt(5);
		if (k == 1) {
			for (int i = 0; i < n; i++) {
				out.print('1');
			}
			return;
		}
		String s = next();
//		String s;
//		{
//			int c = 1 + rng.nextInt(5);
//			char ss[] = new char[n];
//			for (int i = 0; i < n; i++) {
//				ss[i] = (char) ('a' + rng.nextInt(c));
//			}
//			s = new String(ss);
//		}
//		char dumb[] = solveDumb(n, k, s);
		int pfun[] = new int[n];
		int pfunClamped[] = new int[n];
		out.print('0');
		for (int i = 1; i < n; i++) {
			char c = s.charAt(i);
			int cp = pfun[i - 1];
			while (s.charAt(cp) != c) {
				if (cp == 0) {
					cp = -1;
					break;
				}
				cp = pfun[cp - 1];
			}
			pfun[i] = ++cp;
			cp = pfunClamped[i - 1];
			while (s.charAt(cp) != c || (long) (cp + 1) * (k + 1) > (long) k * (i + 1)) {
				if (cp == 0) {
					cp = -1;
					break;
				}
				cp = pfun[cp - 1];
			}
			pfunClamped[i] = ++cp;
//			if (dumb[i] != ((long) cp * k >= (long) (k - 1) * (i + 1) ? '1' : '0')) {
//				System.err.println(n + " " + k + " " + s + " " + new String(dumb) + " " + i + " " + Arrays.toString(pfun));
//				throw new AssertionError();
//			}
			out.print((long) cp * k >= (long) (k - 1) * (i + 1) ? '1' : '0');
		}
	}
	
//	static char[] solveDumb(int n, int k, String s) {
//		char ans[] = new char[n];
//		for (int i = 1; i <= n; i++) {
//			ans[i - 1] = '0';
//			String cs = s.substring(0, i);
//			for (int j = (i * (k - 1) + k - 1) / k; j <= i * k / (k + 1); j++) {
//				if (cs.substring(0, j).equals(cs.substring(i - j, i))) {
//					ans[i - 1] = '1';
//					break;
//				}
//			}
//		}
//		return ans;
//	}
	
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