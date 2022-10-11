import java.io.*;
import java.util.*;

public class Main {
  public static IO in;
  public static PrintWriter out;
  
  public static void main(String[] args) {
    in = new IO();
    out = new PrintWriter(System.out, true);

    int Q = in.nint();
    for (int i = 0; i < Q; i++) {
      int n = in.nint();
      String s = in.nstring();
      boolean flag = false;
      for (int j = 0; j < Math.max(n - 10, 0); j++) {
        if (s.charAt(j) == '8') flag = true;
      }
      if (flag) out.println("YES");
      else out.println("NO");
    }
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