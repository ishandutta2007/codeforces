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
  
  public static void main(String[] _u_n_u_s_e_d_) throws Exception {
    init_io("");

    int Q = in.nint();

    TreeMap<String, Long> cnt = new TreeMap<String, Long>();
    for (int q = 0; q < Q; q++) {
      String type = in.nstr();
      if (type.equals("+")) {
        String str = "";
        long x = in.nlong();
        for (int it = 0; it < 20; it++) {
          str = (x % 2 == 1 ? '1' : '0') + str;
          x /= 10;
        }
        Long res = cnt.get(str);
        if (res == null) cnt.put(str, 1L);
        else cnt.put(str, res + 1);
      } else if (type.equals("-")) {
        String str = "";
        long x = in.nlong();
        for (int it = 0; it < 20; it++) {
          str = (x % 2 == 1 ? '1' : '0') + str;
          x /= 10;
        }
        Long res = cnt.get(str);
        if (res != null) cnt.put(str, res - 1);
      } else {
        String qu = in.nstr();
        while (qu.length() < 20) qu = "0" + qu;
        Long res = cnt.get(qu);
        if (res == null) res = 0L;
        out.println(res);
      }
    }
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