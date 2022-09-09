import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class E {

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

		void clear() {
			size = 0;
		}

		void set(int index, int value) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			data[index] = value;
		}

		void expand() {
			if (size >= data.length) {
				data = copyOf(data, (data.length << 1) + 1);
			}
		}

		void insert(int index, int value) {
			if (index < 0 || index > size) {
				throw new IndexOutOfBoundsException();
			}
			expand();
			arraycopy(data, index, data, index + 1, size++ - index);
			data[index] = value;
		}

		int delete(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			int value = data[index];
			arraycopy(data, index + 1, data, index, --size - index);
			return value;
		}

		void push(int value) {
			expand();
			data[size++] = value;
		}

		int pop() {
			if (size == 0) {
				throw new NoSuchElementException();
			}
			return data[--size];
		}

		void unshift(int value) {
			expand();
			arraycopy(data, 0, data, 1, size++);
			data[0] = value;
		}

		int shift() {
			if (size == 0) {
				throw new NoSuchElementException();
			}
			int value = data[0];
			arraycopy(data, 1, data, 0, --size);
			return value;
		}
	}

	static int v[];
	static IntList edges[];
	static int ans;

	static void solve() throws Exception {
		int n = scanInt();
		v = new int[n];
		int vsum = 0;
		for (int i = 0; i < n; i++) {
			v[i] = scanInt() % MOD;
			if (v[i] < 0) {
				v[i] += MOD;
			}
			vsum = add(vsum, v[i]);
		}
		edges = new IntList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new IntList();
		}
		for (int i = 0; i < n - 1; i++) {
			int a = scanInt() - 1;
			int b = scanInt() - 1;
			edges[a].push(b);
			edges[b].push(a);
		}
		ans = 0;
		dfs(0, -1);
		out.print(sub(add(ans, ans), vsum));
	}

	static int resCntEven, resSumEven, resCntOdd, resSumOdd;
	static void dfs(int cur, int prev) {
		int cntEven = 0, sumEven = 0, cntOdd = 0, sumOdd = 0;
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur].get(i);
			if (next == prev) {
				continue;
			}
			dfs(next, cur);
			ans = add(ans, mul(sumEven, resCntEven));
			ans = add(ans, mul(resSumEven, cntEven));
			ans = add(ans, mul(sumOdd, resCntOdd));
			ans = add(ans, mul(resSumOdd, cntOdd));
			ans = add(ans, mul(v[cur], sub(mul(cntEven, resCntEven), mul(cntOdd, resCntOdd))));
			cntEven += resCntEven;
			sumEven = add(sumEven, resSumEven);
			cntOdd += resCntOdd;
			sumOdd = add(sumOdd, resSumOdd);
		}
		resCntOdd = cntEven + 1;
		resSumOdd = add(sumEven, mul(v[cur], resCntOdd));
		ans = add(ans, resSumOdd);
		resCntEven = cntOdd;
		resSumEven = sub(sumOdd, mul(v[cur], cntOdd));
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