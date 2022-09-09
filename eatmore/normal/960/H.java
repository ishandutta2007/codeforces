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
import java.util.Locale;
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

	static class LongLongMap {

		static final long EMPTY = Long.MIN_VALUE;

		long data[] = new long[4];
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
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					return true;
				} else if (cur == EMPTY) {
					return false;
				}
			}
		}

		long get(long key, long default_) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					return data[i + 1];
				} else if (cur == EMPTY) {
					return default_;
				}
			}
		}

		static long[] resize(long data[], int newCapacity) {
			int oldCapacity = data.length;
			long ndata[] = new long[newCapacity];
			for (int i = 0; i < newCapacity; i += 2) {
				ndata[i] = EMPTY;
			}
			for (int mask = newCapacity - 2, i = 0; i < oldCapacity; i += 2) {
				long cur = data[i];
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

		void set(long key, long value) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
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

		void delete(long key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
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
			long data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity >> 2 < newCapacity) {
				this.data = resize(data, Integer.highestOneBit(newCapacity - 1) << 3);
			}
		}

		void shrink() {
			long data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity > 4 && oldCapacity >> 3 >= size) {
				this.data = resize(data, max(Integer.highestOneBit(size - 1) << 3, 4));
			}
		}

		static class Iterator {

			final long data[];
			int position = -2;

			Iterator(long data[]) {
				this.data = data;
				advance();
			}

			boolean hasNext() {
				return position < data.length;
			}

			long getKey() {
				return data[position];
			}

			long getValue() {
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

	static class LongLongCounter extends LongLongMap {

		long get(long key) {
			return get(key, 0);
		}

		void set(long key, long value) {
			if (value == 0) {
				delete(key);
			} else {
				super.set(key, value);
			}
		}

		void add(long key, long value) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					data[i + 1] += value;
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
	}

	static long getSum(LongLongCounter fenwick, int i) {
		long res = fenwick.get(i);
		while ((i = (i & (i + 1)) - 1) >= 0) {
			res += fenwick.get(i);
		}
		return res;
	}

	static void updateSum(LongLongCounter fenwick, int i, long v) {
		fenwick.add(i, v);
		while ((i |= i + 1) < 60000) {
			fenwick.add(i, v);
		}
	}

	static void dfs1(int cur, int cDepth) {
		depth[cur] = cDepth;
		tEnter[cur] = tCur++;
		for (int i = 0; i < children[cur].size(); i++) {
			dfs1(children[cur].get(i), cDepth + 1);
		}
		tExit[cur] = tCur;
	}

	static void dfs2(int cur, int cHpRoot, int cHpPos) {
		hpRoot[cur] = cHpRoot;
		hpPos[cur] = cHpPos;
		int heavy = -1, heavySize = -1;
		for (int i = 0; i < children[cur].size(); i++) {
			int next = children[cur].get(i);
			if (heavySize < tExit[next] - tEnter[next]) {
				heavy = next;
				heavySize = tExit[next] - tEnter[next];
			}
		}
		hpChild[cur] = heavy;
		for (int i = 0; i < children[cur].size(); i++) {
			int next = children[cur].get(i);
			if (next == heavy) {
				dfs2(next, cHpRoot, cHpPos + 1);
			} else {
				dfs2(next, next, 0);
			}
		}
		if (cur == cHpRoot) {
			int cnt = 1;
			for (int i = heavy; i >= 0; i = hpChild[i]) {
				++cnt;
			}
			hpList[cur] = new int[cnt];
			cnt = 0;
			int i = cur;
			do {
				hpList[cur][cnt] = i;
				i = hpChild[i];
				++cnt;
			} while (i >= 0);
		}
	}

	static void put(int i, int f, int w) {
		int add = w * depth[i];
		count1[f] += add;
		updateSum(fw1[f], tEnter[i], w);
		count2[f] += add * (getSum(fw1[f], tExit[i] - 1) - getSum(fw1[f], tEnter[i]));
		while (true) {
			int curRoot = hpRoot[i], curPos = hpPos[i], curList[] = hpList[curRoot], curLimit = curList.length;
			do {
				fw2[f].add(curList[curPos], add);
				curPos |= curPos + 1;
			} while (curPos < curLimit);
			curPos = hpPos[i] - 1;
			while (curPos >= 0) {
				count2[f] += w * fw2[f].get(curList[curPos]);
				curPos = (curPos & (curPos + 1)) - 1;
			}
			i = parent[curRoot];
			if (i < 0) {
				break;
			}
			add = w * depth[i];
			count2[f] += add * getSum(fw1[f], tExit[i] - 1);
			if (tEnter[i] > 0) {
				count2[f] -= add * getSum(fw1[f], tEnter[i] - 1);
			}
			count2[f] -= add * (getSum(fw1[f], tExit[curRoot] - 1) - getSum(fw1[f], tEnter[curRoot] - 1));
		}
	}

	static int parent[];
	static IntList children[];
	static int depth[], tCur, tEnter[], tExit[];
	static int hpRoot[], hpPos[], hpChild[], hpList[][];
	static LongLongCounter fw1[], fw2[];
	static long count1[], count2[];

	static void solve() throws Exception {
		int n = scanInt();
		int m = scanInt();
		int q = scanInt();
		int cBig = scanInt();
		int f[] = new int[n];
		for (int i = 0; i < n; i++) {
			f[i] = scanInt() - 1;
		}
		parent = new int[n];
		parent[0] = -1;
		children = new IntList[n];
		for (int i = 0; i < n; i++) {
			children[i] = new IntList();
		}
		for (int i = 1; i < n; i++) {
			parent[i] = scanInt() - 1;
			children[parent[i]].push(i);
		}
		depth = new int[n];
		tCur = 0;
		tEnter = new int[n];
		tExit = new int[n];
		dfs1(0, 1);
		hpRoot = new int[n];
		hpPos = new int[n];
		hpChild = new int[n];
		hpList = new int[n][];
		dfs2(0, 0, 0);
		fw1 = new LongLongCounter[m];
		fw2 = new LongLongCounter[m];
		for (int i = 0; i < m; i++) {
			fw1[i] = new LongLongCounter();
			fw2[i] = new LongLongCounter();
		}
		count1 = new long[m];
		count2 = new long[m];
		for (int i = 0; i < n; i++) {
			put(i, f[i], 1);
		}
		int c[] = new int[m];
		for (int i = 0; i < m; i++) {
			c[i] = scanInt();
		}
		for (int qq = 0; qq < q; qq++) {
			switch (scanInt()) {
			case 1:
				int x = scanInt() - 1;
				int w = scanInt() - 1;
				put(x, f[x], -1);
				put(x, f[x] = w, 1);
				break;
			case 2:
				int k = scanInt() - 1;
				long sum = count1[k];
				long sum2 = sum + 2 * count2[k];
				double ans = (double) (c[k] * c[k] * sum2 - 2 * c[k] * sum * cBig) / n + (long) cBig * cBig;
				out.printf(Locale.US, "%.9f\n", ans);
				break;
			default:
				throw new AssertionError();
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