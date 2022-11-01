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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    private static int MAX_VALUE = 0x3F3F3F3F;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt(), k = in.nextInt();
        int[] pr = new int[n];
        for (int i = 0; i < n; ++i) {
            pr[i] = in.nextInt();
        }

        boolean[][] any = new boolean[n][n];
        boolean[][] must = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (i != j) {
                    any[i][j] = any[i][j - 1];
                    must[i][j] = must[i][j - 1];
                }
                if (pr[j] != 0) any[i][j] = true;
                if (pr[j] == 100) must[i][j] = true;
            }
        }

        int[][] dp = new int[n + 1][n + 1];
        ArrayUtils.fill(dp, MAX_VALUE);

        if (n == 1) {
            dp[0][0] = 0;
        } else {
            dp[0][1] = 0;
        }
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (dp[i][j] == MAX_VALUE) continue;
                int first = i;
                int second = j;
                if (any[second][n - 1] && any[first][first]) {
                    if (second + 1 == n) {
                        dp[n][n] = Math.min(dp[n][n], dp[i][j] + 1);
                    } else if (second + 1 == n - 1) {
                        dp[n - 1][n - 1] = Math.min(dp[n - 1][n - 1], dp[i][j] + 1);
                    } else {
                        dp[second + 1][second + 2] = Math.min(dp[second + 1][second + 2], dp[i][j] + 1);
                    }
                }

                if (!must[second][n - 1] && any[first][first]) {
                    if (second + 1 == n) {
                        dp[first][first] = Math.min(dp[first][first], dp[i][j] + 1);
                    } else {
                        dp[first][second + 1] = Math.min(dp[first][second + 1], dp[i][j] + 1);
                    }
                }

                if (!must[first][first] && any[second][n - 1]) {
                    if (second + 1 == n) {
                        dp[n - 1][n - 1] = Math.min(dp[n - 1][n - 1], dp[i][j] + 1);
                    } else {
                        dp[second][second + 1] = Math.min(dp[second][second + 1], dp[i][j] + 1);
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                if (dp[i][j] <= k) {
                    ++ans;
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

class ArrayUtils {


    public static void fill(int[][] array, int value) {
        for (int i = 0; i < array.length; ++i) {
            Arrays.fill(array[i], value);
        }
    }

    }