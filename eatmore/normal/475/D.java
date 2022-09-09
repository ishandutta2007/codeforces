import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class IntList {
		int a[] = new int[4];
		int count = 0;
		int pointer = 0;
		int ndPointer = 0;
		int prevPow;
		
		int get(int i) {
			if (i < 0 || i > count) {
				throw new IndexOutOfBoundsException();
			}
			return a[i];
		}
		
		void add(int x) {
			if (count >= a.length) {
				a = Arrays.copyOf(a, a.length * 2);
			}
			a[count++] = x;
		}
		
		int size() {
			return count;
		}
		
		void clear() {
			count = 0;
		}
		
		void sort() {
			Arrays.sort(a, 0, count);
		}
		
		int nextNonelement() {
			if (ndPointer <= pointer) {
				ndPointer = pointer + 1;
				while (ndPointer < count && a[ndPointer - 1] + 1 == a[ndPointer]) {
					++ndPointer;
				}
			}
			return a[ndPointer - 1] + 1;
		}
	}
	
	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	static long get(Map<Integer, Long> map, int i) {
		Long r = map.get(i);
		return r == null ? 0 : r;
	}
	
	static void solve() throws Exception {
		int n = nextInt();
//		int n = 100000;
		int a[] = new int[n];
		IntList primes = new IntList();
		primes.add(2);
		Map<Integer, IntList> primePowers = new HashMap<>();
		IntList primeFactors[] = new IntList[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
//			a[i] = 1000000007;
			primeFactors[i] = new IntList();
			int cur = a[i];
			int j = 0;
			while (true) {
				if (j == primes.size()) {
					p: for (int p = primes.get(primes.size() - 1) + 1;; p++) {
						for (int ppi = 0;; ppi++) {
							int pp = primes.get(ppi);
							if (pp * pp > p) {
								primes.add(p);
//								System.err.println("ADDED PRIME " + p);
								break p;
							}
							if (p % pp == 0) {
								break;
							}
						}
					}
				}
				int p = primes.get(j);
				if (p * p > cur) {
					break;
				}
				if (cur % p == 0) {
					primeFactors[i].add(p);
					int cp = p;
					do {
						cur /= p;
						IntList cpp = primePowers.get(cp);
						if (cpp == null) {
							primePowers.put(cp, cpp = new IntList());
							cpp.prevPow = cp / p;
						}
						cpp.add(i);
						cp *= p;
					} while (cur % p == 0);
				}
				++j;
			}
			if (cur > 1) {
				primeFactors[i].add(cur);
				IntList cpp = primePowers.get(cur);
				if (cpp == null) {
					primePowers.put(cur, cpp = new IntList());
					cpp.prevPow = 1;
				}
				cpp.add(i);
			}
		}
		Map<Integer, Long> ans = new HashMap<>();
		IntList events = new IntList();
		for (int i = 0; i < n; i++) {
//			System.err.println("INDEX " + i + " VALUE " + a[i]);
			int cur = a[i];
			for (int j = 0; j < primeFactors[i].size(); j++) {
				int p = primeFactors[i].get(j);
				int cp = p;
				do {
					cur /= p;
					IntList cpp = primePowers.get(cp);
					if (cpp.get(cpp.pointer) != i) {
						throw new AssertionError();
					}
					events.add(cpp.nextNonelement());
//					System.err.println("POWER " + cp + " ENDS AT INDEX " + cpp.nextNonelement());
					++cpp.pointer;
					cp *= p;
				} while (cur % p == 0);
				
			}
			if (cur != 1) {
				throw new AssertionError();
			}
			events.sort();
			int pp = i;
			cur = a[i];
			for (int j = 0; j < events.size(); j++) {
				int p = events.get(j);
				if (p == pp) {
					continue;
				}
				ans.put(cur, get(ans, cur) + p - pp);
				pp = p;
				if (p >= n) {
					break;
				}
				cur = gcd(cur, a[p]);
			}
			ans.put(1, get(ans, 1) + n - pp);
			events.clear();
		}
		int q = nextInt();
//		int q = 300000;
		for (int i = 0; i < q; i++) {
			out.println(get(ans, nextInt()/*100000007*/));
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