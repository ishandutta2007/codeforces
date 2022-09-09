import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class G {

	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
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

	static IntList edges[], redges[];
	static int seen[];
	static int order[], pos;
	static long v[];

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		edges = new IntList[n];
		redges = new IntList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new IntList();
			redges[i] = new IntList();
		}
		for (int i = 0; i < m; i++) {
			int a = scanInt() - 1, b = scanInt() - 1, l = scanInt();
			edges[a].push(b);
			edges[a].push(l);
			redges[b].push(a);
			redges[b].push(l);
		}
		seen = new int[n];
		order = new int[n];
		pos = 0;
		for (int i = 0; i < n; i++) {
			dfs1(i);
		}
		v = new long[n];
		for (int i = n - 1; i >= 0; i--) {
			int ii = order[i];
			if (seen[ii] == 1) {
				long gcd = dfs2(ii, 0);
				dfs3(ii, gcd);
			}
		}
		int q = scanInt();
		for (int i = 0; i < q; i++) {
			int vv = scanInt() - 1, s = scanInt(), t = scanInt();
			out.println(s % gcd(v[vv], t) == 0 ? "YES" : "NO");
		}
	}

	static void dfs1(int cur) {
		if (seen[cur] != 0) {
			return;
		}
		seen[cur] = 1;
		IntList e = edges[cur];
		for (int i = 0; i < e.size; i += 2) {
			dfs1(e.data[i]);
		}
		order[pos++] = cur;
	}

	static long dfs2(int cur, long curV) {
		long res = 0;
		if (seen[cur] == 1) {
			seen[cur] = 2;
			v[cur] = curV;
			IntList e = redges[cur];
			for (int i = 0; i < e.size; i += 2) {
				res = gcd(res, dfs2(e.data[i], curV + e.data[i + 1]));
			}
		} else if (seen[cur] == 2) {
			res = abs(curV - v[cur]);
		}
		return res;
	}

	static void dfs3(int cur, long gcd) {
		if (seen[cur] == 2) {
			seen[cur] = 3;
			v[cur] = gcd;
			IntList e = redges[cur];
			for (int i = 0; i < e.size; i += 2) {
				dfs3(e.data[i], gcd);
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