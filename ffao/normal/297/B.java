import java.util.NavigableSet;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;
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
    public void solve(int testNumber, Parser in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();

        TreeMap<Integer,Integer> tm = new TreeMap<Integer, Integer>();
        for (int i = 0 ; i < n; i++) {
            int t = in.nextInt();
            if (tm.containsKey(t)) tm.put(t, tm.get(t)+1);
            else tm.put(t, 1);
        }
        for (int i = 0 ; i < m; i++) {
            int t = in.nextInt();
            if (tm.containsKey(t)) tm.put(t, tm.get(t)-1);
            else tm.put(t, -1);
        }
        
        int t = 0;
        for (int c : tm.descendingKeySet()) {
            t += tm.get(c);
            if (t > 0) {
                out.println("YES");
                return;
            }
        }
        out.println("NO");
        return;
        
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