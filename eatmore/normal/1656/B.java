import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static class IntSet {

		static final int EMPTY = Integer.MIN_VALUE;

		int data[] = new int[4];
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

		static int hash(int key) {
			int hash = key * 1000000007;
			hash ^= hash >> 16;
			hash ^= hash >> 24;
			return hash;
		}

		boolean have(int key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 1, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
				if (cur == key) {
					return true;
				} else if (cur == EMPTY) {
					return false;
				}
			}
		}

		static int[] resize(int data[], int newCapacity) {
			int oldCapacity = data.length;
			int ndata[] = new int[newCapacity];
			fill(ndata, EMPTY);
			for (int mask = newCapacity - 1, i = 0; i < oldCapacity; i++) {
				int cur = data[i];
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

		boolean add(int key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			int data[] = this.data;
			for (int capacity = data.length, mask = capacity - 1, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
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

		boolean delete(int key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			int data[] = this.data;
			for (int capacity = data.length, mask = capacity - 1, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
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
			int data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity >> 1 < newCapacity) {
				this.data = resize(data, Integer.highestOneBit(newCapacity - 1) << 2);
			}
		}

		void shrink() {
			int data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity > 4 && oldCapacity >> 2 >= size) {
				this.data = resize(data, max(Integer.highestOneBit(size - 1) << 2, 4));
			}
		}

		static class Iterator {

			final int data[];
			int position = -1;

			Iterator(int data[]) {
				this.data = data;
				advance();
			}

			boolean hasNext() {
				return position < data.length;
			}

			int get() {
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

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), k = scanInt();
			IntSet els = new IntSet();
			boolean ans = false;
			for (int i = 0; i < n; i++) {
				int v = scanInt();
				if (els.have(v + k) || els.have(v - k)) {
					ans = true;
				}
				els.add(v);
			}
			out.println(ans ? "YES" : "NO");
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