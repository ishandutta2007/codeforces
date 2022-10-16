import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.ArrayDeque;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.Collection;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ffao
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Parser in = new Parser(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    int maxx, maxy;
    String[] board;
    int[][] dist;
    boolean[][] seen;

    int[] dx = {0, 0, 1, -1};
    int[] dy = {1, -1, 0, 0};

    int hash(int a, int b) {
        return a*maxy + b;
    }

    void bfs(int x, int y) {
        dist[x][y] = 0;
        Queue<Integer> q = new ArrayDeque<Integer>();
        q.add(hash(x, y));

        while (!q.isEmpty()) {
            int el = q.remove();
            int cx = el/maxy;
            int cy = el%maxy;

            for (int i = 0; i < 4; i++) {
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if (nx < 0 || nx >= maxx || ny < 0 || ny >= maxy) continue;
                if (seen[nx][ny] || board[nx].charAt(ny) == 'T') continue;

                dist[nx][ny] = dist[cx][cy]+1;
                seen[nx][ny] = true;
                q.add(hash(nx,ny));
            }
        }
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        maxx = in.nextInt();
        maxy = in.nextInt();
        board = new String[maxx];
        dist = new int[maxx][maxy];
        seen = new boolean[maxx][maxy];

        for (int i = 0; i < maxx; i++) {
            board[i] = in.next();
        }

        for (int i = 0; i < maxx; i++) {
            for (int j = 0; j < maxy; j++) {
                if (board[i].charAt(j) == 'E') {
                    bfs(i, j);
                    break;
                }
            }
        }

        int targ = 0;
        for (int i = 0; i < maxx; i++) {
            for (int j = 0; j < maxy; j++) {
                if (board[i].charAt(j) == 'S') {
                    targ = dist[i][j];
                    break;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < maxx; i++) {
            for (int j = 0; j < maxy; j++) {
                char c = board[i].charAt(j);
                if (c >= '0' && c <= '9') {
                    if (seen[i][j] && dist[i][j] <= targ) {
                        cnt += c - '0';
                    }
                }
            }
        }

        out.println(cnt);
    }
}

class Parser
{
    private BufferedReader din;
    private StringTokenizer tokenizer;

    public Parser(InputStream in)
    {
        din = new BufferedReader(new InputStreamReader(in));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(din.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt()
    {
        return Integer.parseInt(next());
    }

    }

class OutputWriter extends PrintWriter {
    public OutputWriter(Writer out) {
        super(out);
    }

    public OutputWriter(OutputStream out) {
        super(out);
    }

    }