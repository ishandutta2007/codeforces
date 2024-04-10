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

public class H {

	static class IntMinTree {

		final int n;
		final int t[];

		IntMinTree(int n) {
			if (n == 0) {
				n = 1;
			}
			this.n = n;
			t = new int[2 * n - 1];
		}

		void init(int v[]) {
			if (v.length != 0) {
				arraycopy(v, 0, t, n - 1, n);
			}
			for (int i = n - 1; i != 0; i--) {
				t[i - 1] = min(t[(i << 1) - 1], t[i << 1]);
			}
		}

		int get(int i) {
			return t[i + n - 1];
		}

		int getMin(int l, int r) {
			int v = Integer.MAX_VALUE;
			for (l += n, r += n; l != r; l >>>= 1, r >>>= 1) {
				if ((l & 1) != 0) {
					v = min(v, t[l++ - 1]);
				}
				if ((r & 1) != 0) {
					v = min(v, t[--r - 1]);
				}
			}
			return v;
		}

		int scanLE(int l, int r, int v) {
			int i;
			scan: {
				for (l += n, r += n, i = 0; l != r >>> i; l >>>= 1, ++i) {
					if ((l & 1) != 0) {
						if (t[l - 1] <= v) {
							break scan;
						}
						++l;
					}
				}
				while (i != 0) {
					int j = r >>> --i;
					if ((j & 1) != 0 && t[j - 2] <= v) {
						l = j - 1;
						break scan;
					}
				}
				return r - n;
			}
			for (; i != 0; --i) {
				if (t[(l <<= 1) - 1] > v) {
					++l;
				}
			}
			return l - n;
		}

		int rscanLE(int l, int r, int v) {
			int i;
			scan: {
				for (l += n - 1, r += n, i = 0; r != (l >>> i) + 1; r >>>= 1, ++i) {
					if ((r & 1) != 0 && t[--r - 1] <= v) {
						break scan;
					}
				}
				while (i != 0) {
					int j = l >>> --i;
					if ((j & 1) == 0 && t[j] <= v) {
						r = j + 1;
						break scan;
					}
				}
				return l - n;
			}
			for (; i != 0; --i) {
				if (t[r <<= 1] <= v) {
					++r;
				}
			}
			return r - n;
		}

		void set(int i, int v) {
			t[(i += n) - 1] = v;
			while ((i >>= 1) != 0) {
				t[i - 1] = min(t[(i << 1) - 1], t[i << 1]);
			}
		}
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

	static int parent[];
	static IntList children[];
	static int v2pos[], v2endpos[], pos2v[], pos;
	static IntMinTree depth;
	static int x[], y[];
	static IntList ends[];
	static int fires[];
	static boolean done[];

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		parent = new int[n];
		children = new IntList[n];
		for (int i = 0; i < n; i++) {
			children[i] = new IntList();
		}
		parent[0] = -1;
		for (int i = 0; i < n - 1; i++) {
			children[parent[i + 1] = scanInt() - 1].push(i + 1);
		}
		v2pos = new int[n];
		v2endpos = new int[n];
		pos2v = new int[2 * n - 1];
		depth = new IntMinTree(2 * n - 1);
		pos = 0;
		dfs1(0, 0);
		x = new int[m];
		y = new int[m];
		ends = new IntList[n];
		for (int i = 0; i < n; i++) {
			ends[i] = new IntList();
		}
		for (int i = 0; i < m; i++) {
			x[i] = scanInt() - 1;
			y[i] = scanInt() - 1;
			if (parent[x[i]] == y[i] || parent[y[i]] == x[i]) {
				out.print(-1);
				return;
			}
			int px = v2pos[x[i]], py = v2pos[y[i]];
			if (px > py) {
				int t = x[i];
				x[i] = y[i];
				y[i] = t;
				t = px;
				px = py;
				py = t;
			}
			int lcd = depth.getMin(px, py + 1);
			int lca = pos2v[depth.scanLE(px, py + 1, lcd)];
			if (lca == x[i]) {
				int z = pos2v[depth.rscanLE(px, py + 1, lcd + 1)];
				ends[z].push(i);
			}
		}
		fires = new int[n];
		done = new boolean[m];
		dfs2(0);
		for (int i = 0; i < m; i++) {
			if (!done[i]) {
				if (fires[0] == fires[x[i]] + fires[y[i]]) {
					++fires[0];
				}
			}
		}
		out.print(fires[0]);
	}

	static void dfs1(int cur, int d) {
		depth.set(pos, d);
		v2pos[cur] = v2endpos[cur] = pos;
		pos2v[pos] = cur;
		++pos;
		IntList c = children[cur];
		for (int i = 0; i < c.size; i++) {
			dfs1(c.data[i], d + 1);
			depth.set(pos, d);
			v2endpos[cur] = pos;
			pos2v[pos] = cur;
			++pos;
		}
	}

	static int dfs2(int cur) {
		int lca = -1;
		IntList c = children[cur];
		for (int i = 0; i < c.size; i++) {
			int next = c.data[i];
			int z = dfs2(next);
			if (z >= 0) {
				lca = lca < 0 ? z : cur;
			}
			fires[cur] += fires[next];
		}
		IntList e = ends[cur];
		for (int i = 0; i < e.size; i++) {
			int v = e.data[i];
			if (lca < 0 || (v2pos[y[v]] <= v2pos[lca] && v2endpos[y[v]] >= v2pos[lca])) {
				++fires[cur];
				lca = cur;
			}
			done[v] = true;
		}
		return lca;
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