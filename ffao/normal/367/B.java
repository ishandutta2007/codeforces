import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.TreeMap;
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
    TreeMap<Integer, Integer> countsA;
    TreeMap<Integer, Integer> counts;
    int tot;

    public void remElement(int ele) {
        if (counts.containsKey(ele)) {
            int countB = counts.get(ele);
            int val = countsA.get(ele)-1;
            tot -= Math.min(countB, val+1);

            countsA.put(ele, val);
            tot += Math.min(countB, val);
        }
    }

    public void addElement(int ele) {
        if (counts.containsKey(ele)) {
            int countB = counts.get(ele);
            int val;

            if (countsA.containsKey(ele)) {
                val = countsA.get(ele)+1;
                tot -= Math.min(countB, val-1);
            }
            else val = 1;

            countsA.put(ele, val);
            tot += Math.min(countB, val);
        }
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        long p = in.nextLong();

        int[] a = in.readIntArray(n);
        int[] b = in.readIntArray(m);
        counts = new TreeMap<>();

        for (int i = 0; i < m; i++) {
            if (counts.containsKey(b[i])) {
                counts.put(b[i], counts.get(b[i])+1);
            }
            else counts.put(b[i], 1);
        }

        Integer[] ans = new Integer[300000];
        int anscnt = 0;

        for (int q = 0; q < p; q++) {
            countsA = new TreeMap<>();

            if (q + (m-1)*p >= n) break;

            int prev = q;
            int next = q;
            tot = 0;
            for (int i = 0; i < m; i++) {
                addElement(a[next]);
                next += p;
            }


            while (true) {
                if (tot == m) {
                    ans[anscnt++] = prev;
                }

                if (next >= n) break;
                remElement(a[prev]);
                addElement(a[next]);
                prev += p;
                next += p;
            }

        }

        out.println(anscnt);
        Arrays.sort(ans, 0, anscnt);
        for (int i = 0; i < anscnt; i++) out.print((ans[i]+1) + " ");
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

    public long nextLong()
    {
        return Long.parseLong(next());
    }

    public int[] readIntArray(int n)
    {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) ret[i] = nextInt();
        return ret;
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