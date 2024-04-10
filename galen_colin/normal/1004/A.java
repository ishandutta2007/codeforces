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

    int n = ni();
    long d = nl();
    TreeSet<Long> ts = new TreeSet<Long>();
    long[] a = new long[n];
    for (int i = 0; i < n; i++) {
      a[i] = ni();
    }

    long ans = 0;
    for (int i = 0; i < n; i++) {
      long v = a[i] - d;
      if (!ts.contains(v)) {
        ts.add(v);
        long md = 5000000000L;
        for (int j = 0; j < n; j++) md = Math.min(md, Math.abs(a[j] - v));
        if (md == d) ++ans;
      }

      v = a[i] + d;
      if (!ts.contains(v)) {
        ts.add(v);
        long md = 5000000000L;
        for (int j = 0; j < n; j++) md = Math.min(md, Math.abs(a[j] - v));
        if (md == d) ++ans;
      }
    }

    out.println(ans);
  }

  static Point max(Point a, Point b) {
    if (a.x == b.x) {
      if (a.y < b.y) return new Point(b.x, b.y);
      return new Point(a.x, a.y);
    }
    if (a.x < b.x) return new Point(b.x, b.y);
    return new Point(a.x, a.y);
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

    public String toString() {
      return "(" + x + ", " + y + ")";
    }
  }
}