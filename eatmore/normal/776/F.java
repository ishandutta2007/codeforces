import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class F {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

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

		void set(int index, int value) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			data[index] = value;
		}

		void add(int value) {
			if (size >= data.length) {
				data = copyOf(data, (data.length << 1) + 1);
			}
			data[size++] = value;
		}

		int remove(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			int value = data[index];
			arraycopy(data, index + 1, data, index, --size - index);
			return value;
		}

		void clear() {
			size = 0;
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

	static IntList edges[];
	static int color[];

	static void solve() throws Exception {
		int n = nextInt();
		int m = n + nextInt();
		IntList lines[] = new IntList[n];
		int point1[] = new int[m];
		int point2[] = new int[m];
		for (int i = 0; i < n; i++) {
			lines[i] = new IntList();
			lines[i].add(i);
			lines[i].add((i + n - 1) % n);
			point1[i] = i;
			point2[i] = (i + 1) % n;
		}
		for (int i = n; i < m; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			lines[a].add(i);
			lines[b].add(i);
			point1[i] = a;
			point2[i] = b;
		}
		int pointSum[] = new int[m];
		for (int i = 0; i < m; i++) {
			pointSum[i] = point1[i] + point2[i];
		}
		int nextLine1[] = new int[m];
		int nextLine2[] = new int[m];
		fill(nextLine1, -1);
		fill(nextLine2, -1);
		int sortKey[] = new int[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < lines[i].size; j++) {
				int cur = lines[i].data[j], other = pointSum[cur] - i;
				sortKey[cur] = (other - i + n) % n;
			}
			sortBy(lines[i].data, lines[i].size, sortKey);
			for (int j = 0; j < lines[i].size - 1; j++) {
				int cur = lines[i].data[j], next = lines[i].data[j + 1];
				if (point1[cur] == i) {
					nextLine1[cur] = next;
				} else {
					nextLine2[cur] = next;
				}
			}
		}
//		for (int i = 0; i < m; i++) {
//			System.err.println("Line " + (i + 1) + ": " + (point1[i] + 1) + " " + (point2[i] + 1) +
//				", " + (nextLine1[i] + 1) + " " + (nextLine2[i] + 1));
//		}
		boolean seen1[] = new boolean[m];
		boolean seen2[] = new boolean[m];
		final List<int[]> faces = new ArrayList<>();
		IntList curFace = new IntList();
		int face1[] = new int[m - n];
		int face2[] = new int[m - n];
		fill(face1, -1);
		fill(face2, -1);
		start: for (int start = 0; start < m;) {
			int point, line = start;
			if (!seen1[start]) {
				point = point1[line];
			} else if (!seen2[start]) {
				point = point2[line];
			} else {
				++start;
				continue;
			}
			curFace.clear();
			boolean haveFace = false;
			while (!(point == point1[line] ? seen1 : seen2)[line]) {
				curFace.add(-point);
				if (line >= n) {
					(point == point1[line] ? face1 : face2)[line - n] = faces.size();
					haveFace = true;
				}
				(point == point1[line] ? seen1 : seen2)[line] = true;
				line = (point == point1[line] ? nextLine1 : nextLine2)[line];
				if (line < 0) {
					if (haveFace) {
						throw new AssertionError();
					}
					continue start;
				}
				point = pointSum[line] - point;
			}
			faces.add(copyOf(curFace.data, curFace.size));
		}
		int nFaces = faces.size();
		if (nFaces != m - n + 1) {
			throw new AssertionError();
		}
		edges = new IntList[nFaces];
		for (int i = 0; i < nFaces; i++) {
			edges[i] = new IntList();
		}
		for (int i = 0; i < m - n; i++) {
			edges[face1[i]].add(face2[i]);
			edges[face2[i]].add(face1[i]);
		}
		color = new int[nFaces];
		fill(color, -1);
		dfs1(0, -1, 0);
		for (int[] face: faces) {
			sort(face);
		}
		Integer idx[] = new Integer[nFaces];
		for (int i = 0; i < nFaces; i++) {
			idx[i] = i;
		}
		sort(idx, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				int[] face1 = faces.get(o1);
				int[] face2 = faces.get(o2);
				for (int i = 0; i < max(face1.length, face2.length); i++) {
					int cur = (i >= face1.length ? -1 : -face1[i]) - (i >= face2.length ? -1 : -face2[i]);
					if (cur != 0) {
						return cur;
					}
				}
				return 0;
			}
		});
//		System.err.println("Regions:");
		for (int i = 0; i < nFaces; i++) {
			out.print((color[idx[i]] + 1) + " ");
//			for (int j = faces.get(idx[i]).length - 1; j >= 0; j--) {
//				System.err.print((-faces.get(idx[i])[j] + 1) + " ");
//			}
//			System.err.println();
		}
	}

	static void dfs1(int cur, int prev, int curColor) {
		int size = dfs2(cur, prev);
		dfs3(cur, prev, curColor, (size + 1) / 2);
	}

	static int dfs2(int cur, int prev) {
		int res = 1;
		for (int i = 0; i < edges[cur].size; i++) {
			int next = edges[cur].data[i];
			if (next != prev && color[next] < 0) {
				res += dfs2(next, cur);
			}
		}
		return res;
	}

	static int dfs3(int cur, int prev, int curColor, int size) {
		int curSize = 1;
		for (int i = 0; i < edges[cur].size; i++) {
			int next = edges[cur].data[i];
			if (next != prev && color[next] < 0) {
				int subSize = dfs3(next, cur, curColor, size);
				if (subSize >= size) {
					return size;
				}
				curSize += subSize;
			}
		}
		if (curSize >= size) {
			color[cur] = curColor;
			for (int i = 0; i < edges[cur].size; i++) {
				int next = edges[cur].data[i];
				if (color[next] < 0) {
					dfs1(next, cur, curColor + 1);
				}
			}
		}
		return curSize;
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