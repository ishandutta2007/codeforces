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

  static int ans = 0;
  
  public static void main(String[] _u_n_u_s_e_d_) throws Exception {
    init_io("");

    int Q = in.nint();
    TreeMap<Integer, Integer> recs = new TreeMap<Integer, Integer>();
    for (int q = 0; q < Q; q++) {
      int n = in.nint();

      Integer x = recs.get(n);
      if (x != null) {
        out.println(x);
        continue;
      }
      int cnt = 0;
      boolean flag = false;
      int prev = n;
      while (n > 0) {
        if ((n & 1) == 0) flag = true;
        ++cnt;
        n /= 2;
      }
      int ans;
      if (flag) ans = (1 << cnt) - 1;
      else ans = compute(prev);

      recs.put(n, ans);
      out.println(ans);
    }
  }

  static int compute(int n) {
    int ans = 1;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) ans = Math.max(n / i, ans);
    }
    return ans;
  }

  static int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
  }

  static String getid(int k) {
    if (k < 26) return "" + (char)('A' + k);
    return "A" + (char)('a' + k - 26);
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
}