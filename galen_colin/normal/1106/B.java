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

    int n = in.nint(), m = in.nint();
    long[] left = in.nla(n);
    long[] cost = in.nla(n);
    long[] ans = new long[m];

    /* <<cost, index>, left> */
    TreeSet<Pair<Long, Integer>> vals = new TreeSet<Pair<Long, Integer>>(); 

    for (int i = 0; i < n; i++) {
      vals.add(new Pair(cost[i], i));
    }

    for (int i = 0; i < m; i++) {
      int ind = in.nint();
      --ind;
      long num = in.nlong();
      if (num > left[ind]) {
        if (left[ind] != 0) {
          ans[i] += cost[ind] * left[ind];
          num -= left[ind];
          vals.remove(new Pair(cost[ind], ind));
          left[ind] = 0;
        }

        while (num > 0 && vals.size() > 0) {
          Pair<Long, Integer> next = vals.first();

          int nind = next.s;
          if (num <= left[nind]) {
            left[nind] -= num;
            ans[i] += cost[nind] * num;
            num = 0;
          } else {
            ans[i] += cost[nind] * left[nind];
            num -= left[nind];
            left[nind] = 0;
            vals.remove(vals.first());
          }
        }

        if (num > 0) ans[i] = 0;
      } else {
        left[ind] -= num;
        ans[i] = num * cost[ind];
      }
    }

    for (int i = 0; i < m; i++) {
      out.println(ans[i]);
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
  }
}