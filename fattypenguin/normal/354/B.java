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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    private static int MAX_VALUE = 0x3F3F3F3F;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[][] value = new int[n][n];
        int[][] map = new int[n][n];
        for (int i = 0; i < n; ++i) {
            char[] line = in.next().toCharArray();
            for (int j = 0; j < n; ++j) {
                map[i][j] = line[j] - 'a';
                if (line[j] == 'a') {
                    value[i][j] = 1;
                } else if (line[j] == 'b') {
                    value[i][j] = -1;
                }
            }
        }
        int[] dp = new int[1 << n];
        Arrays.fill(dp, -MAX_VALUE);
        dp[(1 << (n - 1))] = 0;
        for (int iter = 2 * n - 3; iter >= 0; --iter) {
            int[] next = new int[1 << n];
            boolean isFirstUser = iter % 2 == 1;
            if (isFirstUser) {
                Arrays.fill(next, -MAX_VALUE);
            } else {
                Arrays.fill(next, MAX_VALUE);
            }
            int begin = 0;
            while (iter - begin >= n) ++begin;
            int end = n - 1;
            while (iter - end < 0) --end;
            int fullMask = 0;
            for (int i = begin; i <= end; ++i) {
                fullMask |= 1 << i;
            }
            int[] newMasks = new int[26];
            for (int mask = fullMask; mask != 0; mask = (mask - 1) & fullMask) {
                Arrays.fill(newMasks, 0);
                for (int i = begin; i <= end; ++i) {
                    if (((mask >> i) & 1) != 0) {
                        int j = iter - i;
                        if (i + 1 < n) newMasks[map[i + 1][j]] |= 1 << (i + 1);
                        if (j + 1 < n) newMasks[map[i][j + 1]] |= 1 << i;
                    }
                }
                for (int i = 0; i < 26; ++i) {
                    int cost = i == 0 ? 1 : (i == 1 ? -1 : 0);
                    if (newMasks[i] > 0) {
                        if (isFirstUser) {
                            next[mask] = Math.max(next[mask], dp[newMasks[i]] + cost);
                        } else {
                            next[mask] = Math.min(next[mask], dp[newMasks[i]] + cost);
                        }
                    }
                }
            }
            dp = next;
        }
        int result = dp[1] + value[0][0];
        if (result == 0) {
            out.println("DRAW");
        } else if (result > 0) {
            out.println("FIRST");
        } else {
            out.println("SECOND");
        }
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