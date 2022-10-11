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

    int q = ni(), x = ni();

    boolean[] pos = new boolean[400005];
    long[] cur = new long[400005];
    for (int i = 0; i < 400002; i++) cur[i] = i - x;

    int pt = 0;
    for (int i = 0; i < q; i++) {
      long z = ni();
      z %= x;

      cur[(int)z] += x;
      z = cur[(int)z];

      if (z <= 400001) pos[(int)z] = true;
      while (pos[pt]) ++pt;
      out.println(pt);
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