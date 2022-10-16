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
    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();

        int[] costs = in.readIntArray(9);

        int m = costs[8], mindig = 8;
        for (int i = 7; i >= 0; i--) {
            if (costs[i] < m) {
                m = costs[i];
                mindig = i;
            }
        }

        int cnt = n/m;
        n -= cnt*m;
        
        if (cnt == 0) {
            out.println(-1);
        }

        for (int i = 0; i < cnt; i++) {
            for (int d = 8; d >= 0; d--) {
                if (costs[d] - m <= n) {
                    n -= costs[d] - m;
                    out.print(d+1);
                    break;
                }
            }
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

    public int[] readIntArray(int n)
    {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) ret[i] = nextInt();
        return ret;
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