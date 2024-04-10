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
  static int MAX = 100000 + 100;
  static ArrayList<ArrayList<Integer>> adj;
 // static ArrayList<Integer> adj[] = new ArrayList[MAX];
  static int[] vis = new int[MAX];
  static int[] vert = new int [MAX];
  static int[] edge = new int[MAX];
  static int[][] edges = new int[MAX][2];
  public static void dfs(int src, int cmp){
    vis[src] = cmp;
    for(int nxt: adj.get(src)){
      if(vis[nxt] != 0) continue;
      dfs(nxt, cmp);
    }
  }
  public static void main(String[] args) throws Exception {
    reader = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);

    int n = ni();
    adj =  new ArrayList<ArrayList<Integer>>();
    for (int i = 0; i < n; i++) adj.add(new ArrayList<Integer>());
    int m = ni();
    int cnt = 1;
    for(int i = 0; i < m; i++){
      int x, y;
      x = ni();
      y = ni();
      x--;
      y--;
      adj.get(x).add(y);
      adj.get(y).add(x);
      edges[i][0] = x;
      edges[i][1] = y;
    }
    for(int i = 0; i<n; i++){
      if(vis[i] == 0){
        dfs(i, cnt);
        cnt++;
      }
    }
    for(int i = 0; i<n; i++){
      vert[vis[i]]++;
    }
    for(int i = 0; i<m; i++){
      int v = edges[i][0];
      edge[vis[v]]++;  
    }
    int ans = 0;
    for(int i = 0; i<= n; i++){
      if(vert[i]>edge[i]) ans++;
    }
    System.out.println(ans);



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

    public int hashCode() {
      return 65536 * x + y + 4733 * 0;
    }
    public String toString() {
      return "(" + x + ", " + y + ")";
    }
  }
}