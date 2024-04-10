import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
        TaskC1 solver = new TaskC1();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC1 {
    int[] pd;

    int func(int n) {
        if (pd[n] != -1) return pd[n];

        int tn = n, b = Constants.INF;
        while (tn != 0) {
            if (tn%10 != 0) b = Math.min(b, func(n-(tn%10))+1);
            tn /= 10;
        }

        return pd[n] = b;
    }

    public void solve(int testNumber, Parser in, PrintWriter out) {
        int n = in.nextInt();
        pd = new int[n+1];
        Arrays.fill(pd, -1);
        pd[0] = 0;
        out.println(func(n));
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