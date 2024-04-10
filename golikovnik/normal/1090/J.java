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
		String s = in.next();
		int len = s.length() - 1;
		String t = in.next();
		int[] preft = new int[t.length() + 1];
		preft[0] = -1;
		preft[1] = 0;
		for (int i = 1; i < preft.length - 1; i++) {
			if (t.charAt(i) == t.charAt(preft[i])) {
				preft[i + 1] = preft[i] + 1;
			} else {
				int th = preft[i];
				while (th != -1) {
					if (t.charAt(i) == t.charAt(th)) {
						preft[i + 1] = th + 1;
						break;
					}
					th = preft[th];
				}
			}
		}
		s = t + "$" + s.substring(1);
		int[] prefs = new int[s.length() + 1];
		prefs[0] = -1;
		prefs[1] = 0;
		for (int i = 1; i < prefs.length - 1; i++) {
			if (s.charAt(i) == s.charAt(prefs[i])) {
				prefs[i + 1] = prefs[i] + 1;
			} else {
				int th = prefs[i];
				while (th != -1) {
					if (s.charAt(i) == s.charAt(th)) {
						prefs[i + 1] = th + 1;
						break;
					}
					th = prefs[th];
				}
			}
		}
		long ans = 0;
		int[] v = new int[len];
		for (int i = 0; i < len; i++) {
			v[i] = prefs[prefs.length - len + i];
		}
//		for (int i = 0; i < preft.length; i++) {
//			System.out.print(preft[i] + " ");
//		}
//		System.out.println();
//		for (int i = 0; i < v.length; i++) {
//			System.out.print(v[i] + " ");
//		}
//		System.out.println();
		int[] more = new int[len + 1];
		for (int i = 0; i < v.length; i++) {
			more[v[i]]++;
		}
//		for (int i = 0; i < more.length; i++) {
//			System.out.print(more[i] + " ");
//		}
//		System.out.println();
		for (int i = len; i >= 1; i--) {
			if (i < preft.length) {
//				System.out.println(i + " " + preft[i]);
				more[preft[i]] += more[i];
			}
		}
//		for (int i = 0; i < more.length; i++) {
//			System.out.print(more[i] + " ");
//		}
//		System.out.println();
		for (int i = 1; i < preft.length; i++) {
			ans += len + 1;
			if (preft[i] > 0 && i - preft[i] < more.length) {
				ans -= more[i - preft[i]];
			}
//			System.out.println(ans);
		}
		out.println(ans);
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