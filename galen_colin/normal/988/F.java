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

    int n = ni() + 1, seg = ni(), umb = ni();

    int[] cost = new int[n];
    long[] dp = new long[n];
    int[] pre = new int[n];
    int[] ev = new int[n];

    for (int i = 0; i < seg; i++) {
      int l = ni(), r = ni();
      ++ev[l];
      --ev[r];
    }

    int run = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += run;
      pre[i] = cnt;
      run += ev[i];
    }

    for (int i = 0; i < umb; i++) {
      int p = ni(), c = ni();
      if (cost[p] == 0) cost[p] = c;
      else cost[p] = Math.min(cost[p], c);
    }

    for (int i = 1; i < n; i++) {
      int mrain = -1;
      if (cost[i] != 0 || i == n - 1) {
        dp[i] = 2000000005;
        for (int j = i - 1; j >= 0; j--) {
          if (pre[j] != pre[i] && mrain == -1) mrain = j + 1;
          if (cost[j] != 0 && dp[j] != 2000000005) {
            long v = dp[j];
            if (mrain != -1) v += cost[j] * (mrain - j);
            dp[i] = Math.min(dp[i], v);
          }
        }
        if (pre[i] == 0) dp[i] = 0;
      }
    }

    if (dp[n - 1] == 2000000005) out.println(-1);
    else out.println(dp[n - 1]);
  }
}