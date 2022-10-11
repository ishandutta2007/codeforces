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
    int[] a = new int[n];
    for (int i = 0; i < n; i++) a[i] = ni() - 1;

    boolean[] vis = new boolean[100005];

    TreeMap<Integer, Integer> s = new TreeMap<Integer, Integer>();
    int cnt = 0;
    for (int i = 1; i < n; i++) {
      if (!s.containsKey(a[i])) {
        ++cnt;
        s.put(a[i], 1);
      } else s.put(a[i], s.get(a[i]) + 1);
    }

    long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (!vis[a[i]]) {
        vis[a[i]] = true;
        ans += cnt;
      }
      int v = s.get(a[i + 1]);
      if (v == 1) {
        s.remove(a[i + 1]);
        --cnt;
      } else s.put(a[i + 1], v - 1);
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