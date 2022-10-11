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
 
  final static long mod = 1_000_000_007;
  
  static long[] fact, ifact;
 
  public static void main(String[] _u_n_u_s_e_d_) throws Exception {
    init_io("");
 
    int n = in.nint();
    long[] counts = new long[n];
    for (int i = 0; i < n; i++) counts[i] = in.nlong();
    long[] sum = new long[n];
    long run = 0;
    for (int i = 0; i < n; i++) {
        run += counts[i];
        sum[i] = run;
    }
    
    int tot = (int)(sum[n - 1] + 1);
    
    long[] dp = new long[n + 1];
    
    fact = new long[1005];
    ifact = new long[1005];
    fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    for (int i = 2; i < 1005; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        ifact[i] = minv(fact[i]);
    }
    
    int cur = (int)counts[0];
    long ways = 1;
    for (int i = 1; i < n; i++) {
        int x = (int)counts[i];
        cur += x;
        ways = (ways * nck(cur - 1, x - 1)) % mod;
    }
    out.println(ways);
  }
  
  static long nck(int n, int k) {
    long dem = (ifact[n - k] * ifact[k]) % mod;
    return (fact[n] * dem) % mod;
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
 
  static int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
  }
 
  static void qsort(long[] arr) {
    Long[] oarr = new Long[arr.length];
    for (int i = 0; i < arr.length; i++) {
      oarr[i] = arr[i];
    }
 
    ArrayList<Long> alist = new ArrayList<Long>(Arrays.asList(oarr));
    Collections.sort(alist);
 
    for (int i = 0; i < arr.length; i++) {
      arr[i] = alist.get(i);
    }
  }
 
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