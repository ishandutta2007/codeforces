import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.Random;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Node {
		static final Random rng = new Random(42);
		
		final int depth = rng.nextInt();
		final long value;
		final int val2;
		
		Node left, right;
		int size, max;
		
		Node(long value) {
			this.value = value;
			this.val2 = 0;
			fix();
		}
		
		Node(long value, int val2) {
			this.value = value;
			this.val2 = val2;
			fix();
		}
		
		static int size(Node node) {
			return node == null ? 0 : node.size;
		}
		
		static int v2m(Node node) {
			return node == null ? -1 : node.max;
		}
		
		void fix() {
			size = 1 + size(left) + size(right);
			max = max(max(val2, v2m(left)), v2m(right));
		}
		
		public String toString() {
			String out = "(";
			if (left != null) {
				out += left + " ";
			}
			out += "[v: " + value + ", v2: " + val2 + ", c: " + size + ", m: " + max + "]";
			if (right != null) {
				out += " " + right;
			}
			out += ")";
			return out;
		}
	}
	
	static Node splitLeft, splitMid, splitRight;
	
	static void split(Node n, long x) {
		if (n == null) {
			splitLeft = null;
			splitRight = null;
			splitMid = null;
		} else if (n.value > x) {
			split(n.left, x);
			n.left = splitRight;
			splitRight = n;
			n.fix();
		} else if (n.value < x) {
			split(n.right, x);
			n.right = splitLeft;
			splitLeft = n;
			n.fix();
		} else {
			splitLeft = n.left;
			n.left = null;
			splitRight = n.right;
			n.right = null;
			splitMid = n;
			n.fix();
		}
	}
	
	static Node merge(Node a, Node b) {
		if (a == null) {
			return b;
		}
		if (b == null) {
			return a;
		}
		if (a.depth < b.depth) {
			a.right = merge(a.right, b);
			a.fix();
			return a;
		} else {
			b.left = merge(a, b.left);
			b.fix();
			return b;
		}
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		long k = nextLong();
		final int r[] = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = nextInt();
		}
		long a[] = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}
		Integer idx[] = new Integer[n];
		for (int i = 0; i < n; i++) {
			idx[i] = i;
		}
		sort(idx, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return r[o1] - r[o2];
			}
		});
		int size[] = new int[n];
		Node tree = null;
//		System.err.println("==== Phase 1");
		for (int i: idx) {
			split(tree, 2 * a[i] - 1);
			tree = merge(merge(splitLeft, new Node(2 * a[i])), splitRight);
//			System.err.println("Tree: " + tree);
			split(tree, 2 * (a[i] - k) - 1);
			Node tmp = splitLeft;
			split(splitRight, 2 * (a[i] + k) + 1);
			size[i] = Node.size(splitLeft);
//			System.err.println("From " + (2 * (a[i] - k) - 1) + " to " + (2 * (a[i] + k) + 1) + ": " + splitLeft);
			tree = merge(merge(tmp, splitLeft), splitRight);
//			System.err.println("Tree: " + tree);
		}
//		System.err.println(Arrays.toString(size));
		int q = nextInt();
		final int x[] = new int[q];
		final int y[] = new int[q];
		for (int i = 0; i < q; i++) {
			x[i] = nextInt() - 1;
			y[i] = nextInt() - 1;
		}
		Integer idx2[] = new Integer[q];
		for (int i = 0; i < q; i++) {
			idx2[i] = i;
		}
		sort(idx2, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return max(r[x[o1]], r[y[o1]]) - max(r[x[o2]], r[y[o2]]);
			}
		});
		Node root = null;
		int ans[] = new int[q];
		fill(ans, Integer.MIN_VALUE);
//		System.err.println("==== Phase 2");
		for (int p1 = n - 1, p2 = q - 1; p2 >= 0; ) {
			int v1 = p1 >= 0 ? idx[p1] : Integer.MIN_VALUE;
			int v2 = idx2[p2];
			if (p1 >= 0 && r[v1] >= max(r[x[v2]], r[y[v2]])) {
//				System.err.println("Add " + (v1 + 1) + " (" + a[v1] + ")");
				split(root, 2 * a[v1] - 1);
				root = merge(merge(splitLeft, new Node(2 * a[v1], size[v1])), splitRight);
				--p1;
			} else {
//				System.err.println("Check " + (v2 + 1) + " (" + (x[v2] + 1) + " " + (y[v2] + 1) + ")");
				long mina = min(a[x[v2]], a[y[v2]]);
				long maxa = max(a[x[v2]], a[y[v2]]);
				if (maxa - mina <= 2 * k) {
					split(root, 2 * (maxa - k) - 1);
					Node tmp = splitLeft;
					split(splitRight, 2 * (mina + k) + 1);
//					System.err.println("From " + (2 * (maxa - k) - 1) + " to " + (2 * (mina + k) + 1) + ": " + splitLeft);
					ans[v2] = Node.v2m(splitLeft);
					root = merge(merge(tmp, splitLeft), splitRight);
				} else {
					ans[v2] = -1;
				}
				--p2;
			}
//			System.err.println("Tree: " + root);
		}
		for (int i = 0; i < q; i++) {
			out.println(ans[i]);
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