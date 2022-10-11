import java.io.*;
import java.util.*;

public class Main {
  public static IO in;
  public static PrintWriter out;
  
  public static void main(String[] args) {
    in = new IO();
    out = new PrintWriter(System.out, true);

    int n = in.nint(), m = in.nint(), h = in.nint();
    long[] cols = in.nla(m);
    long[] rows = in.nla(n);
    long[][] grid = new long[n][m];
    for (int i = 0; i < n; i++) {
      grid[i] = in.nla(m);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          grid[i][j] = Math.min(rows[i], cols[j]);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      String s = "";
      for (int j = 0; j < m; j++) {
        if (j > 0) s += " ";
        s += grid[i][j];
      }
      out.println(s);
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