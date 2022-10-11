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
    int[] mx = new int[n];
    int[] cnt = new int[n];
    int gmx = 0;
    long ans = 0;
    for (int i = 0; i < n; i++) {
      int m = ni();
      for (int j = 0; j < m; j++) {
        int x = ni();
        mx[i] = Math.max(mx[i], x);
        ++cnt[i];
        gmx = Math.max(gmx, mx[i]);
      }
    }
    
    for (int i = 0; i < n; i++) {
      ans += (gmx - mx[i]) * (long)cnt[i];
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
      return other.x - x;
    }

    // public int hashCode() {
    //   return 65536 * x + y + 4733 * 0;
    // }
    // public String toString() {
    //   return "(" + x + ", " + y + ")";
    // }
  }

  static class DSU{
    public int[] parent, size;
    public int maxsize = 1;
    public DSU(int n){
      parent = new int[n];
      size = new int[n];
      for(int i=0; i<n; i++){
        parent[i] = i;
        size[i] = 1;
      }
    }
    public void merge(int x, int y){
      int rx = root(x);
      int ry = root(y);
      if(rx != ry){
        if(size[rx] > size[ry]){
          int temp = rx;
          rx = ry;
          ry = temp;
        }
        parent[rx] = ry;
        size[ry] += size[rx];
        maxsize = Math.max(maxsize,size[ry]);
      }

    }
    public int root(int x){
      while(parent[x] != x){
        int p = parent[x];
        parent[x] = parent[p];
        x = p;
      }
      return x;
    }
  }
}