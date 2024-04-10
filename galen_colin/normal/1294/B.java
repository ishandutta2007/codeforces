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

      Point[] pp = new Point[n];

      for (int i = 0; i < n; i++) {
        pp[i] = new Point(ni(), ni());
      }

      Arrays.sort(pp);

      String s = "";
      boolean pos = true;
      int cx = 0, cy = 0;
      for (int i = 0; i < n; i++) {
        int nx = pp[i].x, ny = pp[i].y;
        if (nx < cx || ny < cy) {
          pos = false;
          break;
        }
        for (int j = 0; j < nx - cx; j++) s += "R";
        for (int j = 0; j < ny - cy; j++) s += "U";
        cx = nx;
        cy = ny;
      }

      if (pos) {
        out.println("YES");
        out.println(s);
      } else out.println("NO");
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