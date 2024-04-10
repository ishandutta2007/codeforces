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

public class E {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

//	static class State {
//		final int have;
//		final long turns;
//
//		public State(int have, long turns) {
//			this.have = have;
//			this.turns = turns;
//		}
//
//		public int hashCode() {
//			final int prime = 31;
//			int result = 1;
//			result = prime * result + have;
//			result = prime * result + (int) (turns ^ (turns >>> 32));
//			return result;
//		}
//
//		public boolean equals(Object obj) {
//			if (this == obj)
//				return true;
//			if (obj == null)
//				return false;
//			if (getClass() != obj.getClass())
//				return false;
//			State other = (State) obj;
//			if (have != other.have)
//				return false;
//			if (turns != other.turns)
//				return false;
//			return true;
//		}
//	}
//
//	static final Map<State, Integer> grundy = new HashMap<>();
//
//	static int grundy(int have, long turns) {
//		State key = new State(have, turns);
//		Integer res = grundy.get(key);
//		if (res == null) {
//			long not = 0;
//			for (int turn = 1; turn <= have; turn++) {
//				if ((turns & (1L << turn)) == 0) {
//					not |= 1L << grundy(have - turn, turns | (1L << turn));
//				}
//			}
//			for (int i = 0;; i++) {
//				if ((not & (1L << i)) == 0) {
//					res = i;
//					break;
//				}
//			}
//			grundy.put(key, res);
//		}
//		return res;
//	}

	static void solve() throws Exception {
		int grundy[] = /*new int[61];
		for (int i = 0; i < 61; i++) {
			grundy[i] = grundy(i, 0);
		}*/ {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};
		System.err.println(Arrays.toString(grundy));
		int n = nextInt();
		int res = 0;
		for (int i = 0; i < n; i++) {
			res ^= grundy[nextInt()];
		}
		out.print(res == 0 ? "YES" : "NO");
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