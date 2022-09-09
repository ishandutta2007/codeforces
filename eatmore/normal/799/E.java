import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Collections.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.NavigableSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class E {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static class Token implements Comparable<Token> {
		final int id, cost;

		Token(int id, int cost) {
			this.id = id;
			this.cost = cost;
		}

		public int compareTo(Token o) {
			if (cost != o.cost) {
				return cost - o.cost;
			}
			return id - o.id;
		}
	}

	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int c[] = new int[n];
		for (int i = 0; i < n; i++) {
			c[i] = nextInt();
		}
		boolean sA[] = new boolean[n];
		int cntA = nextInt();
		for (int i = 0; i < cntA; i++) {
			sA[nextInt() - 1] = true;
		}
		boolean sB[] = new boolean[n];
		int cntB = nextInt();
		for (int i = 0; i < cntB; i++) {
			sB[nextInt() - 1] = true;
		}
		List<Token> costAB = new ArrayList<>();
		List<Token> costA = new ArrayList<>();
		List<Token> costB = new ArrayList<>();
		NavigableSet<Token> setN1 = new TreeSet<>();
		NavigableSet<Token> setN2 = new TreeSet<>();
		long sumA = 0, sumB = 0, sumN1 = 0;
		for (int i = 0; i < n; i++) {
			Token tok = new Token(i, c[i]);
			if (sA[i]) {
				if (sB[i]) {
					costAB.add(tok);
				} else {
					costA.add(tok);
					sumA += tok.cost;
				}
			} else {
				if (sB[i]) {
					costB.add(tok);
					sumB += tok.cost;
				} else {
					sumN1 += tok.cost;
					setN1.add(tok);
				}
			}
		}
		sort(costAB);
		sort(costA);
		sort(costB);
		long ans = Long.MAX_VALUE;
		long sumAB = 0;
		for (int i = 0; i <= costAB.size(); i++) {
			while (!costA.isEmpty() && costA.size() > k - i) {
				Token tok = costA.remove(costA.size() - 1);
				sumA -= tok.cost;
				if (setN2.isEmpty() || setN2.first().compareTo(tok) > 0) {
					sumN1 += tok.cost;
					setN1.add(tok);
				} else {
					setN2.add(tok);
				}
			}
			while (!costB.isEmpty() && costB.size() > k - i) {
				Token tok = costB.remove(costB.size() - 1);
				sumB -= tok.cost;
				if (setN2.isEmpty() || setN2.first().compareTo(tok) > 0) {
					sumN1 += tok.cost;
					setN1.add(tok);
				} else {
					setN2.add(tok);
				}
			}
			int target = i >= k ? m - i : m + i - 2 * k;
			while (!setN1.isEmpty() && setN1.size() > target) {
				Token tok = setN1.last();
				setN1.remove(tok);
				sumN1 -= tok.cost;
				setN2.add(tok);
			}
			while (!setN2.isEmpty() && setN1.size() < target) {
				Token tok = setN2.first();
				setN2.remove(tok);
				sumN1 += tok.cost;
				setN1.add(tok);
			}
			if (costA.size() == max(k - i, 0) && costB.size() == max(k - i, 0) && setN1.size() == target) {
				ans = min(ans, sumAB + sumA + sumB + sumN1);
			}
			if (i < costAB.size()) {
				sumAB += costAB.get(i).cost;
			}
		}
		out.print(ans == Long.MAX_VALUE ? -1 : ans);
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