import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Side implements Comparable<Side> {
		long sq;
		int n;

		public Side(long sq, int n) {
			this.sq = sq;
			this.n = n;
		}

		@Override
		public int compareTo(Side o) {
			if (sq > o.sq) {
				return 1;
			}
			if (sq < o.sq) {
				return -1;
			}
			return n - o.n;
		}
	}

	public class Fract {
		long p;
		long q;

		public Fract(long p, long q) {
			this.p = p;
			this.q = q;
			long gcd = gcd(Math.abs(p), q);
			p /= gcd;
			q /= gcd;
		}
	}

	public Fract sum(Fract a, Fract b) {
		return new Fract(a.p * b.q + a.q * b.p, a.q * b.q);
	}

	public Fract neg(Fract a) {
		return new Fract(-a.p, a.q);
	}

	public Fract subtr(Fract a, Fract b) {
		return sum(a, neg(b));
	}

	public class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return x + ":" + y;
		}
	}

	public class Vertex {
		int x;
		int y;
		int a;
		int b;

		public Vertex(int x, int y, int a, int b) {
			this.x = x;
			this.y = y;
			this.a = a;
			this.b = b;
		}
	}

	public long gcd(long a, long b) {
		if (a == 0) {
			return b;
		}
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	public int gcd1(int a, int b) {
		if (a == 0) {
			return b;
		}
		if (b == 0) {
			return a;
		}
		return gcd1(b, a % b);
	}

	public long pow(long x, long p) {
		if (p == 0) {
			return 1;
		}
		if (p % 2 == 0) {
			long y = pow(x, p / 2);
			return y * y % mod;
		}
		return pow(x, p - 1) * x % mod;
	}

	public void lAdd() {
		l--;
		if (map.containsKey(s[l])) {
			map.put(s[l], map.get(s[l]) + 1);
		} else {
			map.put(s[l], 1);
		}
		th *= (r - l + 1);
		th %= mod;
		th *= modInv[map.get(s[l])];
		th %= mod;
	}

	public void rAdd() {
		r++;
		if (map.containsKey(s[r])) {
			map.put(s[r], map.get(s[r]) + 1);
		} else {
			map.put(s[r], 1);
		}
		th *= (r - l + 1);
		th %= mod;
		th *= modInv[map.get(s[r])];
		th %= mod;
	}

	public void lDel() {
		th *= modInv[r - l + 1];
		th %= mod;
		th *= map.get(s[l]);
		th %= mod;
		if (map.get(s[l]) == 1) {
			map.remove(s[l]);
		} else {
			map.put(s[l], map.get(s[l]) - 1);
		}
		l++;
	}

	public void rDel() {
		th *= modInv[r - l + 1];
		th %= mod;
		th *= map.get(s[r]);
		th %= mod;
		if (map.get(s[r]) == 1) {
			map.remove(s[r]);
		} else {
			map.put(s[r], map.get(s[r]) - 1);
		}
		r--;
	}

	final long mod = 1000000007;

	int l = 0;
	int r = -1;
	int[] s;
	long th = 1;
	long[] modInv;
	HashMap<Integer, Integer> map = new HashMap<>();

	public void solve() {
		long time = System.currentTimeMillis();
		int sz = 201;
		int max = 25;
		ArrayList<Pair> list0 = new ArrayList<>();
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				if (i == max && j < max - 1) {
					list0.add(new Pair(i, j));
				} else if (i < max - 1 && j == max) {
					list0.add(new Pair(i, j));
				} else {
					if (i >= max - 1 && j >= max - 1 && Math.abs(i - j) == 2) {
						list0.add(new Pair(i, j));
					}
				}
			}
		}
		max = 15;
		ArrayList<Pair> list1 = new ArrayList<>();
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				if (i == max && j < max - 1) {
					list1.add(new Pair(i, j));
				} else if (i < max - 1 && j == max) {
					list1.add(new Pair(i, j));
				} else {
					if (i >= max - 1 && j >= max - 1 && Math.abs(i - j) == 2) {
						list1.add(new Pair(i, j));
					}
				}
			}
		}
		Vertex[][][][] prev = new Vertex[sz][sz][4][4];
		prev[0][0][0][0] = new Vertex(-1, -1, -1, -1);
		for (int sum = 0; sum < 4; sum++) {
			for (int i = 0; i < 3; i++) {
				int j = sum - i;
				if (j < 0 || j >= 3) {
					continue;
				}
				for (int x = 0; x < sz; x++) {
					for (int y = 0; y < sz; y++) {
						if (prev[x][y][i][j] != null) {
							for (Pair p : list0) {
								if (x + p.x < sz && y + p.y < sz) {
									if (p.x > p.y) {
										prev[x + p.x][y + p.y][i + 1][j] = new Vertex(x, y, i, j);
									} else {
										prev[x + p.x][y + p.y][i][j + 1] = new Vertex(x, y, i, j);
									}
								}
							}
						}
					}
				}
			}
		}
		int i = 2;
		int j = 2;
		for (int x = 0; x < sz; x++) {
			for (int y = 0; y < sz; y++) {
				if (prev[x][y][i][j] != null) {
					for (Pair p : list1) {
						if (x + p.x < sz && y + p.y < sz) {
							if (p.x > p.y) {
								prev[x + p.x][y + p.y][i + 1][j] = new Vertex(x, y, i, j);
							} else {
								prev[x + p.x][y + p.y][i][j + 1] = new Vertex(x, y, i, j);
							}
						}
					}
				}
			}
		}
		System.err.println(System.currentTimeMillis() - time);
		Pair[] res = { new Pair(3, 0), new Pair(3, 1), new Pair(3, 2), new Pair(2, 3), new Pair(1, 3), new Pair(0, 3) };
		int t = in.nextInt();
		for (; t > 0; t--) {
			int a = in.nextInt();
			int b = in.nextInt();
			Vertex best = null;
			for (Pair p : res) {
				if (prev[a][b][p.x][p.y] != null) {
					out.println(p);
					best = new Vertex(a, b, p.x, p.y);
					break;
				}
			}
			if (best == null) {
				out.println("Impossible");
				continue;
			}
			ArrayList<Pair> ans = new ArrayList<>();
			while (best.x >= 0) {
				ans.add(new Pair(best.x - prev[best.x][best.y][best.a][best.b].x,
						best.y - prev[best.x][best.y][best.a][best.b].y));
				best = prev[best.x][best.y][best.a][best.b];
			}
			for (int k = ans.size() - 2; k >= 0; k--) {
				out.print(ans.get(k) + " ");
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
				out = new PrintWriter(System.out);
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
		new C().run();
	}
}