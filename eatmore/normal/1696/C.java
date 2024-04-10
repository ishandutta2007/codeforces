import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class C {

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

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), m = scanInt();
			LongList l1 = new LongList();
			long curV = 0, curC = 0;
			for (int i = 0; i < n; i++) {
				long newV = scanInt(), newC = 1;
				while (newV % m == 0) {
					newV /= m;
					newC *= m;
				}
				if (curV != newV) {
					if (curC != 0) {
						l1.push(curV);
						l1.push(curC);
					}
					curV = newV;
					curC = newC;
				} else {
					curC += newC;
				}
			}
			if (curC != 0) {
				l1.push(curV);
				l1.push(curC);
			}
			n = scanInt();
			LongList l2 = new LongList();
			curV = 0;
			curC = 0;
			for (int i = 0; i < n; i++) {
				long newV = scanInt(), newC = 1;
				while (newV % m == 0) {
					newV /= m;
					newC *= m;
				}
				if (curV != newV) {
					if (curC != 0) {
						l2.push(curV);
						l2.push(curC);
					}
					curV = newV;
					curC = newC;
				} else {
					curC += newC;
				}
			}
			if (curC != 0) {
				l2.push(curV);
				l2.push(curC);
			}
			out.println(Arrays.equals(l1.data, 0, l1.size, l2.data, 0, l2.size) ? "Yes" : "No");
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