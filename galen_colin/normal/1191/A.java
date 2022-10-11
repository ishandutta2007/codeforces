import java.io.*;
import java.util.*;

public class Main {
  public static IO in;
  public static PrintWriter out;
  
  public static void main(String[] args) {
    in = new IO();
    out = new PrintWriter(System.out, true);

    int n = in.nint();
    String ans;
    if (n % 4 == 0) {
      ans = "1 A";
    } else if (n % 4 == 1) {
      ans = "0 A";
    } else if (n % 4 == 2) {
      ans = "1 B";
    } else {
      ans = "2 A";
    }
    out.println(ans);
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