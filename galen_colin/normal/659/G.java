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

  static final long mod = 1000000007;

  public static void main(String[] args) throws Exception {
    reader = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);

    int n = ni();
    long[] a = new long[n];
    for (int i = 0; i < n; i++) a[i] = nl() - 1;
    if (n == 1) {
      out.println(a[0]);
      System.exit(0);
    }

    /* left bool - less/eq to left */
    /* right bool - less/eq to right */
    /* assuming MUST include i */
    long[][][] dp = new long[n][2][2];

    long ans = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        if (a[i] > a[i + 1]) {
          dp[i][1][0] = a[i] - a[i + 1];
          if (dp[i][1][0] < 0) dp[i][1][0] += mod;
        }
        dp[i][1][1] = a[i] - dp[i][1][0];
      } else if (i == n - 1) {
        if (a[i] > a[i - 1]) {
          dp[i][0][0] = a[i] - a[i - 1];
          if (dp[i][0][0] < 0) dp[i][0][0] += mod;
        }
        dp[i][1][0] = (Math.min(a[i], a[i - 1]) * (dp[i - 1][0][1] + dp[i - 1][1][1] + 1)) % mod;
      } else {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) dp[i][0][0] = Math.min(a[i] - a[i - 1], a[i] - a[i + 1]);
        if (a[i] > a[i - 1]) {
          dp[i][0][1] = Math.max(0, Math.min(a[i], a[i + 1]) - a[i - 1]);
        }
        if (a[i] > a[i + 1]) {
          dp[i][1][0] = (Math.max(0, Math.min(a[i], a[i - 1]) - a[i + 1]) * (dp[i - 1][0][1] + dp[i - 1][1][1] + 1)) % mod;
        }
        dp[i][1][1] = (Math.min(Math.min(a[i], a[i - 1]), a[i + 1]) * (dp[i - 1][0][1] + dp[i - 1][1][1] + 1)) % mod;
      }
      ans = (ans + dp[i][0][0] + dp[i][0][1] + dp[i][1][0] + dp[i][1][1]) % mod;

      // out.println(dp[i][0][0] + " " + dp[i][0][1] + " " + dp[i][1][0] + " " + dp[i][1][1]);
    }

    out.println(ans);
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
    public int y;

    Point() {}
    Point(int a, int b) {x = a; y = b;}

    public int compareTo(Point other) {
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