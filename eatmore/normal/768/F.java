import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class F {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static int inv(int a) {
		return BigInteger.valueOf(a).modInverse(BigInteger.valueOf(MOD)).intValue();
	}

	static void solve() throws Exception {
		int f = nextInt();
		int w = nextInt();
		int h = nextInt();
		int facts[] = new int[max(f, w) + 1];
		facts[0] = 1;
		for (int i = 1; i < facts.length; i++) {
			facts[i] = mul(facts[i - 1], i);
		}
		int totalNum = 0, totalDen = 1, goodNum = 0, goodDen = 1;
		for (int cntF = 0; cntF <= f; cntF++) {
			if ((f == 0) != (cntF == 0)) {
				continue;
			}
			int curNum, curDen;
			if (f == 0) {
				curNum = curDen = 1;
			} else {
				curNum = facts[f - 1];
				curDen = mul(facts[cntF - 1], facts[f - cntF]);
			}
			for (int cntW = max(cntF - 1, 0); cntW <= min(cntF + 1, w); cntW++) {
				if ((w == 0) != (cntW == 0)) {
					continue;
				}
				int curNum2, curDen2;
				if (w == 0) {
					curNum2 = curNum;
					curDen2 = curDen;
				} else {
					curNum2 = mul(curNum, facts[w - 1]);
					curDen2 = mul(curDen, mul(facts[cntW - 1], facts[w - cntW]));
				}
				if (cntF == cntW) {
					curNum2 = add(curNum2, curNum2);
				}
				totalNum = add(mul(totalNum, curDen2), mul(totalDen, curNum2));
				totalDen = mul(totalDen, curDen2);
				if (w == 0) {
					goodNum = add(mul(goodNum, curDen2), mul(goodDen, curNum2));
					goodDen = mul(goodDen, curDen2);
				} else if ((long) cntW * (h + 1) <= w) {
					curNum2 = mul(curNum, facts[w - cntW * h - 1]);
					curDen2 = mul(curDen, mul(facts[cntW - 1], facts[w - cntW * (h + 1)]));
					if (cntF == cntW) {
						curNum2 = add(curNum2, curNum2);
					}
					goodNum = add(mul(goodNum, curDen2), mul(goodDen, curNum2));
					goodDen = mul(goodDen, curDen2);
				}
			}
		}
		out.print(mul(mul(goodNum, totalDen), inv(mul(goodDen, totalNum))));
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