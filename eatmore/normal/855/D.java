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

	static int up[][], type[], depth[], minDepth[], minParent[], enter[], exit[], pos;
	static IntList children[];

	static void solve() throws Exception {
		int n = scanInt();
		up = new int[n][20];
		type = new int[n];
		children = new IntList[n];
		for (int i = 0; i < n; i++) {
			children[i] = new IntList();
		}
		IntList roots = new IntList();
		for (int i = 0; i < n; i++) {
			int p = scanInt(), t = scanInt();
			if (p < 0) {
				roots.push(i);
				up[i][0] = -1;
				type[i] = -1;
			} else {
				children[--p].push(i);
				up[i][0] = p;
				type[i] = t;
			}
		}
		depth = new int[n];
		minDepth = new int[n];
		minParent = new int[n];
		enter = new int[n];
		exit = new int[n];
		pos = 0;
		for (int i = 0; i < roots.size(); i++) {
			dfs(roots.get(i), 0, -1, 0, 0);
		}
		int q = scanInt();
		for (int qq = 0; qq < q; qq++) {
			int t = scanInt();
			int u = scanInt() - 1, v = scanInt() - 1;
			boolean ret;
			switch (t) {
			case 1:
				ret = child(v, u) && type[v] == 0 && minDepth[v] <= depth[u];
				break;
			case 2:
				ret = child(v, u) && type[v] == 1 && minDepth[v] <= depth[u];
				if (!ret) {
					int p1 = minParent[u], p2 = minParent[v];
					int p = depth[p1] > depth[p2] ? p1 : p2;
					ret = child(u, p) && child(v, p) && type[u] == 0 && minDepth[u] <= depth[p] && type[v] == 1 && minDepth[v] <= depth[p];
				}
				break;
			default:
				throw new AssertionError();
			}
			out.println(ret ? "YES" : "NO");
		}
	}

	static boolean child(int v, int u) {
		return enter[v] > enter[u] && exit[v] <= exit[u];
	}

	static void dfs(int cur, int d, int curT, int curTDepth, int curTParent) {
		depth[cur] = d;
		minDepth[cur] = curTDepth;
		minParent[cur] = curTParent;
		enter[cur] = pos++;
		for (int i = 0; i < children[cur].size(); i++) {
			int next = children[cur].get(i);
			dfs(next, d + 1, type[next], type[next] == curT ? curTDepth : d, type[next] == curT ? curTParent : cur);
		}
		exit[cur] = pos;
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