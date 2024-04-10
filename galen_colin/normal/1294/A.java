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
      int a = ni(), b = ni(), c = ni(), n = ni();

      int d = (a + b + c + n);
      boolean pos = true;
      if (d % 3 != 0) pos = false;
      d /= 3;
      if (a > d) pos = false;
      if (b > d) pos = false;
      if (c > d) pos = false;

      out.println(pos?"YES":"NO");
    }
  }
}