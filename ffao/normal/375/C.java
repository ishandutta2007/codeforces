import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Parser in = new Parser(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    int[] objx = new int[8];
    int[] objy = new int[8];
    int[] value = new int[8];
    int[] v = new int[10];

    String[] board;
    int[][][] seen;
    int n, m;
    int objects;
    int sx, sy;

    int queue[] = new int[103000];
    int ini, fim;

    int calc(int bm) {
        int tot = 0;
        for (int i = 0; i < objects; i++) {
            if ((bm & (1<<i)) != 0) tot += v[value[i]];
        }
        return tot;
    }

    int process(int x, int y, int nx, int ny) {
        int bm = 0;
        if (ny == y) return bm;
        else y = Math.max(ny, y);

        for (int i = 0; i < objects; i++) {
            if (objx[i] == 0 || objx[i] == n-1 || objy[i] == 0 || objy[i] == m-1) continue;
            if (nx > objx[i] && y == objy[i]+1) bm ^= (1<<i);
        }

        return bm;
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        board = new String[n];
        objects = 0;

        int t = 0;

        for (int i = 0; i < n; i++) {
            board[i] = in.next();

            for (int j = 0; j < m; j++) {
                if (board[i].charAt(j) == 'S') {
                    sx = i; sy = j;
                }

                else if (board[i].charAt(j) == 'B' || (board[i].charAt(j) >= '1' && board[i].charAt(j) <= '9')) {
                    objx[objects] = i;
                    objy[objects] = j;
                    if (board[i].charAt(j) == 'B') value[objects] = 0;
                    else {
                        value[objects] = board[i].charAt(j) - '0';
                        t = Math.max(t, board[i].charAt(j) - '0');
                    }
                    objects++;
                }
            }
        }

        v[0] = -10000;
        for (int i = 1; i <= t; i++) {
            v[i] = in.nextInt();
        }

        seen = new int[n][m][1<<objects];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Arrays.fill(seen[i][j], -1);
            }
        }

        int h1 = m * (1<<objects);
        int h2 = (1<<objects);

        int ans = 0;
        seen[sx][sy][0] = 0;
        queue[fim++] = sx * h1 + sy * h2;

        while (ini != fim) {
            int x = queue[ini] / h1;
            int y = (queue[ini] / h2) % m;
            int bm = (queue[ini]) % (1<<objects);

            ini++;

            if (x == sx && y == sy) ans = Math.max(ans, calc(bm) - seen[x][y][bm]);

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx * dy != 0) continue;
                    if (dx + dy == 0) continue;

                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (board[nx].charAt(ny) == 'B' || board[nx].charAt(ny) == '#' || (board[nx].charAt(ny) >= '1' && board[nx].charAt(ny) <= '9')) continue;

                    int nbm = bm ^ process(x,y,nx,ny);
                    if (seen[nx][ny][nbm] == -1) {
                        queue[fim++] = nx * h1 + ny * h2 + nbm;
                        seen[nx][ny][nbm] = seen[x][y][bm] + 1;
                    }
                }
            }
        }

        out.println(ans);
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