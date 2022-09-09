import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
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
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), m = scanInt(), a[] = new int[n], b[] = new int[n], maxA = 0;
			for (int i = 1; i < n; i++) {
				a[i] = scanInt();
				maxA = max(maxA, a[i]);
			}
			for (int i = 1; i < n; i++) {
				b[i] = scanInt();
			}
			IntList edges[] = new IntList[n];
			for (int i = 0; i < n; i++) {
				edges[i] = new IntList();
			}
			for (int i = 0; i < m; i++) {
				int u = scanInt() - 1, v = scanInt() - 1;
				edges[u].push(v);
				edges[v].push(u);
			}
			int status[] = new int[n];
			long strength[] = new long[n];
			int stack[] = new int[n];
			int l = 1, r = maxA;
			bs: while (l < r) {
				int mid = (l + r + 1) >> 1;
				long str = mid;
				status[0] = -2;
				fill(status, 1, n, -1);
				int left = n - 1;
				while (left > 0) {
					int stackSize = 0;
					int b1, b2;
					bb: {
						for (int cur = 0; cur < n; cur++) {
							if (status[cur] == -2) {
								IntList e = edges[cur];
								for (int i = 0; i < e.size; i++) {
									int next = e.data[i];
									if (a[next] >= str) {
										continue;
									}
									if (status[next] == -1) {
										status[next] = cur;
										strength[next] = str + b[next];
										stack[stackSize++] = next;
									} else if (status[next] >= 0) {
										b1 = next;
										b2 = cur;
										break bb;
									}
								}
							}
						}
						while (stackSize > 0) {
							int cur = stack[--stackSize];
							int prev = status[cur];
							long cstr = strength[cur];
							IntList e = edges[cur];
							for (int i = 0; i < e.size; i++) {
								int next = e.data[i];
								if (next == prev || a[next] >= cstr) {
									continue;
								}
								if (status[next] == -1) {
									status[next] = cur;
									strength[next] = cstr + b[next];
									stack[stackSize++] = next;
								} else {
									b1 = next;
									b2 = cur;
									break bb;
								}
							}
						}
						l = mid;
						continue bs;
					}
					while (status[b1] >= 0) {
						str += b[b1];
						int nb1 = status[b1];
						status[b1] = -2;
						--left;
						b1 = nb1;
					}
					while (status[b2] >= 0) {
						str += b[b2];
						int nb2 = status[b2];
						status[b2] = -2;
						--left;
						b2 = nb2;
					}
					for (int i = 0; i < n; i++) {
						if (status[i] != -2) {
							status[i] = -1;
						}
					}
				}
				r = mid - 1;
			}
			out.println(l + 1);
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