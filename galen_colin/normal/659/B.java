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

  static ArrayList<ArrayList<Point>> ap;

  public static void main(String[] args) throws Exception {
    reader = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);

    int n = ni(), m = ni();
    ap = new ArrayList<ArrayList<Point>>();
    for (int i = 0; i < m; i++) ap.add(new ArrayList<Point>());

    for (int i = 0; i < n; i++) {
      String a = ns();
      int b = ni(), c = ni();

      --b;
      ap.get(b).add(new Point(c, a));
    }

    for (int i = 0; i < m; i++) {
      Collections.sort(ap.get(i));
      int sz = ap.get(i).size();
      if (sz < 2) out.println("?");
      else {
        if (sz > 2 && ap.get(i).get(sz - 1).x == ap.get(i).get(sz - 3).x) out.println("?");
        else if (sz > 2 && ap.get(i).get(sz - 2).x == ap.get(i).get(sz - 3).x) out.println("?");
        else out.println(ap.get(i).get(sz - 1).z + " " + ap.get(i).get(sz - 2).z);
      }
    }
  }

  // static Point max(Point a, Point b) {
  //   if (a.x == b.x) {
  //     if (a.y < b.y) return new Point(b.x, b.y);
  //     return new Point(a.x, a.y);
  //   }
  //   if (a.x < b.x) return new Point(b.x, b.y);
  //   return new Point(a.x, a.y);
  // }

  static class Point implements Comparable<Point> {
    public int x;
    public String z;

    Point() {}
    Point(int a, String c) {x = a; z = c;}

    public int compareTo(Point other) {
      if (x == other.x) return z.compareTo(other.z);
      return x - other.x;
    }

    // public int hashCode() {
    //   return 65536 * x + y + 4733 * 0;
    // }
    // public String toString() {
    //   return "(" + x + ", " + y + ")";
    // }
  }
}