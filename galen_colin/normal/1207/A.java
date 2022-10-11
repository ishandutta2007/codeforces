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
      long[] vals = in.nla(5);

      if (vals[3] < vals[4]) {
        long temp = vals[1];
        vals[1] = vals[2];
        vals[2] = temp;
        
        temp = vals[3];
        vals[3] = vals[4];
        vals[4] = temp;
      }

      long ans = 0;
      vals[0] /= 2;
      long num = Math.min(vals[0], vals[1]);
      vals[0] -= num;
      ans += num * vals[3];
      ans += Math.min(vals[0], vals[2]) * vals[4];
      out.println(ans);
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

    
    long[] nla(int n) {
      long[] arr = new long[n];
      for (int i = 0; i < n; i++) {
        arr[i] = nlong();
      }
      return arr;
    }
  }
}