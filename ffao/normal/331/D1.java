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
 * @author ffao
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Parser in = new Parser(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD1 solver = new TaskD1();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD1 {
    int n, b;
    PrintWriter out;

    char[][] arrow;
    int[][][] visited;
    long[][][] reach;
    int[][][] reachx;
    int[][][] reachy;
    int[][][] reachd;
    int[][][] cycle;
    boolean[][][] proc;

    void simulate(int x, int y, int dir, long t) {
        if (t == 0) {
            out.println(x + " " + y);
            return;
        }

        if (arrow[x][y] != '-') {
            if (arrow[x][y] == 'U') dir = 0;
            else if (arrow[x][y] == 'D') dir = 1;
            else if (arrow[x][y] == 'L') dir = 2;
            else dir = 3;
        }

        int nx = x, ny = y;
        if (dir == 0) ny++;
        else if (dir == 1) ny--;
        else if (dir == 2) nx--;
        else nx++;

        if (nx < 0 || nx > b || ny < 0 || ny > b) {
            out.println(x + " " + y);
            return;
        }

        simulate(nx,ny,dir,t-1);
    }

    void get(int x, int y, int dir, int d) {
        if (visited[x][y][dir] != -1) {
            if (!proc[x][y][dir]) {
                proc[x][y][dir] = true;
                reach[x][y][dir] = 0;
                reachx[x][y][dir] = x;
                reachy[x][y][dir] = y;
                reachd[x][y][dir] = dir;
                //System.out.println(x + " " + y + " " + dir + " " + d + " " + visited[x][y][dir]);
                cycle[x][y][dir] = d - visited[x][y][dir];
            }
            return;
        }

        visited[x][y][dir] = d;
        int odir = dir;

        if (arrow[x][y] != '-') {
            if (arrow[x][y] == 'U') dir = 0;
            else if (arrow[x][y] == 'D') dir = 1;
            else if (arrow[x][y] == 'L') dir = 2;
            else dir = 3;
        }

        int nx = x, ny = y;
        if (dir == 0) ny++;
        else if (dir == 1) ny--;
        else if (dir == 2) nx--;
        else nx++;

        if (nx < 0 || nx > b || ny < 0 || ny > b) {
            reach[x][y][odir] = 1000000000000001L;
            return;
        }

        get(nx,ny,dir,d+1);

        proc[x][y][odir] = true;
        reach[x][y][odir] = reach[nx][ny][dir] + 1;
        reachx[x][y][odir] = reachx[nx][ny][dir];
        reachy[x][y][odir] = reachy[nx][ny][dir];
        reachd[x][y][odir] = reachd[nx][ny][dir];
    }

    public void solve(int testNumber, Parser in, PrintWriter out) {
        this.out = out;
        n = in.nextInt();
        b = in.nextInt();

        arrow = new char[b+1][b+1];
        visited = new int[b+1][b+1][4];
        reach = new long[b+1][b+1][4];
        reachx = new int[b+1][b+1][4];
        reachy = new int[b+1][b+1][4];
        reachd = new int[b+1][b+1][4];
        cycle = new int[b+1][b+1][4];
        proc = new boolean[b+1][b+1][4];

        for (int i = 0; i <= b; i++) {
            for (int j = 0; j <= b; j++) {
                arrow[i][j] = '-';
            }
        }

        for (int i = 0; i < n; i++) {
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();

            if (x1 == x2) {
                if (y1 < y2) {
                    for (int y = y1; y <= y2; y++) {
                        arrow[x1][y] = 'U';
                    }
                }
                else {
                    for (int y = y2; y <= y1; y++) {
                        arrow[x1][y] = 'D';
                    }
                }
            }
            else {
                if (x1 < x2) {
                    for (int x = x1; x <= x2; x++) {
                        arrow[x][y1] = 'R';
                    }
                }
                else {
                    for (int x = x2; x <= x1; x++) {
                        arrow[x][y1] = 'L';
                    }
                }
            }
        }

        for (int x = 0; x <= b; x++) {
            for (int y = 0; y <= b; y++) {
                for (int dir = 0; dir < 4; dir++) visited[x][y][dir]=-1;
            }
        }

        for (int x = 0; x <= b; x++) {
            for (int y = 0; y <= b; y++) {
                for (int dir = 0; dir < 4; dir++) {
                    if (visited[x][y][dir] == -1) get(x,y,dir,0);
                }
            }
        }

        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int x = in.nextInt();
            int y = in.nextInt();

            String d = in.next();
            int dir;
            if (d.charAt(0) == 'U') dir = 0;
            else if (d.charAt(0) == 'D') dir = 1;
            else if (d.charAt(0) == 'L') dir = 2;
            else dir = 3;

            long t = in.nextLong();

            if (reach[x][y][dir] <= t) {
                t -= reach[x][y][dir];

                int ox = x, oy = y;
                x = reachx[ox][oy][dir];
                y = reachy[ox][oy][dir];
                dir = reachd[ox][oy][dir];

                t %= cycle[x][y][dir];
            }

            simulate(x,y,dir,t);
        }
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

    public long nextLong()
    {
        return Long.parseLong(next());
    }

    }