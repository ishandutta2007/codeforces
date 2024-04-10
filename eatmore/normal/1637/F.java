import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class F {

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

	static IntList edges[];
	static int h[];
	static long ans;

	static void solve() throws Exception {
		int n = scanInt();
		h = new int[n];
		int maxH = 0, maxI = -1;
		for (int i = 0; i < n; i++) {
			if (maxH < (h[i] = scanInt())) {
				maxH = h[i];
				maxI = i;
			}
		}
		edges = new IntList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new IntList();
		}
		for (int i = 0; i < n - 1; i++) {
			int u = scanInt() - 1, v = scanInt() - 1;
			edges[u].push(v);
			edges[v].push(u);
		}
		ans = 0;
		IntList e = edges[maxI];
		int max1 = 0, max2 = 0;
		for (int i = 0; i < e.size; i++) {
			int cur = dfs(e.data[i], maxI);
			if (max1 < cur) {
				max2 = max1;
				max1 = cur;
			} else if (max2 < cur) {
				max2 = cur;
			}
		}
		ans += maxH - max1;
		ans += maxH - max2;
		out.print(ans);
	}

	static int dfs(int cur, int prev) {
		IntList e = edges[cur];
		int max = 0;
		for (int i = 0; i < e.size; i++) {
			int next = e.data[i];
			if (next != prev) {
				max = max(max, dfs(next, cur));
			}
		}
		if (h[cur] > max) {
			ans += h[cur] - max;
			max = h[cur];
		}
		return max;
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