import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static class IntIntMap {

		static final int EMPTY = Integer.MIN_VALUE;

		int data[] = new int[4];
		{
			data[0] = EMPTY;
			data[2] = EMPTY;
		}
		int size = 0;

		boolean isEmpty() {
			return size == 0;
		}

		int size() {
			return size;
		}

		void clear() {
			for (int i = 0; i < data.length; i += 2) {
				data[i] = EMPTY;
			}
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
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
				if (cur == key) {
					return true;
				} else if (cur == EMPTY) {
					return false;
				}
			}
		}

		int get(int key, int default_) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
				if (cur == key) {
					return data[i + 1];
				} else if (cur == EMPTY) {
					return default_;
				}
			}
		}

		static int[] resize(int data[], int newCapacity) {
			int oldCapacity = data.length;
			int ndata[] = new int[newCapacity];
			for (int i = 0; i < newCapacity; i += 2) {
				ndata[i] = EMPTY;
			}
			for (int mask = newCapacity - 2, i = 0; i < oldCapacity; i += 2) {
				int cur = data[i];
				if (cur == EMPTY) {
					continue;
				}
				for (int j = hash(cur) & mask;; j = (j - 1) & mask) {
					if (ndata[j] == EMPTY) {
						ndata[j] = cur;
						ndata[j + 1] = data[i + 1];
						break;
					}
				}
			}
			return ndata;
		}

		void set(int key, int value) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			int data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
				if (cur == key) {
					data[i + 1] = value;
					return;
				} else if (cur == EMPTY) {
					data[i] = key;
					data[i + 1] = value;
					if (++size > capacity >> 2) {
						this.data = resize(data, capacity << 1);
					}
					return;
				}
			}
		}

		void delete(int key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			int data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
				if (cur == key) {
					for (int j = i;;) {
						cur = data[j = (j - 1) & mask];
						if (cur == EMPTY) {
							data[i] = EMPTY;
							--size;
							return;
						}
						int k = hash(cur) & mask;
						if ((k >= i) ^ (k < j) ^ (i < j)) {
							data[i] = cur;
							data[i + 1] = data[j + 1];
							i = j;
						}
					}
				} else if (cur == EMPTY) {
					return;
				}
			}
		}

		void expand(int newCapacity) {
			int data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity >> 2 < newCapacity) {
				this.data = resize(data, Integer.highestOneBit(newCapacity - 1) << 3);
			}
		}

		void shrink() {
			int data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity > 4 && oldCapacity >> 3 >= size) {
				this.data = resize(data, max(Integer.highestOneBit(size - 1) << 3, 4));
			}
		}

		static class Iterator {

			final int data[];
			int position = -2;

			Iterator(int data[]) {
				this.data = data;
				advance();
			}

			boolean hasNext() {
				return position < data.length;
			}

			int getKey() {
				return data[position];
			}

			int getValue() {
				return data[position + 1];
			}

			void advance() {
				do {
					position += 2;
				} while (position < data.length && data[position] == EMPTY);
			}
		}

		Iterator iterator() {
			return new Iterator(data);
		}
	}

	static void solve() throws Exception {
		int n = scanInt();
		IntIntMap profit = new IntIntMap();
		for (int i = 0; i < n; i++) {
			profit.set(scanInt(), scanInt());
		}
		int m = scanInt();
		for (int i = 0; i < m; i++) {
			int k = scanInt();
			profit.set(k, max(profit.get(k, 0), scanInt()));
		}
		long res = 0;
		for (IntIntMap.Iterator it = profit.iterator(); it.hasNext(); it.advance()) {
			res += it.getValue();
		}
		out.print(res);
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