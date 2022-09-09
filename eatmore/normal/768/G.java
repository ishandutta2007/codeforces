import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G {

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

	static int tree[] = new int[1024];
	static int treePtr = 0;

	static int treeNew(int left, int right) {
		if (left == 0 && right == 0) {
			return 0;
		}
		int res = treePtr;
		if (tree.length == res) {
			tree = copyOf(tree, 2 * res);
		}
		tree[res] = left;
		tree[res + 1] = right;
		treePtr = res + 2;
		return ~res;
	}

	static int treeMerge(int a, int b) {
		if (a == 0) {
			return b;
		} else if (b == 0) {
			return a;
		} else if (a > 0 && b > 0) {
			return a + b;
		} else if (a < 0 && b < 0) {
			return treeNew(treeMerge(tree[~a], tree[~b]), treeMerge(tree[~a + 1], tree[~b + 1]));
		} else {
			throw new AssertionError();
		}
	}

	static int treeIncrement(int node, int depth, int n, int value) {
		if (depth == 0) {
			if (node >= 0 && node + value >= 0 && n == 0) {
				return node + value;
			} else {
				throw new AssertionError();
			}
		} else {
			int left, right;
			if (node == 0) {
				left = 0;
				right = 0;
			} else if (node < 0) {
				left = tree[~node];
				right = tree[~node + 1];
			} else {
				throw new AssertionError();
			}
			if (n < 1 << (depth - 1)) {
				left = treeIncrement(left, depth - 1, n, value);
			} else {
				right = treeIncrement(right, depth - 1, n - (1 << (depth - 1)), value);
			}
			return treeNew(left, right);
		}
	}

	static int n, bits, parent[];
	static IntList children[];
	static int subtreeSize[], subtreeSizes[], totalSize, ans[];

	static void solve() throws Exception {
		n = nextInt();
		bits = 32 - Integer.numberOfLeadingZeros(n);
		parent = new int[n];
		children = new IntList[n];
		for (int i = 0; i < n; i++) {
			children[i] = new IntList();
		}
		int root = -1;
		for (int i = 0; i < n; i++) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			parent[v] = u;
			if (u >= 0) {
				children[u].add(v);
			} else {
				root = v;
			}
		}
		subtreeSize = new int[n];
		subtreeSizes = new int[n];
		totalSize = dfs1(root);
		ans = new int[n];
		dfs2(root, subtreeSizes[root], 0);
		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
		}
	}

	static int dfs1(int cur) {
		int res = 1, resTree = 0;
		for (int i = 0; i < children[cur].size; i++) {
			int next = children[cur].data[i];
			res += dfs1(next);
			resTree = treeMerge(resTree, subtreeSizes[next]);
		}
		subtreeSize[cur] = res;
		subtreeSizes[cur] = treeIncrement(resTree, bits, res, 1);
		return res;
	}

	static void dfs2(int cur, int sizes, int upSizes) {
		int curSize = subtreeSize[cur];
		int subSizes = treeIncrement(sizes, bits, curSize, -1);
		int subUpSizes = treeIncrement(upSizes, bits, curSize, 1);
		int minSize = totalSize - curSize, maxSize = minSize, maxSize2 = 0, maxSizes = sizes;
		int count = minSize == 0 ? 0 : 1;
		boolean maxUp = true;
		for (int i = 0; i < children[cur].size; i++) {
			int next = children[cur].data[i];
			dfs2(next, subSizes, subUpSizes);
			int nextSize = subtreeSize[next];
			if (minSize == 0 || minSize > nextSize) {
				minSize = nextSize;
			}
			if (maxSize < nextSize) {
				maxSize2 = maxSize;
				maxSize = nextSize;
				maxSizes = subtreeSizes[next];
				maxUp = false;
			} else if (maxSize2 < nextSize) {
				maxSize2 = nextSize;
			}
			++count;
		}
		if (count <= 1) {
//			System.err.println("NODE " + (cur + 1) + " leaf");
			ans[cur] = totalSize - 1;
			return;
		}
//		System.err.println("NODE " + (cur + 1) + " min " + minSize + " max " + maxSize + " up " + maxUp);
		int maxSizesSub = maxUp ? subtreeSizes[cur] : 0;
		int cans = maxSize;
		getAnsRes = maxSize - minSize;
		getAns(maxSize - minSize, bits, maxSizes, maxSizesSub);
//		System.err.println(val);
		if (maxUp) {
			getAns(maxSize - minSize + 2 * curSize, bits, upSizes, 0);
		}
		cans = min(cans, (maxSize + minSize + getAnsRes) / 2);
		ans[cur] = max(cans, maxSize2);
	}

	static int getAnsRes;
	static void getAns(int point, int depth, int nodePlus, int nodeMinus) {
		if (nodePlus == nodeMinus) {
			return;
		}
		if (point + getAnsRes <= 0 || point - getAnsRes >= (2 << depth) - 2) {
			return;
		}
		if (depth == 0) {
			if (nodePlus >= 0 && nodeMinus >= 0) {
				int v = abs(point);
				if (getAnsRes > v) {
					getAnsRes = v;
				}
				return;
			} else {
				throw new AssertionError();
			}
		} else {
			int leftPlus, rightPlus;
			if (nodePlus == 0) {
				leftPlus = 0;
				rightPlus = 0;
			} else if (nodePlus < 0) {
				leftPlus = tree[~nodePlus];
				rightPlus = tree[~nodePlus + 1];
			} else {
				throw new AssertionError();
			}
			int leftMinus, rightMinus;
			if (nodeMinus == 0) {
				leftMinus = 0;
				rightMinus = 0;
			} else if (nodeMinus < 0) {
				leftMinus = tree[~nodeMinus];
				rightMinus = tree[~nodeMinus + 1];
			} else {
				throw new AssertionError();
			}
			if (point < 1 << depth) {
				getAns(point, depth - 1, leftPlus, leftMinus);
//				if (getAnsRes >= 0 && point + getAnsRes < 1 << depth) {
//					return;
//				}
				getAns(point - (1 << depth), depth - 1, rightPlus, rightMinus);
			} else {
				getAns(point - (1 << depth), depth - 1, rightPlus, rightMinus);
//				if (getAnsRes >= 0 && point - getAnsRes >= 1 << depth) {
//					return;
//				}
				getAns(point, depth - 1, leftPlus, leftMinus);
			}
		}
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