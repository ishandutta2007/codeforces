import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static void solve() throws Exception {
		int n = scanInt();
		long c = scanLong();
		long v1[] = new long[n], v1Add = 0;
		long v2[] = new long[n], v2Add = 0;
		long s = scanLong();
		s = min(s, c);
		long ans = s;
		v1[0] = c - s;
		int head = 0, tail = 1;
//		System.err.println("POS 0 BUY " + s + " ANS " + ans + " SEQ [(0 " + (c - s) + ")]");
		for (int i = 1; i < n; i++) {
			long s1 = scanLong(), s2 = scanLong();
			v2Add += s1 + s2;
			while (tail != head && v2[tail - 1] + v2Add <= s2) {
				--tail;
			}
			if (tail == head || v1[tail - 1] + v1Add < c) {
				v1[tail] = c - v1Add;
				v2[tail] = s2 - v2Add;
				++tail;
			}
			long add;
			if (v1[head] + v1Add <= v2[head] + v2Add) {
				while (head + 1 != tail && v1[head + 1] + v1Add <= v2[head + 1] + v2Add) {
					++head;
				}
				add = v1[head] + v1Add;
				++head;
				if (head != tail) {
					add = max(add, v2[head] + v2Add);
				}
			} else {
				add = v2[head] + v2Add;
			}
			ans += add;
			v1Add -= add;
			v2Add -= add;
//			System.err.print("POS " + i + " BUY " + add + " ANS " + ans + " SEQ [");
//			for (int j = head; j != tail; j++) {
//				if (j != head) {
//					System.err.print(' ');
//				}
//				System.err.print("(" + (v2[j] + v2Add) + " " + (v1[j] + v1Add) + ")");
//			}
//			System.err.println(']');
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