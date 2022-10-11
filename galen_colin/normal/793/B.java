import java.io.*;
import java.util.*;
 
public class Main {
  public static IO in;
  public static PrintWriter out;
 
  static void init_io(String filename) throws Exception {
    if (filename.equals("")) {
      in = new IO(System.in);
      out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);
    } else {
      in = new IO(new FileInputStream(filename + ".in"));
      out = new PrintWriter(new BufferedWriter(new FileWriter(filename + ".out")), true);
    }
  }
 
  final static long mod = 1000000007;
 
/*
fun main(args: Array<String>) {
    Main.main(args);
}
*/
 
  static int n, m;
 
  static int pack(int r, int c, int dir, int nturns) {
      return r * m * 12 + c * 12 + dir * 3 + nturns;
  }
  
  static int pack2(int pos, int dir, int nturns) {
      return pos * 12 + dir * 3 + nturns;
  }
  
  static int dr[] = new int[]{0, 0, -1, 1};
  static int dc[] = new int[]{1, -1, 0, 0};
  
  static boolean valid(int r, int c) {
      return r >= 0 && r < n && c >= 0 && c < m;
  }
 
  static void solve(int tc) throws Exception {
    n = in.nint();
    m = in.nint();
    
    boolean[][] grid = new boolean[n][m];
    boolean[] vis = new boolean[n * m * 12];
    
    int spos = 0, tpos = 0;
    for (int i = 0; i < n; i++) {
        String s = in.nstr();
        for (int j = 0; j < m; j++) {
            if (s.charAt(j) == 'S') spos = i * m + j;
            if (s.charAt(j) == 'T') tpos = i * m + j;
            grid[i][j] = (s.charAt(j) != '*');
        }
    }
    
    int[] queue = new int[15000000]; // (row, col, direction, # turns)
    
    int qstart = 0, qend = 0;
    
    for (int i = 0; i < 4; i++) {
        queue[qend++] = pack2(spos, i, 0);
    }
    
    while (qstart < qend) {
        int val = queue[qstart++];
        
        int r = val / (m * 12);
        int c = (val / 12) % m;
        int dir = (val / 3) % 4;
        int nturns = val % 3;
        // out.println(r + " " + c + " " + dir + " " + nturns);
        
        if (r * m + c == tpos) {
            out.println("YES\n");
            return;
        }
        
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            int nt = nturns;
            if (d != dir) ++nt;
            
            if (nt <= 2 && valid(nr, nc) && grid[nr][nc]) {
                int nstate = pack(nr, nc, d, nt);
                if (!vis[nstate]) {
                    vis[nstate] = true;
                    queue[qend++] = nstate;
                }
            }
        }
    }
    
    out.println("NO\n");
  }
 
  public static void main(String[] _u_n_u_s_e_d_) throws Exception {
    init_io("");
 
    int t = 1;
    // t = in.nint();
    for (int tc = 0; tc < t; tc++) {
      solve(tc);
    }
  }
 
  static long minv(long v) {
    return mpow(v, mod - 2);
  }
 
  static long mpow(long base, long exp) {
    long res = 1;
 
    while (exp > 0) {
      if ((exp & 1) == 1) {
        res = (res * base) % mod;
      }
      base = (base * base) % mod;
      exp >>= 1;
    }
 
    return res;
  }
 
  static int gcd(int x, int y) {
    if (x == 0) return y;
    if (y == 0) return x;
    return gcd(y % x, x);
  }
 
  static void rsort(long[] arr) {
    Random r = new Random();
    for (int i = 0; i < arr.length; i++) {
      int j = i + r.nextInt(arr.length - i);
      long t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
    }
    Arrays.sort(arr);
  }
 
  static void rsort(int[] arr) {
    Random r = new Random();
    for (int i = 0; i < arr.length; i++) {
      int j = i + r.nextInt(arr.length - i);
      int t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
    }
    Arrays.sort(arr);
  }
 
  /* static void qsort(long[] arr) {
    Long[] oarr = new Long[arr.length];
    for (int i = 0; i < arr.length; i++) {
      oarr[i] = arr[i];
    }
 
    ArrayList<Long> alist = new ArrayList<Long>(Arrays.asList(oarr));
    Collections.sort(alist);
 
    for (int i = 0; i < arr.length; i++) {
      arr[i] = (long)alist.get(i);
    }
  } */
 
  static void reverse(long[] arr) {
    for (int i = 0; i < arr.length / 2; i++) {
      long temp = arr[i];
      arr[i] = arr[arr.length - 1 - i];
      arr[arr.length - 1 - i] = temp;
    }
  }
 
  static String atos(long[] arr) {
    String s = Arrays.toString(arr);
    s = s.substring(1, s.length() - 1);
    return s.replace(",", "");
  }
 
  static class IO {
    public BufferedReader in;
    public StringTokenizer tokens;
 
    public IO(InputStream x) throws Exception {
      in = new BufferedReader(new InputStreamReader(x));
      tokens = new StringTokenizer(in.readLine());
    }
 
    int nint() throws Exception {
      return Integer.parseInt(nstr());
    }
 
    long nlong() throws Exception {
      return Long.parseLong(nstr());
    }
 
    double ndouble() throws Exception {
      return Double.parseDouble(nstr());
    }
 
    String nstr() throws Exception {
      if (!tokens.hasMoreTokens()) tokens = new StringTokenizer(in.readLine());
      return tokens.nextToken();
    }
    
    long[] nla(int n) throws Exception {
      long[] arr = new long[n];
      for (int i = 0; i < n; i++) {
        arr[i] = nlong();
      }
      return arr;
    }
  }
 
  static class Pair<A extends Comparable<A>, B extends Comparable<B>> implements Comparable<Pair<A, B>> {
    public A f;
    public B s;
 
    public Pair(A a, B b) {
      f = a;
      s = b;
    }
 
    public int compareTo(Pair<A, B> other) {
      int v = f.compareTo(other.f);
      if (v != 0) return v;
      return s.compareTo(other.s);
    }
 
    public String toString() {
      return "(" + f.toString() + ", " + s.toString() + ")";
    }
  }
}