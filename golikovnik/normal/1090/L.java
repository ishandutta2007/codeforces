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
	
	
	
	public void solve() {
		long t1 = in.nextLong();
		long n1 = in.nextLong();
		long a1 = in.nextLong();
		long b1 = in.nextLong();
		long k1 = in.nextLong();
		long l = 0;
		long r = t1 + 1;
		while (l + 1 < r) {
			long m = (l + r) / 2;
			long k = k1;
			long n = n1;
			long a = a1;
			long b = b1;
			if (a >= m && b >= m) {
				if (n >= k) {
					l = m;
				} else {
					r = m;
				}
				continue;
			}
			if (a >= m) {
				k -= (n + 1) / 2;
				if (k <= 0) {
					l = m;
					continue;
				}
				n /= 2;
				if (n * b >= k * m) {
					l = m;
				} else {
					r = m;
				}
				continue;
			}
			if (b >= m) {
				k -= (n) / 2;
				if (k <= 0) {
					l = m;
					continue;
				}
				n -= n / 2;
				if (n * a >= k * m) {
					l = m;
				} else {
					r = m;
				}
				continue;
			}
			if ((n + 1) / 2 * a + n / 2 * b >= k * m) {
				l = m;
			} else {
				r = m;
			}
		}
		out.println(l);
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