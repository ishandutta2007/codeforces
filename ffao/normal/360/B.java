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
    int[] a;
    int[] pd = new int[2000];
    int n, k;

    boolean check(int mid) {
        int ans = 2000000000;

        for (int i = 0; i < n; i++) pd[i] = i;
        for (int i = 0; i < n; i++) {
            ans = Math.min(ans, pd[i] + n-i-1);

            for (int j = i+1; j < n; j++) {
                long diff = (a[j] - a[i]) / (j-i);
                if (diff < 0) diff = -diff;
                if ((a[j] - a[i]) % (j-i) != 0) diff++;

                if (diff > mid) continue;
                else pd[j] = Math.min(pd[i]+(j-i-1), pd[j]);
            }
        }

        return ans <= k;
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        n = in.nextInt();
        k = in.nextInt();
        a = in.readIntArray(n);

        int st = 0, end = 2000000000;
        while (st < end) {
            int mid = st + (end-st)/2;
            if (check(mid)) end=mid;
            else st = mid+1;
        }

        out.println(st);
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