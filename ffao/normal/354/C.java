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
    int[] part = new int[1000100];
    int k;

    boolean check(int p) {
        for (int x = 0; x <= 1000000; x+=p) {
            int max = Math.min(1000000, x+p-1);
            int min = x+k+1;

            if (max >= min && part[max] > part[min-1]) return false;
        }

        return true;
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();
        k = in.nextInt();

        int[] a = in.readIntArray(n);

        int m = a[0];
        for (int i = 0; i < n; i++) {
            m = Math.min(m, a[i]);
            part[a[i]] = 1;
        }

        for (int i = 1; i <= 1000000; i++) {
            part[i] = part[i-1]+part[i];
        }

        int best = 1;
        for (int i = 2; i <= m; i++) {
            if (check(i)) best = i;
        }

        out.println(best);
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