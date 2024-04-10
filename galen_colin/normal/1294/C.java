import java.io.*;
import java.util.*;

public class Main {
  static BufferedReader reader;
  static StringTokenizer stoken;
  static PrintWriter out;

  static int ni() throws Exception {
    return Integer.parseInt(ns());
  }

  static long nl() throws Exception {
    return Long.parseLong(ns());
  }

  static double nd() throws Exception {
    return Double.parseDouble(ns());
  }

  static String ns() throws Exception {
    if (stoken == null || !stoken.hasMoreTokens()) stoken = new StringTokenizer(reader.readLine());
    return stoken.nextToken();
  }

  public static void main(String[] args) throws Exception {
    reader = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);

    int Q = ni();
    for (int q = 0; q < Q; q++) {
      int n = ni();

      int div1 = -1, div2 = -1;
      for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
          div1 = i;
          div2 = n / i;
          break;
        }
      }

      int div3 = -1;
      if (div1 == -1) {
        out.println("NO");
      } else {
        for (int i = 2; i * i < div1; i++) {
          if (div1 % i == 0 && i != div1 && i != div2) {
            div3 = i;
            div1 /= i;
            break;
          }
        }
        for (int i = 2; i * i < div2; i++) {
          if (div2 % i == 0 && i != div1 && i != div2) {
            div3 = i;
            div2 /= i;
            break;
          }
        }
        if (div3 == -1) out.println("NO"); 
        else {
          out.println("YES");
          out.println(div1 + " " + div2 + " " + div3);
        }
      }
    }
  }

  static class Point implements Comparable<Point> {
    public int x;
    public int y;

    Point() {}
    Point(int a, int b) {x = a; y = b;}

    public int compareTo(Point other) {
      if (x == other.x) return y - other.y;
      return x - other.x;
    }
  }
}