import java.io.*;
import java.util.*;

public class Main {
  public static IO in;
  public static PrintWriter out;
  
  public static void main(String[] args) {
    in = new IO();
    out = new PrintWriter(System.out, true);

    long[] arg = in.nla(3);
    Arrays.sort(arg);
    out.println(Math.max(0, arg[2] - arg[1] - arg[0] + 1));
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