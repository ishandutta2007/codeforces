import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.BitSet;
import java.util.NoSuchElementException;
import java.util.Random;
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

	static class LongList {

		long data[] = new long[3];
		int size = 0;

		boolean isEmpty() {
			return size == 0;
		}

		int size() {
			return size;
		}

		long get(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			return data[index];
		}

		void clear() {
			size = 0;
		}

		void set(int index, long value) {
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

		void insert(int index, long value) {
			if (index < 0 || index > size) {
				throw new IndexOutOfBoundsException();
			}
			expand();
			arraycopy(data, index, data, index + 1, size++ - index);
			data[index] = value;
		}

		long delete(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			long value = data[index];
			arraycopy(data, index + 1, data, index, --size - index);
			return value;
		}

		void push(long value) {
			expand();
			data[size++] = value;
		}

		long pop() {
			if (size == 0) {
				throw new NoSuchElementException();
			}
			return data[--size];
		}

		void unshift(long value) {
			expand();
			arraycopy(data, 0, data, 1, size++);
			data[0] = value;
		}

		long shift() {
			if (size == 0) {
				throw new NoSuchElementException();
			}
			long value = data[0];
			arraycopy(data, 1, data, 0, --size);
			return value;
		}
	}

	static void sortBy(int a[], int n, int v[]) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			int cv = v[ca];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (cv <= v[na]) {
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
				j += (v[a[j + 2]] > v[a[j + 1]]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			int cv = v[ca];
			while (j != 0 && v[a[j]] < cv) {
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
		int c = scanInt(), n = scanInt();
		int lc[] = new int[c + 1];
		for (int i = 1; i * i <= c; i++) {
			for (int j = i; j * i <= c; j += i) {
				lc[j * i] = j;
			}
		}
		for (int i = 4; i <= c; i++) {
			lc[i] = lc[lc[i]];
		}
		int q = 0, x[] = new int[c];
		for (int i = 1; i <= c; i++) {
			if (lc[i] == i) {
				x[q++] = i;
			}
		}
		IntList cls[] = new IntList[q];
		for (int i = 0; i < q; i++) {
			cls[i] = new IntList();
		}
		int lcr[] = new int[c + 1];
		for (int i = 0; i < q; i++) {
			lcr[x[i]] = i;
		}
		for (int i = 1; i <= c; i++) {
			cls[lcr[lc[i]]].push(i);
		}
		out.print(q);
		for (int i = 0; i < q; i++) {
			out.print(' ');
			out.print(x[i]);
		}
		out.println();
		out.flush();
		int y[] = new int[c + 1];
		for (int i = 0; i < q; i++) {
			y[x[i]] = scanInt();
		}
		for (int i = c; i >= 1; i--) {
			if (lc[i] != i) {
				continue;
			}
			for (int j = i + i; j <= c; j += i) {
				if (lc[j] != j) {
					continue;
				}
				y[j] ^= y[i];
			}
		}
		for (int i = 1; i <= c; i++) {
			if (lc[i] != i) {
				continue;
			}
			for (int j = i + i; j <= c; j += i) {
				if (lc[j] != j) {
					continue;
				}
				y[i] ^= y[j];
			}
		}
		IntList ca = new IntList();
		LongList cb = new LongList();
		boolean ans[] = new boolean[c + 1];
		int ansN = 0;
		long lzeros[][] = new long[q][];
		BitSet bitZeros[][] = new BitSet[q][];
		int nZeros[] = new int[q];
		for (int i = 0; i < q; i++) {
			int cv = y[x[i]];
			IntList ccl = cls[i];
			int cn = ccl.size;
			if (cn < 64) {
				long cans = 0;
				ca.size = cb.size = cn;
				while (ca.data.length < cn) {
					ca.expand();
				}
				while (cb.data.length < cn) {
					cb.expand();
				}
				arraycopy(ccl.data, 0, ca.data, 0, cn);
				for (int j = 0; j < cn; j++) {
					cb.data[j] = 1L << j;
				}
				for (int bit = 19; bit >= 0; bit--) {
					int j;
					for (j = 0; j < cn; j++) {
						if ((ca.data[j] & (-1 << bit)) == 1 << bit) {
							break;
						}
					}
					if (j == cn) {
						if ((cv & (1 << bit)) != 0) {
							throw new AssertionError();
						}
						continue;
					}
					if ((cv & (1 << bit)) != 0) {
						cv ^= ca.data[j];
						cans ^= cb.data[j];
					}
					for (int jj = 0; jj < cn; jj++) {
						if (jj != j && (ca.data[jj] & (1 << bit)) != 0) {
							ca.data[jj] ^= ca.data[j];
							cb.data[jj] ^= cb.data[j];
						}
					}
				}
				for (int j = 0; j < cn; j++) {
					if ((cans & (1L << j)) != 0) {
						ans[ccl.data[j]] = true;
						++ansN;
					}
				}
				int nz = 0;
				for (int j = 0; j < cn; j++) {
					if (ca.data[j] == 0) {
						++nz;
					}
				}
				nZeros[i] = nz;
				lzeros[i] = new long[nz];
				nz = 0;
				for (int j = 0; j < cn; j++) {
					if (ca.data[j] == 0) {
						lzeros[i][nz++] = cb.data[j];
					}
				}
			} else {
				BitSet cans = new BitSet();
				ca.size = cn;
				while (ca.data.length < cn) {
					ca.expand();
				}
				arraycopy(ccl.data, 0, ca.data, 0, cn);
				BitSet ccb[] = new BitSet[cn];
				for (int j = 0; j < cn; j++) {
					ccb[j] = new BitSet();
					ccb[j].set(j);
				}
				for (int bit = 19; bit >= 0; bit--) {
					int j;
					for (j = 0; j < cn; j++) {
						if ((ca.data[j] & (-1 << bit)) == 1 << bit) {
							break;
						}
					}
					if (j == cn) {
						if ((cv & (1 << bit)) != 0) {
							throw new AssertionError();
						}
						continue;
					}
					if ((cv & (1 << bit)) != 0) {
						cv ^= ca.data[j];
						cans.xor(ccb[j]);
					}
					for (int jj = 0; jj < cn; jj++) {
						if (jj != j && (ca.data[jj] & (1 << bit)) != 0) {
							ca.data[jj] ^= ca.data[j];
							ccb[jj].xor(ccb[j]);
						}
					}
				}
				for (int j = 0; j < cn; j++) {
					if (cans.get(j)) {
						ans[ccl.data[j]] = true;
						++ansN;
					}
				}
				int nz = 0;
				for (int j = 0; j < cn; j++) {
					if (ca.data[j] == 0) {
						++nz;
					}
				}
				nZeros[i] = nz;
				bitZeros[i] = new BitSet[nz];
				nz = 0;
				for (int j = 0; j < cn; j++) {
					if (ca.data[j] == 0) {
						bitZeros[i][nz++] = ccb[j];
					}
				}
			}
		}
		int idx[] = new int[q];
		for (int i = 0; i < q; i++) {
			idx[i] = i;
		}
		sortBy(idx, q, nZeros);
		Random rng = new Random(42);
		while (ansN != n) {
			for (int i = q - 1; i >= 0; i--) {
				int ii = idx[i];
				if (nZeros[ii] == 0) {
					break;
				}
				IntList ccl = cls[ii];
				int cn = ccl.size;
				int j = rng.nextInt(nZeros[ii]);
				if (lzeros[ii] != null) {
					long z = lzeros[ii][j];
					for (int k = 0; k < cn; k++) {
						if ((z & (1L << k)) != 0) {
							ansN += (ans[ccl.data[k]] ^= true) ? 1 : -1;
						}
					}
				} else {
					BitSet z = bitZeros[ii][j];
					for (int k = 0; k < cn; k++) {
						if (z.get(k)) {
							ansN += (ans[ccl.data[k]] ^= true) ? 1 : -1;
						}
					}
				}
				if (ansN == n) {
					break;
				}
			}
		}
		for (int i = 1; i <= c; i++) {
			if (ans[i]) {
				out.print(i + " ");
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