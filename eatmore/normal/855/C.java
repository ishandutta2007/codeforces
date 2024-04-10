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

public class C {

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

	static IntList edges[];
	static int m, k, x;

	static void solve() throws Exception {
		int n = scanInt();
		m = scanInt();
//		int n = 100000;
//		m = 1000000000;
		if (n < 1 || n > 100000 || m < 1 || m > 1000000000) {
			throw new AssertionError();
		}
		edges = new IntList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new IntList();
		}
		for (int i = 0; i < n - 1; i++) {
			int a = scanInt() - 1;
			int b = scanInt() - 1;
//			int a = i, b = i + 1;
			edges[a].push(b);
			edges[b].push(a);
		}
		k = scanInt() - 1;
		x = scanInt();
//		k = 500000000;
//		x = 10;
		if (k < 0 || k >= m || x < 1 || x > 10) {
			throw new AssertionError();
		}
		data = new int[3 * (x + 1) * (2 * n - 1)];
		free = 0;
		int res = dfs(0, -1);
		if (free != data.length) {
			throw new AssertionError();
		}
		int ans = 0;
		for (int i = 0; i <= x; i++) {
			ans = add(ans, data[res + i]);
		}
		out.print(ans);
	}

	static int data[], free;

	static int dfs(int cur, int prev) {
		int res = free; // <k, =k, >k
		free += 3 * (x + 1);
		data[res] = k;
		data[res + x + 2] = 1;
		data[res + 2 * x + 2] = m - k - 1;
		for (int i = 0; i < edges[cur].size; i++) {
			int next = edges[cur].get(i);
			if (next == prev) {
				continue;
			}
			int subres = dfs(next, cur); // all, <k, !=k
			int tmp = free;
			free += 3 * (x + 1);
			for (int ii = 0; ii < 3 * (x + 1); ii += x + 1) {
				for (int j = 0; j <= x; j++) {
					long v = 0;
					for (int jj = 0; jj <= j; jj++) {
						v += (long) data[res + ii + jj] * data[subres + ii + j - jj];
						v %= MOD;
					}
					data[tmp + ii + j] = (int) (v % MOD);
				}
			}
			res = tmp;
		}
		for (int i = 0; i <= x; i++) {
			int a = data[res + i], b = data[res + x + 1 + i], c = data[res + 2 * x + 2 + i];
//			a = mul(a, k);
//			c = mul(c, m - k - 1);
			c = add(a, c);
			data[res + i] = add(b, c);
			data[res + x + 1 + i] = a;
			data[res + 2 * x + 2 + i] = c;
		}
		return res;
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