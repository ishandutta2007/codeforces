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
    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();

        Integer[] costs = new Integer[m];

        for (int i = 0; i < m; i++) {
            in.nextInt();
            costs[i] = in.nextInt();
        }

        Arrays.sort(costs);

        int comb = 0;
        int can_use = 1;
        for (int i = 1; i < n; i++) {
            comb += i;

            int req = comb;
            if (i % 2 == 1) {
                req += (i-1)/2;
            }
            req++;

            if (req > n) break;
            can_use = i+1;
        }

        if (can_use > m) can_use = m;
        long tot = 0;
        for (int i = 0; i < can_use; i++) {
            tot += costs[m-1-i];
        }

        out.println(tot);
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