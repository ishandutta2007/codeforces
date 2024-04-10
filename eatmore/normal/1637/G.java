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
import java.util.StringTokenizer;

public class G {

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

	static IntList ans = new IntList();
	static int p2s[] = new int[17];

	static void squash(int p2, int p2c, int n) {
		for (int i = 1; i <= n; i++) {
			ans.push((1 << p2c) - (i << p2));
			ans.push((1 << p2c) + (i << p2));
		}
		p2s[p2c + 1] += n;
		subsolve(p2 + 1, n);
	}

	static void subsolve(int p2, int n) {
		for (int i = 31 - Integer.numberOfLeadingZeros(n); i >= 0; i--) {
			if (n >= 1 << i) {
				if (n > 1 << i) {
					squash(p2, p2 + i, n - (1 << i));
				}
				++p2s[p2 + i];
				n = (1 << (i + 1)) - 1 - n;
			}
		}
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt();
			if (n <= 2) {
				out.println(-1);
				continue;
			}
			ans.clear();
			fill(p2s, 0);
			subsolve(0, n);
			int l = 32 - Integer.numberOfLeadingZeros(n - 1);
			for (int i = 0;; i++) {
				if (i == l) {
					throw new AssertionError();
				}
				if (p2s[i] >= 2) {
					ans.push(1 << i);
					ans.push(1 << i);
					p2s[i] -= 2;
					++p2s[i + 1];
					break;
				}
			}
			for (int i = 0; i < l; i++) {
				while (p2s[i] != 0) {
					ans.push(0);
					ans.push(1 << i);
					ans.push(1 << i);
					ans.push(1 << i);
					--p2s[i];
					++p2s[i + 1];
				}
			}
			ans.push(0);
			ans.push(1 << l);
			out.println(ans.size >> 1);
			for (int i = 0; i < ans.size; i += 2) {
				out.println(ans.data[i] + " " + ans.data[i + 1]);
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