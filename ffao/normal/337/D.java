import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    ArrayList<Integer> g[];
    int down[];
    boolean cont[];
    int n,m,d;

    void dfs(int v, int p) {
        for (Integer child : g[v]) {
            if (child == p) continue;
            dfs(child, v);
            down[v] = Math.max(down[v], down[child]+1);
        }
    }

    int dfs2(int v, int p, int up) {
        int ans = 0;
        if (cont[v]) up = Math.max(up, 0);

        //System.out.println(v + " " + p + " " + down[v] + " " + up);
        if (down[v] <= d && up <= d) {
            //System.out.println(v + " is ok");
            ans++;
        }

        int best = -Constants.INF;
        int bestid = -1;
        int best2 = -Constants.INF;

        for (Integer child : g[v]) {
            if (child == p) continue;

            int val = down[child] + 2;
            if (val > best) {
                best2 = best;

                best = val;
                bestid = child;
            }
            else if (val > best2) {
                best2 = val;
            }
        }


        for (Integer child : g[v]) {
            if (child == p) continue;

            if (child != bestid) ans += dfs2(child, v, Math.max(up+1, best));
            else ans += dfs2(child, v, Math.max(up+1, best2));
        }

        return ans;
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        d = in.nextInt();

        g = new ArrayList[n];
        down = new int[n];
        cont = new boolean[n];
        for (int i = 0; i < n; i++) g[i] = new ArrayList<Integer>();

        Arrays.fill(down, -Constants.INF);
        for (int i = 0; i < m; i++) {
            int a = in.nextInt()-1;
            down[a] = 0;
            cont[a] = true;
        }

        for (int i = 0; i < n-1; i++) {
            int a = in.nextInt()-1;
            int b = in.nextInt()-1;
            g[a].add(b);
            g[b].add(a);
        }

        dfs(0, -1);
        out.println(dfs2(0, -1, -Constants.INF));
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