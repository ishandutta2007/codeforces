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

	static int fibs[] = new int[30];
	static {
		fibs[0] = fibs[1] = 1;
		for (int i = 2; i < fibs.length; i++) {
			fibs[i] = fibs[i - 1] + fibs[i - 2];
		}
	}
	static IntList edges[];

	static void solve() throws Exception {
		int n = scanInt();
		edges = new IntList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new IntList();
		}
		for (int i = 1; i < n; i++) {
			int u = scanInt() - 1, v = scanInt() - 1;
			edges[u].push(v);
			edges[v].push(u);
		}
		int m;
		for (int i = 0;; i++) {
			if (n == fibs[i]) {
				m = i;
				break;
			}
			if (n < fibs[i]) {
				out.println("NO");
				return;
			}
		}
		int res = dfs(0, -1, m);
		out.println(res == -1 ? "YES" : "NO");
	}

	static int dfs(int cur, int prev, int m) {
		if (m <= 1) {
			return -1;
		}
		int size = 1;
		IntList c = edges[cur];
		for (int i = 0; i < c.size; i++) {
			int next = c.data[i];
			if (next != prev) {
				int nextRes = dfs(next, cur, m);
				if (nextRes < 0) {
					return nextRes;
				}
				size += nextRes;
			}
		}
		if (size == fibs[m - 1] || size == fibs[m - 2]) {
			if (size == fibs[m - 2]) {
				int t = cur;
				cur = prev;
				prev = t;
			}
			c = edges[cur];
			for (int i = 0; i < c.size; i++) {
				if (c.data[i] == prev) {
					c.data[i] = c.data[c.size - 1];
					--c.size;
					break;
				}
			}
			c = edges[prev];
			for (int i = 0; i < c.size; i++) {
				if (c.data[i] == cur) {
					c.data[i] = c.data[c.size - 1];
					--c.size;
					break;
				}
			}
			return dfs(cur, -1, m - 1) == -1 && dfs(prev, -1, m - 2) == -1 ? -1 : -2;
		}
		return size;
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