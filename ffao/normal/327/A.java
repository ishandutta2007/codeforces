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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, Parser in, PrintWriter out) {
        int n = in.nextInt();
        int[] val = in.readIntArray(n);

        int cnt = 0;
        int[] zeros = new int[n+1];
        for (int i = 0; i < n; i++) {
            zeros[i+1] = zeros[i];
            if (val[i] == 1) cnt++;
            else zeros[i+1]++;
        }

        int m = 0;
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                int z = zeros[i] - zeros[j];
                int o = i - j - z;

                ans = Math.max(ans, cnt + z - o);
            }
        }

        out.println(ans);
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

    public int[] readIntArray(int n)
    {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) ret[i] = nextInt();
        return ret;
    }
}