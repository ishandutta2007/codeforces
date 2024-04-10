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
 * @author ffao
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
    int n;
    long[] a, o;
    int[] cnt;
    int tot, best;

    void bt(int c, int ign) {
        //System.out.println(c + " " + tot + " " + ign);

        if (c == n) {
            if (ign == 1) best = Math.min(best, tot);
            else best = Math.min(best, tot+1);
            return;
        }

        bt(c+1, ign+1);

        for (int i = c+1; i < n; i++) {
            if (a[i] % o[c] == 0 ) {

                tot -= cnt[c];
                a[i] /= o[c];

                //System.out.println("MAKE PAIR " + i + " " + c);
                bt(c+1, ign);
                //System.out.println("UNMAKE PAIR " + i + " " + c);

                tot += cnt[c];
                a[i] *= o[c];
            }
        }
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        n = in.nextInt();

        a = in.readLongArray(n);
        Arrays.sort(a);

        o = a.clone();

        cnt = new int[n];

        tot = 0;
        for (int i = 0; i < n; i++) {
            cnt[i] = 0;
            for (long j = 2; j*j <= a[i]; j++) {
                if (a[i] % j == 0) {
                    while (a[i] % j == 0) {
                        cnt[i]++;
                        a[i] /= j;
                    }
                }
            }

            if (a[i] != 1) cnt[i]++;
            if (cnt[i] != 1) tot += cnt[i];

            a[i] = o[i];
        }

        best = Constants.INF;
        bt(0,0);

        out.println(best + n);
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

class Constants {
    public static int INF = 1000000010;
    }