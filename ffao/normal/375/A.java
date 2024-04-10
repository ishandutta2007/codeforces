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
    int[] seen = {-1, 0, -1, -1, -1, -1, 0, -1, 0, 0};
    int[] perm = {1869, 1968, 1689, 6198, 1698, 1986, 1896};

    public void solve(int testNumber, Parser in, OutputWriter out) {
        String n = in.next();

        int cur = 0, zero = 0;

        for (int i = 0; i < n.length(); i++) {
            int dig = n.charAt(i)-'0';
            if (dig == 0) zero++;
            else if (seen[dig] == 0) seen[dig] = 1;
            else {
                out.print(dig);
                cur = (10*cur + dig) % 7;
            }
        }

        cur = (cur * 10000) % 7;

        out.print(perm[(7-cur) % 7]);
        for (int i = 0; i < zero; i++) out.print(0);
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

    }

class OutputWriter extends PrintWriter {
    public OutputWriter(Writer out) {
        super(out);
    }

    public OutputWriter(OutputStream out) {
        super(out);
    }

    }