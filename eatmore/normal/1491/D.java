import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int q = scanInt();
		q: for (int qq = 0; qq < q; qq++) {
			int u = scanInt(), v = scanInt();
			int cu = Integer.bitCount(u), cv = Integer.bitCount(v);
			if (cv > cu) {
				out.println("NO");
				continue;
			}
			int d = cu - cv;
			while (true) {
				int i = 31 - Integer.numberOfLeadingZeros(u), j = 31 - Integer.numberOfLeadingZeros(v);
				if (i > j) {
					out.println("NO");
					continue q;
				} else if (i < j) {
					while (d > 0) {
						u ^= 1 << i;
						i = 31 - Integer.numberOfLeadingZeros(u);
						--d;
					}
				} else if (i < 0) {
					break;
				}
				u ^= 1 << i;
				v ^= 1 << j;
			}
			out.println("YES");
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