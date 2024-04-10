import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    PrintWriter out;
    Scanner in;
    int p, alpha;
    BigInteger A;
    int[][][] dp, ndp;
    final int MOD = (int) (1e9 + 7);

    int add(int a, int b) {
        return (a + b) > MOD ? a + b - MOD : a + b;
    }

    public void run() {
        try {
            in = new Scanner(System.in);
            out = new PrintWriter(System.out);
        } catch(Exception e) {

        }
        p = in.nextInt();
        alpha = in.nextInt();
        A = in.nextBigInteger();
        dp = new int[2][2][5000];
        dp[0][0][0] = 1;
        ndp = new int[2][2][5000];
        int all = 0;
        while (A.compareTo(BigInteger.ZERO) > 0) {
            int cur = A.mod(BigInteger.valueOf(p)).intValue();
            int[][] cnt = new int[3][3];
            cnt[0][0] = (int) (((long) (cur) * (long) (cur -  1) / 2) % MOD);
            cnt[0][1] = (int) (((long) (p - 1 + p - cur) * (long) (cur) / 2) % MOD);
            cnt[1][0] = (int) (((long) (cur + 1 + p - 1) * (long) (p - 1 - cur) / 2) % MOD);
            cnt[1][1] = (int) (((long) (p - 1 - cur) * (long) (p - 1 - cur - 1) / 2) % MOD);
            cnt[2][0] = cur;
            cnt[2][1] = p - 1 - cur;
            cnt[2][2] = 1;
            cnt[0][2] = cur;
            cnt[1][2] = p - 1 - cur;
            for (int i1 = 0; i1 < 2; i1++) {
                for (int i2 = 0; i2 < 2; i2++) {
                    for (int r = 0; r <= all + 1; r++) {
                        ndp[i1][i2][r] = 0;
                    }
                }
            }
            for (int i1 = 0; i1 < 2; i1++) {
                for (int i2 = 0; i2 < 2; i2++) {
                    for (int j1 = 0; j1 < 2; j1++) {
                        for (int j2 = 0; j2 < 2; j2++) {
                            for (int r = 0; r <= all; r++) {
                                ndp[i1][i2][r + i2] = add(ndp[i1][i2][r + i2],
                                        (int) ((long) dp[j1][j2][r] * (long) cnt[i1][i2] % MOD));
                                if (i1 == j1) {
                                    ndp[i1][i2][r + i2] = add(ndp[i1][i2][r + i2],
                                            (int) ((long) dp[j1][j2][r] * (long) cnt[2][i2] % MOD));
                                }
                                if (i2 == j2) {
                                    ndp[i1][i2][r + i2] = add(ndp[i1][i2][r + i2],
                                            (int) ((long) dp[j1][j2][r] * (long) cnt[i1][2] % MOD));
                                }
                                if (i1 == j1 && i2 == j2) {
                                    ndp[i1][i2][r + i2] = add(ndp[i1][i2][r + i2],
                                            (int) ((long) dp[j1][j2][r] * (long) cnt[2][2] % MOD));
                                }
                            }
                        }
                    }
                }
            }
            int[][][] tmp = dp;
            dp = ndp;
            ndp = tmp;
            A = A.divide(BigInteger.valueOf(p));
            all++;
        }

        int ans = 0;
        for (int i = alpha; i <= all + 1; i++) {
            ans = (ans + dp[0][0][i]) % MOD;
        }
        out.println(ans);

        out.close();
        in.close();
    }

    public static void main(String[] args) {
        Main app = new Main();
        app.run();
    }
}