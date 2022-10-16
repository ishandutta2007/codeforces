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
	
	long p = 479001599;
	long mod = 655360001123456L;

	public void solve() {
		int n = in.nextInt();
		Str[] s = new Str[n];
		for (int q = 0; q < s.length; q++) {
			String s1 = in.next();
			String s2 = in.next();
			int[] l = new int['z' - 'a' + 1];
			for (int j = 0; j < s2.length(); j++) {
				l[s2.charAt(j) - 'a'] = 1;
			}
			long th = 0;
			long hash = 0;
			for (int i = 0; i < s1.length(); i++) {
				th = s1.charAt(i) + th * p;
				th %= mod;
				if (l[s1.charAt(i) - 'a'] == 0) {
					hash = th;
				}
			}
			s[q] = new Str(l, hash, q + 1);
		}
		Arrays.sort(s);
		Stack<ArrayList<Integer>> ans = new Stack<>();
		ArrayList<Integer> th = new ArrayList<>();
		th.add(s[0].number);
		for (int i = 1; i < s.length; i++) {
			if (s[i].compareTo(s[i - 1]) == 0) {
				th.add(s[i].number);
			} else {
				ans.add(th);
				th = new ArrayList<>();
				th.add(s[i].number);
			}
		}
		ans.add(th);
		out.println(ans.size());
		for (ArrayList<Integer> list : ans) {
			out.print(list.size() + " ");
			for (int i : list) {
				out.print(i + " ");
			}
			out.println();
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