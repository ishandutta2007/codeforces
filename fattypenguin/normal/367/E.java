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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n, m, x;
        n = in.nextInt();
        m = in.nextInt();
        x = in.nextInt();
        if (n > m) {
            out.println("0");
            return;
        }
        long[][] dp = new long[n + 1][n + 1];
        long[][] next = new long[n + 1][n + 1];

        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            ArrayUtils.fill(next, 0);
            for (int j = 0; j <= n; ++j) {
                for (int k = j; k <= n; ++k) {
                    if (dp[j][k] == 0) continue;
                    if (i != x) next[j][k] = (next[j][k] + dp[j][k]) % MOD;
                    if (j > 0) {
                        if (i != x) next[j - 1][k] = (next[j - 1][k] + dp[j][k]) % MOD;
                        if (k + 1 <= n) {
                            next[j][k + 1] = (next[j][k + 1] + dp[j][k]) % MOD;
                        }
                    }
                    if (k < n) {
                        if (j == 0) next[j][k + 1] = (next[j][k + 1] + dp[j][k]) % MOD;
                        next[j + 1][k + 1] = (next[j + 1][k + 1] + dp[j][k]) % MOD;
                    }
                }
            }
            long[][] tmp = dp; dp = next; next = tmp;
        }

        long ans = dp[0][n];
        for (int i = 1; i <= n; ++i) {
            ans = ans * i % MOD;
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

class ArrayUtils {


    public static void fill(long[][] array, long value) {
        for (int i = 0; i < array.length; ++i) {
            Arrays.fill(array[i], value);
        }
    }

    }