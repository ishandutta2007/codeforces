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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, Parser in, OutputWriter out) {
        String inp = in.next();
        int n = inp.length();

        int[] x = new int[n+1];
        int[] y = new int[n+1];
        int[] z = new int[n+1];

        for (int i = 1; i <= n; i++) {
            x[i] = x[i-1]; y[i] = y[i-1]; z[i] = z[i-1];
            if (inp.charAt(i-1) == 'x') x[i]++;
            else if (inp.charAt(i-1) == 'y') y[i]++;
            else z[i]++;
        }

        int q = in.nextInt();

        for (int i = 0; i < q; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            if (b - a + 1 < 3) {
                out.println("YES");
                continue;
            }

            int xx = x[b]-x[a-1], yy = y[b]-y[a-1], zz = z[b]-z[a-1];
            int M = Math.max(xx, Math.max(yy,zz));
            int m = Math.min(xx, Math.min(yy,zz));
            
            if (M - m <= 1) out.println("YES");
            else out.println("NO");
            
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