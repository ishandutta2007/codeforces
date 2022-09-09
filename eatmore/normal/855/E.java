import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static long data[][][] = new long[11][][];
	static {
		for (int base = 2; base <= 10; base++) {
			long cData[][] = data[base] = new long[64][];
			for (int len = 0; len < 64; len++) {
				long ccData[] = cData[len] = new long[len + 1];
				if (len == 0) {
					ccData[0] = 1;
				} else {
					for (int cnt = len % 2; cnt <= len && cnt <= base; cnt += 2) {
						long v = 0;
						if (cnt > 0) {
							v = cnt * cData[len - 1][cnt - 1];
						}
						if (cnt < base && cnt < len) {
							v += (base - cnt) * cData[len - 1][cnt + 1];
						}
						ccData[cnt] = v;
					}
				}
			}
		}
	}

	static long get(int b, long l) {
		int cnt = 0;
		long pow = 1;
		long ans = 0;
		while (true) {
			if (pow * b / b != pow || pow * b > l) {
				break;
			}
//			System.err.println("Q1 " + cnt + " " + 1);
			if (cnt >= 1) {
				ans += (b - 1) * data[b][cnt][1];
			}
			pow *= b;
			++cnt;
		}
		int set = 0;
		boolean init = true;
		while (cnt >= 0) {
			for (int i = init ? 1 : 0; i < l / pow; i++) {
				set ^= 1 << i;
				int c = Integer.bitCount(set);
//				System.err.println("Q2 " + cnt + " " + c);
				if (c <= cnt) {
					ans += data[b][cnt][c];
				}
				set ^= 1 << i;
			}
			int i = (int) (l / pow);
//			System.err.println("P " + cnt + " " + i);
			set ^= 1 << i;
			l -= i * pow;
			pow /= b;
			--cnt;
			init = false;
		}
		return ans;
	}

	static void solve() throws Exception {
		int q = scanInt();
//		int q = 100000;
		for (int qq = 0; qq < q; qq++) {
			int b = scanInt();
			long l = scanLong();
			long r = scanLong();
//			int b = 2;
//			long l = 1000000000000000000L, r = 1000000000000000000L;
			out.println(get(b, r + 1) - get(b, l));
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