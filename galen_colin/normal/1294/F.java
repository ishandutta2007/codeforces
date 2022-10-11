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

  static ArrayList<ArrayList<Integer>> edges;
  static ArrayList<ArrayList<Point>> child;
  static ArrayList<ArrayList<Point>> uschild;
  static int[] res;
  static int ans;

  public static void main(String[] args) throws Exception {
    reader = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);

    int n = ni();
    edges = new ArrayList<ArrayList<Integer>>();
    child = new ArrayList<ArrayList<Point>>();
    uschild = new ArrayList<ArrayList<Point>>();
    res = new int[3];
    ans = 0;
    for (int i = 0; i < n; i++) {
      edges.add(new ArrayList<Integer>());
      child.add(new ArrayList<Point>());
      uschild.add(new ArrayList<Point>());
    }

    for (int i = 0; i < n - 1; i++) {
      int a = ni(), b = ni();
      --a; --b;
      edges.get(a).add(b);
      edges.get(b).add(a);
    }

    gdown(0, -1);
    gup(0, -1, new Point(0, 0));

    out.println(ans);
    for (int i = 0; i < 3; i++) out.print(res[i] + 1 + " ");
    out.println();
  }

  static void gup(int v, int par, Point pass) {
    int sz = child.get(v).size();
    Point[] pmax = new Point[sz];
    Point[] smax = new Point[sz];

    Point best = new Point(0, 0);
    for (int i = 0; i < sz; i++) {
      best = max(best, uschild.get(v).get(i));
      pmax[i] = best;
    }
    best = new Point(0, 0);
    for (int i = sz - 1; i >= 0; i--) {
      best = max(best, uschild.get(v).get(i));
      smax[i] = best;
    }

    // out.println(v + " " + pass);
    // for (Point x: child.get(v)) out.print(x + " ");
    // out.println();

    if (v != 0) {
      if (sz == 1) {
        int a = child.get(v).get(0).x + pass.x;
        if (a > ans) {
          ans = a;
          res[0] = v;
          res[1] = pass.y;
          res[2] = child.get(v).get(0).y;
        }
      } else if (sz > 1) {
        int a = child.get(v).get(sz - 1).x + child.get(v).get(sz - 2).x + pass.x;
        if (a > ans) {
          ans = a;
          res[0] = child.get(v).get(sz - 2).y;
          res[1] = pass.y;
          res[2] = child.get(v).get(sz - 1).y;
        }

        if (sz > 2) {
          a = child.get(v).get(sz - 1).x + child.get(v).get(sz - 2).x + child.get(v).get(sz - 3).x;
          if (a > ans) {
            ans = a;
            res[0] = child.get(v).get(sz - 2).y;
            res[1] = child.get(v).get(sz - 3).y;
            res[2] = child.get(v).get(sz - 1).y;
          }
        }
      }
    } else {
      if (sz == 2) {
        int a = child.get(v).get(sz - 1).x + child.get(v).get(sz - 2).x;
        if (a > ans) {
          ans = a;
          res[0] = child.get(v).get(sz - 2).y;
          res[1] = v;
          res[2] = child.get(v).get(sz - 1).y;
        }
      } else if (sz > 2) {
        int a = child.get(v).get(sz - 1).x + child.get(v).get(sz - 2).x + child.get(v).get(sz - 3).x;
        if (a > ans) {
          ans = a;
          res[0] = child.get(v).get(sz - 2).y;
          res[1] = child.get(v).get(sz - 3).y;
          res[2] = child.get(v).get(sz - 1).y;
        }
      }
    }

    int c = 0;
    for (int i = 0; i < edges.get(v).size(); i++) {
      if (edges.get(v).get(i) != par) {
        Point b = new Point(pass.x, pass.y);
        if (c > 0) b = max(b, pmax[c - 1]);
        if (c < sz - 1) b = max(b, smax[c + 1]);
        gup(edges.get(v).get(i), v, new Point(b.x + 1, b.y));
        ++c;
      }
    }
  }

  static Point gdown(int v, int par) {
    Point best = new Point(0, v);
    for (int i = 0; i < edges.get(v).size(); i++) {
      if (edges.get(v).get(i) != par) {
        int x = edges.get(v).get(i);
        Point nx = gdown(x, v);
        child.get(v).add(nx);
        best = max(best, nx);
      }
    }

    for (Point x: child.get(v)) uschild.get(v).add(x);

    Collections.sort(child.get(v));

    // out.println(v);
    // for (Point x: child.get(v)) out.print(x + " ");
    // out.println();

    ++best.x;
    return best;
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