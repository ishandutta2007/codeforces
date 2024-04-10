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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    int mod = 1000000007;
    long [][] pd = new long[2010][2010];

    long func(int can, int cant) {
        if (can < 0) return 0;
        if (can == 0 && cant == 0) return 1;
        
        else if (pd[can][cant] != -1) return pd[can][cant];

        if (cant > 0) {
            pd[can][cant] = (func(can-1, cant)*can + func(can, cant-1)*cant) % mod;
        }
        else {
            pd[can][cant] = (func(can-2, cant+1) * (can-1)) % mod;
        }

        return pd[can][cant];
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();
        int[] a = in.readIntArray(n);

        for (int i = 0; i <= 2000; i++) Arrays.fill(pd[i], -1);

        int spaces_can = 0;
        int spaces_cant = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] != -1) {
                if (a[a[i] - 1] == -1) {
                    spaces_can--;
                    spaces_cant++;
                }
            }
            else {
                spaces_can++;
            }
        }

        out.println(func(spaces_can, spaces_cant));
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

class OutputWriter extends PrintWriter {
    public OutputWriter(Writer out) {
        super(out);
    }

    public OutputWriter(OutputStream out) {
        super(out);
    }

    }