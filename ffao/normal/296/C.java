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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();

        long[] a = in.readLongArray(n);
        long[] inc = new long[n+1];
        int[] operation = new int[m+1];
        int[] opst = new int[m];
        int[] opend = new int[m];
        int[] opd = new int[m];

        for (int i = 0; i < m; i++) {
            opst[i] = in.nextInt()-1;
            opend[i] = in.nextInt()-1;
            opd[i] = in.nextInt();
        }

        for (int i = 0; i < k; i++) {
            int f = in.nextInt()-1;
            int b = in.nextInt()-1;
            operation[f]++;
            operation[b+1]--;
        }

        long c = 0;
        for (int i = 0; i < m; i++) {
            c += operation[i];
            inc[opst[i]] += opd[i] * c;
            inc[opend[i]+1] -= opd[i] * c;
        }

        c = 0;
        for (int i = 0; i < n; i++) {
            c += inc[i];
            out.print((a[i] + c) + " ");
        }
        out.println();
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

    public long[] readLongArray(int n) {
        long[] ret = new long[n];
        for (int i = 0; i < n; i++) ret[i] = nextLong();
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