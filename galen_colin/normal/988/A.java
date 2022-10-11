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

    int n = ni(), k = ni();

    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = ni();
    }

    boolean[] seen = new boolean[105];

    int[] inds = new int[n];

    int c = 0;
    for (int i = 0; i < n; i++) {
      if (!seen[a[i]]) {
        inds[c] = i + 1;
        c++;
        seen[a[i]] = true;
      }
    }

    if (c >= k) {
      out.println("YES");
      for (int i = 0; i < k; i++) out.print(inds[i] + " ");
      out.println();
    } else out.println("NO");
  }
}