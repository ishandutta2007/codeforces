import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		solver.solve(in, out);
		out.close();
	}
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream), 32768);
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

}

class FibNums {
	static final long MOD = 1000000000 + 9;
	public long[] a, b;
	public long[] sa, sb;

	public FibNums(int n) {
		n = Math.max(n + 5, 2);
		a = new long[n];
		b = new long[n];
		a[0] = 1;
		a[1] = 0;
		b[0] = 0;
		b[1] = 1;
		for (int i = 2; i < n; ++i) {
			a[i] = (a[i - 1] + a[i - 2]) % MOD;
			b[i] = (b[i - 1] + b[i - 2]) % MOD;
		}
		sa = new long[n + 1];
		sb = new long[n + 1];
		sa[0] = sb[0] = 0;
		for (int i = 0; i < n; ++i) {
			sa[i + 1] = (sa[i] + a[i]) % MOD;
			sb[i + 1] = (sb[i] + b[i]) % MOD;
		}

	}

	public long getVal(int i) {
		return (a[i] + b[i]) % MOD;
	}
}

class TreeNode {
	static final long MOD = 1000000000 + 9;
	static FibNums fib;
	int n;
	TreeNode l, r;
	long sum, b1, b2;

	private void update() {
		sum = (l.sum + r.sum) % MOD;
	}

	private void push(long a1, long a2) {
		b1 = (b1 + a1) % MOD;
		b2 = (b2 + a2) % MOD;
		long v1 = fib.sa[n] * a1 % MOD;
		long v2 = fib.sb[n] * a2 % MOD;
		sum = (sum + v1 + v2) % MOD;
	}

	private void release() {
		l.push(b1, b2);
		long c1 = (fib.a[n / 2] * b1 + fib.b[n / 2] * b2) % MOD;
		long c2 = (fib.a[n / 2 + 1] * b1 + fib.b[n / 2 + 1] * b2) % MOD;
		r.push(c1, c2);
		b1 = b2 = 0;
	}

	public TreeNode(int[] a, int x, int y) {
		n = y - x;
		b1 = b2 = 0;
		if (n == 1) {
			l = r = null;
			sum = a[x];
		} else {
			int mid = (x + y) / 2;
			l = new TreeNode(a, x, mid);
			r = new TreeNode(a, mid, y);
			update();
		}
	}

	public void add(int x, int y) {
		if (x <= 0 && n <= y) {
			push(fib.getVal(-x), fib.getVal(-x + 1));
			return;
		}
		if (x >= n || y <= 0)
			return;
		release();
		l.add(x, y);
		r.add(x - l.n, y - l.n);
		update();
	}

	public long query(int x, int y) {
		if (x <= 0 && n <= y)
			return sum;
		if (x >= n || y <= 0)
			return 0;
		release();
		return (l.query(x, y) + r.query(x - l.n, y - l.n)) % MOD;
	}
}

class Solver {
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int numQuery = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
		TreeNode.fib = new FibNums(n);
		TreeNode root = new TreeNode(a, 0, n);
		for (int i = 0; i < numQuery; i++) {
			int op = in.nextInt();
			int l = in.nextInt() - 1;
			int r = in.nextInt();
			if (op == 1) {
				root.add(l, r);
			} else {
				long ans = root.query(l, r);
				out.println(ans);
			}
		}
	}
}