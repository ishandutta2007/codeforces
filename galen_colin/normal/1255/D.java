import java.io.*;
import java.util.*;
 
public class Main {
  public static IO in;
  public static PrintWriter out;
  
  public static void main(String[] _u_n_u_s_e_d_) {
    in = new IO();
    out = new PrintWriter(System.out, true);
 
    int Q = in.nint();
    for (int q = 0; q < Q; q++) {
      int r = in.nint(), c = in.nint(), k = in.nint();
 
      int sum = 0;
      boolean[][] grid = new boolean[r][c];
      for (int i = 0; i < r; i++) {
        String s = in.nstr();
        for (int j = 0; j < c; j++) {
          grid[i][j] = (s.charAt(j) == 'R');
          if (grid[i][j]) sum++;
        }
      }
 
      char[] outgrid = new char[c];
 
      int size = sum / k;
      int cnt = sum - k * size;
 
      int run = 0, id = 0;
      for (int i = 0; i < r; i++) {
        int start = c - 1, end = -1, change = -1;
        if (i % 2 == 0) {
            start = 0;
            end = c;
            change = 1;
        }
        
        for (int j = start; j != end; j += change) {
          if (grid[i][j]) run++;
          outgrid[j] = getid(Math.min(id, k - 1));
 
          if (cnt > 0) {
            if (run == size + 1) {
              cnt--;
              run = 0;
              id++;
            }
          } else {
            if (run == size) {
              run = 0;
              id++;
            }
          }
        }
        String s = "";
        for (int j = 0; j < c; j++) {
          s += outgrid[j];
        }
        out.println(s);
      }
    }
  }
 
  static char getid(int id) {
    if (id < 10) return (char)(id + '0');
    else if (id < 36) return (char)(id - 10 + 'A');
    else return (char)(id - 36 + 'a');
  }
 
  static void qsort(long[] arr) {
    Long[] oarr = new Long[arr.length];
    for (int i = 0; i < arr.length; i++) {
      oarr[i] = arr[i];
    }
 
    ArrayList<Long> alist = new ArrayList<Long>(Arrays.asList(oarr));
    Collections.sort(alist);
 
    for (int i = 0; i < arr.length; i++) {
      arr[i] = alist.get(i);
    }
  }
 
  static void reverse(long[] arr) {
    for (int i = 0; i < arr.length / 2; i++) {
      long temp = arr[i];
      arr[i] = arr[arr.length - 1 - i];
      arr[arr.length - 1 - i] = temp;
    }
  }
 
  static String atos(long[] arr) {
    String s = Arrays.toString(arr);
    s = s.substring(1, s.length() - 1);
    return s.replace(",", "");
  }
 
  static class IO {
    public Scanner in;
 
    IO() {
      in = new Scanner(System.in);
    }
 
    int nint() {
      return in.nextInt();
    }
 
    long nlong() {
      return in.nextLong();
    }
 
    double ndouble() {
      return in.nextDouble();
    }
 
    String nstr() {
      return in.next();
    }
    
    long[] nla(int n) {
      long[] arr = new long[n];
      for (int i = 0; i < n; i++) {
        arr[i] = nlong();
      }
      return arr;
    }
  }
}