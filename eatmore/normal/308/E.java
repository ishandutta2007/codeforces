import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

//	static final Random rng = new Random(42);
	
	static void solve() throws Exception {
		int n = nextInt();
//		int n = rng.nextInt(10) + 1;
		final int l[] = new int[n];
		final int r[] = new int[n];
		for (int i = 0; i < n; i++) {
			l[i] = nextInt();
			r[i] = nextInt();
//			l[i] = rng.nextInt(5);
//			r[i] = l[i] + rng.nextInt(5);
			
		}
		int left = -1;
		int right = n - 1;
		int rightOrder[] = new int[n];
		for (int i = 0; i < n; i++) {
			rightOrder[i] = i;
		}
		int order[] = new int[n];
		int deadline[] = new int[n];
		int deadlineCount[] = new int[n];
		bs: while (left + 1 < right) {
			int mid = (left + right) >>> 1;
			fill(deadline, n - 1);
			fill(deadlineCount, 0);
			deadlineCount[n - 1] = n;
			for (int i = 0; i < n; i++) {
				int looseness = 0;
				int j;
				for (j = i; ; j++) {
					if (j >= n) {
						throw new AssertionError();
					}
					looseness += 1 - deadlineCount[j];
					if (looseness <= 0) {
						break;
					}
				}
				if (looseness < 0) {
					left = mid;
					continue bs;
				}
				int best = -1, bestR = Integer.MAX_VALUE;
				for (int jj = 0; jj < n; jj++) {
					if (deadline[jj] < i || deadline[jj] > j) {
						continue;
					}
					if (r[jj] < bestR) {
						best = jj;
						bestR = r[jj];
					}
				}
				order[i] = best;
				--deadlineCount[deadline[best]];
				deadline[best] = -1;
				for (int jj = 0; jj < n; jj++) {
					if (l[best] <= r[jj] && l[jj] <= r[best] && deadline[jj] > i + mid) {
						if (mid == 0) {
							left = mid;
							continue bs;
						}
						--deadlineCount[deadline[jj]];
						deadline[jj] = i + mid;
						++deadlineCount[deadline[jj]];
					}
				}
			}
			right = mid;
			arraycopy(order, 0, rightOrder, 0, n);
		}
//		int ans = res(n, l, r, rightOrder);
//		if (ans != right) {
//			throw new AssertionError();
//		}
//		Integer testOrder[] = new Integer[n];
//		for (int i = 0; i < n; i++) {
//			testOrder[i] = i;
//		}
//		int testOrd[] = new int[n];
//		for (int i = 0; i < 5; i++) {
//			Collections.shuffle(Arrays.asList(testOrder));
//			for (int j = 0; j < n; j++) {
//				testOrd[j] = testOrder[j];
//			}
//			if (res(n, l, r, testOrd) < right) {
//				throw new AssertionError();
//			}
//		}
		for (int i = 0; i < n; i++) {
			out.print(rightOrder[i] + 1 + " ");
		}
//		out.println();
	}
	
//	static int res(int n, int l[], int r[], int order[]) {
//		int ans = 0;
//		for (int i = 0; i < n; i++) {
//			for (int j = i + 1; j < n; j++) {
//				int ii = order[i];
//				int jj = order[j];
//				if (l[ii] <= r[jj] && l[jj] <= r[ii]) {
//					ans = max(ans, j - i);
//				}
//			}
//		}
//		return ans;
//	}
	
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