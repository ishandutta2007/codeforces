import java.io.InputStreamReader;
import java.io.IOException;
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

    final int MOD = 1000000007;

    private int addMod(int x, int y) {
        int ret = x + y;
        if (ret < 0) ret += MOD;
        if (ret >= MOD) ret -= MOD;

        return ret;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int choose[][] = new int[200][200];
        for (int i = 0; i < choose.length; ++i) {
            choose[i][0] = choose[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
            }
        }

        int n = in.nextInt();
        int m = in.nextInt();
        int upper = in.nextInt();

        int dp[][][][] = new int[2][n + 1][upper + 1][upper + 1];
        for (int i = 1; i + i <= n; ++i) {
            dp[0][2 * i][1][i] = 1;
        }

        int ans = 0;

        for (int i = 0; i < m - 1; ++i) {
            int now = i & 1, next = now ^ 1;

            for (int j = 0; j <= n; ++j) {
                for (int k = 1; k <= upper; ++k) {
                    for (int r = 1; r <= upper; ++r) {
                        dp[next][j][k][r] = 0;
                    }
                }
            }

            for (int j = 1; j * 2 <= n; ++j) {
                dp[next][2 * j][1][j] = 1;
            }

            for (int j = 0; j <= n; ++j) {
                for (int k = 1; k <= upper; ++k) {
                    for (int r = 1; r <= upper; ++r) {
                        if (0 == dp[now][j][k][r]) continue;
                        if (j > 1) {
                            ans = addMod(ans, dp[now][j][k][r]);
                        }
                        for (int delta = 1; j + 2 * delta <= n && delta <= upper; ++delta) {
                            int nextPlan = k * choose[delta + r - 1][r - 1];
                            if (nextPlan > upper) break;
                            dp[next][j + 2 * delta][nextPlan][delta] = addMod(dp[next][j + 2 * delta][nextPlan][delta], dp[now][j][k][r]);
                        }
                    }
                }
            }
        }

        out.println(ans);
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