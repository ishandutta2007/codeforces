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
    long[] h;
    long[] p;
    int n, m;

    long cost(int head, int fk, int lk) {
        long fpp = p[fk];
        long lpp = p[lk];
        long hpp = h[head];

        if (lpp <= hpp) {
            return hpp-fpp;
        }
        else if (fpp >= hpp) {
            return lpp-hpp;
        }
        else {
            return (lpp-fpp) + Math.min(lpp-hpp, hpp-fpp);
        }
    }

    boolean check(long mid) {
        int last_pos = 0;
        for (int i = 0; i < n; i++) {
            int next = last_pos;
            for (int j = last_pos; j < m; j++) {
                if (cost(i, last_pos, j) <= mid) {
                    next = j+1;
                }
                else break;
            }

            last_pos = next;
        }

        return last_pos == m;
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        n = in.nextInt();
        m = in.nextInt();

        h = in.readLongArray(n);
        p = in.readLongArray(m);

        long st = 0, end = 100000000000L;

        while (st < end) {
            long mid = (st+end)/2;

            if (check(mid)) end = mid;
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