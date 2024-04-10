import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
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
	static boolean seen[], visited[];
	static int depth[];
	static int count, cycleCount;

	static void solve() throws Exception {
		int n = scanInt();
		edges = new IntList[2 * n];
		for (int i = 0; i < edges.length; i++) {
			edges[i] = new IntList();
		}
		for (int i = 0; i < n; i++) {
			int a = scanInt() - 1;
			int b = scanInt() - 1;
			edges[a].push(i);
			edges[a].push(b);
			edges[b].push(i);
			edges[b].push(a);
		}
		seen = new boolean[2 * n];
		visited = new boolean[n];
		depth = new int[2 * n];
		int ans = 1;
		for (int i = 0; i < 2 * n; i++) {
			if (!seen[i]) {
				count = cycleCount = 0;
				dfs(i, 0);
				ans = mul(ans, cycleCount != 0 ? min(cycleCount, 2) : count);
			}
		}
		out.print(ans);
	}

	static void dfs(int cur, int curDepth) {
		if (seen[cur]) {
			cycleCount = curDepth - depth[cur];
			return;
		}
		seen[cur] = true;
		depth[cur] = curDepth;
		++count;
		for (int i = 0; i < edges[cur].size(); i += 2) {
			int j = edges[cur].get(i), next = edges[cur].get(i + 1);
			if (!visited[j]) {
				visited[j] = true;
				dfs(next, curDepth + 1);
			}
		}
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