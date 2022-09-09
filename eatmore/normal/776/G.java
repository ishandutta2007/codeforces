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

public class G {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static final long pows[][] = new long[17][16]; // [base][exp]
	static {
		for (int i = 0; i < 17; i++) {
			long p = 1;
			for (int j = 0; j < 16; j++) {
				pows[i][j] = p;
				p *= i;
			}
		}
	}

	static final int digitsWithBit[][] = new int[17][4]; // [digitLimit][bit]
	static {
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 4; j++) {
				digitsWithBit[i + 1][j] = ((i & (1 << j)) != 0) ? digitsWithBit[i][j] + 1 : digitsWithBit[i][j];
			}
		}
	}

	static long getAns(long limit, int digitLimit, int bit, int curDigit) {
		if (limit >= 1L << (4 * curDigit)) {
			return bit < 4 * curDigit ?
				pows[digitLimit][curDigit - 1] * digitsWithBit[digitLimit][bit & 3] :
				pows[digitLimit][curDigit];
		}
		if (limit == 0) {
			return 0;
		}
		int d = (int) (limit >> (4 * (curDigit - 1)));
		if (d >= digitLimit) {
			return bit < 4 * curDigit ?
				pows[digitLimit][curDigit - 1] * digitsWithBit[digitLimit][bit & 3] :
				pows[digitLimit][curDigit];
		}
		long res = bit < 4 * (curDigit - 1) ?
			pows[digitLimit][curDigit - 2] * digitsWithBit[digitLimit][bit & 3] :
			pows[digitLimit][curDigit - 1];
		res *= (bit >= 4 * (curDigit - 1) && bit < 4 * curDigit) ? digitsWithBit[d][bit & 3] : d;
		if (bit >= 4 * (curDigit - 1) && bit < 4 * curDigit && (d & (1 << (bit & 3))) == 0) {
			return res;
		}
		return res + getAns(limit - ((long) d << (4 * (curDigit - 1))), digitLimit, bit, curDigit - 1);
	}

	static long getAns(long limit) {
		long ans = 0;
		for (int digit = 0; digit < 16; digit++) {
			ans += getAns(limit, digit + 1, digit, 15) - getAns(limit, digit, digit, 15);
		}
		return ans;
	}

	static void solve() throws Exception {
		int q = nextInt();
		for (int i = 0; i < q; i++) {
			long l = parseLong(next(), 16);
			long r = parseLong(next(), 16);
			out.println(getAns(r + 1) - getAns(l));
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