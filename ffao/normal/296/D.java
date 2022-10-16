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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    long[] ans = new long[501];
    int[][] g = new int[501][501];
    int[] x = new int[501];
    int[] idx = new int[501];

    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = in.nextInt();
            }
        }

        for (int i = 1; i <= n; i++) {
            x[i] = in.nextInt();
            idx[x[i]] = i;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    g[i][j] = Math.min(g[i][j], g[i][x[n-k+1]] + g[x[n-k+1]][j]);
                    
                    if (idx[i] > n-k && idx[j] > n-k) ans[k] += g[i][j];
                }
            }
        }

        for (int k = n; k >= 1; k--) {
            out.println(ans[k]);
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