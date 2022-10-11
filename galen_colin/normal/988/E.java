import java.io.*;
import java.util.*;

public class Main {
  static Scanner reader;
  static PrintWriter out;

  static int ni() {
    return reader.nextInt();
  }

  static long nl() {
    return reader.nextLong();
  }

  static double nd() {
    return reader.nextDouble();
  }

  static String ns() {
    return reader.next();
  }

  static boolean valid(String s) {
    return s.equals("25") || s.equals("50") || s.equals("75") || s.equals("00");
  }

  public static void main(String[] args) {
    reader = new Scanner(System.in);
    out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);

    String s = ns();
    if (s.length() == 1) {
      out.println(-1);
      System.exit(0);
    }
    if (valid(s.substring(s.length() - 2))) {
      out.println(0);
      System.exit(0);
    }

    int n = s.length();

    char[] c = new char[n];
    for (int i = 0; i < n; i++) {
      c[i] = s.charAt(n - i - 1);
    }

    int ans = 1000000;
    int cnt = 0, run = 0;
    for (int i = 0; i < s.length(); i++) {
      if (c[i] == '0') {
        cnt++;
        run += i;
        if (cnt == 2) {
          ans = run - 1;
          break;
        }
      }
    }

    cnt = 0; run = 0;
    int p0 = -1, w0 = -1, p5 = -1, po = -1;
    for (int i = 0; i < s.length(); i++) {
      if (c[i] == '0') {
        w0 = i;
        if (p0 == -1) p0 = i;
      } else if (c[i] == '5') {
        if (p5 == -1) p5 = i;
        else po = i;
      } else po = i;
    }

    int targ = 1000000;
    if (p0 != -1 && p5 != -1) {
      if (w0 == n - 2 && p5 == n - 1) {
        if (po != -1) {
          targ = (n - po - 2) + p5 - 1 + p0;
          if (p0 == w0) --targ;
        }
      } else {
        targ = p5 - 1 + p0;
      }
    }
    if (p5 < p0) ++targ;
    ans = Math.min(ans, targ);

    int p2 = -1;
    w0 = -1; p5 = -1; po = -1;
    for (int i = 0; i < s.length(); i++) {
      if (c[i] == '0') {
        w0 = i;
      } else if (c[i] == '5') {
        if (p5 == -1) p5 = i;
        else po = i;
      } else if (c[i] == '2') {
        if (p2 == -1) p2 = i;
        else po = i;
      } else po = i;
    }

    targ = 1000000;
    if (p2 != -1 && p5 != -1) {
      if (w0 != -1 && w0 == n - 2 && ((p5 == n - 1) || (p2 == n - 1))) {
        if (po != -1) {
          targ = (n - po - 1) + p2 - 1 + p5;
          if (po < p2) --targ;
          if (po < p5) --targ;
        }
      } else if (w0 != -1 && w0 == n - 3 && p5 > w0 && p2 > w0) {
        if (po != -1) {
          targ = (n - po - 1) + p2 - 1 + p5;
          if (po < p2) --targ;
          if (po < p5) --targ;
        }
      } else {
        targ = p2 - 1 + p5;
      }
    }
    if (p2 < p5) ++targ;
    ans = Math.min(ans, targ);

    p2 = -1;
    w0 = -1; p5 = -1; po = -1;
    for (int i = 0; i < s.length(); i++) {
      if (c[i] == '0') {
        w0 = i;
      } else if (c[i] == '5') {
        if (p5 == -1) p5 = i;
        else po = i;
      } else if (c[i] == '7') {
        if (p2 == -1) p2 = i;
        else po = i;
      } else po = i;
    }

    targ = 1000000;
    if (p2 != -1 && p5 != -1) {
      if (w0 != -1 && w0 == n - 2 && ((p5 == n - 1) || (p2 == n - 1))) {
        if (po != -1) {
          targ = (n - po - 1) + p2 - 1 + p5;
          if (po < p2) --targ;
          if (po < p5) --targ;
        }
      } else if (w0 != -1 && w0 == n - 3 && p5 > w0 && p2 > w0) {
        if (po != -1) {
          targ = (n - po - 1) + p2 - 1 + p5;
          if (po < p2) --targ;
          if (po < p5) --targ;
        }
      } else {
        targ = p2 - 1 + p5;
      }
    }
    if (p2 < p5) ++targ;
    ans = Math.min(ans, targ);

    if (ans == 1000000) out.println(-1);
    else out.println(ans);
  }
}