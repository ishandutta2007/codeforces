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

	static int dsuGet(int dsu[], int i) {
		return dsu[i] == i ? i : (dsu[i] = dsuGet(dsu, dsu[i]));
	}

	static boolean dsuMerge(int dsu[], int i, int j) {
		i = dsuGet(dsu, i);
		j = dsuGet(dsu, j);
		if (i == j) {
			return false;
		}
		dsu[j] = i;
		return true;
	}

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt(), x = scanInt();
		long a[] = new long[n];
		long sum = 0;
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
			sum += a[i];
		}
		int u[] = new int[m], v[] = new int[m];
		for (int i = 0; i < m; i++) {
			u[i] = scanInt() - 1;
			v[i] = scanInt() - 1;
		}
		if (sum < (long) x * (n - 1)) {
			out.println("NO");
			return;
		}
		int dsu[] = new int[n];
		for (int i = 0; i < n; i++) {
			dsu[i] = i;
		}
		IntList roads[] = new IntList[n];
		for (int i = 0; i < n; i++) {
			roads[i] = new IntList();
		}
		for (int i = 0; i < m; i++) {
			roads[u[i]].push(i);
			roads[v[i]].push(i);
		}
		int allRoadsPtr = 0;
		int stack[] = new int[2 * n - 1], stackSize = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] >= x) {
				stack[stackSize++] = i;
			}
		}
		out.println("YES");
		i: for (int i = 0; i < n - 1; i++) {
			while (stackSize > 0) {
				int cur = stack[--stackSize];
				if (dsuGet(dsu, cur) != cur || a[cur] < x) {
					continue;
				}
				a[cur] -= x;
				while (true) {
					int r = roads[cur].data[--roads[cur].size];
					int uu = dsuGet(dsu, u[r]), vv = dsuGet(dsu, v[r]);
					if (uu != vv) {
						out.println(r + 1);
						dsuMerge(dsu, uu, vv);
						a[uu] += a[vv];
						if (roads[uu].size < roads[vv].size) {
							IntList tt = roads[uu];
							roads[uu] = roads[vv];
							roads[vv] = tt;
						}
						for (int j = 0; j < roads[vv].size; j++) {
							roads[uu].push(roads[vv].data[j]);
						}
						if (a[uu] >= x) {
							stack[stackSize++] = uu;
						}
						continue i;
					}
				}
			}
			while (true) {
				int r = allRoadsPtr++;
				int uu = dsuGet(dsu, u[r]), vv = dsuGet(dsu, v[r]);
				if (uu != vv) {
					out.println(r + 1);
					dsuMerge(dsu, uu, vv);
					a[uu] += a[vv];
					if (roads[uu].size < roads[vv].size) {
						IntList tt = roads[uu];
						roads[uu] = roads[vv];
						roads[vv] = tt;
					}
					for (int j = 0; j < roads[vv].size; j++) {
						roads[uu].push(roads[vv].data[j]);
					}
					if (a[uu] >= x) {
						stack[stackSize++] = uu;
					}
					continue i;
				}
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