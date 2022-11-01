import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author sheep
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    private static final int MOD = 1000000007;
    private static final long[][] choose;
    static {
        choose = new long[55][55];
        for (int i = 0; i <= 51; ++i) {
            choose[i][0] = choose[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % MOD;
            }
        }
    }
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt(), k = in.nextInt();

        if (k > n) {
            out.println(0);
            return;
        }

        int[][][] dp = new int[n + 1][2][n + 1];
        dp[1][0][0] = 1;
        dp[0][1][0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int match = 0; match <= i; ++match) {
                    for (int left = 0; left < 2; ++left) {
                        for (int right = 0; right < 2; ++right) {
                            if ((left == 0 || right == 0) && j == 0) continue;
                            if (left == 1 && right == 1 && j == 1) continue;
                            int rem = match - j;
                            if (rem < 0) continue;
                            for (int leftSize = 0; leftSize < i; ++leftSize) {
                                for (int leftMatch = 0; leftMatch <= leftSize && leftMatch <= rem; ++leftMatch) {
                                    int rightSize = i - 1 - leftSize;
                                    int rightMatch = rem - leftMatch;
                                    if (rightMatch > rightSize) continue;
                                    if (leftSize < rightSize || leftSize == rightSize && leftMatch < rightMatch) {
                                        dp[i][j][match] = (int) ((dp[i][j][match] + dp[leftSize][left][leftMatch]
                                                * (long) dp[rightSize][right][rightMatch] % MOD * (i == n ? 1 : i) % MOD * choose[i - 1][leftSize] % MOD) % MOD);
                                    } else if (leftSize == rightSize && leftMatch == rightMatch) {
                                        dp[i][j][match] = (int) ((dp[i][j][match] + dp[leftSize][left][leftMatch]
                                                * (long) (dp[rightSize][right][rightMatch] - 1) % MOD * NumberUtils.powMod(2, MOD - 2, MOD) % MOD * (i == n ? 1 : i) % MOD * choose[i - 1][leftSize] % MOD) % MOD);
                                        dp[i][j][match] = (int) ((dp[i][j][match] + dp[leftSize][left][leftMatch] * (long) (i == n ? 1 : i) % MOD * choose[i - 1][leftSize] % MOD * NumberUtils.powMod(2, MOD - 2, MOD) % MOD) % MOD);
                                    }
//                                    if (i == 3 && j == 1 && match == 1) {
//                                        out.println("left = " + left + " right = " + right + " ls = " + leftSize + " lm = " + leftMatch + " rs = " + rightSize + " rm = " + rightMatch + " i = " + i + " j = " + j + " match = " + match + " res = " + dp[i][j][match]);
//                                    }
                                 }
                            }
                        }
                    }
//                    out.println("i = " + i + " j = " + j + " match = " + match + " res = " + dp[i][j][match]);
                }
            }
        }

        out.println((((dp[n][0][k] + dp[n][1][k]) % MOD) + MOD) % MOD);
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }

class NumberUtils {

    public static long powMod(long x, long y, long mod) {
        long res = 1;
        for (; y != 0; y >>= 1L) {
            if (y % 2 == 1) res = res * x % mod;
            x = x * x % mod;
        }
        return res;
    }

    }