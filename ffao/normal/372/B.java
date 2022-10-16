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
    long[][] count = new long[1600][1600];
    long[][] tot = new long[1600][1600];
    String[] board = new String[40];

    int n, m;

    void fill() {
        for (int x2 = 0; x2 < n; x2++) {
            int lo = -1;
            for (int y2 = 0; y2 < m; y2++) {
                
                if (board[x2].charAt(y2) == '1') lo = y2;
                
                for (int x1 = 0; x1 <= x2; x1++) {
                    for (int y1 = 0; y1 <= y2; y1++) {
                        int hash_start = x1*m + y1;

                        int hash_end = x2*m + y2;
                        int last_one = Math.max(lo, y1-1);
                        
                        if (board[x2].charAt(y2) == '1') {
                            count[hash_start][hash_end] = 0;
                        }
                        else {
                            if (x2 > x1) count[hash_start][hash_end] += count[x1*m + last_one + 1][(x2-1) * m + y2];
                            count[hash_start][hash_end] += y2 - last_one;
                        }

                        tot[hash_start][hash_end] = count[hash_start][hash_end];
                        if (x2 > x1) tot[hash_start][hash_end] += tot[hash_start][hash_end - m];
                        if (y2 > y1) tot[hash_start][hash_end] += tot[hash_start][hash_end - 1];
                        if (x2 > x1 && y2 > y1) tot[hash_start][hash_end] -= tot[hash_start][hash_end - m - 1];
                    }
                }
                
            }
        }
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        int q = in.nextInt();

        for (int i = 0; i < n; i++) board[i] = in.next();

        fill();

        int hs = 1 * m + 2;
        for (int i = 0; i < q; i++) {
            int x1 = in.nextInt()-1;
            int y1 = in.nextInt()-1;
            int x2 = in.nextInt()-1;
            int y2 = in.nextInt()-1;

            out.println(tot[x1*m + y1][x2*m + y2]);
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

    }

class OutputWriter extends PrintWriter {
    public OutputWriter(Writer out) {
        super(out);
    }

    public OutputWriter(OutputStream out) {
        super(out);
    }

    }