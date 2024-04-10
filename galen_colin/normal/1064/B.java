import java.io.*;
import java.util.*;

public class Main {
  public static IO in;
  public static PrintWriter out;
  
  public static void main(String[] _u_n_u_s_e_d_) {
    in = new IO();
    out = new PrintWriter(System.out, true);

    int Q = in.nint();
    for (int q = 0; q < Q; q++) {
      int n = in.nint();
      int cnt = 0;
      for (int i = 0; i < 31; i++) {
        if ((n & (1 << i)) != 0) cnt++;
      }

      out.println((1 << cnt));
    }
   
    /* 1064B - also do the E */
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

    String nstring() {
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