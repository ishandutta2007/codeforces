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

    int test(int destx, int desty, int n, int m, int i, int j, int a, int b) {
        int dx = Math.abs(i-destx);
        int dy = Math.abs(j-desty);

        if (dx % a != 0 || dy % b != 0) return Constants.INF;

        dx /= a;
        dy /= b;

        if (dx % 2 != dy % 2) return Constants.INF;

        //System.out.println("dx = " + dx + " dy = " + dy);
        if (dx == 0 && dy == 0) return 0;
        if (dy == 0) {
            return (j+b <= m || j-b >= 1) ? dx : Constants.INF;
        }
        if (dx == 0) {
            return (i+a <= n || i-a >= 1) ? dy : Constants.INF;
        }

        return Math.max(dx, dy);
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int i = in.nextInt();
        int j = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();

        int k = 1000000000;
        k = Math.min(k, test(1, m, n,m,i, j, a, b));
        k = Math.min(k, test(n,m,n,m,i,j,a,b));
        k = Math.min(k, test(1,1,n,m,i,j,a,b));
        k = Math.min(k, test(n,1,n,m,i,j,a,b));

        if (k == 1000000000) {
            out.println("Poor Inna and pony!");
        }
        else out.println(k);
    }
}

class Constants {
    public static int INF = 1000000010;
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