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

    String s = in.nstr();
    int n = s.length();

    StringBuilder ob = new StringBuilder(), zb = new StringBuilder();
    String o = "";
    String zt = "";
    for (int i = 0; i < n; i++) {
      if (s.charAt(i) == '1') ob.append(s.charAt(i));
      else zb.append(s.charAt(i));
    }
    o = ob.toString();
    zt = zb.toString();
    int pos = n;
    for (int i = 0; i < zt.length(); i++) {
      if (zt.charAt(i) == '2') {
        pos = i;
        break;
      }
    }
    String ans;
    if (pos == n) ans = zt + o;
    else if (pos == 0) ans = o + zt;
    else ans = zt.substring(0, pos) + o + zt.substring(pos, zt.length());
    out.println(ans);
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
    public Scanner in;

    public IO(InputStream x) {
      in = new Scanner(x);
    }

    int nint() {
      return in.nextInt();
    }

    long nlong() {
      return in.nextLong();
    }

    double ndouble() {
      return in.nextDouble();
    }

    String nstr() {
      return in.next();
    }
    
    long[] nla(int n) {
      long[] arr = new long[n];
      for (int i = 0; i < n; i++) {
        arr[i] = nlong();
      }
      return arr;
    }
  }
}