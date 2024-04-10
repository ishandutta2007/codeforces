import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.Random;
import java.util.StringTokenizer;

public class E {

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

	static void solve() throws Exception {
		int n = scanInt();
		int q = scanInt();
		Random rng = new Random(n * 239 + q * 65537);
		int shift = rng.nextInt(16385 - n), levels;
		{
			int y = 0, x1 = shift, x2 = shift + n;
			while (true) {
				if ((x1 & (1 << y)) != 0) {
					x1 += 1 << y;
				}
				if ((x2 & (1 << y)) != 0) {
					x2 -= 1 << y;
				}
				if (x1 < x2) {
					++y;
				} else {
					break;
				}
			}
			levels = y + 1;
		}
		queries = new IntList[levels][];
		for (int i = 0; i < levels; i++) {
			queries[i] = new IntList[(shift + n) >> i];
			for (int j = 0; j < queries[i].length; j++) {
				queries[i][j] = new IntList();
			}
		}
		for (int i = 0; i < q; i++) {
			int x1 = scanInt() + shift - 1;
			int x2 = scanInt() + shift;
			int v = scanInt();
			int y = 0;
			while (true) {
				if ((x1 & (1 << y)) != 0) {
					queries[y][x1 >> y].push(v);
					x1 += 1 << y;
				}
				if ((x2 & (1 << y)) != 0) {
					x2 -= 1 << y;
					queries[y][x2 >> y].push(v);
				}
				if (x1 < x2) {
					++y;
				} else {
					break;
				}
			}
		}
		ss = (n >> 6) + 1;
		states = new long[levels + 1][ss];
		ans = new long[ss];
		{
			int y = 0, x1 = shift, x2 = shift + n;
			while (true) {
				if ((x1 & (1 << y)) != 0) {
					fill(states[y + 1], 0);
					states[y + 1][0] = 1;
					go(y, x1 >> y);
					x1 += 1 << y;
				}
				if ((x2 & (1 << y)) != 0) {
					x2 -= 1 << y;
					fill(states[y + 1], 0);
					states[y + 1][0] = 1;
					go(y, x2 >> y);
				}
				if (x1 < x2) {
					++y;
				} else {
					break;
				}
			}
		}
		int k = 0;
		for (int i = 1; i <= n; i++) {
			if ((ans[i >> 6] & (1L << i)) != 0) {
				++k;
			}
		}
		out.println(k);
		for (int i = 1; i <= n; i++) {
			if ((ans[i >> 6] & (1L << i)) != 0) {
				out.print(i + " ");
			}
		}
	}

	static IntList queries[][];
	static int ss;
	static long states[][];
	static long ans[];

	static void go(int y, int x) {
		long pstate[] = states[y + 1], cstate[] = states[y];
		arraycopy(pstate, 0, cstate, 0, ss);
		IntList q = queries[y][x];
		for (int i = 0; i < q.size(); i++) {
			int v = q.get(i);
			if ((v & 63) == 0) {
				for (int j = ss - 1; j >= v >> 6; j--) {
					cstate[j] |= cstate[j - (v >> 6)];
				}
			} else {
				for (int j = ss - 1; j > v >> 6; j--) {
					cstate[j] |= (cstate[j - (v >> 6)] << v) | (cstate[j - (v >> 6) - 1] >>> -v);
				}
				cstate[v >> 6] |= cstate[0] << v;
			}
		}
		if (y == 0) {
			for (int i = 0; i < ss; i++) {
				ans[i] |= cstate[i];
			}
		} else {
			go(y - 1, x << 1);
			go(y - 1, (x << 1) + 1);
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