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
  static int[] flat;
  static boolean[] in;
  static boolean[] on;

  static int vis = 0;
  static long cap;
  static int n, m;
  static void dfs(int x) {
    if (!in[x] || on[x]) return;
    if (vis++ >= cap) return;
    on[x] = true;

    int i=x/m;
    int j=x%m;
    if (i > 0) dfs(x - m);
    if (i < n - 1) dfs(x + m);
    if (j > 0) dfs(x - 1);
    if (j < m - 1) dfs(x + 1);
  }

  public static void main(String[] args) throws Exception {
    reader = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);

    long k;
    n = ni();
    m = ni();
    k = nl();
    flat = new int[n*m];
    in = new boolean[n*m];
    on = new boolean[n * m];
    ArrayList<Point> pts = new ArrayList<Point>();
    for(int i=0; i<n*m; i++){
      flat[i] = ni();
      pts.add(new Point(flat[i],i));
      in[i] = false;
      on[i] = false;
    }

    Collections.sort(pts);
    DSU d = new DSU(n*m);
    for(Point p: pts){
      in[p.y] = true;
      int i=p.y/m;
      int j=p.y%m;
      if(i>0 && in[p.y-m]){
        d.merge(p.y,p.y-m);
      }
      if(i<n-1 && in[p.y+m]){
        d.merge(p.y,p.y+m);
      }
      if(j>0 && in[p.y-1]){
        d.merge(p.y,p.y-1);
      }
      if(j<m-1 && in[p.y+1]){
        d.merge(p.y,p.y+1);
      }
      if(k%p.x == 0 && k/p.x <= d.size[d.root(p.y)]){
        out.println("YES");
        int root = -1;
        cap = k / p.x;
        dfs(p.y);
        for (int b = 0; b < n; b++) {
          for (int c = 0; c < m; c++) {
            if (on[b * m + c]) out.print(p.x);
            else out.print(0);
            out.print(" ");
          }
          out.println();
        }
        return;
        
      }
    }
    out.println("NO");


    
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