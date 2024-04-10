import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static class LongSet {

		static final long EMPTY = Long.MIN_VALUE;

		long data[] = new long[4];
		{
			fill(data, EMPTY);
		}
		int size = 0;

		boolean isEmpty() {
			return size == 0;
		}

		int size() {
			return size;
		}

		void clear() {
			fill(data, EMPTY);
			size = 0;
		}

		static int hash(long key) {
			long hash = key * 1000000007;
			hash ^= hash >> 16;
			hash ^= hash >> 24;
			return (int) hash;
		}

		boolean have(long key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 1, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					return true;
				} else if (cur == EMPTY) {
					return false;
				}
			}
		}

		static long[] resize(long data[], int newCapacity) {
			int oldCapacity = data.length;
			long ndata[] = new long[newCapacity];
			fill(ndata, EMPTY);
			for (int mask = newCapacity - 1, i = 0; i < oldCapacity; i++) {
				long cur = data[i];
				if (cur == EMPTY) {
					continue;
				}
				for (int j = hash(cur) & mask;; j = (j - 1) & mask) {
					if (ndata[j] == EMPTY) {
						ndata[j] = cur;
						break;
					}
				}
			}
			return ndata;
		}

		boolean add(long key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 1, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					return false;
				} else if (cur == EMPTY) {
					data[i] = key;
					if (++size > capacity >> 1) {
						this.data = resize(data, capacity << 1);
					}
					return true;
				}
			}
		}

		boolean delete(long key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 1, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					for (int j = i;;) {
						cur = data[j = (j - 1) & mask];
						if (cur == EMPTY) {
							data[i] = EMPTY;
							--size;
							return true;
						}
						int k = hash(cur) & mask;
						if ((k >= i) ^ (k < j) ^ (i < j)) {
							data[i] = cur;
							i = j;
						}
					}
				} else if (cur == EMPTY) {
					return false;
				}
			}
		}

		void expand(int newCapacity) {
			long data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity >> 1 < newCapacity) {
				this.data = resize(data, Integer.highestOneBit(newCapacity - 1) << 2);
			}
		}

		void shrink() {
			long data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity > 4 && oldCapacity >> 2 >= size) {
				this.data = resize(data, max(Integer.highestOneBit(size - 1) << 2, 4));
			}
		}

		static class Iterator {

			final long data[];
			int position = -1;

			Iterator(long data[]) {
				this.data = data;
				advance();
			}

			boolean hasNext() {
				return position < data.length;
			}

			long get() {
				return data[position];
			}

			void advance() {
				do {
					++position;
				} while (position < data.length && data[position] == EMPTY);
			}
		}

		Iterator iterator() {
			return new Iterator(data);
		}
	}

	static void sort(int a[]) {
		int n = a.length;
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (ca <= na) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		int ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (a[j + 2] > a[j + 1]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			while (j != 0 && a[j] < ca) {
				j = (j - 1) >> 1;
			}
			while (j != 0) {
				na = a[j];
				a[j] = ca;
				ca = na;
				j = (j - 1) >> 1;
			}
		}
		a[0] = ca;
	}

	static void solve() throws Exception {
		int a = nextInt();
		int b = nextInt();
		if (a < b) {
			int t = a;
			a = b;
			b = t;
		}
		int h = nextInt();
		int w = nextInt();
		if (h < w) {
			int t = h;
			h = w;
			w = t;
		}
		if (h >= a && w >= b) {
			out.print(0);
			return;
		}
		int n = nextInt();
		int x[] = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
		}
		sort(x);
		LongSet cur = new LongSet();
		cur.add(((long) h << 32) | w);
		LongSet next = new LongSet();
		for (int i = n - 1; i >= 0; i--) {
			int mul = x[i];
			next.clear();
			for (LongSet.Iterator it = cur.iterator(); it.hasNext(); it.advance()) {
				long cv = it.get();
				int ch = (int) (cv >> 32);
				int cw = (int) cv;
				int nh = (int) min((long) ch * mul, Integer.MAX_VALUE);
				int nw = (int) min((long) cw * mul, Integer.MAX_VALUE);
				int s1 = max(nh, cw), s2 = min(nh, cw);
				if (s1 >= a && s2 >= b) {
					out.print(n - i);
					return;
				}
				next.add(((long) s1 << 32) | s2);
				s1 = max(nw, ch); s2 = min(nw, ch);
				if (s1 >= a && s2 >= b) {
					out.print(n - i);
					return;
				}
				next.add(((long) s1 << 32) | s2);
			}
			LongSet t = cur;
			cur = next;
			next = t;
		}
		out.print(-1);
	}

	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}