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

public class H {

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

	static void sort(int a[], int b[], int n) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i], cb = b[i];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (ca >= na) {
					break;
				}
				a[j] = na;
				b[j] = b[nj];
				j = nj;
			} while (j != 0);
			a[j] = ca;
			b[j] = cb;
		}
		int ca = a[0], cb = b[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (a[j + 2] < a[j + 1]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i], nb = b[i];
			a[i] = ca;
			b[i] = cb;
			ca = na;
			cb = nb;
			while (j != 0 && a[j] > ca) {
				j = (j - 1) >> 1;
			}
			while (j != 0) {
				na = a[j];
				nb = b[j];
				a[j] = ca;
				b[j] = cb;
				ca = na;
				cb = nb;
				j = (j - 1) >> 1;
			}
		}
		a[0] = ca;
		b[0] = cb;
	}

	static IntList edges[];
	static int dyn[][], ans;

	static void solve() throws Exception {
		int n = scanInt();
		edges = new IntList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new IntList();
		}
		for (int i = 0; i < n - 1; i++) {
			int a = scanInt() - 1, b = scanInt() - 1;
			edges[a].push(b);
			edges[b].push(a);
		}
		dyn = new int[n][];
		dfs1(0, -1);
		ans = 0;
		dfs2(0, -1, 0);
		out.println(ans);
		out.flush();
		int start = scanInt() - 1;
		int ans[] = new int[2], ansPos = 0;
		int s = start, spos = 0, startPos = 0, sprev = -1;
		s: while (true) {
			int see[] = edges[s].data, ses = edges[s].size;
			while (true) {
				if (spos >= ses) {
					ans[ansPos++] = s;
					if (ansPos == 2) {
						break s;
					}
					s = start;
					spos = startPos;
					continue s;
				}
				int scur = see[spos];
				++spos;
				if (s == start) {
					startPos = spos;
				}
				if (scur == sprev) {
					continue;
				}
				int cur = scur, prev = s;
				d: while (true) {
					int cee[] = edges[cur].data, ces = edges[cur].size;
					for (int j = 0;; j++) {
						if (j >= ces) {
							break d;
						}
						int next = cee[j];
						if (next != prev) {
							prev = cur;
							cur = next;
							break;
						}
					}
				}
				out.println("? " + (cur + 1));
				out.flush();
				int cres = scanInt() - 1;
				if (cres == s) {
					continue;
				}
				cur = scur;
				prev = s;
				while (true) {
					if (cres == cur) {
						s = cur;
						sprev = prev;
						spos = edges[s].data[0] == sprev ? 2 : 1;
						continue s;
					}
					int cee[] = edges[cur].data, ces = edges[cur].size;
					for (int j = 0;; j++) {
						if (j >= ces) {
							throw new AssertionError();
						}
						int next = cee[j];
						if (next != prev) {
							prev = cur;
							cur = next;
							break;
						}
					}
				}
			}
		}
		out.println("! " + (ans[0] + 1) + " " + (ans[1] + 1));
	}

	static int dfs1(int cur, int prev) {
		IntList e = edges[cur];
		int ee[] = e.data, es = e.size, d[] = dyn[cur] = new int[es];
		for (int i = 0; i < es; i++) {
			int next = ee[i];
			d[i] = next == prev ? -1 : dfs1(next, cur);
		}
		sort(d, ee, es);
		int res = 0;
		if (prev < 0) {
			for (int i = 0; i < es; i++) {
				res = max(res, i + d[i]);
			}
		} else {
			for (int i = 0; i < es - 1; i++) {
				res = max(res, i + d[i]);
			}
		}
		return res;
	}

	static void dfs2(int cur, int prev, int dv) {
		IntList e = edges[cur];
		int ee[] = e.data, es = e.size, d[] = dyn[cur];
		if (prev >= 0) {
			int i;
			for (i = 0; i < es - 1 && d[i] > dv; i++) { }
			arraycopy(ee, i, ee, i + 1, es - i - 1);
			ee[i] = prev;
			arraycopy(d, i, d, i + 1, es - i - 1);
			d[i] = dv;
		}
		int pdyn[] = new int[es], sdyn[] = new int[es];
		for (int i = 0; i < es - 1; i++) {
			pdyn[i + 1] = max(pdyn[i], i + d[i]);
		}
		for (int i = es - 1; i > 0; i--) {
			sdyn[i - 1] = max(sdyn[i], i + d[i] - 1);
		}
		for (int i = 0; i < es; i++) {
			int next = ee[i];
			if (next != prev) {
				dfs2(next, cur, max(pdyn[i], sdyn[i]));
			}
		}
		if (es > 0) {
			ans = max(ans, es == 1 ? d[0] + 1 : d[0] + sdyn[0] + 2);
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