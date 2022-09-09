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

public class D {

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
		int m = scanInt();
		IntList edges[] = new IntList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new IntList();
		}
		for (int i = 0; i < m; i++) {
			int a = scanInt() - 1;
			int b = scanInt() - 1;
			edges[a].push(b);
			edges[b].push(a);
		}
		int dist[] = new int[n], prev[] = new int[n];
		int queue[] = new int[n], queueHead = 0, queueTail = 1;
		fill(dist, 1, n, Integer.MAX_VALUE);
		prev[0] = -1;
		do {
			int cur = queue[queueHead++], newDist = dist[cur] + 1;
			IntList eCur = edges[cur];
			for (int i = 0; i < eCur.size(); i++) {
				int next = eCur.get(i);
				if (dist[next] == Integer.MAX_VALUE) {
					dist[next] = newDist;
					prev[next] = cur;
					queue[queueTail++] = next;
				}
			}
		} while (queueHead < queueTail);
		if (dist[n - 1] > 4) {
			boolean dir0[] = new boolean[n];
			dir0[0] = true;
			IntList e0 = edges[0];
			for (int i = 0; i < e0.size(); i++) {
				dir0[e0.get(i)] = true;
			}
			for (int i = 0; i < e0.size(); i++) {
				int cur = e0.get(i);
				IntList eCur = edges[cur];
				for (int j = 0; j < eCur.size(); j++) {
					int next = eCur.get(j);
					if (!dir0[next]) {
						out.println(4);
						out.print("1 " + (cur + 1) + " " + (next + 1) + " 1 " + n);
						return;
					}
				}
			}
			if (dist[n - 1] > 5) {
				boolean seen[] = new boolean[n], seenCur[] = new boolean[n];
				for (int i = 0; i < e0.size(); i++) {
					int cur = e0.get(i);
					if (seen[cur]) {
						continue;
					}
					seenCur[cur] = true;
					IntList eCur = edges[cur];
					int curSize = eCur.size();
					for (int j = 0; j < eCur.size(); j++) {
						seenCur[eCur.get(j)] = true;
					}
					for (int j = 0; j < eCur.size(); j++) {
						int next = eCur.get(j);
						if (next == 0) {
							continue;
						}
						IntList eNext = edges[next];
						for (int k = 0; k < eNext.size(); k++) {
							int next2 = eNext.get(k);
							if (!seenCur[next2]) {
								out.println(5);
								out.print("1 " + (cur + 1) + " " + (next + 1) + " " + (next2 + 1) + " " + (cur + 1) + " " + n);
								return;
							}
						}
						if (eNext.size() != curSize) {
							seenCur[next] = false;
							for (int k = 0; k < eNext.size(); k++) {
								seenCur[eNext.get(k)] = false;
							}
							for (int next2 = 0; next2 < n; next2++) {
								if (seenCur[next2]) {
									out.println(5);
									out.print("1 " + (next + 1) + " " + (cur + 1) + " " + (next2 + 1) + " " + (next + 1) + " " + n);
									return;
								}
							}
							throw new AssertionError();
						}
					}
					seenCur[cur] = false;
					seen[cur] = true;
					for (int j = 0; j < eCur.size(); j++) {
						int next = eCur.get(j);
						seenCur[next] = false;
						seen[next] = true;
					}
				}
				if (dist[n - 1] == Integer.MAX_VALUE) {
					out.print(-1);
					return;
				}
			}
		}
		out.println(dist[n - 1]);
		IntList ans = new IntList();
		for (int cur = n - 1; cur >= 0; cur = prev[cur]) {
			ans.push(cur);
		}
		for (int i = dist[n - 1]; i >= 0; i--) {
			out.print((ans.get(i) + 1) + " ");
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