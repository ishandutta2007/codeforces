import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;

public class E {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static int left[], right[], value[], y[], size[], func[];
	static int free;

	static final Random rng = new Random();

	static int create(int val) {
		int res = free;
		free = value[free];
		left[res] = -1;
		right[res] = -1;
		value[res] = val;
		size[res] = 1;
		func[res] = val;
		return res;
	}

	static void destroy(int i) {
		value[i] = free;
		free = i;
	}

	static void fix(int i) {
		int l = left[i], r = right[i];
		int sl = l < 0 ? 0 : size[l];
		int sr = r < 0 ? 0 : size[r];
		size[i] = 1 + sl + sr;
		func[i] = value[i] - sl;
		if (l >= 0) {
			func[i] = min(func[i], func[l]);
		}
		if (r >= 0) {
			func[i] = min(func[i], func[r] - sl - 1);
		}
	}

	static int splitLeft, splitRight, splitSelf;
	static void split(int root, int val) {
		if (root < 0) {
			splitLeft = splitRight = splitSelf = -1;
		} else if (value[root] > val) {
			split(left[root], val);
			left[root] = splitRight;
			splitRight = root;
			fix(root);
		} else if (value[root] < val) {
			split(right[root], val);
			right[root] = splitLeft;
			splitLeft = root;
			fix(root);
		} else {
			splitLeft = left[root];
			splitRight = right[root];
			splitSelf = root;
			left[root] = right[root] = -1;
			fix(root);
		}
	}

	static void split2(int root, int v) {
		if (root < 0) {
			splitLeft = splitRight = -1;
		} else {
			int sl = left[root] < 0 ? 0 : size[left[root]];
			if (value[root] + sl + v >= 0) {
				split2(left[root], v);
				left[root] = splitRight;
				splitRight = root;
				fix(root);
			} else {
				split2(right[root], v + sl + 1);
				right[root] = splitLeft;
				splitLeft = root;
				fix(root);
			}
		}
	}

	static int merge(int l, int r) {
		if (l < 0) {
			return r;
		} else if (r < 0) {
			return l;
		} else if (y[l] < y[r]) {
			right[l] = merge(right[l], r);
			fix(l);
			return l;
		} else {
			left[r] = merge(l, left[r]);
			fix(r);
			return r;
		}
	}

//	static void print(int root) {
//		print2(root);
//		System.err.println();
//	}
//
//	static void print2(int root) {
//		if (root >= 0) {
//			System.err.print('(');
//			if (left[root] >= 0) {
//				print2(left[root]);
//				System.err.print(' ');
//			}
//			System.err.print(value[root]);
//			if (right[root] >= 0) {
//				System.err.print(' ');
//				print2(right[root]);
//			}
//			System.err.print(')');
//		}
//	}

	static void solve() throws Exception {
		int n = nextInt();
		left = new int[n];
		right = new int[n];
		value = new int[n];
		y = new int[n];
		size = new int[n];
		func = new int[n];
		free = 0;
		for (int i = 0; i < n; i++) {
			y[i] = rng.nextInt();
			value[i] = i < n - 1 ? i + 1 : -1;
		}
		int root = -1;
		for (int i = 0; i < n; i++) {
			int val = nextInt();
			split(root, val);
			root = merge(merge(merge(splitLeft, create(val)), splitSelf), splitRight);
//			print(root);
			split2(root, 0);
			int sl = splitLeft < 0 ? 0 : size[splitLeft];
			int sr = splitRight < 0 ? 0 : size[splitRight];
			int fr = splitRight < 0 ? 2 * n : func[splitRight];
			out.println(min(sr - sl, fr + sr - 1));
			root = merge(splitLeft, splitRight);
//			print(root);
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