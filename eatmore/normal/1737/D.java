import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class D {

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

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), m = scanInt();
			IntList edges[] = new IntList[n];
			for (int i = 0; i < n; i++) {
				edges[i] = new IntList();
			}
			int dist[][] = new int[n][n];
			for (int a[]: dist) {
				fill(a, Integer.MAX_VALUE / 2);
			}
			for (int i = 0; i < m; i++) {
				int u = scanInt() - 1, v = scanInt() - 1, w = scanInt();
				edges[u].push(v);
				edges[u].push(w);
				edges[v].push(u);
				edges[v].push(w);
				dist[u][v] = 1;
				dist[v][u] = 1;
			}
			for (int i = 0; i < n; i++) {
				dist[i][i] = 0;
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
					}
				}
			}
			int ds[] = new int[n];
			for (int i = 0; i < n; i++) {
				ds[i] = dist[0][i] + dist[n - 1][i];
			}
			long ans = Long.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				int dd = Integer.MAX_VALUE;
				int di[] = dist[i];
				for (int k = 0; k < n; k++) {
					dd = min(dd, ds[k] + di[k] + 1);
				}
				IntList e = edges[i];
				for (int j = 0; j < e.size; j += 2) {
					int d = min(dist[0][i] + dist[e.data[j]][n - 1], dd);
					ans = min(ans, (long) (d + 1) * e.data[j + 1]);
				}
			}
			out.println(ans);
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