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

    long[] a = new long[n];
    for (int i = 0; i < n; i++) a[i] = nl();
    TreeSet<Long> ts = new TreeSet<Long>();
    for (int i = 0; i < n; i++) ts.add(a[i]);

    long mx = 10000000000000L;
    long[] pos = new long[3];
    long[] cpos = new long[3];
    int best = 0;

    for (int i = 0; i < n; i++) {
      long targ = 1;
      while (targ < mx) {
        cpos[0] = a[i];
        if (best < 1) {
          best = 1;
          pos[0] = cpos[0];
        }

        if (ts.contains(a[i] + targ)) {
          cpos[1] = a[i] + targ;
          if (best < 2) {
            best = 2;
            pos[0] = cpos[0];
            pos[1] = cpos[1];
          }

          if (ts.contains(a[i] + 2 * targ)) {
            cpos[2] = a[i] + 2 * targ;

            if (best < 3) {
              best = 3;
              pos[0] = cpos[0];
              pos[1] = cpos[1];
              pos[2] = cpos[2];
            }
          }
        }

        targ *= 2;
      }
    }

    out.println(best);
    for (int i = 0; i < best; i++) out.print(pos[i] + " ");
    out.println();
  }
}