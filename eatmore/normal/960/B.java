import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		int n = scanInt();
		int ops = scanInt() + scanInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
		}
		for (int i = 0; i < n; i++) {
			a[i] -= scanInt();
		}
		for (int i = 0; i < ops; i++) {
			int maxI = 0;
			for (int j = 0; j < n; j++) {
				if (abs(a[maxI]) < abs(a[j])) {
					maxI = j;
				}
			}
			if (a[maxI] > 0) {
				--a[maxI];
			} else {
				++a[maxI];
			}
		}
		long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (long) a[i] * a[i];
		}
		out.print(ans);
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