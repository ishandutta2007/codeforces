import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		String s1 = next();
		String s2 = next();
		solve(n, s1, s2);
//		int a1 = ans1;
//		int a2 = ans2;
//		solveDumb(n, s1, s2);
//		if (a1 != ans1 || a2 != ans2) {
//			throw new AssertionError();
//		}
		out.println(ans2 + " " + ans1);
	}

	static int ans1, ans2;
	static void solve(int n, String s1, String s2) {
		int a1[] = s2n(s1);
		int a2[] = s2n(s2);
//		System.err.println(Arrays.toString(a1));
//		System.err.println(Arrays.toString(a2));
		int len1 = a1.length;
		int len2 = a2.length;
		int gcd = gcd(len1, len2);
		int len1mod = len1 / gcd;
		int s2full = n / len2;
		int sums[][] = new int[3][len1];
		int csums[] = new int[3];
		for (int mod = 0; mod < gcd; mod++) {
			fill(csums, 0);
			for (int i = mod; i < len1; i += gcd) {
				csums[a1[i]]++;
			}
			for (int i = 0; i < 3; i++) {
				csums[i] *= s2full / len1mod;
			}
			int p1 = mod, p2 = mod;
			for (int i = 0; i < s2full % len1mod; i++) {
				csums[a1[p2]]++;
				p2 = (p2 + len2) % len1;
			}
			for (int i = 0; i < len1mod; i++) {
				for (int j = 0; j < 3; j++) {
					sums[j][p1] = csums[j];
				}
				csums[a1[p1]]--;
				csums[a1[p2]]++;
				p1 = (p1 + len2) % len1;
				p2 = (p2 + len2) % len1;
			}
		}
//		System.err.println(gcd + " " + len1mod + " " + (len2 / gcd) + " " + s2full + " " + Arrays.deepToString(sums));
		ans1 = 0;
		ans2 = 0;
		for (int i = 0; i < len2; i++) {
			for (int j = 0; j < 3; j++) {
				switch ((a2[i] - j + 3) % 3) {
				case 1:
					ans2 += sums[j][i % len1];
					break;
				case 2:
					ans1 += sums[j][i % len1];
					break;
				}
			}
		}
		for (int i = s2full * len2; i < n; i++) {
			switch ((a2[i % len2] - a1[i % len1] + 3) % 3) {
			case 1:
				ans2++;
				break;
			case 2:
				ans1++;
				break;
			}
		}
	}
	
//	static void solveDumb(int n, String s1, String s2) {
//		int a1[] = s2n(s1);
//		int a2[] = s2n(s2);
//		ans1 = 0;
//		ans2 = 0;
//		for (int i = 0; i < n; i++) {
//			switch ((a2[i % a2.length] - a1[i % a1.length] + 3) % 3) {
//			case 1:
//				++ans2;
//				break;
//			case 2:
//				++ans1;
//			}
//		}
//	}
	
	static int[] s2n(String s) {
		int n[] = new int[s.length()];
		for (int i = 0; i < n.length; i++) {
			n[i] = "PSR".indexOf(s.charAt(i));
		}
		return n;
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