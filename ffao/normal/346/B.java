import java.io.IOException;
import java.io.InputStreamReader;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class Pred {
    int x,y,k;
    Pred() {x=y=k=0;}
}

class TaskB {
    int[][][] pd = new int[110][110][110];
    Pred[][][] pred = new Pred[110][110][110];
    int[] overlap = new int[110];

    void set(int nx,int ny, int nz, int x, int y, int z, int v) {
        if (v > pd[nx][ny][nz]) {
            pd[nx][ny][nz] = v;
            pred[nx][ny][nz].x = x;
            pred[nx][ny][nz].y = y;
            pred[nx][ny][nz].k = z;
        }
    }

    void over(String s1) {
        overlap[0] = -1;
        for (int i = 0; i < s1.length(); i++) {
            overlap[i + 1] = overlap[i] + 1;
            while (overlap[i + 1] > 0 &&
                    s1.charAt(i) != s1.charAt(overlap[i + 1] - 1) )
                overlap[i + 1] = overlap[overlap[i + 1] - 1] + 1;
        }
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        String s1 = in.next();
        String s2 = in.next();
        String virus = in.next();

        over(virus);

        int n = s1.length();
        int m = s2.length();
        int v = virus.length();
        for (int i = 0; i <= 105; i++) {
            for (int j = 0; j <= 105; j++) {
                for (int k = 0; k <= 105; k++) {
                    pred[i][j][k] = new Pred();
                }
            }
            pd[0][0][i] = 0;
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int lk = 0; lk < v; lk++) {
                    if (pd[i][j][lk] < lk) continue;
                    //out.println(i + " " + j + " " + lk + " " + pd[i][j][lk]);
                    int k = lk;

                    set(i+1,j,k,i,j,k,pd[i][j][k]);
                    set(i, j + 1, k, i, j, k, pd[i][j][k]);

                    if (i < n && j < m && s1.charAt(i) == s2.charAt(j)) {
                        while (k != -1) {
                            if (s1.charAt(i) == virus.charAt(k)) {
                                set(i+1,j+1,k+1,i,j,lk,pd[i][j][lk]+1);
                                break;
                            }
                            else k = overlap[k];
                        }

                        if (k == -1) {
                            set(i+1,j+1,k+1,i,j,lk,pd[i][j][lk]+1);
                        }
                    }

                }
            }
        }

        int maxk = -1;
        int big = 0;
        for (int k = 0; k < v; k++) {
            //out.println(n + " " + m + " " + k + " " + pd[n][m][k]);
            if (pd[n][m][k] > big) {
                maxk = k;
                big = pd[n][m][k];
            }
        }

        StringBuilder s = new StringBuilder();

        if (maxk == -1) {
            out.println(0);
            return;
        }

        else {
            int cx = n, cy = m, ck = maxk, cur = big;
            while (cx != 0 && cy != 0 && pd[cx][cy][ck] != 0) {
                Pred p = pred[cx][cy][ck];
                cx = p.x; cy = p.y; ck = p.k;
                if (pd[cx][cy][ck] == big-1) {
                    s.append(s1.charAt(cx));
                    big--;
                }
            }
        }

        out.println(s.reverse().toString());
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

    }

class OutputWriter extends PrintWriter {
    public OutputWriter(Writer out) {
        super(out);
    }

    public OutputWriter(OutputStream out) {
        super(out);
    }

    }