import java.io.*;
import java.util.*;

public class Main {
  public static IO in;
  public static PrintWriter out;
  
  public static void main(String[] args) {
    in = new IO();
    out = new PrintWriter(System.out, true);

    int n = in.nint();
    long[] arr = in.nla(n);
    int max_len = Math.min(n, 2);

    int pt = 0;
    for (int i = 2; i < n; i++) {
      if (arr[i] == arr[i - 1] + arr[i - 2]) {
        max_len = Math.max(max_len, i - pt + 1);
      } else {
        pt = i - 1;
      }
    }
    out.println(max_len);
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