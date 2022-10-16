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

class TaskB {
    String[] board = new String[20];
    int[][] pd = new int[40][1<<20];
    int[] value = new int[200];
    int n;

    public int convertToIdx(int x, int y) {
        int i = x+y;
        int tx,ty;
        if (i < n) {
            tx = i;
            ty = 0;
        }
        else {
            tx = n-1;
            ty = i-tx;
        }

        return tx-x;
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        n = in.nextInt();

        value['a']=1;
        value['b']=-1;

        for (int i = 0; i < n; i++) {
            board[i] = in.next();
        }

        pd[2*n-2][1] = value[board[n-1].charAt(n-1)];

        for (int i = 2*n-3; i >= 0; i--) {
            int len;

            if (i < n) len = i+1;
            else len = 2*n-i-1;

            for (int bm = 1; bm < (1<<len); bm++) {
                int[] amask = new int[30];

                char th='s';
                int m = bm;

                while (m != 0) {
                    int bit = Integer.numberOfTrailingZeros(m);
                    m -= m&-m;

                    int tx, ty;
                    if (i < n) {
                        tx = i;
                        ty = 0;
                    }
                    else {
                        tx = n-1;
                        ty = i-tx;
                    }

                    tx -= bit;
                    ty += bit;

                    th = board[tx].charAt(ty);

                    if (tx != n-1) {
                        int nx = tx+1;
                        int ny = ty;

                        amask[board[nx].charAt(ny)-'a'] |= (1<<convertToIdx(nx,ny));
                    }

                    if (ty != n-1) {
                        int nx = tx;
                        int ny = ty+1;

                        amask[board[nx].charAt(ny)-'a'] |= (1<<convertToIdx(nx,ny));
                    }
                }

                int best;
                if (i % 2 == 0) best = Constants.INF;
                else best = -Constants.INF;

                for (int k = 0; k < 26; k++) {
                    if (amask[k] != 0) {
                        if (i % 2 == 0) best = Math.min(pd[i+1][amask[k]] + value[th], best);
                        else best = Math.max(pd[i+1][amask[k]] + value[th], best);
                    }
                }

                //System.out.println("from (" + i + ","+bm+") value of " + best);
                pd[i][bm]=best;
            }
        }

        if (pd[0][1] > 0) out.println("FIRST");
        else if (pd[0][1] < 0) out.println("SECOND");
        else out.println("DRAW");
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

class Constants {
    public static int INF = 1000000010;
    }