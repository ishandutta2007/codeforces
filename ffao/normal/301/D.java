import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class Query implements Comparable<Query>{
    int x, y;
    int id;

    public Query(int a, int b, int c) {
        x = a;
        y = b;
        id = c;
    }

    public int compareTo(Query o) {
        return x - o.x;
    }
}

class TaskD {
    public void solve(int testNumber, Parser in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] p = new int[n+1];
        int[] inv = new int[n+1];
        int[] res = new int[m];

        for (int i = 1; i <= n; i++) {
            p[i] = in.nextInt();
            inv[p[i]]=i;
        }

        int[] divHead = new int[n + 1];
        int[] divNext = new int[n * 20];
        int[] divValue = new int[n * 20];
        Arrays.fill(divHead, -1);
        int count = 0;

        for (int val = 1; val <= n; val++) {
            for (int i = 2 * val; i <= n; i += val) {
                if (count == divNext.length) {
                    divNext = Arrays.copyOf(divNext, 2 * count);
                    divValue = Arrays.copyOf(divValue, 2 * count);
                }
                divValue[count] = val;
                divNext[count] = divHead[i];
                divHead[i] = count++;
            }
        }

        ArrayList<Query>[] queries = new ArrayList[n+1];
        for (int i = 0; i <= n; i++) queries[i] = new ArrayList<Query>();

        for (int i = 0; i < m; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            queries[a].add(new Query(a,b,i));
        }

        BIT b = new BIT(n);

        for (int a = n; a >= 1; a--) {
            int val = p[a];
            for (int i = 2 * val; i <= n; i += val) {
                int pos = inv[i];
                if (a < pos) {
                    b.update(pos, 1);
                }
            }
            for (int i = divHead[val]; i >= 0; i = divNext[i]) {
                int pos = inv[divValue[i]];
                if (a < pos) {
                    b.update(pos, 1);
                }
            }
            b.update(a, 1);


            for (Query q : queries[a]) {
                res[q.id] = b.read(q.y);
            }
        }

        for (int i = 0; i < m; i++) {
            out.println(res[i]);
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