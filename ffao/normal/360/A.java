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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class Operation {
    int t,l,r,d;
}

class TaskA {
    Operation[] op = new Operation[5000];
    int[] best = new int[5010];

    public void solve(int testNumber, Parser in, OutputWriter out) {
        if (testNumber == 1) {
            for (int i = 0; i < 5000; i++) op[i] = new Operation();
        }

        Arrays.fill(best, 1000000000);

        int n = in.nextInt();
        int m = in.nextInt();

        BIT increment = new BIT(n);

        for (int i = 0; i < m; i++) {
            op[i].t = in.nextInt();
            op[i].l = in.nextInt();
            op[i].r = in.nextInt();
            op[i].d = in.nextInt();

            if (op[i].t == 1) {
                increment.update(op[i].l, op[i].d);
                increment.update(op[i].r+1, -op[i].d);
            }

            else {
                for (int j = op[i].l; j <= op[i].r; j++) {
                    best[j] = Math.min(best[j], op[i].d - increment.read(j));
                }
            }
        }

        increment = new BIT(n);
        boolean ok = true;
        for (int i = 0; i < m; i++) {

            //System.out.println(i + " " + op[i].l + " " + op[i].r + " " + op[i].t + " " + op[i].d);
            if (op[i].t == 1) {
                increment.update(op[i].l, op[i].d);
                increment.update(op[i].r+1, -op[i].d);
            }

            else {
                int res = best[op[i].l] + increment.read(op[i].l);
                for (int j = op[i].l; j <= op[i].r; j++) {
                    //System.out.println("element " + j + " is " + best[j] + " + " + increment.read(j));
                    res = Math.max(res, best[j] + increment.read(j));
                }

                //System.out.println("res = " + res);
                if (res != op[i].d) {
                    ok = false;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (Math.abs(best[i+1]) > 1000000000) ok = false;
        }

        if (!ok) out.println("NO");
        else {
            out.println("YES");
            for (int i = 0; i < n; i++) out.print(best[i+1] + " ");
            out.println();
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

class BIT {
    int[] tree;
    int n;

    public BIT(int n) {
        this.n = n;
        tree = new int[n+1];
    }

    public int read(int x) {
        int s = 0;
        while (x > 0) {
            s += tree[x];
            x -= x&-x;
        }
        return s;
    }

    public void update(int x, int delta) {
        while (x <= n) {
            tree[x] += delta;
            x += x&-x;
        }
    }

}