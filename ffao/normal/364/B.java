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
    boolean[] kn = new boolean[520000];

    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();
        int d = in.nextInt();

        kn[0] = true;
        int s = 0;
        for (int i = 0; i < n; i++) {
            int c = in.nextInt();
            s += c;
            for (int v = s; v >= c; v--) {
                kn[v] = kn[v] || kn[v-c];
            }
        }

        int ch = 1;
        int cur = 0;
        int ans = 0;
        while (true) {
            int best = -1;
            for (; ch <= cur+d; ch++) {
                if (kn[ch]) best = ch;
            }

            if (best != -1) {
                ans++;
                cur = best;
            }
            else break;
        }

        out.println(cur + " " + ans);
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