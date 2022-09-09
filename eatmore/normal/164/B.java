import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

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
		int l1 = nextInt();
		int l2 = nextInt();
		int c1[] = new int[l1];
		for (int i = 0; i < l1; i++) {
			c1[i] = nextInt() - 1;
		}
		int c2[] = new int[l2];
		for (int i = 0; i < l2; i++) {
			c2[i] = nextInt() - 1;
		}
		int ans = solve(c1, c2);
		out.println(ans);
	}

	static int solve(int[] c1, int[] c2) {
		int l1 = c1.length;
		int l2 = c2.length;
		int pos2[] = new int[1000000];
		fill(pos2, -1);
		for (int i = 0; i < l2; i++) {
			pos2[c2[i]] = i;
		}
		long dyn[] = new long[2 * l1];
		boolean dynBad[] = new boolean[dyn.length];
		long curDyn = 0;
		for (int i = 0; i < 2 * l1; i++) {
			int c = c1[i % l1];
			int cPos = pos2[c];
			if (cPos < 0) {
				curDyn += l2;
			} else {
				curDyn += ((cPos - curDyn) % l2 + l2) % l2;
			}
			dyn[i] = curDyn;
			if (cPos < 0) {
				curDyn += l2;
				dynBad[i] = true;
			}
		}
//		System.err.println(Arrays.toString(c1));
//		System.err.println(Arrays.toString(c2));
//		System.err.println(Arrays.toString(dyn));
//		System.err.println(Arrays.toString(dynBad));
		int p1 = 0, p2 = 0;
		while (p2 < dyn.length && p2 < p1 + l1 && dyn[p2] < dyn[p1] + l2) {
			++p2;
		}
		if (dynBad[p1]) {
			p1 = p2;
		}
		int ans = p2 - p1;
//		System.err.println("p " + p1 + " " + p2);
		while (++p1 < dyn.length) {
			while (p2 < dyn.length && p2 < p1 + l1 && dyn[p2] < dyn[p1] + l2) {
				++p2;
			}
			boolean x = dynBad[p1];
			if (x) {
				p1 = p2;
			}
//			System.err.println("p " + p1 + " " + p2);
			ans = max(ans, p2 - p1);
			if (x) {
				--p1;
			}
		}
		return ans;
	}
	
	static int nextInt() throws IOException {
		int c;
		do {
			c = in.read();
			if (c < 0) {
				throw new AssertionError();
			}
		} while (c < '0' || c > '9');
		int ans = 0;
		do {
			ans = ans * 10 + (c - '0');
			c = in.read();
		} while (c >= '0' && c <= '9');
		return ans;
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