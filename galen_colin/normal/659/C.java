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
    int k = ni();
    Integer[] a = new Integer[n];
    ArrayList<Integer> arr = new ArrayList<>() ;
      for(int i = 0; i < n; i++){
        a[i] = ni();
    }
    int ind = 0, i = 1;
    Arrays.sort(a);
    while(k>=0){
        if(ind>n)
        break;
        if(ind == n || a[ind] != i ){
            if(k-i >= 0){
                arr.add(i);
                k-=i;
                i++;
            }else{
                ind++;
                i++;
            }
        }else{
            ind++;
            i++;
        }
    }
    System.out.println(arr.size());
    for(int ii : arr){
        System.out.print(ii + " ");
    }
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