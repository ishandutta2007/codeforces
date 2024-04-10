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

    int n = ni(), m = ni();
    int[][] mat = new int[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      mat[i][j] = ni();
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
      TreeMap<Integer, Integer> tm = new TreeMap<Integer, Integer>();

      int mn = n;
      for (int j = 0; j < n; j++) {
        int v = mat[j][i];

        v -= (i + 1);
        if (v % m == 0) {
          int pos = v / m;

          int mov = j - pos;
          if (mov < 0) mov += n;

          if (pos < n && mov < n && mov >= 0) {
            int v2 = 0;
            if (tm.containsKey(mov)) v2 = tm.get(mov);
            tm.put(mov, ++v2);
            mn = Math.min(mn, mov + n - v2);
          }
        }
      }

      ans += mn;
    }

    out.println(ans);
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