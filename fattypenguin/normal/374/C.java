import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    private static final char[] PATTERN = "DIMA".toCharArray();
    private int[] dx = new int[]{-1, 1, 0, 0};
    private int[] dy = new int[]{0, 0, -1, 1};

    private Integer[][] dp;
    private char[][] board;
    private Integer go(int i, int j, int k) {
        Integer current = dp[i][j];
        if (current != null) {
            return current < 0 ? null : current;
        }

        dp[i][j] = -1;
        int answer = 1;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if (nx >= 0 && nx < dp.length && ny >= 0 && ny < dp[0].length) {
                if (board[nx][ny] == PATTERN[(k + 1) & 3]) {
                    Integer next = go(nx, ny, (k + 1) & 3);
                    if (next == null) return null;
                    answer = Math.max(answer, next + 1);
                }
            }
        }
        return dp[i][j] = answer;
    }
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        board = new char[n][];
        for (int i = 0; i < n; ++i) {
            board[i] = in.next().toCharArray();
        }

        dp = new Integer[n][m];
        Integer res = 0;
        outer: for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'D') {
                    Integer current = go(i, j, 0);
                    if (current == null) {
                        res = null;
                        break outer;
                    }
                    if (current > res) {
                        res = current;
                    }
                }
            }
        }

        if (res == null) {
            out.println("Poor Inna!");
        } else if (res < 4) {
            out.println("Poor Dima!");
        } else out.println(res / 4);
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