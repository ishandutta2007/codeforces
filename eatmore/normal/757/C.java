import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class C {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

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

		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + Arrays.hashCode(data);
			result = prime * result + size;
			return result;
		}

		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			IntList other = (IntList) obj;
			if (!Arrays.equals(data, other.data))
				return false;
			if (size != other.size)
				return false;
			return true;
		}
	}

	static final int MOD = 1000000007;

	static int mul(int a, int b) {
		return (int) ((long) a * b % MOD);
	}

	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		IntList schools[] = new IntList[m];
		for (int i = 0; i < n; i++) {
			int g = nextInt();
			for (int j = 0; j < g; j++) {
				int k = nextInt() - 1;
				if (schools[k] == null) {
					schools[k] = new IntList();
				}
				schools[k].add(i);
			}
		}
		Map<IntList, Integer> cnts = new HashMap<>();
		int cnt0 = 0;
		for (IntList l: schools) {
			if (l == null) {
				++cnt0;
			} else {
				Integer v = cnts.get(l);
				cnts.put(l, v == null ? 1 : v + 1);
			}
		}
		int facts[] = new int[m + 1];
		facts[0] = 1;
		for (int i = 1; i <= m; i++) {
			facts[i] = mul(facts[i - 1], i);
		}
		int ans = facts[cnt0];
		for (int i: cnts.values()) {
			ans = mul(ans, facts[i]);
		}
		out.print(ans);
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