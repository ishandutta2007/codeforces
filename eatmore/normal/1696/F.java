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

public class F {

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

	static int n;
	static boolean same[][][], seen[][], seen2[];
	static IntList edges[], haveEdges;
	static int dist[][];

	static void solve() throws Exception {
		int tests = scanInt();
		test: for (int test = 0; test < tests; test++) {
			n = scanInt();
			same = new boolean[n][n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					same[i][j][i] = true;
				}
				for (int j = 0; j < n - i - 1; j++) {
					String s = scanString();
					for (int k = 0; k < n; k++) {
						if (s.charAt(k) == '1') {
							same[i][k][i + j + 1] = same[i + j + 1][k][i] = true;
						}
					}
				}
			}
			seen = new boolean[n][n];
			edges = new IntList[n];
			for (int i = 0; i < n; i++) {
				edges[i] = new IntList();
			}
			haveEdges = new IntList();
			seen2 = new boolean[n];
			dist = new int[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < i; j++) {
					if (seen[i][j]) {
						continue;
					}
					dfs1(i, j);
					if (haveEdges.size == 2 * (n - 1)) {
						if (dfs2(0) == n) {
							for (int ii = 0; ii < n; ii++) {
								dfs3(ii, ii, -1, 0);
							}
							finalCheck: {
								for (int ii = 0; ii < n; ii++) {
									for (int jj = 0; jj < n; jj++) {
										for (int kk = 0; kk < n; kk++) {
											if (same[ii][jj][kk] != (dist[ii][jj] == dist[jj][kk])) {
												break finalCheck;
											}
										}
									}
								}
								out.println("Yes");
								for (int ii = 0; ii < n; ii++) {
									for (int jj = 0; jj < edges[ii].size; jj++) {
										int kk = edges[ii].data[jj];
										if (kk > ii) {
											out.println((ii + 1) + " " + (kk + 1));
										}
									}
								}
								continue test;
							}
						}
						fill(seen2, false);
					}
					for (int ii = 0; ii < haveEdges.size; ii++) {
						edges[haveEdges.data[ii]].size = 0;
					}
					haveEdges.size = 0;
				}
			}
			out.println("No");
		}
	}

	static void dfs1(int i, int j) {
		seen[i][j] = seen[j][i] = true;
		edges[i].push(j);
		edges[j].push(i);
		haveEdges.push(i);
		haveEdges.push(j);
		for (int k = 0; k < n; k++) {
			if (same[i][j][k] && !seen[j][k]) {
				dfs1(j, k);
			}
			if (same[k][i][j] && !seen[k][i]) {
				dfs1(k, i);
			}
		}
	}

	static int dfs2(int cur) {
		seen2[cur] = true;
		int r = 1;
		for (int i = 0; i < edges[cur].size; i++) {
			int next = edges[cur].data[i];
			if (!seen2[next]) {
				r += dfs2(next);
			}
		}
		return r;
	}

	static void dfs3(int start, int cur, int prev, int depth) {
		dist[start][cur] = depth;
		for (int i = 0; i < edges[cur].size; i++) {
			int next = edges[cur].data[i];
			if (next != prev) {
				dfs3(start, next, cur, depth + 1);
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