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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    private int[] dx = new int[]{-1, 1, 0, 0};
    private int[] dy = new int[]{0, 0, -1, 1};
    private char[][] maze;
    private boolean[][] used;
    private int n, m, count;
    boolean isGood(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        int s = in.nextInt();
        maze = new char[n][];
        for (int i = 0; i < n; ++i) {
            maze[i] = in.next().toCharArray();
        }
        count = 0;
        used = new boolean[n][m];
        int numNonEmpty = 0;
        outer: for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (maze[i][j] != '#') {
                    ++numNonEmpty;
                }
            }
        }
        target = numNonEmpty - s;
        outer: for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (maze[i][j] != '#') {
                    go(i, j);
                    break outer;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!used[i][j] && maze[i][j] == '.') {
                    maze[i][j] = 'X';
                }
            }
            out.println(new String(maze[i]));
        }
    }

    private int target;

    private void go(int i, int j) {
        if (target <= 0) return;
        used[i][j] = true;
        --target;
        for (int d = 0; d < 4; ++d) {
            int nx = i + dx[d];
            int ny = j + dy[d];
            if (isGood(nx, ny) && maze[nx][ny] != '#' && !used[nx][ny]) {
                go(nx, ny);
            }
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