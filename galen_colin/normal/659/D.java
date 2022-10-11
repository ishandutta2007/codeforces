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

    int n = ni();
    ArrayList<Point> pts = new ArrayList<Point>();
    ArrayList<Point> seg = new ArrayList<Point>();

    for(int i=0; i<=n; i++){
      pts.add(new Point(ni(),ni()));
    }
    for(int i=0; i<n; i++){
      seg.add(new Point(pts.get(i+1).x-pts.get(i).x,pts.get(i+1).y-pts.get(i).y));
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
      int a = seg.get(i).x;
      int b = seg.get(i).y;
      int c = seg.get((i+1)%n).x;
      int d = seg.get((i+1)%n).y;
      if(a*d - b*c >=0){
        cnt ++;
      }
    }
    System.out.println(cnt);


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