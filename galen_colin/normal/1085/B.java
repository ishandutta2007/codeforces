import java.io.*;
import java.util.*;

public class Main {
  public static IO in;
  public static PrintWriter out;
  
  public static void main(String[] args) {
    in = new IO();
    out = new PrintWriter(System.out, true);

    int n = in.nint(), k = in.nint();

    ArrayList<Long> facs = new ArrayList<Long>();
    for (long i = 1L; i * i <= n; i++) {
      if (n % i == 0) {
        facs.add(i);
        facs.add(n / i);
      }
    }

    long ans = Long.MAX_VALUE;
    for (Long fac: facs) {
      long ofac = n / fac;
      if (ofac >= k) continue;
      long oans = k * fac + ofac;
      ans = Math.min(ans, oans);
    }
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