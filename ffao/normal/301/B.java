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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    int[] a;
    int[] dist;
    boolean[] mark;
    int[] x,y;
    int d;

    public int cost(int i, int j) {
        return d*(Math.abs(x[j] - x[i]) + Math.abs(y[j] - y[i]));
    }

    public void solve(int testNumber, Parser in, PrintWriter out) {
        int n = in.nextInt();
        d = in.nextInt();

        a = new int[n];
        dist = new int[n];
        mark = new boolean[n];
        x = new int[n]; y = new int[n];

        for (int i = 0; i < n-2; i++) {
            a[i+1] = in.nextInt();
        }

        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }

        for (int i = 0; i < n; i++) dist[i] = Constants.INF;
        dist[n-1] = 0;

        int cur = n-1;
        while (cur != -1) {
            mark[cur] = true;
            for (int i = 0; i < n; i++) {
                if (mark[i]) continue;
                int nc = dist[cur] + cost(cur, i) - a[i];
                dist[i] = Math.min(nc, dist[i]);
            }

            int best = Constants.INF;
            cur = -1;
            for (int i = 0; i < n; i++) {
                if (!mark[i] && dist[i] < best) {
                    best = dist[i];
                    cur = i;
                }
            }
        }

        out.println(dist[0]);
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

class Constants {
    public static int INF = 1000000010;
}