import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class E {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		if (res >= MOD) {
			res -= MOD;
		}
		return res;
	}

	static int mul(int a, int b) {
		return (int) ((long) a * b % MOD);
	}

	static int inv(int a) {
		return BigInteger.valueOf(a).modInverse(BigInteger.valueOf(MOD)).intValue();
	}

	static class IntList {

		int data[] = new int[3];
		int size = 0;

		boolean isEmpty() {
			return size == 0;
		}

		int size() {
			return size;
		}

		int get(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			return data[index];
		}

		void set(int index, int value) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			data[index] = value;
		}

		void add(int value) {
			if (size >= data.length) {
				data = copyOf(data, (data.length << 1) + 1);
			}
			data[size++] = value;
		}

		int remove(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			int value = data[index];
			arraycopy(data, index + 1, data, index, --size - index);
			return value;
		}

		void clear() {
			size = 0;
		}
	}

	static void solve() throws Exception {
		int primes[] = new int[200];
		pr: for (int i = 0, pr = 2; i < primes.length; pr++) {
			for (int j = 0; j < i && primes[j] * primes[j] <= pr; j++) {
				if (pr % primes[j] == 0) {
					continue pr;
				}
			}
			primes[i++] = pr;
		}
		int facts[] = new int[1100000];
		facts[0] = 1;
		for (int i = 1; i < facts.length; i++) {
			facts[i] = mul(facts[i - 1], i);
		}
		char buf[] = new char[11];
		int tests = nextInt();
//		int tests = 1000000;
		int resNums[] = new int[tests];
		int resDens[] = new int[tests];
		for (int test = 0; test < tests; test++) {
			int r = nextInt();
			int v = nextInt();
//			int r = 0xfffff;
//			int v = 1021020;
			if (r == 0) {
				int npows = 0;
				for (int i = 0; primes[i] * primes[i] <= v; i++) {
					if (v % primes[i] == 0) {
						++npows;
						do {
							v /= primes[i];
						} while (v % primes[i] == 0);
					}
				}
				if (v > 1) {
					++npows;
				}
				resNums[test] = 1 << npows;
				resDens[test] = 1;
			} else {
				int num = 1, den = 1;
				for (int i = 0; primes[i] * primes[i] <= v; i++) {
					if (v % primes[i] == 0) {
						int pow = 0;
						do {
							v /= primes[i];
							++pow;
						} while (v % primes[i] == 0);
						int cNum = 0, cDen = 1;
						for (int j = 0; j <= pow; j++) {
							int nNum = facts[j + r - 1];
							int nDen = mul(facts[j], facts[r - 1]);
							if (j < pow) {
								nNum = add(nNum, nNum);
							}
							cNum = add(mul(cNum, nDen), mul(cDen, nNum));
							cDen = mul(cDen, nDen);
						}
						num = mul(num, cNum);
						den = mul(den, cDen);
					}
				}
				if (v > 1) {
					num = mul(num, r + 2);
				}
				resNums[test] = num;
				resDens[test] = den;
			}
		}
		int prod = 1;
		for (int i = 0; i < tests; i++) {
			prod = mul(prod, resDens[i]);
			if (i < tests - 1) {
				resNums[i + 1] = mul(resNums[i + 1], prod);
			}
		}
		prod = inv(prod);
		for (int i = tests - 1; i >= 0; i--) {
			resNums[i] = mul(resNums[i], prod);
			prod = mul(prod, resDens[i]);
		}
		for (int test = 0; test < tests; test++) {
			int res = resNums[test];
			buf[10] = '\n';
			int i;
			for (i = 9; i == 9 || res > 0; i--, res /= 10) {
				buf[i] = (char) (res % 10 + '0');
			}
			out.write(buf, i + 1, 10 - i);
		}
	}

	static int nextInt() throws IOException {
		int c = in.read();
		while (!('0' <= c && c <= '9')) {
			c = in.read();
		}
		int r = c - '0';
		while ('0' <= (c = in.read()) && c <= '9') {
			r = 10 * r + (c - '0');
		}
		return r;
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