import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskB1 solver = new TaskB1();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB1 {
    BIT bit;
    PrintWriter out;
    int n;
    int[] p, where;

    void query(int x, int y) {
        out.println(1 + bit.read(y) - bit.read(x));
    }

    void swap(int x, int y) {
        x--; y--;
        if (x > y) {
            int t = y;
            y = x;
            x = t;
        }

        int a = p[x], b = p[y];

        if (Math.abs(a - b) == 1) {
            if (a > b) bit.update(a, -1);
            else bit.update(b, 1);
        }

        if (a != 1 && a-1 != b) {
            if (x > where[a-1] && y < where[a-1]) bit.update(a, 1);
            if (x < where[a-1] && y > where[a-1]) bit.update(a, -1);
        }

        if (b != 1 && b-1 != a) {
            if (y > where[b-1] && x < where[b-1]) bit.update(b, 1);
            if (y < where[b-1] && x > where[b-1]) bit.update(b, -1);
        }

        if (a != n && a+1 != b) {
            if (x < where[a+1] && y > where[a+1]) bit.update(a+1, 1);
            if (x > where[a+1] && y < where[a+1]) bit.update(a+1, -1);
        }

        if (b != n && b+1 != a) {
            if (y < where[b+1] && x > where[b+1]) bit.update(b+1, 1);
            if (y > where[b+1] && x < where[b+1]) bit.update(b+1, -1);
        }

        p[x] = b;
        p[y] = a;
        where[a] = y;
        where[b] = x;
    }

    public void solve(int testNumber, Parser in, PrintWriter out) {
        n = in.nextInt();
        p = new int[n];
        where = new int[n+1];
        bit = new BIT(n);
        this.out = out;

        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt();
            where[p[i]] = i;
        }

        for (int i = 1; i < n; i++) {
            if (where[i+1] < where[i]) bit.update(i+1, 1);
        }

        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int type = in.nextInt();
            int x = in.nextInt();
            int y = in.nextInt();

            if (type == 1) query(x, y);
            else swap(x, y);

            /*for (int j = 0; j < n; j++) {
                out.print(p[j] + " ");
            }
            out.println();
            for (int j = 1; j <= n; j++) {
                out.print(bit.read(j) + " ");
            }
            out.println();*/
        }
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