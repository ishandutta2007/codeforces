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

  public static void main(String[] args) {
    reader = new Scanner(System.in);
    out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);

    int n = ni();

    String[] a = new String[n];
    for (int i = 0; i < n; i++) a[i] = ns();

    int[] pos = new int[n];

    boolean[] done = new boolean[n];
    boolean passed = true;

    int loc = 0;
    while (passed) {
      passed = false;
      for (int i = 0; i < n; i++) {
        if (!done[i]) {
          int vcnt = 0;
          for (int j = 0; j < n; j++) {
            if (i == j || done[j]) {
              ++vcnt;
            } else {
              if (a[i].contains(a[j])) ++vcnt;
            }
          }

          if (vcnt == n) {
            passed = true;
            pos[loc++] = i;
            done[i] = true;
            break;
          }
        }
      }
    }

    if (loc == n) {
      out.println("YES");
      for (int i = 0; i < n; i++) out.println(a[pos[n - i - 1]]);
    } else out.println("NO");
  }
}