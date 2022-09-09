import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static class LongSlimCounter {

		long data[] = new long[4];
		{
			fill(data, -1);
		}
		int spaceUsed = 0;

		boolean isEmpty() {
			return spaceUsed == 0;
		}

		void clear() {
			fill(data, -1);
			spaceUsed = 0;
		}

		static int hash(long value) {
			long hash = value * 1000000007;
			hash ^= hash >> 16;
			hash ^= hash >> 24;
			return (int) hash;
		}

		long get(long key) {
			if (key < 0) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int mask = data.length - 1, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					long value = data[(i - 1) & mask];
					return value < -1 ? ~value : 1;
				} else if (cur == -1) {
					return 0;
				}
			}
		}

		static void emplace(long data[], int mask, int i, long val) {
			do {
				long cur = data[i = (i - 1) & mask];
				data[i] = val;
				val = cur;
			} while (val != -1);
		}

		static long[] resize(long data[], int newCapacity) {
			int oldCapacity = data.length;
			long ndata[] = new long[newCapacity];
			fill(ndata, -1);
			for (int mask = newCapacity - 1, i = oldCapacity - 1; i >= 0; i--) {
				long cur = data[i];
				if (cur < 0) {
					continue;
				}
				long val = data[(i == 0 ? oldCapacity : i) - 1];
				for (int j = hash(cur) & mask;; j = (j - 1) & mask) {
					if (ndata[j] == -1) {
						ndata[j] = cur;
						if (val < -1) {
							--i;
							emplace(ndata, mask, j, val);
						}
						break;
					}
				}
			}
			return ndata;
		}

		static void evict(long data[], int mask, int i) {
			for (int j = i;;) {
				long cur = data[j = (j - 1) & mask];
				if (cur == -1) {
					data[i] = -1;
					return;
				} else if (cur >= 0) {
					int k = hash(cur) & mask;
					if ((k >= i) ^ (k < j) ^ (i < j)) {
						data[i] = cur;
						int nj = (j - 1) & mask;
						if ((cur = data[nj]) < -1) {
							data[j] = -1;
							emplace(data, mask, i, cur);
							j = nj;
						}
						i = j;
					}
				}
			}
		}

		void set(long key, long value) {
			if (value == 0) {
				delete(key);
				return;
			}
			if (key < 0 || value < 0) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 1, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					cur = data[i = (i - 1) & mask];
					if (value == 1) {
						if (cur < -1) {
							evict(data, mask, i);
							--spaceUsed;
						}
						return;
					}
					data[i] = ~value;
					if (cur < -1) {
						return;
					}
					if (cur >= 0) {
						emplace(data, mask, i, cur);
					}
				} else if (cur == -1) {
					data[i] = key;
					if (value != 1) {
						emplace(data, mask, i, ~value);
						++spaceUsed;
					}
				} else {
					continue;
				}
				if (++spaceUsed > capacity >> 1) {
					this.data = resize(data, capacity << 1);
				}
				return;
			}
		}

		void delete(long key) {
			if (key < 0) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 1, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					int j = (i - 1) & mask;
					if (data[j] < -1) {
						evict(data, mask, j);
						--spaceUsed;
					}
					evict(data, mask, i);
					--spaceUsed;
					return;
				} else if (cur == -1) {
					return;
				}
			}
		}

		void add(long key, long value) {
			set(key, get(key) + value);
		}

		void add1(long key) {
			if (key < 0) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 1, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					cur = data[i = (i - 1) & mask];
					if (cur < -1) {
						if (cur == Long.MIN_VALUE) {
							throw new IllegalArgumentException();
						}
						data[i] = cur - 1;
						return;
					}
					data[i] = ~2;
					if (cur >= 0) {
						emplace(data, mask, i, cur);
					}
				} else if (cur == -1) {
					data[i] = key;
				} else {
					continue;
				}
				if (++spaceUsed > capacity >> 1) {
					this.data = resize(data, capacity << 1);
				}
				return;
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
			if (oldCapacity > 4 && oldCapacity >> 2 >= spaceUsed) {
				this.data = resize(data, max(Integer.highestOneBit(spaceUsed - 1) << 2, 4));
			}
		}

		static class Iterator {

			final long data[];
			int position = 0;
			long key, value;

			Iterator(long data[]) {
				this.data = data;
				if ((key = data[0]) >= 0) {
					long val = data[data.length - 1];
					value = val < -1 ? ~val : 1;
				} else {
					advance();
				}
			}

			boolean hasNext() {
				return position < data.length;
			}

			long getKey() {
				return key;
			}

			long getValue() {
				return value;
			}

			void advance() {
				while (++position < data.length) {
					if ((key = data[position]) >= 0) {
						long val = data[position - 1];
						value = val < -1 ? ~val : 1;
						return;
					}
				}
			}
		}

		Iterator iterator() {
			return new Iterator(data);
		}
	}

	static void solve() throws Exception {
		int n = nextInt();
		long k = nextLong();
		LongSlimCounter counter = new LongSlimCounter();
		long sum = Long.MAX_VALUE / 2;
		counter.add(sum, 1);
		long ans = 0;
		for (int i = 0; i < n; i++) {
			sum += nextLong();
			for (long pow = 1; abs(pow) <= 1_000_000_000_000_000L; pow *= k) {
				ans += counter.get(sum - pow);
				if (abs(k) == 1 && pow == k) {
					break;
				}
			}
			counter.add(sum, 1);
		}
		out.print(ans);
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