import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
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
	static final int MOD2 = 1000000006;

	static int add(int a, int b, int mod) {
		int res = a + b;
		if (res >= mod) {
			res -= mod;
		}
		return res;
	}

	static int sub(int a, int b, int mod) {
		int res = a - b;
		if (res < 0) {
			res += mod;
		}
		return res;
	}

	static int mul(int a, int b, int mod) {
		return (int) ((long) a * b % mod);
	}

	static int pow10(int n) {
		if (n == 0) {
			return 1;
		}
		int res = 10;
		for (int i = 30 - Integer.numberOfLeadingZeros(n); i >= 0; i--) {
			res = mul(res, res, MOD);
			if ((n & (1 << i)) != 0) {
				res = mul(res, 10, MOD);
			}
		}
		return res;
	}

	static class Value {
		int length, valueNum, valueDen;

		Value(int length, int valueNum, int valueDen) {
			this.length = length;
			this.valueNum = valueNum;
			this.valueDen = valueDen;
		}

		Value(int length, int value) {
			this(length, value, 1);
		}

		void append(Value o) {
			length = add(length, o.length, MOD2);
			valueNum = add(mul(mul(valueNum, pow10(o.length), MOD), o.valueDen, MOD), mul(valueDen, o.valueNum, MOD), MOD);
			valueDen = mul(valueDen, o.valueDen, MOD);
		}

		void repeat(int mod1, int mod2) {
			if (length == 0) {
				valueNum = mul(valueNum, mod1, MOD);
			} else {
				valueNum = mul(valueNum, sub(pow10(mul(length, mod2, MOD2)), 1, MOD), MOD);
				valueDen = mul(valueDen, sub(pow10(length), 1, MOD), MOD);
				length = mul(length, mod2, MOD2);
			}
		}
	}

	static char s[];
	static int pos;

	static Value parseExpression() {
		Value v = parseTerm();
		while (pos < s.length && s[pos] == '+') {
			++pos;
			v.append(parseTerm());
		}
		return v;
	}

	static Value cseq(int len, int from1, int from2, int to1, int to2) {
		int n2 = sub(add(to2, 1, MOD2), from2, MOD2);
		int b = pow10(len);
		int pbn = pow10(mul(len, n2, MOD2));
		int pbn1 = mul(pbn, b, MOD);
		int num = add(add(sub(sub(mul(from1, sub(pbn1, pbn, MOD), MOD), mul(b, to1, MOD), MOD), b, MOD), to1, MOD), pbn, MOD);
		int bm1 = sub(b, 1, MOD);
		int den = mul(bm1, bm1, MOD);
		return new Value(mul(len, n2, MOD2), num, den);
	}

	static Value parseTerm() {
		parseNumber();
		if (pos < s.length && s[pos] == '-') {
			int l1 = retLen, v11 = retMod1, v12 = retMod2;
			++pos;
			parseNumber();
			int l2 = retLen, v21 = retMod1, v22 = retMod2;
			Value res;
			if (l1 == l2) {
				res = cseq(l1, v11, v12, v21, v22);
			} else {
				int p10_1 = 1, p10_2 = 1;
				for (int i = 0; i < l1; i++) {
					p10_1 = mul(p10_1, 10, MOD);
					p10_2 = mul(p10_2, 10, MOD2);
				}
				res = cseq(l1, v11, v12, sub(p10_1, 1, MOD), sub(p10_2, 1, MOD2));
				for (int i = l1 + 1; i < l2; i++) {
					int p10_1_new = mul(p10_1, 10, MOD);
					int p10_2_new = mul(p10_2, 10, MOD2);
					res.append(cseq(i, p10_1, p10_2, sub(p10_1_new, 1, MOD), sub(p10_2_new, 1, MOD2)));
					p10_1 = p10_1_new;
					p10_2 = p10_2_new;
				}
				res.append(cseq(l2, p10_1, p10_2, v21, v22));
			}
			return res;
		} else if (pos < s.length && s[pos] == '(') {
			int m1 = retMod1, m2 = retMod2;
			++pos;
			Value v = parseExpression();
			if (s[pos] != ')') {
				throw new AssertionError();
			}
			++pos;
			v.repeat(m1, m2);
			return v;
		} else {
			return new Value(retLen, retMod1);
		}
	}

	static int retLen, retMod1, retMod2;
	static void parseNumber() {
		if (!('1' <= s[pos] && s[pos] <= '9')) {
			throw new AssertionError();
		}
		int len = 0, mod1 = 0, mod2 = 0;
		do {
			++len;
			int i = s[pos++] - '0';
			mod1 = add(mul(mod1, 10, MOD), i, MOD);
			mod2 = add(mul(mod2, 10, MOD2), i, MOD2);
		} while (pos < s.length && '0' <= s[pos] && s[pos] <= '9');
		retLen = len;
		retMod1 = mod1;
		retMod2 = mod2;
	}

	static void solve() throws Exception {
		s = next().toCharArray();
		pos = 0;
		Value v = parseExpression();
		if (pos != s.length) {
			throw new AssertionError();
		}
		out.print(mul(v.valueNum, BigInteger.valueOf(v.valueDen).modInverse(BigInteger.valueOf(MOD)).intValue(), MOD));
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