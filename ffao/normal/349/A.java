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
        int n = in.nextInt();

        int d25 = 0, d50 = 0;
        for (int i = 0; i < n; i++) {
            int t = in.nextInt();
            if (t == 25) d25++;
            else if (t == 50) {
                if (d25 == 0) {
                    out.println("NO");
                    return;
                }
                d25--;
                d50++;
            }
            else {
                if (d50 == 0) {
                    if (d25 < 3) {
                        out.println("NO");
                        return;
                    }
                    d25-=3;
                }
                else {
                    d50--;
                    if (d25 == 0) {
                        out.println("NO");
                        return;
                    }
                    d25--;
                }
            }
        }

        out.println("YES");
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