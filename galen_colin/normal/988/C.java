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

    int k = ni();

    TreeMap<Long, Long> mp = new TreeMap<Long, Long>();

    int[] a = new int[200005];
    long big = 1000000000;
    for (int i = 0; i < k; i++) {
      long sum = 0;
      int n = ni();
      for (int j = 0; j < n; j++) {
        a[j] = ni();
        sum += a[j];
      }

      for (int j = 0; j < n; j++) {
        long s2 = sum - a[j];
        if (mp.containsKey(s2)) {
          long l = mp.get(s2);
          long seq = l / big;
          long pos = l % big;
          out.println("YES");
          out.println((seq + 1) + " " + (pos + 1));
          out.println((i + 1) + " " + (j + 1));
          System.exit(0);
        }
      }

      for (int j = 0; j < n; j++) {
        long s2 = sum - a[j];
        if (!mp.containsKey(s2)) {
          mp.put(s2, i * big + j);
        }
      }
    }

    out.println("NO");
  }
}