import java.io.*;
import java.util.*;

public class Main {
  public static IO in;
  public static PrintWriter out;
  
  public static void main(String[] _u_n_u_s_e_d_) {
    in = new IO();
    out = new PrintWriter(System.out, true);

    int n = in.nint();
    int lpos = 0, rpos = 1000000000;
    String s = "black";
    out.println("1 0");
    String res = in.nstr();
    if (res.equals(s)) s = "white";
    for (int i = 0; i < n - 1; i++) {
      int mid = (lpos + rpos) / 2;
      out.println(1 + " " + mid);
      res = in.nstr();
      if (res.equals(s)) {
        rpos = mid;
      } else {
        lpos = mid;
      }
    }
    int mid = (lpos + rpos) / 2;
    out.println("0 " + (mid) + " 2 " + (mid + 1));
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

    IO() {
      in = new Scanner(System.in);
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