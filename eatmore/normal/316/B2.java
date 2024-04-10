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
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int n = nextInt();
		int x = nextInt() - 1;
		int a[] = new int[n];
		int aRev[] = new int[n];
		fill(aRev, -1);
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
			if (a[i] >= 0) {
				aRev[a[i]] = i;
			}
		}
		boolean see[] = new boolean[n];
		List<Integer> lines = new ArrayList<>();
		int xLine = -1;
		int xPos = -1;
		for (int i = 0; i < n; i++) {
			if (see[i]) {
				continue;
			}
			int j = i;
			while (a[j] >= 0) {
				j = a[j];
			}
			int cnt = 0;
			while (true) {
				if (j == x) {
					xLine = lines.size();
					xPos = cnt;
				}
				see[j] = true;
				++cnt;
				if (aRev[j] >= 0) {
					j = aRev[j];
				} else {
					break;
				}
			}
			lines.add(cnt);
		}
		int xLength = lines.remove(xLine);
		boolean can[] = new boolean[n + 1 - xLength];
		can[0] = true;
		int csum = 0;
		for (int i: lines) {
			for (int j = csum; j >= 0; j--) {
				if (can[j]) {
					can[j + i] = true;
				}
			}
			csum += i;
		}
		if (csum != n - xLength) {
			throw new AssertionError();
		}
		for (int i = 0; i < can.length; i++) {
			if (can[i]) {
				out.println(i + xPos + 1);
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