import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class A {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public int gcd(int a, int b) {
		if (a == 0) {
			return b;
		}
		return gcd(b % a, a);
	}

	public class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

	}

	public class Str implements Comparable<Str> {
		int[] l;
		long hash;
		int number;

		public Str(int[] l, long hash, int number) {
			this.l = l;
			this.hash = hash;
			this.number = number;
		}

		@Override
		public int compareTo(Str o) {
			if (hash > o.hash) {
				return 1;
			} else if (hash < o.hash) {
				return -1;
			}
			for (int i = 0; i < l.length; i++) {
				if (l[i] != o.l[i]) {
					return l[i] - o.l[i];
				}
			}
			return 0;
		}
	}

	public class Ans {
		int from;
		int to;
		int type;

		public Ans(int from, int to, int type) {
			this.from = from;
			this.to = to;
			this.type = type;
		}

		public String toString() {
			return from + " " + to + " " + type;
		}
	}

	public class Child implements Comparable<Child> {
		int s;
		int[] set;
		int number;

		public Child(int s, int[] set, int number) {
			this.s = s;
			this.set = set;
			this.number = number;
		}

		@Override
		public int compareTo(Child o) {
			return o.s - s;
		}

	}

	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int sum = 0;
		ArrayList<Ans> ans = new ArrayList<>();
		Child[] children = new Child[n];
		for (int i = 0; i < n; i++) {
			int s = in.nextInt();
			int[] set = new int[s];
			for (int j = 0; j < s; j++) {
				set[j] = in.nextInt();
			}
			children[i] = new Child(s, set, i + 1);
			sum += s;
		}
		int[] size = new int[n];
		for (int i = 0; i < size.length; i++) {
			size[i] = sum / n;
		}
		sum -= sum / n * n;
		for (int i = 0; i < size.length; i++) {
			if (sum > 0) {
				sum--;
				size[i]++;
			}
		}
		Arrays.sort(children);
		int l = 0;
		int r = n - 1;
		BitSet[] set = new BitSet[n];
		for (int i = 0; i < set.length; i++) {
			set[i] = null;
		}
		int[] number = new int[n];
		for (int i = 0; i < number.length; i++) {
			number[i] = children[i].number;
		}
		int[] s = new int[n];
		for (int i = 0; i < s.length; i++) {
			s[i] = children[i].s;
		}
		while (l < r) {
			boolean flag = false;
			if (size[l] == s[l]) {
				set[l] = null;
				l++;
				flag = true;
			}
			if (size[r] == s[r]) {
				set[r] = null;
				r--;
				flag = true;
			}
			if (flag) {
				continue;
			}
			if (set[l] == null) {
				set[l] = new BitSet(m + 1);
				for (int i : children[l].set) {
					set[l].set(i);
				}
			}
			if (set[r] == null) {
				set[r] = new BitSet(m + 1);
				for (int i : children[r].set) {
					set[r].set(i);
				}
			}
			BitSet s1 = (BitSet) set[l].clone();
			s1.andNot(set[r]);
			int iter = Math.min(s[l] - size[l], size[r] - s[r]);
			int iter0 = iter;
			if (s[l] - size[l] == iter) {
				for (int i = s1.nextSetBit(0); i != -1; i = s1.nextSetBit(i + 1)) {
					set[r].set(i);
					ans.add(new Ans(number[l], number[r], i));
					iter--;
					if (iter == 0) {
						break;
					}
				}
			} else {
				for (int i = s1.nextSetBit(0); i != -1; i = s1.nextSetBit(i + 1)) {
					set[l].set(i, false);
					ans.add(new Ans(number[l], number[r], i));
					iter--;
					if (iter == 0) {
						break;
					}
				}
			}
			s[l] -= iter0;
			s[r] += iter0;
		}
		out.println(ans.size());
		for (Ans a : ans) {
			out.println(a.toString());
		}
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("input.txt"));
				out = new PrintWriter(new File("output.txt"));
			}
			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				return null;
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

	}

	// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	public static void main(String[] arg) {
		new A().run();
	}
}